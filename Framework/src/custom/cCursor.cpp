#include "custom/cCursor.h"

cCursor::cCursor(Framework::Math::Vec2 offset)
:_offset(offset){
    
}

cCursor::~cCursor(){

}

void cCursor::onAwake(){
    requireComponent(_transform);
    requireComponent(_view);
}

void cCursor::onStart(){

}

void cCursor::onUpdate(){
    _view->setEnabled(!Input::isCursorCaptured());
    
    _transform->getPosition() = Input::getCursorPosition() + _offset;
}