#include "graphics/shaders/Shader.h"

#include "Logger.h"
#include "glad/gl.h"


Shader::Shader(){ }

Shader::~Shader(){ }

unsigned int Shader::getGlShaderId(){
    return _shaderId;
}

bool Shader::loadShader(GLenum shaderType, const std::string& shaderCode, std::string& out_errorMessage) {
    _shaderId = glCreateShader(shaderType);
    const char* sourcePtr = shaderCode.c_str();
    glShaderSource(_shaderId, 1, &sourcePtr, NULL);
    glCompileShader(_shaderId);

    int success;
    glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        out_errorMessage.reserve(512);
        char infoLog[512];
        glGetShaderInfoLog(_shaderId, 512, NULL, &out_errorMessage[0]);
        return false;
    }
    
    return true;
}