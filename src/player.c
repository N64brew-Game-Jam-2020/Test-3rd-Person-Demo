//#include "common.h"
//#include "objectDefs.h"
#include "playerDefs.h"

//audio test
#include "audio.h"

Player playerAvatar;
u8 animFrame = 1; 

#define PLAYER_MAX_SPEED 200.0f
#define PLAYER_MID_SPEED 80.5f
#define PLAYER_MIN_SPEED 60.5f

#define PLAYER_MAX_JUMP_SPEED 300.0f

static void updatePlayerAnim();
void PlayerCollision();
void FireShot();
void UpdateShot();

void PlayerJump();
void PlayerJumpV2();
void FireShotv2();
void UpdateShotv2();
void CheckEnemyTargets();

EnemyTargets enemyTargets;

EnemyObject emptyTargetObject;

extern int GetFPS();

//TO DO NOTE: 12/9/2020 flesh out the targeting system so that player shots point toward a targeted enemy if facing their direction.
//have enemies take damage and die (partially done)
//when enemies die, they're set to de-active. 
//before checking for collision with an enemy check to be sure it is active. If not, cycle to the next enemy in UI and enemyTargets
//When an enemy is inactive, have enemyTargets struct re-arrange the order of nearby enemies and fill slot with an emptyTargetObject
// if an emptyTargetObject is cycled to, disable enemyTargets' UI element 


//have camera position itself in between the player and the targeted enemy (Maybe...)
//have player strafe around the enemy? (Maybe...)
//Return to work on enemy AI

void initPlayer()
{
	u8 tempCounter;
	SetVector3(&emptyTargetObject.obj.pos, 0,0,0);
	SetVector3(&emptyTargetObject.obj.rot, 0,0,0);
	SetVector3(&emptyTargetObject.obj.scl, 1,1,1);
	
	for(tempCounter = 0; tempCounter < 4; tempCounter++)
	{
		enemyTargets.enemyObjects[tempCounter] = &emptyTargetObject.obj;
	}
	
	enemyTargets.activeTarget = enemyTargets.enemyObjects[2];

	SetVector3(&playerAvatar.obj.pos, 3258,-2500,5); //spawn in ship area
	//SetVector3(&playerAvatar.obj.pos, 75,-300,5); //spawn in ship area
	SetVector3(&playerAvatar.obj.rot, 0,0,0); 
	SetVector3(&playerAvatar.obj.scl, 1,1,1); 
	SetVector3(&playerAvatar.rigidBody.velocity, 0,0,0); 
	SetVector3(&playerAvatar.playerNormal, 0,-1,0); 
	SetVector3(&playerAvatar.rigidBody.centerMass, 0,0,0); 
	playerAvatar.rigidBody.speed = 3.0f;	
	playerAvatar.rigidBody.gravityStrength = 60.0f;
	playerAvatar.isJumping = 0;
	playerAvatar.isFalling = 0;

	SetRigAnimator(&playerAvatar.animRig, &DrawPlayerModel, 0,0);
		
	playerAvatar.sphereCollider.enabled = 1;	
	playerAvatar.sphereCollider.radius = 15.0f;
	SetVector3(&playerAvatar.sphereCollider.center, 		playerAvatar.obj.pos.x,playerAvatar.obj.pos.y,playerAvatar.obj.pos.z + (playerAvatar.sphereCollider.radius));
	SetVector3(&playerAvatar.rigidBody.nextPos, playerAvatar.obj.pos.x,playerAvatar.obj.pos.y,playerAvatar.obj.pos.z); 
	
	defaultRig();	

	playerAvatar.isGrounded = groundMesh_CollisionCheck(&playerAvatar.sphereCollider);
	//playerAvatar.isGrounded = AgainstGround(&playerAvatar.sphereCollider, &groundCollisionPoints.currentCollisionPoint);

	
}

u8 currentFrame = 0;
u8 frameCounter = 0;
//Vector2 tempVectors = {0,0}; //no longer used

/*--------------------------------------------------------------------------*/
/*---------------------------Player Control Functions-----------------------*/
/*--------------------------------------------------------------------------*/

void PlayerMovement();

