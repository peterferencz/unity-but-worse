#include "graphics/shaders/FragmentShader.h"

FragmentShader::FragmentShader(std::string path)
:Shader(path) {
    _shaderId = glCreateShader(GL_FRAGMENT_SHADER);
    const char* source = _fileContent.c_str();
    glShaderSource(_shaderId, 1, &source, NULL);
    glCompileShader(_shaderId);

    int success;
    glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(_shaderId, 512, NULL, infoLog);
        Logger::Error("[Shader] Shader compilation failed: " + std::string(infoLog));
    }
    Logger::Log("[Shader] Loaded fragment shader: " + path);
}

FragmentShader::~FragmentShader(){
    
}

unsigned int FragmentShader::getGlShaderId(){
    return _shaderId;
}