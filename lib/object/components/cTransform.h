#pragma once

#include "glm/glm.hpp"
#include "object/components/Component.h"
#include "glm/ext/matrix_transform.hpp"

class cTransform : public Component {
private:
    glm::vec3 _pos;
    glm::vec3 _rot;
    glm::vec3 _scale;
    
public:
    cTransform();
    cTransform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);
    ~cTransform();

    glm::vec3& getPosition();

    /// @brief Return rotation in Euler angles
    /// @return Vec3(pitch, yaw, roll)
    glm::vec3& getRotation();
    glm::vec3& getScale();


    glm::mat4 getModelMatrix();
};