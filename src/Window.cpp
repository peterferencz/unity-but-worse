#include "Window.h"

Window* Window::instance = nullptr;

Window::Window(int width, int height, std::string title)
: _dimensions(glm::vec2(width, height)),
_title(title),
_scene(nullptr) {
    if(instance != nullptr) {
        Logger::Fatal("Window is already initialized");
    }
    instance = this;

    glfwSetErrorCallback(scb_error);

    bool glfwInitRes = glfwInit();
    if(!glfwInitRes){
        Logger::Fatal("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    _glfwWindow = glfwCreateWindow(_dimensions.x, _dimensions.y, _title.c_str(), NULL, NULL);
    if(_glfwWindow == nullptr){
        glfwTerminate();
        const char* description;
        int code = glfwGetError(&description);
        if(description){
            Logger::Error(description);
        }
        Logger::Fatal("Could not create glfw window");
    }
    glfwSetWindowUserPointer(_glfwWindow, this);
    Input::_window = _glfwWindow;

    glfwMakeContextCurrent(_glfwWindow);

    bool glLoadRes = gladLoadGL(glfwGetProcAddress);
    if(!glLoadRes){
        Logger::Fatal("Failed to load OpenGL");
    }

    glfwSetKeyCallback(_glfwWindow, scb_key);
    glfwSetCursorPosCallback(_glfwWindow, scb_cursor_position);
    glfwSetMouseButtonCallback(_glfwWindow, scb_mouse_button);
    glfwSetFramebufferSizeCallback(_glfwWindow, scb_framebuffer_size);

    glfwSwapInterval(1);
    glEnable(GL_DEPTH_TEST);

    //Enable face culling
    glEnable(GL_CULL_FACE);

    //Enable alpha
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Logger::Log("Window created");
}

void Window::scb_error(int error, const char* description){
    Logger::Error(description);
}

void Window::scb_key(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Window* instance = static_cast<Window*>(glfwGetWindowUserPointer(window));

    if (instance == nullptr){
        Logger::Error("Received key event withouth a window user pointer");
        return;
    }

    if (action == GLFW_PRESS){
        Input::setKeyStatus(key, true);
    } else if (action == GLFW_RELEASE){
        Input::setKeyStatus(key, false);
    }
}

void Window::scb_cursor_position(GLFWwindow* window, double xpos, double ypos) {
    Input::setCursorPosition(xpos, ypos);
}

void Window::scb_framebuffer_size(GLFWwindow* window, int width, int height) {
    Window* instance = static_cast<Window*>(glfwGetWindowUserPointer(window));

    if (instance) {
        instance->onResize(width, height);
    }
}

void Window::scb_mouse_button(GLFWwindow* window, int button, int action, int mods) {
    if (action == GLFW_PRESS) {
        Input::setMouseButtonStatus(button, true);
    } else if (action == GLFW_RELEASE) {
        Input::setMouseButtonStatus(button, false);
    }
}

void Window::setScene(Scene& scene){
    _scene = &scene;
}

const Scene& Window::getScene(){
    return *_scene;
}

void Window::MainLoop() {
    if(_scene == nullptr){
        Logger::Error("No active scene set");
        return;
    }

    //Set initial cursor positions, so start can poll it
    double startX, startY;
    glfwGetCursorPos(_glfwWindow, &startX, &startY);
    Input::setCursorPosition(startX, startY);

    _scene->Start();

    double time = glfwGetTime();

    while (!glfwWindowShouldClose(_glfwWindow)) {
        
        //Render
        glViewport(0, 0, _dimensions.x, _dimensions.y);
        _scene->Render(_dimensions.x, _dimensions.y);
        glfwSwapBuffers(_glfwWindow);

        //Tick
        double newTime = glfwGetTime();
        Time::deltaTime = newTime - time;
        Time::timeStamp += Time::deltaTime;
        _scene->Update();
        time = newTime;
        
        glfwPollEvents();
    }

    onExit();
}

Window::~Window(){
    if(_glfwWindow != nullptr){
        glfwDestroyWindow(_glfwWindow);
    }
    instance = nullptr;
    Input::_window = nullptr;
}

GLFWwindow* Window::getGlfwWindow(){
    return _glfwWindow;
}


void Window::onExit() {
    Logger::Log("Window exit");
}


void Window::onResize(int width, int height){
    _dimensions.x = width;
    _dimensions.y = height;
}
