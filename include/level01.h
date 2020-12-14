#ifndef _LEVEL01_H
#define _LEVEL01_H

#include "common.h"
#include "levelDefs.h"
#include "playerShipDefs.h"



/*--------------------------------------------------------------------------*/
/*------------------------------From level01.c------------------------------*/
/*--------------------------------------------------------------------------*/


extern Level lvl01;
extern void InitLevel01();
extern void Level01(Dynamic* ddp);
extern void Level01_Objects(Dynamic* ddp);
//extern void Level01_Enemies();
extern void Level01_InitEnemies();
void Level01_Enemies_DL();
void Level01_Enemies_Update();

extern void InitLvl01_Env02();
extern void Lvl01_Env02(Dynamic* ddp);

//Env00
extern void InitLvl01_Env00();
extern void Lvl01_Env00();

//Env00-Env01 LoadZone
extern void Lvl01_00_01_loadzone();
void InitLvl01_00_01_loadzone();

extern CollisionPoint collisionPoints;
extern CollisionPoint groundCollisionPoints;

extern TriggerGeometry lvl01_collision_trig_env[3];
extern TriggerGeometry lvl01_geometry_trig_env[3];


/*--------------------------------------------------------------------------*/
/*------------------------From env00_environment.c------------------------*/
/*--------------------------------------------------------------------------*/

extern void Load_Landing_Site_Animator(u8 animFrame); //controller to load all landing site assets

extern  void Landing_Ground001_PolyList(u8 animFrame) ;
extern	void Landing_Pad001_PolyList(u8 animFrame) 	;
extern	void LadingZone_obelisks001001_PolyList(u8 animFrame) 	;
extern	void Landing_2001_PolyList(u8 animFrame) 	;
extern	void Landing001_PolyList(u8 animFrame) 	;
extern	void Landing_Staris001_PolyList(u8 animFrame) 	;
extern  void LadingZone_obeliskslit_PolyList(u8 animFrame) ;





/*--------------------------------------------------------------------------*/
/*------------------------From env01_environment.c------------------------*/
/*--------------------------------------------------------------------------*/

 extern void env01_segm_exit02_PolyList(u8 animFrame) ;
 extern void env01_segm_exit01_PolyList(u8 animFrame) ;
 extern void env01_segm_exits_PolyList(u8 animFrame) ;
 extern void env01_walls_main_PolyList(u8 animFrame);
 extern void env01_partial_arches002_PolyList(u8 animFrame) ;
 extern void env01_partial_arches001_PolyList(u8 animFrame) ;
 extern void env01_broken_arch_PolyList(u8 animFrame) ;
 extern void env01_waterfall_PolyList(u8 animFrame) ;
  extern void env01_partial_arches_PolyList(u8 animFrame); 
 extern void env01_river_PolyList(u8 animFrame);
 extern void env01_ground_PolyList(u8 animFrame);
extern void env01_segm_entry_PolyList(u8 animFrame);  
extern  void env01_old_tree_PolyList(u8 animFrame) ;
extern  void env01_old_tree001_PolyList(u8 animFrame) ;
extern void env01_leaves_01_PolyList(u8 animFrame) ;
extern void env01_leaves_02_PolyList(u8 animFrame) ;
extern void env01_ground_exits_PolyList(u8 animFrame) ;
extern void env01_ceiling_PolyList(u8 animFrame) ;
extern void lvl01_test_tile_PolyList(u8 animFrame) ;

extern void env01_segm_loadzone00_walls_PolyList(u8 animFrame); 
extern void env01_segm_loadzone00_ground_PolyList(u8 animFrame);

extern Vector3 getPosLightValues();

/*---------------Test Geist Model------------

extern void LadingZone_platform_PolyList(u8 animFrame) ;
extern	void LandingZone_ground_PolyList(u8 animFrame)	;
extern	void LandingZone_stairs_PolyList(u8 animFrame)	;
extern	void LadingZone_PolyList(u8 animFrame)	;
*/


/*--------------------------------------------------------------------------*/
/*------------------------From env01_collision.c------------------------*/
/*--------------------------------------------------------------------------*/
extern MeshCollider testMesh[];
extern MeshColliderTri testMeshTri[];
extern u8 testMesh_CollisionCheck(Sphere* sphereCollider, Dynamic* ddp);
extern u8 groundMesh_CollisionCheck(Sphere* sphereCollider);
extern u8 getGroundCheck(Sphere* sphereCollider);

/*------------------------From env02_environment.c------------------------*/
extern void env02_segm_ceiling_wiring_PolyList(u8 animFrame) ;
 extern void env02_segm_water01_PolyList(u8 animFrame); 
  extern void env02_segm_ground01_PolyList(u8 animFrame) ;
   extern void env02_segm_walls01_PolyList(u8 animFrame) ;
   
   

   /*------------------------From env02_environment.c------------------------*/
   

   

   
   
   
   
