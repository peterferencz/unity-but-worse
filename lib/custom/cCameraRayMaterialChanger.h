#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cCamera.h"
#include "object/components/cTransform.h"

class cCameraRayMaterialChanger : public cBehaviour {
private:
    cTransform* _transform;
    cCamera* _camera;


public:
    cCameraRayMaterialChanger();
    ~cCameraRayMaterialChanger();

    void onAwake() override;
    void onStart() override;
    void onUpdate() override;
};

