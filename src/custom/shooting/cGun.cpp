#include "custom/shooting/cGun.h"

#include "Scene.hpp"
#include "physics/Physics.h"
#include "Input.h"
#include "custom/shooting/cEnemy.h"

cGun::cGun() {

}

cGun::~cGun() {

}

void cGun::onAwake() {
    requireComponent(_transform);
    requireComponent(_view);
}

void cGun::onStart() {

}

void cGun::onUpdate() {
    _timeSinceShot += Time::getDeltaTime();
    bool canShoot = _timeSinceShot > RELOADTIME;
    _view->setEnabled(canShoot);

    if(Input::isMouseButtonDown(GLFW_MOUSE_BUTTON_1) && canShoot){
        shoot();
    }
}

void cGun::shoot() {
    _timeSinceShot = 0;
    
    RaycastHit hit = Physics::Raycast(Scene::getActiveScene()->getEnabledComponentsOfType<cCamera>()[0]->forwardRay());
    if(!hit.hit) { return; }

    cEnemy* enemy = hit.gameObject->getFirstComponent<cEnemy>();
    if(enemy != nullptr){
        enemy->die();
    }
}