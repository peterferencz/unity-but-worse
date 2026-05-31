#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform2D.h"
#include "object/components/cScreenView.h"
#include "graphics/shaders/Texture.h"
#include "Input.h"

class cCursor : public cBehaviour {
private:

    cTransform2D* _transform;
    cScreenView* _view;
    Framework::Math::Vec2 _offset;

public:
    cCursor(Framework::Math::Vec2 offset = Framework::Math::Vec2(0));
    ~cCursor();

    void onAwake();
    void onStart();
    void onUpdate();

};