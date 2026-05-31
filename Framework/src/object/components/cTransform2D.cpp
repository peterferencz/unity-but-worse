#include "object/components/cTransform2D.h"


cTransform2D::cTransform2D() 
: _pos(Framework::Math::Vec2(0,0)), 
_rot(Framework::Math::Vec2(0,0)), 
_scale(Framework::Math::Vec2(1,1)) {

}

cTransform2D::cTransform2D(Framework::Math::Vec2 pos, Framework::Math::Vec2 rot, Framework::Math::Vec2 scale)
:_pos(pos), _rot(rot), _scale(scale) {

}

cTransform2D::~cTransform2D() { }

Framework::Math::Vec2& cTransform2D::getPosition(){
    return _pos;
}

Framework::Math::Vec2& cTransform2D::getRotation(){
    return _rot;
}

Framework::Math::Vec2& cTransform2D::getScale(){
    return _scale;
}


Framework::Math::Mat4 cTransform2D::getModelMatrix(){
    using Framework::Math::Mat4;
    using Framework::Math::Vec3;
    Mat4 translation = Framework::Math::translate(Mat4(1.0f), Vec3(_pos, 0.0f));
    Mat4 rotation = Framework::Math::rotate(Mat4(1.0f), Framework::Math::radians(_rot.x), Vec3(0.0f, 0.0f, 1.0f));
    Mat4 scaling = Framework::Math::scale(Mat4(1.0f), Vec3(_scale, 1.0f));

    return translation * rotation * scaling;
}