#pragma once

#include <vector>

#include "object/components/Component.h"
#include "graphics/mesh/Mesh.h"
#include "graphics/materials/Material.h"
#include "object/components/cTransform.h"
#include "object/components/cTransform2D.h"
#include "glm/matrix.hpp"
#include "Time.h"

//requires transform
class cMeshView : public Component {
private:
    Mesh* _mesh;
    Material* _material;

public:
    cMeshView(Mesh* mesh, Material* material);
    ~cMeshView();

    Material* getMaterial();
    void setMaterial(Material* material);

    void Draw(const glm::mat4& view, const glm::mat4& projection, const glm::mat4& orthoMatrix = glm::mat4(1.0f));
};