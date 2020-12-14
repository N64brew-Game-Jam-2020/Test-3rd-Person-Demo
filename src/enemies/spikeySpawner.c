#include "common.h"
#include "objectDefs.h"
#include "level01.h"
#include "collisionDefs.h"
//#include "audio.h"

//EnemyObject enemySpikedSmall;
//EnemyObject enemySpikedLarge;

EnemyObject enemySpikedLarge; //single large spikey that spaws smaller ones
EnemyObject enemySpikedSmall[3]; //array of spikey spawns 

u8 spikeySpawnerChildren = 0;
u8 spikeySpawnerHealth = 0;

u8 tempCounter = 0;
int decisionTimer = 0; //making AI decisions 
int enemySpeedFast = 50;
float enemySpeedSlow = 0.45;

//NOTE: Large spikey spawner will spawn multiple small spikeys (up to 3). 
//Will continue spawning new spikeys until the spawner is dead.  

//TO DO NOTE: 12/8/2020 flesh out the targeting system so that player shots point toward a targeted enemy if facing their direction.
//have enemies take damage and die
//when enemies die, they're set to de-active. When not active, have enemy target struct re-arrange order of nearby enemies



//Local functions
void Spikey_Player_Collision(int spawnID);



typedef struct
{
	Vector3 enemyWaypointPos;	
	Vector3 enemyWaypointNorm;		
}Waypoints;

Vector3 enemyWaypoints[]=
{
	114, -158, 4,
	219, -173, 4,
	225, -361, 4,
	305, -564, 4,
	118, -727, 4,	
	59, -478, 4,
};

/*
Vector3 enemyWaypointNormals[]=
{
	0, -1, 0,
	225, -316, 212,
	164, -262, 301,
	0, -267, 330,
	-145, -262, 301,	
	-182, -316, 212,
	-182, -316, 4,
};
*/

void Spikey_Init(u8 spawnID)
{	

	int randomSign;
	int sign;

	if(spawnID == 0)
	{
		SetVector3(&enemySpikedSmall[spawnID].obj.pos, 90,-250,5);
		SetVector3(&enemySpikedSmall[spawnID].obj.rot, 0,0,0);
		SetVector3(&enemySpikedSmall[spawnID].obj.scl, 1,1,1);
		enemySpikedSmall[spawnID].seesPlayer = 1; //always spawn with enemy not noticing player.
		
		//enemySpikedSmall[spawnID].decisionTimer = 1;
		SetVector3(&enemySpikedSmall[spawnID].targetPosition, enemyWaypoints[0].x, enemyWaypoints[0].y, enemyWaypoints[0].z);
		enemySpikedSmall[spawnID].decisionVar = 3;
		
		SetAnimator(&enemySpikedSmall[spawnID].animator, &testenemyspiked_PolyList, 0,0);	
	}
	
	if(spawnID == 1)
	{
		SetVector3(&enemySpikedSmall[spawnID].obj.pos, 40,-350,5);
		SetVector3(&enemySpikedSmall[spawnID].obj.rot, 0,0,0);
		SetVector3(&enemySpikedSmall[spawnID].obj.scl, 1,1,1);
		enemySpikedSmall[spawnID].seesPlayer = 0; //always spawn with enemy not noticing player.
		
	//	SetVector3(&enemySpikedSmall[spawnID].targetPosition, enemyWaypoints[0].x, enemyWaypoints[0].y, enemyWaypoints[0].z);
		
		enemySpikedSmall[spawnID].decisionVar = 2;
		SetAnimator(&enemySpikedSmall[spawnID].animator, &testenemyspiked_PolyList, 0,0);	
	}
	
	if(spawnID == 2)
	{
		SetVector3(&enemySpikedSmall[spawnID].obj.pos, 115,-150,5);
		SetVector3(&enemySpikedSmall[spawnID].obj.rot, 0,0,0);
		SetVector3(&enemySpikedSmall[spawnID].obj.scl, 1,1,1);
		enemySpikedSmall[spawnID].seesPlayer = 0; //always spawn with enemy not noticing player.
		enemySpikedSmall[spawnID].decisionVar = 5;
		SetAnimator(&enemySpikedSmall[spawnID].animator, &testenemyspiked_PolyList, 0,0);	
		//SetVector3(&enemySpikedSmall[tempCounter].targetPosition, enemyWaypoints[0].x, enemyWaypoints[0].z, enemyWaypoints[0].z);
	}
	
	enemySpikedSmall[spawnID].sphereCollider.center = enemySpikedSmall[spawnID].obj.pos;
	enemySpikedSmall[spawnID].sphereCollider.radius = 20.0f;
	enemySpikedSmall[spawnID].health = 3;
	enemySpikedSmall[spawnID].isActive = 1;
	
	/*
	srand(spawnID);
			
		sign = 1;

		randomSign = guRandom();
		if(randomSign < 0)
			sign = -1;
		
		enemySpikedSmall[spawnID].randomizedVar.x = RAND(80);
		enemySpikedSmall[spawnID].randomizedVar.y = RAND(80);
		*/
	

}

