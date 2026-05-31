#include "Scene.hpp"

#include "object/components/cMeshView.h"
#include "object/components/cScreenView.h"


Scene::Scene() {
    #ifdef DEBUG
        AddGameObject(new DebugObject());
    #endif
}

Scene::~Scene() {
    for(auto* go : _gameObjets) delete go;
}

void Scene::AddGameObject(GameObject* go){
    _gameObjets.push_back(go);
    
    // Call start on all behaviours if the scene has already started
    if(_hasStarted){
        std::vector<cBehaviour*> behaviours = go->getAllComponents<cBehaviour>();
        if(!behaviours.empty()){
            for(cBehaviour* ptr : behaviours){
                ptr->onAwake();
                ptr->onStart();
            }
        }
    }
}

Scene* Scene::_activeScene = nullptr;

Scene* Scene::getActiveScene(){
    return _activeScene;
}

void Scene::Start(){
    if(_hasStarted){ 
        Logger::Warn("Scene.Start has been called when it has already started");
        return;
    }

    for(cBehaviour* behaviour : getEnabledComponentsOfType<cBehaviour>()){
        behaviour->onAwake();
    }

    _hasStarted = true;

    for(cBehaviour* behaviour : getEnabledComponentsOfType<cBehaviour>()){
        behaviour->onStart();
    }
}

void Scene::Update(){
    for(cBehaviour* behaviour : getEnabledComponentsOfType<cBehaviour>()){
        behaviour->onUpdate();
    }
}

void Scene::Render(int width, int height){
    std::vector<cCamera*> cameras = getEnabledComponentsOfType<cCamera>();
    if(cameras.empty()){
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        Logger::Warn("No camera found in scene");
        return;
    } else if(cameras.size() > 1){
        Logger::Warn("Multiple cameras are rendering in the scene");
    }

    cCamera* camera = cameras[0];
    camera->setAspectRatio(((float)width) / height);

    glViewport(0, 0, width, height);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    


    Framework::Math::Mat4 view = camera->getViewMatrix();
    Framework::Math::Mat4 projection = camera->getProjectionMatrix();
    Framework::Math::Mat4 orthoMatrix = Framework::Math::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);


    std::vector<cMeshView*> drawableMeshes = getEnabledComponentsOfType<cMeshView>();
    for(cMeshView* component : drawableMeshes){
        component->Draw(view, projection, orthoMatrix);
    }


    std::vector<cScreenView*> drawableScreenRects = getEnabledComponentsOfType<cScreenView>();
    for(cScreenView* component : drawableScreenRects){
        component->Draw(view, projection, orthoMatrix);
    }
}