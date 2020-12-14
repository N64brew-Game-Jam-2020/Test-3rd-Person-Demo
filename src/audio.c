//audio
#include <nusys.h>
#include <ultra64.h>
#include <nualstl_n.h>
#include "config.h"
#include "audioDefs.h"
#include "audio.h"
#include "common.h"

//handle for background
static musHandle sndBgHandle[5];
//static musHandle sndBgHandle1;
//static musHandle sndBgHandle2;
//static musHandle sndBgHandle3;
//static musHandle sndBgHandle4;


//handle for obne shot sound effects
static musHandle sndFxHandle;
static musHandle sndStepFxHandle;

void initAudio(void)
{
    musConfig c;

    c.control_flag	    = 0;                                // Set to MUSCONTROL_RAM if wbk file also placed in RAM
    c.channels		    = NU_AU_CHANNELS;                   // Maximum total number of channels
    c.sched		        = NULL;                             // The address of the Scheduler structure. NuSystem uses NULL
    c.thread_priority	= NU_AU_MGR_THREAD_PRI;             // thread priority (highest)
    c.heap		        = (unsigned char*)NU_AU_HEAP_ADDR;  // Heap address
    c.heap_length	    = NU_AU_HEAP_SIZE;                  // Heap size
    c.ptr		        = NULL;                             // Allows you to set a default ptr file
    c.wbk		        = NULL;                             // Allows you to set a default wbk file
    c.default_fxbank	= NULL;                             // Allows you to set a default bfx file
    c.fifo_length	    = NU_AU_FIFO_LENGTH;                // The size of the library's FIFO buffer
    c.syn_updates	    = NU_AU_SYN_UPDATE_MAX;             // Specifies the number of updates usable by the synthesizer.
    c.syn_output_rate	= 22050;                            // Audio output rate. The higher, the better quality
    c.syn_rsp_cmds	    = NU_AU_CLIST_LEN;                  // The maximum length of the audio command list.
    c.syn_retraceCount	= 1;                                // The number of frames per retrace message
    c.syn_num_dma_bufs	= NU_AU_DMA_BUFFER_NUM;             // Specifies number of buffers Audio Manager can use for DMA from ROM.
    c.syn_dma_buf_size	= NU_AU_DMA_BUFFER_SIZE;            // The length of each DMA buffer

    // Initialize the Audio Manager.
    nuAuStlMgrInit(&c);

    // Register the PRENMI function.
    nuAuPreNMIFuncSet(nuAuPreNMIProc);
}


void PlayAmbientLoop(u8 track, int volume)
{
	if(nuAuStlSndPlayerGetSndState(sndBgHandle[0]) == 0)
	{
		sndBgHandle[0] = nuAuStlSndPlayerPlay(track);
		MusHandleSetVolume(sndBgHandle[0], volume);
	}
}

void PlayAmbientLoopLocal(u8 track, int handle, int volume, int range, Vector3 position)
{
	if(nuAuStlSndPlayerGetSndState(sndBgHandle[handle]) == 0)
	{
		//MusHandleSetVolume(sndBgHandle[handle], volume);
		float distance = vectorDistance(mainCamera.obj.pos, position);
		float squareRange = range*range;
		if (distance < squareRange)
		{
			float dist = 1-((1.0f/squareRange)*distance);
			dist = dist*dist*dist*dist;
			sndBgHandle[handle] = nuAuStlSndPlayerPlay(track);
			MusHandleSetVolume(sndBgHandle[handle], (int)(volume * dist));
		}
	}
	else
	{
		float distance = vectorDistance(mainCamera.obj.pos, position);
		float squareRange = range*range;
		if (distance < squareRange)
		{
			float dist = 1-((1.0f/squareRange)*distance);
			dist = dist*dist*dist*dist;
			MusHandleSetVolume(sndBgHandle[handle], (int)(volume * dist));
		}
		else
			MusHandleStop(sndBgHandle[handle],0);
	}
}

/*void PlayAmbientLoop(u8 track)
{
	if(nuAuStlSndPlayerGetSndState(sndBgHandle[0]) == 0)
		sndBgHandle[0] = nuAuStlSndPlayerPlay(track);
}*/

void PlaySfx(u8 track)
{
	sndFxHandle = nuAuStlSndPlayerPlay(track);
}

void PlaySfx_Footstep(u8 track)
{
	if(nuAuStlSndPlayerGetSndState(sndStepFxHandle) == 0)
	{	
		sndStepFxHandle = MusStartEffect(track);
		MusHandleSetVolume(sndStepFxHandle, 96);
		MusHandleSetFreqOffset(sndStepFxHandle, -(guRandom()%100)*0.1f);
	}
}

void PlaySfxVolume(u8 track, int volume)
{ 
	sndFxHandle = MusStartEffect(track);
	MusHandleSetVolume(sndFxHandle, volume);
	MusHandleSetFreqOffset(sndFxHandle, -(guRandom()%100)*0.05f);
}

void Play3dSfx(u8 track, int volume, int range, Vector3 position)
{
	float distance = vectorDistance(mainCamera.obj.pos, position);
	float squareRange = range*range;
	//calculate volume multiplier - inverselerp?
    if (distance < squareRange)
	{
		//distance = (range-distance)*(65536.0/range);
		float dist = 1-((1.0f/squareRange)*distance);
		//volume = (int)(volume * dist);
		
		sndFxHandle = MusStartEffect(track);
		MusHandleSetVolume(sndFxHandle, (int)(volume * dist));
	}
}