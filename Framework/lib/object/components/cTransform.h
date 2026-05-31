#pragma once

#include "object/components/Component.h"
#include "Math.h"

class cTransform : public Component {
private:
    Framework::Math::Vec3 _pos;
    Framework::Math::Vec3 _rot;
    Framework::Math::Vec3 _scale;
    
public:
    cTransform();
    cTransform(Framework::Math::Vec3 pos, Framework::Math::Vec3 rot, Framework::Math::Vec3 scale);
    ~cTransform();

    Framework::Math::Vec3& getPosition();

    /// @brief Return rotation in Euler angles
    /// @return Vec3(pitch, yaw, roll)
    Framework::Math::Vec3& getRotation();
    Framework::Math::Vec3& getScale();


    Framework::Math::Mat4 getModelMatrix();
};