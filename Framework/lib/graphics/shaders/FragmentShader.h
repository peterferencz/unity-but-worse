#pragma once

#include "Shader.h"

class ShaderCache;  //FWDecl

class FragmentShader : public Shader {
friend class ShaderCache;
private:
    
    FragmentShader();
    static FragmentShader* FromCode(const std::string& code);
    static FragmentShader* FromCode(const std::string& code, std::string& message);

protected:

public:
    ~FragmentShader();
};