#include "custom/Rotator.h"

void Rotator::onStart(){
    _transform = _gameObject->getFirstComponent<cTransform>();
}

void Rotator::onUpdate(){
    _transform->getRotation().y += _speed * Time::getDeltaTime();

    if (_transform->getRotation().y >= 360.0f) {
        _transform->getRotation().y -= 360.0f;
    }
}