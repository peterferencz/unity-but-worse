#pragma once

#include "object/components/Component.h"

class cBehaviour : public Component {

public:
    virtual ~cBehaviour() {}

    virtual void onAwake() {}
    virtual void onStart() {}
    virtual void onUpdate() {}

    template <typename T>
    void requireComponent(T*& var){
        if(_gameObject == nullptr){ Logger::Error("RequrieComponent was called before component was attached to a gameobject"); }
        
        T* found = _gameObject->getFirstComponent<T>();
        if(found == nullptr){
            std::string errorMsg = std::string("[") + typeid(*this).name() + "] requires component \"" 
                + typeid(T).name() + "\", but it was not found on the GameObject. Disabling component.";
            Logger::Error(errorMsg);
            setEnabled(false);
        }else{
            var = found;
        }
    }
};