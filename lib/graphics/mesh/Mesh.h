#pragma once

#include <vector>

#include "glad/gl.h"
#include "glm/glm.hpp"

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

class Mesh{
private:
    unsigned int _vao, _vbo, _ebo;
    unsigned int _indexCount;
    
    std::vector<Vertex> _verticies;
    std::vector<unsigned int> _indices;

protected:
    void setupMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    virtual ~Mesh();

    std::vector<Vertex>& getVerticies();
    std::vector<unsigned int>& getIndicies();

    void Bind();
    void Unbind();
    unsigned int getIndexCount() const { return _indexCount; }
};