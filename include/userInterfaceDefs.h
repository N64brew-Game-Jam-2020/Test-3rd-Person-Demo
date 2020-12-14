#ifndef _UI_DEFS_H
#define _UI_DEFS_H
//#include "transformDefs.h"
#include "common.h"


/*--------------------------------------------------------------------------*/
/*-----------------------userInterfaceModels.c Functions--------------------*/
/*--------------------------------------------------------------------------*/

extern void ui_target_init(); //initiate or re-initiate UI target models
extern void UI_Target_Render(); //render UI target models
extern void UI_Target_Update(); //update position and state of target ring and arrow
extern void target_ring_PolyList(u8 animFrame); 
extern void target_arrow_PolyList(u8 animFrame);

/*--------------------------------------------------------------------------*/
/*-----------------------userInterfaceTextures.c Textures--------------------*/
/*--------------------------------------------------------------------------*/
extern unsigned char glow_material[];
extern unsigned short glow_material_tlut[];



#endif