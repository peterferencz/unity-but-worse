#pragma once

#include "Shader.h"

class ShaderCache;    //FWDecl

class VertexShader : public Shader {
friend class ShaderCache;
private:
    unsigned int _shaderId;

protected:
    VertexShader(std::string path);

public:
    ~VertexShader();

    unsigned int getGlShaderId();
};