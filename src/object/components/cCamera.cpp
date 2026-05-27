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

glm::mat4 cCamera::getViewMatrix(){
    if(_transform == nullptr) {
        _transform = _gameObject->getFirstComponent<cTransform>();
        
        if(_transform == nullptr){
            Logger::Error("No transform on gameobject with camera");
            return glm::mat4(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
        }
    }

    glm::vec3 pos = _transform->getPosition();

    return glm::lookAt(pos, pos + forward(), glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::vec3 cCamera::forward(){
    glm::vec3 rot = _transform->getRotation();
    glm::vec3 forward;
    forward.x = cos(glm::radians(rot.y)) * cos(glm::radians(rot.x));
    forward.y = sin(glm::radians(rot.x));
    forward.z = sin(glm::radians(rot.y)) * cos(glm::radians(rot.x));

    return glm::normalize(forward);
}

Ray cCamera::forwardRay(){
    return Ray(_transform->getPosition(), forward());
}

glm::mat4 cCamera::getProjectionMatrix() {
    return glm::perspective(glm::radians(_fov), _aspectRatio, _near, _far);
}