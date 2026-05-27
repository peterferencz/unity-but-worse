#include "physics/Physics.h"
#include "object/components/cMeshCollider.h"
#include "Scene.hpp"

bool Physics::RayTriangleIntersect(const Ray& ray, 
        const glm::vec3& v0, const glm::vec3& v1, const glm::vec3& v2, 
        float& outIntersectionDistance) {


    const float EPSILON = 0.0000001f;
    glm::vec3 edge1 = v1 - v0;
    glm::vec3 edge2 = v2 - v0;
    glm::vec3 h = glm::cross(ray.direction, edge2);
    float a = glm::dot(edge1, h);

    if (std::abs(a) < EPSILON) return false; // Ray is parallel to triangle

    float f = 1.0f / a;
    glm::vec3 s = ray.origin - v0;
    float u = f * glm::dot(s, h);

    if (u < 0.0f || u > 1.0f) return false;

    glm::vec3 q = glm::cross(s, edge1);
    float v = f * glm::dot(ray.direction, q);

    if (v < 0.0f || u + v > 1.0f) return false;

    float t = f * glm::dot(edge2, q);
    if (t > EPSILON) { // Ray intersection
        outIntersectionDistance = t;
        return true;
    }

    return false;
}

RaycastHit Physics::Raycast(const Ray& worldRay) {
    RaycastHit closestHit;
    closestHit.hit = false;
    closestHit.distance = std::numeric_limits<float>::max();

    std::vector<cMeshCollider*> colliders = Scene::getActiveScene()->getEnabledComponentsOfType<cMeshCollider>();

    for (cMeshCollider* collider : colliders) {
        Mesh* mesh = collider->getMesh();
        if (!mesh) continue;

        glm::mat4 modelMatrix = collider->getModelMatrix();
        glm::mat4 invModelMatrix = glm::inverse(modelMatrix);

        glm::vec4 localDirVec4 = invModelMatrix * glm::vec4(worldRay.direction, 0.0f);
        Ray localRay(
            glm::vec3(invModelMatrix * glm::vec4(worldRay.origin, 1.0f)),
            glm::vec3(localDirVec4.x, localDirVec4.y, localDirVec4.z)
        );
        

        // Extract vertex data from mesh
        const std::vector<Vertex>& vertices = mesh->getVerticies();
        const std::vector<unsigned int>& indices = mesh->getIndicies();

        // Iterate over all triangles in the mesh (3 indices per triangle)
        for (size_t i = 0; i < indices.size(); i += 3) {
            glm::vec3 v0 = vertices[indices[i]].Position;
            glm::vec3 v1 = vertices[indices[i + 1]].Position;
            glm::vec3 v2 = vertices[indices[i + 2]].Position;

            float localDistance = 0.0f;
            if (RayTriangleIntersect(localRay, v0, v1, v2, localDistance)) {
                    
                // Calculate intersection point in local space, then bring back to world space
                glm::vec3 localHitPoint = localRay.origin + localRay.direction * localDistance;
                glm::vec3 worldHitPoint = glm::vec3(modelMatrix * glm::vec4(localHitPoint, 1.0f));
                    
                // Calculate actual world space distance
                float worldDistance = glm::distance(worldRay.origin, worldHitPoint);

                // Check if this is the closest object hit along the ray path
                if (worldDistance < closestHit.distance) {
                    closestHit.hit = true;
                    closestHit.distance = worldDistance;
                    closestHit.point = worldHitPoint;
                    closestHit.gameObject = collider->getParent();
                }
            }
        }
    }

    return closestHit.hit ? closestHit : RaycastHit{.hit = false, .distance = 0, .point = glm::vec3(0), .gameObject = nullptr};
}