#pragma once

#include "Shader.h"

class VertexShader : public Shader {
private:
    unsigned int _shaderId;

public:
    VertexShader(std::string path);
    ~VertexShader();

    unsigned int getGlShaderId();
};