#include "object/components/cCamera.h"


cCamera::cCamera()
: _fov(60.0f),
_aspectRatio(16.0f / 9.0f),
_near(.1f),
_far(100.0f) {

}

void cCamera::setAspectRatio(float aspectRatio){
    _aspectRatio = aspectRatio;
}

void cCamera::setFov(float fov){
    _fov = fov;
}

Framework::Math::Mat4 cCamera::getViewMatrix(){
    if(_transform == nullptr) {
        _transform = _gameObject->getFirstComponent<cTransform>();
        
        if(_transform == nullptr){
            Logger::Error("No transform on gameobject with camera");
            return Framework::Math::Mat4(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
        }
    }

    Framework::Math::Vec3 pos = _transform->getPosition();

    return Framework::Math::lookAt(pos, pos + forward(), Framework::Math::Vec3(0.0f, 1.0f, 0.0f));
}

Framework::Math::Vec3 cCamera::forward(){
    Framework::Math::Vec3 rot = _transform->getRotation();
    Framework::Math::Vec3 forward;
    forward.x = cos(Framework::Math::radians(rot.y)) * cos(Framework::Math::radians(rot.x));
    forward.y = sin(Framework::Math::radians(rot.x));
    forward.z = sin(Framework::Math::radians(rot.y)) * cos(Framework::Math::radians(rot.x));

    return Framework::Math::normalize(forward);
}

Ray cCamera::forwardRay(){
    return Ray(_transform->getPosition(), forward());
}

Framework::Math::Mat4 cCamera::getProjectionMatrix() {
    return Framework::Math::perspective(Framework::Math::radians(_fov), _aspectRatio, _near, _far);
}