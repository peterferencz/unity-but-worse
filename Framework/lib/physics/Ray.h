#pragma once

#include "Math.h"

struct Ray {
    Framework::Math::Vec3 origin;
    Framework::Math::Vec3 direction;

    Ray(Framework::Math::Vec3 origin, Framework::Math::Vec3 direction)
    : origin(origin), direction(direction) { }
};