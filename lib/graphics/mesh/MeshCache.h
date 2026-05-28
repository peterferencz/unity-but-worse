#pragma once

#include <map>
#include <string>
#include <memory>

#include "graphics/mesh/Mesh.h"

#include "Logger.h"

class MeshCache {
private:

    static std::map<std::size_t, std::unique_ptr<Mesh>> _meshes;

    MeshCache() = delete;
    ~MeshCache() = delete;
    
public:

    template<typename T>
    static T& getMesh() {
        std::size_t hash = typeid(T).hash_code();
        
        auto iter = _meshes.find(hash);
        if(iter != _meshes.end()){
            return static_cast<T&>(*iter->second);
        }

        Logger::Log("[Mesh] Loaded mesh: " + std::string(typeid(T).name()));
        _meshes[hash] = std::make_unique<T>();
        return static_cast<T&>(*_meshes[hash]);
    }
};

