#pragma once

#include <bitset>

#include "GLFW/glfw3.h"
#include "Math.h"

class Window;

class Input{
friend class Window;
private:
    static std::bitset<512> _keys;
    static std::bitset<512> _keyPressedFired;
    static std::bitset<8> _mouseButtons;
    static Framework::Math::Vec2 _cursorPos;
    static bool _isCursorCaptured;

    static void setKeyStatus(int key, bool pressed);
    static void setMouseButtonStatus(int button, bool pressed);
    static void setCursorPosition(double x, double y);

    static GLFWwindow* _window;
public:
    
    /// @brief Returns weather a key is being held down
    /// @param key GLFW_KEY
    /// @return The key state
    static bool isKeyDown(int key);
    
    /// @brief Returns true on the first frame a key is pressed
    /// @param key GLFW_KEY
    /// @return True during one `update` when the key is pressed
    static bool isKeyPressed(int key);

    static bool isMouseButtonDown(int button);
    static Framework::Math::Vec2 const& getCursorPosition();

    static void captureCursor();
    static void releaseCursor();
    static bool isCursorCaptured();
};
