#include "object/components/cMeshView.h"


cMeshView::cMeshView(Mesh* mesh, Material* material)
:_mesh(mesh),
_material(material) {
    
}

cMeshView::~cMeshView(){
    delete _mesh;
    delete _material;
}

Material* cMeshView::getMaterial(){
    return _material;
}

void cMeshView::setMaterial(Material* material){
    delete _material;
    _material = material;
}

void cMeshView::Draw(const glm::mat4& view, const glm::mat4& projection, const glm::mat4& orthoMatrix){
    _material->Use();

    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 currentView = view;
    glm::mat4 currentProjection = projection;
    bool is2D = false;
    
    if(cTransform* transform = _gameObject->getFirstComponent<cTransform>()){
        model = transform->getModelMatrix();
    } else if(cTransform2D* transform = _gameObject->getFirstComponent<cTransform2D>()){
        model = transform->getModelMatrix();
        currentView = glm::mat4(1.0f);
        currentProjection = orthoMatrix;
        is2D = true;
        
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);
    }


    _material->setUniform("uModel", model);
    _material->setUniform("uView", currentView);
    _material->setUniform("uProjection", currentProjection);
    _material->setUniform("uTime", static_cast<float>(Time::getTimeStamp()));
    
    _material->Draw();
    
    _mesh->Bind();
    glDrawElements(GL_TRIANGLES, _mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
    _mesh->Unbind();

    if(is2D){
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
    }
}