Vector2 userInput_Player; 
Vector3 playerTempPos;
u8 playerState = 0; //TO DO: temporarily used for "in motion" but will flesh this out with a state machine later

float shootingCooldownTimer = 0.0f;
int lowerArmTimerStart = 0; //after 3 seconds with no input, lower arm
int lowerArmTimer = 0;  //after 3 seconds with no input, lower arm
int lowerArm = 1; //after 1 second with no input, lower arm

u8 shotCycle = 0;
ProjectileObject projectileSpawns[8]; //maximum of 4 projectiles from player at a time
u8 maxShot = 8;
u8 recentShot = 0; //used for debugging
u8 shotCounter = 0; //used for iterating array

void updatePlayer(Dynamic* dp)
{	
	updatePlayerAnim(); //NOTE: Update current animation frame based on player inputs from the previous frame and current frame of animation
	userInput_Player = Player_Input(); //NOTE: calls Player_Input() function in controller.c which returns the X, Y inputs in a Vector2. The Player_Input function will grab values based on the controller settings set by the player
	SetVector3(&playerAvatar.rigidBody.velocity, 0,0,0);  //NOTE: resets the playerAvatar rigidBody velocity to 0,0,0 each frame
	
	collisionPoints.collision = 0; 
	
	//FireShot();
	//UpdateShot();
	
	
	CheckEnemyTargets();
	FireShotv2();
	UpdateShotv2();
	


	
	if(userInput_Player.y >= 0.1f || userInput_Player.y <= -0.1f || userInput_Player.x >= 0.1f || userInput_Player.x <= -0.1f) 
	{		
		//NOTE: 	userInput_Player.x and .y are determined by player sensitivity settings. 
		//NOTE:  If the inputs do not meet the minimum player sensitivity, the userInput_Player.x and userInput_Player.y will be set to 0.0f in the Player_Input function. 
		playerAvatar.rotation = atan2(userInput_Player.y, userInput_Player.x); //NOTE: get angle with atan2 and x, y inputs
		playerAvatar.rotation = (playerAvatar.rotation * 57.29577); //NOTE: convert angle from radians to degrees 
		//playerAvatar.rotation += 180.0f;
		playerAvatar.rotation += 90.0f;
		playerAvatar.rotation = playerAvatar.rotation + mainCamera.cameraOrbit;
		if(playerAvatar.rotation >360.0f)
					playerAvatar.rotation = playerAvatar.rotation - 360.0f;				

		//NOTE: Replace later with smoother motion  
			playerAvatar.obj.rot.z = playerAvatar.rotation;
				
		if(abs(userInput_Player.y) + abs(userInput_Player.x) > 60.0f)	
		{
			playerAvatar.rigidBody.speed = lerp(playerAvatar.rigidBody.speed, PLAYER_MAX_SPEED, 0.1f ); //increase speed from current speed to max speed if x+y inputs pass a threshold
			playerState = 1;
		}
		else
		{
			playerAvatar.rigidBody.speed = lerp(playerAvatar.rigidBody.speed, PLAYER_MIN_SPEED, 0.1f ); //increase speed from current speed to max speed if x+y inputs remain below a "max speed" threshold
			playerState = 2;
		}	
		playerAvatar.obj.pos = playerAvatar.rigidBody.currentPos; //if no collision is found, apply to player character as currentPosition

	//NOTE: calculate next movement and store it in playerAvatar.rigidBody.nextPos
		PlayerMovement(); 
		//PlayerJumpV2();
		
		VectorAdd(&playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.velocity );	
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;
		
	//NOTE: calculate the updated collider position based off of playerAvatar.rigidBody.nextPos but offset on the Z-axis by the radius of the sphere
		SetVector3(&playerAvatar.sphereCollider.center, 	playerAvatar.rigidBody.nextPos.x,playerAvatar.rigidBody.nextPos.y,playerAvatar.rigidBody.nextPos.z + (playerAvatar.sphereCollider.radius));

	//NOTE: After calculating the next player position based on velocity, check to see if the player is colliding with the ground plane
		//and check to see what the players current Z axis should be based on the value of the nearest point on the ground plane.

		
		
		PlayerGroundCollision(dp);	
		
	//NOTE: check to see if the next movement causes a collision and update playerAvatar.rigidBody.nextPos if so
		PlayerCollision(dp); 
		
	//	PlayerJump();
		
	//NOTE: set playerAvatar.rigidBody.currentPos as playerAvatar.rigidBody.nextPos for updating player position and collision checks in the next frame
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;
		
	//NOTE: after horizontal movement is done, check for vertical movement (gravity) 
	//and collision, then update playerAvatar.rigidBody.currentPos.z
	// - RAY/LINE COLLISION from center of player to a tri. 
	// - The ray/line will go straight down on the z axis only

		playerAvatar.playerNormal = playerAvatar.rigidBody.velocity;
		VectorNormalize(&playerAvatar.playerNormal);	

	}
	
	/*
	else if(playerAvatar.isFalling == true || playerAvatar.isJumping == true)
	{
		playerAvatar.obj.pos = playerAvatar.rigidBody.currentPos; //if no collision is found, apply to player character as currentPosition
		playerAvatar.rigidBody.speed = lerp(playerAvatar.rigidBody.speed, 0.0f, 0.4f ); //slowd own to a stop
	
		PlayerJumpV2();
		
		VectorAdd(&playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.velocity );	
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;		
		
		SetVector3(&playerAvatar.sphereCollider.center, 	playerAvatar.rigidBody.nextPos.x,playerAvatar.rigidBody.nextPos.y,playerAvatar.rigidBody.nextPos.z + (playerAvatar.sphereCollider.radius));

		PlayerGroundCollision(dp);	
		PlayerCollision(dp); //check to see if this movement causes a collision
		
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;
		
		playerAvatar.playerNormal = playerAvatar.rigidBody.velocity;
		VectorNormalize(&playerAvatar.playerNormal);
	}
	*/
	
	else
	{	
		playerAvatar.obj.pos = playerAvatar.rigidBody.currentPos; //if no collision is found, apply to player character as currentPosition

		playerAvatar.rigidBody.speed = lerp(playerAvatar.rigidBody.speed, 0.0f, 0.4f ); //slowd own to a stop
		
		//PlayerJumpV2();
		
		VectorAdd(&playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.nextPos, playerAvatar.rigidBody.velocity );				
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;

		SetVector3(&playerAvatar.sphereCollider.center, 	playerAvatar.rigidBody.nextPos.x,playerAvatar.rigidBody.nextPos.y,playerAvatar.rigidBody.nextPos.z + (playerAvatar.sphereCollider.radius));
			
		if(playerAvatar.rigidBody.speed < PLAYER_MIN_SPEED)
			playerState = 0;			
			
		else
		{
			PlayerGroundCollision(dp);	
			PlayerCollision(dp); //check to see if this movement causes a collision
		}
		
		//Note: if player is still moving (even if input has stopped) continue collision checks
		//if(playerAvatar.isFalling == true || playerAvatar.isJumping == true)
		//{

		//}
		
		
		playerAvatar.rigidBody.currentPos = playerAvatar.rigidBody.nextPos;
		
		//playerAvatar.playerNormal = playerAvatar.rigidBody.velocity;
		//VectorNormalize(&playerAvatar.playerNormal);


	}
	
	//if(playerAvatar.isGrounded == 0)
		//playerAvatar.isFalling = 1;

		
		
	//if(tempCollisionBool == 0) //If at the end of the cycle, no tempCollisionBool trigger is made, set 	collisionPoints.collision as false
	
	
	
}


		
int fireRate = 2; //time that must pass before another shot was fired
int lastShotTime = 0; //last time a shot was fired
u8 active = 0;

