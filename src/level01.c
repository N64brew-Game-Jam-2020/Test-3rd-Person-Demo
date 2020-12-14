//#include "levelDefs.h"
#include "common.h"
#include "objectDefs.h"
#include "level01.h"
#include "collisionDefs.h"

Level lvl01;

EnvObject lvl01Ground;
EnvObject lvl01Wall;

EnvObject env01WallsMain;
EnvObject env01WallsEntrance;
EnvObject env01WallsExit01;
EnvObject env01WallsExit02;
EnvObject env01Ground;
EnvObject env01Ground2;
EnvObject env01River;
EnvObject env01Waterfall;

EnvObject env01PartialArch01;
EnvObject env01PartialArch02;
EnvObject env01PartialArch03;
EnvObject env01BrokenArch01;

EnvObject detailObject01;
EnvObject detailObject02;
EnvObject detailObject03;
EnvObject detailObject04;
EnvObject testTile;
EnvObject detailObject_Ceiling;


EnvObject env02CaveWires01;
EnvObject env02CaveRiver01;
EnvObject env02CaveGround01;
EnvObject env02CaveWalls01;

EnvObject geistTestObj;
EnvObject landingSite;
EnvObject landingSiteObjects;


//Env00-Env01 LoadZone is triggered when player is in env 00 or 01
EnvObject	env00_01_loadzone_Walls;
EnvObject	env00_01_loadzone_Ground;


//Env00
EnvObject playerShip;
EnvObject playerShipThrusters[4];

/*
EnemyObject enemySpikedSmall;
EnemyObject enemySpikedLarge;
*/
//there is one trigger box that uses the bright light
EnvLighting env01_bright_trig = 	{
	//min x,y,z  max x,y,z   u8 boolean
	{-378,-1144,-142,590,654,654 , 0}
};

//there are multiple trigger boxes that use the dark shade
EnvLighting env01_shade_trig[] = {	
	//min x,y,z  max x,y,z   u8 boolean
	{-580,-2216,-142,590,-1147,654 , 0},
	{-2089,-1616,-142,-384,654,654 , 0},
	{590,-921,-142,1505,654,654 , 0},
	{2018,-4073,-450,5118,165,652, 0},
};

//EnvLighting env01_shade_trig;
EnvLighting env02_dark_trig;

Lights2 env01_bright = gdSPDefLights2(
	100, 100, 60, // amb col 
	//side reflect light
	0, 135, 155, // col 1  
	0,   0,  90, // dir 1
	//ground reflect light
	75, 10, 50, // col 2   
	45,   0,  -90 // dir 2
);

Lights2 env01_shade = gdSPDefLights2(
	50, 60, 50, // amb col 
	//side reflect light
	0, 175, 200, // col 1  
	0,   0,  90, // dir 1
	//ground reflect light
	45, 20, 55, // col 2   
	45,   0,  -90 // dir 2
);

Lights2 env00_cave_shade = gdSPDefLights2(
	20, 45, 85, // amb col 
	//side reflect light
	0, 70, 110, // col 1  
	0,   0,  90, // dir 1
	//ground reflect light
	25, 45, 65, // col 2   
	45,   0,  -90 // dir 2
);


void Lvl01_Env01_Lighting_Check()
{ //for checking lighting trigger boxes
	
	u8 counter = 0;
	u8 boolCheck = triggerBoundBox(&playerAvatar.obj.pos, &env01_bright_trig.trigger);
	if(boolCheck == 1)
		playerAvatar.playerLighting = env01_bright;
		
	else
	{	
		for (counter = 0; counter < 3; counter++)
		{
			boolCheck = triggerBoundBox(&playerAvatar.obj.pos, &env01_shade_trig[0].trigger);
			
			if(boolCheck == 1)
			{
				playerAvatar.playerLighting = env01_shade;
				counter = 3;
			}				
		}	
	}
	
	boolCheck = triggerBoundBox(&playerAvatar.obj.pos, &env01_shade_trig[3].trigger);
			if(boolCheck == 1)
			{
				playerAvatar.playerLighting = env00_cave_shade;
				counter = 3;
			}
	
	
}