void Spikey_Spawner_Init()
{		
	SetVector3(&enemySpikedLarge.obj.pos, -90,-250,5);
	SetVector3(&enemySpikedLarge.obj.rot, 0,0,0);
	SetVector3(&enemySpikedLarge.obj.scl, 1,1,1);
	enemySpikedLarge.isActive = 1;
	SetAnimator(&enemySpikedLarge.animator, &testenemyspiked_LARGE_PolyList, 0,0);	
	spikeySpawnerHealth = 6;
}



void Spikey_Spawner_Update()
{
	tempCounter = 0;

	//TEXTURE_FOG_LIGHT(glistp, 150, 45, 10, 255,700,992); //call only once for all similar env objects
	
	//NOTE: Check to make sure spikeySpawner is alive
	if(spikeySpawnerHealth >=1)
	{
		//NOTE: If spikeySpawner is alive, render spikeySpawner
		
		//NOTE: If spikeySpawner has less than the max number of active children, spawn a new one
		if(spikeySpawnerChildren < 3)
		{
			Spikey_Init(spikeySpawnerChildren);
			spikeySpawnerChildren++;
		}
		
		//TO DO NOTE: If any of the spikey children are dead, respawn them...
		
	}
	

}


void Spikey_DL()
{
	if(spikeySpawnerHealth >=1)
	{
		RenderEnemyObj(&enemySpikedLarge); 
	}


	if(spikeySpawnerChildren > 0)
	{
		//NOTE: Render any active children
		for(tempCounter = 0; tempCounter < spikeySpawnerChildren; tempCounter++)
		{
		
			if(enemySpikedSmall[tempCounter].health > 0 && enemySpikedSmall[tempCounter].isActive == 1)
			{
				RenderEnemyObj(&enemySpikedSmall[tempCounter]); 
			}
		
			
		}
			
	}
}


	int waypoint;
