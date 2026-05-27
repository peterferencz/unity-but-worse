#include "custom/shooting/cEnemy.h"

cEnemy::cEnemy(){

}

cEnemy::~cEnemy(){

}

void cEnemy::die() {
    _meshCollider->setEnabled(false);
    _meshView->setEnabled(false);
}

void cEnemy::onAwake() {
    requireComponent(_transform);
    requireComponent(_meshView);
    requireComponent(_meshCollider);
}

void cEnemy::onStart() {

}

void cEnemy::onUpdate() {
    glm::vec3 currentPos = _transform->getPosition();
    glm::vec3 targetPos = glm::vec3(0.0f, currentPos.y, 0.0f);

    glm::vec3 toCenter = targetPos - currentPos;
    float distance = glm::length(toCenter);

    if (distance < 0.05f) { return; }
    
    glm::vec3 direction = toCenter / distance; 

    float moveStep = _speed * static_cast<float>(Time::getDeltaTime());

    if (moveStep > distance) {
        moveStep = distance;
    }

    _transform->getPosition() = currentPos + (direction * moveStep);

    float angle = atan2(direction.x, direction.z);
    _transform->getRotation() = glm::vec3(0.0f, glm::degrees(angle), 0.0f);
}