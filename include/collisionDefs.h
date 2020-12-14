#ifndef _COLLISIONDEFS_H
#define _COLLISIONDEFS_H
#include "common.h"


/*--------------------------------------------------------------------------*/
/*-----------------------------COLLISION FUNCTIONS--------------------------*/
/*--------------------------------------------------------------------------*/

extern u8 triggerBoundBox(Vector3* playerPos, TriggerBox* trigger);
//extern Vector3 checkSphereTriangle(Sphere* sphereCollider, MeshCollider* meshColliderp);
extern void CalcTriNormal(MeshCollider* vertexA, MeshCollider* vertexB, MeshCollider* vertexC, Vector3 *triNormalP);
extern void CalcSlidingPlane(u8 objectID, Vector3* playerVelocity, CollisionPoint* collisions, Sphere* colliderPosition, Vector3* nearestPoint, Vector3 triangleNormal, Vector3* tempNewPosition);
extern void CalcGroundSlidingPlane(u8 objectID, Vector3* playerVelocity, CollisionPoint* collisions, Sphere* colliderPosition, Vector3* nearestPoint, Vector3 triangleNormal, Vector3* tempNewPosition);

extern void clearVariables(u8 objectID);
extern Vector3 DistanceComparison(Sphere* colliderPosition, Vector3 compPoint, Vector3* closePoint);
extern u8 AgainstWall(Sphere* colliderPosition, Vector3 *point);
extern u8 AgainstGround(Sphere* colliderPosition, Vector3 *point);
extern u8 SphereToMeshNearPoint(Sphere* colliderPosition, MeshCollider* vertexA, MeshCollider* vertexB, MeshCollider* vertexC, Vector3* currentPoint);
extern u8 SphereToMeshTriCollision(Sphere* s, Vector3* point);
extern u8 LineToGroundPoint(Sphere* colliderPosition, MeshCollider vertexA, MeshCollider vertexB, MeshCollider vertexC, Vector3* point);
extern u8 sphereToSphere(Sphere* sphereA, Sphere* sphereB);
extern u8 sphereToSphereSimple(Sphere* sphereA, Sphere* sphereB);
extern void GroundDistanceComparison(Sphere* colliderPosition, Vector3 compPoint, Vector3 *currentGroundPoint);

extern Vector3 ClosestPointTriangle(Vector3 p, Vector3 a, Vector3 b, Vector3 c);


#endif