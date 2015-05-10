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
#include "point.h"
#include "uiparent.h"

Point* pointOne;
Point* pointTwo;
Paddle* paddleOne;
Paddle* paddleTwo;
Ball* ball;

int _screenWidth, _screenHeight;

UIParent* UIParent::getInstance()
{
    UIParent* uiparent = new UIParent();
    pointOne = Point::getInstance(ONE);
    pointTwo = Point::getInstance(TWO);
    paddleOne = Paddle::getInstance(ONE);
    paddleTwo = Paddle::getInstance(TWO);
    ball = Ball::getInstance(paddleOne, paddleTwo, uiparent);
    return uiparent;
}

int keyPressed(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

void keyListener()
{
    if (keyPressed(sf::Keyboard::A))
        paddleOne->moveUp();
    if (keyPressed(sf::Keyboard::D))
        paddleOne->moveDown();
    if (keyPressed(sf::Keyboard::Left))
        paddleTwo->moveUp();
    if (keyPressed(sf::Keyboard::Right))
        paddleTwo->moveDown();
}

void UIParent::draw(sf::RenderWindow* window, int screenWidth, int screenHeight)
{
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;

    pointOne->draw(window, screenWidth, screenHeight);
    pointTwo->draw(window, screenWidth, screenHeight);
    paddleOne->draw(window, screenWidth, screenHeight);
    paddleTwo->draw(window, screenWidth, screenHeight);
    ball->draw(window, screenWidth, screenHeight);

    keyListener();
}

void reset()
{
    sf::sleep(sf::seconds(1));
    paddleOne->reset();
    paddleTwo->reset();
    ball->reset(_screenWidth, _screenHeight);
}

void UIParent::pointOneScored()
{
    pointOne->point++;
    reset();
}

void UIParent::pointTwoScored()
{
    pointTwo->point++;
    reset();
}
