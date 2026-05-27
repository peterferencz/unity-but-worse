#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform.h"
#include "object/components/cMeshView.h"
#include "object/components/cMeshCollider.h"
#include "object/components/cCamera.h"

class cMoveManager : public cBehaviour {
private:
    cTransform* _transform;
    cMeshView* _meshView;
    cCamera* _camera;

    float _moveSpeed = 10.0f;
    float _mouseSensitivity = 0.1f;
    
    glm::vec2 _lastMousePos{0.0f, 0.0f};

    void look();
    void move();

public:
    cMoveManager();
    ~cMoveManager();

    void onAwake() override;
    void onStart() override;
    void onUpdate() override;
};