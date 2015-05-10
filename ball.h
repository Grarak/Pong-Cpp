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

#ifndef _BALL_H
#define _BALL_H

#include <SFML/Graphics.hpp>

#include "paddle.h"

class Ball
{
    private:
        Paddle* paddleOne;
        Paddle* paddleTwo;
        sf::Vector2<double> position;
        sf::Vector2<double> velocity;
        int touchedWall(double wallHeight);
        int touchedPaddle(Paddle* paddle);
        int getVelocityY(Paddle* paddle);
        int radius;
        int gameover;
        UIParent* uiparent;

    public:
        static Ball* getInstance(Paddle* paddleOne, Paddle* paddleTwo, UIParent* uiparent);
        void draw(sf::RenderWindow* window, int screenWidth, int screenHeight);
        void reset(int screenWidth, int screenHeight);

};

#endif
