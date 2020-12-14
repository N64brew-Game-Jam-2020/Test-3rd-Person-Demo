#ifndef _COMMON_H
#define _COMMON_H

#include <ultra64.h>
#include <nusys.h>
#include <libmus.h>
#include <stdio.h>
#include <PR/gu.h>

#include <n_libaudio.h>

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "debug.h"
#include "gfxmacros.h"
#include "graphic.h"
/// @brief typedef declarations
/// @note Use this for flags
#include "boolCast.h"
#include "gamemain.h"
#include "main.h"
#include "font.h"
#include "view.h"
#include "audio.h"

#include "transformDefs.h"
#include "objectDefs.h"
#include "playerDefs.h"
#include "enemyDefs.h"
#include "engineTools.h"
#include "controllerDefs.h"
#include "userInterfaceDefs.h"
//#include "levelDefs.h"

#define GRAVITY -.9f
#define FLOOR_Z 0.0f
#define STICK_DEADZONE 16

#include "C99ToNintendo.h"

extern u8 DEBUG;

#define PI 3.14159
#define RAD2DEG 57.29577

/*--------------------------------------------------------------------------*/
/*----------------------------Extern Declarations---------------------------*/
/*--------------------------------------------------------------------------*/

extern void CalcSysTime();
extern f32 GetDeltaTime();

extern void FrameCount();

extern void InitDebug();

extern int GetFPS(); //returns the game's average FPS
extern int GetFPS_6(); //returns a timer that updates 6 times / second 
extern int GetFPS_12(); //returns a timer that updates 12 times / second 
extern int GetFPS_24(); //returns a timer that updates 24 times / second

extern Vector3 Debug_MiscVar[4]; //set miscellaneous variables for debugging 

extern Debug_Collision debug_Collision;




#endif // _COMMON_H
