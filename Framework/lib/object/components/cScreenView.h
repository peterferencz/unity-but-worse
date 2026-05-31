#pragma once


#include "object/components/Component.h"
#include "object/components/IDrawableComponent.h"
#include "graphics/mesh/Mesh.h"
#include "graphics/materials/Material.h"

class cScreenView : public Component, public IDrawableComponent {
private:
    Mesh& _mesh;
    Material* _material;
    Material* _debugMaterial;

public:
    cScreenView(Mesh& mesh, Material* material);
    ~cScreenView();

    Material* getMaterial();
    void setMaterial(Material* material);

    Mesh& getMesh();

    void Draw(const Framework::Math::Mat4& view, const Framework::Math::Mat4& projection, const Framework::Math::Mat4& orthoMatrix = Framework::Math::Mat4(1.0f)) override;
};