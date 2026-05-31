#include "custom/FreeCameraController.h"

void FreeCameraController::onAwake() {
    requireComponent(_transform);
    requireComponent(_camera);
}

void FreeCameraController::onStart(){
    Input::captureCursor();
    _lastMousePos = Input::getCursorPosition();
    _focused = true;
}

void FreeCameraController::onUpdate(){
    Framework::Math::Vec2 currentMouse = Input::getCursorPosition();
    Framework::Math::Vec2 delta = _focused ? currentMouse - _lastMousePos : Framework::Math::Vec2(0,0);
    _lastMousePos = currentMouse;

    
    float yaw = _transform->getRotation().y;
    yaw += delta.x * _sensitivity;
    _transform->getRotation().x -= delta.y * _sensitivity;
    
    _transform->getRotation().x = Framework::Math::clamp(_transform->getRotation().x, -89.0f, 89.0f);
    yaw -= (((int)yaw) / 360) * 360;
    _transform->getRotation().y = yaw;

    float speed = 5.0f;
    Framework::Math::Vec3 moveDir(0.0f);
    
    Framework::Math::Vec3 forward(
        cos(Framework::Math::radians(_transform->getRotation().y)) * cos(Framework::Math::radians(_transform->getRotation().x)),
        sin(Framework::Math::radians(_transform->getRotation().x)),
        sin(Framework::Math::radians(_transform->getRotation().y)) * cos(Framework::Math::radians(_transform->getRotation().x))
    );
    Framework::Math::Vec3 right = Framework::Math::normalize(Framework::Math::cross(forward, Framework::Math::Vec3(0, 1, 0)));
    Framework::Math::Vec3 up(0,1,0);

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

    if(Framework::Math::length(moveDir) > 0.0f) {
        _transform->getPosition() += Framework::Math::normalize(moveDir) * speed * Time::getDeltaTime();
    }
}