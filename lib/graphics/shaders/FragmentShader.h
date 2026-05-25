#pragma once

#include "Shader.h"

class FragmentShader : public Shader {
private:
    unsigned int _shaderId;

public:
    FragmentShader(std::string path);
    ~FragmentShader();

    unsigned int getGlShaderId();
};