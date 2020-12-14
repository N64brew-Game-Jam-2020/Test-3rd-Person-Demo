

#include <nusys.h>
#include "common.h"
#include "objectDefs.h"
#include "graphic.h"
#include "para.h"

Gfx          gfx_glist[GFX_GTASK_NUM][GFX_GLIST_LEN];
Gfx          gfx_clear_glist[2][GFX_CLEAR_GLIST_LEN];
Dynamic      gfx_dynamic[GFX_GTASK_NUM];
Gfx*         glistp;
u32          gfx_gtask_no = 0;

/*
Gfx          gfx_glistDebug[GFX_GTASK_NUM][GFX_GLIST_LEN];
Dynamic      gfx_debugDynamic[GFX_GTASK_NUM];
Gfx*         glistpDebugp;
u32          gfx_debug_gtask_no = 0;
*/
extern void PlayerObjMTX(Player* pla);

/*--------------------------------------------------------------------------*/
/*--------------LOW RES Mode RCP Settings and Clear Frame Buffer------------*/
/*--------------------------------------------------------------------------*/  
void
gfxRCPInit(void)
{
    /* Setting the RSP segment register  */
    gSPSegment(glistp++, 0, 0x0); /* For the CPU virtual address  */

    /* Setting RSP  */
    gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(game_setup_rspstate));

    /* Setting RDP  */
    gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(game_setup_rdpstate));	
}
  
void
gfxClearCfb(void)
{
    /* Clear the Z-buffer  */
    gDPSetDepthImage(glistp++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b,SCREEN_WD,
		     OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPSetFillColor(glistp++,(GPACK_ZDZ(G_MAXFBZ,0) << 16 |
			      GPACK_ZDZ(G_MAXFBZ,0)));
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD-1, SCREEN_HT-1);
    gDPPipeSync(glistp++);
  
    /* Clear the frame buffer  */
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD,
		     osVirtualToPhysical(nuGfxCfb_ptr));
	/*BLACK FRAME BUFFER*/
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(0, 0, 0, 1) << 16 | 
			       GPACK_RGBA5551(0, 0, 0, 1)));
				  
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD-1, SCREEN_HT-1);
	
    gDPPipeSync(glistp++);
	//gDPPipeSync(glistpDebugp++); 
}

//that is still cropped for now
inline void gfxClearCfb_C(uint32_t red, uint32_t green, uint32_t blue)
{
	gDPSetScissor(glistp++,G_SC_NON_INTERLACE, 0,0, SCREEN_WD,SCREEN_HT);

	gDPSetDepthImage(glistp++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_FILL);

    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b,SCREEN_WD, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPSetFillColor(glistp++,(GPACK_ZDZ(G_MAXFBZ,0) << 16 | GPACK_ZDZ(G_MAXFBZ,0)));

    gDPFillRectangle(glistp++, 5, 10, SCREEN_WD-1-5, SCREEN_HT-1-10);//cropped
    gDPPipeSync(glistp++);

    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, osVirtualToPhysical(nuGfxCfb_ptr));
	
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(red, green, blue, 1) << 16 | GPACK_RGBA5551(red, green, blue, 1))); // blue
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD-1, SCREEN_HT-1);
	
	//draw bacl frame
	gDPSetFillColor(glistp++, (GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1))); // black
	gDPFillRectangle(glistp++, 0, 0, SCREEN_WD-1, 15);//top
	gDPFillRectangle(glistp++, 0, SCREEN_HT-16, SCREEN_WD-1, SCREEN_HT-1);//bottom
	gDPFillRectangle(glistp++, 0, 0, 9, SCREEN_HT-1);//left
	gDPFillRectangle(glistp++, SCREEN_WD-10, 0, SCREEN_WD-1, SCREEN_HT-1);//right
	
	
	gDPSetScissor(glistp++,G_SC_NON_INTERLACE, 10,16, SCREEN_WD-10,SCREEN_HT-16);
	
    gDPPipeSync(glistp++);
}

/*END-----------LOW RES Mode RCP Settings and Clear Frame Buffer------------*/



/*--------------------------------------------------------------------------*/
/*-------------HIGH RES Mode RCP Settings and Clear Frame Buffer------------*/
/*--------------------------------------------------------------------------*/  
void menuGfxRCPInit(void)
{
    /* Setting the RSP segment register  */
    gSPSegment(glistp++, 0, 0x0); /* For the CPU virtual address  */

    /* Setting RSP  */
    gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(menu_setup_rspstate));

    /* Setting RDP  */
    gSPDisplayList(glistp++, OS_K0_TO_PHYSICAL(menu_setup_rdpstate));	
}

