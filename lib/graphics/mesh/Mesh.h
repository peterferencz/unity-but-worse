#pragma once

#include <vector>
#include <string>

#include "glm/glm.hpp"

class MeshCache;    //FWDecl

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

class Mesh{
friend class MeshCache;
// friend struct std::make_unique<T>
private:
    unsigned int _vao, _vbo, _ebo;
    unsigned int _indexCount;
    
    std::vector<Vertex> _verticies;
    std::vector<unsigned int> _indices;

protected:
    /// @brief Uploads data to the GPU
    /// @param vertices Vertex data
    /// @param indices Triangle indicies
    void uploadData(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

    
    
    
public:

    Mesh();
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    virtual ~Mesh();

    std::vector<Vertex>& getVerticies();
    std::vector<unsigned int>& getIndicies();

    void Bind();
    void Unbind();
    unsigned int getIndexCount() const { return _indexCount; }
};