#pragma once

#include "VertexShader.h"
#include "FragmentShader.h"

#include <map>
#include <string>

class ShaderCache {
private:

    static std::map<std::string, VertexShader*> _vertexShaders;
    static std::map<std::string, FragmentShader*> _fragmentShaders;

    ShaderCache();
    ~ShaderCache();
public:

    static VertexShader* getVertexShader(std::string path);
    static FragmentShader* getFragmentShader(std::string path);
};