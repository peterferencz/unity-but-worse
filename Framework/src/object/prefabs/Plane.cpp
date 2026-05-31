#include "object/prefabs/Plane.h"

#include "graphics/mesh/MeshCache.h"

Plane::Plane(Framework::Math::Vec2 size) {
    using Framework::Math::Vec3;
    addComponent(new cTransform(Vec3(0,0,0), Vec3(-90,0,0), Vec3(size.x, size.y, 1)));
    addComponent(new cMeshView(MeshCache::getMesh<QuadMesh>(), new mDefault()));
}

Plane::~Plane() {

}