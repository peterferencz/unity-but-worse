#include "graphics/shaders/Shader.h"


Shader::Shader(std::string path){
    _fileContent = readFile(path);

    // _shaderId = glCreateShader(fragment ? GL_FRAGMENT_SHADER : GL_VERTEX_SHADER);
    // const char* source = _fileContent.c_str();
    // glShaderSource(_shaderId, 1, &source, NULL);
    // glCompileShader(_shaderId);

    // int success;
    // glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &success);
    // if (!success) {
    //     char infoLog[512];
    //     glGetShaderInfoLog(_shaderId, 512, NULL, infoLog);
    //     Logger::Error("Shader compilation failed: " + std::string(infoLog));
    // }
    // Logger::Log("Loaded shader: " + path);
}

Shader::~Shader(){

}

std::string Shader::readFile(std::string path){
    std::ifstream fileStream(path, std::ios::in);

    if(!fileStream.is_open()) {
        Logger::Error("Could not read file " + path + ". File does not exist.");
        return "";
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();

    fileStream.close();

    return buffer.str();
}