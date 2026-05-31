#pragma once

#include "object/components/Component.h"
#include "object/components/cTransform.h"
#include "Logger.h"
#include "glm/vec3.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "physics/Physics.h"
#include "Math.h"

// Requires Transform
class cCamera : public Component {
private:
    float _fov;
    float _aspectRatio;
    float _near;
    float _far;

    cTransform* _transform = nullptr;

public:
    cCamera();

    void setFov(float fov);
    void setAspectRatio(float aspectratio);

    Framework::Math::Vec3 forward();
    Ray forwardRay();

    Framework::Math::Mat4 getViewMatrix();
    Framework::Math::Mat4 getProjectionMatrix();
};