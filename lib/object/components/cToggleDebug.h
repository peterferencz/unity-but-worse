#pragma once 

#include "cBehaviour.h"
#include "cTransform2D.h"
#include "cCamera.h"
#include "cMeshView.h"
#include "Input.h"
#include "Debug.h"
#include "Scene.hpp"

class cToggleDebug : public cBehaviour {
private:
    cCamera* _camera;
    cTransform* _transform;
    cCamera* _prevCam;

public:
    cToggleDebug();
    ~cToggleDebug();

    void onAwake() override;
    void onStart() override;
    void onUpdate() override;

};