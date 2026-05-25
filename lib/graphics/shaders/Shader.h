#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include "glad/gl.h"

#include "Logger.h"


class Shader {
private:
    std::string readFile(std::string path);

protected:
    std::string _fileContent;
    Shader(std::string path);

public:
    virtual ~Shader();
    virtual unsigned int getGlShaderId() = 0;
};