void CheckEnemyTargets()
{
		if(ContTriger[0].trigger & R_TRIG)
		{ //NOTE: when the player taps the R button it cycles between current active nearby enemies			
		
		
				if(enemyTargets.isActive == 0)
				{					 
					GetActiveSpikey(&enemyTargets);
					//compare distance of enemies and target the closest one. For a test I'll just be targeting a specific one
					enemyTargets.activeTarget = enemyTargets.enemyObjects[active];
					ui_target_init(&enemyTargets);
					enemyTargets.isActive = 1;
				}
				
				else if(enemyTargets.isActive == 1)
				{				
					if(active < 3)					
						active++;					
					else
					{
						active = 0;
						enemyTargets.isActive = 0;
					}
						
					enemyTargets.activeTarget = enemyTargets.enemyObjects[active];
					ui_target_init(&enemyTargets);
					
				}
			
		}	
		

}

void FireShotv2()
{	//update to include a fire rate based on time

	if(ContTriger[0].button & Z_TRIG)
	{		
		playerAvatar.playerShooting = 1;
		lowerArmTimerStart = GetSeconds();
		
		if(abs(lastShotTime - GetFPS_6()) > fireRate)
		{		
			projectileSpawns[shotCycle].isActive = 1;
		
			lastShotTime = GetFPS_6();			
			spawn_player_shot(&projectileSpawns[shotCycle], enemyTargets.activeTarget);	
			//play blaster sound
			PlaySfxVolume(0, 96);
			
			recentShot = shotCycle; 
			
			if(shotCycle >= maxShot-1)	
				shotCycle = 0;				
			else
				shotCycle++;			
			//projectileSpawns[shotCycle].isActive = false;
				
		}
			//projectileSpawns[shotCycle]
	}
	
		
}	

	
	


