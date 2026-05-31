#pragma once

#include "Math.h"
#include "object/GameObject.hpp"


struct RaycastHit {
    bool hit = false;
    float distance = 0.0f;
    Framework::Math::Vec3 point = Framework::Math::Vec3(0.0f);
    GameObject* gameObject = nullptr;
};
