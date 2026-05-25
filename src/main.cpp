#include <iostream>

#include "Window.h"
#include "Logger.h"
#include "object/prefabs/Cube.h"
#include "glm/vec3.hpp"
#include "object/prefabs/Camera.h"
#include "object/prefabs/Plane.h"
#include "custom/FreeCameraController.h"
#include "custom/Rotator.h"
#include "graphics/materials/mSimpleTexture.h"
#include "object/components/cTransform2D.h"
#include "custom/cCursor.h"

int main(){
    Logger::Log("Program start");

    Window w(700, 600, "Hehe");

#pragma region Main scene
    Scene main;
    Cube* cube = new Cube(glm::vec3(1, 1, 1));
    cube->getFirstComponent<cTransform>()->getPosition() = glm::vec3(0, 0.5f, 0);
    cube->getFirstComponent<cMeshView>()->setMaterial(new mSimpleColor(glm::vec3(0.7f,0.7f, 0.85f)));
    cube->addComponent(new Rotator(1000));

    Cube* szirmay = new Cube(glm::vec3(1, 1, 1));
    szirmay->getFirstComponent<cTransform>()->getPosition() = glm::vec3(0, 0.5f, 3);
    szirmay->getFirstComponent<cTransform>()->getScale().x = 2;
    szirmay->getFirstComponent<cMeshView>()->setMaterial(new mSimpleTexture(new Texture("resources/images/szirmay.jpeg")));
    szirmay->addComponent(new Rotator(100));

    Plane* plane = new Plane(glm::vec2(10, 10));
    plane->getFirstComponent<cMeshView>()->setMaterial(new mSimpleTexture(new Texture("resources/images/bkfl.jpg")));

    Camera* camera = new Camera();
    camera->getFirstComponent<cTransform>()->getPosition() = glm::vec3(-5, 1, 0);
    camera->addComponent(new FreeCameraController());

    Cube* checker = new Cube(glm::vec3(1, 1, 1));
    checker->getFirstComponent<cTransform>()->getPosition() = glm::vec3(3, 0.5f, 0);
    checker->getFirstComponent<cMeshView>()->setMaterial(new Material(
        new VertexShader("resources/shaders/vertexshader.glsl"),
        new FragmentShader("resources/shaders/fCensored.glsl")
    ));


    GameObject* uiImg = new GameObject();
    uiImg->addComponent(new cTransform2D(glm::vec2(300, 250), glm::vec2(0), glm::vec2(128, 128)));
    uiImg->addComponent(new cMeshView(new QuadMesh(), new mSimpleTexture(new Texture("resources/images/time.jpg"))));
    
    GameObject* cursor = new GameObject();
    cursor->addComponent(new cTransform2D(glm::vec2(0), glm::vec2(0), glm::vec2(300, 300)));
    cursor->addComponent(new cMeshView(new QuadMesh(), new mSimpleTexture(new Texture("resources/images/pointer.png"))));
    cursor->addComponent(new cCursor(glm::vec2(-28, 39)));

    main.AddGameObject(cube);
    main.AddGameObject(szirmay);
    main.AddGameObject(plane);
    main.AddGameObject(checker);
    main.AddGameObject(camera);
    main.AddGameObject(uiImg);
    main.AddGameObject(cursor);
#pragma endregion


    Scene game;
    
    Plane* pl = new Plane(glm::vec2(10,10));

    Camera* cam = new Camera();
    cam->getFirstComponent<cTransform>()->getPosition() = glm::vec3(-5, 1, 0);
    cam->addComponent(new FreeCameraController());

    game.AddGameObject(pl);
    game.AddGameObject(cam);
    

    w.setScene(game);
    w.MainLoop();
}