void UpdateShotv2()	
{
	if(playerAvatar.playerShooting == 1)
	{		
		lowerArmTimer = GetSeconds();
		
		if(abs(lowerArmTimer - lowerArmTimerStart) > lowerArm)
		{	//reset arm position
			playerAvatar.playerShooting = 0;		
			lowerArmTimerStart = 0; 
		}			
	}
	
	
	for(shotCounter = 0; shotCounter < maxShot; shotCounter ++)
	{
		update_player_shot(&projectileSpawns[shotCounter]);
		
	}
	
	Debug_MiscVar[0] = projectileSpawns[recentShot].obj.pos;
	Debug_MiscVar[1] = projectileSpawns[recentShot].obj.rot;
	Debug_MiscVar[2] = projectileSpawns[recentShot].obj.scl;
	Debug_MiscVar[3] = projectileSpawns[recentShot].obj.scl;
}
		
void PlayerMovement()
{

	SetVector3(&playerAvatar.rigidBody.velocity, userInput_Player.x, userInput_Player.y, playerAvatar.rigidBody.velocity.z);	//begins velocity calculation based on userInput_player set in updatePlayer function
	playerAvatar.rigidBody.velocity = RotateAround(playerAvatar.rigidBody.velocity, playerAvatar.rigidBody.centerMass, mainCamera.cameraOrbit);
	
	VectorNormalize(&playerAvatar.rigidBody.velocity);
	VectorScale(&playerAvatar.rigidBody.velocity, (playerAvatar.rigidBody.speed * (float)GetDeltaTime()));
	

	

	
}


void PlayerCollision(Dynamic* dp)
{
	u8 tempCollisionBool = 0;			
	//TO DO NOTE: Add a script to cycle through all nearby collision objects

	//TO DO NOTE: test collision against different objects
	tempCollisionBool = testMesh_CollisionCheck(&playerAvatar.sphereCollider, dp);	
		
	//NOTE: If tempCollisionBool is triggered, set the variable collisionPoints.collision as true
	if(tempCollisionBool == 1)
		collisionPoints.collision = tempCollisionBool; 

}


Vector3 gravityPull = {0,0,-1};
void PlayerGroundCollision(Dynamic* dp)
{
	//playerAvatar.isGrounded = 0;	

	playerAvatar.isGrounded = groundMesh_CollisionCheck(&playerAvatar.sphereCollider);
	groundCollisionPoints.collision = playerAvatar.isGrounded;
	
	
	
	
	
}


//u8 jumpButtonDown = 0;

//float jumpTimerStart = 0;
//float jumpTimerElapsed = 0;
//float finalJumpTime = 0;
//float maxJump	=  50.0;
float jumpingForce = 60.0f;
float resetJumpingForce = 60.0f;
float jumpingForceMultiplyer = 10.0f;
float resetJumpingMultiplyer = 10.0f;
u8 canJump;


