#include "object/prefabs/Cube.h"


Cube::Cube(glm::vec3 dimensions){
    addComponent(new cTransform(glm::vec3(0,0,0), glm::vec3(0,0,0), dimensions));

    std::vector<Vertex> vtx = {
        // Front face
        {{-0.5f, -0.5f,  0.5f}, {0, 0, 1}, {0, 0}}, {{0.5f, -0.5f,  0.5f}, {0, 0, 1}, {1, 0}}, {{0.5f,  0.5f,  0.5f}, {0, 0, 1}, {1, 1}}, {{-0.5f,  0.5f,  0.5f}, {0, 0, 1}, {0, 1}},
        // Back face
        {{ 0.5f, -0.5f, -0.5f}, {0, 0, -1}, {0, 0}}, {{-0.5f, -0.5f, -0.5f}, {0, 0, -1}, {1, 0}}, {{-0.5f,  0.5f, -0.5f}, {0, 0, -1}, {1, 1}}, {{ 0.5f,  0.5f, -0.5f}, {0, 0, -1}, {0, 1}},
        // Top face
        {{-0.5f,  0.5f,  0.5f}, {0, 1, 0}, {0, 0}}, {{ 0.5f,  0.5f,  0.5f}, {0, 1, 0}, {1, 0}}, {{ 0.5f,  0.5f, -0.5f}, {0, 1, 0}, {1, 1}}, {{-0.5f,  0.5f, -0.5f}, {0, 1, 0}, {0, 1}},
        // Bottom face
        {{-0.5f, -0.5f, -0.5f}, {0, -1, 0}, {0, 0}}, {{ 0.5f, -0.5f, -0.5f}, {0, -1, 0}, {1, 0}}, {{ 0.5f, -0.5f,  0.5f}, {0, -1, 0}, {1, 1}}, {{-0.5f, -0.5f,  0.5f}, {0, -1, 0}, {0, 1}},
        // Left face
        {{-0.5f, -0.5f, -0.5f}, {-1, 0, 0}, {0, 0}}, {{-0.5f, -0.5f,  0.5f}, {-1, 0, 0}, {1, 0}}, {{-0.5f,  0.5f,  0.5f}, {-1, 0, 0}, {1, 1}}, {{-0.5f,  0.5f, -0.5f}, {-1, 0, 0}, {0, 1}},
        // Right face
        {{ 0.5f, -0.5f,  0.5f}, {1, 0, 0}, {0, 0}}, {{ 0.5f, -0.5f, -0.5f}, {1, 0, 0}, {1, 0}}, {{ 0.5f,  0.5f, -0.5f}, {1, 0, 0}, {1, 1}}, {{ 0.5f,  0.5f,  0.5f}, {1, 0, 0}, {0, 1}}
    };
    std::vector<unsigned int> ids;
    for (unsigned int i = 0; i < 6; ++i) {
        ids.push_back(i * 4 + 0); ids.push_back(i * 4 + 1); ids.push_back(i * 4 + 2);
        ids.push_back(i * 4 + 0); ids.push_back(i * 4 + 2); ids.push_back(i * 4 + 3);
    }
    Mesh* cubeMesh = new Mesh(vtx, ids);

    addComponent(new cMeshView(cubeMesh, new mDefault()));
}

Cube::~Cube(){
    
}