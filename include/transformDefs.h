#ifndef _TRANSFORMDEFS_H
#define _TRANSFORMDEFS_H

#define PI 3.14159
#define RAD2DEG 57.29577

/*--------------------------------------------------------------------------*/
/*-------------------------------Base Transforms----------------------------*/
/*--------------------------------------------------------------------------*/

typedef struct {
    float x;
	float y;
	float z;		
}Vector3;

typedef struct {
    float x;
	float y;		
}Vector2;

typedef struct
{	
    Vector3 pos;
    Vector3 rot;
    Vector3 scl;   
	
	Mtx matrix[3];	
}GameObject; //NOTE: GameObjects are defined in objectDefs.h

typedef struct {
	//For use with collision tests
	
	Vector3 currentPos; 
	Vector3 nextPos;
	
	Vector3 velocity;
	Vector3 centerMass;
	//Vector3 rotation;
	float speed;
	float gravityStrength;
	float rotation;
	//Vector3 max;	
}RigidBody;
/*END----------------------------Base Transforms----------------------------*/



/*--------------------------------------------------------------------------*/
/*----------------------------Rigging and Animation-------------------------*/
/*--------------------------------------------------------------------------*/


typedef struct
{
    u8 animID; //NOTE: current animation 
    u8 animFrame; //NOTE: current frame of current animation
    void (*animate)(u8);
}Animaton;


typedef struct
{	
    Vector3 pos;
    Vector3 rot;
	Vector3 scl;	
	Mtx matrix[3];
	
}RigObject; 

typedef struct
{
	RigObject head;
	RigObject chest;
	RigObject armR[2]; //[0] = upper [1] = lower
	RigObject armL[2]; //[0] = upper [1] = lower
	RigObject legR[2]; //[0] = upper [1] = lower
	RigObject legL[2]; //[0] = upper [1] = lower
}Joint;

typedef struct
{
    u8 animID; //NOTE: current animation 
    u8 animFrame; //NOTE: current frame of current animation
    void (*controller)();
	Joint joint;
}AnimRig;

typedef struct
{
	Vector3 pos;
	Vector3 rot;
	Vector3 scl;
	
}RigAnimation;

typedef struct
{
	Vector3 pos;
	int value;
	short sHex;
	short tHex;
	u8 normalx;
	u8 normaly;
	u8 normalz;
	u8 alpha;	
}TempVTX;



/*END-------------------------Rigging and Animation-------------------------*/






/*--------------------------------------------------------------------------*/
/*------------------------------Collision Objects---------------------------*/
/*--------------------------------------------------------------------------*/




typedef struct {
	//For use with simple collision tests that are axis aligned like hit boxes, triggers, etc
	Vector3 min;
	Vector3 max;	
}BoundBox;

typedef struct 
{	//For use with collision tests on complex objects that are not axis aligned.
	Vector3 minA;
	Vector3 maxA;	
	Vector3 minB;
	Vector3 maxB;
}PolyBox;

typedef struct {
	//best for use for moving object collision tests 
	u8 enabled;
	Vector3 center;
	float radius;
}Sphere;


/*--------------------------------------------------------------------------*/
/*------------------------------Collision Mesh---------------------------*/
/*--------------------------------------------------------------------------*/

typedef struct {
	//Use the mesh collider to build a simple collision mesh to represent level geometry
	Vector3 vertex;
	u8 normal[3];	
}MeshCollider;

typedef struct {
	//Use the mesh collider to build a simple collision mesh to represent level geometry
	short tri[3];
}MeshColliderTri;

typedef struct {
	u8 collision;
	u8 triNum;
	float vDot;
	Vector3 vecSubtract;
	Vector3 lastCollisionPoint;
	Vector3 currentCollisionPoint;
}CollisionPoint;

typedef struct {
	u8 collision;
	u8 triNum;
	float vDot;
	Vector3 triNormal;
	Vector3 lastCollisionPoint;
	Vector3 currentCollisionPoint;
}Debug_Collision;

/*END---------------------------Collision Objects---------------------------*/



/*
typedef struct boundBox testBoundBox; //Very basic collision good for death planes, triggers, item pickups etc. 
struct boundBox
{
	//For use with collision tests
	Vector3 min;
	Vector3 max;	
};
*/
/*
//Page 127 (88)
typedef struct Sphere testSphere; 
struct Sphere{
	Vector3 center;
	float radius;
};


typedef struct polygon testSlopedBox;
struct polyBox
{
	//For use with collision tests
	Vector3 minA;
	Vector3 maxA;	
	Vector3 minB;
	Vector3 maxB;
};*/

/*END----------------------Base Transforms and Objects----------------------*/

/*--------------------------------------------------------------------------*/
/*--------------------Definitions for transformFunctions.c------------------*/
/*--------------------------------------------------------------------------*/

extern void SetVector3(Vector3 *setVector, float x, float y, float z);
extern void SetVector2(Vector2 *setVector, float x, float y);
extern void SetAnimator(Animaton *setAnim, void (*setAnimFunc)(u8), u8 defaultAnimID, u8 defaultAnimFrame);
extern void SetRigAnimator(AnimRig *setAnimRig, void (*setAnimFunc)(), u8 defaultAnimID, u8 defaultAnimFrame);
extern void VectorNormalize(Vector3 *vector);
extern float vectorDot(Vector3 vectorA, Vector3 vectorB);
extern Vector3 vectorCross(Vector3 vectorA, Vector3 vectorB);
extern float vectorScalarTriple(Vector3 vectorA, Vector3 vectorB, Vector3 vectorC);
extern u8 vectorCompare(Vector3 vectorA, Vector3 vectorB);
extern Vector3 vectorAdd(Vector3 vectorA, Vector3 vectorB);
extern Vector3 vectorSubtract(Vector3 vectorA, Vector3 vectorB);
extern Vector3 vectorScale(Vector3 vectorA, float scaler); // return a vector3

extern void VectorAdd(Vector3 *vectorSum, Vector3 vectorA, Vector3 vectorB);
extern void VectorScale(Vector3 *vectorToScale,float scaler); // pass a pointer to a vector 3 to scale it 

extern Vector3 RotateAround(Vector3 basePosition, Vector3 centerPoint, double angleInDegrees);
extern Vector3 RotatePlayerMovement(Vector3 basePosition, Vector3 centerPoint, double angleInDegrees);
extern Vector3 RotateCameraAround(Vector3 basePosition, Vector3 centerPoint, double angleInDegrees);
extern Vector3 Normalize(Vector3 *vectorToNormalize); //normalize vector to between -1 and 1
extern float vectorDistance(Vector3 pointA, Vector3 pointB);
extern int absDistance(Vector3 pointA, Vector3 pointB); //simplified distance calculation when precision is not needed
extern float vectorAngleTriangle(Vector3 pointA, Vector3 pointB,Vector3 pointC);
extern Vector3 Falling();

/*END-----------------Definitions for transformFunctions.c------------------*/

#endif