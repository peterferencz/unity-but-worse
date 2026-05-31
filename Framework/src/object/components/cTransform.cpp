#include "object/components/cTransform.h"


cTransform::cTransform()
:cTransform(Framework::Math::Vec3(0,0,0), Framework::Math::Vec3(0,0,0), Framework::Math::Vec3(1,1,1)) { }

cTransform::cTransform(Framework::Math::Vec3 pos, Framework::Math::Vec3 rot, Framework::Math::Vec3 scale)
:_pos(pos),
_rot(rot),
_scale(scale) {
    
}

cTransform::~cTransform() {

}


Framework::Math::Vec3& cTransform::getPosition(){
    return _pos;
}
Framework::Math::Vec3& cTransform::getRotation(){
    return _rot;
}
Framework::Math::Vec3& cTransform::getScale(){
    return _scale;
}

Framework::Math::Mat4 cTransform::getModelMatrix() {
    Framework::Math::Mat4 model = Framework::Math::Mat4(1.0f);
    model = Framework::Math::translate(model, _pos);
    
    model = Framework::Math::rotate(model, Framework::Math::radians(_rot.y), Framework::Math::Vec3(0, 1, 0)); // Yaw
    model = Framework::Math::rotate(model, Framework::Math::radians(_rot.x), Framework::Math::Vec3(1, 0, 0)); // Pitch
    model = Framework::Math::rotate(model, Framework::Math::radians(_rot.z), Framework::Math::Vec3(0, 0, 1)); // Roll

    model = Framework::Math::scale(model, _scale);

    return model;
}