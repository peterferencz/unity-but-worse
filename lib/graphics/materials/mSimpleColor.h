#pragma once

#include "graphics/materials/Material.h"
#include "glm/glm.hpp"
#include "GL/gl.h"

class mSimpleColor : public Material {
public:
    glm::vec3 color;

    mSimpleColor(glm::vec3 color);
    ~mSimpleColor();

    void Draw() const override;
};