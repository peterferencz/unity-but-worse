#pragma once

#include <string>

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