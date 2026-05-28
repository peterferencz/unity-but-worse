#pragma once

#include "Shader.h"

class ShaderCache;  //FWDecl

class FragmentShader : public Shader {
friend class ShaderCache;
private:
    unsigned int _shaderId;

protected:

public:
    
    FragmentShader(std::string path, ConstructorToken);
    ~FragmentShader();

    unsigned int getGlShaderId();
};