void menuGfxClearCfb(void)
{
    // Clear the Z-buffer
    gDPSetDepthImage(glistp++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b,MENU_SCREEN_WD,
		     OS_K0_TO_PHYSICAL(nuGfxZBuffer));
    gDPSetFillColor(glistp++,(GPACK_ZDZ(G_MAXFBZ,0) << 16 |
			      GPACK_ZDZ(G_MAXFBZ,0)));
    gDPFillRectangle(glistp++, 0, 0, MENU_SCREEN_WD-1, MENU_SCREEN_HT-1);
    gDPPipeSync(glistp++);
  
    // Clear the frame buffer
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, MENU_SCREEN_WD,
		     osVirtualToPhysical(nuGfxCfb_ptr));
	
	//Black frame buffer

    gDPSetFillColor(glistp++, (GPACK_RGBA5551(0, 0, 0, 1) << 16 | 
			       GPACK_RGBA5551(0, 0, 0, 1)));

    gDPFillRectangle(glistp++, 0, 0, MENU_SCREEN_WD-1, MENU_SCREEN_HT-1);
	
    gDPPipeSync(glistp++);
	//gDPPipeSync(glistpDebugp++); 
}
/*END----------HIGH Res Mode RCP Settings and Clear Frame Buffer------------*/



/*--------------------------------------------------------------------------*/
/*-------------- Render environments and other static objects  -------------*/
/*--------------------------------------------------------------------------*/  

void RenderEnvObj(EnvObject* env)
{ 
		gDPPipeSync(glistp++);
		gSPClearGeometryMode(glistp++,0xFFFFFFFF);
		gSPSetGeometryMode(glistp++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | 
			   G_FOG | G_LIGHTING | G_CULL_BACK);			 
			   

			   
		guTranslate(&env->obj.matrix[0], env->obj.pos.x, env->obj.pos.y, env->obj.pos.z);
		guRotateRPY(&env->obj.matrix[1], env->obj.rot.x, env->obj.rot.y, env->obj.rot.z);

		
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&env->obj.matrix[0]),
			  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&env->obj.matrix[1]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
			  
			  
		if(env->obj.scl.x || env->obj.scl.y || env->obj.scl.z != 1)	  
		{
			guScale(&env->obj.matrix[2], env->obj.scl.x, env->obj.scl.y, env->obj.scl.z);	  
				  
			gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&env->obj.matrix[2]),
				  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);	
		}
		//TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,900,995);		
		//TEXTURE_FOG_LIGHT(glistp, 150, 150, 100,255,900,992); //moved to level01.c
			  
		env->animator.animate(env->animator.animFrame);
		
		gDPPipeSync(glistp++);
}

void RenderEnemyObj(EnemyObject* enemy)
{ 
		gDPPipeSync(glistp++);
		gSPClearGeometryMode(glistp++,0xFFFFFFFF);
		gSPSetGeometryMode(glistp++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | 
			   G_FOG | G_LIGHTING | G_CULL_BACK);			 
			   

			   
		guTranslate(&enemy->obj.matrix[0], enemy->obj.pos.x, enemy->obj.pos.y, enemy->obj.pos.z);
		guRotateRPY(&enemy->obj.matrix[1], enemy->obj.rot.x, enemy->obj.rot.y, enemy->obj.rot.z);

		
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&enemy->obj.matrix[0]),
			  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&enemy->obj.matrix[1]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
			  
			  
		if(enemy->obj.scl.x || enemy->obj.scl.y || enemy->obj.scl.z != 1)	  
		{	  
			  		guScale(&enemy->obj.matrix[2], enemy->obj.scl.x, enemy->obj.scl.y, enemy->obj.scl.z);
			gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&enemy->obj.matrix[2]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);	
		}
			 
		//TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,900,995);		
		//TEXTURE_FOG_LIGHT(glistp, 150, 150, 100,255,900,992); //moved to level01.c
			  
		enemy->animator.animate(enemy->animator.animFrame);
		
		gDPPipeSync(glistp++);
}

