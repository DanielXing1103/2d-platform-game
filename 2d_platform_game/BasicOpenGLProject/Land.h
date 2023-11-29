// Land.h

#ifndef LAND_H
#define LAND_H

#include "Entity.h"

class land : public entity {
public:
    land(float _xpos, float _ypos, float _xlen, float _ylen)
        : entity(_xpos, _ypos, _xlen, _ylen, 0.0f, 0.0f) {
        // The land entity has no speed, so set xspeed and yspeed to 0.
    }

    void draw() {
        entity::draw(0, 0, 0);
    }
};

#endif // LAND_H
#pragma once