u8 loadMainCourtyard = 0;
u8 loadShip = 0;

TriggerGeometry lvl01_geometry_trig_env[3] = {	
	//min x,y,z  max x,y,z   u8 boolean
	{-768, -6642, -450,4794,-2300,654, 0}, //loading zone 
	{-2244,-4034,-450,1220,819,654, 0}, //courtyard
	{2018,-4073,-450,5118,165,652, 0}, //landing area
	
};

TriggerGeometry lvl01_collision_trig_env[3] = {	
	//min x,y,z  max x,y,z   u8 boolean
	{-2244, -4034, -142,2006,-867,427, 0}, //loading zone 
	{-2244,-866,-142,2006,552,427, 0}, //courtyard
	{2018,-4073,-450,5118,165,652, 0}, //landing area
	
};
void Lvl01_EnvLoadTriggers()
{	//When player is inside these trigger boxes, trigger certain geometry and collision to load 
	u8 counter = 0;
	u8 boolCheck;
		

		//lvl01_geometry_trig_env00.trigger.isActive = triggerBoundBox(&playerAvatar.obj.pos, &lvl01_geometry_trig_env00.trigger);
		//	lvl01_geometry_trig_env01.trigger.isActive = triggerBoundBox(&playerAvatar.obj.pos, &lvl01_geometry_trig_env01.trigger);
		
		//loadMainCourtyard = triggerBoundBox(&playerAvatar.obj.pos, &lvl01_geometry_trig_env00.trigger);
			//lvl01_geometry_trig_env00.trigger.isActive = boolCheck;
		//loadShip = triggerBoundBox(&playerAvatar.obj.pos, &lvl01_geometry_trig_env01.trigger);
			//lvl01_geometry_trig_env01.trigger.isActive = boolCheck;
		
		for (counter = 0; counter < 3; counter++)
		{			
			lvl01_geometry_trig_env[counter].trigger.isActive = triggerBoundBox(&playerAvatar.obj.pos, &lvl01_geometry_trig_env[counter].trigger);
		}	
		
		for (counter = 0; counter < 3; counter++)
		{			
			lvl01_collision_trig_env[counter].trigger.isActive = triggerBoundBox(&playerAvatar.obj.pos, &lvl01_collision_trig_env[counter].trigger);
		}	
	

	
}





//Landing site env:
InitLevel01_env00() 
{

}






//env01_ceiling_PolyList

