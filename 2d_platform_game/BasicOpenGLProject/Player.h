#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Entity.h"
class node {
public:
    bool collision;
    int position;//one is top, 0 is bottom
    node() {
        collision = false;
        position = 1;
    }
};
class player :public entity {
public:
    float acc;//accelration
    bool gameover;
    player() : entity() {
        acc = 3;
        gameover = false;
    }

    // Constructor with parameters
    player(float _xpos, float _ypos, float _xlen, float _ylen, float _xspeed, float _yspeed, float _acc)
        : entity(_xpos, _ypos, _xlen, _ylen, _xspeed, _yspeed) {
        acc = _acc;
        gameover = false;
    }
    node checkCollision(const entity& other) {
        node result;
        result.collision = entity::checkCollision(other);
        if (result.collision) {
            if (std::abs((ypos - (ylen / 2.0f)) - (other.ypos + (other.ylen / 2.0f))) <= std::abs(yspeed)) {
                // Place the player on top of the other entity
                ypos = other.ypos + other.ylen / 2.0f + ylen / 2.0f;
                result.position = 1;
            }
            else if (std::abs((ypos + (ylen / 2.0f)) - (other.ypos - (other.ylen / 2.0f))) <= std::abs(yspeed)) {
                // Place the player below the other entity
                ypos = other.ypos - other.ylen / 2.0f - ylen / 2.0f-0.01;
                result.position = 0;

            }
            else {
                gameover = true;
            }
        }
        return result;
    }

    void move() {
        entity::move();
        yspeed += acc;
    }
    // Draw function to draw a box of the input size
    void draw() {
        entity::draw(1.0, 0, 0);
    }
};
#endif