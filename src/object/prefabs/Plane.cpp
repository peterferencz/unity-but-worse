#include "object/prefabs/Plane.h"

#include "graphics/mesh/MeshCache.h"

Plane::Plane(glm::vec2 size) {
    addComponent(new cTransform(glm::vec3(0,0,0), glm::vec3(-90,0,0), glm::vec3(size.x, size.y, 1)));
    addComponent(new cMeshView(MeshCache::getMesh<QuadMesh>(), new mDefault()));
}

Plane::~Plane() {

}