//let's try
/*u8 lastFrameButon = 0;
void PlayerJumpV3()
{
	if(ContTriger[0].trigger & B_BUTTON && playerOnGround == 1)
	{
		playerAvatar.isJumping = 1;
		jumpingForceMultiplyer = 60;
	}
	
	if(playerAvatar.isJumping == 1)
	{
		if(jumpingForceMultiplyer > -8)
			jumpingForceMultiplyer -= 8.0 * GetDeltaTime();
	}
}*/ // no time for that now

void PlayerJumpV2()
{
	//TO DO NOTE: Update getGroundCheck for accuracy... it is currently not accurate enough and should only be used for proximity checks. 
	//Update state machine so that player can continue to fall even when not putting any input on b button or analog stick.
	//set up debug to show isFalling and isJumping to see where the issue is
	
	//Distance Check (v1) for distance checks that do not need precision (simple triggers, etc)
	//playerAvatar.isGrounded = getGroundCheck(&playerAvatar.sphereCollider);
	//Ground check (v2)	for distance checks that need precision (ground/wall collision, etc)
	//playerAvatar.isGrounded = AgainstGround(&playerAvatar.sphereCollider, &groundCollisionPoints.currentCollisionPoint);
	//Ground check (v2)	for distance checks that need precision (ground/wall collision, etc)
	//playerAvatar.isGrounded = AgainstGround(&playerAvatar.sphereCollider, &groundCollisionPoints.currentCollisionPoint);
		
	if(ContTriger[0].trigger & B_BUTTON)
		playerAvatar.isJumping = 1;
		
	else if(ContTriger[0].trigger & B_BUTTON)
		playerAvatar.isJumping = 0;
		
	
	if(ContTriger[0].button & B_BUTTON && jumpingForceMultiplyer > 0.0f)
	{
		//if(playerAvatar.isJumping == 0)
			//playerAvatar.jumpForce = PLAYER_MAX_JUMP_SPEED;
		
		//jumpingForceMultiplyer -= GetDeltaTime();
		jumpingForceMultiplyer = lerp(jumpingForceMultiplyer, -8.0, GetDeltaTime());
		playerAvatar.jumpTimerElapsed = jumpingForceMultiplyer;
		
		//playerAvatar.finalJumpTime = jumpingForceMultiplyer;
	}
	
	else if(ContTriger[0].button & B_BUTTON && jumpingForceMultiplyer <= 0.0f)
	{
		playerAvatar.isJumping = 0;
		playerAvatar.isFalling = 1;
		jumpingForceMultiplyer = lerp(jumpingForceMultiplyer, -8.0, GetDeltaTime());
		playerAvatar.jumpTimerElapsed = jumpingForceMultiplyer;
	}
	
	else if((playerAvatar.isJumping == 1 || playerAvatar.isFalling == 1) && playerAvatar.isGrounded == 0)
	{
	
		if(jumpingForceMultiplyer > 0.0f)
		{
			playerAvatar.isJumping = 0;
			playerAvatar.isFalling = 1;
			jumpingForceMultiplyer = -0.1f;
		//	jumpingForceMultiplyer = lerp(jumpingForceMultiplyer, 0.0, GetDeltaTime()*jumpingForceMultiplyer);
			//playerAvatar.jumpTimerElapsed = jumpingForceMultiplyer;
		}
		
		else if(jumpingForceMultiplyer <= 0.0f)
		{
			playerAvatar.isJumping = 0;
			playerAvatar.isFalling = 1;
			jumpingForceMultiplyer = lerp(jumpingForceMultiplyer, -8.0, GetDeltaTime());
			//playerAvatar.jumpTimerElapsed = jumpingForceMultiplyer;
		}
		
		//else
		/*
		else if(!ContTriger[0].button & B_BUTTON && playerAvatar.isGrounded && playerAvatar.isFalling == 1 && jumpingForceMultiplyer <= 0.0f)
		{
			playerAvatar.isJumping = 0;
			playerAvatar.isFalling = 0;
			jumpingForceMultiplyer = 0.0;
		}
		*/
		
	}
	
	else
	{
		playerAvatar.isJumping = 0;
		playerAvatar.isFalling = 0;
		jumpingForceMultiplyer = 8.0;
		
		/*
		if(playerAvatar.isGrounded == false)
			playerAvatar.isFalling = 1;
			
		else	
			playerAvatar.isFalling = 0;
		*/
	}
		
//	if(playerAvatar.isGrounded)
	
	
/*
	SetVector3(&playerAvatar.rigidBody.velocity, userInput_Player.x, userInput_Player.y, playerAvatar.rigidBody.velocity.z);	//begins velocity calculation based on userInput_player set in updatePlayer function
	playerAvatar.rigidBody.velocity = RotateAround(playerAvatar.rigidBody.velocity, playerAvatar.rigidBody.centerMass, mainCamera.cameraOrbit);
	
	VectorNormalize(&playerAvatar.rigidBody.velocity);
	VectorScale(&playerAvatar.rigidBody.velocity, (playerAvatar.rigidBody.speed * (float)GetDeltaTime()));
*/
	if(playerAvatar.isJumping)
	{		
		playerAvatar.rigidBody.velocity.z = jumpingForce*(GetDeltaTime())*jumpingForceMultiplyer;		
	}
	
	if(playerAvatar.isFalling)
	{
		playerAvatar.rigidBody.velocity.z = jumpingForce*(GetDeltaTime())*jumpingForceMultiplyer;	
	}
	
	//else if (!playerAvatar.isJumping )

}

