#pragma once

#include "glm/glm.hpp"
#include "object/GameObject.hpp"


struct RaycastHit {
    bool hit = false;
    float distance = 0.0f;
    glm::vec3 point = glm::vec3(0.0f);
    GameObject* gameObject = nullptr;
};
