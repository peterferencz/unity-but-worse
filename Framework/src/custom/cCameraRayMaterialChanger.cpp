#include "custom/cCameraRayMaterialChanger.h"
#include "physics/Physics.h"
#include "object/components/cMeshView.h"
#include "Input.h"

cCameraRayMaterialChanger::cCameraRayMaterialChanger() {

}

cCameraRayMaterialChanger::~cCameraRayMaterialChanger() {

}

void cCameraRayMaterialChanger::onAwake(){
    requireComponent(_transform);
    requireComponent(_camera);
}

void cCameraRayMaterialChanger::onStart(){

}

void cCameraRayMaterialChanger::onUpdate(){
    RaycastHit hit = Physics::Raycast(_camera->forwardRay());
    if(!hit.hit){ return; }

    cMeshView* meshView = hit.gameObject->getFirstComponent<cMeshView>();
    if(meshView == nullptr) { return; }

    Framework::Math::Vec3& color = dynamic_cast<mSimpleColor*>(meshView->getMaterial())->color;
    if(Input::isMouseButtonDown(GLFW_MOUSE_BUTTON_1)){
        color = Framework::Math::Vec3(1, .3, .3);
    }else{
        color = Framework::Math::Vec3(.3, 1, .3);
    }
}