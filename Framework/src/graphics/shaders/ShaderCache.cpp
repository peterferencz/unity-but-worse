#include "graphics/shaders/ShaderCache.h"

#include "__generated/shaders/fSimpleColor.h"
#include "__generated/shaders/fSimpleTexture.h"
#include "__generated/shaders/vDefaultVertex.h"

#include <fstream>
#include <sstream>

#include "Logger.h"

static const std::string DEFAULT_VERTEX_SHADER = "baked:vertex";
static const std::string DEFAULT_FRAGMENT_SHADER = "baked:color";

std::unordered_map<std::string, std::unique_ptr<VertexShader>> ShaderCache::_vertexShaders;
std::unordered_map<std::string, std::unique_ptr<FragmentShader>> ShaderCache::_fragmentShaders;
bool ShaderCache::_isInitialized = false;

bool ShaderCache::InitializeShaders() {
    _isInitialized = true;

    ShaderCache::_vertexShaders[DEFAULT_VERTEX_SHADER] = 
        std::unique_ptr<VertexShader>(VertexShader::FromCode(reinterpret_cast<const char*>(resources_shaders_vDefaultVertex_glsl)));
    Logger::Log("[Shader] Loaded vertex shader into cache (" + DEFAULT_VERTEX_SHADER + ")");
        
    ShaderCache::_fragmentShaders[DEFAULT_FRAGMENT_SHADER] = 
        std::unique_ptr<FragmentShader>(FragmentShader::FromCode(reinterpret_cast<const char*>(resources_shaders_fSimpleColor_glsl)));
    Logger::Log("[Shader] Loaded fragment shader into cache (" + DEFAULT_FRAGMENT_SHADER + ")");
    ShaderCache::_fragmentShaders["baked:texture"] = 
        std::unique_ptr<FragmentShader>(FragmentShader::FromCode(reinterpret_cast<const char*>(resources_shaders_fSimpleTexture_glsl)));
    Logger::Log("[Shader] Loaded fragment shader into cache (baked:texture)");
        
    Logger::Log("[Shader] ShaderCache initialized");
    return true;
}

std::string ShaderCache::ReadFile(const std::string& path) {
    std::ifstream fileStream(path, std::ios::in);

    if(!fileStream.is_open()) {
        Logger::Error("[Shader] Unable to open shader file \"" + path + "\"");
        return "";
    }

    std::stringstream buffer;
    buffer << fileStream.rdbuf();

    fileStream.close();

    return buffer.str();
}

VertexShader& ShaderCache::getVertexShader(const std::string& path) {
    if(!_isInitialized) { InitializeShaders(); }
    auto iter = _vertexShaders.find(path);
    if(iter != _vertexShaders.end()){
        return static_cast<VertexShader&>(*iter->second);
    }

    const std::string file = ReadFile(path);
    if(file == ""){
        if(path == DEFAULT_VERTEX_SHADER){
            Logger::Fatal("[Shader] Unable to open baked vertex shader");
        }
        return getVertexShader(DEFAULT_VERTEX_SHADER);
    }

    std::string compileMessage;
    VertexShader* vtx = VertexShader::FromCode(file, compileMessage);
    if(vtx == nullptr){
        Logger::Error("[Shader] Shader compilation error: " + compileMessage);
        if(path == DEFAULT_VERTEX_SHADER){
            Logger::Fatal("[Shader] Unable to compile baked vertex shader");
        }
        return getVertexShader(DEFAULT_VERTEX_SHADER);
    }

    Logger::Log("[Shader] Loaded vertex shader into cache (" + path + ")");
    _vertexShaders[path] = std::unique_ptr<VertexShader>(vtx);
    return static_cast<VertexShader&>(*_vertexShaders[path]);
}

FragmentShader& ShaderCache::getFragmentShader(const std::string& path) {
    if(!_isInitialized) { InitializeShaders(); }

    auto iter = _fragmentShaders.find(path);
    if(iter != _fragmentShaders.end()){
        return static_cast<FragmentShader&>(*iter->second);
    }

    const std::string file = ReadFile(path);
    if(file == ""){
        if(path == DEFAULT_FRAGMENT_SHADER){
            Logger::Fatal("[Shader] Unable to open baked fragment shader");
        }
        return getFragmentShader(DEFAULT_FRAGMENT_SHADER);
    }

    std::string compileMessage;
    FragmentShader* vtx = FragmentShader::FromCode(file, compileMessage);
    if(vtx == nullptr){
        Logger::Error("[Shader] Shader compilation error: " + compileMessage);
        if(path == DEFAULT_FRAGMENT_SHADER){
            Logger::Fatal("[Shader] Unable to compile baked fragment shader");
        }
        return getFragmentShader(DEFAULT_FRAGMENT_SHADER);
    }

    Logger::Log("[Shader] Loaded fragment shader into cache (" + path + ")");
    _fragmentShaders[path] = std::unique_ptr<FragmentShader>(vtx);
    return static_cast<FragmentShader&>(*_fragmentShaders[path]);
}