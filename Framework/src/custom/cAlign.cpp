#include "glad/gl.h"

#include "custom/cAlign.h"

cAlign::cAlign(HorizontalAlignment const& ha, VerticalAlignment const& va)
: _ha(ha), _va(va), _transform(nullptr), _screenView(nullptr) {

}

cAlign::~cAlign() {

}

void cAlign::onAwake(){
    requireComponent(_transform);
    requireComponent(_screenView);
}

void cAlign::onStart(){

}

void cAlign::onUpdate() {
    GLint m_viewport[4];
    glGetIntegerv(GL_VIEWPORT, m_viewport);

    float width = static_cast<float>(m_viewport[2]);
    float height = static_cast<float>(m_viewport[3]);

    Framework::Math::Vec2 targetPos = _transform->getPosition();

    switch (_ha) {
        case HorizontalAlignment::Left:
            targetPos.x = 0.0f;
            break;
        case HorizontalAlignment::Center:
            targetPos.x = width / 2.0f;
            break;
        case HorizontalAlignment::Right:
            targetPos.x = width - _transform->getScale().x / 2;
            break;
    }

    switch (_va) {
        case VerticalAlignment::Top:
            targetPos.y = 0.0f;
            break;
        case VerticalAlignment::Middle:
            targetPos.y = height / 2.0f;
            break;
        case VerticalAlignment::Bottom:
            targetPos.y = height - _transform->getScale().y / 2;
            break;
    }

    _transform->getPosition() = targetPos;
}