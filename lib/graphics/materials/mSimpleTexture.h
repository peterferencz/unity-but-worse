#pragma once

#include "graphics/materials/Material.h"
#include "graphics/shaders/Texture.h"
#include "glm/glm.hpp"
#include "GL/gl.h"


class mSimpleTexture : public Material {
private:
    Texture* _texture;

public:

    mSimpleTexture(Texture* texture);
    ~mSimpleTexture();

    void Draw() override;
};