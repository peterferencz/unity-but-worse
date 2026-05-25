#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform2D.h"
#include "object/components/cMeshView.h"
#include "graphics/shaders/Texture.h"
#include "Input.h"

class cCursor : public cBehaviour {
private:

    cTransform2D* _transform;
    cMeshView* _meshView;
    glm::vec2 _offset;

public:
    cCursor(glm::vec2 offset = glm::vec2(0));
    ~cCursor();

    void onAwake();
    void onStart();
    void onUpdate();

};