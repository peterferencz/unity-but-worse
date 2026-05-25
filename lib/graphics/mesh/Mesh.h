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

protected:
    void setupMesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);

public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
    virtual ~Mesh();

    void Bind();
    void Unbind();
    unsigned int getIndexCount() const { return _indexCount; }
};