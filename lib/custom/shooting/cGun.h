#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform2D.h"
#include "object/components/cScreenView.h"
#include "object/components/cMeshCollider.h"
#include "object/components/cCamera.h"

class cGun : public cBehaviour {
private:
    cTransform2D* _transform;
    cScreenView* _view;

    const float RELOADTIME = 1;
    float _timeSinceShot;

    void shoot();
    
public:
    cGun();
    ~cGun();

    void onAwake() override;
    void onStart() override;
    void onUpdate() override;
};