void Spikey_Update()
{
	int tempSeconds = GetSeconds();
	tempCounter = 0; //reset counter
	
	

	
	
	
	
	
	//NOTE: Check if spikeySpawner has any active children and render them
	if(spikeySpawnerChildren > 0)
	{
	
	
	
		//if(projectile->isActive == 1)
	
	
		//NOTE: Render any active children
		for(tempCounter = 0; tempCounter < spikeySpawnerChildren; tempCounter++)
		{	

			//check to make sure enemy is not dead... if so, deactivate it
			if(enemySpikedSmall[tempCounter].health <= 0)
			{
				enemySpikedSmall[tempCounter].isActive = 0;
			}
			
			
			//NOTE: measure distance between current position and target position
			//once close to current position, switch to next position
			//
			
			else
			{
				if(enemySpikedSmall[tempCounter].seesPlayer == 1) 
				{
					
					//NOTE: find normal between current position and target points
					//find the perpindicular normal
					//convert perp normal into rotation on the y axis
				
				
					if(vectorDistance(enemySpikedSmall[tempCounter].obj.pos, enemySpikedSmall[tempCounter].targetPosition) < 15.0f)
					{
					
						if(waypoint < 5)
							waypoint++;
							
						else
							waypoint = 0;
							
						SetVector3(&enemySpikedSmall[tempCounter].targetPosition, enemyWaypoints[waypoint].x, enemyWaypoints[waypoint].y, enemyWaypoints[waypoint].z);
					

							
						enemySpikedSmall[tempCounter].normal = vectorSubtract(enemySpikedSmall[tempCounter].obj.pos,enemySpikedSmall[tempCounter].targetPosition);
						VectorNormalize(&enemySpikedSmall[tempCounter].normal);
					}
					
					
					//NOTE: measure distance between current position and target position
					else
					{			
						enemySpikedSmall[tempCounter].rigidBody.nextPos.x = lerp(enemySpikedSmall[tempCounter].obj.pos.x, 
							enemySpikedSmall[tempCounter].targetPosition.x, 
								enemySpeedSlow*GetDeltaTime());
								
						enemySpikedSmall[tempCounter].rigidBody.nextPos.y = lerp(enemySpikedSmall[tempCounter].obj.pos.y, 
							enemySpikedSmall[tempCounter].targetPosition.y, 
								enemySpeedSlow*GetDeltaTime());
								
						enemySpikedSmall[tempCounter].rigidBody.nextPos.z = lerp(enemySpikedSmall[tempCounter].obj.pos.z, 
							enemySpikedSmall[tempCounter].targetPosition.z, 
								enemySpeedSlow*GetDeltaTime());
					}		
						//SetVector3(&enemySpikedSmall[tempCounter].targetPosition, enemyWaypoints[0].x, enemyWaypoints[0].y, enemyWaypoints[0].z);
				
				
					
				
					enemySpikedSmall[tempCounter].rigidBody.currentPos = enemySpikedSmall[tempCounter].obj.pos;
					enemySpikedSmall[tempCounter].obj.pos = enemySpikedSmall[tempCounter].rigidBody.nextPos;
				
				}
			}

	
			/*
			if(enemySpikedSmall[tempCounter].seesPlayer == true)
			{
				if(tempSeconds > enemySpikedSmall[tempCounter].decisionTimer)
				{	
					SetVector3(&enemySpikedSmall[tempCounter].targetPosition, playerAvatar.obj.pos.x + (enemySpikedSmall[tempCounter].randomizedVar.x),
						playerAvatar.obj.pos.y + (enemySpikedSmall[tempCounter].randomizedVar.y),
							enemySpikedSmall[tempCounter].obj.pos.z);
							
				}
		
		
		
		
		
		
		
			
			//TO DO NOTE: RANDOMIZING TOO FREQUENTLY - Get distance between spikey and the target position. 
			//Once within a certain distance, re-roll randomizedVar 
			//Set up behavior enumerator in objectdefs.h 
			//use this behavior enum to alternate 
			//Create simple navmesh / waypoint system of points rather than true pathfinding
			//Create waypoints in the middle of each 
			//Allow only one enemy to target you at a time
						
						
						
			
			
			
			
			
				enemySpikedSmall[tempCounter].obj.pos.x = lerp(enemySpikedSmall[tempCounter].obj.pos.x, 
				enemySpikedSmall[tempCounter].targetPosition.x, 
				enemySpeedSlow*GetDeltaTime());
				enemySpikedSmall[tempCounter].obj.pos.y = lerp(enemySpikedSmall[tempCounter].obj.pos.y, 
				enemySpikedSmall[tempCounter].targetPosition.y, 
				enemySpeedSlow*GetDeltaTime());
			}	
			
			*/
			
			
			
			
				//tempCameraOffset.y = lerp(tempCameraOffset.y, -1000.0f, userInput_Y * -0.01f);
			//enemySpikedSmall[spawnID].seesPlayer = 0; //always spawn with enemy not noticing player.
			
		}
		
		tempCounter = 0; //reset counter
		for(tempCounter = 0; tempCounter < spikeySpawnerChildren; tempCounter++)
		{
			enemySpikedSmall[tempCounter].sphereCollider.center = enemySpikedSmall[tempCounter].obj.pos;
			Spikey_Player_Collision(tempCounter);
			
		}
		
		
		
		//if(tempSeconds != enemySpikedSmall[tempCounter].decisionTimer)
				//enemySpikedSmall[tempCounter].decisionTimer = tempSeconds;
		
	}
/*
				Debug_MiscVar[0] = enemySpikedSmall[1].rigidBody.currentPos;
				Debug_MiscVar[1] = enemySpikedSmall[1].targetPosition;
				Debug_MiscVar[2] = enemySpikedSmall[1].normal;
				*/
				Debug_MiscVar[3].x = enemySpikedSmall[0].playerCollision;
				Debug_MiscVar[3].y = enemySpikedSmall[0].health;
				
				//Debug_MiscVar[3].y = enemySpikedSmall[1].playerCollision;
				Debug_MiscVar[3].z = enemySpikedSmall[2].playerCollision;
				
		
}