void InitLevel01()
{

	//Lvl01_Env01_InitLighting();

	SetVector3(&detailObject_Ceiling.obj.pos, 0,0,0); 
	SetVector3(&detailObject_Ceiling.obj.rot, 0,0,0);
	SetVector3(&detailObject_Ceiling.obj.scl, 1,1,1);
	SetAnimator(&detailObject_Ceiling.animator, &env01_ceiling_PolyList, 0,0);	

	SetVector3(&env01WallsMain.obj.pos, 0,0,0); 
	SetVector3(&env01WallsMain.obj.rot, 0,0,0);
	SetVector3(&env01WallsMain.obj.scl, 1,1,1);
	SetAnimator(&env01WallsMain.animator, &env01_walls_main_PolyList, 0,0);	
	
	SetVector3(&env01Ground.obj.pos, 0,0,0);
	SetVector3(&env01Ground.obj.rot, 0,0,0);
	SetVector3(&env01Ground.obj.scl, 1,1,1);
	SetAnimator(&env01Ground.animator, &env01_ground_PolyList, 0,0);	
	
	SetVector3(&env01Ground2.obj.pos, 0,0,0);
	SetVector3(&env01Ground2.obj.rot, 0,0,0);
	SetVector3(&env01Ground2.obj.scl, 1,1,1);
	SetAnimator(&env01Ground2.animator, &env01_ground_exits_PolyList, 0,0);	
	
	SetVector3(&env01WallsEntrance.obj.pos, 0,0,0);
	SetVector3(&env01WallsEntrance.obj.rot, 0.000000, -0.000000, 0.000000);
	SetVector3(&env01WallsEntrance.obj.scl, 1,1,1);
	SetAnimator(&env01WallsEntrance.animator, &env01_segm_entry_PolyList, 0,0);
	SetVector3(&env01WallsExit02.obj.rot, 0.000000, -0.000000, 0.000000);
	SetVector3(&env01WallsExit02.obj.scl, 1,1,1);
	SetAnimator(&env01WallsExit02.animator, &env01_segm_exit01_PolyList, 0,0);
	
	
	SetVector3(&env01WallsExit01.obj.pos, 0,0,0);
	SetVector3(&env01WallsExit01.obj.rot, 0.000000, -0.000000, 0.000000);
	SetVector3(&env01WallsExit01.obj.scl, 1,1,1);
	SetAnimator(&env01WallsExit01.animator, &env01_segm_exits_PolyList, 0,0);
	
	SetVector3(&env01WallsExit02.obj.pos, 0,0,0);
	
	SetVector3(&env01PartialArch01.obj.pos, 0.0, 0.0, 8.433469);
	SetVector3(&env01PartialArch01.obj.rot, 0.000000, -0.000000, 0.000000);
	SetVector3(&env01PartialArch01.obj.scl, 1,1,1);
	SetAnimator(&env01PartialArch01.animator, &env01_partial_arches_PolyList, 0,0);
	
	SetVector3(&env01PartialArch02.obj.pos, 0.0, 0.0, 8.433469);
	SetVector3(&env01PartialArch02.obj.rot, 0.000000, -0.000000, 0.000000);
	SetVector3(&env01PartialArch02.obj.scl, 1,1,1);
	SetAnimator(&env01PartialArch02.animator, &env01_partial_arches001_PolyList, 0,0);
	
	SetVector3(&env01PartialArch03.obj.pos, 0.0, 0.0, 8.433469);
	SetVector3(&env01PartialArch03.obj.rot, 0.000000, -0.000000, 0.000000);
	SetVector3(&env01PartialArch03.obj.scl, 1,1,1);
	SetAnimator(&env01PartialArch03.animator, &env01_partial_arches002_PolyList, 0,0);

	SetVector3(&env01BrokenArch01.obj.pos, 0.0, 0.0, 8.433469);
	SetVector3(&env01BrokenArch01.obj.rot, 0.000000, -0.000000, 0.000000);
	SetVector3(&env01BrokenArch01.obj.scl, 1,1,1);
	SetAnimator(&env01BrokenArch01.animator, &env01_broken_arch_PolyList, 0,0);
	
	
	SetVector3(&detailObject01.obj.pos, -412.829685, -510.849714, 12.954864);
	SetVector3(&detailObject01.obj.rot, 0.000000, -0.000000, 0.000000);
	SetVector3(&detailObject01.obj.scl, 1,1,1);
	SetAnimator(&detailObject01.animator, &env01_old_tree_PolyList, 0,0);
	

		SetVector3(&detailObject02.obj.pos, 531.567621, -400.269842, 12.954862);
	SetVector3(&detailObject02.obj.rot, 0.000000, -0.000000, 0.0);
	SetVector3(&detailObject02.obj.scl, 1,1,1);
	SetAnimator(&detailObject02.animator, &env01_old_tree001_PolyList, 0,0);
	
	

	SetVector3(&detailObject03.obj.pos, -550.011587, -504.034901, 767.893076);
	SetVector3(&detailObject03.obj.rot, 0.000000, -0.000000, 0.0);
	SetVector3(&detailObject03.obj.scl, 1,1,1);
	SetAnimator(&detailObject03.animator, &env01_leaves_01_PolyList, 0,0);
	


	SetVector3(&detailObject04.obj.pos, 490.231752, -504.034901, 767.893076);
	SetVector3(&detailObject04.obj.rot, 0.000000, -0.000000, 0.0);
	SetVector3(&detailObject04.obj.scl, 1,1,1);
	SetAnimator(&detailObject04.animator, &env01_leaves_02_PolyList, 0,0);
	

	SetVector3(&env01River.obj.pos, -0.219087, -0.285139, -8.643668); 
	SetVector3(&env01River.obj.rot, 0,0,0);
	SetVector3(&env01River.obj.scl, 1,1,1);
	SetAnimator(&env01River.animator, &env01_river_PolyList, 0,0);
		
	SetVector3(&env01Waterfall.obj.pos, 0,0,0);
	SetVector3(&env01Waterfall.obj.rot, 0,0,0);
	SetVector3(&env01Waterfall.obj.scl, 1,1,1);
	SetAnimator(&env01Waterfall.animator, &env01_waterfall_PolyList, 0,0);
	
	
	//NOTE: Initiate other parts of scene
	Level01_InitEnemies();
	InitLvl01_Env00();
	InitLvl01_00_01_loadzone(); //init loading zone between env00 and env01
	InitLevel01_env00();

	
	/*NOTE: Hide until region culling is functional------
		InitLvl01_Env02();
		
		SetVector3(&geistTestObj.obj.pos, 0,2990,0);
		SetVector3(&geistTestObj.obj.rot, 0,0,0);
		SetVector3(&geistTestObj.obj.scl, 1,1,1);
		SetAnimator(&geistTestObj.animator, &LadingZone_PolyList, 0,0);*/
	/*END NOTE-------------------------------------------*/
	
};

