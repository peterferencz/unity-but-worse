#include "object/components/cMeshCollider.h"

cMeshCollider::cMeshCollider()
:_meshView(nullptr), _transform(nullptr) {

}

Mesh& cMeshCollider::getMesh() {
    if(_meshView == nullptr){
        _meshView = _gameObject->getFirstComponent<cMeshView>();
    }
    return _meshView->getMesh();
}
Framework::Math::Mat4 cMeshCollider::getModelMatrix() {
    if(_transform == nullptr){
        _transform = _gameObject->getFirstComponent<cTransform>();
    }
    return _transform->getModelMatrix();
}