/*--------------------------------------------------------------------------*/
/*----------------------------- Level 01 Textures ---------------------------*/
/*--------------------------------------------------------------------------*/

/*----------------------------- env01_textures.c ---------------------------*/


extern	unsigned char Stairs2[]	;
extern	unsigned short Stairs2_tlut[]	;
extern	unsigned char RockToBlack[]	;
extern	unsigned short RockToBlack_tlut[]	;
extern	unsigned char Obelisk2[]	;
extern	unsigned short Obelisk2_tlut[]	;
extern	unsigned char LightRays[]	;
extern	unsigned short LightRays_tlut[]	;
extern	unsigned char Dirt1[]	;
extern	unsigned short Dirt1_tlut[] 	;
extern	unsigned char AltarPlatform[]	;
extern	unsigned short AltarPlatform_tlut[]	;













/*----------------------------- env01_textures.c ---------------------------*/

extern unsigned char lvl01_tree_trunk[]; 
extern unsigned short lvl01_tree_trunk_tlut[]; 

extern unsigned char lvl01_ground[]; 
extern unsigned short lvl01_ground_tlut[];

extern unsigned char lvl01_ground_riverbed[];
extern unsigned short lvl01_ground_riverbed_tlut[];

extern unsigned char lvl01_pillar[];
extern unsigned short lvl01_pillar_tlut[];

extern unsigned char lvl01_pillar_broken[];
extern unsigned short lvl01_pillar_broken_tlut[];

extern unsigned char lvl01_pillar_detail1[];
extern unsigned short lvl01_pillar_detail1_tlut[];

extern unsigned char lvl01_pillar_detail2[];
extern unsigned short lvl01_pillar_detail2_tlut[];

extern unsigned char lvl01_wall[];
extern unsigned short lvl01_wall_tlut[];

extern unsigned char lvl01_wall_base[];
extern unsigned short lvl01_wall_base_tlut[];

extern unsigned char lvl01_wall_basev2[];
extern unsigned short lvl01_wall_basev2_tlut[];

extern unsigned char lvl01_wallv2[];
extern unsigned short lvl01_wallv2_tlut[];

extern unsigned char lvl01_wall_top[];
extern unsigned short lvl01_wall_top_tlut[];

extern unsigned char lvl01_water[];
extern unsigned short lvl01_water_tlut[];

extern unsigned char lvl01_waterfall[];
extern unsigned short lvl01_waterfall_tlut[];

extern unsigned char lvl01_tree_leaves[];
extern unsigned short lvl01_tree_leaves_tlut[];


extern unsigned char water_grey1[];
extern unsigned short water_grey1_tlut[];

extern unsigned char water_grey2[];
extern unsigned short water_grey2_tlut[];

extern unsigned char water_grey3[];
extern unsigned short water_grey3_tlut[];

extern unsigned char water_grey4[];
extern unsigned short water_grey4_tlut[];

extern unsigned char water_grey5[];
extern unsigned short water_grey5_tlut[];

extern unsigned char water_grey6[];
extern unsigned short water_grey6_tlut[];

extern unsigned char water_grey7[];
extern unsigned short water_grey7_tlut[];

extern unsigned char water_grey8[];
extern unsigned short water_grey8_tlut[];

extern unsigned char water_grey9[];
extern unsigned short water_grey9_tlut[];

extern unsigned char water_grey10[];
extern unsigned short water_grey10_tlut[];

extern unsigned char water_grey11[];
extern unsigned short water_grey11_tlut[];

extern unsigned char water_grey12[];
extern unsigned short water_grey12_tlut[];

extern	unsigned char RockDirtEdge[]	;
extern	unsigned short RockDirtEdge_tlut[]	;


/*----------------------------- env02_textures.c ---------------------------*/

extern	unsigned char env02_cave_ground[]	;
extern	unsigned short env02_cave_ground_tlut[]	;
extern	unsigned char env02_cave_ground_riverbed[]	;
extern	unsigned short env02_cave_ground_riverbed_tlut[]	;
extern	unsigned char env02_cave_river_dark[]	;
extern	unsigned short env02_cave_river_dark_tlut[]	;
extern	unsigned char env02_cave_wall[]	;
extern	unsigned short env02_cave_wall_tlut[] 	;
extern	unsigned char env02_cave_wall_base[]	;
extern	unsigned short env02_cave_wall_base_tlut[]	;


/*END-------------------------- env01_textures.c ---------------------------*/
#endif