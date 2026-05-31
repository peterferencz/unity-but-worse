#include "cMoveManager.h"

#include "Input.h"

cMoveManager::cMoveManager() {

}

cMoveManager::~cMoveManager() {

}

void cMoveManager::onAwake() {
    requireComponent(_transform);
    requireComponent(_meshView);
    requireComponent(_camera);
}

void cMoveManager::onStart() {
    Input::captureCursor();
    _lastMousePos = Input::getCursorPosition();
}

void cMoveManager::onUpdate() {
    if(Input::isKeyPressed(GLFW_KEY_ESCAPE)) { Input::releaseCursor(); }

    look();
    move();
}

void cMoveManager::look(){
    Framework::Math::Vec2 currentMousePos = Input::getCursorPosition();
    float mouseXOffset = currentMousePos.x - _lastMousePos.x;
    float mouseYOffset = _lastMousePos.y - currentMousePos.y;
    _lastMousePos = currentMousePos;

    mouseXOffset *= _mouseSensitivity;
    mouseYOffset *= _mouseSensitivity;


    _transform->getRotation().y += mouseXOffset;
    float pitch = _transform->getRotation().x;
    pitch += mouseYOffset;
    pitch = Framework::Math::clamp(pitch, -89.f, 89.f);
    _transform->getRotation().x = pitch;
}

void cMoveManager::move(){
    using Framework::Math::Vec3;
    Vec3 moveDirection(0);
    Vec3 forward(Framework::Math::normalize(Vec3(cos(Framework::Math::radians(_transform->getRotation().y)), 0, sin(Framework::Math::radians(_transform->getRotation().y)))));
    Vec3 right(Framework::Math::normalize(Vec3(-sin(Framework::Math::radians(_transform->getRotation().y)), 0, cos(Framework::Math::radians(_transform->getRotation().y)))));


    if (Input::isKeyDown(GLFW_KEY_W)) moveDirection += forward;
    if (Input::isKeyDown(GLFW_KEY_S)) moveDirection -= forward;
    if (Input::isKeyDown(GLFW_KEY_D)) moveDirection += right;
    if (Input::isKeyDown(GLFW_KEY_A)) moveDirection -= right;

    if (Framework::Math::length(moveDirection) > 0.0f) {
        moveDirection = Framework::Math::normalize(moveDirection);
    }

    Vec3 pos = _transform->getPosition() + (moveDirection * Time::getDeltaTime() * _moveSpeed);
    pos = Framework::Math::clamp(pos, Vec3(-5), Vec3(5));
    _transform->getPosition() = pos;
}