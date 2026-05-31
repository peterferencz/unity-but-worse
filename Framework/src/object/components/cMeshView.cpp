#include "object/components/cMeshView.h"


cMeshView::cMeshView(Mesh& mesh, Material* material)
:_mesh(mesh),
_material(material),
_debugMaterial(new mDebug()) {
    
}

cMeshView::~cMeshView(){
    delete _material;
    delete _debugMaterial;
}

Material* cMeshView::getMaterial(){
    return _material;
}

void cMeshView::setMaterial(Material* material){
    delete _material;
    _material = material;
}

Mesh& cMeshView::getMesh() {
    return _mesh;
}

void cMeshView::Draw(const Framework::Math::Mat4& view, const Framework::Math::Mat4& projection, const Framework::Math::Mat4& orthoMatrix){
    if(!_enabled) { return; }
    cTransform* transform = _gameObject->getFirstComponent<cTransform>();
    if(transform == nullptr) {
        Logger::Warn("No cTransform on a gameobject with cMeshView");
        return;
    }
    
    Material* mat = Debug::isEnabled() ? _debugMaterial : _material;

    mat->Use();

    if(Debug::isEnabled()){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    mat->setUniform("uModel", transform->getModelMatrix());
    mat->setUniform("uView", view);
    mat->setUniform("uProjection", projection);
    mat->setUniform("uTime", static_cast<float>(Time::getTimeStamp()));
    
    mat->Draw();
    
    _mesh.Bind();
    glDrawElements(GL_TRIANGLES, _mesh.getIndexCount(), GL_UNSIGNED_INT, 0);
    _mesh.Unbind();

    if(Debug::isEnabled()){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}