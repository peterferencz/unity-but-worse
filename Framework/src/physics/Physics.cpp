#include "physics/Physics.h"
#include "object/components/cMeshCollider.h"
#include "Scene.hpp"

bool Physics::RayTriangleIntersect(const Ray& ray, 
        const Framework::Math::Vec3& v0, const Framework::Math::Vec3& v1, const Framework::Math::Vec3& v2, 
        float& outIntersectionDistance) {


    const float EPSILON = 0.0000001f;
    Framework::Math::Vec3 edge1 = v1 - v0;
    Framework::Math::Vec3 edge2 = v2 - v0;
    Framework::Math::Vec3 h = Framework::Math::cross(ray.direction, edge2);
    float a = Framework::Math::dot(edge1, h);

    if (std::abs(a) < EPSILON) return false; // Ray is parallel to triangle

    float f = 1.0f / a;
    Framework::Math::Vec3 s = ray.origin - v0;
    float u = f * Framework::Math::dot(s, h);

    if (u < 0.0f || u > 1.0f) return false;

    Framework::Math::Vec3 q = Framework::Math::cross(s, edge1);
    float v = f * Framework::Math::dot(ray.direction, q);

    if (v < 0.0f || u + v > 1.0f) return false;

    float t = f * Framework::Math::dot(edge2, q);
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
        Mesh& mesh = collider->getMesh();

        Framework::Math::Mat4 modelMatrix = collider->getModelMatrix();
        Framework::Math::Mat4 invModelMatrix = Framework::Math::inverse(modelMatrix);

        Framework::Math::Vec4 localDirVec4 = invModelMatrix * Framework::Math::Vec4(worldRay.direction, 0.0f);
        Ray localRay(
            Framework::Math::Vec3(invModelMatrix * Framework::Math::Vec4(worldRay.origin, 1.0f)),
            Framework::Math::Vec3(localDirVec4.x, localDirVec4.y, localDirVec4.z)
        );
        

        // Extract vertex data from mesh
        const std::vector<Vertex>& vertices = mesh.getVerticies();
        const std::vector<unsigned int>& indices = mesh.getIndicies();

        // Iterate over all triangles in the mesh (3 indices per triangle)
        for (size_t i = 0; i < indices.size(); i += 3) {
            Framework::Math::Vec3 v0 = vertices[indices[i]].Position;
            Framework::Math::Vec3 v1 = vertices[indices[i + 1]].Position;
            Framework::Math::Vec3 v2 = vertices[indices[i + 2]].Position;

            float localDistance = 0.0f;
            if (RayTriangleIntersect(localRay, v0, v1, v2, localDistance)) {
                    
                // Calculate intersection point in local space, then bring back to world space
                Framework::Math::Vec3 localHitPoint = localRay.origin + localRay.direction * localDistance;
                Framework::Math::Vec3 worldHitPoint = Framework::Math::Vec3(modelMatrix * Framework::Math::Vec4(localHitPoint, 1.0f));
                    
                // Calculate actual world space distance
                float worldDistance = Framework::Math::distance(worldRay.origin, worldHitPoint);

                // Check if this is the closest object hit along the ray path
                if (worldDistance < closestHit.distance) {
                    closestHit.hit = true;
                    closestHit.distance = worldDistance;
                    closestHit.point = worldHitPoint;
                    closestHit.gameObject = collider->getGameObject();
                }
            }
        }
    }

    return closestHit.hit ? closestHit : RaycastHit{.hit = false, .distance = 0, .point = Framework::Math::Vec3(0), .gameObject = nullptr};
}