void RenderProjectileObj(ProjectileObject* proj)
{ 
		gDPPipeSync(glistp++);
		gSPClearGeometryMode(glistp++,0xFFFFFFFF);
		gSPSetGeometryMode(glistp++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | 
			   G_FOG | G_LIGHTING | G_CULL_BACK);			 
			   

			   
		guTranslate(&proj->obj.matrix[0], proj->obj.pos.x, proj->obj.pos.y, proj->obj.pos.z);
		guRotateRPY(&proj->obj.matrix[1], proj->obj.rot.x, proj->obj.rot.y, proj->obj.rot.z);
		guScale(&proj->obj.matrix[2], proj->obj.scl.x, proj->obj.scl.y, proj->obj.scl.z);
		
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&proj->obj.matrix[0]),
			  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&proj->obj.matrix[1]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&proj->obj.matrix[2]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);	
			 
		//TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,900,995);		
		//TEXTURE_FOG_LIGHT(glistp, 150, 150, 100,255,900,992); //moved to level01.c
			  
		proj->animator.animate(proj->animator.animFrame);
		
		gDPPipeSync(glistp++);
}
/*END------------ Render environment and other static objects  -------------*/




/*--------------------------------------------------------------------------*/
/*---------- Update Matrices and render Player, NPCs, enemies etc ----------*/
/*--------------------------------------------------------------------------*/ 

void PlayerObjMTX(Player* pla)
{ 
		//For storing current player model's position, rotation and scale in matrices 
		gDPPipeSync(glistp++);
		gSPClearGeometryMode(glistp++,0xFFFFFFFF);
		gSPSetGeometryMode(glistp++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | 
			   G_FOG | G_LIGHTING | G_CULL_BACK);			 
			   
		guTranslate(&pla->obj.matrix[0], pla->obj.pos.x, pla->obj.pos.y, pla->obj.pos.z);
		guRotateRPY(&pla->obj.matrix[1], pla->obj.rot.x, pla->obj.rot.y, pla->obj.rot.z);
		
		
		

		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&pla->obj.matrix[0]),
			  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&pla->obj.matrix[1]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);

			  
		if(pla->obj.scl.x || pla->obj.scl.y || pla->obj.scl.z != 1)	  
		{
			guScale(&pla->obj.matrix[2], pla->obj.scl.x, pla->obj.scl.y, pla->obj.scl.z);
					gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&pla->obj.matrix[2]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);	
		}  
			 
		//TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,800,980);		//moved to player.c to avoid calling multiple times

		//pla->animator.animate(pla->animator.animFrame);				
		gDPPipeSync(glistp++);
				
}

void PlayerRigObjectMTX(RigObject* rigObj, void (*rigFunc)(void))
{	
	//Pass the RigObject located inside of the Player object or NPCObj, followed by the function associated 
	//with that rig part  ex. RenderPlayerRig(&playerAvatar.animRig.head, &player_head_PolyList);
		
	//Graphic settings
		gDPPipeSync(glistp++);
		gSPClearGeometryMode(glistp++,0xFFFFFFFF);
		gSPSetGeometryMode(glistp++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | 
			   G_FOG | G_LIGHTING | G_CULL_BACK);			 
	
	//Update the matrices of the RigObject with the current pos, rot, and scale 
	//and add the RigObject's offset position with the player object position. 
		guTranslate(&rigObj->matrix[0], rigObj->pos.x + playerAvatar.obj.pos.x, 
										rigObj->pos.y + playerAvatar.obj.pos.y, 
										rigObj->pos.z + playerAvatar.obj.pos.z);
		guRotateRPY(&rigObj->matrix[1], rigObj->rot.x, rigObj->rot.y, rigObj->rot.z);
		
		
		

		
	//Combine playerObject rotation matrix[1] with current rotation of rigObject
	//guMtxCatL(pointer to first matrix, pointer to second matrix, pointer to store resulting matrix)	
		guMtxCatL(&rigObj->matrix[1], &playerAvatar.obj.matrix[1], &rigObj->matrix[1] );

		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&rigObj->matrix[0]),
			  G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
		gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&rigObj->matrix[1]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
		if(rigObj->scl.x || rigObj->scl.y || rigObj->scl.z != 1)	  
		{
			guScale(&rigObj->matrix[2], rigObj->scl.x, rigObj->scl.y, rigObj->scl.z);
			gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&rigObj->matrix[2]),
			  G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);	
		}
		
		//TEXTURE_FOG_LIGHT(glistp, 42,26,40,255,800,980);		//moved to player.c to avoid calling multiple times
		
	//Call the function that is passed which has the model information for this RigObject
		rigFunc(); 
				
		gDPPipeSync(glistp++);
}
/*END------- Update Matrices and render Player, NPCs, enemies etc ----------*/
