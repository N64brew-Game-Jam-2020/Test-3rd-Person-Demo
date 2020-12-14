#ifndef _OBJECTDEFS_H
#define _OBJECTDEFS_H
//#include "transformDefs.h"
#include "common.h"

/*--------------------------------------------------------------------------*/
/*-------------------------------Base GameObjects---------------------------*/
/*--------------------------------------------------------------------------*/



typedef struct
{
    GameObject obj; //Note:Holds game object properties (pos, rot, scl) and matrixes
	Sphere sphereCollider; //Note: Collider for physics checks
	RigidBody rigidBody; //Note:Holds mass, collisions, velocity etc.
	AnimRig animRig; //Note:pointer to animator 
	Lights2 playerLighting;
	Light envLightSide; //Note: collision boxes in environment will trigger a change in the environment light affecting the character (and only the character)
	Light envLightGround; //Note: collision boxes in environment will trigger a change in the environment light affecting the character (and only the character)
	float rotation;
	
	Vector3 playerNormal;
	
	u8 playerShooting;
	
	u8 isGrounded;
	u8 isJumping;
	u8 isFalling;
	float jumpForce;
	float jumpTimerStart;
	float jumpTimerElapsed;
	float finalJumpTime;

}Player;

typedef struct
{
	GameObject obj; //Note:Holds game object properties (pos, rot, scl) and matrixes
	Sphere sphereCollider; //Note: Collider for physics checks
	RigidBody rigidBody; //Note:Holds mass, collisions, velocity etc.
	Animaton animator; //pointer to animator 
	
}PlayerShip;

typedef struct
{
	u8 isActive; //if no enemies are targeted, is deactivated
	GameObject obj; //in game pointer model 
	Animaton animator; //pointer to animator 
	
	GameObject* activeTarget;
	GameObject* enemyObjects[4]; //an array of nearby enemy objects
	
}EnemyTargets;


typedef struct
{
    GameObject obj; //Note:pointer to game object (pos, rot, scl)
	GameObject* camLook; //Note: GameObject pointer of object camera is currently looking at (ex player character)
	Vector3 camLookPoint;
	Vector3 cameraOffset; //Note: distance to offset from "camLook"
	Vector3 nextPosition; //Note: distance to offset from "camLook"
	
	float cameraOrbit; //Note:Orbital position around player character (0-360 degrees)
	float distance; //Note: Current distance 
	float adjDistance;	//Note: adjusted distance when colliding with wall or object
	float nearPosition;	//Note: used for nearClipping 
	u8 againstWall;
	 
	//Animaton animator; //pointer to animator 
//	Gfx* DL; //pointer to display list for object	
}CameraObject;

typedef struct
{
    GameObject obj; //pointer to game object (pos, rot, scl)
	Animaton animator; //pointer to animator 
//	Gfx* DL; //pointer to display list for object	
}EnvObject;

typedef struct
{
	u8 isActive; //set active when a shot is fired
	int startTimer; //time that shot is fired updated to int to avoid hang up
	int activeTimer; //after 2 seconds, deactivate fired updated to int to avoid hang up
    GameObject obj; //pointer to game object (pos, rot, scl)
	Sphere sphereCollider; //for colliding with enemies
	RigidBody rigidBody; //Note:Holds mass, collisions, velocity etc.
	Animaton animator; //pointer to animator 
}ProjectileObject;


/*
typedef struct
{
	
	
	
}AI;
*/


typedef struct
{	
	//--GENERAL---
	u8 enemyType; //denotes what type of enemy will spawn
    GameObject obj; //pointer to game object (pos, rot, scl)
	Animaton animator; //pointer to animator 
	RigidBody rigidBody; //Note:Holds mass, collisions, velocity etc.
	
	
	signed char health; //NOTE: current Enemy health	
	u8 isActive;
	
	u8 cooldownStart;
	u8 cooldownTimeElapsed;
	//u8 hitCooldown;
	//---COLLISION CHECKS---
	u8 playerCollision; //check if colliding with player
	
	//TO DO NOTE: Add in projectile collision boolean to enemyobject struct and 
	//a function in spikeySpawner.c
	
	Sphere sphereCollider; //Note: Collider for physics checks

	
	//----AI-----
	//TO DO NOTE: Create enemy state machine
	//BEHAVIOR behaviors = IDLE;
	Vector3 pathNormal; //NOTE: Normal of the path being traveled along
	Vector3 normal; //NOTE: Normal of enemy which should be the reverse of the pathNormal
	u8 seesPlayer;
	Vector3 targetPosition;
	Vector3 randomizedVar;
	int decisionTimer; //NOTE: timer is updated every so often in order to make AI decisions
	int decisionVar; //NOTE: used to differenciate the movements of the enemies so they are checking player position at different intervals
//	Gfx* DL; //pointer to display list for object	
}EnemyObject;

/*END----------------------------Base GameObjects---------------------------*/




/*--------------------------------------------------------------------------*/
/*-----------------------------Trigger GameObjects--------------------------*/
/*--------------------------------------------------------------------------*/

typedef struct
{
	BoundBox collider;
	//u8 boolean;
	u8 isActive;
}TriggerBox;

typedef struct
{
	TriggerBox trigger;	
	//void (*function)();
}EnvLighting;

typedef struct
{
	TriggerBox trigger;	
	//void (*function)();
}TriggerGeometry;

typedef struct
{
	TriggerBox trigger;	
	void (*function)();
}EventTrigger;

/*END---------------------------Trigger GameObjects--------------------------*/



/*--------------------------------------------------------------------------*/
/*----------------------------Collision GameObjects-------------------------*/
/*--------------------------------------------------------------------------*/


/*END---------------------------Trigger GameObjects--------------------------*/

#endif