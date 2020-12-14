#ifndef _CONTROLLERDEFS_H
#define _CONTROLLERDEFS_H
//#include "transformDefs.h"
#include "common.h"

typedef enum CONT_OPTIONS_ENUM
{
	//NOTE: control player with Stick
    CONT_STICK, 
	//NOTE: control player with D-Pad
    CONT_DPAD, 
    //NOTE: control player with C-Buttons
	CONT_CBUTTON 
}CONT_OPTIONS;

typedef enum FACE_OPTIONS_ENUM
{
	//NOTE: face button options when controlling player with CONT_STICK or CONT_CBUTTON. D-Pad L, R, U not used
	A_B_DPAD_DOWN, 
    B_A_DPAD_DOWN, 
	//NOTE: face button options when controlling player with CONT_DPAD. C-Button L, R, U not used
    A_B_CBUTTON_DOWN, 
    B_A_CBUTTON_DOWN 
}FACE_OPTIONS;

extern enum CONT_OPTIONS contPrefs;

extern Vector2 Camera_Input();
extern Vector2 Player_Input();


#endif