void InitLvl01_Env02()
{
	SetVector3(&env02CaveWires01.obj.pos, 2025.294113, 489.500380, 730.048990); 
	SetVector3(&env02CaveWires01.obj.rot, 0,0,0);
	SetVector3(&env02CaveWires01.obj.scl, 1,1,1);
	SetAnimator(&env02CaveWires01.animator, &env02_segm_ceiling_wiring_PolyList, 0,0);	
	
	SetVector3(&env02CaveRiver01.obj.pos, 2990.583801, 1516.483688, -8.643579); 
	SetVector3(&env02CaveRiver01.obj.rot, 0,0,0);
	SetVector3(&env02CaveRiver01.obj.scl, 1,1,1);
	SetAnimator(&env02CaveRiver01.animator, &env02_segm_water01_PolyList, 0,0);	
	
	SetVector3(&env02CaveGround01.obj.pos, 2990.583801, 1516.483688, 0.041294); 
	SetVector3(&env02CaveGround01.obj.rot, 0,0,0);
	SetVector3(&env02CaveGround01.obj.scl, 1,1,1);
	SetAnimator(&env02CaveGround01.animator, &env02_segm_ground01_PolyList, 0,0);	
	
	SetVector3(&env02CaveWalls01.obj.pos, 2990.377235, 1516.313553, 0.361502); 
	SetVector3(&env02CaveWalls01.obj.rot, 0,0,0);
	SetVector3(&env02CaveWalls01.obj.scl, 1,1,1);
	SetAnimator(&env02CaveWalls01.animator, &env02_segm_walls01_PolyList, 0,0);	
	
	InitLvl01_Env02();
}

