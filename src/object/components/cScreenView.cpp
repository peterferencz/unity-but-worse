#include "object/components/cScreenView.h"

#include "Debug.h"
#include "graphics/materials/mDebug.h"
#include "object/components/cTransform2D.h"
#include "Time.h"

cScreenView::cScreenView(Mesh* mesh, Material* material)
:_mesh(mesh),
_material(material),
_debugMaterial(new mDebug()) {
    
}

cScreenView::~cScreenView(){
    delete _mesh;
    delete _material;
    delete _debugMaterial;
}

Material* cScreenView::getMaterial(){
    return _material;
}

void cScreenView::setMaterial(Material* material){
    delete _material;
    _material = material;
}

Mesh* cScreenView::getMesh() {
    return _mesh;
}

void cScreenView::Draw(const glm::mat4& view, const glm::mat4& projection, const glm::mat4& orthoMatrix){
    if(!_enabled) { return; }
    cTransform2D* transform = _gameObject->getFirstComponent<cTransform2D>();
    if(transform == nullptr) {
        Logger::Warn("No cTransform2D on a gameobject with cScreenView");
        return;
    }
    
    Material* mat = Debug::isEnabled() ? _debugMaterial : _material;

    mat->Use();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    if(Debug::isEnabled()){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    mat->setUniform("uModel", transform->getModelMatrix());
    mat->setUniform("uView", glm::mat4(1.0f));
    mat->setUniform("uProjection", orthoMatrix);
    mat->setUniform("uTime", static_cast<float>(Time::getTimeStamp()));
    
    mat->Draw();
    
    _mesh->Bind();
    glDrawElements(GL_TRIANGLES, _mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
    _mesh->Unbind();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    
    if(Debug::isEnabled()){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}