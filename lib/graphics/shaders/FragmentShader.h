#pragma once

#include "Shader.h"

class ShaderCache;  //FWDecl

class FragmentShader : public Shader {
friend class ShaderCache;
private:
    unsigned int _shaderId;

protected:
    FragmentShader(std::string path);
    
public:
    ~FragmentShader();

    unsigned int getGlShaderId();
};