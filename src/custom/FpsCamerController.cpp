#include "custom/FpsCameraController.h"

void FpsCamerController::onAwake() {
    requireComponent(_transform);
    requireComponent(_camera);
}

void FpsCamerController::onStart(){
    Input::captureCursor();
    _lastMousePos = Input::getCursorPosition();
    _focused = true;
}

void FpsCamerController::onUpdate(){
    glm::vec2 currentMouse = Input::getCursorPosition();
    glm::vec2 delta = _focused ? currentMouse - _lastMousePos : glm::vec2(0,0);
    _lastMousePos = currentMouse;

    
    float yaw = _transform->getRotation().y;
    yaw += delta.x * _sensitivity;
    _transform->getRotation().x -= delta.y * _sensitivity;
    
    _transform->getRotation().x = glm::clamp(_transform->getRotation().x, -89.0f, 89.0f);
    yaw -= (((int)yaw) / 360) * 360;
    _transform->getRotation().y = yaw;

    float speed = 5.0f;
    glm::vec3 moveDir(0.0f);
    
    glm::vec3 forward(
        cos(glm::radians(_transform->getRotation().y)) * cos(glm::radians(_transform->getRotation().x)),
        sin(glm::radians(_transform->getRotation().x)),
        sin(glm::radians(_transform->getRotation().y)) * cos(glm::radians(_transform->getRotation().x))
    );
    glm::vec3 right = glm::normalize(glm::cross(forward, glm::vec3(0, 1, 0)));
    glm::vec3 up(0,1,0);

    if(Input::isKeyDown(GLFW_KEY_W)) { moveDir += forward; }
    if(Input::isKeyDown(GLFW_KEY_S)) { moveDir -= forward; }
    if(Input::isKeyDown(GLFW_KEY_D)) { moveDir += right; }
    if(Input::isKeyDown(GLFW_KEY_A)) { moveDir -= right; }
    if(Input::isKeyDown(GLFW_KEY_SPACE)) { moveDir += up; }
    if(Input::isKeyDown(GLFW_KEY_LEFT_SHIFT)) { moveDir -= up; }
    
    if(Input::isKeyDown(GLFW_KEY_ESCAPE))             {
        _focused = false;
        Input::releaseCursor();
    }
    if(Input::isMouseButtonDown(GLFW_MOUSE_BUTTON_1)) {
        _lastMousePos = Input::getCursorPosition();
        _focused = true;
        Input::captureCursor();
    }

    if(glm::length(moveDir) > 0.0f) {
        _transform->getPosition() += glm::normalize(moveDir) * speed * Time::getDeltaTime();
    }
}