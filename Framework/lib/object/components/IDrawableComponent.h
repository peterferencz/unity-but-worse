#pragma once

#include "object/components/Component.h"
#include "Math.h"

class IDrawableComponent {
public:
    virtual void Draw(const Framework::Math::Mat4& view, const Framework::Math::Mat4& projection, const Framework::Math::Mat4& orthoMatrix = Framework::Math::Mat4(1.0f)) = 0;
};