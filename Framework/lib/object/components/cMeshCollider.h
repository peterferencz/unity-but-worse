#pragma once

#include "object/components/Component.h"
#include "object/components/IDrawableComponent.h"
#include "object/components/cMeshView.h"

class cMeshCollider : public Component, public IDrawableComponent {
private:
    cMeshView* _meshView;
    cTransform* _transform;

public:
    cMeshCollider();
    virtual ~cMeshCollider() = default;

    void Draw(const Framework::Math::Mat4& view, const Framework::Math::Mat4& projection, const Framework::Math::Mat4& orthoMatrix = Framework::Math::Mat4(1.0f)) override {};

    Mesh& getMesh();
    Framework::Math::Mat4 getModelMatrix();
};