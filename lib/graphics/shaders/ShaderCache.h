#pragma once

#include "VertexShader.h"
#include "FragmentShader.h"

#include <unordered_map>
#include <string>
#include <memory>

class ShaderCache {
private:
    static std::unordered_map<std::string, std::unique_ptr<VertexShader>> _vertexShaders;
    static std::unordered_map<std::string, std::unique_ptr<FragmentShader>> _fragmentShaders;

    ShaderCache() = delete;
    ~ShaderCache() = delete;
public:

    static VertexShader& getVertexShader(const std::string& path);
    static FragmentShader& getFragmentShader(const std::string& path);
};