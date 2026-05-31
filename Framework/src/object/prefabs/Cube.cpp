#include "object/prefabs/Cube.h"
#include "graphics/mesh/CubeMesh.h"
#include "graphics/mesh/MeshCache.h"

Cube::Cube(Framework::Math::Vec3 dimensions){
    addComponent(new cTransform(Framework::Math::Vec3(0,0,0), Framework::Math::Vec3(0,0,0), dimensions));
    addComponent(new cMeshView(MeshCache::getMesh<CubeMesh>(), new mDefault()));
}

Cube::~Cube(){
    
}