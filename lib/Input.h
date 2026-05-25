#pragma once

#include <bitset>

#include "glm/glm.hpp"
#include "GLFW/glfw3.h"

class Window;

class Input{
friend class Window;
private:
    static std::bitset<512> _keys;
    static std::bitset<8> _mouseButtons;
    static glm::vec2 _cursorPos;
    static bool _isCursorCaptured;

    static void setKeyStatus(int key, bool pressed);
    static void setMouseButtonStatus(int button, bool pressed);
    static void setCursorPosition(double x, double y);

    static GLFWwindow* _window;
public:
    static bool isKeyDown(int key);

    static bool isMouseButtonDown(int button);
    static glm::vec2 const& getCursorPosition();

    static void captureCursor();
    static void releaseCursor();
    static bool isCursorCaptured();
};
