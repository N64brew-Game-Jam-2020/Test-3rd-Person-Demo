#include "view.h"
#include "common.h"

CameraObject mainCamera;
/*
    GameObject obj; //Note:pointer to game object (pos, rot, scl)
	GameObject* camLook; //Note: GameObject pointer of object camera is currently looking at (ex player character)
	Vector3 cameraOffset; //Note: distance to offset from "camLook"
	
	float cameraOrbit; //Note:Orbital position around player character (0-360 degrees)
	float distance; //Note: Current distance 
	float adjDistance;	//Note: adjusted distance when colliding with wall or object
	float nearPosition;	//Note: used for nearClipping 
	u8 againstWall;
*/


Vector3 cameraPosition = { 0.0f, -300.0f,  125.0f};
Vector3 camUpdatedPosition = { 0.0f, -300.0f,  125.0f};
Vector3 camLook = {0.0f, 0.0f, 0.0f};
Vector3 cameraOffset = { 0.0f, -300.0f, 125.0f};
float cameraOrbit = 0.0f; //Rotation around player from a set distance
Vector3 playerPos = {0.0f, 0.0f, 0.0f};

u8 camCollidedWithObject = 0;
u8 camIsAgainstWall;
	
float distance = -750.0f;
float adjDistance = -750.0f;
//float nearPosition = 200;
float nearPosition = 50;

float lookZMin = 125; //for looking down
float lookZMax = 225; //for looking up
float lookZ = 110; //for looking up

/*--------------------------------------------------------------------------*/
/*-------------------------------Camera Setup-------------------------------*/
/*--------------------------------------------------------------------------*/

