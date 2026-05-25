#pragma once

#include "object/components/Component.h"
#include "glm/glm.hpp"

class IDrawableComponent {
public:
    virtual void Draw(const glm::mat4& view, const glm::mat4& projection, const glm::mat4& orthoMatrix = glm::mat4(1.0f)) = 0;
};