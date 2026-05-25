#pragma once

#include "object/GameObject.hpp"
#include "object/components/cTransform2D.h"
#include "object/components/cMeshView.h"
#include "object/components/cToggleDebug.h"
#include "graphics/mesh/QuadMesh.h"
#include "graphics/materials/mSimpleTexture.h"
#include "custom/FreeCameraController.h"

class DebugObject : public GameObject {
private:

public:
    DebugObject();
    ~DebugObject();
};