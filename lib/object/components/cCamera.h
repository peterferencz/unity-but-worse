#pragma once

#include "object/components/Component.h"
#include "object/components/cTransform.h"
#include "Logger.h"
#include "glm/vec3.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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

    glm::vec3 forward();

    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();
};