#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform.h"
#include "object/components/cMeshView.h"
#include "object/components/cMeshCollider.h"

class cEnemy : public cBehaviour {
private:
    cTransform* _transform;
    cMeshView* _meshView;
    cMeshCollider* _meshCollider;

    float _speed = 2;    
public:
    cEnemy();
    ~cEnemy();
    
    void die();

    void onAwake() override;
    void onStart() override;
    void onUpdate() override;
};