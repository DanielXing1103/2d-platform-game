#ifndef ENTITY_H
#define ENTITY_H

#include <GL/freeglut.h>
#include <iostream>

class entity {
public:

    float xpos;
    float ypos;
    float xlen;
    float ylen;
    float xspeed;
    float yspeed;
    entity() {
        xpos = ypos = xlen = ylen = xspeed = yspeed = 0;
    }

    entity(float _xpos, float _ypos, float _xlen, float _ylen, float _xspeed, float _yspeed) {
        xpos = _xpos;
        ypos = _ypos;
        xlen = _xlen;
        ylen = _ylen;
        xspeed = _xspeed;
        yspeed = _yspeed;
    }
    virtual bool checkCollision(const entity& other) const {
        // Calculate bounding box for the current entity
        float thisLeft = xpos - xlen / 2.0f;
        float thisRight = xpos + xlen / 2.0f;
        float thisTop = ypos + ylen / 2.0f;
        float thisBottom = ypos - ylen / 2.0f;

        // Calculate bounding box for the other entity
        float otherLeft = other.xpos - other.xlen / 2.0f;
        float otherRight = other.xpos + other.xlen / 2.0f;
        float otherTop = other.ypos + other.ylen / 2.0f;
        float otherBottom = other.ypos - other.ylen / 2.0f;

        // Check for overlap
        return (thisLeft <= otherRight&& thisRight >= otherLeft &&
            thisTop >= otherBottom && thisBottom <= otherTop);
    }
    virtual void move() {
        xpos += xspeed;
        ypos += yspeed;
    }

    virtual void draw(float r, float g, float b) {
        glBegin(GL_QUADS);
        glColor3f(r,g,b); // black color for land
        glVertex2f((xpos - xlen / 2.0f) / 10, (ypos - ylen / 2.0f) / 10);
        glVertex2f((xpos + xlen / 2.0f) / 10, (ypos - ylen / 2.0f) / 10);
        glVertex2f((xpos + xlen / 2.0f) / 10, (ypos + ylen / 2.0f) / 10);
        glVertex2f((xpos - xlen / 2.0f) / 10, (ypos + ylen / 2.0f) / 10);


        glEnd();
    }
};

#endif // ENTITY_H
