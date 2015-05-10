/*
 * Copyright (C) 2015 Willi Ye
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <SFML/Graphics.hpp>

#include "ball.h"
#include "paddle.h"
#include "uiparent.h"

Ball* Ball::getInstance(Paddle* paddleOne, Paddle* paddleTwo, UIParent* uiparent)
{
    Ball* ball = new Ball();
    ball->paddleOne = paddleOne;
    ball->paddleTwo = paddleTwo;
    ball->position.x = SCREEN_WIDTH / 2;
    ball->position.y = SCREEN_HEIGHT / 2;
    ball->velocity.x = -4;
    ball->velocity.y = 0;
    ball->radius = 5;
    return ball;
}

void Ball::draw(sf::RenderWindow* window, int screenWidth, int screenHeight)
{
    if (gameover) return;
    position.x += velocity.x;
    position.y += velocity.y;

    if (velocity.x < 0
            && position.x - radius < paddleOne->getWidth()
            && touchedPaddle(paddleOne))
    {
        velocity.x *= -1;
        velocity.y += getVelocityY(paddleOne);
        position.x = paddleOne->getWidth() + radius * 2;
    }

    if (velocity.x > 0
            && position.x + radius > screenWidth - paddleTwo->getWidth()
            && touchedPaddle(paddleTwo))
    {
        velocity.x *= -1;
        velocity.y += getVelocityY(paddleTwo);
        position.x = screenWidth - paddleTwo->getWidth();
    }

    if (touchedWall(screenHeight)) velocity.y *= -1;

    if (position.x >= 0 && position.x <= screenWidth)
    {
        sf::CircleShape ball(radius);
        ball.setPosition(position.x - radius, position.y);
        ball.setFillColor(sf::Color::Red);

        window->draw(ball);
    }
    else
    {
        gameover = 1;
        if (velocity.x < 0) uiparent->pointOneScored();
        else uiparent->pointTwoScored();
    }
}

int Ball::touchedWall(double wallHeight)
{
    return position.y - radius <= 0 || position.y + radius >= wallHeight;
}

int Ball::touchedPaddle(Paddle* paddle)
{
    return position.y > paddle->getHeight() && position.y < paddle->getHeight() + paddle->getLength();
}

int Ball::getVelocityY(Paddle* paddle) {
    double hitboxes[5][2];
    for (int i = 0; i < 5; i++)
    {
        hitboxes[i][0] = (paddle->getLength() / 5) * i + paddle->getHeight();
        hitboxes[i][1] = (paddle->getLength() / 5) * (i + 1) + paddle->getHeight();
        if (i == 0) hitboxes[i][0] -= radius;
        else if (i == 4) hitboxes[i][1] += radius;
    }

    for (int i = 0; i < 5; i++)
    {
        if (position.y > hitboxes[i][0] && position.y < hitboxes[i][1])
            switch (i)
            {
                case 0:
                    return -4;
                case 4:
                    return 4;
                case 1:
                    return -2;
                case 3:
                    return 2;
            }
    }
    return 0;
}

void Ball::reset(int screenWidth, int screenHeight)
{
    position.x = screenWidth / 2;
    position.y = screenHeight / 2;
    velocity.y = 0;
    gameover = 0;
}
