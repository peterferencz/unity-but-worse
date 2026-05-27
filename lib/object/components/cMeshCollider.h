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

    void Draw(const glm::mat4& view, const glm::mat4& projection, const glm::mat4& orthoMatrix = glm::mat4(1.0f)) override {};

    Mesh* getMesh();
    glm::mat4 getModelMatrix();
};