#pragma once
// Triangle.h

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Entity.h"

class triangle : public entity {
public:
    triangle(float _xpos, float _ypos, float _size, float _xspeed)
        : entity(_xpos, _ypos, _size, _size, _xspeed, 0.0f) {}

    void move() {
        // Move the triangle spike horizontally
        entity::move();
    }

    void draw() {
        // Implement draw for triangle spike
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Red color for spikes
        glVertex2f((xpos - xlen / 2.0f) / 10, (ypos - ylen / 2.0f) / 10);
        glVertex2f((xpos + xlen / 2.0f) / 10, (ypos - ylen / 2.0f) / 10);
        glVertex2f(xpos / 10, (ypos + ylen / 2.0f) / 10);
        glEnd();
    }
};

#endif // TRIANGLE_H
