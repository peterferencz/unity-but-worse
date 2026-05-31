#pragma once

#include "graphics/materials/Material.h"
#include "Math.h"
#include "GL/gl.h"

class mSimpleColor : public Material {
public:
    Framework::Math::Vec3 color;

    mSimpleColor(Framework::Math::Vec3 color);
    ~mSimpleColor();

    void Draw() const override;
};