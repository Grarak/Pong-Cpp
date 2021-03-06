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

#ifndef _PADDLE_H
#define _PADDLE_H

#include <SFML/Graphics.hpp>

#include "uiparent.h"

class Paddle
{
    private:
        Player player;
        double offset;
        int moving;
        double height;
        double length;
        double thickness;

    public:
        static Paddle* getInstance(Player player);
        void draw(sf::RenderWindow* window, int screenWidth, int screenHeight);
        void moveUp();
        void moveDown();
        double getHeight();
        double getLength();
        double getWidth();
        void reset();

};

#endif