void SetGameViewMtx( Dynamic* dp )
{
//ADJUSTABLE CAMERA ANGLE FIXED----------------------------------------------------------------------------------------------------

	u16   perspNorm;
    static LookAt lookat;	

	/*WORKING VERSION:
    guPerspective(&dp->projection, &perspNorm,
		  22, (float)SCREEN_WD/(float)SCREEN_HT, nearPosition, 2750, 1.0);*/
		  
	//guPerspective(&dp->projection, &perspNorm,
		//  45, (float)SCREEN_WD/(float)SCREEN_HT, nearPosition, 4000, 1.0);
		// 45, (float)SCREEN_WD/(float)SCREEN_HT, nearPosition, 3500, 1.0);
		
	guPerspective(&dp->projection, &perspNorm, 45, ((float)SCREEN_WD/(float)SCREEN_HT), nearPosition, 3250, 1.0f);

    guLookAtReflect(&dp->viewing, &lookat,
			mainCamera.obj.pos.x,
			mainCamera.obj.pos.y,
			mainCamera.obj.pos.z,
			mainCamera.camLookPoint.x,mainCamera.camLookPoint.y, mainCamera.camLookPoint.z + lookZ, 
		    //returnPlayerPosition(0), returnPlayerPosition(1), returnPlayerPosition(2)-50, //What object we are looking at
		    0, 0, 1); //Up direction
 
    gSPPerspNormalize(glistp++, perspNorm);
    gSPLookAt(glistp++, &lookat);

    gSPMatrix(glistp++, &(dp->projection), 
	      G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(glistp++, &(dp->viewing), 
	      G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
		  
 
//ADJUSTABLE CAMERA ANGLE FIXED----------------------------------------------------------------------------------------------------		 
	
}

void SetMenuViewMtx( Dynamic* dp )
{

//ADJUSTABLE CAMERA ANGLE FIXED----------------------------------------------------------------------------------------------------

	u16   perspNorm;
    static LookAt lookat;	

	//WORKING VERSION:
    guPerspective(&dp->projection, &perspNorm,
		  22, (float)SCREEN_WD/(float)SCREEN_HT, nearPosition, 1750, 1.0);

    guLookAtReflect(&dp->viewing, &lookat,
			mainCamera.obj.pos.x,
			mainCamera.obj.pos.y,
			mainCamera.obj.pos.z,
			mainCamera.camLookPoint.x,mainCamera.camLookPoint.y, mainCamera.camLookPoint.z + 500.0f,
		    //returnPlayerPosition(0), returnPlayerPosition(1), returnPlayerPosition(2)-50, //What object we are looking at
		    0, 0, 1); //Up direction
 
    gSPPerspNormalize(glistp++, perspNorm);
    gSPLookAt(glistp++, &lookat);

    gSPMatrix(glistp++, &(dp->projection), 
	      G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(glistp++, &(dp->viewing), 
	      G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
		  
 
//ADJUSTABLE CAMERA ANGLE FIXED----------------------------------------------------------------------------------------------------		 
	
}

float tempCameraOrbit;
Vector3 tempCameraOffset;
float userInput_X = 0.1f;
float userInput_Y = 0.1f;
float cameraSensitivity = 1.0f;
void initMainCamera()
{
	//mainCamera
	SetVector3(&mainCamera.obj.pos, 0.0f, -300.0f, 125.0f); //Note:pointer to game object (pos, rot, scl)
	SetVector3(&mainCamera.obj.rot, 0.0f, 0.0f, 0.0f);
	SetVector3(&mainCamera.obj.scl, 1.0f, 1.0f, 1.0f);
	SetVector3(&mainCamera.camLookPoint, playerAvatar.obj.pos.x, playerAvatar.obj.pos.y, 5.0f); //Note: distance to offset from "camLook"
	mainCamera.camLook = &playerAvatar.obj; //Note: GameObject pointer of object camera is currently looking at (ex player character)
	SetVector3(&mainCamera.cameraOffset, 0.0f, -300.0f, 125.0f);
	
	mainCamera.cameraOrbit = 0.0f; //Note:Orbital position around player character (0-360 degrees)
	mainCamera.distance = -750; //Note: Current distance 
	mainCamera.adjDistance = -750;	//Note: adjusted distance when colliding with wall or object
	mainCamera.nearPosition = 50;	//Note: used for nearClipping 
	mainCamera.againstWall = 0; 
}
/*END----------------------------Camera Setup-------------------------------*/

#define cameraSmoothSpeed 4 //value to lerp camera position
void CameraControl_C()
{
		//NOTE: Get L and R C button input for horizontal/orbital movement around player character			
			if(ContTriger[0].button & R_CBUTTONS)
				//userInput_X = lerp(userInput_X, 3.0f, 0.01f);		
				userInput_X = lerp(userInput_X, 3.0f, cameraSensitivity * (float)GetDeltaTime());		
		//NOTE: Only allow user to press one of the L or R buttons	
			else if(ContTriger[0].button & L_CBUTTONS)		
				//userInput_X = lerp(userInput_X, -3.0f, 0.01f);
				userInput_X = lerp(userInput_X, -3.0f, cameraSensitivity * (float)GetDeltaTime());
		//NOTE: When user depresses the C button, quickly lerp down camera movement
			else if(userInput_X >= 0.2f || userInput_X <= -0.2f )
				//userInput_X = lerp(userInput_X, 0.0f, 0.2f);	
				userInput_X = lerp(userInput_X, 0.0f, (cameraSensitivity*4) * (float)GetDeltaTime());		
		//NOTE: Once userInput_Y movement speed is below |.2f|, set it to 0.0f to avoid drift
			else
				userInput_X = 0.0f;
		
		//NOTE: Apply userInput_X to tempCamera Orbit and keep it in the 0-360 degree range			
			tempCameraOrbit += userInput_X;					
			if(tempCameraOrbit >= 360.0f)
				tempCameraOrbit -= 360.0f;
			else if(tempCameraOrbit < 0.0f)
				tempCameraOrbit += 360.0f;		
		
		
		//NOTE: Get U and D C button input for vertical/distance from player character		
			userInput_Y = 0.0f;
			
			if(ContTriger[0].button & U_CBUTTONS)
				userInput_Y += (cameraSensitivity*150) * (float)GetDeltaTime();
				
			else if(ContTriger[0].button & D_CBUTTONS)
				userInput_Y -= (cameraSensitivity*150) * (float)GetDeltaTime();				
		
		//NOTE: Adjust distance of camera from player
			if(userInput_Y > 0.1f && tempCameraOffset.y <= -300.0f)						
				tempCameraOffset.y = lerp(tempCameraOffset.y, -300.0f, userInput_Y * 0.01f);

			else if(userInput_Y > 0.1f && tempCameraOffset.y > -300.0f)						
				tempCameraOffset.y = -300.0f;
			
			if(userInput_Y < 0.0f && tempCameraOffset.y >= -1000.0f)						
				tempCameraOffset.y = lerp(tempCameraOffset.y, -1000.0f, userInput_Y * -0.01f);

			else if(userInput_Y < 0.0f && tempCameraOffset.y < -1000.0f)						
				tempCameraOffset.y = -1000.0f;


		//NOTE: Adjust camera vertical position
			if(userInput_Y < 0.1f && tempCameraOffset.z <= 300.0f)						
				tempCameraOffset.z = lerp(tempCameraOffset.z, 300, userInput_Y * -0.01f);			
			
			else if(userInput_Y < 0.1f && tempCameraOffset.z > 300.0f)			
				tempCameraOffset.z = 300.0f;			
			
			if(userInput_Y > 0.0f && tempCameraOffset.z >= 125.0f)						
				tempCameraOffset.z = lerp(tempCameraOffset.z, 125, userInput_Y * 0.01f);			
						
			else if(userInput_Y > 0.0f && tempCameraOffset.z <= 125.0f)			
				tempCameraOffset.z = 125.0f;
				
}

/*--------------------------------------------------------------------------*/
/*-------------------Calculate Camera Position and Orbit--------------------*/
/*--------------------------------------------------------------------------*/
u8 cameraInitalPosed = 0;
void UpdateCameraPosition( Dynamic* dp )
{
/*------------------------Calculate Rotating Camera-------------------------*/
		//Note: update camLookPoint based on the object being looked at
		GameObject* lookObject = mainCamera.camLook;
		SetVector3(&mainCamera.camLookPoint, playerAvatar.obj.pos.x, playerAvatar.obj.pos.y, 5.0f); //Note: distance to offset from "camLook"

		tempCameraOffset = mainCamera.cameraOffset;
		tempCameraOrbit = mainCamera.cameraOrbit;				
		
		CameraControl_C();

/*-------------------------Depth/Horizontal Distance------------------------*/
		if(userInput_Y >= 1.0f || userInput_Y <= -1.0f )
		{
			if(camIsAgainstWall == 0)
			{					
				if(distance >= 600)
					
						nearPosition = 450;						
	
					
				else if(distance <= 600 && distance >= 500)
					nearPosition = 400;
				
				else if(distance < 500)
					
						nearPosition = 50;	
						
			}			
				else
				{
					if(adjDistance >= 600)					
						nearPosition = 450;											
					else if(adjDistance <= 600 && adjDistance >= 500)
						nearPosition = 400;
					else if(adjDistance < 500)
					
						nearPosition = 50;	
						
						
				}
		}	
		
/*END-------------------------Depth/Horizontal Distance------------------------*/		
		
		camUpdatedPosition = RotateCameraAround( vectorAdd(mainCamera.camLookPoint, tempCameraOffset), mainCamera.camLookPoint, tempCameraOrbit);
		
		mainCamera.cameraOrbit = tempCameraOrbit;
		mainCamera.cameraOffset = tempCameraOffset;	
				
		//lerp the canera quickly into position to soften sudden changes and jitters
		if(cameraInitalPosed == 1)
		{
			mainCamera.obj.pos.x = lerp(mainCamera.obj.pos.x,camUpdatedPosition.x,(float)GetDeltaTime()*cameraSmoothSpeed);	
			mainCamera.obj.pos.y = lerp(mainCamera.obj.pos.y,camUpdatedPosition.y,(float)GetDeltaTime()*cameraSmoothSpeed);	
			mainCamera.obj.pos.z = lerp(mainCamera.obj.pos.z,camUpdatedPosition.z,(float)GetDeltaTime()*(cameraSmoothSpeed*.5f));
		}
		else
		{
			mainCamera.obj.pos = mainCamera.obj.pos;
			cameraInitalPosed = 1;
		}
		
		
		
		//NO WALL COLLISION 		
		/*
		mainCamera.obj.pos.x = (int)mainCamera.obj.pos.x;
		mainCamera.obj.pos.y = (int)mainCamera.obj.pos.y;
		mainCamera.obj.pos.z = (int)mainCamera.obj.pos.z;
		
		camLook.x = (int)camLook.x;
		camLook.y = (int)camLook.y;
		camLook.z = (int)camLook.z;
		*/

}

/*END----------------Calculate Camera Position and Orbit--------------------*/