void Spikey_Player_Collision(int spawnID)
{
	u8 collision = 0;
	collision = sphereToSphere(&playerAvatar.sphereCollider, &enemySpikedSmall[spawnID].sphereCollider);
	
	enemySpikedSmall[spawnID].playerCollision = collision;
	

	
}



void Spikey_Collision(ProjectileObject* projectile)
{
	u8 collision = 0;
	Sphere tempSphere = projectile->sphereCollider;

	//check all spikeys for collision with object passed as sphereCollider
	//collision = sphereToSphere(&playerAvatar.sphereCollider, &enemySpikedSmall[spawnID].sphereCollider);
	
		for(tempCounter = 0; tempCounter < spikeySpawnerChildren; tempCounter++)
		{
		
			if(enemySpikedSmall[tempCounter].isActive == 1)
			{			
				//NOTE TO GEIST: Original sphereToSphere:	
				collision = sphereToSphere(&tempSphere, &enemySpikedSmall[tempCounter].sphereCollider);	
				
				/*NOTE TO GEIST: Simplified sphereToSphere... it seems to cause issues and is always returning true...
				This is causing all enemies to die with a single hit... 
				or if I deactivate the bullet upon collision, it just beings ticking down health of all enemies
				probably a simple error but I'm not sure how to fix it so I renamed the function  "sphereToSphereSimple" for now*/
				
				//collision = sphereToSphereSimple(&tempSphere, &enemySpikedSmall[tempCounter].sphereCollider);	
				
				
				
				enemySpikedSmall[tempCounter].playerCollision = collision;
		
				if(collision == 1)	//If struck by blaster, play splort sound 		
				{			
				
					if(projectile->isActive == 1)
					{
						//PlaySfx(5);
						
						enemySpikedSmall[tempCounter].health -= collision;
						
						//play hit or death effects
						if(enemySpikedSmall[tempCounter].health > 0)
							//PlaySfx(5);
							Play3dSfx(5, 96, 2000, enemySpikedSmall[tempCounter].obj.pos);
							//do goop explosion here?
						else
							//PlaySfx(1);
							Play3dSfx(1, 127, 3000, enemySpikedSmall[tempCounter].obj.pos);
							//do goop splat here?
					}
					projectile->isActive = 0; //deactivate this projectile to keep from spawning multiple sounds and doing extra damage. 
					
				}
			}
		}
	//}
	
	
	
}

void Spikey_Behaviors()
{
/*
			switch(enemySpikedSmall[tempCounter].behaviors)
			{
				case IDLE: 
					break;
				case WANDER:
					break;
				case COMBAT:
					break;
				case CHASE:
					break;
				case FLEE:
					break;						
					
			}*/
}

void Spikey_Change_Behavior()
{
	
}

void GetActiveSpikey(EnemyTargets* enemyTargetList)
{
	for(tempCounter = 0; tempCounter < spikeySpawnerChildren+1; tempCounter++)
	{
		if(tempCounter == 0 && enemySpikedLarge.isActive == 1)		
			enemyTargetList->enemyObjects[tempCounter] = &enemySpikedLarge.obj;		
	
		else if(enemySpikedSmall[tempCounter-1].isActive == 1)
			enemyTargetList->enemyObjects[tempCounter] = &enemySpikedSmall[tempCounter-1].obj;
	}
	
	enemyTargetList->activeTarget = &enemySpikedSmall[0].obj;
}