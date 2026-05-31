#pragma once

#include <string>

class Shader {
private:

protected:
    bool loadShader(unsigned int haderType, const std::string& shaderCode, std::string& errorMessage);
    
    unsigned int _shaderId;

public:
    
    Shader();
    virtual ~Shader() = 0;
    unsigned int getGlShaderId();
};