/*
void PlayerJump()
{
	//TO DO: add player "jump" functions
	//if(ContTriger[0].button & R_TRIG)
	
	

	//NOTE: check for input. The longer the player holds the button, the higher they will jump
	
	playerAvatar.isGrounded = getGroundCheck(&playerAvatar.sphereCollider);
	
	if(ContTriger[0].button & B_BUTTON && playerAvatar.jumpTimerElapsed < 3 )
	{			
		if(playerAvatar.isJumping == 0)
		{
			playerAvatar.sphereCollider.enabled = 0;		
			playerAvatar.jumpTimerStart = GetFPS_6();		//this will count up 6 times per second to determine the jump height 
		}
		
		playerAvatar.isJumping = 1;
		
		playerAvatar.jumpTimerElapsed = GetFPS_6() - playerAvatar.jumpTimerStart;		
	
		playerAvatar.rigidBody.velocity.z += PLAYER_MAX_JUMP_SPEED*GetDeltaTime();
	//	playerAvatar.rigidBody.nextPos.z += PLAYER_MAX_SPEED*GetDeltaTime();
	//	playerAvatar.rigidBody.currentPos.z = playerAvatar.rigidBody.nextPos.z;
	}
	
	else if(playerAvatar.isGrounded == 1)
	{		
		playerAvatar.isJumping = 0;
		playerAvatar.isFalling = 0;
		playerAvatar.jumpTimerElapsed = 0;
		playerAvatar.jumpTimerStart = 0;
	}	
	
	else
	{		
		playerAvatar.isJumping = 0;
		playerAvatar.isFalling = 1;
		playerAvatar.jumpTimerElapsed = 0;
		playerAvatar.jumpTimerStart = 0;
		//TO DO NOTE: CHANGE THIS to move to the nearest ground collision point. 
		//A ground collision check will need to be performed when falling.
		playerAvatar.rigidBody.velocity.z -= PLAYER_MAX_JUMP_SPEED*GetDeltaTime();
		//playerAvatar.obj.pos.z = lerp(playerAvatar.obj.pos.z, groundCollisionPoints.currentCollisionPoint.z, PLAYER_MAX_JUMP_SPEED*GetDeltaTime());
		//playerAvatar.obj.pos = 
		
		//playerAvatar.rigidBody.velocity.z -= PLAYER_MAX_JUMP_SPEED*GetDeltaTime();
	}
	
	
	
	
		//SetVector3(&playerAvatar.rigidBody.velocity, userInput_Player.x, userInput_Player.y, 0);	//begins velocity calculation based on userInput_player set in updatePlayer function

	
	

}

*/

/*END------------------------Player Control Functions-----------------------*/



/*--------------------------------------------------------------------------*/
/*------------------------Player Rendering and Animating--------------------*/
/*--------------------------------------------------------------------------*/

