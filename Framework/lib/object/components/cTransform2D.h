#pragma once

#include "object/components/Component.h"
#include "Math.h"

class cTransform2D : public Component {
private:
    Framework::Math::Vec2 _pos;
    Framework::Math::Vec2 _rot;
    Framework::Math::Vec2 _scale;

public:
    cTransform2D();
    cTransform2D(Framework::Math::Vec2 pos, Framework::Math::Vec2 rot, Framework::Math::Vec2 scale);
    ~cTransform2D();

    Framework::Math::Vec2& getPosition();
    Framework::Math::Vec2& getRotation();
    Framework::Math::Vec2& getScale();

    Framework::Math::Mat4 getModelMatrix();
};