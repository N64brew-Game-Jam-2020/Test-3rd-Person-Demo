
#ifndef _PLAYERSHIPDEFS_H
#define _PLAYERSHIPDEFS_H
//#include "transformDefs.h"
#include "common.h"


extern Vtx player_ship_VertList_0 [];
extern Vtx Ship_Drife_Flame2_VertList_0 [];
extern Vtx player_ship_drive_VertList_0 [];
extern Vtx Tuster_FLame_VertList_0 [];
extern Vtx Shadow2_VertList_0 [];
extern Vtx Billboard_ShipDrive_VertList_0 [];
extern void player_ship_PolyList(u8 animFrame);
extern	void Ship_Drife_Flame2_PolyList(u8 animFrame) 	;
extern	void player_ship_drive_PolyList(u8 animFrame) 	;
extern	void Tuster_FLame_PolyList(u8 animFrame) 	;
extern	void Shadow2_PolyList(u8 animFrame) 	;
extern	void Billboard_ShipDrive_PolyList(u8 animFrame)	;


extern unsigned char shipbodytexture[];
extern unsigned short shipbodytexture_tlut[];
extern unsigned char shipthruster[];
extern unsigned short shipthruster_tlut[];

#endif