void InitLvl01_Env00()
{
	SetVector3(&playerShip.obj.pos, 3380, -1800, 80); 
	SetVector3(&playerShip.obj.rot, 0,0,180);
	SetVector3(&playerShip.obj.scl, 2,2,2);
	SetAnimator(&playerShip.animator, &player_ship_PolyList, 0,0);	
	
	SetVector3(&playerShipThrusters[0].obj.pos, playerShip.obj.pos.x + 194, playerShip.obj.pos.y + -116, playerShip.obj.pos.z + 164); 
	SetVector3(&playerShipThrusters[0].obj.rot, 180,0,0);
	SetVector3(&playerShipThrusters[0].obj.scl, playerShip.obj.scl.x,playerShip.obj.scl.y,playerShip.obj.scl.z);
	SetAnimator(&playerShipThrusters[0].animator, &player_ship_drive_PolyList, 0,0);	
	
	SetVector3(&playerShipThrusters[1].obj.pos, playerShip.obj.pos.x + -194, playerShip.obj.pos.y + -116, playerShip.obj.pos.z + 164); 
	SetVector3(&playerShipThrusters[1].obj.rot, 180,0,180);
	SetVector3(&playerShipThrusters[1].obj.scl,  playerShip.obj.scl.x,playerShip.obj.scl.y,playerShip.obj.scl.z);
	SetAnimator(&playerShipThrusters[1].animator, &player_ship_drive_PolyList, 0,0);	
	
	SetVector3(&playerShipThrusters[2].obj.pos, playerShip.obj.pos.x + 194, playerShip.obj.pos.y + 116, playerShip.obj.pos.z + 164); 
	SetVector3(&playerShipThrusters[2].obj.rot, 180,0,0);
	SetVector3(&playerShipThrusters[2].obj.scl,  playerShip.obj.scl.x,playerShip.obj.scl.y,playerShip.obj.scl.z);
	SetAnimator(&playerShipThrusters[2].animator, &player_ship_drive_PolyList, 0,0);	
	
	SetVector3(&playerShipThrusters[3].obj.pos, playerShip.obj.pos.x + -194, playerShip.obj.pos.y + 116, playerShip.obj.pos.z + 164); 
	SetVector3(&playerShipThrusters[3].obj.rot, 180,0,180);
	SetVector3(&playerShipThrusters[3].obj.scl,  playerShip.obj.scl.x,playerShip.obj.scl.y,playerShip.obj.scl.z);
	SetAnimator(&playerShipThrusters[3].animator, &player_ship_drive_PolyList, 0,0);	
	
	SetVector3(&landingSite.obj.pos, 0,0,0); 
	SetVector3(&landingSite.obj.rot, 0,0,0);
	SetVector3(&landingSite.obj.scl, 1,1,1);
	SetAnimator(&landingSite.animator, &Load_Landing_Site_Animator, 0,0);	
}

void InitLvl01_00_01_loadzone()
{
	SetVector3(&env00_01_loadzone_Walls.obj.pos, 0,0,0); 
	SetVector3(&env00_01_loadzone_Walls.obj.rot, 0,0,0);
	SetVector3(&env00_01_loadzone_Walls.obj.scl, 1,1,1);
	SetAnimator(&env00_01_loadzone_Walls.animator, &env01_segm_loadzone00_walls_PolyList, 0,0);	
	
	SetVector3(&env00_01_loadzone_Ground.obj.pos, 0,0,0); 
	SetVector3(&env00_01_loadzone_Ground.obj.rot, 0,0,0);
	SetVector3(&env00_01_loadzone_Ground.obj.scl, 1,1,1);
	SetAnimator(&env00_01_loadzone_Ground.animator, &env01_segm_loadzone00_ground_PolyList, 0,0);	
}

//EnvObject	env00_01_loadzone_Walls;
//EnvObject	env00_01_loadzone_Ground;


	Gfx	light_shine01_mode[]  ={
	gsDPPipeSync(),
	gsSPTexture( 0xffff, 0xffff, 0, 0, G_OFF),
	gsDPSetCombineLERP(
		0, 0, 0, PRIMITIVE,
		SHADE, 0, PRIMITIVE, 0,
		0, 0, 0, PRIMITIVE,
		SHADE, 0, PRIMITIVE, 0
	),
	gsSPEndDisplayList(),
};

