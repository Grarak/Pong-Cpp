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

#include <iostream>
#include <stdio.h>
#include <string.h>

#include <SFML/Graphics.hpp>

#include "point.h"

Point* Point::getInstance(Player player)
{
    Point* point = new Point();
    point->player = player;
    return point;
}

void Point::draw(sf::RenderWindow* window, int screenWidth, int screenHeight)
{
    sf::Font font;
    if (!font.loadFromFile("/etc/alternatives/fonts-japanese-gothic.ttf")) return;

    double w = 0;
    switch (player)
    {
        case ONE:
            w = screenWidth / 4;
            break;
        case TWO:
            w = screenWidth - screenWidth / 4;
            break;
    }

    char buf[100];
    sprintf(buf, "%d", point);

    sf::Text text;
    text.setFont(font);
    text.setString(strdup(buf));
    text.setCharacterSize(30);
    text.setPosition(w, 40);
    text.setColor(sf::Color::White);

    window->draw(text);
}
