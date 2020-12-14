//#include "gametitle.h"
#include "gametitle.h"
//#include "common.h"

#include "BootIntro.h"

u8 resolution = 0;

int menuState = menuState_fade_BlackToBrew;
u8 menuInit = 0;

void InitTitle(void)
{
	fullScreenFadeAlpha = 255;
	menuState = menuState_fade_BlackToBrew;
	
	initPlayer();
	initMainCamera();
	menuInit = 1;
}

/*--------------------------------------------------------------------------*/
/*--------------------------------GameTitle---------------------------------*/
/*--------------------------------------------------------------------------*/
void gameTitleGFX(unsigned int pendingGfx)
{
	if(menuInit != 1)
		InitTitle();
	
	/*Create trigger data */
	nuContDataGetExAll(&ContTriger[0]);
    
	/* The title progressing process  */
	updateTitle();
    /* Provide the display process if there is only one task which is processing or waiting for the process. */
    if(pendingGfx < 1)
	maketitleDL();	
}

void maketitleDL(void)
{
    Dynamic* dynamicp;

    /* Specify the dynamic buffer  */
    dynamicp = &gfx_dynamic[gfx_gtask_no];
    /* Specify the display list buffer  */
    glistp = &gfx_glist[gfx_gtask_no][0];
	
    gfxRCPInit();
    /*Clear the frame and Z-buffer */
    gfxClearCfb();
    /* Setting the view-matrix  */
	
	if(resolution == 0)
	{
		SetGameViewMtx( dynamicp );
		//SetGameViewMtx( dynamicDebugp );
	}
	/*
	if(resolution == 1)
	{
		SetMenuViewMtx( dynamicp );
		SetMenuViewMtx( dynamicDebugp );
	}
*/
    DrawTitle();
	
    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);
    assert((glistp - gfx_glist[gfx_gtask_no]) < GFX_GLIST_LEN);
    /* Activate the RSP task and switch display buffers. */
    nuGfxTaskStart(&gfx_glist[gfx_gtask_no][0],
		   (s32)(glistp - gfx_glist[gfx_gtask_no]) * sizeof (Gfx),
		   NU_GFX_UCODE_F3DEX2_NON  , NU_SC_SWAPBUFFER);
		   
    /* Indicate next graphic task number  */
    gfx_gtask_no++;
	//gfx_debug_gtask_no++;
    gfx_gtask_no %= GFX_GTASK_NUM;
	//gfx_debug_gtask_no %= GFX_GTASK_NUM;
	
	/* Wait for the task to end */
    nuGfxTaskAllEndWait();
	
}

int waiter = 0;//waiting to run out before progressing

void updateTitle(void)
{
	if(ContTriger[0].trigger & L_TRIG)
	{
		nuGfxFuncRemove();
		// Switch to first stage
		stage = 1;
	}
	
	if(menuState == menuState_fade_BlackToBrew)
	{
		if(fullScreenFadeAlpha <= 0)
		{
			fullScreenFadeAlpha = 0;
			menuState = menuState_wait_Brew;
			waiter = 60;
		}
		else
			fullScreenFadeAlpha -= 15;
	}
	else if(menuState == menuState_wait_Brew)
	{
		if(waiter <= 0)
		{
			menuState = menuState_fade_BrewToBlack;
			waiter = 0;
		}
		else
			waiter -= 1;
	}
	else if(menuState == menuState_fade_BrewToBlack)
	{
		if(fullScreenFadeAlpha >= 255)
		{
			fullScreenFadeAlpha = 255;
			menuState = menuState_fade_blackToTeam;
		}
		else
			fullScreenFadeAlpha += 5;
	}
	else if(menuState == menuState_fade_blackToTeam)
	{
		if(fullScreenFadeAlpha <= 0)
		{
			fullScreenFadeAlpha = 0;
			menuState = menuState_wait_Team;
			waiter = 60;
		}
		else
			fullScreenFadeAlpha -= 15;
	}
	else if(menuState == menuState_wait_Team)
	{
		if(waiter <= 0)
		{
			menuState = menuState_fade_teamToBlack;
			waiter = 0;
		}
		else
			waiter -= 1;
	}
	else if(menuState == menuState_fade_teamToBlack)
	{
		if(fullScreenFadeAlpha >= 255)
		{
			fullScreenFadeAlpha = 255;
			menuState = menuState_fade_BlackToMenu;
		}
		else
			fullScreenFadeAlpha += 5;
	}
	else if(menuState == menuState_fade_BlackToMenu)
	{
		if(fullScreenFadeAlpha <= 0)
		{
			fullScreenFadeAlpha = 0;
			menuState = menuState_wait_MenuInput;
		}
		else
			fullScreenFadeAlpha -= 15;
	}
	else if(menuState == menuState_wait_MenuInput)
	{
		if(ContTriger[0].trigger & START_BUTTON)
		{
			menuState = menuState_fade_MenuToGame;
			fullScreenFadeAlpha = 0;
		}
	}
	else if(menuState == menuState_fade_MenuToGame)
	{
		if(fullScreenFadeAlpha >= 255)
		{
			fullScreenFadeAlpha = 255;
			nuGfxFuncRemove();
			// Switch to first stage
			stage = 1;
		}
		else
			fullScreenFadeAlpha += 15;
	}
}

void DrawTitle( void )
{
	if(menuState <= menuState_fade_BrewToBlack)//logo
	{
		DrawSlide(0);
		sprintf(outstring,".");
		Draw8Font(0,0, TEX_COL_BLACK, 0);
	}
	else if(menuState <= menuState_fade_teamToBlack)//logo
	{
		DrawSlide(1);
		sprintf(outstring,".");
		Draw8Font(0,0, TEX_COL_BLACK, 0);
	}
	
	else if(menuState <= menuState_fade_MenuToGame)//menu
	{
		sprintf(outstring,"Test 3rd Person Demo");
		Draw8Font(50,70, TEX_COL_WHITE, 0);
		
		sprintf(outstring,"Controls");
		Draw8Font(50,110, TEX_COL_WHITE, 0);
		
		sprintf(outstring,"Move: Analog Stick");
		Draw8Font(50,130, TEX_COL_WHITE, 0);
		
		sprintf(outstring,"Camera: C Buttons");
		Draw8Font(50,150, TEX_COL_WHITE, 0);
		
		sprintf(outstring,"PRESS START");
		Draw8Font(50,170, TEX_COL_WHITE, 0);
		
		DrawStartPrompt();
	}
	
	
	//do the fading Stuff
	if(fullScreenFadeAlpha > 0)
		DrawFade(fullScreenFadeAlpha);
	
	//sync
	gDPPipeSync(glistp++)
}
