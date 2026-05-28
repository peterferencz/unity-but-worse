#include "graphics/shaders/ShaderCache.h"

std::unordered_map<std::string, std::unique_ptr<VertexShader>> ShaderCache::_vertexShaders;
std::unordered_map<std::string, std::unique_ptr<FragmentShader>> ShaderCache::_fragmentShaders;


VertexShader& ShaderCache::getVertexShader(const std::string& path) {
    auto iter = _vertexShaders.find(path);
    if(iter != _vertexShaders.end()){
        return static_cast<VertexShader&>(*iter->second);
    }
    _vertexShaders[path] = std::unique_ptr<VertexShader>(new VertexShader(path, VertexShader::ConstructorToken{}));
    return static_cast<VertexShader&>(*_vertexShaders[path]);
}

FragmentShader& ShaderCache::getFragmentShader(const std::string& path) {
    auto iter = _fragmentShaders.find(path);
    if(iter != _fragmentShaders.end()){
        return static_cast<FragmentShader&>(*iter->second);
    }
    _fragmentShaders[path] = std::unique_ptr<FragmentShader>(new FragmentShader(path, FragmentShader::ConstructorToken{}));
    return static_cast<FragmentShader&>(*_fragmentShaders[path]);
}