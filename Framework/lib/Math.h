#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace Framework::Math {
    using Vec2 = glm::vec2;
    using Vec3 = glm::vec3;
    using Vec4 = glm::vec4;
    using Mat4 = glm::mat4;
    using Quat = glm::quat;

    using glm::lookAt;
    using glm::translate;
    using glm::ortho;
    using glm::clamp;
    using glm::radians;
    using glm::length;
    using glm::normalize;
    using glm::cross;
    using glm::degrees;
    using glm::value_ptr;
    using glm::perspective;
    using glm::rotate;
    using glm::scale;
    using glm::dot;
    using glm::distance;
    using glm::inverse;
}