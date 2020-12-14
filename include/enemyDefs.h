#ifndef _ENEMYDEFS_H
#define _ENEMYDEFS_H

#include "common.h"

//NOTE: Enemies are loaded into the scene via level scripts (such as level01.c)

/*--------------------------------------------------------------------------*/
/*------------------------------Spikey Enemy--------------------------------*/
/*--------------------------------------------------------------------------*/

/*-----------------------------enemy_spikey.c-------------------------------*/
extern Vtx testenemyspiked_LARGE_VertList_0 [];
extern Vtx testenemyspiked_VertList_0 [];
extern  void testenemyspiked_LARGE_PolyList(u8 animFrame) ;
extern  void testenemyspiked_PolyList(u8 animFrame);

/*-----------------------------spikeySpawner.c-------------------------------*/
//NOTE: Large spikey spawner will spawn multiple small spikeys (up to 3). 
//Will continue spawning new spikeys until the spawner is dead.  
extern void Spikey_Init(u8 spawnID);
extern void GetActiveSpikey(EnemyTargets* enemyTargetList); //sets nearby activeSpikeys to the enemy target list


extern void Spikey_Spawner_Init();
extern void Spikey_Spawner_Update();
extern void Spikey_Update(); //update spikey enemies
extern void Spikeys_DL(); //Draw spikey enemies 
extern void Spikey_Collision(ProjectileObject* projectile);
//extern void Level01_Enemies(Dynamic* ddp);

/*--------------------------------------------------------------------------*/
/*END-------------------------From Spikey Enemy-----------------------------*/
/*--------------------------------------------------------------------------*/

#endif //_ENEMYDEFS_H