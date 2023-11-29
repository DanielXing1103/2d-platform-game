#ifndef PLAYER_H
#define PLAYER_H

#include <GL/freeglut.h>
#include <iostream>
#include "Entity.h"

class player :public entity {
public:
    float acc;//accelration
    player() : entity() {
        acc = 3;
    }

    // Constructor with parameters
    player(float _xpos, float _ypos, float _xlen, float _ylen, float _xspeed, float _yspeed, float _acc)
        : entity(_xpos, _ypos, _xlen, _ylen, _xspeed, _yspeed) {
        acc = _acc;
    }
    bool checkCollision(const entity& other) {
        bool landed = entity::checkCollision(other);
        if (landed) {
            ypos = ypos = other.ypos + other.ylen / 2.0f + ylen / 2.0f;
        }
        return landed;
    }
    void move() {
        std::cout << xpos << ypos << std::endl;
        entity::move();
        yspeed += acc;
    }
    // Draw function to draw a box of the input size
    void draw() {
        entity::draw(1.0, 0, 0);
    }
};
#endif