void Lvl01_Env02(Dynamic* ddp)
{
	TEXTURE_FOG_LIGHT(glistp, 35, 30, 50, 255,700,992); //call only once for all similar env objects

	RenderEnvObj(&env02CaveGround01);
	RenderEnvObj(&env02CaveWalls01);
	
	TEXTURE_FOG_LIGHT(glistp, 75, 115, 125, 175,900,500); 
		RenderEnvObj(&env02CaveRiver01);

	//RenderEnvObj(&env02CaveWires01);
}


void Lvl01_00_01_loadzone()
{
		TEXTURE_FOG_LIGHT(glistp, 35, 30, 50, 255,700,992); //call only once for all similar env objects

		RenderEnvObj(&env00_01_loadzone_Walls);
		RenderEnvObj(&env00_01_loadzone_Ground);		

}
//env00_01_loadzone_Walls

void Lvl01_Env00() //ship spawn environment
{
	

		TEXTURE_FOG_LIGHT(glistp, 35, 30, 50, 255,700,992); //call only once for all similar env objects

		RenderEnvObj(&playerShip);
		RenderEnvObj(&playerShipThrusters[0]);
		RenderEnvObj(&playerShipThrusters[1]);
		RenderEnvObj(&playerShipThrusters[2]);
		RenderEnvObj(&playerShipThrusters[3]);			
		RenderEnvObj(&landingSite);	
		
	
	//RenderEnvObj(&env02CaveWalls01);
	
	//TEXTURE_FOG_LIGHT(glistp, 75, 115, 125, 175,900,500); 
		//RenderEnvObj(&env02CaveRiver01);

	//RenderEnvObj(&env02CaveWires01);
}


void Level01(Dynamic* ddp)
{
	
	
			//TEXTURE_FOG(glistp, 240, 240, 175, 255,920,992);
	//gDPSetEnvColor(glistp++, 255,255,255,0);	
	//gDPSetPrimColor(glistp++, 125, 150, 200, 220, 235, 225);  //water primative color is blended with fog in combiner


	//NOTE: Set up load triggers for lighting and collision and 
	//set up player animation to update with delta time rather than with frame
	

	Lvl01_Env01_Lighting_Check();
	
	
	

	//if(lvl01_geometry_trig_env[0].trigger.isActive == 1 || lvl01_geometry_trig_env[2].trigger.isActive == 1)
	if(lvl01_geometry_trig_env[0].trigger.isActive == 1 || lvl01_geometry_trig_env[2].trigger.isActive == 1)
	//if(loadShip == 1)
	{
		//Lvl01_Env01_Lighting_Check(); //will update lighting on the player character;
		//TEXTURE_FOG_LIGHT(glistp, 240, 240, 175, 255,920,992); //call only once for all similar env objects
		
		Lvl01_Env00();
	}
	
	if(lvl01_geometry_trig_env[1].trigger.isActive == 1)
	//if(loadMainCourtyard == 1)
	{
		//First check for lighting collision triggers. 	
		Lvl01_Env01_Lighting_Check(); //will update lighting on the player character;
		
		/*TO DO NOTE: Hide until region culling is functional------
			RenderEnvObj(&geistTestObj);*/
		/*END NOTE-------------------------------------------*/
		
		
		TEXTURE_FOG_LIGHT(glistp, 240, 240, 175, 255,920,992); //call only once for all similar env objects
		//TEXTURE_FOG_LIGHT(glistp, 200, 200, 140, 50,700,980); //call only once for all similar env objects

		RenderEnvObj(&env01Ground);

		//env01_ground_exits_PolyList  env01Ground2
		RenderEnvObj(&env01WallsMain);	
		//TEXTURE_FOG_LIGHT(glistp, 240, 240, 175, 255,920,992); //call only once for all similar env objects

		
		
		//RenderEnvObj(&env01PartialArch01);	
		//RenderEnvObj(&env01PartialArch02);	
		//RenderEnvObj(&env01PartialArch03);
		RenderEnvObj(&env01BrokenArch01);	
		
		
		RenderEnvObj(&detailObject01);
		RenderEnvObj(&detailObject02);
		RenderEnvObj(&detailObject03);
		RenderEnvObj(&detailObject04);
			//	RenderEnvObj(&testTile); //For testing animated s,t values



			
		TEXTURE_FOG_LIGHT(glistp, 45, 40, 30, 175,860,992); //call only once for all similar env objects
		RenderEnvObj(&env01Ground2);
		RenderEnvObj(&env01WallsExit01);	
		//RenderEnvObj(&env01WallsEntrance);
		//RenderEnvObj(&env01WallsExit02);
		RenderEnvObj(&detailObject_Ceiling);	
		
		
		//gSPDisplayList(glistp++,light_shine01_mode);
			//	RenderEnvObj(&env01Waterfall);
		//RenderEnvObj(&env01River); //call river first since it is an interpentrating surface with the ground plane.
		
	//env01_segm_entry
		
		//RenderEnvObj(&env01BrokenArch01);
		//RenderEnvObj(&env01River);
		//RenderEnvObj(&env01Waterfall);
		//lvl01_test_tile_PolyList(0);
		
		//testMesh_CollisionCheck(&playerAvatar.sphereCollider, ddp);
	}
	
	if(lvl01_geometry_trig_env[0].trigger.isActive == 1 || lvl01_geometry_trig_env[1].trigger.isActive == 1 || lvl01_geometry_trig_env[1].trigger.isActive == 2)
	{ //if player is in env01 or env00, then the transition zone area should be visible at all times
		Lvl01_00_01_loadzone();	
	}
	
	Lvl01_EnvLoadTriggers();


}

