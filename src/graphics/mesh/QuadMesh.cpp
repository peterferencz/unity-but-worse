#include "graphics/mesh/QuadMesh.h"

QuadMesh::QuadMesh() : Mesh({}, {}) {
    std::vector<Vertex> vertices = {
        {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 1.0f}}, // Bottom-Left
        {{ 0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 1.0f}}, // Bottom-Right
        {{ 0.5f,  0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1.0f, 0.0f}}, // Top-Right
        {{-0.5f,  0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f}}  // Top-Left
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        0, 2, 3
    };

    setupMesh(vertices, indices);
}

QuadMesh::~QuadMesh() {

}