#include "object/prefabs/DebugObject.h"


DebugObject::DebugObject(){
    addComponent(new cTransform());
    cCamera* cam = new cCamera();
    cam->setEnabled(false);
    addComponent(cam);
    addComponent(new FreeCameraController());
    addComponent(new cToggleDebug());
}

DebugObject::~DebugObject(){

}