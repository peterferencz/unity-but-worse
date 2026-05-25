#pragma once

#include <vector>

#include "object/components/Component.h"
#include "object/components/IDrawableComponent.h"
#include "graphics/mesh/Mesh.h"
#include "graphics/materials/Material.h"
#include "object/components/cTransform.h"
#include "object/components/cTransform2D.h"
#include "glm/matrix.hpp"
#include "Time.h"
#include "Debug.h"
#include "graphics/materials/mDebug.h"

//requires transform
class cMeshView : public Component, public IDrawableComponent {
private:
    Mesh* _mesh;
    Material* _material;
    Material* _debugMaterial;

public:
    cMeshView(Mesh* mesh, Material* material);
    ~cMeshView();

    Material* getMaterial();
    void setMaterial(Material* material);

    void Draw(const glm::mat4& view, const glm::mat4& projection, const glm::mat4& orthoMatrix = glm::mat4(1.0f)) override;
};