#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform.h"
#include "Logger.h"
#include "Input.h"
#include "Time.h"

//requires transform
class Rotator : public cBehaviour {
private:
    cTransform* _transform;
    float _speed;

public:
    Rotator(float speed = 5) : _speed(speed) {}

    void onStart() override;
    void onUpdate() override;
};