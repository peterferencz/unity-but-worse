#include "object/components/cTransform.h"


cTransform::cTransform()
:cTransform(glm::vec3(0,0,0), glm::vec3(0,0,0), glm::vec3(1,1,1)) { }

cTransform::cTransform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale)
:_pos(pos),
_rot(rot),
_scale(scale) {
    
}

cTransform::~cTransform() {

}


glm::vec3& cTransform::getPosition(){
    return _pos;
}
glm::vec3& cTransform::getRotation(){
    return _rot;
}
glm::vec3& cTransform::getScale(){
    return _scale;
}

glm::mat4 cTransform::getModelMatrix() {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, _pos);
    
    model = glm::rotate(model, glm::radians(_rot.y), glm::vec3(0, 1, 0)); // Yaw
    model = glm::rotate(model, glm::radians(_rot.x), glm::vec3(1, 0, 0)); // Pitch
    model = glm::rotate(model, glm::radians(_rot.z), glm::vec3(0, 0, 1)); // Roll

    model = glm::scale(model, _scale);

    return model;
}