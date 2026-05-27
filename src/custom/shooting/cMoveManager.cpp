#include "custom/shooting/cMoveManager.h"

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
    glm::vec2 currentMousePos = Input::getCursorPosition();
    float mouseXOffset = currentMousePos.x - _lastMousePos.x;
    float mouseYOffset = _lastMousePos.y - currentMousePos.y;
    _lastMousePos = currentMousePos;

    mouseXOffset *= _mouseSensitivity;
    mouseYOffset *= _mouseSensitivity;


    _transform->getRotation().y += mouseXOffset;
    float pitch = _transform->getRotation().x;
    pitch += mouseYOffset;
    pitch = glm::clamp(pitch, -89.f, 89.f);
    _transform->getRotation().x = pitch;
}

void cMoveManager::move(){
    glm::vec3 moveDirection(0);
    glm::vec3 forward(glm::normalize(glm::vec3(cos(glm::radians(_transform->getRotation().y)), 0, sin(glm::radians(_transform->getRotation().y)))));
    glm::vec3 right(glm::normalize(glm::vec3(-sin(glm::radians(_transform->getRotation().y)), 0, cos(glm::radians(_transform->getRotation().y)))));


    if (Input::isKeyDown(GLFW_KEY_W)) moveDirection += forward;
    if (Input::isKeyDown(GLFW_KEY_S)) moveDirection -= forward;
    if (Input::isKeyDown(GLFW_KEY_D)) moveDirection += right;
    if (Input::isKeyDown(GLFW_KEY_A)) moveDirection -= right;

    if (glm::length(moveDirection) > 0.0f) {
        moveDirection = glm::normalize(moveDirection);
    }

    glm::vec3 pos = _transform->getPosition() + (moveDirection * Time::getDeltaTime() * _moveSpeed);
    pos = glm::clamp(pos, glm::vec3(-5), glm::vec3(5));
    _transform->getPosition() = pos;
}