void DrawPlayerModel()
{	
	//NOTE: update position, rotation, and scale of player model and store in a matrix:
	//TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,800,980);		
		
	
	//NOTE: RenderPlayerRig(pointer to RigObject, pointer to RigObject function) 
	//This function combine the relative pos/rot etc of each RigObject with that of the player object in a matrix 
	//and then call the function to render the RigObject
	//RigObject head;	RigObject chest;
	//RigObject armR[2];		RigObject armL[2];
	//RigObject legR[2];	RigObject legL[2];	
	

		PlayerObjMTX(&playerAvatar); 	
		
		TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,800,980);	//Fog and texture settings	
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.head, &player_head_PolyList); 
		
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.chest, &player_chest_PolyList); 
		
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.armR[0], &player_right_arm_PolyList); 
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.armR[1], &player_right_arm_lower_PolyList); 
		
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.armL[0], &player_left_arm_PolyList); 
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.armL[1], &player_left_arm_lower_PolyList);
		
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.legR[0], &player_right_leg_PolyList); 
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.legR[1], &player_right_leg_lower_PolyList); 
		
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.legL[0], &player_left_leg_PolyList); 
		PlayerRigObjectMTX(&playerAvatar.animRig.joint.legL[1], &player_left_leg_lower_PolyList);
		
		TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,800,980);	//Fog and texture settings	

		for(shotCounter = 0; shotCounter < maxShot; shotCounter++)
		{
			if(projectileSpawns[shotCounter].isActive == 1)
			{
				draw_player_shot(&projectileSpawns[shotCounter]);
			}
		}
		
}

static void updatePlayerAnim()
{
	//update lighting on playerModel.c passed to playerAvatar via scene triggers in level scripts
	nextPlayerLightingState(); 
	
	
	
	
	
	
	
	//update player animations
	if( GetFPS() < 50)
	{

	if(playerState == 2)
	{
		if(frameCounter >= 1 )
		{	
			if(animFrame<34)
				animFrame = 34;
		
			else if(animFrame < 42)
				animFrame += 1;
		
			else if(animFrame < 81)		
				animFrame += 1; 					
			
			else if(animFrame >= 81)			
				animFrame = 42; 
			
			frameCounter = 0;
			nextPlayerAnimFrame();
		}
		
		else
			frameCounter++;	
	}
	
	if(playerState == 1)
	{
		if(frameCounter >= 1 )
		{			
			if(animFrame <5)
				animFrame += 1;
		
			else if(animFrame < 26)		
				animFrame += 1; 					
			
			else if(animFrame >= 26)			
				animFrame = 6; 
			
			frameCounter = 0;
			nextPlayerAnimFrame();
		}
		
		else
			frameCounter++;	
	}
	
	else if(playerState == 0)
	{
		frameCounter = 0;
		animFrame = 1;
		nextPlayerAnimFrame();
	}
	}

	if( GetFPS() >= 50)
	{

		//NOTE: playerState is temporarily used for signalling if the player is in motion or not and therefore whether the player needs to be animated or not
		if(playerState == 2)
		{
			if(frameCounter >= 2 )
			{	
				if(animFrame<34)
					animFrame = 34;
			
				else if(animFrame < 42)
					animFrame += 1;
			
				else if(animFrame < 81)		
					animFrame += 1; 					
				
				else if(animFrame >= 81)			
					animFrame = 42; 
				
				frameCounter = 0;
				nextPlayerAnimFrame();
			}
			
			else
				frameCounter++;	
		}
		
		else if(playerState == 1)
		{
			if(frameCounter >= 2 )
			{			
				if(animFrame <5)
					animFrame += 1;
			
				else if(animFrame < 26)		
					animFrame += 1; 					
				
				else if(animFrame >= 26)			
					animFrame = 6; 
				
				frameCounter = 0;
				nextPlayerAnimFrame();
			}
			
			else
				frameCounter++;	
		}
		
		else if(playerState == 0)
		{
			frameCounter = 0;
			animFrame = 1;
			nextPlayerAnimFrame();
		}
	
	}
	
	//play step sound
	if(animFrame == 6 || animFrame == 16)
		//play blaster sound
			PlaySfx_Footstep(6);

}

/*END---------------------Player Rendering and Animating--------------------*/



