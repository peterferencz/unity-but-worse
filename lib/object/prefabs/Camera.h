#pragma once

#include "object/GameObject.hpp"
#include "object/components/cCamera.h"
#include "object/components/cTransform.h"

class Camera : public GameObject {
public:
    Camera();
    ~Camera();
};
