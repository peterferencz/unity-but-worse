#pragma once

#include <vector>

#include "object/GameObject.hpp"
#include "object/components/cTransform.h"
#include "object/components/cMeshView.h"
#include "graphics/materials/mDefault.h"
#include "glm/glm.hpp"

class Cube : public GameObject {
private:


public:

    Cube(glm::vec3 dimensions = glm::vec3(1));
    ~Cube();

};