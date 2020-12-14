
#include <ultra64.h>
#include "common.h"
//#include "graphic.h"

/* The viewport structure  */
static Vp vp = {
    //SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, /* scale */
    //SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, /* translate */
	(SCREEN_WD)*2, (SCREEN_HT)*2, G_MAXZ/2, 0, /* scale */
    SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, /* translate */
};


static Vp menu_vp = {
    //SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, /* scale */
    //SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0, /* translate */
	(MENU_SCREEN_WD)*2, (MENU_SCREEN_HT)*2, G_MAXZ/2, 0, /* scale */
    MENU_SCREEN_WD*2, MENU_SCREEN_HT*2, G_MAXZ/2, 0, /* translate */
};

Lights1 sun_light1 = gdSPDefLights1(  75, 100, 100, // amb col 
0, 50, 100, // col 1   
90,   0,  90);   // dir 1   

Lights1 sun_light2 = gdSPDefLights1(  50, 75, 125, // amb col 
0, 100, 125, // col 1   
0,   0,  90);   // dir 1   

Lights1 sun_light3 = gdSPDefLights1(  5, 15, 15, // amb col 
125, 40, 125, // col 1   
0,   0,  90);   // dir 1   

Lights1 dark_light = gdSPDefLights1(  25, 0, 45, // amb col 
75, 0, 75, // col 1   
-90,   0,  0);   // dir 1   
		   
				   
/*
//Original Light
Lights1 sun_light = gdSPDefLights1(  80,  80,  80, // no ambient light 
				   200, 200, 200, // white light
				   0,   -1,   1);	
	*/		   

/* Setting RDP  */
Gfx game_setup_rdpstate[] = {

	gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_BAYER),
	gsDPSetScissor(G_SC_NON_INTERLACE, 0,0, SCREEN_WD,SCREEN_HT),	
	//gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),
    gsSPEndDisplayList(),
};

/* Setting RSP  */
Gfx game_setup_rspstate[] = {
    gsSPViewport(&vp),
	gsSPClipRatio(FRUSTRATIO_2),
	//gsSPClearGeometryMode((G_ZBUFFER |G_SHADE|G_SHADING_SMOOTH|G_LIGHTING|G_TEXTURE_GEN|G_TEXTURE_GEN_LINEAR|G_CULL_BOTH|G_FOG)),
    gsSPClearGeometryMode((G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_TEXTURE_GEN | G_CULL_BOTH | G_FOG | G_LIGHTING)),
	//gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_TEXTURE_GEN |
	//		   G_CULL_BACK | G_FOG | G_LIGHTING),
	gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH |
			   G_CULL_BACK | G_FOG | G_LIGHTING),
    gsSPTexture(0, 0, 0, 0, G_ON),
	gsSPSetLights1(sun_light1),	
	gsSPSetLights1(sun_light2),	
    gsSPEndDisplayList(),
};

/* Setting RDP  */
Gfx menu_setup_rdpstate[] = {

	gsDPPipeSync(),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_BAYER),
	gsDPSetScissor(G_SC_NON_INTERLACE, 0,0, MENU_SCREEN_WD,MENU_SCREEN_HT),	
	//gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),
    gsSPEndDisplayList(),
};

/* Setting RSP  */
Gfx menu_setup_rspstate[] = {
    gsSPViewport(&menu_vp),
	gsSPClipRatio(FRUSTRATIO_2),
	//gsSPClearGeometryMode((G_ZBUFFER |G_SHADE|G_SHADING_SMOOTH|G_LIGHTING|G_TEXTURE_GEN|G_TEXTURE_GEN_LINEAR|G_CULL_BOTH|G_FOG)),
    gsSPClearGeometryMode((G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_TEXTURE_GEN | G_CULL_BOTH | G_FOG | G_LIGHTING)),
	//gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_TEXTURE_GEN |
			//   G_CULL_BACK | G_FOG | G_LIGHTING),
	gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH |
			   G_CULL_BACK | G_FOG | G_LIGHTING),
    gsSPTexture(0, 0, 0, 0, G_ON),
	gsSPSetLights1(sun_light1),	
	gsSPSetLights1(sun_light2),	
    gsSPEndDisplayList(),
};
