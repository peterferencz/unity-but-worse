#include "graphics/shaders/ShaderCache.h"

std::map<std::string, VertexShader*> ShaderCache::_vertexShaders;
std::map<std::string, FragmentShader*> ShaderCache::_fragmentShaders;

ShaderCache::ShaderCache() {

}

ShaderCache::~ShaderCache() {
    for(auto vtxSh : _vertexShaders){
        delete vtxSh.second;
    }
    for(auto fragSh : _fragmentShaders){
        delete fragSh.second;
    }
}


VertexShader* ShaderCache::getVertexShader(std::string path) {
    auto iter = _vertexShaders.find(path);
    if(iter != _vertexShaders.end()){
        return iter->second;
    }
    VertexShader* newVertexShader = new VertexShader(path);
    _vertexShaders.insert({path, newVertexShader});
    return newVertexShader;
}

FragmentShader* ShaderCache::getFragmentShader(std::string path) {
    auto iter = _fragmentShaders.find(path);
    if(iter != _fragmentShaders.end()){
        return iter->second;
    }
    FragmentShader* newFragmentShader = new FragmentShader(path);
    _fragmentShaders.insert({path, newFragmentShader});
    return newFragmentShader;
}