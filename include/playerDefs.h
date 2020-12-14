#ifndef _PLAYERDEFS_H
#define _PLAYERDEFS_H

#include "common.h"
//#include "objectDefs.h"

/*--------------------------------------------------------------------------*/
/*------------------------------player.c Functions--------------------------*/
/*--------------------------------------------------------------------------*/

//player.c is the main script for controlling all functions tied to the player character
extern Player playerAvatar; //accessible to other scripts
extern EnemyTargets enemyTargets; //accessible to other scripts

extern u8 animFrame; 

extern void initPlayer();
extern void updatePlayer(Dynamic* dp);
extern void DrawPlayerModel();
extern void playerAnimationController(u8 anim);
extern void PlayerCollision(Dynamic* dp);
//extern void PlayerGravity(Dynamic* dp);
extern void PlayerGroundCollision(Dynamic* dp);



/*END---------------------------player.c Functions--------------------------*/


/*--------------------------------------------------------------------------*/
/*-------------------------playerController.c Functions---------------------*/
/*--------------------------------------------------------------------------*/
//playerController.c controls player input functions and user settings/preferences


/*END----------------------playerController.c Functions---------------------*/


/*--------------------------------------------------------------------------*/
/*----------------------------projectiles.c Functions-----------------------*/
/*--------------------------------------------------------------------------*/

extern void player_missile_PolyList(u8 animFrame); 
extern void player_shot_PolyList(u8 animFrame); 

//extern  void spawn_player_shot(ProjectileObject* projectile);
extern void spawn_player_shot(ProjectileObject* projectile, GameObject* targetObject);
extern  void draw_player_shot(ProjectileObject* projectile);
extern  void update_player_shot(ProjectileObject* projectile);
//extern void draw_player_shot(ProjectileObject* projectile);

/*END-------------------------projectiles.c Functions-----------------------*/


/*--------------------------------------------------------------------------*/
/*---------------------------playerModel.c Functions------------------------*/
/*--------------------------------------------------------------------------*/

//playerModel.c controls player model, textures, etc 
extern void defaultRig();
extern void nextPlayerAnimFrame();
extern void nextPlayerLightingState(); //update lighting on playerModel.c passed to playerAvatar via scene triggers in level scripts

extern void player_head_animation();
extern void player_head_PolyList();
extern void player_chest_animation();
extern void player_chest_PolyList();

extern void player_right_arm_animation();
extern void player_right_arm_PolyList();
extern void player_right_arm_lower_animation();
extern void player_right_arm_lower_PolyList();

extern void player_left_arm_animation();
extern void player_left_arm_PolyList();
extern void player_left_arm_lower_animation();
extern void player_left_arm_lower_PolyList();

extern void player_right_leg_animation();
extern void player_right_leg_PolyList();
extern void player_right_leg_lower_animation();
extern void player_right_leg_lower_PolyList();

extern void player_left_leg_animation();
extern void player_left_leg_PolyList();
extern void player_left_leg_lower_animation();
extern void player_left_leg_lower_PolyList();
/*END------------------------playerModel.c Functions------------------------*/



/*--------------------------------------------------------------------------*/
/*----------------------------- playerTextures.c ---------------------------*/
/*--------------------------------------------------------------------------*/

extern unsigned char player_glow[];
extern unsigned short player_glow_tlut[];

extern unsigned char player_dark_joints[];
extern unsigned short player_dark_joints_tlut[];

extern unsigned char player_torso[];
extern unsigned short player_torso_tlut[];

extern unsigned char player_chest_plate[];
extern unsigned short player_chest_plate_tlut[];

extern unsigned char playerHead_front[];
extern unsigned short playerHead_front_tlut[];

extern unsigned char player_limb2[];
extern unsigned short player_limb2_tlut[];

extern unsigned char player_limb1[];
extern unsigned short player_limb1_tlut[];

extern unsigned char playerHead_back[];
extern unsigned short playerHead_back_tlut[];

extern unsigned char playerHead[];
extern unsigned short playerHead_tlut[];

extern unsigned char playerHead_glow[];
extern unsigned short playerHead_glow_tlut[];

extern unsigned char PlayerTextures_metal[];
extern unsigned short PlayerTextures_metal_tlut[];

extern unsigned char PlayerTextures_glow[];
extern unsigned short PlayerTextures_glow_tlut[];

extern unsigned char PlayerTextures_face[];
extern unsigned short PlayerTextures_face_tlut[];

extern unsigned char PlayerTextures_chest_front[];
extern unsigned short PlayerTextures_chest_front_tlut[];

extern unsigned char PlayerTextures_chest_accent[];
extern unsigned short PlayerTextures_chest_accent_tlut[];

extern unsigned char PlayerTextures_chest[];
extern unsigned short PlayerTextures_chest_tlut[];

/*END-------------------------- playerTextures.c ---------------------------*/


#endif