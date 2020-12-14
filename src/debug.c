#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <common.h>


/*------------TO USE DEBUG FEATURES----------------
Mike Updated to James build: 08/10/2020
Mike Added: 08/8/2020

from Makefile, set LDEFS to:
LCDEFS = -DNU_DEBUG -DF3DEX_GBI_2
--------------TO USE DEBUG FEATURES--------------*/

char FPS[8];
char debugStringA[50];
char debugStringB[50];
char debugStringC[50];
char debugStringD[50];


Debug_Collision debug_Collision =
{
	0, 0, 0.0f, // u8 collision, u8 triNum
	{0,0,0}, //Vector3 triNormal
	{0,0,0}, //Vector3 lastCollisionPoint
	{0,0,0}, //Vector3 currentCollisionPoint
};

Vector3 Debug_MiscVar[4];

enum TEXT_COLORS
{
    TEXT_BLACK,
    TEXT_BLUE,
    TEXT_GREEN,
    TEXT_CYAN,
    TEXT_RED,
    TEXT_MAGENTA,
    TEXT_YELLOW,
    TEXT_WHITE,
    NUM_OF_COLORS
};


//	This will be used to toggle between different debug modes	

enum DEBUG_MODE
{
	DEBUG_NONE, //displays FPS only
	DEBUG_MISC,
    DEBUG_PLAYER, //positions for ball, camera and car	
    DEBUG_WALL_COLLISION, //rotations for ball, camera and car
	DEBUG_GROUND_COLLISION,
	DEBUG_CAM //camera debug info 
	//*****Add a new mode here for whatever you are testing
}debugMode;




extern void FPSCalc();

void InitDebug()
{
	debugMode = DEBUG_NONE;
	nuDebConScroll(NU_DEB_CON_WINDOW0, NU_DEB_CON_SCROLL_OFF );
	nuDebConScroll(NU_DEB_CON_WINDOW1, NU_DEB_CON_SCROLL_OFF );
	nuDebConTextColor(NU_DEB_CON_WINDOW0, TEXT_WHITE);
	nuDebConTextColor(NU_DEB_CON_WINDOW1, TEXT_WHITE);
	nuDebConClear(NU_DEB_CON_WINDOW0);
	nuDebConClear(NU_DEB_CON_WINDOW1);
}

