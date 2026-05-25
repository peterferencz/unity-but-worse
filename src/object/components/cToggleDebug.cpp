#include "object/components/cToggleDebug.h"

cToggleDebug::cToggleDebug(){

}

cToggleDebug::~cToggleDebug(){

}

void cToggleDebug::onAwake(){
    requireComponent(_camera);
    requireComponent(_transform);
}

void cToggleDebug::onStart(){
    
}

void cToggleDebug::onUpdate(){
    if(!Input::isKeyPressed(GLFW_KEY_F12)){ return; }
    
    if(Debug::isEnabled()){
        Debug::disable();
        _camera->setEnabled(false);
        
        if(_prevCam != nullptr){
            _prevCam->setEnabled();
        }
    }else{
        Debug::enable();
        
        std::vector<cCamera*> cameras = Scene::getActiveScene()->getEnabledComponentsOfType<cCamera>();
        if(!cameras.empty()){
            _prevCam = cameras[0];
            _prevCam->setEnabled(false);
            _transform->getPosition() = _prevCam->getParent()->getFirstComponent<cTransform>()->getPosition();
        }

        _camera->setEnabled();
    }
}