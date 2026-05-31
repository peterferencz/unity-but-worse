#pragma once

#include <vector>

#include "Logger.h"
#include "Debug.h"
#include "object/GameObject.hpp"
#include "object/components/cCamera.h"
#include "object/components/cBehaviour.h"
#include "graphics/shaders/ShaderCache.h"

#ifdef DEBUG
    #include "object/prefabs/DebugObject.h"
#endif

class Window;   //FWDecl

class Scene {
friend class Window;
private:
    std::vector<GameObject*> _gameObjets;
    bool _hasStarted = false;

    static Scene* _activeScene;
    

public:
    Scene();
    ~Scene();
    
    void Start();
    void Update();

    void AddGameObject(GameObject* go);

    void Render(int width, int height);

    ShaderCache& getShaderStore();
    
    static Scene* getActiveScene();

    template <typename T>
    std::vector<T*> getComponentsOfType(){
        std::vector<T*> components;

        for(auto* go : _gameObjets){
            std::vector<T*> goComponents  = go->getAllComponents<T>();
            if(!goComponents.empty()){
                for(T* p : goComponents){
                    components.push_back(p);
                }
            }
        }

        return components;
    }

    template <typename T>
    std::vector<T*> getEnabledComponentsOfType(){
        std::vector<T*> components;

        for(auto* go : _gameObjets){
            std::vector<T*> goComponents  = go->getAllComponents<T>();
            for(T* p : goComponents){
                if(p != nullptr && p->isEnabled()){
                    components.push_back(p);
                }
            }
        }

        return components;
    }
};
