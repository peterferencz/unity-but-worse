#pragma once


#include "object/components/Component.h"
#include "object/components/IDrawableComponent.h"
#include "graphics/mesh/Mesh.h"
#include "graphics/materials/Material.h"

class cScreenView : public Component, public IDrawableComponent {
private:
    Mesh* _mesh;
    Material* _material;
    Material* _debugMaterial;

public:
    cScreenView(Mesh* mesh, Material* material);
    ~cScreenView();

    Material* getMaterial();
    void setMaterial(Material* material);

    Mesh* getMesh();

    void Draw(const glm::mat4& view, const glm::mat4& projection, const glm::mat4& orthoMatrix = glm::mat4(1.0f)) override;
};