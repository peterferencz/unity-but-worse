#include "custom/cCursor.h"

cCursor::cCursor(glm::vec2 offset)
:_offset(offset){
    
}

cCursor::~cCursor(){

}

void cCursor::onAwake(){
    requireComponent(_transform);
    requireComponent(_meshView);
}

void cCursor::onStart(){

}

void cCursor::onUpdate(){
    _meshView->setEnabled(!Input::isCursorCaptured());
    
    _transform->getPosition() = Input::getCursorPosition() + _offset;
}