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
#include "custom/cCameraRayMaterialChanger.h"
#include "object/components/cMeshCollider.h"
#include "custom/cAlign.h"
#include "graphics/shaders/ShaderCache.h"
#include "graphics/mesh/CubeMesh.h"
#include "custom/shooting/cMoveManager.h"
#include "custom/shooting/cGun.h"
#include "object/components/cScreenView.h"
#include "custom/shooting/cEnemySpawner.h"
#include "graphics/mesh/MeshCache.h"

Scene* genFunkyScene(){
    Scene* scene = new Scene();

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
        ShaderCache::getVertexShader("resources/shaders/vertexshader.glsl"),
        ShaderCache::getFragmentShader("resources/shaders/fCensored.glsl")
    ));


    GameObject* uiImg = new GameObject();
    uiImg->addComponent(new cTransform2D(glm::vec2(300, 250), glm::vec2(0), glm::vec2(128, 128)));
    uiImg->addComponent(new cScreenView(MeshCache::getMesh<QuadMesh>(), new mSimpleTexture(new Texture("resources/images/time.jpg"))));
    
    GameObject* cursor = new GameObject();
    cursor->addComponent(new cTransform2D(glm::vec2(0), glm::vec2(0), glm::vec2(300, 300)));
    cursor->addComponent(new cScreenView(MeshCache::getMesh<QuadMesh>(), new mSimpleTexture(new Texture("resources/images/pointer.png"))));
    cursor->addComponent(new cCursor(glm::vec2(-28, 39)));

    scene->AddGameObject(cube);
    scene->AddGameObject(szirmay);
    scene->AddGameObject(plane);
    scene->AddGameObject(checker);
    scene->AddGameObject(camera);
    scene->AddGameObject(uiImg);
    scene->AddGameObject(cursor);

    return scene;
}

Scene* genRaycastScene(){
    Scene* scene = new Scene();

    Camera* cam = new Camera();
    cam->getFirstComponent<cTransform>()->getPosition() = glm::vec3(-5, 1, 0);
    cam->addComponent(new FreeCameraController());
    cam->addComponent(new cCameraRayMaterialChanger());
    scene->AddGameObject(cam);

    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            Cube* target = new Cube();
            target->getFirstComponent<cTransform>()->getPosition() = glm::vec3(x *1.5f , 0, y * 1.5f);
            target->getFirstComponent<cMeshView>()->setMaterial(new mSimpleColor(glm::vec3(.7,.7,.7)));
            target->addComponent(new cMeshCollider());
            scene->AddGameObject(target);
        }
    }

    GameObject* fpsCursor = new GameObject();
    fpsCursor->addComponent(new cTransform2D(glm::vec2(10, 10), glm::vec2(0), glm::vec2(10, 10)));
    fpsCursor->addComponent(new cScreenView(MeshCache::getMesh<QuadMesh>(), new mSimpleColor(glm::vec3(1,1,1))));
    fpsCursor->addComponent(new cAlign(HorizontalAlignment::Center, VerticalAlignment::Middle));
    scene->AddGameObject(fpsCursor);

    return scene;
}

Scene* genGameScene(){
    Scene* scene = new Scene();

    GameObject* player = new GameObject{
        new cTransform(glm::vec3(0, 1, 0), glm::vec3(0), glm::vec3(1, 2, 1)),
        new cMeshView(MeshCache::getMesh<CubeMesh>(), new mSimpleColor(glm::vec3(1,0,0))),
        new cCamera(),
        new cMoveManager(),
    };

    GameObject* gun = new GameObject{
        new cTransform2D(glm::vec2(0), glm::vec2(0), glm::vec2(300, 300)),
        new cScreenView(MeshCache::getMesh<QuadMesh>(), new mSimpleTexture(new Texture("resources/images/gun.png"))),
        new cAlign(HorizontalAlignment::Center, VerticalAlignment::Bottom),
        new cGun()
    };

    GameObject* crosshair = new GameObject{
        new cTransform2D(glm::vec2(0), glm::vec2(0), glm::vec2(10, 10)),
        new cScreenView(MeshCache::getMesh<QuadMesh>(), new mSimpleColor(glm::vec3(1))),
        new cAlign(HorizontalAlignment::Center, VerticalAlignment::Middle)
    };

    GameObject* spawner = new GameObject{
        new cEnemySpawner()
    };

    Plane* plane = new Plane(glm::vec2(10,10));
    plane->getFirstComponent<cMeshView>()->setMaterial(new mSimpleTexture(new Texture("resources/images/grass.png")));

    scene->AddGameObject(player);
    scene->AddGameObject(gun);
    scene->AddGameObject(crosshair);
    scene->AddGameObject(plane);
    scene->AddGameObject(spawner);

    return scene;
}

int main(){
    Logger::Log("Program start");

    Window w(700, 600, "Hehe");

    // Scene* main = genFunkyScene();
    // w.setScene(*main);

    Scene* ray = genRaycastScene();
    w.setScene(*ray);
    
    // Scene* game = genGameScene();
    // w.setScene(*game);
    

    w.MainLoop();
}
