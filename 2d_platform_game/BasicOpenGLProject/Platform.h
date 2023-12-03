// In your Platform.h file
#ifndef PLATFORM_H
#define PLATFORM_H

#include "Entity.h"

class platform : public entity {
public:

    platform(float _xpos, float _ypos, float _xlen, float _ylen, float _xspeed)
        : entity(_xpos, _ypos, _xlen, _ylen, _xspeed, 0.0f){}

    void move()  {
        // Move the platform horizontally
        entity::move();
    }


    void draw()  {
        entity::draw(1.0f, 1.0f, 1.0f);
    }
};

#endif // PLATFORM_H
