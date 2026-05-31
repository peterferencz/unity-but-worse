#pragma once

#include "object/components/cBehaviour.h"
#include "object/components/cTransform2D.h"
#include "object/components/cScreenView.h"
#include "object/components/cMeshCollider.h"
#include "object/components/cCamera.h"

class cEnemySpawner : public cBehaviour {
private:
    

    const float SPAWN_MIN = 1.5;
    const float SPAWN_MAX = 6;
    const float RADIUS = 30;
    float _timeSinceSpawn;

    void spawn();
    
public:
    cEnemySpawner();
    ~cEnemySpawner();

    void onAwake() override;
    void onStart() override;
    void onUpdate() override;
};