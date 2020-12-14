#include "common.h"

/*--------------------------------------------------------------------------*/
/*----------------------------Player Projectiles----------------------------*/
/*--------------------------------------------------------------------------*/


extern unsigned char DebugTexture_Orange[];
extern unsigned short DebugTexture_Orange_tlut[];


	Lights1 projectileLight = gdSPDefLights1( 
		200,25,150,
		0,0,0,
		0,0,0);


Vtx player_missile_VertList_0 [] = {
   { 3.37, -0.54, -0.57, 1, 0x0000, 0x1000, 255, 255, 255, 255}, 
   { -0.70, 20.50, 0.22, 1, 0x0000, 0x1000, 255, 255, 255, 255}, 
   { 1.02, 20.50, 0.22, 1, 0x0000, 0x1000, 255, 255, 255, 255}, 
   { 0.09, -0.54, 1.29, 1, 0x0000, 0x1000, 255, 255, 255, 255}, 
   { -2.96, -0.54, -0.89, 1, 0x0000, 0x1000, 255, 255, 255, 255}, 
   { 0.16, -2.90, -0.22, 1, 0x0000, 0x1000, 255, 255, 255, 255}, 
};

//Test Object = 1 
Vtx player_shot_VertList_0 [] = {
   { -2.70, -2.00, 0.83, 1, 0x0000, 0x1000, -84, -47, 81, 255}, 
   { 2.35, -2.01, 0.85, 1, 0x1000, 0x1000, 83, -48, 82, 255}, 
   { 0.06, 13.76, 0.80, 1, 0x1000, 0x0000, 1, 126, 7, 255}, 
   { 2.35, -3.02, -1.37, 1, 0x0000, 0x1000, 74, -81, -61, 255}, 
   { -2.70, -3.01, -1.43, 1, 0x1000, 0x1000, -75, -80, -63, 255}, 
};




void player_missile_PolyList(u8 animFrame) 
 { 

   Vtx *player_missile_VTXPointer = &player_missile_VertList_0[0]; 

   gSPVertex(glistp++,player_missile_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 0 'player_missile'OK 

	TEXTURE_4B_TLUT(glistp, DebugTexture_Orange, DebugTexture_Orange_tlut, 6,1);
	gSPSetLights2(glistp++, projectileLight);
   gSPVertex(glistp++,player_missile_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,2, 1, 3, 2); 
   gSP1Triangle(glistp++,1, 4, 3, 1); 
   gSP1Triangle(glistp++,2, 3, 0, 2); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,0, 3, 5, 0); 
   gSP1Triangle(glistp++,4, 0, 5, 4); 
   gSP1Triangle(glistp++,0, 4, 1, 0); 

   gDPPipeSync(glistp++);

 } 
 
 //Test Object = 1 
void player_shot_PolyList(u8 animFrame) 
 { 

   Vtx *player_shot_VTXPointer = &player_shot_VertList_0[0]; 

   gSPVertex(glistp++,player_shot_VTXPointer+0,26,0);

//OBJECT: 1 MATERIAL NO. 0 'Player_shot'OK 

   TEXTURE_4B_TLUT(glistp, DebugTexture_Orange, DebugTexture_Orange_tlut, 6,1);

gSPSetLights2(glistp++, projectileLight);
   gSPVertex(glistp++,player_shot_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 2, 3); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x00001000);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x10000000);
   gSP1Triangle(glistp++,2, 1, 3, 2); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x10000000);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x00000000);
   gSP1Triangle(glistp++,1, 0, 4, 1); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00001000);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x10001000);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x10000000);
   gSP1Triangle(glistp++,0, 2, 4, 0); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x00001000);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x00000000);
   gSP1Triangle(glistp++,3, 1, 4, 3); 

   gDPPipeSync(glistp++);

 } 
 
 
 //	SetVector3(&playerAvatar.rigidBody.velocity, userInput_Player.x, userInput_Player.y, 0);	//begins velocity calculation based on userInput_player set in updatePlayer function

 //NOTE: pass the current projectile to spawn as well as the enemy targetObject (This will only be used if "enemyTargets" is currently active)
 void spawn_player_shot(ProjectileObject* projectile, GameObject* targetObject)
 {
 
 
 
	//Vector3 tempVelocity = vectorScale(playerAvatar.playerNormal, 20.0f);
	
	
	
	
	
	
	
	//Vector3 testTarget = {0,0,0};
	Vector3 testTarget = targetObject->pos;
	Vector3 tempVelocity = {0,0,0};
	
	
		
		
		
		//playerAvatar.playerNormal = playerAvatar.rigidBody.velocity;
		//VectorNormalize(&playerAvatar.playerNormal);	
		
	//else if(enemyTargets.isActive == 1) 
	
	
	
	
	
 
	//NOTE: spawn just above player collider position and match player rotation at the time projectile is fired
	SetVector3(&projectile->obj.pos, playerAvatar.sphereCollider.center.x +tempVelocity.x,playerAvatar.sphereCollider.center.y +tempVelocity.y ,playerAvatar.sphereCollider.center.z + 40.0f + tempVelocity.z);
	SetVector3(&projectile->obj.rot, 0,0,playerAvatar.obj.rot.z); 
	SetVector3(&projectile->obj.scl, 3,3,3);		
	

	SetVector3(&projectile->rigidBody.centerMass, 0,0,0); 
	projectile->rigidBody.speed = 3.0f;	
	projectile->sphereCollider.enabled = true;	
	projectile->sphereCollider.radius = 30.0f;
	SetVector3(&projectile->sphereCollider.center, 		projectile->obj.pos.x,projectile->obj.pos.y,projectile->obj.pos.z + (projectile->sphereCollider.radius));
	SetAnimator(&projectile->animator, &player_shot_PolyList, 0,0);		
	
	if(enemyTargets.isActive == 1) 
	{
		tempVelocity = vectorSubtract(testTarget, projectile->obj.pos);
		VectorNormalize(&tempVelocity);
		tempVelocity = vectorScale(tempVelocity, 20.0f);
	}
 
	if(enemyTargets.isActive == 0) 
	{		
		//tempVelocity = vectorSubtract(projectile->obj.pos, playerAvatar.playerNormal);		
		
		
		//NOTE: when doing "precision aim" set velocity as the direction of the player position to the camera position
		//so that you can aim up/down instead of just straight ahead. This will also allow for
		//precision aim
		
		VectorNormalize(&tempVelocity);
		tempVelocity = vectorScale(playerAvatar.playerNormal, 20.0f);
		tempVelocity.z = 0.0f; //NOTE: zero this out unless an enemy is targeted
	}
	
	SetVector3(&projectile->rigidBody.velocity, tempVelocity.x,tempVelocity.y,tempVelocity.z); 
	
 }
 
 void draw_player_shot(ProjectileObject* projectile)
 {
	RenderProjectileObj(projectile);
 }
 
  void update_player_shot(ProjectileObject* projectile)
 {

	if(absDistance(projectile->obj.pos, playerAvatar.obj.pos) >= 10000.0f )	
		projectile->isActive = 0;
 
	else
	{	
		projectile->obj.pos = vectorAdd(projectile->obj.pos, projectile->rigidBody.velocity);
		projectile->sphereCollider.center = projectile->obj.pos;
	}
	
	//Check for collisions (eventually this will call a script in enemy manager... but for now just calling spikey directly)
	Spikey_Collision(projectile);

 }
 
/*END-------------------------Player Projectiles----------------------------*/