#pragma once

#include <string>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "Scene.hpp"
#include "Math.h"

class Window {
private:
    std::string _title;
    Framework::Math::Vec2 _dimensions;

    GLFWwindow* _glfwWindow;
    Scene* _scene;

    Window();

private:

    GLFWwindow* getGlfwWindow();

    static void scb_error(int error, const char* description);
    static void scb_key(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void scb_cursor_position(GLFWwindow* window, double xpos, double ypos);
    static void scb_mouse_button(GLFWwindow* window, int button, int action, int mods);
    static void scb_framebuffer_size(GLFWwindow* window, int width, int height);

public:
    Window(int width, int height, std::string title);
    ~Window();

    void MainLoop();

    void setScene(Scene& scene);
    const Scene& getScene();

    static Window* instance;

protected:
    void onResize(int width, int height);
    void onExit();
};