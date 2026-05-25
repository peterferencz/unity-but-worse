#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform.h"
#include "object/components/cCamera.h"
#include "GLFW/glfw3.h"
#include "Input.h"
#include "Logger.h"
#include "Time.h"

//required: cCamera
class FpsCamerController : public cBehaviour {
private:
    cTransform* _transform;
    cCamera* _camera;
    
    float _sensitivity = 0.1f;
    bool _focused = false;
    glm::vec2 _lastMousePos;

public:
    void onAwake() override;
    void onStart() override;
    void onUpdate() override;
};