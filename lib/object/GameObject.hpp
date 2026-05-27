#pragma once

#include <vector>

class Component;
#include "object/components/Component.h"
#include "Logger.h"

class GameObject {
protected:
    std::vector<Component*> _components;
    
public:
    GameObject();
    GameObject(std::initializer_list<Component*> components);
    virtual ~GameObject();


    void addComponent(Component* component);

    /// @brief Returns the first component of type T
    /// @tparam T a type of Component
    /// @return the component or `nullptr`
    template <class T>
    T* getFirstComponent(){
        for (auto* comp : _components) {
            if (T* casted = dynamic_cast<T*>(comp)) {
                return casted;
            }
        }
        return nullptr;
    }

    template <class T>
    std::vector<T*> getAllComponents() {
        std::vector<T*> found;
        for (auto* comp : _components) {
            if (T* casted = dynamic_cast<T*>(comp)) {
                found.push_back(casted);
            }
        }
        return found;
    }

};
