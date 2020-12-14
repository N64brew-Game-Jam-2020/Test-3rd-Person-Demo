/*#include <nusys.h>
#include <nualsgi_n.h>
#include "main.h"
#include "para.h"
//#include "pack.h"
#include "malloc.h"*/
#include "main.h"
#include "levelDefs.h"

//audio
#include <nusys.h>
#include <ultra64.h>
#include <nualstl_n.h>
#include "config.h"
#include "audioDefs.h"
#include "audio.h"

int ptr_buf[NU_AU_SAMPLE_SIZE];
int sfx_buf[NU_AU_SE_SIZE];

// The stage number and structure  
volatile int stage;

//Controller structure
NUContData ContTriger[NU_CONT_MAXCONTROLLERS];

// main.c */
volatile int Pause = 0;
/* Frame buffer (3 frame buffers) */
static u16*	FrameBuf3[3] = {
    (u16*)NU_GFX_FRAMEBUFFER0_ADDR,
    (u16*)NU_GFX_FRAMEBUFFER1_ADDR,
    (u16*)NU_GFX_FRAMEBUFFER2_ADDR,
};

extern void gameTitleGFX(unsigned int pendingGfx);
extern void gameMainGFX(unsigned int pendingGfx);


/*--------------------------------------------------------------------------*/
/*-------------------------------Main Process-------------------------------*/
/*--------------------------------------------------------------------------*/
//From here, all other processes begin

void
mainproc(void)
{
	    nuGfxInit(); //nusys graphic initializer
		nuContInit(); //nusys controller initializer
		initAudio(); //nusys audio initializer
		nuGfxSetCfb(FrameBuf3, 3);
		stage = 0; //beginning stage number set to 0 (main menu)
				
		initLevels();

		//audio load test
		 // Read and register the sample bank and its pointers.
		Rom2Ram((void *)PBANK_START, (void *)ptr_buf, PBANK_END-PBANK_START);
		MusPtrBankInitialize(ptr_buf, WBANK_START);

		// Read and register the sound effects.
		Rom2Ram((void *)SFX_START, (void *)sfx_buf, SFX_END-SFX_START);
		MusFxBankInitialize(sfx_buf);


	while(1)
	{
		
		/*loadLevel will load a specific level based on the current stage.
		
		- 
		*/
		
	loadLevel(stage); //inits current stage; sets stage = -1; begins NUGfxFunc	for current stage			
	nuGfxDisplayOn();
	/*
		switch(stage)
		{
			//Switch to load a specific level based on the current stage. when 'stage' changes, 
		
			case 0: //title screen				
				loadLevel(stage); //inits current stage; sets stage = -1; begins NUGfxFunc	for current stage			
				nuGfxDisplayOn();
				break;
				
			case 1: //main game screen
				loadLevel(stage); //inits stage and begins NUGfxFunc
				nuGfxDisplayOn();
				break;
		}	
	*/


		/*
		    while(1){
	switch(stage){
		case 0:// Title Screen
			// Set stage to the different value from the stage number first so
			// that you can notice the call-back has set the value 
			stage = -1;
			
			// Play sequence of the title -   
			//nuAuSeqPlayerSetNo(0,0);
			//nuAuSeqPlayerPlay(0);
			
			// Call-back register  
			nuGfxFuncSet((NUGfxFunc)gametitle);
			// Start to display  
			nuGfxDisplayOn();
			break;
		
		case 1:// Level 1
			stage = -1;
			
			// Play sequence of this game volume  - HIDE MUSIC 
			//nuAuSeqPlayerSetNo(0,2);
			//nuAuSeqPlayerPlay(0);
			
			// Call-back register  
			nuGfxFuncSet((NUGfxFunc)gametitle);
			nuGfxDisplayOn();
			nuGfxFuncSet((NUGfxFunc)gamemain);
			// Start to display  
			nuGfxDisplayOn();
			break;
	  default:
	    break;
	}
	*/
		
		// Wait for switching the scene 
		while(stage == -1);
		{		
			nuGfxDisplayOff(); // Clear the display 
		}
	}
		
}

void loadLevel(unsigned int Index)
{
	stage = -1;
    lvls[Index]->levelInit();
 //resets stage to -1 and it will await the next stage value change
	//nuGfxFuncSet((NUGfxFunc)gameTitleGFX);
    nuGfxFuncSet((NUGfxFunc)lvls[Index]->levelGfx);
	
}

void initLevels(void)
{
    // Main Menu
    lvl00.levelInit    = InitTitle;
    lvl00.levelGfx     = gameTitleGFX;
    lvls[LEVEL_MAINMENU] = &lvl00;

    // Stage 00
    lvl01.levelInit   = InitLevel01;
    lvl01.levelGfx    = gameMainGFX;
    lvls[LEVEL_01] = &lvl01;	
}

static u8 GetStage()
{
	return stage;
}

