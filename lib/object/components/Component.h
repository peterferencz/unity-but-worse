#pragma once

class GameObject;
#include "object/GameObject.hpp"
#include <string>

class Component {
private:
    friend class GameObject;
    void setParent(GameObject* gameObject) {_gameObject = gameObject;}

    
protected:
    bool _enabled = true;
    GameObject* _gameObject;

    
public:
    Component() {}
    virtual ~Component() {}
    
    GameObject* getParent() { return _gameObject; }

    bool isEnabled() {return _enabled;}
    void setEnabled(bool eanabled = true){_enabled = eanabled;}
};
