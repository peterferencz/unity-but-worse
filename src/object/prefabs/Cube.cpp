#include "object/prefabs/Cube.h"
#include "graphics/mesh/CubeMesh.h"
#include "graphics/mesh/MeshCache.h"

Cube::Cube(glm::vec3 dimensions){
    addComponent(new cTransform(glm::vec3(0,0,0), glm::vec3(0,0,0), dimensions));
    addComponent(new cMeshView(MeshCache::getMesh<CubeMesh>(), new mDefault()));
}

Cube::~Cube(){
    
}