#include "object/GameObject.hpp"

GameObject::GameObject() {
}

GameObject::GameObject(std::vector<Component*> components)
: _components(components) {
    
}

GameObject::~GameObject() {
    for (auto* comp : _components) delete comp;
}

void GameObject::addComponent(Component* component){
    _components.push_back(component);
    component->setParent(this);
}