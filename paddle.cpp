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

#include "paddle.h"

Paddle* Paddle::getInstance(Player player)
{
    Paddle* paddle = new Paddle();
    paddle->player = player;
    return paddle;
}

void Paddle::draw(sf::RenderWindow* window, int screenWidth, int screenHeight)
{
    length = screenHeight / 4;
    thickness = screenWidth / 80;

    double position = offset;
    if (position < 0) position = -position;
    if (position + length / 2 <= screenHeight / 2)
    {
        if (moving == 1) offset += screenHeight / 100;
        else if (moving == 2) offset -= screenHeight / 100;
    }
    else
    {
        if (offset <= 0) offset = -(screenHeight / 2 - length / 2);
        else offset = screenHeight / 2 - length / 2;
    }

    double w = 0;
    double h = screenHeight / 2 - length / 2 + offset;
    switch (player)
    {
        case ONE:
            w = 10;
            break;
        case TWO:
            w = screenWidth - thickness - 10;
            break;
    }

    sf::RectangleShape paddle(sf::Vector2f(thickness, length));
    paddle.setPosition(w, (height = h));
    paddle.setFillColor(sf::Color::Blue);

    window->draw(paddle);

    moving = 0;
}

void Paddle::moveUp()
{
    moving = 1;
}

void Paddle::moveDown()
{
    moving = 2;
}

double Paddle::getHeight()
{
    return height;
}

double Paddle::getLength()
{
    return length;
}

double Paddle::getWidth()
{
    return thickness + 10;
}

void Paddle::reset()
{
    offset = 0;
}
