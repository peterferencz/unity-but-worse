#include "object/components/cTransform2D.h"


cTransform2D::cTransform2D() 
: _pos(glm::vec2(0,0)), 
_rot(glm::vec2(0,0)), 
_scale(glm::vec2(1,1)) {

}

cTransform2D::cTransform2D(glm::vec2 pos, glm::vec2 rot, glm::vec2 scale)
:_pos(pos), _rot(rot), _scale(scale) {

}

cTransform2D::~cTransform2D() { }

glm::vec2& cTransform2D::getPosition(){
    return _pos;
}

glm::vec2& cTransform2D::getRotation(){
    return _rot;
}

glm::vec2& cTransform2D::getScale(){
    return _scale;
}


glm::mat4 cTransform2D::getModelMatrix(){
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), glm::vec3(_pos, 0.0f));
    glm::mat4 rotation    = glm::rotate(glm::mat4(1.0f), glm::radians(_rot.x), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4 scaling     = glm::scale(glm::mat4(1.0f), glm::vec3(_scale, 1.0f));

    return translation * rotation * scaling;
}