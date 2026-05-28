#include "graphics/mesh/MeshCache.h"

std::map<std::size_t, std::unique_ptr<Mesh>> MeshCache::_meshes;