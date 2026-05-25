#include "object/prefabs/Camera.h"

Camera::Camera(){
    addComponent(new cTransform());
    addComponent(new cCamera());
}

Camera::~Camera(){

}