void SetDebugString()
{	
	sprintf(FPS, "FPS %02i",  GetFPS()); //if debug is flagged, displays FPS by default in any mode
	//debugMode = DEBUG_NONE;
	switch(debugMode)
	{		
		case DEBUG_NONE: //when flag _DEBUG is set and debugMode is set to DEBUG_NONE, then NU_DEB_CON_WINDOW1 (game FPS) is displayed but not but not NU_DEB_CON_WINDOWO
			break;
			
		case DEBUG_MISC: //Use to debug specific things - for testing game logic, etc
			sprintf(debugStringA, "MISC[0]: X %.2f Y %.2f Z %.2f ",  Debug_MiscVar[0].x,  Debug_MiscVar[0].y, Debug_MiscVar[0].z);
			sprintf(debugStringB, "MISC[1]: X %.2f Y %.2f Z %.2f ",  Debug_MiscVar[1].x,  Debug_MiscVar[1].y, Debug_MiscVar[1].z);
			sprintf(debugStringC, "MISC[2]: X %.2f Y %.2f Z %.2f ",  Debug_MiscVar[2].x,  Debug_MiscVar[2].y, Debug_MiscVar[2].z);
			sprintf(debugStringD, "MISC[3]: X %.2f Y %.2f Z %.2f ",  Debug_MiscVar[3].x,  Debug_MiscVar[3].y, Debug_MiscVar[3].z);
			break;
			
		case DEBUG_PLAYER: //display rotations for ball, camera and car
			sprintf(debugStringA, "Player Pos: X %.2f Y %.2f Z %.2f ",  playerAvatar.obj.pos.x,  playerAvatar.obj.pos.y, playerAvatar.obj.pos.z);
			//sprintf(debugStringB, "Player Rot: X %.2f Y %.2f Z %.2f ",  playerAvatar.obj.rot.x,  playerAvatar.obj.rot.y, playerAvatar.obj.rot.z);
			sprintf(debugStringB, "Player Jump: X %i Y %.2f Z %.2f ",  playerAvatar.isJumping,  playerAvatar.jumpTimerElapsed, playerAvatar.finalJumpTime);
			sprintf(debugStringC, "Player Fall: X %i Y %i Z %.2f ",  playerAvatar.isFalling,  playerAvatar.isGrounded, 0.0f);
			//sprintf(debugStringC, "Player Vel: X %.2f Y %.2f Z %.2f ",  playerAvatar.rigidBody.velocity.x,  playerAvatar.rigidBody.velocity.y, playerAvatar.rigidBody.velocity.z);
			sprintf(debugStringD, "Player Norm: X %.2f Y %.2f Z %.2f ",  playerAvatar.playerNormal.x,  playerAvatar.playerNormal.y, playerAvatar.playerNormal.z);	

			break;
			
		case DEBUG_WALL_COLLISION: 
			sprintf(debugStringA, "Collide %i | Near Tri %i | vDot %.2f ", collisionPoints.collision, collisionPoints.triNum, collisionPoints.vDot); //eventually do collision checks for what the player's car is colliding with
			sprintf(debugStringB, "Player Collid %.2f | %.2f | %.2f ",  playerAvatar.sphereCollider.center.x, playerAvatar.sphereCollider.center.y, playerAvatar.sphereCollider.center.z);
			sprintf(debugStringC, "Nearest Point %.2f | %.2f | %.2f ", collisionPoints.currentCollisionPoint.x, collisionPoints.currentCollisionPoint.y, collisionPoints.currentCollisionPoint.z); //eventually do collision checks for what the player's car is colliding with
			sprintf(debugStringD, "Time Check: %llu ",  getLapTime);
			break;

		case DEBUG_GROUND_COLLISION: 
			sprintf(debugStringA, "Collide %i | Near Tri %i | vDot %.2f ", groundCollisionPoints.collision, groundCollisionPoints.triNum, groundCollisionPoints.vDot); //eventually do collision checks for what the player's car is colliding with
			sprintf(debugStringB, "Player Collid %.2f | %.2f | %.2f ",  playerAvatar.sphereCollider.center.x, playerAvatar.sphereCollider.center.y, playerAvatar.sphereCollider.center.z);
			sprintf(debugStringC, "Nearest Point %.2f | %.2f | %.2f ", groundCollisionPoints.currentCollisionPoint.x, groundCollisionPoints.currentCollisionPoint.y, groundCollisionPoints.currentCollisionPoint.z); //eventually do collision checks for what the player's car is colliding with
			sprintf(debugStringD, "Time 6 per second: %i ",  GetFPS_6());
			break;
		
	//	mainCamera.cameraOrbit = tempCameraOrbit;
	//	mainCamera.cameraOffset = tempCameraOffset;		
		
		
		case DEBUG_CAM: 
			sprintf(debugStringA, "Camera Pos: X %.2f Y %.2f Z %.2f ", mainCamera.obj.pos.x,  mainCamera.obj.pos.y, mainCamera.obj.pos.z); //camera position
			sprintf(debugStringB, "Camera Rot: X %.2f Y %.2f Z %.2f ",  mainCamera.obj.rot.x,  mainCamera.obj.rot.y, mainCamera.obj.rot.z);
			sprintf(debugStringC, "Nearest Point %.2f | %.2f | %.2f ", groundCollisionPoints.currentCollisionPoint.x, groundCollisionPoints.currentCollisionPoint.y, groundCollisionPoints.currentCollisionPoint.z); //eventually do collision checks for what the player's car is colliding with
			sprintf(debugStringD, "Time Check: %i ",  GetFPS_12());
			break;
}
		
}

//void DebugPrint(player_t* player, cam_t* camera, ball_t* ball, NUContData* contdata)
void DebugPrint()
{

//-------nuDebConClear clears the buffer for each console window before printing updated string:---------
		nuDebConClear(NU_DEB_CON_WINDOW0);
		nuDebConClear(NU_DEB_CON_WINDOW1);		
	//	sprintf(FPS, "Sec: %02i",  40); //if debug is flagged, displays FPS by default in any mode

		
	
		//SetDebugString(player, camera, ball, contdata );		
		
//-------nuDebConTextPos sets the position on screen of the console text window ---- nuDebConTextPos(window number, column, row); ---------
		nuDebConTextPos(1, 1,2);
//-------nuDebConCPuts sends a string to a console window ---- nuDebConCPuts(window#, string); ---------

		nuDebConCPuts(NU_DEB_CON_WINDOW1, FPS);		//when _DEBUG flag is made, always at least display FPS. 

		if (debugMode != DEBUG_NONE) 
		{	//Strings A,B,C vary depending on the current debugMode being checked
			nuDebConTextPos(0, 1,11);
			nuDebConCPuts(NU_DEB_CON_WINDOW0, debugStringA);
			nuDebConTextPos(0, 1,13);
			nuDebConCPuts(NU_DEB_CON_WINDOW0, debugStringB);				
			nuDebConTextPos(0, 1,15);			
			nuDebConCPuts(NU_DEB_CON_WINDOW0, debugStringC);		
/*			
			nuDebConTextPos(0, 1,17);			
			nuDebConCPuts(NU_DEB_CON_WINDOW0, debugStringD);
			
			nuDebTaskPerfBar1EX2(6,200,NU_SC_NOSWAPBUFFER);
			*/
			
		}
		
		//nuDebConDisp(NU_SC_NOSWAPBUFFER);		
		nuDebConDisp(NU_SC_SWAPBUFFER);

}

void ToggleDebugMode()
{

	if(debugMode < DEBUG_CAM)
		debugMode++;
		
	else
		debugMode = DEBUG_NONE;
		
	SetDebugString();
		
	
}

