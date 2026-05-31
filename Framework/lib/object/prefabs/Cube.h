#pragma once

#include <vector>

#include "object/GameObject.hpp"
#include "object/components/cTransform.h"
#include "object/components/cMeshView.h"
#include "graphics/materials/mDefault.h"
#include "Math.h"

class Cube : public GameObject {
private:


public:

    Cube(Framework::Math::Vec3 dimensions = Framework::Math::Vec3(1));
    ~Cube();

};