#pragma once

#include "Ray.h"
#include "RaycastHit.h"
#include "Math.h"

class Physics {
private:
    Physics();
    ~Physics();
    
    static bool RayTriangleIntersect(const Ray& ray, 
        const Framework::Math::Vec3& v0, const Framework::Math::Vec3& v1, const Framework::Math::Vec3& v2, 
        float& outIntersectionDistance);
public:
    
    static RaycastHit Raycast(const Ray& worldRay);
};

