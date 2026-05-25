#pragma once

#include "object/components/Component.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class cTransform2D : public Component {
private:
    glm::vec2 _pos;
    glm::vec2 _rot;
    glm::vec2 _scale;

public:
    cTransform2D();
    cTransform2D(glm::vec2 pos, glm::vec2 rot, glm::vec2 scale);
    ~cTransform2D();

    glm::vec2& getPosition();
    glm::vec2& getRotation();
    glm::vec2& getScale();

    glm::mat4 getModelMatrix();
};