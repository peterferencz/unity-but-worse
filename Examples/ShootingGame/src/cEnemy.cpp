#include "cEnemy.h"

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
    Framework::Math::Vec3 currentPos = _transform->getPosition();
    Framework::Math::Vec3 targetPos = Framework::Math::Vec3(0.0f, currentPos.y, 0.0f);

    Framework::Math::Vec3 toCenter = targetPos - currentPos;
    float distance = Framework::Math::length(toCenter);

    if (distance < 0.05f) { return; }
    
    Framework::Math::Vec3 direction = toCenter / distance; 

    float moveStep = _speed * static_cast<float>(Time::getDeltaTime());

    if (moveStep > distance) {
        moveStep = distance;
    }

    _transform->getPosition() = currentPos + (direction * moveStep);

    float angle = atan2(direction.x, direction.z);
    _transform->getRotation() = Framework::Math::Vec3(0.0f, Framework::Math::degrees(angle), 0.0f);
}