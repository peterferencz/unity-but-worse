#include "graphics/shaders/Shader.h"

#include <fstream>
#include <sstream>

#include "Logger.h"
#include "glad/gl.h"


Shader::Shader(std::string path, ConstructorToken){
    _fileContent = readFile(path);
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