void Level01_Objects(Dynamic* ddp)
{		

		if(lvl01_geometry_trig_env[1].trigger.isActive == 1)
		//if(loadMainCourtyard == 1)
		{

			TEXTURE_FOG_LIGHT(glistp, 240, 240, 175, 175,700,400); 
			//TEXTURE_FOG_LIGHT(glistp, 240, 240, 175, 175,600,992); //call only once for all similar env objects
			//TEXTURE_FOG_LIGHT(glistp, 200, 225, 225, 255,800,700); 
			gDPSetPrimColor(glistp++, 125, 150, 200, 220, 235, 225);  //water primative color is blended with fog in combiner
			RenderEnvObj(&env01Waterfall);
			
			TEXTURE_FOG_LIGHT(glistp, 55, 85, 95, 75,700,500); //NOTE: this setting removes detail closer to the camera 
			//TEXTURE_FOG_LIGHT(glistp, 125, 175, 150, 175,875,700); 
			gDPSetPrimColor(glistp++, 125, 150, 175, 245, 255, 210);  //water primative color is blended with fog in combiner
			RenderEnvObj(&env01River); 
		
		}
}


//NOTE Possible process for adding enemies: 
//Create an array of enemies for the level here in level01.c
//this will be the master array

EnemyObject lvl01EnemyObjects[10];

void Level01_InitEnemies()
{
	Spikey_Spawner_Init();
}

void Level01_Enemies_DL()
{
	if(lvl01_geometry_trig_env[1].trigger.isActive == 1)
	//if(loadMainCourtyard == 1)
	{
		Spikey_DL(); //NOTE: draw even when paused	
	}
}

void Level01_Enemies_Update()
{
	//NOTE: update only when game is not paused

	Spikey_Spawner_Update(); //render spikey spawner and spawn children if spawner is alive
	Spikey_Update(); //render any active children of spikey_spawner

	//TEXTURE_FOG_LIGHT(glistp, 45, 45, 10, 255,700,992); //call only once for all similar env objects
	//RenderEnvObj(&enemySpikedSmall); 
	//RenderEnvObj(&enemySpikedLarge); 
}


