#include "Input.h"

std::bitset<512> Input::_keys;
std::bitset<512> Input::_keyPressedFired;
std::bitset<8> Input::_mouseButtons;
Framework::Math::Vec2 Input::_cursorPos;
bool Input::_isCursorCaptured = false;

bool Input::isKeyDown(int key) {
    if (key < 0 || key >= 512) return false;
    return _keys[key];
}

bool Input::isKeyPressed(int key) {
    if (key < 0 || key >= 512) return false;
    if(_keys[key] && !_keyPressedFired[key]){
        _keyPressedFired[key] = true;
        return true;
    }
    return false;
}

void Input::setKeyStatus(int key, bool pressed) {
    if (key >= 0 && key < 512) {
        _keys[key] = pressed;
        if(!pressed){
            _keyPressedFired[key] = false;
        }
    }
}

bool Input::isMouseButtonDown(int button) {
    if (button < 0 || button >= 8) return false;
    return _mouseButtons[button];
}

void Input::setMouseButtonStatus(int button, bool pressed) {
    if (button >= 0 && button < 8) _mouseButtons[button] = pressed;
}

void Input::setCursorPosition(double x, double y){
    _cursorPos.x = x;
    _cursorPos.y = y;
}

Framework::Math::Vec2 const& Input::getCursorPosition(){
    return _cursorPos;
}

GLFWwindow* Input::_window = nullptr;

void Input::captureCursor(){
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    _isCursorCaptured = true;
}

void Input::releaseCursor(){
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    _isCursorCaptured = false;
}

bool Input::isCursorCaptured(){
    return _isCursorCaptured;
}