#include "object/GameObject.hpp"

GameObject::GameObject() {
}

GameObject::GameObject(std::initializer_list<Component*> components) {
    for (Component* comp : components) {
        addComponent(comp);
    }
}

GameObject::~GameObject() {
    for (auto* comp : _components) delete comp;
}

void GameObject::addComponent(Component* component){
    _components.push_back(component);
    component->setParent(this);
}