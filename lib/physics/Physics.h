#pragma once

#include "Ray.h"
#include "RaycastHit.h"
#include "glm/glm.hpp"

class Physics {
private:
    Physics();
    ~Physics();
    
    static bool RayTriangleIntersect(const Ray& ray, 
        const glm::vec3& v0, const glm::vec3& v1, const glm::vec3& v2, 
        float& outIntersectionDistance);
public:
    
    static RaycastHit Raycast(const Ray& worldRay);
};

