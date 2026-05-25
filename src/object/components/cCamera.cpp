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
    cTransform* transform = _gameObject->getFirstComponent<cTransform>();
    if(transform == nullptr){
        Logger::Error("No transform on gameobject with camera");
        return glm::mat4(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    }

    glm::vec3 pos = transform->getPosition();
    glm::vec3 rot = transform->getRotation();

    glm::vec3 front;
    front.x = cos(glm::radians(rot.y)) * cos(glm::radians(rot.x));
    front.y = sin(glm::radians(rot.x));
    front.z = sin(glm::radians(rot.y)) * cos(glm::radians(rot.x));

    return glm::lookAt(pos, pos + glm::normalize(front), glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 cCamera::getProjectionMatrix() {
    return glm::perspective(glm::radians(_fov), _aspectRatio, _near, _far);
}