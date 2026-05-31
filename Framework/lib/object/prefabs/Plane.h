#pragma once

#include "object/GameObject.hpp"
#include "object/components/cTransform.h"
#include "graphics/mesh/Mesh.h"
#include "graphics/materials/mDefault.h"
#include "object/components/cMeshView.h"
#include "graphics/mesh/QuadMesh.h"
#include "Math.h"

class Plane : public GameObject {
private:

public:
    Plane(Framework::Math::Vec2 size);
    ~Plane();
};