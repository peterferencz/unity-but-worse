#pragma once

#include <string>
#include "stb_image.h"

#include "GL/gl.h"
#include "GL/glext.h"
#include "Logger.h"

class Texture {
private:
    std::string _path;
    unsigned int _textureId;

public:
    Texture(std::string const& path);
    ~Texture();

    void Bind() const;
    void Unbind() const;
};