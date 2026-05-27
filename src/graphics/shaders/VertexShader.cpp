#include "graphics/shaders/VertexShader.h"

VertexShader::VertexShader(std::string path)
:Shader(path) {
    _shaderId = glCreateShader(GL_VERTEX_SHADER);
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
    Logger::Log("[Shader] Loaded vertex shader: " + path);
}

VertexShader::~VertexShader(){
    
}

unsigned int VertexShader::getGlShaderId(){
    return _shaderId;
}