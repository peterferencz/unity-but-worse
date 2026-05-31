#include "cEnemySpawner.h"
#include "cEnemy.h"
#include "BirdMesh.h"

#include "Scene.hpp"
#include "Time.h"
#include "graphics/mesh/CubeMesh.h"
#include "graphics/materials/mSimpleColor.h"
#include <random>
#include "graphics/shaders/ShaderCache.h"
#include "graphics/mesh/MeshCache.h"

cEnemySpawner::cEnemySpawner(){

}

cEnemySpawner::~cEnemySpawner(){

}

void cEnemySpawner::onAwake(){

}

void cEnemySpawner::onStart(){

}

void cEnemySpawner::onUpdate(){
    _timeSinceSpawn += Time::getDeltaTime();
    if(_timeSinceSpawn > SPAWN_MIN){
        spawn();
    }
}

void cEnemySpawner::spawn(){
    _timeSinceSpawn = 0;

    const float TWO_PI = 6.28318530718f;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, TWO_PI);
    float randomAngle = dis(gen);

    float xPos = cos(randomAngle) * RADIUS;
    float zPos = sin(randomAngle) * RADIUS;
    Framework::Math::Vec3 spawnPosition = Framework::Math::Vec3(xPos, 1, zPos);


    GameObject* bird = new GameObject{
        new cTransform(spawnPosition, Framework::Math::Vec3(0), Framework::Math::Vec3(1)),
        new cMeshView(MeshCache::getMesh<BirdMesh>(), new Material(ShaderCache::getVertexShader("resources/shaders/vWobbleBird.glsl"), ShaderCache::getFragmentShader("resources/shaders/fCensored.glsl"))),
        new cMeshCollider(),
        new cEnemy()
    };
    Scene::getActiveScene()->AddGameObject(bird);
}