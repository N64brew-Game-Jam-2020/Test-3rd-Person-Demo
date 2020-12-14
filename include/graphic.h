
#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
//#include "common.h"
#include "para.h"
#include "transformDefs.h"
#include "objectDefs.h"

// Gameplay screen size
#define SCREEN_HT        240
#define SCREEN_WD        320

// Gameplay screen size
#define MENU_SCREEN_HT        480
#define MENU_SCREEN_WD        640


/* The maximum length of the display list of one task  */
#define GFX_GLIST_LEN     2048*10
#define GFX_CLEAR_GLIST_LEN     512
//#define GFX_GLIST_DEBUG_LEN     2048*10

/* The maximum value of the graphic task in the 1 retrace period  */
#define GFX_GTASK_NUM        2


/*-------------------------- define structure ------------------------------ */
/* The projection-matrix structure  */
typedef struct {
	
Mtx viewingSpecHilite;
Mtx projectionSpecHilite;
	
  Mtx     projection;
  Mtx     modeling;
  Mtx     viewing; 
  
 // Mtx     base_trans;
 // Mtx     base_rotate;
 // Mtx     base_scale;

 // Mtx     saku_trans;
 // Mtx     saku_rotate;
 // Mtx     saku_scale;

  Mtx     obj_trans[OBJ_MAX]; /*OBJ_MAX is the number of map objects*/
  Mtx     obj_rotate[OBJ_MAX];
  Mtx     obj_scale[OBJ_MAX];

	/*WADE EDIT adding matrix for N64 Logo 

	Mtx		n64logo_trans;
	Mtx		n64logo_rotate;
	Mtx		n64logo_scale;
	
	Mtx		TestEnv_trans[10];
	Mtx		TestEnv_scale[10];
	Mtx		TestEnv_rotate[10];
	*/
//	Mtx		TestObj_trans[10];
//	Mtx		TestObj_scale[10];
//	Mtx		TestObj_rotate[10];
	
//	Mtx		TestObj_transB[5];
//	Mtx		TestObj_scaleB[5];
//	Mtx		TestObj_rotateB[5];
	
	Mtx 	Rotate_obj;
	/*Matrixes for player position and the position of various body parts.*/
	Mtx 	Player_trans;	
	Mtx 	Player_scale;
	Mtx 	Player_rotate;
	Mtx 	Player_rot_updatedR;
	Mtx 	Player_rot_updatedL;
	
	
	
/*
	Mtx		Head_trans;
	Mtx		Head_scale;
	Mtx 	Head_rotate;
	
	Mtx		Chest_trans;
	Mtx		Chest_scale;
	Mtx 	Chest_rotate;
	
	Mtx 	RightArm_trans[3];
	Mtx 	RightArm_scale[3];
	Mtx 	RightArm_rotate[3];
	
	Mtx 	LeftArm_trans[3];	
	Mtx 	LeftArm_scale[3];
	Mtx 	LeftArm_rotate[3];
	
	Mtx 	RightLeg_trans[3];
	Mtx 	RightLeg_scale[3];
	Mtx 	RightLeg_rotate[3];
	
	Mtx 	LeftLeg_trans[3];	
	Mtx 	LeftLeg_scale[3];
	Mtx 	LeftLeg_rotate[3];
*/
//	Mtx		ghost_trans;
//	Mtx		ghost_rotate;
//	Mtx		ghost_scale;
	
//	Mtx		map2_trans;
//	Mtx		map2_rotate;
//	Mtx		map2_scale;
  //PositionalLight checkPosLight;
  Vector3 posLightValues;
  Vector3 debugValues;

  Hilite newHilite[2];
  LookAt lookAt[2];
  //PositionalLight posLight[2]; 
  Light lights[2];
  
	

  /*The buffer for movie drawing */
  //unsigned short MovieBuf[8200];
} Dynamic;

typedef struct {
  Mtx     projection;
  Mtx     modeling;
  Mtx     viewing; 
	
} DebugDynamic;

/* The parameter of the tail for shooting  */
typedef struct{
    float pos_x;	/*The X-coordinate */
    float pos_y;	/*The Y-coordinate */
    float pos_z;	/*The Z-coordinate */
    float rot_x;	/*The rotational angle of the X-axis direction */
    float rot_y;	/*The rotational angle of the Y-axis direction */
    float rot_z;	/*The rotational angle of the Z-axis direction */
    float size_x;
    float size_y;
    float size_z;
    int tail_pattern;
    int user;
    float tail_dir;
    int status;
}ShotTail;

/*
typedef struct {
     float  col[3];         // Color (and intensity) 
     float  pos[3];         // Position (absolute coordinates)
     float  a1, a2;         // Attenuation rate 
     // Actual color = col/(a1* distance + a2) 
} PositionalLight;*/


/*
typedef struct{
	float col[3];
	float pos[3];
	float a1, a2;
} PositionalLight;
*/
/*
typedef struct PositionalLight testPosLight;
struct PositionalLight
{
	float col[3];
	float pos[3];
	float a1, a2;
};*/


/*-------------------------------- parameter---------------------------------*/
extern Dynamic gfx_dynamic[];
extern Gfx* glistp;
extern Gfx gfx_glist[GFX_GTASK_NUM][GFX_GLIST_LEN];
extern Gfx gfx_clear_glist[][GFX_CLEAR_GLIST_LEN];
extern u32 gfx_gtask_no;

/*-------------------------------test second display list---------------------
extern Dynamic gfx_debugDynamic[];
extern Gfx* glistpDebugp;
extern Gfx gfx_glistDebug[GFX_GTASK_NUM][GFX_GLIST_LEN]; //smaller size for debug
extern u32 gfx_debug_gtask_no;
*/
/*-------------------------------- graphic.c functions ---------------------------------*/
extern void gfxRCPInit(void);
extern void gfxClearCfb(void);
extern void menuGfxRCPInit(void);
extern void menuGfxClearCfb(void);

extern void PlayerObjMTX(Player* pla);
extern void RenderEnvObj(EnvObject* env);
extern void RenderProjectileObj(ProjectileObject* proj);
extern void PlayerRigObjectMTX(RigObject* rigObj, void (*rigFunc)(void));
extern void RenderEnemyObj(EnemyObject* enemy);

/*------------------------------- other extern define -----------------------*/
extern Gfx game_setup_rdpstate[];
extern Gfx game_setup_rspstate[];
extern Gfx menu_setup_rdpstate[];
extern Gfx menu_setup_rspstate[];

//extern void RenderPlayerObj(Player* pla);
//extern void RenderPlayerRig(RigObject* rigObj, void (*rigFunc));

extern void PlayerRigObjectMTX(RigObject* rigObj, void (*rigFunc)(void));


#endif /* _GRAPHIC_H_ */



