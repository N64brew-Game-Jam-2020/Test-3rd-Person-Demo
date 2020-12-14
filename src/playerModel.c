//#include "common.h"
#include "playerDefs.h"
#include "common.h"

//void player_head_PolyList();
/*
extern unsigned char PlayerTextures_face[];
unsigned short PlayerTextures_face_tlut[];
unsigned char PlayerTextures_glow[];
unsigned short PlayerTextures_glow_tlut[];
unsigned char PlayerTextures_metal[];
unsigned short PlayerTextures_metal_tlut[];
*/

//temporary variables used by all "_animation()" functions prior to storing final pos and rot data in RigObject
Vtx player_head_VertList_0 [];
Vtx player_chest_VertList_0 [];

Vtx player_right_arm_VertList_0 [];
Vtx player_right_arm_lower_VertList_0 [];

Vtx player_left_arm_VertList_0 [];
Vtx player_left_arm_lower_VertList_0 [];

Vtx player_right_leg_VertList_0 [];
Vtx player_right_leg_lower_VertList_0 [];

Vtx player_left_leg_VertList_0 [];
Vtx player_left_leg_lower_VertList_0 [];

//temporary variables used by all "_animation()" functions prior to storing final pos and rot data in RigObject
Vector3 tempObjVectorPos = {0,0,0};
Vector3 tempObjVectorRot = {0,0,0};
Vector3 tempObjVectorScl = {0,0,0};


	//This is a solid teal light that is for the glowing elements of the player model
	Lights1 glowLight = gdSPDefLights1( 
		0,200,200,
		0,0,0,
		0,0,0);

	//This is the lighting 
	Lights2 player_lighting = gdSPDefLights2(  	100, 100, 60, // amb col 
	//side reflect light
	0, 150, 175, // col 1  
	0,   0,  90, // dir 1
	//ground reflect light
	75, 10, 50, // col 2   
	45,   0,  -90 // dir 2
	);
	
	//For testing setting player light to playerAvatar struct
	Lights2 default_lighting = gdSPDefLights2( 255, 255, 255, // amb col 
	//side reflect light
	255, 255, 255, // col 1  
	0,   0,  90, // dir 1
	//ground reflect light
	255, 0, 0, // col 2   
	45,   0,  -90 // dir 2
	);


void defaultRig()
{
	//animFrame = 12;
	player_head_animation();
	player_chest_animation();
	player_right_arm_animation();
	player_right_arm_lower_animation();
	player_left_arm_animation();
	player_left_arm_lower_animation();	
	player_right_leg_animation();
	player_right_leg_lower_animation();
	player_left_leg_animation();
	player_left_leg_lower_animation();	
	
	
	//set default lighting info for first room. This is stored in the playerAvatar struct. During gameplay it will be updated as the player moves to different triggers in the environment 
	playerAvatar.playerLighting = default_lighting;
	player_lighting = playerAvatar.playerLighting;
	
	//playerAvatar.envLightSide = test_lighting.l[0]; 
	//playerAvatar.envLightGround = test_lighting.l[1];
	
	//player_lighting.l[0] = playerAvatar.envLightSide;
	//player_lighting.l[1] = playerAvatar.envLightGround;
}

void nextPlayerAnimFrame()
{	
	player_head_animation();
	player_chest_animation();
	player_right_arm_animation();
	player_right_arm_lower_animation();
	player_left_arm_animation();
	player_left_arm_lower_animation();	
	player_right_leg_animation();
	player_right_leg_lower_animation();
	player_left_leg_animation();
	player_left_leg_lower_animation();		
	
}

void nextPlayerLightingState()
{
	//pass new lighting state from playerAvatar to player_lighting
	player_lighting = playerAvatar.playerLighting;
}



	


		
 //Test Object = 1 
 
 //Test Object = 1 
 //Test Object = 1 
RigAnimation player_head_anim[] =
 { 
-0.516611, 0.284372, 70.710123,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, 0.284372, 70.710123,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.562508, -0.699441, 70.507151,
    3.861693, 0.000000, -0.414853,
       1.000000, 1.000000, 1.000000,
 -0.682560, -3.272834, 69.906789,
    13.962860, 0.000000, -1.500000,
       1.000000, 1.000000, 1.000000,
 -0.802613, -5.846227, 69.119072,
    24.064030, 0.000000, -2.585147,
       1.000000, 1.000000, 1.000000,
 -0.848509, -6.830039, 68.443131,
    27.925727, 0.000000, -3.000001,
       1.000000, 1.000000, 1.000000,
 -0.806244, -6.375930, 68.012214,
    27.421300, 0.000000, -2.640856,
       1.000000, 1.000000, 1.000000,
 -0.677363, -5.404195, 67.600203,
    26.341895, 0.000000, -1.501682,
       1.000000, 1.000000, 1.000000,
 -0.516611, -4.950087, 66.760695,
    25.837470, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.332696, -6.162286, 64.803427,
    28.974472, -0.152971, 1.892777,
       1.000000, 1.000000, 1.000000,
 -0.117917, -7.923054, 63.489312,
    34.098538, -0.417778, 3.978157,
       1.000000, 1.000000, 1.000000,
 0.146618, -8.690507, 64.200348,
    37.787086, -0.642469, 6.127498,
       1.000000, 1.000000, 1.000000,
 0.424439, -9.032685, 65.939039,
    40.970914, -0.858235, 8.196123,
       1.000000, 1.000000, 1.000000,
 0.530198, -9.084026, 67.319512,
    42.065523, -0.936934, 8.951498,
       1.000000, 1.000000, 1.000000,
 0.369469, -8.382900, 68.118739,
    39.348471, -0.824519, 7.874805,
       1.000000, 1.000000, 1.000000,
 -0.017740, -6.882578, 68.613636,
    33.534323, -0.545236, 5.200820,
       1.000000, 1.000000, 1.000000,
 -0.311845, -6.181452, 68.743420,
    30.817281, -0.313444, 2.983596,
       1.000000, 1.000000, 1.000000,
 -0.410300, -6.624199, 68.277669,
    30.849926, -0.221994, 1.845756,
       1.000000, 1.000000, 1.000000,
 -0.421141, -7.751699, 66.954100,
    31.130930, -0.176660, 1.117968,
       1.000000, 1.000000, 1.000000,
 -0.516611, -8.749532, 65.480596,
    31.814427, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.760393, -9.438808, 63.545740,
    34.350244, 0.575550, -1.835157,
       1.000000, 1.000000, 1.000000,
 -1.062359, -9.941884, 62.382865,
    38.361204, 0.994379, -3.874624,
       1.000000, 1.000000, 1.000000,
 -1.396150, -10.313590, 62.937862,
    42.626056, 0.992498, -6.044488,
       1.000000, 1.000000, 1.000000,
 -1.735806, -10.542538, 64.388704,
    47.074692, 0.976310, -8.169004,
       1.000000, 1.000000, 1.000000,
 -1.863251, -10.602228, 65.755057,
    48.763012, 0.936934, -8.951498,
       1.000000, 1.000000, 1.000000,
 -1.631361, -9.989858, 66.828507,
    46.244393, 0.799019, -7.874805,
       1.000000, 1.000000, 1.000000,
 -1.091234, -8.229480, 67.857379,
    38.839307, 0.533241, -5.200820,
       1.000000, 1.000000, 1.000000,
 -0.723988, -6.230023, 68.750811,
    30.107675, 0.313444, -2.983596,
       1.000000, 1.000000, 1.000000,
 -0.581841, -3.713113, 69.653451,
    18.609696, 0.156544, -1.487240,
       1.000000, 1.000000, 1.000000,
 -0.523401, -0.845450, 70.438820,
    5.284968, 0.037523, -0.355824,
       1.000000, 1.000000, 1.000000,
 -0.516611, 0.284372, 70.710123,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, 0.284372, 70.710123,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, 0.284372, 70.710123,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, 0.284372, 70.710123,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, 0.284372, 70.710123,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.519698, 0.001792, 70.866656,
    0.762714, -0.042476, 0.716601,
       1.000000, 1.000000, 1.000000,
 -0.528627, -0.800283, 71.278083,
    2.925552, -0.185905, 2.591040,
       1.000000, 1.000000, 1.000000,
 -0.539862, -1.772126, 71.694827,
    5.541078, -0.416548, 4.465479,
       1.000000, 1.000000, 1.000000,
 -0.548771, -2.483277, 71.864790,
    7.446579, -0.679188, 5.182079,
       1.000000, 1.000000, 1.000000,
 -0.556462, -2.994137, 71.875399,
    8.799577, -1.044315, 4.741444,
       1.000000, 1.000000, 1.000000,
 -0.564512, -3.442072, 71.877289,
    9.969897, -1.543036, 3.588863,
       1.000000, 1.000000, 1.000000,
 -0.570257, -3.720239, 71.879172,
    10.687531, -1.954545, 2.436280,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 71.889782,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.564463, -3.600865, 71.975142,
    10.348026, -1.961209, 2.327356,
       1.000000, 1.000000, 1.000000,
 -0.536772, -3.070619, 72.170591,
    8.910116, -1.599455, 3.255516,
       1.000000, 1.000000, 1.000000,
 -0.488453, -2.532950, 72.360724,
    7.472204, -1.237701, 4.346901,
       1.000000, 1.000000, 1.000000,
 -0.428716, -2.312549, 72.432661,
    6.922489, -1.099402, 5.090665,
       1.000000, 1.000000, 1.000000,
 -0.332461, -2.294616, 71.766502,
    6.922489, -1.099402, 5.497189,
       1.000000, 1.000000, 1.000000,
 -0.212638, -2.287244, 70.138258,
    6.922489, -1.099402, 5.685410,
       1.000000, 1.000000, 1.000000,
 -0.163836, -2.286387, 68.847114,
    6.922490, -1.099402, 5.716444,
       1.000000, 1.000000, 1.000000,
 -0.166355, -2.676102, 68.103302,
    6.934179, -1.098711, 4.659651,
       1.000000, 1.000000, 1.000000,
 -0.188036, -3.659854, 67.646277,
    7.034774, -1.092765, 2.117485,
       1.000000, 1.000000, 1.000000,
 -0.240770, -4.511361, 67.527449,
    7.279454, -1.078301, 0.195241,
       1.000000, 1.000000, 1.000000,
 -0.357503, -5.157730, 67.750454,
    8.200612, -1.047382, -0.777041,
       1.000000, 1.000000, 1.000000,
 -0.564607, -5.798052, 68.402958,
    10.080138, -0.997834, -1.351686,
       1.000000, 1.000000, 1.000000,
 -0.793007, -6.237632, 69.242096,
    11.858384, -0.954273, -1.550120,
       1.000000, 1.000000, 1.000000,
 -0.963501, -6.377242, 69.936264,
    12.523861, -0.938468, -1.572676,
       1.000000, 1.000000, 1.000000,
 -1.071039, -6.203160, 70.554715,
    12.040105, -0.951489, -1.542102,
       1.000000, 1.000000, 1.000000,
 -1.138930, -5.697821, 71.215165,
    10.644129, -0.988971, -1.354243,
       1.000000, 1.000000, 1.000000,
 -1.196769, -5.057614, 71.741259,
    8.895789, -1.035684, -0.875294,
       1.000000, 1.000000, 1.000000,
 -1.278930, -4.543063, 72.020513,
    7.522508, -1.072011, -0.109879,
       1.000000, 1.000000, 1.000000,
 -1.386952, -4.179961, 72.132599,
    6.590734, -1.102526, 1.350039,
       1.000000, 1.000000, 1.000000,
 -1.511227, -3.860964, 72.168529,
    5.814764, -1.129266, 3.258383,
       1.000000, 1.000000, 1.000000,
 -1.639482, -3.483637, 72.204757,
    4.911568, -1.138542, 4.048666,
       1.000000, 1.000000, 1.000000,
 -1.784020, -3.008310, 72.274625,
    3.783611, -1.116829, 3.315461,
       1.000000, 1.000000, 1.000000,
 -1.935156, -2.474182, 72.343522,
    2.530280, -1.070366, 1.479658,
       1.000000, 1.000000, 1.000000,
 -2.034859, -1.996357, 72.368991,
    1.384851, -1.048652, -0.076074,
       1.000000, 1.000000, 1.000000,
 -2.088920, -1.513338, 71.604085,
    0.177333, -1.076863, -1.198493,
       1.000000, 1.000000, 1.000000,
 -2.111146, -1.073361, 69.717664,
    -0.955168, -1.137230, -2.107060,
       1.000000, 1.000000, 1.000000,
 -2.113729, -0.917322, 68.183321,
    -1.363202, -1.165440, -2.406953,
       1.000000, 1.000000, 1.000000,
 -2.044687, -1.722479, 67.212373,
    -0.253689, -1.116583, -1.361445,
       1.000000, 1.000000, 1.000000,
 -1.865897, -3.734538, 66.531551,
    2.690679, -0.988422, 0.875811,
       1.000000, 1.000000, 1.000000,
 -1.701142, -5.430929, 66.330040,
    5.557689, -0.866776, 1.921320,
       1.000000, 1.000000, 1.000000,
 -1.597902, -6.636401, 66.436702,
    8.413103, -0.758620, 0.898552,
       1.000000, 1.000000, 1.000000,
 -1.506484, -7.597957, 66.716540,
    11.332652, -0.652025, -1.290044,
       1.000000, 1.000000, 1.000000,
 -1.362519, -7.912195, 66.982251,
    12.430568, -0.594158, -2.312812,
       1.000000, 1.000000, 1.000000,
 -1.112774, -7.703177, 67.126149,
    11.488507, -0.568882, -1.765361,
       1.000000, 1.000000, 1.000000,
 -0.769854, -7.084106, 67.203450,
    9.024333, -0.553942, -0.316743,
       1.000000, 1.000000, 1.000000,
 -0.486245, -6.269873, 67.380744,
    6.560156, -0.548784, 1.176751,
       1.000000, 1.000000, 1.000000,
 -0.386224, -5.568177, 67.777085,
    5.618098, -0.548197, 1.837486,
       1.000000, 1.000000, 1.000000,
 -0.431130, -4.836349, 69.098228,
    6.893413, -0.922921, 1.945897,
       1.000000, 1.000000, 1.000000,
 -0.527221, -4.085397, 71.218926,
    9.622427, -1.724784, 1.990468,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 -0.572126, -3.802527, 72.150975,
    10.897741, -2.099508, 1.995646,
       1.000000, 1.000000, 1.000000,
 
};
void player_head_animation()
 { 
   tempObjVectorPos = player_head_anim[animFrame].pos;
   tempObjVectorRot = player_head_anim[animFrame].rot;
   tempObjVectorScl = player_head_anim[animFrame].scl;

   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
   
	SetVector3(&playerAvatar.animRig.joint.head.pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.head.rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.head.scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z);
       //NOTE: Assign values to your rig here. For instance: 
       //SetVector3(&playerAvatar.animRig.joint.armR[0].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z);

 } 
void player_head_PolyList() 
 { 

   Vtx *player_head_VTXPointer = &player_head_VertList_0[0]; 
   
   	gSPClearGeometryMode(glistp++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_TEXTURE_GEN | G_CULL_BOTH | G_FOG | G_LIGHTING);
	gSPSetGeometryMode(glistp++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_FOG | G_LIGHTING | G_CULL_BACK);

   gSPVertex(glistp++,player_head_VTXPointer+0,26,0);

//OBJECT: 1 MATERIAL NO. 0 'playerHead_back'OK 
	gSPSetLights2(glistp++, player_lighting);

   TEXTURE_4B_TLUT_CLAMP(playerHead_back, playerHead_back_tlut, 6,1);

   gSPVertex(glistp++,player_head_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,9, 10, 11, 9); 
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSPVertex(glistp++,player_head_VTXPointer+24,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+10,26,0);
   gSP1Triangle(glistp++,17, 18, 0, 17); 
   gSP1Triangle(glistp++,0, 10, 17, 0); 
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSP1Triangle(glistp++,21, 18, 22, 21); 
   gSPVertex(glistp++,player_head_VTXPointer+9,26,0);
   gSP1Triangle(glistp++,22, 0, 2, 22); 
   gSPVertex(glistp++,player_head_VTXPointer+10,26,0);
   gSP1Triangle(glistp++,18, 1, 0, 18); 
   gSPVertex(glistp++,player_head_VTXPointer+57,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 0, 2, 3); 
   gSP1Triangle(glistp++,4, 5, 6, 4); 
   gSP1Triangle(glistp++,7, 2, 1, 7); 
   gSPVertex(glistp++,player_head_VTXPointer+59,26,0);
   gSP1Triangle(glistp++,5, 1, 0, 5); 
   gSPVertex(glistp++,player_head_VTXPointer+87,26,0);
   gSP1Triangle(glistp++,8, 9, 10, 8); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0dfc0212);
   gSP1Triangle(glistp++,14, 12, 15, 14); 
   gSPVertex(glistp++,player_head_VTXPointer+86,26,0);
   gSP1Triangle(glistp++,21, 22, 23, 21); 
           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x081b00cc);
   gSP1Triangle(glistp++,15, 20, 24, 15); 
   gSPVertex(glistp++,player_head_VTXPointer+11,26,0);
   gSP1Triangle(glistp++,20, 0, 17, 20); 
   gSPVertex(glistp++,player_head_VTXPointer+111,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+100,26,0);
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x083f103a);
   gSP1Triangle(glistp++,25, 23, 8, 25); 
   gSPVertex(glistp++,player_head_VTXPointer+125,26,0);
   gSP1Triangle(glistp++,1, 2, 3, 1); 
   gSPVertex(glistp++,player_head_VTXPointer+112,26,0);
   gSP1Triangle(glistp++,1, 0, 14, 1); 
   gSP1Triangle(glistp++,17, 14, 0, 17); 
   gSPVertex(glistp++,player_head_VTXPointer+107,26,0);
   gSP1Triangle(glistp++,0, 2, 6, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+137,26,0);
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x05ae0158);           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x02f2003b);
   gSP1Triangle(glistp++,9, 16, 17, 9); 
   gSPVertex(glistp++,player_head_VTXPointer+98,26,0);
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0dfc0212);
   gSP1Triangle(glistp++,3, 13, 17, 3); 
   gSPVertex(glistp++,player_head_VTXPointer+137,26,0);
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSPVertex(glistp++,player_head_VTXPointer+161,26,0);
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x0c33090c);
   gSP1Triangle(glistp++,17, 16, 0, 17); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0b060fc6);
   gSP1Triangle(glistp++,14, 17, 0, 14); 
   gSPVertex(glistp++,player_head_VTXPointer+160,26,0);
   gSP1Triangle(glistp++,0, 19, 1, 0); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x05360fca);
   gSP1Triangle(glistp++,13, 1, 19, 13); 


//OBJECT: 1 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_head_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0c6b03cc);
   gSP1Triangle(glistp++,6, 5, 7, 6); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0ddf07e4);
   gSP1Triangle(glistp++,1, 8, 3, 1); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x02ac08fe);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x03c708a4);
   gSP1Triangle(glistp++,12, 22, 13, 12); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x025b02ca);           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x016301ea);
   gSP1Triangle(glistp++,15, 16, 23, 15); 
   gSPVertex(glistp++,player_head_VTXPointer+32,26,0);
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0ddf07e4);
   gSP1Triangle(glistp++,15, 14, 7, 15); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x097d05d7);           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x080d061a);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x09fd07fa);
   gSP1Triangle(glistp++,10, 19, 6, 10); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0d5d09fb);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0d090aa6);
   gSP1Triangle(glistp++,11, 6, 8, 11); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x08dd04ff);           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x07bb058c);
   gSP1Triangle(glistp++,19, 13, 18, 19); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x0c7f0111);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0dd9009f);
   gSP1Triangle(glistp++,16, 13, 12, 16); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0f48074b);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0f5e078f);
   gSP1Triangle(glistp++,14, 11, 8, 14); 
   gSPVertex(glistp++,player_head_VTXPointer+16,26,0);
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x09ce013d);
   gSP1Triangle(glistp++,2, 7, 0, 2); 
   gSPVertex(glistp++,player_head_VTXPointer+66,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x025f093e);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x015b0583);
   gSP1Triangle(glistp++,4, 2, 9, 4); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x059f07ec);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x03ab0610);
   gSP1Triangle(glistp++,5, 7, 10, 5); 
   gSP1Triangle(glistp++,11, 5, 10, 11); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x025b02ca);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x039f0231);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x016301ea);
   gSP1Triangle(glistp++,1, 7, 8, 1); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x02ac08fe);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x03de08e8);
   gSP1Triangle(glistp++,3, 4, 6, 3); 
   gSPVertex(glistp++,player_head_VTXPointer+38,26,0);
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0c6b03cc);
   gSP1Triangle(glistp++,11, 6, 8, 11); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0d5d09fb);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x097d05d7);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x09fd07fa);
   gSP1Triangle(glistp++,5, 4, 0, 5); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x080d061a);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x08dd04ff);
   gSP1Triangle(glistp++,13, 4, 7, 13); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x0c7f0111);           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0db40046);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0dd9009f);
   gSP1Triangle(glistp++,10, 12, 7, 10); 
   gSPVertex(glistp++,player_head_VTXPointer+120,26,0);
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x015b0583);           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x014d029f);
   gSP1Triangle(glistp++,14, 13, 12, 14); 
   gSP1Triangle(glistp++,15, 16, 17, 15); 
   gSPVertex(glistp++,player_head_VTXPointer+71,26,0);
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x08ae0a94);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x059f07ec);
   gSP1Triangle(glistp++,6, 1, 0, 6); 
   gSPVertex(glistp++,player_head_VTXPointer+121,26,0);
   gSP1Triangle(glistp++,17, 18, 19, 17); 


//OBJECT: 1 MATERIAL NO. 5 'playerHead_front'OK 

   TEXTURE_4B_TLUT_CLAMP(playerHead_front, playerHead_front_tlut, 6,1);

   gSPVertex(glistp++,player_head_VTXPointer+33,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+32,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x01d506d6);
   gSP1Triangle(glistp++,0, 4, 5, 0); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x05550c06);
   gSP1Triangle(glistp++,23, 24, 21, 23); 
   gSPVertex(glistp++,player_head_VTXPointer+57,26,0);
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0f6c0a9c);
   gSP1Triangle(glistp++,8, 9, 1, 8); 
   gSPVertex(glistp++,player_head_VTXPointer+66,26,0);
   gSP1Triangle(glistp++,17, 18, 15, 17); 
   gSPVertex(glistp++,player_head_VTXPointer+87,26,0);
   gSP1Triangle(glistp++,11, 12, 13, 11); 
   gSPVertex(glistp++,player_head_VTXPointer+96,26,0);
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0acb06a0);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0dc00673);
   gSP1Triangle(glistp++,9, 18, 0, 9); 
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSPVertex(glistp++,player_head_VTXPointer+100,26,0);
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSPVertex(glistp++,player_head_VTXPointer+112,26,0);
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0dc00673);
   gSP1Triangle(glistp++,15, 2, 18, 15); 
   gSPVertex(glistp++,player_head_VTXPointer+121,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x0a5a0e67);
   gSP1Triangle(glistp++,3, 2, 4, 3); 
   gSPVertex(glistp++,player_head_VTXPointer+98,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x032b05a3);
   gSP1Triangle(glistp++,0, 4, 17, 0); 
   gSP1Triangle(glistp++,2, 20, 0, 2); 
   gSPVertex(glistp++,player_head_VTXPointer+162,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,1, 3, 2, 1); 
   gSPVertex(glistp++,player_head_VTXPointer+143,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0a280962);
   gSP1Triangle(glistp++,0, 21, 22, 0); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0acb06a0);
   gSP1Triangle(glistp++,21, 0, 9, 21); 
   gSPVertex(glistp++,player_head_VTXPointer+142,26,0);
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x0acb06a0);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0a280962);
   gSP1Triangle(glistp++,0, 10, 1, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+166,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,6, 2, 1, 6); 
   gSP1Triangle(glistp++,1, 7, 6, 1); 
   gSP1Triangle(glistp++,8, 4, 3, 8); 
   gSP1Triangle(glistp++,4, 8, 9, 4); 
   gSP1Triangle(glistp++,10, 3, 5, 10); 
   gSP1Triangle(glistp++,11, 8, 10, 11); 
   gSP1Triangle(glistp++,3, 10, 8, 3); 
   gSPVertex(glistp++,player_head_VTXPointer+161,26,0);
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x02d70e53);
   gSP1Triangle(glistp++,17, 13, 16, 17); 
   gSP1Triangle(glistp++,13, 17, 14, 13); 
   gSPVertex(glistp++,player_head_VTXPointer+160,26,0);
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x0d3d0e05);
   gSP1Triangle(glistp++,12, 13, 19, 12); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0fa60cbb);
   gSP1Triangle(glistp++,19, 0, 12, 19); 
   gSP1Triangle(glistp++,20, 12, 0, 20); 
   gSP1Triangle(glistp++,20, 6, 8, 20); 
   gSP1Triangle(glistp++,8, 12, 20, 8); 

   gDPPipeSync(glistp++);
//OBJECT: 1 MATERIAL NO. 7 'playerHead_glow'OK 


  // Vtx *player_head_VTXPointer = &player_head_VertList_0[0]; 
   
	gSPSetLights2(glistp++, glowLight);


   //gSPVertex(glistp++,player_head_VTXPointer+0,26,0);



   TEXTURE_4B_TLUT_CLAMP(playerHead_glow, playerHead_glow_tlut, 6,1);

   gSPVertex(glistp++,player_head_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,12, 13, 14, 12); 
   gSP1Triangle(glistp++,12, 14, 15, 12); 
   gSP1Triangle(glistp++,16, 17, 18, 16); 
   gSPVertex(glistp++,player_head_VTXPointer+32,26,0);
   gSP1Triangle(glistp++,6, 7, 8, 6); 
   gSP1Triangle(glistp++,9, 10, 11, 9); 
   gSP1Triangle(glistp++,12, 13, 14, 12); 
   gSP1Triangle(glistp++,16, 17, 18, 16); 
   gSP1Triangle(glistp++,18, 6, 19, 18); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x03460a03);
   gSP1Triangle(glistp++,20, 4, 21, 20); 
   gSP1Triangle(glistp++,21, 22, 20, 21); 
   gSPVertex(glistp++,player_head_VTXPointer+57,26,0);
   gSP1Triangle(glistp++,10, 11, 12, 10); 
   gSP1Triangle(glistp++,13, 14, 15, 13); 
   gSPVertex(glistp++,player_head_VTXPointer+66,26,0);
   gSP1Triangle(glistp++,7, 5, 8, 7); 
   gSP1Triangle(glistp++,0, 12, 13, 0); 
   gSP1Triangle(glistp++,14, 15, 16, 14); 
   gSPVertex(glistp++,player_head_VTXPointer+63,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x053e0109);
   gSP1Triangle(glistp++,22, 0, 23, 22); 
   gSPVertex(glistp++,player_head_VTXPointer+87,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,6, 4, 7, 6); 
   gSP1Triangle(glistp++,0, 16, 17, 0); 
   gSP1Triangle(glistp++,6, 16, 2, 6); 
   gSPVertex(glistp++,player_head_VTXPointer+86,26,0);
   gSP1Triangle(glistp++,0, 18, 17, 0); 
   gSP1Triangle(glistp++,17, 4, 0, 17); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x00f2046b);
   gSP1Triangle(glistp++,0, 16, 18, 0); 
   gSP1Triangle(glistp++,7, 2, 19, 7); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0111075e);
   gSP1Triangle(glistp++,1, 16, 12, 1); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x024700eb);
   gSP1Triangle(glistp++,20, 15, 0, 20); 
   gSP1Triangle(glistp++,4, 17, 8, 4); 
   gSPVertex(glistp++,player_head_VTXPointer+38,26,0);
   gSP1Triangle(glistp++,0, 12, 1, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+100,26,0);
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x03460a03);
   gSP1Triangle(glistp++,18, 0, 17, 18); 
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSPVertex(glistp++,player_head_VTXPointer+112,26,0);
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSPVertex(glistp++,player_head_VTXPointer+70,26,0);
   gSP1Triangle(glistp++,0, 4, 1, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+121,26,0);
   gSP1Triangle(glistp++,20, 21, 22, 20); 
   gSP1Triangle(glistp++,0, 3, 23, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+132,26,0);
   gSP1Triangle(glistp++,13, 14, 15, 13); 
   gSPVertex(glistp++,player_head_VTXPointer+87,26,0);
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0111075e);
   gSP1Triangle(glistp++,0, 11, 1, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+137,26,0);
   gSP1Triangle(glistp++,11, 12, 13, 11); 
   gSP1Triangle(glistp++,14, 15, 16, 14); 
   gSPVertex(glistp++,player_head_VTXPointer+87,26,0);
   gSP1Triangle(glistp++,0, 2, 16, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+137,26,0);
   gSP1Triangle(glistp++,14, 12, 18, 14); 
   gSPVertex(glistp++,player_head_VTXPointer+86,26,0);
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x024700eb);           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x00f2046b);
   gSP1Triangle(glistp++,0, 15, 16, 0); 
   gSPVertex(glistp++,player_head_VTXPointer+136,26,0);
   gSP1Triangle(glistp++,20, 21, 22, 20); 
   gSPVertex(glistp++,player_head_VTXPointer+87,26,0);
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x00f2046b);
   gSP1Triangle(glistp++,0, 17, 15, 0); 
   
   gSPSetLights2(glistp++, player_lighting);
   

   gDPPipeSync(glistp++);

 } 
    
  
 RigAnimation player_chest_anim[] =
 { 
-0.516611, -0.068683, 49.476635,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.476635,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.127920, 49.345753,
    2.483215, 0.000000, -0.414853,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.282868, 48.933941,
    8.978650, 0.000000, -1.500000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.437816, 48.334712,
    15.474086, 0.000000, -2.585147,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.497052, 47.730708,
    17.957302, 0.000000, -3.000001,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.393579, 47.164696,
    16.991086, 0.000000, -2.640856,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.172157, 46.504748,
    14.923513, 0.000000, -1.501682,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 45.656356,
    13.957299, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 44.207826,
    17.428749, -0.152971, 1.892777,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 43.305877,
    22.218370, -0.417778, 3.978157,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.138434, 44.231802,
    24.025453, -0.642469, 6.127498,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.287693, 46.306774,
    24.768392, -0.858235, 8.196123,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.357444, 47.521240,
    24.854710, -0.936934, 8.951498,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.287693, 47.824255,
    23.037499, -0.824519, 7.874805,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.138434, 47.948831,
    19.148893, -0.545236, 5.200820,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.963306,
    17.331678, -0.313444, 2.983596,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.650078,
    18.566853, -0.194864, 1.852086,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 46.727026,
    21.727744, -0.118985, 1.131424,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 45.634592,
    24.558956, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 44.073850,
    26.571458, 0.198850, -1.891976,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 43.110004,
    28.091793, 0.417778, -3.978157,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 43.820766,
    29.267986, 0.642469, -6.127498,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 45.543215,
    30.053771, 0.858235, -8.196123,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 46.875122,
    30.276429, 0.936934, -8.951498,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.459623,
    28.416089, 0.824519, -7.874805,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.690246,
    23.183762, 0.545236, -5.200820,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.985068,
    17.465832, 0.313444, -2.983596,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 48.570785,
    10.623416, 0.156544, -1.487240,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.222383,
    2.984826, 0.037523, -0.355824,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.476635,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.476635,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.476635,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.476635,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.476635,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.627566,
    0.761851, -0.051537, 0.498979,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.039566,
    2.922973, -0.212976, 1.940909,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.497991,
    5.538247, -0.446266, 3.751766,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.766110,
    7.446579, -0.679188, 5.182079,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.872630,
    8.807280, -0.963459, 6.224587,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.916791,
    9.990089, -1.331065, 7.135872,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.937349,
    10.718750, -1.626819, 7.988036,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.984263,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.074171,
    10.378380, -1.642544, 9.686319,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.189983,
    8.927727, -1.414554, 10.368288,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.282978,
    7.477075, -1.186563, 11.272954,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.315296,
    6.922489, -1.099402, 12.640161,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.634760,
    6.922489, -1.099402, 15.114664,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 48.990333,
    6.922489, -1.099402, 18.185865,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.729748,
    6.922490, -1.099402, 19.435380,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.101685,
    7.954202, -1.302987, 18.585454,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 46.810770,
    10.569545, -1.795313, 16.236289,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 46.762758,
    12.857733, -2.173620, 13.751298,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.053316,
    14.638287, -2.375333, 11.385137,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.882801,
    16.437726, -2.505530, 8.709640,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 48.899713,
    17.690975, -2.559775, 6.190660,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 49.663424,
    18.092705, -2.569751, 4.219613,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.248849,
    17.609771, -2.533473, 2.940733,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.799406,
    16.216206, -2.428588, 2.294434,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.162535,
    14.470973, -2.296742, 1.659327,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.274800,
    13.100270, -2.192404, 0.408702,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.274800,
    12.168222, -2.101005, -1.505972,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.274800,
    11.391586, -2.018018, -3.956675,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.274800,
    10.495196, -1.988640, -6.537984,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.274800,
    9.381009, -2.091964, -9.373992,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.274800,
    8.148662, -2.374188, -12.391562,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.274800,
    7.030735, -2.665928, -14.628267,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.470525,
    5.865906, -2.987670, -16.065467,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 48.523846,
    4.784066, -3.334097, -16.750674,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.024044,
    4.396311, -3.467424, -16.871284,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 46.259198,
    6.437137, -2.799294, -16.195857,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 45.885235,
    11.562036, -1.177716, -14.428995,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 45.815921,
    15.938760, 0.081838, -12.762422,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 46.166074,
    19.167729, 0.747964, -11.624679,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 46.915361,
    21.836581, 1.099680, -10.560640,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.265515,
    22.729661, 1.174382, -9.092245,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.265515,
    22.123673, 1.156640, -7.258798,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.265515,
    20.331151, 1.054565, -5.146517,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.265515,
    17.978993, 0.802291, -2.737107,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 47.265515,
    15.960224, 0.405382, -0.153572,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 48.226881,
    13.870321, -0.345339, 3.392623,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 50.284088,
    11.735451, -1.324506, 7.340432,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 -0.516611, -0.068683, 51.245451,
    10.932968, -1.729705, 8.881299,
       1.000000, 1.000000, 1.000000,
 
};
void player_chest_animation()
 { 
   tempObjVectorPos = player_chest_anim[animFrame].pos;
   tempObjVectorRot = player_chest_anim[animFrame].rot;
   tempObjVectorScl = player_chest_anim[animFrame].scl;

   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
   
   	SetVector3(&playerAvatar.animRig.joint.chest.pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.chest.rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.chest.scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z); 
       //NOTE: Assign values to your rig here. For instance: 
       //SetVector3(&playerAvatar.animRig.joint.armR[0].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z);

 } 
void player_chest_PolyList() 
 { 

   Vtx *player_chest_VTXPointer = &player_chest_VertList_0[0]; 

   gSPVertex(glistp++,player_chest_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_chest_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0d1f099c);           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0ac007fb);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x0c780a66);
   gSP1Triangle(glistp++,0, 11, 6, 0); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x03ae09e0);           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x06720946);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0618085e);
   gSP1Triangle(glistp++,2, 10, 3, 2); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x08960830);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x088c0722);
   gSP1Triangle(glistp++,3, 9, 4, 3); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0f9c0c09);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0e8a0c49);
   gSP1Triangle(glistp++,1, 6, 8, 1); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0b0806e0);
   gSP1Triangle(glistp++,4, 11, 5, 4); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x026f0c32);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x04830a97);
   gSP1Triangle(glistp++,1, 7, 2, 1); 
   gSP1Triangle(glistp++,0, 5, 11, 0); 
   gSP1Triangle(glistp++,2, 7, 10, 2); 
   gSP1Triangle(glistp++,3, 10, 9, 3); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0f9c0c09);
   gSP1Triangle(glistp++,1, 0, 6, 1); 
   gSP1Triangle(glistp++,4, 9, 11, 4); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x026f0c32);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x03870c49);
   gSP1Triangle(glistp++,1, 8, 7, 1); 
   gSPVertex(glistp++,player_chest_VTXPointer+25,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 0, 3); 
   gSPVertex(glistp++,player_chest_VTXPointer+23,26,0);
   gSP1Triangle(glistp++,8, 3, 6, 8); 
   gSP1Triangle(glistp++,9, 6, 10, 9); 
   gSP1Triangle(glistp++,11, 9, 12, 11); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0f210631);
   gSP1Triangle(glistp++,0, 8, 11, 0); 
   gSP1Triangle(glistp++,12, 10, 5, 12); 
   gSP1Triangle(glistp++,4, 13, 0, 4); 
   gSP1Triangle(glistp++,14, 15, 16, 14); 
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSP1Triangle(glistp++,20, 21, 22, 20); 
   gSP1Triangle(glistp++,20, 16, 23, 20); 
   gSP1Triangle(glistp++,24, 18, 25, 24); 
   gSPVertex(glistp++,player_chest_VTXPointer+38,26,0);
   gSP1Triangle(glistp++,0, 10, 11, 0); 
   gSPVertex(glistp++,player_chest_VTXPointer+37,26,0);
   gSP1Triangle(glistp++,0, 8, 13, 0); 
   gSP1Triangle(glistp++,5, 13, 8, 5); 
   gSP1Triangle(glistp++,2, 12, 14, 2); 
   gSP1Triangle(glistp++,14, 12, 3, 14); 
   gSP1Triangle(glistp++,15, 14, 3, 15); 
   gSPVertex(glistp++,player_chest_VTXPointer+21,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x09350156);
   gSP1Triangle(glistp++,21, 0, 19, 21); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0d490854);
   gSP1Triangle(glistp++,9, 13, 14, 9); 
   gSP1Triangle(glistp++,4, 8, 5, 4); 
   gSP1Triangle(glistp++,7, 12, 8, 7); 
   gSPVertex(glistp++,player_chest_VTXPointer+46,26,0);
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0f2a02ec);
   gSP1Triangle(glistp++,10, 11, 9, 10); 
   gSP1Triangle(glistp++,11, 10, 12, 11); 
   gSPVertex(glistp++,player_chest_VTXPointer+30,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0d490854);           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x0f210631);
   gSP1Triangle(glistp++,4, 0, 23, 4); 
   gSPVertex(glistp++,player_chest_VTXPointer+26,26,0);
   gSP1Triangle(glistp++,5, 10, 0, 5); 
   gSP1Triangle(glistp++,6, 5, 3, 6); 
   gSP1Triangle(glistp++,8, 5, 6, 8); 
   gSPVertex(glistp++,player_chest_VTXPointer+31,26,0);
           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x0f210631);
   gSP1Triangle(glistp++,22, 5, 0, 22); 
   gSP1Triangle(glistp++,4, 1, 2, 4); 
   gSPVertex(glistp++,player_chest_VTXPointer+36,26,0);
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x0f2a02ec);
   gSP1Triangle(glistp++,19, 23, 0, 19); 
   gSP1Triangle(glistp++,1, 11, 2, 1); 
   gSP1Triangle(glistp++,4, 12, 5, 4); 
   gSP1Triangle(glistp++,1, 7, 9, 1); 
   gSP1Triangle(glistp++,7, 1, 3, 7); 
   gSP1Triangle(glistp++,11, 14, 5, 11); 
   gSP1Triangle(glistp++,2, 11, 12, 2); 
   gSP1Triangle(glistp++,11, 1, 14, 11); 
   gSP1Triangle(glistp++,6, 5, 14, 6); 
   gSP1Triangle(glistp++,3, 2, 13, 3); 
   gSP1Triangle(glistp++,12, 4, 13, 12); 
   gSPVertex(glistp++,player_chest_VTXPointer+110,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00d20149);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x003a03b2);
   gSP1Triangle(glistp++,2, 0, 1, 2); 
   gSPVertex(glistp++,player_chest_VTXPointer+89,26,0);
           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x003a03b2);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x020c0606);
   gSP1Triangle(glistp++,23, 22, 0, 23); 
   gSPVertex(glistp++,player_chest_VTXPointer+117,26,0);
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x09bc03b5);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x09350156);
   gSP1Triangle(glistp++,8, 7, 6, 8); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0801061b);
   gSP1Triangle(glistp++,8, 5, 7, 8); 
   gSP1Triangle(glistp++,9, 10, 11, 9); 
   gSPVertex(glistp++,player_chest_VTXPointer+110,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00d20149);
   gSP1Triangle(glistp++,0, 18, 19, 0); 
   gSP1Triangle(glistp++,19, 18, 17, 19); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x09350156);
   gSP1Triangle(glistp++,13, 20, 15, 13); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0801061b);
   gSP1Triangle(glistp++,12, 15, 21, 12); 
   gSP1Triangle(glistp++,21, 15, 20, 21); 


//OBJECT: 0 MATERIAL NO. 2 'player_chest_plate'OK 

   TEXTURE_4B_TLUT_CLAMP(player_chest_plate, player_chest_plate_tlut, 6,1);

   gSPVertex(glistp++,player_chest_VTXPointer+58,26,0);
   gSP1Triangle(glistp++,9, 10, 11, 9); 
   gSP1Triangle(glistp++,12, 13, 14, 12); 
   gSP1Triangle(glistp++,11, 15, 9, 11); 
   gSP1Triangle(glistp++,14, 13, 16, 14); 
   gSPVertex(glistp++,player_chest_VTXPointer+72,26,0);
   gSP1Triangle(glistp++,19, 0, 20, 19); 
   gSP1Triangle(glistp++,2, 20, 0, 2); 
   gSPVertex(glistp++,player_chest_VTXPointer+69,26,0);
   gSP1Triangle(glistp++,24, 23, 0, 24); 
   gSP1Triangle(glistp++,4, 0, 23, 4); 
   gSPVertex(glistp++,player_chest_VTXPointer+110,26,0);
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSPVertex(glistp++,player_chest_VTXPointer+135,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,player_chest_VTXPointer+134,26,0);
   gSP1Triangle(glistp++,0, 2, 4, 0); 
   gSP1Triangle(glistp++,2, 0, 5, 2); 
   gSP1Triangle(glistp++,6, 7, 8, 6); 
   gSP1Triangle(glistp++,9, 8, 7, 9); 
   gSP1Triangle(glistp++,9, 7, 10, 9); 
   gSPVertex(glistp++,player_chest_VTXPointer+117,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0e720787);
   gSP1Triangle(glistp++,23, 0, 24, 23); 
   gSPVertex(glistp++,player_chest_VTXPointer+134,26,0);
   gSP1Triangle(glistp++,7, 0, 10, 7); 
   gSPVertex(glistp++,player_chest_VTXPointer+133,26,0);
   gSP1Triangle(glistp++,11, 1, 0, 11); 
   gSPVertex(glistp++,player_chest_VTXPointer+117,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0e720787);
   gSP1Triangle(glistp++,24, 0, 19, 24); 
   gSP1Triangle(glistp++,0, 20, 19, 0); 


//OBJECT: 0 MATERIAL NO. 9 'player_glow'OK 

	gSPSetLights2(glistp++, glowLight);
		

   TEXTURE_4B_TLUT_CLAMP(player_glow, player_glow_tlut, 6,1);

   gSPVertex(glistp++,player_chest_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,0, 3, 4, 0); 
   gSP1Triangle(glistp++,0, 2, 3, 0); 
   gSP1Triangle(glistp++,0, 4, 5, 0); 
   gSP1Triangle(glistp++,6, 7, 8, 6); 
   gSP1Triangle(glistp++,6, 9, 10, 6); 
   gSP1Triangle(glistp++,6, 10, 7, 6); 
   gSP1Triangle(glistp++,6, 11, 9, 6); 
   
	gSPSetLights2(glistp++, player_lighting);

//OBJECT: 0 MATERIAL NO. 11 'player_torso'OK 

   TEXTURE_4B_TLUT_CLAMP(player_torso, player_torso_tlut, 6,1);

   gSPVertex(glistp++,player_chest_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,12, 13, 14, 12); 
   gSP1Triangle(glistp++,15, 16, 17, 15); 
   gSP1Triangle(glistp++,14, 18, 12, 14); 
   gSP1Triangle(glistp++,19, 12, 18, 19); 
   gSP1Triangle(glistp++,16, 15, 20, 16); 
   gSP1Triangle(glistp++,21, 14, 13, 21); 
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSPVertex(glistp++,player_chest_VTXPointer+23,26,0);
   gSP1Triangle(glistp++,1, 0, 7, 1); 
   gSPVertex(glistp++,player_chest_VTXPointer+15,26,0);
           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x06950109);
   gSP1Triangle(glistp++,5, 0, 20, 5); 
   gSP1Triangle(glistp++,0, 15, 20, 0); 
   gSPVertex(glistp++,player_chest_VTXPointer+46,26,0);
   gSP1Triangle(glistp++,7, 8, 9, 7); 
   gSPVertex(glistp++,player_chest_VTXPointer+36,26,0);
   gSP1Triangle(glistp++,24, 18, 17, 24); 
   gSPVertex(glistp++,player_chest_VTXPointer+61,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,player_chest_VTXPointer+58,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x007c0149);
   gSP1Triangle(glistp++,0, 6, 7, 0); 
   gSP1Triangle(glistp++,3, 8, 4, 3); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0bae0275);
   gSP1Triangle(glistp++,17, 18, 2, 17); 
   gSP1Triangle(glistp++,19, 18, 17, 19); 
   gSP1Triangle(glistp++,20, 19, 17, 20); 
   gSP1Triangle(glistp++,21, 22, 23, 21); 
   gSP1Triangle(glistp++,19, 21, 23, 19); 
   gSPVertex(glistp++,player_chest_VTXPointer+82,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,player_chest_VTXPointer+76,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0bc30768);
   gSP1Triangle(glistp++,0, 9, 10, 0); 
   gSP1Triangle(glistp++,1, 5, 11, 1); 
   gSP1Triangle(glistp++,12, 13, 14, 12); 
   gSPVertex(glistp++,player_chest_VTXPointer+69,26,0);
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0b2106e5);
   gSP1Triangle(glistp++,7, 8, 21, 7); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x03f20533);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x04e406e5);
   gSP1Triangle(glistp++,12, 15, 14, 12); 
   gSP1Triangle(glistp++,14, 18, 12, 14); 
   gSP1Triangle(glistp++,21, 8, 18, 21); 
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x08020810);           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0aa00941);
   gSP1Triangle(glistp++,18, 19, 21, 18); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x055c0921);
   gSP1Triangle(glistp++,18, 14, 19, 18); 
   gSP1Triangle(glistp++,17, 21, 20, 17); 
   gSP1Triangle(glistp++,19, 14, 25, 19); 
   gSP1Triangle(glistp++,25, 14, 13, 25); 
   gSPVertex(glistp++,player_chest_VTXPointer+94,26,0);
   gSP1Triangle(glistp++,1, 2, 3, 1); 
   gSPVertex(glistp++,player_chest_VTXPointer+54,26,0);
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x029604d1);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x002303f3);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x02580566);
   gSP1Triangle(glistp++,19, 0, 13, 19); 
   gSPVertex(glistp++,player_chest_VTXPointer+74,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0d3d04be);           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x0fd7041f);
   gSP1Triangle(glistp++,0, 24, 23, 0); 
   gSPVertex(glistp++,player_chest_VTXPointer+99,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0f040341);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0f480516);
   gSP1Triangle(glistp++,0, 3, 1, 0); 
   gSPVertex(glistp++,player_chest_VTXPointer+95,26,0);
   gSP1Triangle(glistp++,2, 8, 0, 2); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0fd7041f);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0f9f05ba);
   gSP1Triangle(glistp++,2, 3, 8, 2); 
   gSP1Triangle(glistp++,6, 5, 9, 6); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0f480516);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0f3c06d1);
   gSP1Triangle(glistp++,5, 7, 9, 5); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x00980744);
   gSP1Triangle(glistp++,6, 9, 10, 6); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0f3c06d1);
   gSP1Triangle(glistp++,11, 9, 7, 11); 
   gSP1Triangle(glistp++,9, 11, 12, 9); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x00980744);           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x015b09a0);
   gSP1Triangle(glistp++,9, 12, 10, 9); 
   gSPVertex(glistp++,player_chest_VTXPointer+86,26,0);
   gSP1Triangle(glistp++,20, 0, 21, 20); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x015b09a0);
   gSP1Triangle(glistp++,19, 21, 22, 19); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0e930966);
   gSP1Triangle(glistp++,21, 0, 23, 21); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x015b09a0);           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x021c0b01);
   gSP1Triangle(glistp++,21, 23, 22, 21); 
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x0e380b21);
   gSP1Triangle(glistp++,0, 3, 23, 0); 
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x021c0b01);
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSP1Triangle(glistp++,23, 25, 24, 23); 
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x0e380b21);           gSPModifyVertex(glistp++, 25,   G_MWO_POINT_ST, 0x0d1f0e7b);
   gSP1Triangle(glistp++,23, 3, 25, 23); 
   gSPVertex(glistp++,player_chest_VTXPointer+89,26,0);
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0f9f05ba);
   gSP1Triangle(glistp++,9, 24, 14, 9); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x00cb04f2);           gSPModifyVertex(glistp++, 24,   G_MWO_POINT_ST, 0x00cf06bb);
   gSP1Triangle(glistp++,6, 14, 24, 6); 
           gSPModifyVertex(glistp++, 24,   G_MWO_POINT_ST, 0x0f57075c);
   gSP1Triangle(glistp++,25, 24, 9, 25); 
   gSPVertex(glistp++,player_chest_VTXPointer+95,26,0);
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x00cf06bb);
   gSP1Triangle(glistp++,20, 0, 18, 20); 
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x0f57075c);
   gSP1Triangle(glistp++,18, 19, 21, 18); 
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x00cf06bb);           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x01710951);
   gSP1Triangle(glistp++,18, 21, 20, 18); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0e9d09b7);
   gSP1Triangle(glistp++,19, 22, 21, 19); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x01710951);
   gSP1Triangle(glistp++,20, 21, 23, 20); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0e9d09b7);
   gSP1Triangle(glistp++,21, 22, 24, 21); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x01710951);           gSPModifyVertex(glistp++, 24,   G_MWO_POINT_ST, 0x01c60b0d);
   gSP1Triangle(glistp++,21, 24, 23, 21); 
   gSPVertex(glistp++,player_chest_VTXPointer+120,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,player_chest_VTXPointer+117,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x0de10b17);
   gSP1Triangle(glistp++,0, 6, 4, 0); 
   gSP1Triangle(glistp++,4, 6, 7, 4); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x01c60b0d);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x02d20e73);
   gSP1Triangle(glistp++,4, 7, 5, 4); 
   gSPVertex(glistp++,player_chest_VTXPointer+142,26,0);
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,5, 4, 6, 5); 
   gSP1Triangle(glistp++,7, 8, 9, 7); 
   gSP1Triangle(glistp++,8, 10, 9, 8); 

   gDPPipeSync(glistp++);

 } 
 
 
 
 
 
 
 
 
 //------RIGHT ARM STANDARD
 
 //Test Object = 9 
RigAnimation player_right_arm_anim[] =
 { 
-9.667793, -0.068682, 63.127100,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.667793, -0.068682, 63.127100,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.697466, -0.660970, 62.957752,
    5.698412, 0.001911, -0.117731,
       1.000000, 1.000000, 1.000000,
 -9.775081, -2.210238, 62.446851,
    20.603959, 0.018728, -0.425685,
       1.000000, 1.000000, 1.000000,
 -9.852697, -3.759506, 61.752671,
    35.509501, 0.067426, -0.733638,
       1.000000, 1.000000, 1.000000,
 -9.882370, -4.351794, 61.120647,
    41.207914, 0.149821, -0.851370,
       1.000000, 1.000000, 1.000000,
 -9.857429, -4.137272, 60.657936,
    29.442063, 1.014305, -0.811358,
       1.000000, 1.000000, 1.000000,
 -9.776790, -3.678223, 60.169727,
    1.374889, 2.731044, -0.466978,
       1.000000, 1.000000, 1.000000,
 -9.667793, -3.463702, 59.316397,
    -19.298553, 3.522186, 0.370667,
       1.000000, 1.000000, 1.000000,
 -9.534812, -4.474713, 57.481742,
    -27.259369, 1.552204, 1.967873,
       1.000000, 1.000000, 1.000000,
 -9.371029, -6.019828, 56.269300,
    -28.396631, -0.417778, 3.978157,
       1.000000, 1.000000, 1.000000,
 -9.158456, -6.889670, 56.997633,
    -26.499356, -0.416476, 6.114734,
       1.000000, 1.000000, 1.000000,
 -8.929177, -7.485230, 58.766150,
    -20.812158, -0.405272, 8.259695,
       1.000000, 1.000000, 1.000000,
 -8.840869, -7.657845, 60.141772,
    -13.898807, -0.378019, 9.059400,
       1.000000, 1.000000, 1.000000,
 -8.969732, -6.952137, 60.873729,
    -7.336084, 0.346727, 8.016398,
       1.000000, 1.000000, 1.000000,
 -9.278810, -5.442008, 61.264902,
    0.497229, 2.028179, 5.446254,
       1.000000, 1.000000, 1.000000,
 -9.510403, -4.736300, 61.349571,
    10.972163, 3.274738, 3.360584,
       1.000000, 1.000000, 1.000000,
 -9.590641, -4.980239, 60.938543,
    24.869858, 3.849981, 2.529464,
       1.000000, 1.000000, 1.000000,
 -9.603872, -5.544551, 59.762341,
    41.536843, 4.086480, 2.159040,
       1.000000, 1.000000, 1.000000,
 -9.667793, -5.918920, 58.436841,
    56.175075, 4.113957, 0.875989,
       1.000000, 1.000000, 1.000000,
 -9.827217, -6.035486, 56.665075,
    68.206638, -0.566453, -2.113314,
       1.000000, 1.000000, 1.000000,
 -10.015003, -6.052139, 55.593824,
    76.630460, -5.246865, -5.287883,
       1.000000, 1.000000, 1.000000,
 -10.207162, -6.040150, 56.220627,
    81.993416, -4.971681, -7.527478,
       1.000000, 1.000000, 1.000000,
 -10.394265, -5.936968, 57.804447,
    84.466190, -4.152994, -9.167473,
       1.000000, 1.000000, 1.000000,
 -10.462987, -5.685994, 59.178877,
    84.869929, -3.169359, -9.670621,
       1.000000, 1.000000, 1.000000,
 -10.331253, -5.300507, 60.077786,
    77.941228, -1.846270, -8.449535,
       1.000000, 1.000000, 1.000000,
 -10.020985, -4.677298, 60.807252,
    59.606672, -0.301194, -5.436840,
       1.000000, 1.000000, 1.000000,
 -9.801790, -3.815080, 61.461592,
    41.864487, 0.313444, -2.983596,
       1.000000, 1.000000, 1.000000,
 -9.709942, -2.423379, 62.206018,
    24.397904, 0.237730, -1.424927,
       1.000000, 1.000000, 1.000000,
 -9.672181, -0.744668, 62.885725,
    6.653103, 0.075713, -0.326511,
       1.000000, 1.000000, 1.000000,
 -9.667793, -0.068682, 63.127100,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.667793, -0.068682, 63.127100,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.667793, -0.068682, 63.127100,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.667793, -0.068682, 63.127100,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.667793, -0.068682, 63.127100,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.665322, -0.329807, 63.274360,
    0.209848, -0.155599, 0.487428,
       1.000000, 1.000000, 1.000000,
 -9.657104, -1.074926, 63.659561,
    0.758754, -0.562603, 1.899621,
       1.000000, 1.000000, 1.000000,
 -9.644159, -1.987556, 64.044762,
    1.307661, -0.969608, 3.682028,
       1.000000, 1.000000, 1.000000,
 -9.629750, -2.671553, 64.192021,
    1.517509, -1.125206, 5.104042,
       1.000000, 1.000000, 1.000000,
 -9.617268, -3.193318, 64.179939,
    0.037646, -1.119381, 6.165783,
       1.000000, 1.000000, 1.000000,
 -9.604873, -3.681589, 64.148331,
    -4.275142, -1.068135, 7.119592,
       1.000000, 1.000000, 1.000000,
 -9.585088, -4.002348, 64.116722,
    -9.780123, -0.919731, 8.010175,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.104640,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.522134, -4.050333, 64.185333,
    -18.361642, -0.200704, 9.691760,
       1.000000, 1.000000, 1.000000,
 -9.488813, -3.917173, 64.396405,
    -22.827001, 0.514890, 10.318860,
       1.000000, 1.000000, 1.000000,
 -9.431194, -3.784012, 64.607483,
    -26.100164, 1.133326, 11.164128,
       1.000000, 1.000000, 1.000000,
 -9.338035, -3.733104, 64.688176,
    -27.182575, 1.355988, 12.494330,
       1.000000, 1.000000, 1.000000,
 -9.161363, -3.914613, 64.024818,
    -27.182575, 1.355988, 14.957341,
       1.000000, 1.000000, 1.000000,
 -8.935390, -4.368319, 62.399721,
    -27.182575, 1.355988, 18.034628,
       1.000000, 1.000000, 1.000000,
 -8.842490, -4.751124, 61.102629,
    -27.182575, 1.355988, 19.289550,
       1.000000, 1.000000, 1.000000,
 -8.885247, -5.023744, 60.336280,
    -25.344342, 0.876252, 18.484966,
       1.000000, 1.000000, 1.000000,
 -9.012946, -5.241667, 59.846908,
    -20.398100, -0.338707, 16.219193,
       1.000000, 1.000000, 1.000000,
 -9.167302, -5.312990, 59.714293,
    -15.438333, -1.399138, 13.737517,
       1.000000, 1.000000, 1.000000,
 -9.338745, -5.309148, 59.950024,
    -11.495221, -2.132402, 11.318968,
       1.000000, 1.000000, 1.000000,
 -9.548435, -5.275352, 60.635841,
    -7.631927, -2.784480, 8.559240,
       1.000000, 1.000000, 1.000000,
 -9.750324, -5.177481, 61.508417,
    -3.373063, -3.332318, 5.858813,
       1.000000, 1.000000, 1.000000,
 -9.902077, -5.011886, 62.215608,
    1.568637, -3.802433, 3.589973,
       1.000000, 1.000000, 1.000000,
 -10.002175, -4.743724, 62.825769,
    7.062567, -4.194003, 1.912489,
       1.000000, 1.000000, 1.000000,
 -10.058878, -4.313470, 63.461483,
    13.129211, -4.478070, 0.749862,
       1.000000, 1.000000, 1.000000,
 -10.096206, -3.774367, 63.956136,
    19.780487, -4.709024, -0.496424,
       1.000000, 1.000000, 1.000000,
 -10.147392, -3.231419, 64.210194,
    26.750294, -4.966519, -2.385103,
       1.000000, 1.000000, 1.000000,
 -10.220077, -2.692877, 64.318281,
    35.403544, -5.252101, -5.052669,
       1.000000, 1.000000, 1.000000,
 -10.295944, -2.096757, 64.361066,
    44.802575, -5.534003, -8.338883,
       1.000000, 1.000000, 1.000000,
 -10.348654, -1.444611, 64.371252,
    50.061100, -5.810066, -11.506239,
       1.000000, 1.000000, 1.000000,
 -10.379224, -0.691940, 64.378834,
    51.600498, -6.145185, -14.580755,
       1.000000, 1.000000, 1.000000,
 -10.391793, 0.125174, 64.381951,
    51.846235, -6.482504, -17.586767,
       1.000000, 1.000000, 1.000000,
 -10.393253, 0.782377, 64.382315,
    53.097211, -6.608423, -19.910155,
       1.000000, 1.000000, 1.000000,
 -10.388415, 1.315868, 63.558507,
    55.855515, -6.064792, -21.697112,
       1.000000, 1.000000, 1.000000,
 -10.372203, 1.702347, 61.571318,
    59.566121, -4.552523, -22.830855,
       1.000000, 1.000000, 1.000000,
 -10.349303, 1.819899, 60.055959,
    63.350770, -2.933192, -23.136031,
       1.000000, 1.000000, 1.000000,
 -10.322352, 1.199916, 59.319627,
    67.879513, -1.050039, -22.413324,
       1.000000, 1.000000, 1.000000,
 -10.288388, -0.362027, 58.999449,
    72.633092, 1.026779, -20.535544,
       1.000000, 1.000000, 1.000000,
 -10.251503, -1.707190, 58.954668,
    74.442218, 1.834233, -18.791669,
       1.000000, 1.000000, 1.000000,
 -10.224639, -2.723218, 59.160107,
    72.714132, 1.099400, -17.724817,
       1.000000, 1.000000, 1.000000,
 -10.196049, -3.580851, 59.657437,
    67.634575, -0.835936, -16.774361,
       1.000000, 1.000000, 1.000000,
 -10.129581, -3.871698, 60.040772,
    61.647430, -2.689377, -15.121373,
       1.000000, 1.000000, 1.000000,
 -10.002542, -3.861487, 60.195649,
    56.517131, -4.414761, -12.808286,
       1.000000, 1.000000, 1.000000,
 -9.820766, -3.834778, 60.228723,
    51.368227, -6.383483, -9.981744,
       1.000000, 1.000000, 1.000000,
 -9.659642, -3.808069, 60.272455,
    44.246898, -7.865947, -6.687901,
       1.000000, 1.000000, 1.000000,
 -9.584736, -3.797858, 60.454214,
    34.137326, -8.363796, -3.195135,
       1.000000, 1.000000, 1.000000,
 -9.563637, -3.871141, 61.536723,
    16.462119, -6.505006, 1.553649,
       1.000000, 1.000000, 1.000000,
 -9.554962, -4.027957, 63.485712,
    -5.390889, -2.527426, 6.845827,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 -9.553954, -4.101240, 64.365828,
    -14.269608, -0.668636, 8.912310,
       1.000000, 1.000000, 1.000000,
 
};

 //------RIGHT ARM SHOOTING

 RigAnimation player_right_arm_shooting_anim[] =
 { 
-9.551513, -2.869224, 62.739777,
    -73.565092, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.551513, -2.869224, 62.739777,
    -73.565092, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.581185, -3.069563, 62.604279,
    -72.967177, 5.530319, 0.028713,
       1.000000, 1.000000, 1.000000,
 -9.658801, -3.593597, 62.186501,
    -71.403194, 19.996173, 0.103818,
       1.000000, 1.000000, 1.000000,
 -9.736417, -4.117631, 61.597801,
    -69.839217, 34.462030, 0.178923,
       1.000000, 1.000000, 1.000000,
 -9.766089, -4.317970, 61.030827,
    -69.241302, 39.992352, 0.207636,
       1.000000, 1.000000, 1.000000,
 -9.734039, -4.103449, 60.581959,
    -71.595470, 30.839226, -0.531626,
       1.000000, 1.000000, 1.000000,
 -9.645396, -3.644400, 60.077328,
    -76.633090, 11.252670, -2.113555,
       1.000000, 1.000000, 1.000000,
 -9.551513, -3.429879, 59.226574,
    -78.987258, 2.099547, -2.852816,
       1.000000, 1.000000, 1.000000,
 -9.476671, -4.455326, 57.443409,
    -78.772742, 8.476586, -0.375583,
       1.000000, 1.000000, 1.000000,
 -9.371029, -6.019828, 56.269299,
    -78.185490, 15.483480, 2.958143,
       1.000000, 1.000000, 1.000000,
 -9.173570, -6.894066, 56.997627,
    -77.222611, 16.083907, 4.132311,
       1.000000, 1.000000, 1.000000,
 -8.936286, -7.487298, 58.766151,
    -76.045537, 16.142763, 4.615045,
       1.000000, 1.000000, 1.000000,
 -8.840869, -7.657845, 60.141773,
    -75.569233, 16.743191, 4.671131,
       1.000000, 1.000000, 1.000000,
 -8.969732, -6.952137, 60.873734,
    -75.738178, 19.177599, 3.324057,
       1.000000, 1.000000, 1.000000,
 -9.278810, -5.442008, 61.264900,
    -76.472813, 22.894205, 0.131473,
       1.000000, 1.000000, 1.000000,
 -9.510403, -4.736300, 61.349571,
    -77.791914, 24.506389, -2.171226,
       1.000000, 1.000000, 1.000000,
 -9.590642, -4.980239, 60.938545,
    -80.217724, 24.131808, -3.174787,
       1.000000, 1.000000, 1.000000,
 -9.603873, -5.544551, 59.762337,
    -83.320590, 23.330249, -3.587379,
       1.000000, 1.000000, 1.000000,
 -9.667793, -5.918920, 58.436840,
    -84.596244, 22.955668, -3.635317,
       1.000000, 1.000000, 1.000000,
 -9.827216, -6.035486, 56.665073,
    -81.100273, 23.607290, 1.187280,
       1.000000, 1.000000, 1.000000,
 -10.015002, -6.052139, 55.593826,
    -76.897739, 24.258911, 7.615258,
       1.000000, 1.000000, 1.000000,
 -10.207163, -6.040151, 56.220631,
    -75.929109, 23.231835, 9.816076,
       1.000000, 1.000000, 1.000000,
 -10.394265, -5.936968, 57.804451,
    -75.530875, 21.034017, 10.720895,
       1.000000, 1.000000, 1.000000,
 -10.462988, -5.685995, 59.178879,
    -75.484607, 20.006939, 10.826021,
       1.000000, 1.000000, 1.000000,
 -10.331254, -5.300507, 60.077789,
    -76.978677, 20.196787, 8.891712,
       1.000000, 1.000000, 1.000000,
 -10.020986, -4.677298, 60.807255,
    -80.175814, 20.603042, 4.432467,
       1.000000, 1.000000, 1.000000,
 -9.801790, -3.815080, 61.461594,
    -81.669883, 20.792890, 1.511553,
       1.000000, 1.000000, 1.000000,
 -9.720716, -2.423379, 62.206020,
    -79.986713, 15.770302, 0.475459,
       1.000000, 1.000000, 1.000000,
 -9.695084, -0.744668, 62.885727,
    -76.106510, 5.022590, 0.049491,
       1.000000, 1.000000, 1.000000,
 -9.667793, -0.068682, 63.127102,
    -73.565099, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -9.621543, -0.100005, 63.123550,
    -72.541704, 0.271465, 0.131250,
       1.000000, 1.000000, 1.000000,
 -9.571607, -0.187320, 63.112576,
    -71.695676, 1.020447, 0.493374,
       1.000000, 1.000000, 1.000000,
 -9.518923, -0.321994, 63.093697,
    -70.999591, 2.161578, 1.045097,
       1.000000, 1.000000, 1.000000,
 -9.464298, -0.496809, 63.066418,
    -70.430500, 3.622764, 1.751563,
       1.000000, 1.000000, 1.000000,
 -9.408447, -0.705598, 63.030201,
    -69.968793, 5.341664, 2.582630,
       1.000000, 1.000000, 1.000000,
 -9.352016, -0.942984, 62.984474,
    -69.597353, 7.263138, 3.511639,
       1.000000, 1.000000, 1.000000,
 -9.295607, -1.204184, 62.928623,
    -69.300978, 9.337316, 4.514479,
       1.000000, 1.000000, 1.000000,
 -9.239791, -1.484858, 62.861958,
    -69.065835, 11.518084, 5.568855,
       1.000000, 1.000000, 1.000000,
 -9.185128, -1.780985, 62.783726,
    -68.879118, 13.761845, 6.653686,
       1.000000, 1.000000, 1.000000,
 -9.132174, -2.088767, 62.693077,
    -68.728731, 16.026445, 7.748592,
       1.000000, 1.000000, 1.000000,
 -9.081501, -2.404535, 62.589062,
    -68.602960, 18.270204, 8.833423,
       1.000000, 1.000000, 1.000000,
 -9.033700, -2.724666, 62.470604,
    -68.490248, 20.450973, 9.887798,
       1.000000, 1.000000, 1.000000,
 -8.989405, -3.045505, 62.336468,
    -68.378916, 22.525153, 10.890638,
       1.000000, 1.000000, 1.000000,
 -8.949302, -3.363273, 62.185230,
    -68.256894, 24.446627, 11.819647,
       1.000000, 1.000000, 1.000000,
 -8.914151, -3.673974, 62.015244,
    -68.111398, 26.165526, 12.650714,
       1.000000, 1.000000, 1.000000,
 -8.884814, -3.973277, 61.824554,
    -67.928574, 27.626715, 13.357182,
       1.000000, 1.000000, 1.000000,
 -8.862278, -4.256373, 61.610855,
    -67.693021, 28.767845, 13.908903,
       1.000000, 1.000000, 1.000000,
 -8.847706, -4.517788, 61.371353,
    -67.387206, 29.516826, 14.271027,
       1.000000, 1.000000, 1.000000,
 -8.842490, -4.751124, 61.102631,
    -66.990625, 29.788289, 14.402279,
       1.000000, 1.000000, 1.000000,
 -8.885247, -4.999595, 60.619274,
    -66.355711, 29.054453, 13.704652,
       1.000000, 1.000000, 1.000000,
 -9.012945, -5.230308, 59.980034,
    -65.621268, 27.084480, 11.893043,
       1.000000, 1.000000, 1.000000,
 -9.167302, -5.312990, 59.714294,
    -65.330179, 25.118685, 10.212788,
       1.000000, 1.000000, 1.000000,
 -9.338745, -5.309148, 59.950024,
    -66.074874, 23.160864, 8.736932,
       1.000000, 1.000000, 1.000000,
 -9.548434, -5.275352, 60.635841,
    -68.236418, 20.841982, 7.111601,
       1.000000, 1.000000, 1.000000,
 -9.750324, -5.177481, 61.508419,
    -70.974360, 19.058634, 5.913418,
       1.000000, 1.000000, 1.000000,
 -9.902077, -5.011887, 62.215607,
    -73.174118, 18.452736, 5.515874,
       1.000000, 1.000000, 1.000000,
 -10.002174, -4.743724, 62.825768,
    -75.123277, 19.289112, 5.523441,
       1.000000, 1.000000, 1.000000,
 -10.058878, -4.313471, 63.461483,
    -77.205699, 21.646276, 5.590006,
       1.000000, 1.000000, 1.000000,
 -10.096206, -3.774367, 63.956139,
    -78.711735, 24.460584, 5.782773,
       1.000000, 1.000000, 1.000000,
 -10.147392, -3.231419, 64.210197,
    -79.205824, 26.450988, 6.108928,
       1.000000, 1.000000, 1.000000,
 -10.220078, -2.692877, 64.318283,
    -78.404923, 27.710890, 6.836305,
       1.000000, 1.000000, 1.000000,
 -10.295944, -2.096757, 64.361069,
    -76.691106, 28.497735, 8.441655,
       1.000000, 1.000000, 1.000000,
 -10.348654, -1.444611, 64.371254,
    -75.890205, 28.706011, 10.653997,
       1.000000, 1.000000, 1.000000,
 -10.379225, -0.691939, 64.378838,
    -76.570553, 25.454599, 14.129110,
       1.000000, 1.000000, 1.000000,
 -10.391793, 0.125174, 64.381958,
    -78.370820, 18.496982, 18.342456,
       1.000000, 1.000000, 1.000000,
 -10.393253, 0.782377, 64.382317,
    -80.112819, 15.245571, 20.042289,
       1.000000, 1.000000, 1.000000,
 -10.388415, 1.315868, 63.558510,
    -81.827565, 17.282482, 20.037714,
       1.000000, 1.000000, 1.000000,
 -10.372203, 1.702348, 61.571316,
    -83.569516, 21.641219, 19.998353,
       1.000000, 1.000000, 1.000000,
 -10.349303, 1.819899, 60.055958,
    -84.222612, 23.678130, 19.902613,
       1.000000, 1.000000, 1.000000,
 -10.322352, 1.199916, 59.319626,
    -83.038872, 23.639872, 19.705231,
       1.000000, 1.000000, 1.000000,
 -10.288388, -0.362027, 58.999451,
    -80.161730, 23.558009, 19.314011,
       1.000000, 1.000000, 1.000000,
 -10.251503, -1.707191, 58.954666,
    -77.917364, 23.519751, 18.793631,
       1.000000, 1.000000, 1.000000,
 -10.224640, -2.723218, 59.160107,
    -76.708318, 25.490568, 18.318079,
       1.000000, 1.000000, 1.000000,
 -10.196049, -3.580851, 59.657436,
    -76.046650, 29.707874, 17.724390,
       1.000000, 1.000000, 1.000000,
 -10.129581, -3.871698, 60.040771,
    -75.898237, 31.678691, 16.652059,
       1.000000, 1.000000, 1.000000,
 -10.002542, -3.861487, 60.195644,
    -76.570929, 27.382975, 15.047679,
       1.000000, 1.000000, 1.000000,
 -9.820765, -3.834778, 60.228722,
    -78.330515, 16.146525, 12.953368,
       1.000000, 1.000000, 1.000000,
 -9.659641, -3.808069, 60.272453,
    -80.090102, 4.910074, 10.766459,
       1.000000, 1.000000, 1.000000,
 -9.584736, -3.797858, 60.454212,
    -80.762793, 0.614357, 8.928324,
       1.000000, 1.000000, 1.000000,
 -9.563637, -3.871141, 61.536720,
    -79.715800, 7.679984, 7.174795,
       1.000000, 1.000000, 1.000000,
 -9.554962, -4.027957, 63.485714,
    -77.475375, 22.799549, 5.644501,
       1.000000, 1.000000, 1.000000,
 
};

void player_right_arm_animation()
 { 
 
	if(playerAvatar.playerShooting == true)
	{	
	   tempObjVectorPos = player_right_arm_shooting_anim[animFrame].pos;
	   tempObjVectorRot = player_right_arm_shooting_anim[animFrame].rot;
	   tempObjVectorScl = player_right_arm_shooting_anim[animFrame].scl;
	}

	else
	{
	
	   tempObjVectorPos = player_right_arm_anim[animFrame].pos;
	   tempObjVectorRot = player_right_arm_anim[animFrame].rot;
	   tempObjVectorScl = player_right_arm_anim[animFrame].scl;
	}
	
   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
   
   	SetVector3(&playerAvatar.animRig.joint.armR[0].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.armR[0].rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.armR[0].scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z);
       //NOTE: Assign values to your rig here. For instance: 
       //SetVector3(&playerAvatar.animRig.joint.armR[0].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z);

 } 
void player_right_arm_PolyList() 
 { 

	Vtx *player_right_arm_VTXPointer = &player_right_arm_VertList_0[0]; 

   gSPVertex(glistp++,player_right_arm_VTXPointer+0,26,0);

//OBJECT: 9 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_right_arm_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x000b02d1);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x02ab03af);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x02cd00ad);
   gSP1Triangle(glistp++,1, 4, 6, 1); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x05fa02cc);
   gSP1Triangle(glistp++,4, 8, 6, 4); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x072d00c3);
   gSP1Triangle(glistp++,8, 12, 6, 8); 


//OBJECT: 9 MATERIAL NO. 12 'player_limb1'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb1, player_limb1_tlut, 6,1);

   gSPVertex(glistp++,player_right_arm_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,0, 3, 4, 0); 
   gSP1Triangle(glistp++,1, 0, 4, 1); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0f2508cf);
   gSP1Triangle(glistp++,5, 1, 6, 5); 
   gSP1Triangle(glistp++,7, 5, 6, 7); 
   gSP1Triangle(glistp++,3, 8, 4, 3); 
   gSP1Triangle(glistp++,9, 5, 7, 9); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x050e0d21);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x06690c70);
   gSP1Triangle(glistp++,2, 9, 10, 2); 
   gSP1Triangle(glistp++,9, 2, 11, 9); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0a6105ab);
   gSP1Triangle(glistp++,12, 3, 7, 12); 
   gSP1Triangle(glistp++,3, 12, 8, 3); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x05440f74);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x07a009da);
   gSP1Triangle(glistp++,6, 12, 7, 6); 
   gSP1Triangle(glistp++,0, 10, 3, 0); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0a6105ab);
   gSP1Triangle(glistp++,3, 9, 7, 3); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0b7c0306);
   gSP1Triangle(glistp++,11, 1, 5, 11); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0aad0180);
   gSP1Triangle(glistp++,9, 11, 5, 9); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x039b0bf5);
   gSP1Triangle(glistp++,0, 2, 10, 0); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x06690c70);
   gSP1Triangle(glistp++,3, 10, 9, 3); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0d5b01cd);
   gSP1Triangle(glistp++,11, 2, 1, 11); 

   gDPPipeSync(glistp++);

 } 
   

   
   
//------RIGHT ARM STANDARD
RigAnimation player_right_arm_lower_anim[] =
 { 
-16.205229, -0.068682, 48.616540,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.205229, -0.068682, 48.616540,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.206509, 0.674300, 48.838431,
    4.457815, 0.001911, -0.117731,
       1.000000, 1.000000, 1.000000,
 -16.217771, 2.617744, 49.418840,
    16.118278, 0.018728, -0.425685,
       1.000000, 1.000000, 1.000000,
 -16.250384, 4.561188, 49.999249,
    27.778748, 0.067426, -0.733638,
       1.000000, 1.000000, 1.000000,
 -16.305563, 5.304170, 50.221139,
    32.236563, 0.149821, -0.851370,
       1.000000, 1.000000, 1.000000,
 -16.507451, 2.879598, 49.541783,
    21.434329, 1.014305, -0.811358,
       1.000000, 1.000000, 1.000000,
 -16.850296, -3.184027, 47.754923,
    -5.972399, 2.731044, -0.466978,
       1.000000, 1.000000, 1.000000,
 -17.003067, -8.306860, 46.048695,
    -30.002624, 3.522186, 0.370667,
       1.000000, 1.000000, 1.000000,
 -16.317588, -11.862466, 44.359720,
    -46.356313, 1.552204, 1.967873,
       1.000000, 1.000000, 1.000000,
 -15.320939, -13.351098, 43.457368,
    -57.723322, -0.417778, 3.978157,
       1.000000, 1.000000, 1.000000,
 -14.884070, -13.310613, 43.909922,
    -64.985056, -0.416476, 6.114734,
       1.000000, 1.000000, 1.000000,
 -14.686677, -12.962168, 45.045471,
    -68.327437, -0.405272, 8.259695,
       1.000000, 1.000000, 1.000000,
 -14.656013, -12.114633, 46.013233,
    -68.870887, -0.378019, 9.059400,
       1.000000, 1.000000, 1.000000,
 -15.222256, -9.960888, 46.525863,
    -63.409550, 0.346727, 8.016398,
       1.000000, 1.000000, 1.000000,
 -16.433942, -6.067513, 46.887377,
    -47.720452, 2.028179, 5.446254,
       1.000000, 1.000000, 1.000000,
 -17.000185, -2.409520, 47.500968,
    -29.921232, 3.274738, 3.360584,
       1.000000, 1.000000, 1.000000,
 -16.998585, 0.700098, 48.543072,
    -11.366809, 3.849981, 2.529464,
       1.000000, 1.000000, 1.000000,
 -16.984816, 3.665033, 49.842748,
    9.810555, 4.086480, 2.159040,
       1.000000, 1.000000, 1.000000,
 -16.951324, 6.025665, 50.849247,
    27.963355, 4.113957, 0.875989,
       1.000000, 1.000000, 1.000000,
 -16.031726, 7.660715, 51.172304,
    41.895339, -0.566453, -2.113314,
       1.000000, 1.000000, 1.000000,
 -14.890765, 8.576780, 51.654780,
    51.828350, -5.246865, -5.287883,
       1.000000, 1.000000, 1.000000,
 -14.553805, 9.259132, 53.608370,
    60.481059, -4.971681, -7.527478,
       1.000000, 1.000000, 1.000000,
 -14.415272, 9.586907, 56.357014,
    66.804243, -4.152994, -9.167473,
       1.000000, 1.000000, 1.000000,
 -14.399175, 9.645522, 57.521939,
    68.741025, -3.169359, -9.670621,
       1.000000, 1.000000, 1.000000,
 -14.691329, 9.208985, 56.234938,
    61.802461, -1.846270, -8.449535,
       1.000000, 1.000000, 1.000000,
 -15.384252, 7.873324, 53.112817,
    44.113487, -0.301194, -5.436840,
       1.000000, 1.000000, 1.000000,
 -15.885255, 6.199076, 50.691152,
    28.416466, 0.313444, -2.983596,
       1.000000, 1.000000, 1.000000,
 -16.104580, 3.843331, 49.418360,
    15.595881, 0.237730, -1.424927,
       1.000000, 1.000000, 1.000000,
 -16.194752, 1.049353, 48.754674,
    4.062124, 0.075713, -0.326511,
       1.000000, 1.000000, 1.000000,
 -16.205229, -0.068682, 48.616540,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.205229, -0.068682, 48.616540,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.205229, -0.068682, 48.616540,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.205229, -0.068682, 48.616540,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.205229, -0.068682, 48.616540,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.183987, -0.243011, 48.714063,
    0.209848, -0.142009, 0.487636,
       1.000000, 1.000000, 1.000000,
 -16.114426, -0.830695, 48.989940,
    0.758754, -0.522007, 1.900244,
       1.000000, 1.000000, 1.000000,
 -16.007085, -1.773680, 49.321890,
    1.307661, -0.925041, 3.682713,
       1.000000, 1.000000, 1.000000,
 -15.890476, -2.844949, 49.560970,
    1.517509, -1.125206, 5.104042,
       1.000000, 1.000000, 1.000000,
 -15.767196, -4.114569, 49.674624,
    1.018307, -1.184743, 6.175164,
       1.000000, 1.000000, 1.000000,
 -15.622273, -5.712486, 49.710470,
    -0.857343, -1.219931, 7.148298,
       1.000000, 1.000000, 1.000000,
 -15.460816, -7.322312, 49.776524,
    -4.270580, -1.232082, 8.039499,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 49.966440,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.157750, -9.629185, 50.406075,
    -14.124583, -0.761132, 9.649563,
       1.000000, 1.000000, 1.000000,
 -15.039651, -10.421887, 51.104540,
    -21.158080, 0.622573, 10.247188,
       1.000000, 1.000000, 1.000000,
 -14.864656, -11.062274, 51.716727,
    -28.711527, 2.406173, 10.971029,
       1.000000, 1.000000, 1.000000,
 -14.582984, -11.684956, 51.938540,
    -35.497367, 3.888018, 12.035438,
       1.000000, 1.000000, 1.000000,
 -14.053129, -12.403478, 51.331955,
    -42.375272, 5.144356, 13.922216,
       1.000000, 1.000000, 1.000000,
 -13.383749, -13.043539, 49.770775,
    -48.957413, 6.350767, 16.230061,
       1.000000, 1.000000, 1.000000,
 -13.109721, -13.267706, 48.352993,
    -52.511731, 7.267025, 17.164122,
       1.000000, 1.000000, 1.000000,
 -13.305047, -12.889582, 47.129515,
    -53.992082, 7.944464, 16.246954,
       1.000000, 1.000000, 1.000000,
 -13.808368, -11.794788, 45.984125,
    -54.600700, 8.341402, 13.802509,
       1.000000, 1.000000, 1.000000,
 -14.266782, -10.536125, 45.571843,
    -54.671413, 8.438991, 11.400128,
       1.000000, 1.000000, 1.000000,
 -14.655402, -9.369433, 45.685524,
    -54.064830, 8.370641, 9.218343,
       1.000000, 1.000000, 1.000000,
 -15.073502, -8.104196, 46.062377,
    -51.924734, 8.141442, 6.793110,
       1.000000, 1.000000, 1.000000,
 -15.377240, -6.637904, 46.653721,
    -48.291391, 7.776214, 4.752916,
       1.000000, 1.000000, 1.000000,
 -15.477155, -4.963658, 47.308862,
    -43.915186, 7.364472, 3.543144,
       1.000000, 1.000000, 1.000000,
 -15.474410, -3.099369, 47.992563,
    -38.696331, 6.936376, 3.023407,
       1.000000, 1.000000, 1.000000,
 -15.450263, -1.002570, 48.787442,
    -32.134073, 6.440851, 2.930871,
       1.000000, 1.000000, 1.000000,
 -15.380336, 1.253124, 49.715468,
    -25.109606, 5.845207, 2.838336,
       1.000000, 1.000000, 1.000000,
 -15.262023, 3.518533, 50.735283,
    -18.723917, 5.164368, 2.318599,
       1.000000, 1.000000, 1.000000,
 -14.932801, 5.973630, 52.063233,
    -12.761437, 4.304515, 1.052373,
       1.000000, 1.000000, 1.000000,
 -14.268337, 8.540508, 53.565890,
    -7.092982, 3.307885, -1.125270,
       1.000000, 1.000000, 1.000000,
 -13.578454, 10.566726, 54.441965,
    -2.311475, 2.550834, -3.507052,
       1.000000, 1.000000, 1.000000,
 -12.891902, 11.931804, 54.807240,
    0.915679, 2.047616, -6.359005,
       1.000000, 1.000000, 1.000000,
 -12.160131, 12.761678, 54.957420,
    3.171535, 1.770385, -9.509086,
       1.000000, 1.000000, 1.000000,
 -11.604793, 13.562304, 54.974866,
    7.313079, 1.707601, -11.141699,
       1.000000, 1.000000, 1.000000,
 -11.219217, 14.681141, 54.551351,
    14.257129, 2.444800, -11.662232,
       1.000000, 1.000000, 1.000000,
 -11.001882, 15.776800, 53.645092,
    23.088676, 4.312553, -11.876238,
       1.000000, 1.000000, 1.000000,
 -10.951068, 16.180387, 53.221577,
    30.902136, 5.944417, -11.901103,
       1.000000, 1.000000, 1.000000,
 -11.142085, 15.823217, 53.717357,
    38.084841, 7.225586, -10.729334,
       1.000000, 1.000000, 1.000000,
 -11.626863, 14.806569, 54.778254,
    44.457128, 8.342896, -7.792606,
       1.000000, 1.000000, 1.000000,
 -12.052228, 13.671523, 55.274034,
    47.350273, 8.729401, -5.297544,
       1.000000, 1.000000, 1.000000,
 -12.327588, 12.587909, 54.947311,
    48.202663, 8.728066, -3.804578,
       1.000000, 1.000000, 1.000000,
 -12.554562, 11.362796, 53.985870,
    48.553110, 8.716571, -2.687085,
       1.000000, 1.000000, 1.000000,
 -12.790349, 10.075216, 52.850610,
    48.593825, 8.688613, -1.515193,
       1.000000, 1.000000, 1.000000,
 -13.026662, 9.057894, 51.447445,
    46.815746, 8.661669, -0.215369,
       1.000000, 1.000000, 1.000000,
 -13.247779, 8.274488, 49.616283,
    41.117493, 8.623595, 1.090877,
       1.000000, 1.000000, 1.000000,
 -13.508399, 6.958194, 48.136589,
    32.593588, 8.521128, 2.463135,
       1.000000, 1.000000, 1.000000,
 -13.844436, 4.595625, 47.620702,
    23.682296, 8.331628, 3.929601,
       1.000000, 1.000000, 1.000000,
 -14.389282, -0.098567, 48.250413,
    11.451297, 5.902302, 5.916000,
       1.000000, 1.000000, 1.000000,
 -15.036596, -6.135519, 49.597919,
    -2.920565, 1.021109, 8.071462,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 -15.295793, -8.621996, 50.227630,
    -8.651332, -1.233463, 8.903786,
       1.000000, 1.000000, 1.000000,
 
};


//------RIGHT ARM SHOOTING 
 //Test Object = 1 
RigAnimation player_right_arm_lower_shooting_anim[] =
 { 
-16.088949, -16.786911, 58.634357,
    -73.565092, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.088949, -16.786911, 58.634357,
    -73.565092, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.357468, -16.943125, 59.001884,
    -72.432947, 9.478299, 1.680667,
       1.000000, 1.000000, 1.000000,
 -17.059841, -17.351738, 59.963242,
    -69.471562, 34.271027, 6.076847,
       1.000000, 1.000000, 1.000000,
 -17.762215, -17.760351, 60.924595,
    -66.510183, 59.063753, 10.473026,
       1.000000, 1.000000, 1.000000,
 -18.030733, -17.916565, 61.292122,
    -65.378038, 68.542055, 12.153693,
       1.000000, 1.000000, 1.000000,
 -17.872261, -17.773758, 60.463703,
    -65.897235, 60.023238, 11.724913,
       1.000000, 1.000000, 1.000000,
 -17.413641, -17.468170, 58.405251,
    -67.330707, 41.794016, 10.536547,
       1.000000, 1.000000, 1.000000,
 -16.886786, -17.325363, 56.696026,
    -68.843874, 33.275199, 9.272932,
       1.000000, 1.000000, 1.000000,
 -16.285006, -18.627823, 55.586353,
    -70.669720, 44.245327, 7.729349,
       1.000000, 1.000000, 1.000000,
 -15.721906, -20.570129, 55.151409,
    -71.734144, 55.215458, 6.825283,
       1.000000, 1.000000, 1.000000,
 -15.325117, -21.546026, 55.725929,
    -71.633678, 54.865612, 8.825322,
       1.000000, 1.000000, 1.000000,
 -15.053156, -22.117933, 57.208206,
    -71.418691, 54.116982, 13.105154,
       1.000000, 1.000000, 1.000000,
 -14.974257, -22.258568, 58.562218,
    -71.318226, 53.767140, 15.105192,
       1.000000, 1.000000, 1.000000,
 -15.527308, -21.383272, 59.746227,
    -71.545979, 55.423894, 12.930206,
       1.000000, 1.000000, 1.000000,
 -16.710770, -19.510250, 60.864719,
    -72.033347, 59.847005, 8.276006,
       1.000000, 1.000000, 1.000000,
 -17.263821, -18.634954, 61.269241,
    -72.261100, 64.209775, 6.101019,
       1.000000, 1.000000, 1.000000,
 -17.259218, -18.825279, 61.218788,
    -63.712387, 68.657799, 13.353274,
       1.000000, 1.000000, 1.000000,
 -17.219604, -19.354429, 60.784527,
    -45.419208, 73.263334, 28.872197,
       1.000000, 1.000000, 1.000000,
 -17.123253, -19.920450, 59.728268,
    -36.870495, 75.005347, 36.124454,
       1.000000, 1.000000, 1.000000,
 -16.298388, -20.618742, 57.119316,
    -45.735350, 73.249585, 29.840816,
       1.000000, 1.000000, 1.000000,
 -15.389289, -21.029236, 55.280853,
    -57.723185, 68.931922, 21.002526,
       1.000000, 1.000000, 1.000000,
 -15.177461, -21.024052, 55.670795,
    -62.004478, 62.517719, 17.803151,
       1.000000, 1.000000, 1.000000,
 -15.090372, -20.979427, 56.775383,
    -63.764638, 54.863686, 16.704211,
       1.000000, 1.000000, 1.000000,
 -15.080254, -20.870888, 57.998108,
    -63.969141, 51.793833, 15.893218,
       1.000000, 1.000000, 1.000000,
 -15.369720, -20.469673, 59.486935,
    -63.292590, 55.769738, 15.173574,
       1.000000, 1.000000, 1.000000,
 -15.989141, -19.516474, 61.160950,
    -61.844849, 64.277681, 14.860861,
       1.000000, 1.000000, 1.000000,
 -16.278606, -18.348450, 61.816994,
    -61.168299, 68.253589, 13.573853,
       1.000000, 1.000000, 1.000000,
 -16.260216, -16.716274, 61.048218,
    -64.162783, 51.766724, 9.265486,
       1.000000, 1.000000, 1.000000,
 -16.198496, -14.803379, 59.403133,
    -70.570614, 16.486871, 2.794497,
       1.000000, 1.000000, 1.000000,
 -16.111168, -14.041369, 58.634357,
    -73.565099, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -16.010326, -14.093844, 58.641590,
    -73.426610, 0.410380, 0.221988,
       1.000000, 1.000000, 1.000000,
 -15.891088, -14.238626, 58.661541,
    -73.042746, 1.551048, 0.834460,
       1.000000, 1.000000, 1.000000,
 -15.757318, -14.459211, 58.691944,
    -72.454640, 3.304432, 1.767608,
       1.000000, 1.000000, 1.000000,
 -15.612304, -14.741664, 58.730869,
    -71.696885, 5.571916, 2.962478,
       1.000000, 1.000000, 1.000000,
 -15.458924, -15.073934, 58.776661,
    -70.799248, 8.268934, 4.368090,
       1.000000, 1.000000, 1.000000,
 -15.299755, -15.445362, 58.827850,
    -69.787895, 11.321413, 5.939356,
       1.000000, 1.000000, 1.000000,
 -15.137160, -15.846309, 58.883110,
    -68.686349, 14.663117, 7.635493,
       1.000000, 1.000000, 1.000000,
 -14.973360, -16.267860, 58.941208,
    -67.516188, 18.233572, 9.418794,
       1.000000, 1.000000, 1.000000,
 -14.810488, -16.701588, 59.000980,
    -66.297641, 21.976402, 11.253606,
       1.000000, 1.000000, 1.000000,
 -14.650642, -17.139343, 59.061314,
    -65.050100, 25.837916, 13.105459,
       1.000000, 1.000000, 1.000000,
 -14.495936, -17.573071, 59.121086,
    -63.792567, 29.765852, 14.940270,
       1.000000, 1.000000, 1.000000,
 -14.348543, -17.994621, 59.179184,
    -62.544076, 33.708192, 16.723571,
       1.000000, 1.000000, 1.000000,
 -14.210747, -18.395569, 59.234444,
    -61.324150, 37.611980, 18.419707,
       1.000000, 1.000000, 1.000000,
 -14.085001, -18.766998, 59.285633,
    -60.153237, 41.422054, 19.990975,
       1.000000, 1.000000, 1.000000,
 -13.973996, -19.099268, 59.331425,
    -59.053303, 45.079573, 21.396587,
       1.000000, 1.000000, 1.000000,
 -13.880745, -19.381720, 59.370350,
    -58.048439, 48.520342, 22.591459,
       1.000000, 1.000000, 1.000000,
 -13.808689, -19.602304, 59.400753,
    -57.165712, 51.672587, 23.524604,
       1.000000, 1.000000, 1.000000,
 -13.761844, -19.747086, 59.420704,
    -56.436262, 54.454131, 24.137076,
       1.000000, 1.000000, 1.000000,
 -13.744999, -19.799562, 59.427937,
    -55.896772, 56.768462, 24.359067,
       1.000000, 1.000000, 1.000000,
 -14.007298, -19.799433, 58.842815,
    -55.551175, 58.628295, 23.499904,
       1.000000, 1.000000, 1.000000,
 -14.655319, -19.798309, 57.590736,
    -55.409090, 59.771361, 20.921387,
       1.000000, 1.000000, 1.000000,
 -15.184986, -19.795576, 57.005615,
    -55.392581, 60.068652, 17.781096,
       1.000000, 1.000000, 1.000000,
 -15.531240, -19.790392, 57.272976,
    -57.638020, 59.919972, 13.774574,
       1.000000, 1.000000, 1.000000,
 -15.828778, -19.764236, 58.090614,
    -63.511498, 59.531068, 8.483313,
       1.000000, 1.000000, 1.000000,
 -16.010092, -19.689253, 59.227425,
    -69.384982, 59.142157, 4.183657,
       1.000000, 1.000000, 1.000000,
 -16.062941, -19.560806, 60.300514,
    -71.630420, 58.993478, 2.680394,
       1.000000, 1.000000, 1.000000,
 -16.036079, -19.353552, 61.524841,
    -70.446674, 60.565398, 4.490989,
       1.000000, 1.000000, 1.000000,
 -15.947162, -19.020283, 63.057259,
    -66.952998, 64.677124, 9.619086,
       1.000000, 1.000000, 1.000000,
 -15.807904, -18.595152, 64.270500,
    -62.387351, 68.788843, 15.805018,
       1.000000, 1.000000, 1.000000,
 -15.653962, -18.155994, 64.689102,
    -58.497449, 70.360763, 20.286053,
       1.000000, 1.000000, 1.000000,
 -15.555490, -17.697390, 64.661774,
    -54.524427, 69.855043, 23.364967,
       1.000000, 1.000000, 1.000000,
 -15.427505, -17.179251, 64.562317,
    -50.499612, 68.418176, 25.535569,
       1.000000, 1.000000, 1.000000,
 -15.051802, -16.649006, 64.408646,
    -48.992599, 66.819092, 26.181008,
       1.000000, 1.000000, 1.000000,
 -14.143352, -16.096365, 64.275864,
    -53.116762, 64.858172, 22.507130,
       1.000000, 1.000000, 1.000000,
 -12.824141, -15.526340, 64.094414,
    -61.941954, 62.647014, 14.645491,
       1.000000, 1.000000, 1.000000,
 -12.035044, -15.033121, 63.697460,
    -66.066125, 61.779457, 10.971613,
       1.000000, 1.000000, 1.000000,
 -11.747633, -14.551571, 63.063808,
    -66.049719, 61.989042, 11.047642,
       1.000000, 1.000000, 1.000000,
 -11.629471, -14.135595, 62.213528,
    -65.908546, 62.998489, 11.702024,
       1.000000, 1.000000, 1.000000,
 -11.615742, -13.992516, 61.343655,
    -65.565172, 64.937279, 13.293696,
       1.000000, 1.000000, 1.000000,
 -11.765149, -14.606724, 60.297794,
    -46.973622, 68.413866, 31.414881,
       1.000000, 1.000000, 1.000000,
 -12.150578, -16.147915, 59.197605,
    -7.783619, 72.931968, 67.440359,
       1.000000, 1.000000, 1.000000,
 -12.502556, -17.461433, 58.778481,
    10.480967, 75.351234, 84.045901,
       1.000000, 1.000000, 1.000000,
 -12.761962, -18.424871, 59.185928,
    2.832149, 76.056827, 77.077408,
       1.000000, 1.000000, 1.000000,
 -12.998162, -19.216936, 60.057819,
    -16.568342, 76.346912, 59.252315,
       1.000000, 1.000000, 1.000000,
 -13.205622, -19.481064, 60.465267,
    -33.566411, 76.380619, 43.303239,
       1.000000, 1.000000, 1.000000,
 -13.346576, -19.427525, 60.151348,
    -46.836653, 70.878471, 30.267215,
       1.000000, 1.000000, 1.000000,
 -13.419187, -19.276295, 59.330223,
    -60.281952, 56.486317, 16.595983,
       1.000000, 1.000000, 1.000000,
 -13.551859, -19.094877, 58.509094,
    -69.663128, 42.094162, 6.828613,
       1.000000, 1.000000, 1.000000,
 -13.844437, -18.965136, 58.195175,
    -72.673718, 36.592018, 3.647676,
       1.000000, 1.000000, 1.000000,
 -14.472614, -18.879726, 59.758789,
    -71.399806, 39.863077, 4.631947,
       1.000000, 1.000000, 1.000000,
 -15.292542, -18.823032, 63.104733,
    -68.673796, 46.862744, 6.738166,
       1.000000, 1.000000, 1.000000,
 
};



void player_right_arm_lower_animation()
 { 
	if(playerAvatar.playerShooting == true)
	{
		tempObjVectorPos = player_right_arm_lower_shooting_anim[animFrame].pos;
		tempObjVectorRot = player_right_arm_lower_shooting_anim[animFrame].rot;
		tempObjVectorScl = player_right_arm_lower_shooting_anim[animFrame].scl;
	}
 
	else
	{
	   tempObjVectorPos = player_right_arm_lower_anim[animFrame].pos;
	   tempObjVectorRot = player_right_arm_lower_anim[animFrame].rot;
	   tempObjVectorScl = player_right_arm_lower_anim[animFrame].scl;
	}
   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
	SetVector3(&playerAvatar.animRig.joint.armR[1].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.armR[1].rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.armR[1].scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z); 

 } 
void player_right_arm_lower_PolyList() 
 { 

		Vtx *player_right_arm_lower_VTXPointer = &player_right_arm_lower_VertList_0[0]; 

   gSPVertex(glistp++,player_right_arm_lower_VTXPointer+0,26,0);

//OBJECT: 2 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_right_arm_lower_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,0, 6, 7, 0); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0c1b016f);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0bd2032e);
   gSP1Triangle(glistp++,2, 8, 3, 2); 
   gSP1Triangle(glistp++,5, 6, 9, 5); 
   gSP1Triangle(glistp++,4, 10, 6, 4); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0d4b00ca);
   gSP1Triangle(glistp++,1, 11, 8, 1); 
   gSP1Triangle(glistp++,7, 10, 12, 7); 
   gSP1Triangle(glistp++,13, 12, 10, 13); 
   gSP1Triangle(glistp++,13, 14, 12, 13); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x102f035c);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0edc00ea);
   gSP1Triangle(glistp++,13, 11, 14, 13); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0b860895);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0b1d0981);
   gSP1Triangle(glistp++,7, 14, 1, 7); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x089505ee);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0a7106dd);
   gSP1Triangle(glistp++,8, 13, 4, 8); 
   gSP1Triangle(glistp++,0, 7, 1, 0); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x07eb06cd);
   gSP1Triangle(glistp++,3, 8, 4, 3); 
   gSP1Triangle(glistp++,0, 9, 6, 0); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0d4b00ca);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0d640363);
   gSP1Triangle(glistp++,2, 1, 8, 2); 
   gSP1Triangle(glistp++,5, 4, 6, 5); 
   gSP1Triangle(glistp++,4, 13, 10, 4); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0edc00ea);
   gSP1Triangle(glistp++,1, 14, 11, 1); 
   gSP1Triangle(glistp++,7, 6, 10, 7); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0b860895);
   gSP1Triangle(glistp++,7, 12, 14, 7); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x102f035c);
   gSP1Triangle(glistp++,8, 11, 13, 8); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0e630680);           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0bb205cb);           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x0d2c0769);
   gSP1Triangle(glistp++,21, 17, 16, 21); 
           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x0d720221);
   gSP1Triangle(glistp++,20, 17, 21, 20); 
   gSPVertex(glistp++,player_right_arm_lower_VTXPointer+15,26,0);
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0d720221);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0c26025a);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0bb205cb);
   gSP1Triangle(glistp++,5, 3, 2, 5); 
   gSPVertex(glistp++,player_right_arm_lower_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x09980185);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x08ad03e9);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0c250185);
   gSP1Triangle(glistp++,2, 3, 0, 2); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0b2c0530);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0cdf03c0);
   gSP1Triangle(glistp++,5, 9, 0, 5); 
   gSP1Triangle(glistp++,3, 5, 0, 3); 


//OBJECT: 2 MATERIAL NO. 12 'player_limb2'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb2, player_limb2_tlut, 6,1);

   gSPVertex(glistp++,player_right_arm_lower_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,15, 16, 17, 15); 
   gSP1Triangle(glistp++,15, 17, 18, 15); 
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSP1Triangle(glistp++,15, 23, 16, 15); 
   gSP1Triangle(glistp++,16, 24, 21, 16); 
   gSP1Triangle(glistp++,24, 19, 21, 24); 
   gSPVertex(glistp++,player_right_arm_lower_VTXPointer+15,26,0);
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0b5f0ccc);
   gSP1Triangle(glistp++,0, 11, 8, 0); 
   gSP1Triangle(glistp++,1, 8, 9, 1); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x04010d45);
   gSP1Triangle(glistp++,9, 10, 4, 9); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x07360f39);
   gSP1Triangle(glistp++,10, 9, 8, 10); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x05460ffd);
   gSP1Triangle(glistp++,11, 10, 8, 11); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x03960f64);
   gSP1Triangle(glistp++,10, 11, 7, 10); 


//OBJECT: 2 MATERIAL NO. 13 'player_glow'OK 

	gSPSetLights2(glistp++, glowLight);


   TEXTURE_4B_TLUT_CLAMP(player_glow, player_glow_tlut, 6,1);

   gSPVertex(glistp++,player_right_arm_lower_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x0f620ec8);           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x0f660c53);
   gSP1Triangle(glistp++,20, 22, 18, 20); 
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x08a70f65);
   gSP1Triangle(glistp++,19, 22, 20, 19); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x07a009fa);
   gSP1Triangle(glistp++,15, 18, 22, 15); 
   gSP1Triangle(glistp++,22, 19, 25, 22); 
   gSPVertex(glistp++,player_right_arm_lower_VTXPointer+15,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x07a009fa);
   gSP1Triangle(glistp++,0, 7, 11, 0); 
   
   		gSPSetLights2(glistp++, player_lighting);

   gDPPipeSync(glistp++);

 } 
 
 
//RIGHT ARM SHOOTING 
 
 
 
 
 
 //Test Object = 7 
RigAnimation player_left_arm_anim[] =
 { 
8.759880, -0.068682, 62.956840,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 8.759880, -0.068682, 62.956840,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 8.727095, -0.787086, 62.788540,
    0.043461, -0.001174, -0.309680,
       1.000000, 1.000000, 1.000000,
 8.641338, -2.666243, 62.280446,
    0.425810, -0.011505, -1.119720,
       1.000000, 1.000000, 1.000000,
 8.555580, -4.545398, 61.589241,
    1.533055, -0.041421, -1.929760,
       1.000000, 1.000000, 1.000000,
 8.522795, -5.263803, 60.958678,
    3.406478, -0.092038, -2.239440,
       1.000000, 1.000000, 1.000000,
 8.555203, -4.819063, 60.486883,
    15.278401, -1.161944, -2.181269,
       1.000000, 1.000000, 1.000000,
 8.649761, -3.867375, 59.987229,
    41.880268, -3.369614, -1.680595,
       1.000000, 1.000000, 1.000000,
 8.759880, -3.422635, 59.151161,
    65.107836, -4.394464, -0.462790,
       1.000000, 1.000000, 1.000000,
 8.878996, -4.039196, 57.397735,
    83.599897, 0.512394, 2.195548,
       1.000000, 1.000000, 1.000000,
 9.008436, -4.677114, 56.246054,
    92.115667, 5.419252, 5.114406,
       1.000000, 1.000000, 1.000000,
 9.153268, -4.706392, 57.017040,
    90.126498, 3.788989, 6.956786,
       1.000000, 1.000000, 1.000000,
 9.297644, -4.718430, 58.875257,
    83.633986, -0.151102, 8.176556,
       1.000000, 1.000000, 1.000000,
 9.351289, -4.719828, 60.288632,
    74.752500, -3.173219, 8.519216,
       1.000000, 1.000000, 1.000000,
 9.264033, -4.479876, 60.966873,
    64.094461, -4.622203, 7.447665,
       1.000000, 1.000000, 1.000000,
 9.052871, -3.966407, 61.251998,
    50.857705, -5.257622, 4.751449,
       1.000000, 1.000000, 1.000000,
 8.890262, -3.726455, 61.287856,
    38.021163, -5.504740, 2.436930,
       1.000000, 1.000000, 1.000000,
 8.834746, -4.066734, 60.866058,
    26.298131, -5.704257, 0.961848,
       1.000000, 1.000000, 1.000000,
 8.825144, -4.969533, 59.654915,
    14.871040, -5.786283, -0.199204,
       1.000000, 1.000000, 1.000000,
 8.759880, -5.848157, 58.281994,
    3.559935, -5.795813, -1.236254,
       1.000000, 1.000000, 1.000000,
 8.592271, -6.593463, 56.431335,
    -10.901343, -0.571540, -2.023308,
       1.000000, 1.000000, 1.000000,
 8.372251, -7.250494, 55.309272,
    -18.772249, 4.652732, -2.999172,
       1.000000, 1.000000, 1.000000,
 8.117247, -7.832278, 55.895644,
    -18.830744, 4.407236, -5.068771,
       1.000000, 1.000000, 1.000000,
 7.850277, -8.309084, 57.393825,
    -18.854795, 3.702547, -7.588650,
       1.000000, 1.000000, 1.000000,
 7.748792, -8.467760, 58.730543,
    -18.857587, 2.904172, -8.606837,
       1.000000, 1.000000, 1.000000,
 7.922100, -7.905594, 59.664690,
    -13.392059, 1.967819, -7.599350,
       1.000000, 1.000000, 1.000000,
 8.326303, -6.355462, 60.476106,
    -1.696511, 0.901505, -5.087701,
       1.000000, 1.000000, 1.000000,
 8.602400, -4.723149, 61.198390,
    3.769018, 0.313444, -2.983596,
       1.000000, 1.000000, 1.000000,
 8.710345, -2.871057, 61.989361,
    2.858600, 0.098594, -1.517106,
       1.000000, 1.000000, 1.000000,
 8.754724, -0.850627, 62.704349,
    0.910418, 0.010263, -0.369872,
       1.000000, 1.000000, 1.000000,
 8.759880, -0.068682, 62.956840,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 8.759880, -0.068682, 62.956840,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 8.759880, -0.068682, 62.956840,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 8.759880, -0.068682, 62.956840,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 8.759880, -0.068682, 62.956840,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 8.757374, -0.167079, 63.102859,
    2.945124, -0.022290, 0.508383,
       1.000000, 1.000000, 1.000000,
 8.749045, -0.442261, 63.504702,
    11.369910, -0.125600, 1.969003,
       1.000000, 1.000000, 1.000000,
 8.735921, -0.765469, 63.960189,
    21.740373, -0.350344, 3.782607,
       1.000000, 1.000000, 1.000000,
 8.721315, -0.985107, 64.241648,
    29.597242, -0.679188, 5.182079,
       1.000000, 1.000000, 1.000000,
 8.702183, -1.111169, 64.364839,
    35.073817, -1.121737, 6.169204,
       1.000000, 1.000000, 1.000000,
 8.676738, -1.189609, 64.416051,
    39.640096, -1.708435, 7.001113,
       1.000000, 1.000000, 1.000000,
 8.654790, -1.220023, 64.439827,
    43.399435, -2.347808, 7.741482,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.493763,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.641893, -1.084445, 64.596891,
    50.448440, -3.529428, 9.120165,
       1.000000, 1.000000, 1.000000,
 8.641432, -0.671241, 64.729458,
    53.931365, -4.203768, 9.566162,
       1.000000, 1.000000, 1.000000,
 8.640971, -0.134046, 64.835817,
    56.275554, -4.703999, 10.250798,
       1.000000, 1.000000, 1.000000,
 8.638382, 0.319362, 64.872760,
    57.010397, -4.870569, 11.475882,
       1.000000, 1.000000, 1.000000,
 8.609726, 0.774344, 64.195198,
    57.010390, -4.870569, 13.899663,
       1.000000, 1.000000, 1.000000,
 8.553828, 1.230117, 62.554109,
    57.010397, -4.870568, 16.997728,
       1.000000, 1.000000, 1.000000,
 8.528157, 1.399865, 61.287212,
    57.010397, -4.870569, 18.271101,
       1.000000, 1.000000, 1.000000,
 8.573628, 1.021329, 60.635227,
    56.745464, -4.670385, 17.479062,
       1.000000, 1.000000, 1.000000,
 8.670931, 0.032446, 60.309982,
    55.952251, -4.152299, 15.284532,
       1.000000, 1.000000, 1.000000,
 8.716402, -0.897440, 60.247338,
    54.989747, -3.675555, 12.952276,
       1.000000, 1.000000, 1.000000,
 8.691896, -1.735388, 60.501099,
    54.344359, -3.389750, 10.718386,
       1.000000, 1.000000, 1.000000,
 8.620958, -2.673118, 61.234176,
    53.879671, -3.191660, 8.184066,
       1.000000, 1.000000, 1.000000,
 8.531576, -3.371175, 62.154269,
    52.738127, -2.899092, 5.794530,
       1.000000, 1.000000, 1.000000,
 8.460509, -3.604084, 62.880141,
    50.384062, -2.374780, 3.926138,
       1.000000, 1.000000, 1.000000,
 8.413713, -3.529044, 63.484704,
    43.437995, -1.564567, 2.755653,
       1.000000, 1.000000, 1.000000,
 8.378457, -3.332759, 64.097375,
    29.219454, -0.480757, 2.224054,
       1.000000, 1.000000, 1.000000,
 8.336388, -3.136474, 64.549690,
    12.802828, 0.625675, 1.635095,
       1.000000, 1.000000, 1.000000,
 8.272392, -3.061433, 64.749444,
    0.307824, 1.492997, 0.319806,
       1.000000, 1.000000, 1.000000,
 8.191112, -3.138054, 64.800757,
    -8.175561, 2.198602, -1.806985,
       1.000000, 1.000000, 1.000000,
 8.087876, -3.334535, 64.812499,
    -14.351266, 2.717365, -4.605651,
       1.000000, 1.000000, 1.000000,
 7.957453, -3.511406, 64.843404,
    -19.516904, 2.877026, -7.485448,
       1.000000, 1.000000, 1.000000,
 7.785426, -3.660952, 64.926124,
    -24.029659, 2.851412, -10.538637,
       1.000000, 1.000000, 1.000000,
 7.583459, -3.798960, 65.028834,
    -27.435569, 2.630959, -13.730792,
       1.000000, 1.000000, 1.000000,
 7.430652, -3.848255, 65.070629,
    -31.034611, 2.094743, -16.100177,
       1.000000, 1.000000, 1.000000,
 7.331147, -3.766290, 64.344645,
    -36.185536, 0.831114, -17.646943,
       1.000000, 1.000000, 1.000000,
 7.278033, -3.590894, 62.530482,
    -41.616787, -0.945912, -18.400101,
       1.000000, 1.000000, 1.000000,
 7.266557, -3.508928, 61.001033,
    -43.688014, -1.698938, -18.538564,
       1.000000, 1.000000, 1.000000,
 7.345995, -3.915217, 59.914398,
    -41.361717, -0.776188, -17.853571,
       1.000000, 1.000000, 1.000000,
 7.549188, -4.917252, 59.047794,
    -34.586230, 1.653266, -15.908718,
       1.000000, 1.000000, 1.000000,
 7.730988, -5.732371, 58.764625,
    -26.719102, 3.978210, -13.747008,
       1.000000, 1.000000, 1.000000,
 7.845080, -6.248404, 58.893508,
    -18.060536, 5.949038, -11.729050,
       1.000000, 1.000000, 1.000000,
 7.941313, -6.610435, 59.220225,
    -8.054904, 7.894298, -9.454438,
       1.000000, 1.000000, 1.000000,
 8.069948, -6.717639, 59.506083,
    -0.200629, 9.306228, -6.948503,
       1.000000, 1.000000, 1.000000,
 8.274937, -6.469864, 59.646434,
    4.326625, 10.253621, -4.117410,
       1.000000, 1.000000, 1.000000,
 8.545217, -5.723964, 59.708083,
    6.287511, 10.813557, -0.922911,
       1.000000, 1.000000, 1.000000,
 8.764678, -4.714233, 59.840685,
    8.598027, 11.006911, 2.113862,
       1.000000, 1.000000, 1.000000,
 8.841378, -3.800429, 60.160136,
    14.007899, 11.028890, 4.546781,
       1.000000, 1.000000, 1.000000,
 8.793817, -2.765526, 61.487776,
    25.706580, 7.658687, 6.590489,
       1.000000, 1.000000, 1.000000,
 8.692043, -1.652820, 63.747495,
    40.681092, 0.446873, 8.055659,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 8.644482, -1.224845, 64.754957,
    46.838931, -2.923331, 8.497514,
       1.000000, 1.000000, 1.000000,
 
};
void player_left_arm_animation()
 { 
   tempObjVectorPos = player_left_arm_anim[animFrame].pos;
   tempObjVectorRot = player_left_arm_anim[animFrame].rot;
   tempObjVectorScl = player_left_arm_anim[animFrame].scl;

   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
	SetVector3(&playerAvatar.animRig.joint.armL[0].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.armL[0].rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.armL[0].scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z); 

 } 
void player_left_arm_PolyList() 
 { 

   Vtx *player_left_arm_VTXPointer = &player_left_arm_VertList_0[0]; 

   gSPVertex(glistp++,player_left_arm_VTXPointer+0,26,0);

//OBJECT: 7 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_left_arm_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x034506ee);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x063a07bc);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x04a6050c);
   gSP1Triangle(glistp++,2, 6, 3, 2); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x075b0408);
   gSP1Triangle(glistp++,3, 6, 8, 3); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x092e04d8);
   gSP1Triangle(glistp++,8, 6, 12, 8); 


//OBJECT: 7 MATERIAL NO. 12 'player_limb1'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb1, player_limb1_tlut, 6,1);

   gSPVertex(glistp++,player_left_arm_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,0, 3, 4, 0); 
   gSP1Triangle(glistp++,2, 3, 0, 2); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0eba0950);
   gSP1Triangle(glistp++,5, 6, 2, 5); 
   gSP1Triangle(glistp++,7, 6, 5, 7); 
   gSP1Triangle(glistp++,4, 3, 8, 4); 
   gSP1Triangle(glistp++,9, 7, 5, 9); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x048a0df0);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x062f0d5e);
   gSP1Triangle(glistp++,1, 10, 9, 1); 
   gSP1Triangle(glistp++,9, 11, 1, 9); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0bc00654);
   gSP1Triangle(glistp++,12, 7, 4, 12); 
   gSP1Triangle(glistp++,4, 8, 12, 4); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0624085c);           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x07070c3a);
   gSP1Triangle(glistp++,6, 7, 12, 6); 
   gSP1Triangle(glistp++,0, 4, 10, 0); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0bc00654);
   gSP1Triangle(glistp++,4, 7, 9, 4); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0c4e01e8);
   gSP1Triangle(glistp++,11, 5, 2, 11); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0bd70000);
   gSP1Triangle(glistp++,9, 5, 11, 9); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x03160c62);
   gSP1Triangle(glistp++,0, 10, 1, 0); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x062f0d5e);
   gSP1Triangle(glistp++,4, 9, 10, 4); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0eb60114);
   gSP1Triangle(glistp++,11, 2, 1, 11); 

   gDPPipeSync(glistp++);

 } 
 
  
 //Test Object = 3 
RigAnimation player_left_arm_lower_anim[] =
 { 
15.146063, -0.068682, 48.446280,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 15.146063, -0.068682, 48.446280,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 15.120476, -0.702581, 48.174933,
    -2.976248, 0.009526, -0.227759,
       1.000000, 1.000000, 1.000000,
 15.053549, -2.360694, 47.465160,
    -10.761327, 0.034444, -0.823516,
       1.000000, 1.000000, 1.000000,
 14.986622, -4.018806, 46.755388,
    -18.546409, 0.059362, -1.419273,
       1.000000, 1.000000, 1.000000,
 14.961036, -4.652705, 46.484041,
    -21.522659, 0.068888, -1.647032,
       1.000000, 1.000000, 1.000000,
 15.139864, -1.394035, 47.742462,
    -15.161702, -1.009249, -1.608258,
       1.000000, 1.000000, 1.000000,
 15.522538, 5.786461, 50.890207,
    2.790773, -3.316328, -1.274529,
       1.000000, 1.000000, 1.000000,
 15.701367, 9.684277, 53.550786,
    22.532442, -4.394464, -0.462790,
       1.000000, 1.000000, 1.000000,
 14.976482, 10.255486, 55.236638,
    47.978783, 0.512394, 2.047446,
       1.000000, 1.000000, 1.000000,
 14.098495, 10.337088, 56.176209,
    63.174981, 5.419252, 5.114406,
       1.000000, 1.000000, 1.000000,
 13.888609, 10.329369, 56.625628,
    63.020953, 3.788989, 6.956786,
       1.000000, 1.000000, 1.000000,
 13.802318, 10.262943, 56.810397,
    61.695248, -0.151102, 8.176556,
       1.000000, 1.000000, 1.000000,
 13.792293, 10.101371, 56.831867,
    58.470702, -3.173219, 8.519216,
       1.000000, 1.000000, 1.000000,
 14.200953, 9.510415, 55.809611,
    52.575924, -4.622203, 7.447665,
       1.000000, 1.000000, 1.000000,
 15.191220, 7.896169, 53.113151,
    42.716471, -5.257622, 4.751449,
       1.000000, 1.000000, 1.000000,
 15.956792, 5.520183, 50.522006,
    31.200137, -5.504740, 2.436930,
       1.000000, 1.000000, 1.000000,
 16.353332, 2.498336, 48.458678,
    19.036979, -5.704257, 0.961848,
       1.000000, 1.000000, 1.000000,
 16.553913, -1.326190, 46.431461,
    5.098725, -5.786283, -0.199204,
       1.000000, 1.000000, 1.000000,
 16.593540, -5.116009, 44.518363,
    -9.749262, -5.795813, -1.236254,
       1.000000, 1.000000, 1.000000,
 15.159063, -9.247265, 42.264730,
    -26.539906, -0.571540, -2.023308,
       1.000000, 1.000000, 1.000000,
 13.371448, -12.188436, 41.097844,
    -41.977584, 4.652732, -2.999172,
       1.000000, 1.000000, 1.000000,
 12.887330, -13.399589, 41.738525,
    -55.056751, 4.407236, -5.068771,
       1.000000, 1.000000, 1.000000,
 12.688296, -13.897528, 43.340424,
    -65.596611, 3.702547, -7.588650,
       1.000000, 1.000000, 1.000000,
 12.665170, -13.955382, 44.692913,
    -69.065063, 2.904172, -8.606837,
       1.000000, 1.000000, 1.000000,
 13.176307, -12.140550, 45.505083,
    -60.870871, 1.967819, -7.599350,
       1.000000, 1.000000, 1.000000,
 14.311513, -7.683048, 46.105900,
    -40.481613, 0.901505, -5.087701,
       1.000000, 1.000000, 1.000000,
 14.950377, -4.098878, 46.684489,
    -23.487673, 0.313444, -2.983596,
       1.000000, 1.000000, 1.000000,
 15.084510, -1.922072, 47.435290,
    -11.829579, 0.098594, -1.517106,
       1.000000, 1.000000, 1.000000,
 15.139656, -0.476151, 48.173705,
    -2.858352, 0.010263, -0.369872,
       1.000000, 1.000000, 1.000000,
 15.146063, -0.068682, 48.446280,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 15.146063, -0.068682, 48.446280,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 15.146063, -0.068682, 48.446280,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 15.146063, -0.068682, 48.446280,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 15.146063, -0.068682, 48.446280,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 15.098947, 0.620113, 48.738065,
    2.149435, 0.021494, 0.503042,
       1.000000, 1.000000, 1.000000,
 14.956349, 2.580847, 49.600762,
    8.198184, 0.077716, 1.956688,
       1.000000, 1.000000, 1.000000,
 14.761531, 4.970660, 50.731808,
    15.397403, 0.133938, 3.782193,
       1.000000, 1.000000, 1.000000,
 14.582589, 6.742641, 51.701033,
    20.451137, 0.155432, 5.223972,
       1.000000, 1.000000, 1.000000,
 14.421728, 7.890046, 52.520287,
    23.678604, -0.033134, 6.277334,
       1.000000, 1.000000, 1.000000,
 14.251538, 8.752421, 53.348994,
    26.100798, -0.529337, 7.200901,
       1.000000, 1.000000, 1.000000,
 14.072405, 9.472502, 54.152006,
    27.372526, -1.033542, 8.060363,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 54.906404,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.738187, 11.151206, 55.740404,
    27.446055, -1.258268, 9.784319,
       1.000000, 1.000000, 1.000000,
 13.616551, 12.063161, 56.652170,
    26.793046, -1.261110, 10.522215,
       1.000000, 1.000000, 1.000000,
 13.428545, 12.912942, 57.321274,
    26.140046, -1.263951, 11.413356,
       1.000000, 1.000000, 1.000000,
 13.110216, 13.646503, 57.542694,
    25.890399, -1.279911, 12.632639,
       1.000000, 1.000000, 1.000000,
 12.495580, 14.364098, 56.888300,
    29.661029, -2.115240, 14.697575,
       1.000000, 1.000000, 1.000000,
 11.712953, 14.961606, 55.273300,
    38.862895, -4.099460, 17.190982,
       1.000000, 1.000000, 1.000000,
 11.391696, 15.162499, 53.957146,
    46.126617, -5.625795, 18.195421,
       1.000000, 1.000000, 1.000000,
 11.620426, 14.703381, 53.118593,
    50.230376, -6.403432, 17.214179,
       1.000000, 1.000000, 1.000000,
 12.218866, 13.468949, 52.525604,
    52.676458, -6.779557, 14.565797,
       1.000000, 1.000000, 1.000000,
 12.783545, 12.233113, 52.348816,
    53.306047, -6.847777, 11.893336,
       1.000000, 1.000000, 1.000000,
 13.295589, 11.368088, 52.563351,
    53.327317, -6.841103, 9.197768,
       1.000000, 1.000000, 1.000000,
 13.870801, 10.638408, 53.124511,
    53.339881, -6.782382, 5.986196,
       1.000000, 1.000000, 1.000000,
 14.299974, 9.615668, 53.685677,
    53.344221, -6.612331, 3.489337,
       1.000000, 1.000000, 1.000000,
 14.443356, 8.010829, 53.900212,
    53.344713, -6.324610, 2.598019,
       1.000000, 1.000000, 1.000000,
 14.441244, 5.743171, 53.371608,
    48.344537, -5.707578, 2.557209,
       1.000000, 1.000000, 1.000000,
 14.422663, 2.817651, 51.988918,
    34.046475, -4.557607, 2.549942,
       1.000000, 1.000000, 1.000000,
 14.368856, -0.270854, 50.606227,
    16.459581, -3.199169, 2.542676,
       1.000000, 1.000000, 1.000000,
 14.277814, -2.949953, 50.077623,
    3.156956, -2.055869, 2.501865,
       1.000000, 1.000000, 1.000000,
 14.038099, -5.270810, 50.172246,
    -5.883280, -0.934174, 1.449901,
       1.000000, 1.000000, 1.000000,
 13.538884, -7.324610, 50.471216,
    -12.868207, 0.130520, -1.333866,
       1.000000, 1.000000, 1.000000,
 12.969069, -9.059332, 50.863272,
    -18.582032, 0.516541, -4.244223,
       1.000000, 1.000000, 1.000000,
 12.329766, -10.529052, 51.439667,
    -22.722409, 0.513684, -7.252827,
       1.000000, 1.000000, 1.000000,
 11.603066, -11.674814, 52.133095,
    -25.436072, 0.489094, -10.505536,
       1.000000, 1.000000, 1.000000,
 11.051001, -12.679631, 52.412051,
    -30.115400, 0.429284, -12.453209,
       1.000000, 1.000000, 1.000000,
 10.679976, -13.800903, 52.285194,
    -38.038826, -0.679856, -13.340102,
       1.000000, 1.000000, 1.000000,
 10.474058, -14.793703, 51.723570,
    -47.940746, -3.257417, -13.704729,
       1.000000, 1.000000, 1.000000,
 10.426933, -15.140198, 50.702226,
    -56.084394, -5.257595, -13.747094,
       1.000000, 1.000000, 1.000000,
 10.621312, -15.034334, 49.069577,
    -62.687203, -6.325862, -12.661385,
       1.000000, 1.000000, 1.000000,
 11.101881, -14.481527, 46.937728,
    -67.741816, -6.890775, -10.008846,
       1.000000, 1.000000, 1.000000,
 11.495462, -13.369924, 45.391655,
    -69.346146, -7.011050, -7.908186,
       1.000000, 1.000000, 1.000000,
 11.729157, -11.677480, 44.543219,
    -67.599584, -6.670456, -7.017263,
       1.000000, 1.000000, 1.000000,
 11.889217, -9.404492, 44.194403,
    -62.198325, -5.704336, -6.635906,
       1.000000, 1.000000, 1.000000,
 11.990373, -7.246625, 44.153875,
    -55.322955, -4.632275, -5.781226,
       1.000000, 1.000000, 1.000000,
 12.048171, -5.522446, 44.166192,
    -48.600173, -3.397230, -4.354909,
       1.000000, 1.000000, 1.000000,
 12.058461, -4.036537, 44.274566,
    -41.156620, -1.830499, -2.585814,
       1.000000, 1.000000, 1.000000,
 12.068752, -2.320601, 44.588402,
    -31.828743, -0.581737, -0.528698,
       1.000000, 1.000000, 1.000000,
 12.126550, -0.015735, 45.119405,
    -20.349078, -0.149387, 1.624712,
       1.000000, 1.000000, 1.000000,
 12.597604, 3.826958, 47.868025,
    -2.307675, -0.413386, 4.510826,
       1.000000, 1.000000, 1.000000,
 13.484578, 8.418322, 52.891636,
    19.117872, -0.978310, 7.707060,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 13.888970, 10.260691, 55.167598,
    27.695700, -1.242308, 8.951894,
       1.000000, 1.000000, 1.000000,
 
};

void player_left_arm_lower_animation()
 { 
   tempObjVectorPos = player_left_arm_lower_anim[animFrame].pos;
   tempObjVectorRot = player_left_arm_lower_anim[animFrame].rot;
   tempObjVectorScl = player_left_arm_lower_anim[animFrame].scl;

   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
	SetVector3(&playerAvatar.animRig.joint.armL[1].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.armL[1].rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.armL[1].scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z); 

 } 
void player_left_arm_lower_PolyList() 
 { 

   Vtx *player_left_arm_lower_VTXPointer = &player_left_arm_lower_VertList_0[0]; 

   gSPVertex(glistp++,player_left_arm_lower_VTXPointer+0,26,0);

//OBJECT: 3 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_left_arm_lower_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,0, 6, 7, 0); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0b62016c);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0b110323);
   gSP1Triangle(glistp++,1, 3, 8, 1); 
   gSP1Triangle(glistp++,4, 9, 7, 4); 
   gSP1Triangle(glistp++,5, 7, 10, 5); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0c9000cf);
   gSP1Triangle(glistp++,2, 8, 11, 2); 
   gSP1Triangle(glistp++,6, 12, 10, 6); 
   gSP1Triangle(glistp++,13, 10, 12, 13); 
   gSP1Triangle(glistp++,13, 12, 14, 13); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0f5d0365);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0e1b00f6);
   gSP1Triangle(glistp++,13, 14, 11, 13); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0b1e0a71);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0bca0976);
   gSP1Triangle(glistp++,6, 2, 14, 6); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x08f005c7);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0ae5073f);
   gSP1Triangle(glistp++,8, 5, 13, 8); 
   gSP1Triangle(glistp++,0, 2, 6, 0); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x07fd06a6);
   gSP1Triangle(glistp++,3, 5, 8, 3); 
   gSP1Triangle(glistp++,0, 7, 9, 0); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0c9c035e);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0c9000cf);
   gSP1Triangle(glistp++,1, 8, 2, 1); 
   gSP1Triangle(glistp++,4, 7, 5, 4); 
   gSP1Triangle(glistp++,5, 10, 13, 5); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0e1b00f6);
   gSP1Triangle(glistp++,2, 11, 14, 2); 
   gSP1Triangle(glistp++,6, 10, 7, 6); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0bca0976);
   gSP1Triangle(glistp++,6, 14, 12, 6); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0f5d0365);
   gSP1Triangle(glistp++,8, 13, 11, 8); 
           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x0e670221);           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0d480101);           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x0b850275);
   gSP1Triangle(glistp++,20, 17, 16, 20); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0cc70681);
   gSP1Triangle(glistp++,21, 20, 16, 21); 
   gSPVertex(glistp++,player_left_arm_lower_VTXPointer+15,26,0);
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x0cc70681);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0b850275);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0b790614);
   gSP1Triangle(glistp++,6, 1, 3, 6); 
   gSPVertex(glistp++,player_left_arm_lower_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x09b00578);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0c440578);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x08c3030e);
   gSP1Triangle(glistp++,1, 0, 3, 1); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x0b4901c3);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0d000337);
   gSP1Triangle(glistp++,4, 0, 9, 4); 
   gSP1Triangle(glistp++,3, 0, 4, 3); 


//OBJECT: 3 MATERIAL NO. 9 'player_glow'OK 

	gSPSetLights2(glistp++, glowLight);


   TEXTURE_4B_TLUT_CLAMP(player_glow, player_glow_tlut, 6,1);

   gSPVertex(glistp++,player_left_arm_lower_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0ff20e81);           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x0ff20c17);
   gSP1Triangle(glistp++,21, 18, 22, 21); 
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x09020f89);
   gSP1Triangle(glistp++,19, 21, 22, 19); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x07f10979);
   gSP1Triangle(glistp++,15, 22, 18, 15); 
   gSP1Triangle(glistp++,22, 25, 19, 22); 
   gSPVertex(glistp++,player_left_arm_lower_VTXPointer+15,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x07f10979);
   gSP1Triangle(glistp++,0, 11, 7, 0); 

		gSPSetLights2(glistp++, player_lighting);
//OBJECT: 3 MATERIAL NO. 12 'player_limb2'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb2, player_limb2_tlut, 6,1);

   gSPVertex(glistp++,player_left_arm_lower_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,15, 16, 17, 15); 
   gSP1Triangle(glistp++,15, 18, 16, 15); 
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSP1Triangle(glistp++,15, 17, 23, 15); 
   gSP1Triangle(glistp++,17, 20, 24, 17); 
   gSP1Triangle(glistp++,24, 20, 19, 24); 
   gSPVertex(glistp++,player_left_arm_lower_VTXPointer+15,26,0);
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0b3a0c9e);
   gSP1Triangle(glistp++,0, 8, 11, 0); 
   gSP1Triangle(glistp++,2, 9, 8, 2); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x03d80cf4);
   gSP1Triangle(glistp++,9, 4, 10, 9); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x09d70fff);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x07af0e7d);
   gSP1Triangle(glistp++,10, 8, 9, 10); 
   gSP1Triangle(glistp++,11, 8, 10, 11); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0b9c0ec1);
   gSP1Triangle(glistp++,10, 7, 11, 10); 

   gDPPipeSync(glistp++);

 } 
 
 
 //Test Object = 8 
RigAnimation player_right_leg_anim[] =
 { 
-3.973472, -0.068679, 42.821062,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.821062,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.740744,
    1.252882, 0.000000, -0.503563,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.467663,
    4.968398, 0.000000, -1.938784,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.024618,
    9.866520, 0.000000, -3.692476,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.515240,
    14.104830, 0.000000, -5.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.973532,
    17.898186, 0.000000, -5.981351,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.292075,
    21.744925, 0.000000, -6.751271,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.425930,
    24.878214, 0.000000, -7.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 37.976670,
    27.466762, 0.000000, -6.292809,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 37.075451,
    28.476928, 0.000000, -4.999999,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 38.200468,
    18.257637, 0.000000, -3.755432,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.607864,
    -6.516107, -0.000000, -2.480092,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.732880,
    -25.692407, -0.000000, -2.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.732880,
    -35.108965, -0.000000, -2.520854,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.732880,
    -39.577316, -0.000000, -3.842083,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.732880,
    -41.822399, -0.000000, -4.999999,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.419652,
    -43.697498, -0.000000, -5.916362,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.496600,
    -44.468401, -0.000000, -6.720700,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.404166,
    -44.557972, -0.000000, -7.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 37.843424,
    -40.095406, -0.000000, -6.292809,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 36.879578,
    -31.316349, -0.000000, -4.999999,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 37.783164,
    -23.396839, -0.000000, -3.755432,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.882627,
    -14.857140, -0.000000, -2.480092,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.297606,
    -6.953718, -0.000000, -2.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.772550,
    1.634829, 0.000000, -2.724660,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.923434,
    9.812625, 0.000000, -4.275341,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.081097,
    12.782440, 0.000000, -4.999999,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.391849,
    9.694802, 0.000000, -3.792234,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.704418,
    3.087638, 0.000000, -1.207766,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.821062,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.821062,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.821062,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.821062,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.821062,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.999375,
    0.848619, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.465799,
    3.242456, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.932223,
    6.105970, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.110537,
    8.140260, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.047797,
    9.230298, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.883681,
    9.785026, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.719569,
    10.304824, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.656829,
    11.306677, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.714938,
    12.903510, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.866932,
    14.964869, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.018930,
    17.021390, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.077039,
    18.606006, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.396506,
    19.831128, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.752079,
    20.657299, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.491498,
    20.893455, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.863434,
    20.697620, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.572519,
    19.773655, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.524508,
    18.021435, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.815065,
    16.002556, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.644550,
    13.625635, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.661465,
    10.208503, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 42.425174,
    5.563671, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.010592,
    -0.678199, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.561152,
    -8.695373, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.924278,
    -16.812601, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.036546,
    -23.307054, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.036546,
    -28.090203, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.036546,
    -31.500921, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.036546,
    -34.456853, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.036546,
    -37.822845, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.036546,
    -40.755179, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 44.036546,
    -41.768902, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.121889,
    -38.189790, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.050938,
    -30.530946, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.785790,
    -26.951838, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.417720,
    -27.344953, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.266393,
    -28.186176, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.248812,
    -28.579292, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 39.598966,
    -27.088209, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.348253,
    -22.916492, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.698406,
    -18.401486, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.698406,
    -14.161917, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.698406,
    -9.446258, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.698406,
    -4.684183, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 40.698406,
    -0.327440, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 41.476113,
    4.462617, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.140313,
    9.029059, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -3.973472, -0.068679, 43.918020,
    10.688416, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 
};
void player_right_leg_animation()
 { 
   tempObjVectorPos = player_right_leg_anim[animFrame].pos;
   tempObjVectorRot = player_right_leg_anim[animFrame].rot;
   tempObjVectorScl = player_right_leg_anim[animFrame].scl;

   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
	SetVector3(&playerAvatar.animRig.joint.legR[0].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.legR[0].rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.legR[0].scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z); 

 } 
 
void player_right_leg_PolyList() 
 { 

   Vtx *player_right_leg_VTXPointer = &player_right_leg_VertList_0[0]; 

   gSPVertex(glistp++,player_right_leg_VTXPointer+0,26,0);

//OBJECT: 8 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_right_leg_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,6, 7, 0, 6); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x0fff0f6d);           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0d2e0fff);
   gSP1Triangle(glistp++,10, 4, 15, 10); 
   gSP1Triangle(glistp++,0, 7, 1, 0); 
   gSP1Triangle(glistp++,3, 15, 4, 3); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x0952014c);
   gSP1Triangle(glistp++,6, 16, 7, 6); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0fff0aee);
   gSP1Triangle(glistp++,10, 14, 4, 10); 


//OBJECT: 8 MATERIAL NO. 11 'player_limb1'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb1, player_limb1_tlut, 6,1);

   gSPVertex(glistp++,player_right_leg_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x03b30aef);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x04b80ae5);
   gSP1Triangle(glistp++,8, 5, 4, 8); 
   gSP1Triangle(glistp++,9, 10, 11, 9); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0ca20f43);
   gSP1Triangle(glistp++,12, 3, 13, 12); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x09ba023d);           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0883087f);
   gSP1Triangle(glistp++,7, 11, 12, 7); 
   gSP1Triangle(glistp++,14, 8, 4, 14); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x084600fe);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x04b600cc);
   gSP1Triangle(glistp++,8, 6, 0, 8); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0e260281);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0bb701eb);
   gSP1Triangle(glistp++,13, 2, 1, 13); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x0af20fea);
   gSP1Triangle(glistp++,12, 10, 15, 12); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x0ec50227);           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0a9205f4);
   gSP1Triangle(glistp++,6, 11, 16, 6); 
   gSP1Triangle(glistp++,3, 17, 13, 3); 
   gSP1Triangle(glistp++,7, 13, 1, 7); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x023604fc);
   gSP1Triangle(glistp++,0, 17, 8, 0); 
   gSP1Triangle(glistp++,8, 17, 5, 8); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0eac0f02);           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x0caa0f32);
   gSP1Triangle(glistp++,9, 14, 10, 9); 
   gSP1Triangle(glistp++,12, 15, 3, 12); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x07a7033a);           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0883087f);
   gSP1Triangle(glistp++,7, 16, 11, 7); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x06de0ae0);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x07ab0548);
   gSP1Triangle(glistp++,14, 9, 8, 14); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x084600fe);
   gSP1Triangle(glistp++,8, 9, 6, 8); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0ef00777);
   gSP1Triangle(glistp++,13, 17, 2, 13); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x0af20fea);
   gSP1Triangle(glistp++,12, 11, 10, 12); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x0ec50227);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0f0f07f1);           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0a9205f4);
   gSP1Triangle(glistp++,6, 9, 11, 6); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0e0c0f10);
   gSP1Triangle(glistp++,3, 5, 17, 3); 
   gSP1Triangle(glistp++,7, 12, 13, 7); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x021c00e1);           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x023604fc);
   gSP1Triangle(glistp++,0, 2, 17, 0); 

   gDPPipeSync(glistp++);

 } 
 
 
 //Test Object = 4 
RigAnimation player_right_leg_lower_anim[] =
 { 
-6.303421, -0.068679, 22.535932,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -0.068679, 22.535932,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.273569, 0.396273, 22.483681,
    0.116476, 0.000000, -0.503563,
       1.000000, 1.000000, 1.000000,
 -6.176037, 1.765852, 22.319514,
    1.141175, 0.000000, -1.938784,
       1.000000, 1.000000, 1.000000,
 -6.026029, 3.549288, 22.081174,
    4.108606, 0.000000, -3.692476,
       1.000000, 1.000000, 1.000000,
 -5.863707, 5.058999, 21.841677,
    9.129400, 0.000000, -5.000000,
       1.000000, 1.000000, 1.000000,
 -5.632412, 6.368342, 21.670030,
    18.280033, 0.000000, -5.981351,
       1.000000, 1.000000, 1.000000,
 -5.356627, 7.658874, 21.468396,
    33.530556, 0.000000, -6.751271,
       1.000000, 1.000000, 1.000000,
 -5.246049, 8.685432, 21.023178,
    49.872815, 0.000000, -7.000000,
       1.000000, 1.000000, 1.000000,
 -5.277289, 9.483873, 19.963768,
    70.971656, 0.000000, -6.292809,
       1.000000, 1.000000, 1.000000,
 -5.451580, 9.769633, 19.244634,
    83.723714, 0.000000, -4.999999,
       1.000000, 1.000000, 1.000000,
 -5.775724, 6.231782, 19.960769,
    84.526801, 0.000000, -3.755432,
       1.000000, 1.000000, 1.000000,
 -6.213903, -2.294015, 21.797898,
    84.856979, 0.000000, -2.480092,
       1.000000, 1.000000, 1.000000,
 -6.608921, -8.776417, 23.453249,
    84.895338, 0.000000, -2.000000,
       1.000000, 1.000000, 1.000000,
 -6.935416, -11.762350, 24.855988,
    72.158927, 0.000000, -2.520854,
       1.000000, 1.000000, 1.000000,
 -7.224733, -12.926956, 26.152563,
    40.063322, 0.000000, -3.842083,
       1.000000, 1.000000, 1.000000,
 -7.473477, -13.340749, 26.616088,
    12.403563, 0.000000, -4.999999,
       1.000000, 1.000000, 1.000000,
 -7.727954, -13.731840, 26.561543,
    -8.527186, -0.000000, -5.916362,
       1.000000, 1.000000, 1.000000,
 -7.945966, -13.892628, 26.092076,
    -26.223552, -0.000000, -6.720700,
       1.000000, 1.000000, 1.000000,
 -8.020580, -13.911310, 24.950179,
    -32.230959, -0.000000, -7.000000,
       1.000000, 1.000000, 1.000000,
 -7.716409, -12.786298, 21.833499,
    -28.461101, -0.000000, -6.292809,
       1.000000, 1.000000, 1.000000,
 -7.213478, -10.368949, 19.549774,
    -20.382429, -0.000000, -4.999999,
       1.000000, 1.000000, 1.000000,
 -6.890953, -7.917150, 19.827086,
    -10.765533, -0.000000, -3.755432,
       1.000000, 1.000000, 1.000000,
 -6.617690, -5.114419, 20.534123,
    0.188994, 0.000000, -2.480092,
       1.000000, 1.000000, 1.000000,
 -6.387710, -2.441739, 21.161681,
    5.991179, 0.000000, -2.000000,
       1.000000, 1.000000, 1.000000,
 -6.157201, 0.558063, 21.624984,
    7.892068, 0.000000, -2.724660,
       1.000000, 1.000000, 1.000000,
 -5.966980, 3.513507, 22.030769,
    8.673576, 0.000000, -4.275341,
       1.000000, 1.000000, 1.000000,
 -5.903392, 4.605392, 22.298682,
    8.764376, 0.000000, -4.999999,
       1.000000, 1.000000, 1.000000,
 -6.000020, 3.476356, 22.461306,
    6.647313, 0.000000, -3.792234,
       1.000000, 1.000000, 1.000000,
 -6.206793, 1.060358, 22.528164,
    2.117063, 0.000000, -1.207766,
       1.000000, 1.000000, 1.000000,
 -6.303421, -0.068679, 22.535932,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -0.068679, 22.535932,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -0.068679, 22.535932,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -0.068679, 22.535932,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -0.068679, 22.535932,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 0.231064, 22.742510,
    0.220164, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 1.076343, 23.282860,
    0.949326, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 2.086830, 23.823211,
    2.092040, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 2.803632, 24.029788,
    3.356191, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.188147, 23.993227,
    4.515677, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.384669, 23.897594,
    5.732162, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.564941, 23.801960,
    7.472827, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.908433, 23.765399,
    9.955574, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 4.453889, 23.903494,
    12.727034, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 5.155129, 24.264714,
    15.856095, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 5.852884, 24.625936,
    20.169431, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 6.389543, 24.764031,
    25.930525, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 6.802090, 24.152124,
    33.763671, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 7.077341, 22.651865,
    43.536514, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 7.155236, 21.451642,
    52.262169, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 7.094158, 20.736302,
    60.205659, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 6.789494, 20.273635,
    67.298660, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 6.192167, 20.146613,
    71.248278, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 5.494535, 20.296544,
    73.248192, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 4.668467, 20.768841,
    74.430197, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.479163, 21.457306,
    74.838362, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 1.864560, 22.152938,
    74.884760, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -0.317090, 22.872281,
    73.860785, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -3.128677, 23.711368,
    70.429646, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -5.952167, 24.573348,
    64.967626, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -8.163866, 25.350487,
    58.816808, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -9.727170, 26.044127,
    52.099074, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -10.759549, 26.675737,
    43.766076, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -11.624483, 27.268589,
    34.200164, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -12.593932, 27.962255,
    22.855778, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -13.396037, 28.631186,
    10.122908, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -13.664621, 28.875697,
    -0.204797, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -12.618878, 27.186468,
    -8.646434, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -10.381121, 23.515305,
    -14.903768, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -9.335379, 21.652141,
    -16.842000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -9.458877, 21.469480,
    -13.771068, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -9.723148, 21.394382,
    -7.074328, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -9.846647, 21.385658,
    -3.617080, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -9.374856, 21.386354,
    -3.211388, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -8.032844, 21.387845,
    -3.044596, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -6.536300, 21.388541,
    -3.025217, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -5.084645, 21.242826,
    -3.071519, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -3.440826, 20.861673,
    -3.192633, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -1.763245, 20.480523,
    -3.313747, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, -0.226359, 20.334807,
    -3.360049, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 1.470250, 21.216482,
    0.717959, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.099375, 23.103157,
    9.444389, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 -6.303421, 3.693563, 23.984832,
    13.522398, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 
};
void player_right_leg_lower_animation()
 { 
   tempObjVectorPos = player_right_leg_lower_anim[animFrame].pos;
   tempObjVectorRot = player_right_leg_lower_anim[animFrame].rot;
   tempObjVectorScl = player_right_leg_lower_anim[animFrame].scl;

   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
	SetVector3(&playerAvatar.animRig.joint.legR[1].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.legR[1].rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.legR[1].scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z); 

 } 
void player_right_leg_lower_PolyList() 
 { 

   Vtx *player_right_leg_lower_VTXPointer = &player_right_leg_lower_VertList_0[0]; 

   gSPVertex(glistp++,player_right_leg_lower_VTXPointer+0,26,0);

//OBJECT: 4 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_right_leg_lower_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x097b0136);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0515007d);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x051903f6);
   gSP1Triangle(glistp++,8, 1, 5, 8); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00a70107);
   gSP1Triangle(glistp++,0, 11, 5, 0); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x097d038b);
   gSP1Triangle(glistp++,8, 5, 9, 8); 
   gSP1Triangle(glistp++,0, 5, 1, 0); 
   gSP1Triangle(glistp++,15, 16, 17, 15); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0823072e);
   gSP1Triangle(glistp++,12, 18, 19, 12); 
           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x06cf07bd);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x07480755);
   gSP1Triangle(glistp++,22, 18, 14, 22); 
   gSPVertex(glistp++,player_right_leg_lower_VTXPointer+12,26,0);
   gSP1Triangle(glistp++,5, 17, 3, 5); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0c4801e7);
   gSP1Triangle(glistp++,3, 14, 4, 3); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0823072e);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x07480755);
   gSP1Triangle(glistp++,0, 2, 6, 0); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x06cf07bd);           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x06bb0856);
   gSP1Triangle(glistp++,10, 11, 6, 10); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x0d420770);
   gSP1Triangle(glistp++,5, 16, 17, 5); 


//OBJECT: 4 MATERIAL NO. 11 'player_glow'OK 

	gSPSetLights2(glistp++, glowLight);


   TEXTURE_4B_TLUT_CLAMP(player_glow, player_glow_tlut, 6,1);

   gSPVertex(glistp++,player_right_leg_lower_VTXPointer+12,26,0);
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x00850b82);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x07940fe6);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00850e36);
   gSP1Triangle(glistp++,7, 8, 0, 7); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x07ad09ef);
   gSP1Triangle(glistp++,13, 16, 8, 13); 
   gSP1Triangle(glistp++,7, 13, 8, 7); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0f100b2d);
   gSP1Triangle(glistp++,13, 17, 16, 13); 

		gSPSetLights2(glistp++, player_lighting);
//OBJECT: 4 MATERIAL NO. 12 'player_limb1'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb1, player_limb1_tlut, 6,1);

   gSPVertex(glistp++,player_right_leg_lower_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,0, 3, 4, 0); 
   gSP1Triangle(glistp++,5, 6, 7, 5); 
   gSP1Triangle(glistp++,8, 9, 7, 8); 
   gSP1Triangle(glistp++,6, 2, 10, 6); 
   gSP1Triangle(glistp++,6, 4, 3, 6); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0f0d0db7);
   gSP1Triangle(glistp++,11, 4, 6, 11); 
   gSP1Triangle(glistp++,1, 8, 10, 1); 
   gSP1Triangle(glistp++,0, 2, 3, 0); 
   gSP1Triangle(glistp++,0, 4, 11, 0); 
   gSP1Triangle(glistp++,5, 7, 9, 5); 
   gSP1Triangle(glistp++,8, 7, 10, 8); 
   gSP1Triangle(glistp++,6, 10, 7, 6); 
   gSP1Triangle(glistp++,11, 6, 5, 11); 
   gSP1Triangle(glistp++,1, 10, 2, 1); 
   gSP1Triangle(glistp++,6, 3, 2, 6); 


//OBJECT: 4 MATERIAL NO. 13 'player_limb2'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb2, player_limb2_tlut, 6,1);

   gSPVertex(glistp++,player_right_leg_lower_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,12, 13, 14, 12); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0b250388);
   gSP1Triangle(glistp++,20, 17, 13, 20); 
   gSP1Triangle(glistp++,14, 21, 22, 14); 
   gSP1Triangle(glistp++,21, 23, 22, 21); 
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x05fa0daf);
   gSP1Triangle(glistp++,23, 24, 18, 23); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x038c0392);
   gSP1Triangle(glistp++,15, 25, 24, 15); 
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x05220dfd);
   gSP1Triangle(glistp++,24, 19, 18, 24); 
   gSPVertex(glistp++,player_right_leg_lower_VTXPointer+24,26,0);
   gSP1Triangle(glistp++,2, 0, 3, 2); 
   gSPVertex(glistp++,player_right_leg_lower_VTXPointer+12,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x092003ef);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0b250388);
   gSP1Triangle(glistp++,4, 1, 5, 4); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x085a03ef);
   gSP1Triangle(glistp++,4, 15, 9, 4); 
   gSP1Triangle(glistp++,0, 8, 1, 0); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x0f50014d);
   gSP1Triangle(glistp++,8, 16, 5, 8); 
   gSP1Triangle(glistp++,2, 1, 9, 2); 
   gSP1Triangle(glistp++,9, 15, 11, 9); 
   gSP1Triangle(glistp++,11, 15, 12, 11); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x038c0392);           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x00fd01d8);
   gSP1Triangle(glistp++,3, 17, 13, 3); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x05220dfd);
   gSP1Triangle(glistp++,12, 13, 7, 12); 
   gSP1Triangle(glistp++,14, 3, 12, 14); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x092003ef);
   gSP1Triangle(glistp++,4, 9, 1, 4); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x085a03ef);
   gSP1Triangle(glistp++,4, 14, 15, 4); 

   gDPPipeSync(glistp++);

 } 
 
 
  //Test Object = 6 
RigAnimation player_left_leg_anim[] =
 { 
3.185385, -0.068679, 42.910564,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.910564,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.830247,
    -3.948330, 0.107336, 0.494707,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.557165,
    -15.095596, 0.388100, 1.907075,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.114121,
    -28.453914, 0.668864, 3.638752,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.604742,
    -37.983922, 0.776200, 4.939534,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.063035,
    -44.204694, 0.588707, 5.936801,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.381578,
    -48.282208, 0.187494, 6.737282,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.515433,
    -49.416596, -0.000000, 7.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 38.066173,
    -43.847919, -0.000000, 6.292809,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 37.164953,
    -32.504102, -0.000000, 4.999999,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 38.289970,
    -21.243543, -0.000000, 3.755432,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.697366,
    -8.774231, -0.000000, 2.480092,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.822383,
    1.296946, 0.000000, 2.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.822383,
    8.544018, 0.000000, 2.520854,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.822383,
    13.481862, 0.000000, 3.842083,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.822383,
    17.330792, 0.000000, 4.999999,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.509154,
    20.607949, 0.000000, 5.916362,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.586102,
    22.721271, 0.000000, 6.720700,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.493668,
    24.461419, 0.000000, 7.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 37.932926,
    26.326701, 0.000000, 6.292809,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 36.969081,
    27.108474, 0.000000, 4.999999,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 37.872666,
    15.497709, 0.000000, 3.755432,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.972129,
    -11.142864, -0.000000, 2.480092,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.387108,
    -28.286721, -0.000000, 2.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.862053,
    -34.097377, -0.000000, 2.724660,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.012936,
    -36.486300, -0.000000, 4.275341,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.170599,
    -36.763859, -0.000000, 4.999999,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.481351,
    -27.883433, -0.000000, 3.792234,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.793921,
    -8.880428, -0.000000, 1.207766,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.910564,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.910564,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.910564,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.910564,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.910564,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.088877,
    -1.050499, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.555301,
    -4.206813, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.021726,
    -8.465274, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.200039,
    -12.298084, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.137299,
    -15.981575, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.973184,
    -20.111506, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.809071,
    -23.846333, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.746331,
    -26.532409, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.792063,
    -28.359697, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.911684,
    -29.439676, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.031307,
    -29.812608, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.077039,
    -29.854999, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.396506,
    -28.521963, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.752079,
    -25.669432, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.491498,
    -24.336396, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.863434,
    -24.336396, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.572519,
    -24.336396, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.524508,
    -24.336396, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.815065,
    -22.833951, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.644550,
    -18.424710, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.661465,
    -12.722407, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 42.425174,
    -7.955702, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.010592,
    -4.030402, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.561152,
    -0.142221, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.924278,
    3.496467, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.036546,
    6.791932, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.036546,
    9.539632, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.036546,
    11.836245, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.036546,
    14.572822, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.036546,
    18.192045, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.036546,
    22.264366, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.036546,
    25.546236, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.121889,
    28.181822, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.050938,
    30.095982, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.785790,
    30.679390, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.417720,
    29.125692, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.266393,
    24.619441, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.248812,
    19.423642, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 39.598966,
    14.303456, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.348253,
    8.394618, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.698406,
    2.094265, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.698406,
    -4.713535, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.698406,
    -12.199614, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.698406,
    -19.336698, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 40.698406,
    -25.263471, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 41.497734,
    -30.660914, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 43.208194,
    -34.913649, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 3.185385, -0.068679, 44.007522,
    -36.291677, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 
};
void player_left_leg_animation()
 { 
   tempObjVectorPos = player_left_leg_anim[animFrame].pos;
   tempObjVectorRot = player_left_leg_anim[animFrame].rot;
   tempObjVectorScl = player_left_leg_anim[animFrame].scl;

   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
	SetVector3(&playerAvatar.animRig.joint.legL[0].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.legL[0].rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.legL[0].scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z);

 } 
void player_left_leg_PolyList() 
 { 

   Vtx *player_left_leg_VTXPointer = &player_left_leg_VertList_0[0]; 

   gSPVertex(glistp++,player_left_leg_VTXPointer+0,26,0);

//OBJECT: 6 MATERIAL NO. 0 'player_limb1'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb1, player_limb1_tlut, 6,1);

   gSPVertex(glistp++,player_left_leg_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x04920ae1);
   gSP1Triangle(glistp++,9, 10, 4, 9); 
   gSP1Triangle(glistp++,11, 12, 13, 11); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0c790e4b);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0b9d0e60);
   gSP1Triangle(glistp++,14, 3, 5, 14); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x09c201b4);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x078f024e);
   gSP1Triangle(glistp++,7, 15, 8, 7); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x069c0ada);
   gSP1Triangle(glistp++,10, 13, 4, 10); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x08400116);           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x078b0553);
   gSP1Triangle(glistp++,10, 6, 11, 10); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0e6202a3);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0bd901b6);
   gSP1Triangle(glistp++,2, 16, 0, 2); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0ab00ea3);
   gSP1Triangle(glistp++,14, 12, 15, 14); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x0e190184);           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0b6a069a);           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0ea507bc);
   gSP1Triangle(glistp++,6, 15, 11, 6); 
   gSP1Triangle(glistp++,17, 3, 16, 17); 
   gSP1Triangle(glistp++,7, 16, 14, 7); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x023a04f5);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x04cf00de);
   gSP1Triangle(glistp++,17, 1, 10, 17); 
   gSP1Triangle(glistp++,9, 17, 10, 9); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0cf40f99);
   gSP1Triangle(glistp++,11, 15, 12, 11); 
   gSP1Triangle(glistp++,14, 16, 3, 14); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0853075a);
   gSP1Triangle(glistp++,7, 14, 15, 7); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x078b0553);
   gSP1Triangle(glistp++,10, 11, 13, 10); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x08400116);
   gSP1Triangle(glistp++,10, 1, 6, 10); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0f150762);
   gSP1Triangle(glistp++,2, 17, 16, 2); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0ab00ea3);
   gSP1Triangle(glistp++,14, 5, 12, 14); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x0e190184);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0b760012);           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0b6a069a);
   gSP1Triangle(glistp++,6, 8, 15, 6); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0df60e54);
   gSP1Triangle(glistp++,17, 9, 3, 17); 
   gSP1Triangle(glistp++,7, 0, 16, 7); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x023a04f5);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x023a00e2);
   gSP1Triangle(glistp++,17, 2, 1, 17); 


//OBJECT: 6 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_left_leg_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,6, 7, 8, 6); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0ff00aea);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0fff0f62);
   gSP1Triangle(glistp++,12, 4, 13, 12); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0aa10f85);
   gSP1Triangle(glistp++,3, 9, 4, 3); 
   gSP1Triangle(glistp++,12, 5, 4, 12); 
   gSP1Triangle(glistp++,0, 7, 1, 0); 
   gSP1Triangle(glistp++,6, 1, 7, 6); 

   gDPPipeSync(glistp++);

 } 
 
 
 //Test Object = 5 
RigAnimation player_left_leg_lower_anim[] =
 { 
5.729645, -0.068679, 22.625434,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -0.068679, 22.625434,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.793334, -1.371449, 22.937958,
    -0.006882, 0.075510, 0.499194,
       1.000000, 1.000000, 1.000000,
 5.993718, -5.023871, 23.816076,
    -0.067427, 0.273023, 1.923140,
       1.000000, 1.000000, 1.000000,
 6.285276, -9.336578, 24.857801,
    -0.242760, 0.470536, 3.665970,
       1.000000, 1.000000, 1.000000,
 6.579128, -12.306201, 25.583345,
    -0.539417, 0.546046, 4.970169,
       1.000000, 1.000000, 1.000000,
 6.965506, -14.001867, 26.016974,
    -8.545324, 0.414147, 5.959372,
       1.000000, 1.000000, 1.000000,
 7.411531, -14.872794, 26.261598,
    -25.197586, 0.131899, 6.744368,
       1.000000, 1.000000, 1.000000,
 7.588169, -15.049519, 26.318857,
    -32.939434, -0.000000, 7.000000,
       1.000000, 1.000000, 1.000000,
 7.243044, -13.741495, 23.188145,
    -28.855060, -0.000000, 6.292809,
       1.000000, 1.000000, 1.000000,
 6.669998, -10.705870, 20.057434,
    -21.125466, -0.000000, 4.999999,
       1.000000, 1.000000, 1.000000,
 6.296453, -7.158376, 20.318288,
    -14.486818, -0.000000, 3.755432,
       1.000000, 1.000000, 1.000000,
 5.976234, -2.963836, 20.975713,
    -7.562683, -0.000000, 2.480092,
       1.000000, 1.000000, 1.000000,
 5.712072, 0.478968, 21.542452,
    -1.498878, -0.000000, 2.000000,
       1.000000, 1.000000, 1.000000,
 5.500588, 2.986734, 21.971677,
    2.255997, 0.000000, 2.520854,
       1.000000, 1.000000, 1.000000,
 5.347247, 4.783574, 22.334842,
    5.008777, 0.000000, 3.842083,
       1.000000, 1.000000, 1.000000,
 5.193308, 6.172767, 22.458182,
    11.710399, 0.000000, 4.999999,
       1.000000, 1.000000, 1.000000,
 4.982190, 7.309771, 22.300714,
    22.799134, 0.000000, 5.916362,
       1.000000, 1.000000, 1.000000,
 4.767532, 8.017280, 21.773440,
    37.727981, 0.000000, 6.720700,
       1.000000, 1.000000, 1.000000,
 4.687018, 8.578450, 21.029328,
    54.464598, 0.000000, 7.000000,
       1.000000, 1.000000, 1.000000,
 4.727956, 9.144611, 19.746152,
    78.537886, 0.000000, 6.292809,
       1.000000, 1.000000, 1.000000,
 4.914343, 9.361351, 18.912368,
    92.822476, 0.000000, 4.999999,
       1.000000, 1.000000, 1.000000,
 5.245104, 5.276092, 19.740751,
    92.390589, 0.000000, 3.755432,
       1.000000, 1.000000, 1.000000,
 5.685221, -3.964495, 21.803042,
    88.673389, 0.000000, 2.480092,
       1.000000, 1.000000, 1.000000,
 6.063578, -9.586833, 23.524287,
    79.631912, 0.000000, 2.000000,
       1.000000, 1.000000, 1.000000,
 6.397677, -11.201016, 24.710201,
    53.784031, 0.000000, 2.724660,
       1.000000, 1.000000, 1.000000,
 6.681493, -11.864652, 25.626951,
    14.103187, 0.000000, 4.275341,
       1.000000, 1.000000, 1.000000,
 6.778124, -11.941757, 25.920004,
    -3.135119, -0.000000, 4.999999,
       1.000000, 1.000000, 1.000000,
 6.524861, -9.073777, 25.124189,
    -2.377821, -0.000000, 3.792234,
       1.000000, 1.000000, 1.000000,
 5.982909, -2.936658, 23.421249,
    -0.757298, -0.000000, 1.207766,
       1.000000, 1.000000, 1.000000,
 5.729645, -0.068679, 22.625434,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -0.068679, 22.625434,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -0.068679, 22.625434,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -0.068679, 22.625434,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -0.068679, 22.625434,
    0.000000, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -0.444126, 22.795290,
    3.128909, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -1.565705, 23.285347,
    11.313303, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -3.063693, 23.898867,
    19.497699, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -4.389366, 24.380398,
    22.626603, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -5.643009, 24.736005,
    22.386888, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -7.034341, 25.052539,
    21.229702, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -8.269851, 25.333014,
    18.642113, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -9.130128, 25.597593,
    14.791420, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -9.700214, 25.889331,
    9.222885, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -10.037150, 26.195082,
    1.590878, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -10.153499, 26.413429,
    -6.097425, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -10.166725, 26.484519,
    -11.808068, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -9.746747, 25.605458,
    -15.798965, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -8.848045, 23.519622,
    -18.129996, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -8.428067, 22.009398,
    -18.700841, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -8.428067, 21.346575,
    -15.505165, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -8.428067, 21.074070,
    -7.965323, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -8.428067, 21.042410,
    -2.607276, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -7.923976, 21.151385,
    -0.491251, -0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -6.439781, 21.480338,
    0.321934, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -4.508698, 21.927755,
    0.726205, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -2.876464, 22.335783,
    1.809950, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -1.507901, 22.725607,
    3.535180, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -0.130832, 23.159879,
    5.557567, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 1.165439, 23.568682,
    7.827418, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 2.330030, 23.894215,
    10.177358, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 3.297371, 24.087918,
    12.510418, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 4.100850, 24.190117,
    15.026623, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 5.034918, 24.404414,
    17.958249, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 6.251350, 24.885283,
    20.895982, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 7.602687, 25.488517,
    24.201058, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 8.678646, 25.734863,
    28.931660, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 9.520289, 25.143781,
    35.102835, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 10.107806, 23.646802,
    42.694488, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 10.281029, 22.340135,
    50.783942, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 9.802067, 21.316849,
    59.640782, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 8.379988, 20.426264,
    69.119472, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 6.676763, 20.118564,
    76.813011, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 4.925839, 20.128672,
    83.243894, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 2.862154, 20.215672,
    88.041535, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, 0.672356, 20.427287,
    89.535044, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -1.686198, 20.642695,
    88.483263, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -4.285968, 20.886324,
    84.527402, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -6.738684, 21.416132,
    77.321129, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -8.726011, 22.353978,
    68.063866, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -10.436071, 24.219802,
    52.692604, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -11.690161, 26.651430,
    33.374907, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 5.729645, -12.075370, 27.657416,
    25.480999, 0.000000, 0.000000,
       1.000000, 1.000000, 1.000000,
 
};
void player_left_leg_lower_animation()
 { 
   tempObjVectorPos = player_left_leg_lower_anim[animFrame].pos;
   tempObjVectorRot = player_left_leg_lower_anim[animFrame].rot;
   tempObjVectorScl = player_left_leg_lower_anim[animFrame].scl;

   tempObjVectorPos = RotateAround(tempObjVectorPos, playerAvatar.rigidBody.centerMass, playerAvatar.obj.rot.z );
	SetVector3(&playerAvatar.animRig.joint.legL[1].pos, tempObjVectorPos.x,tempObjVectorPos.y,tempObjVectorPos.z); 
	SetVector3(&playerAvatar.animRig.joint.legL[1].rot, tempObjVectorRot.x,tempObjVectorRot.y,tempObjVectorRot.z); 
	SetVector3(&playerAvatar.animRig.joint.legL[1].scl, tempObjVectorScl.x,tempObjVectorScl.y,tempObjVectorScl.z);

 } 
void player_left_leg_lower_PolyList() 
 { 

   Vtx *player_left_leg_lower_VTXPointer = &player_left_leg_lower_VertList_0[0]; 

   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+0,26,0);

//OBJECT: 5 MATERIAL NO. 1 'player_dark_joints'OK 

   TEXTURE_4B_TLUT_CLAMP(player_dark_joints, player_dark_joints_tlut, 6,1);

   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x08e7010f);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x049a03ef);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x047d0077);
   gSP1Triangle(glistp++,8, 5, 2, 8); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00130121);
   gSP1Triangle(glistp++,0, 5, 11, 0); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x08fa0364);
   gSP1Triangle(glistp++,8, 9, 5, 8); 
   gSP1Triangle(glistp++,0, 2, 5, 0); 
   gSP1Triangle(glistp++,15, 16, 17, 15); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0ddc0baa);
   gSP1Triangle(glistp++,18, 13, 19, 18); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0d960ae2);
   gSP1Triangle(glistp++,18, 22, 14, 18); 
   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+12,26,0);
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0e870665);
   gSP1Triangle(glistp++,14, 5, 4, 14); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0d960ae2);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0ddc0baa);
   gSP1Triangle(glistp++,6, 2, 1, 6); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0f3209ea);
   gSP1Triangle(glistp++,6, 11, 10, 6); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0c3e0214);
   gSP1Triangle(glistp++,3, 15, 4, 3); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0d540750);
   gSP1Triangle(glistp++,14, 17, 5, 14); 


//OBJECT: 5 MATERIAL NO. 11 'player_glow'OK 

	gSPSetLights2(glistp++, glowLight);


   TEXTURE_4B_TLUT_CLAMP(player_glow, player_glow_tlut, 6,1);

   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+13,26,0);
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x07590fe2);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x005f0bbc);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x005f0e4b);
   gSP1Triangle(glistp++,7, 6, 0, 7); 
   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+12,26,0);
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x07720a3d);           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x07590fe2);
   gSP1Triangle(glistp++,17, 13, 8, 17); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x005f0bbc);
   gSP1Triangle(glistp++,8, 13, 7, 8); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0ebf0b67);
   gSP1Triangle(glistp++,17, 14, 13, 17); 

		gSPSetLights2(glistp++, player_lighting);
//OBJECT: 5 MATERIAL NO. 12 'player_limb2'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb2, player_limb2_tlut, 6,1);

   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,12, 13, 14, 12); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0b130392);
   gSP1Triangle(glistp++,17, 20, 12, 17); 
   gSP1Triangle(glistp++,14, 21, 12, 14); 
           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x085d0d00);
   gSP1Triangle(glistp++,23, 21, 22, 23); 
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x06390d52);
   gSP1Triangle(glistp++,24, 23, 18, 24); 
   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+16,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x03d303b2);
   gSP1Triangle(glistp++,0, 9, 10, 0); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x056b0d9f);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x06390d52);
   gSP1Triangle(glistp++,3, 8, 2, 3); 
   gSP1Triangle(glistp++,8, 11, 12, 8); 
   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+12,26,0);
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x092703fa);
   gSP1Triangle(glistp++,3, 0, 9, 3); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x085903fa);
   gSP1Triangle(glistp++,16, 3, 9, 16); 
   gSP1Triangle(glistp++,0, 8, 1, 0); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0b130392);           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0f0a0164);
   gSP1Triangle(glistp++,5, 17, 8, 5); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x085d0d00);
   gSP1Triangle(glistp++,2, 10, 9, 2); 
   gSP1Triangle(glistp++,11, 16, 9, 11); 
   gSP1Triangle(glistp++,12, 16, 11, 12); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x03d303b2);
   gSP1Triangle(glistp++,4, 12, 13, 4); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x056b0d9f);
   gSP1Triangle(glistp++,7, 13, 12, 7); 
   gSP1Triangle(glistp++,12, 4, 15, 12); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x092703fa);
   gSP1Triangle(glistp++,3, 5, 0, 3); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x085903fa);
   gSP1Triangle(glistp++,16, 15, 3, 16); 


//OBJECT: 5 MATERIAL NO. 13 'player_limb1'OK 

   TEXTURE_4B_TLUT_CLAMP(player_limb1, player_limb1_tlut, 6,1);

   gSPVertex(glistp++,player_left_leg_lower_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,0, 3, 4, 0); 
   gSP1Triangle(glistp++,5, 6, 7, 5); 
   gSP1Triangle(glistp++,8, 6, 9, 8); 
   gSP1Triangle(glistp++,7, 10, 1, 7); 
   gSP1Triangle(glistp++,7, 4, 3, 7); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0f910a40);
   gSP1Triangle(glistp++,11, 7, 3, 11); 
   gSP1Triangle(glistp++,2, 10, 8, 2); 
   gSP1Triangle(glistp++,0, 4, 1, 0); 
   gSP1Triangle(glistp++,0, 11, 3, 0); 
   gSP1Triangle(glistp++,5, 9, 6, 5); 
   gSP1Triangle(glistp++,8, 10, 6, 8); 
   gSP1Triangle(glistp++,7, 6, 10, 7); 
   gSP1Triangle(glistp++,11, 5, 7, 11); 
   gSP1Triangle(glistp++,2, 1, 10, 2); 
   gSP1Triangle(glistp++,7, 1, 4, 7); 

   gDPPipeSync(glistp++);

 } 
 
 

 
 //896 01.h
 //1444 01.c
 
 
 
 
 
 
 
 //Test Object = 0 
Vtx player_chest_VertList_0 [] = {
   { -0.04, 7.37, 18.38, 1, 0x084e, 0x00b6, -2, -103, 73, 255}, 
   { -8.21, 6.87, 17.52, 1, 0x0f9a, 0x01e2, -95, -74, 38, 255}, 
   { -6.61, 9.60, 12.13, 1, 0x0e4d, 0x08e4, -80, -15, -97, 255}, 
   { 0.01, 10.24, 11.06, 1, 0x088b, 0x0a01, 5, -21, -125, 255}, 
   { 6.29, 9.42, 12.57, 1, 0x02af, 0x0965, 83, -21, -93, 255}, 
   { 8.06, 6.78, 17.55, 1, 0x003f, 0x01f2, 99, -72, 32, 255}, 
   { -0.39, 9.77, 18.48, 1, 0x0851, 0x00b7, -2, 69, 106, 255}, 
   { -5.68, 11.26, 13.90, 1, 0x0e53, 0x08e3, -57, 112, -7, 255}, 
   { -6.96, 9.14, 17.82, 1, 0x0f9d, 0x01e0, -68, 63, 86, 255}, 
   { 5.17, 11.30, 13.76, 1, 0x02b5, 0x0968, 56, 112, -18, 255}, 
   { -0.35, 11.96, 12.56, 1, 0x0891, 0x0a01, 0, 121, -37, 255}, 
   { 6.59, 8.97, 18.13, 1, 0x0042, 0x01f6, 64, 59, 92, 255}, 
   { -6.23, -5.37, 0.84, 1, 0x0515, 0x0db5, -84, -88, -34, 255}, 
   { 0.03, -5.97, -2.88, 1, 0x080b, 0x0f82, 0, -112, -58, 255}, 
   { 0.04, -7.12, 0.05, 1, 0x0808, 0x0dc3, 0, -121, -37, 255}, 
   { 2.93, 4.10, 17.32, 1, 0x0690, 0x0250, 18, 104, 70, 255}, 
   { 7.46, 4.98, 11.46, 1, 0x03f2, 0x0533, 77, 100, 5, 255}, 
   { 2.93, 5.79, 13.02, 1, 0x067f, 0x04a4, 15, 124, 21, 255}, 
   { -3.96, -7.10, 3.56, 1, 0x0620, 0x0bf5, -31, -120, -26, 255}, 
   { -7.81, -7.22, 10.22, 1, 0x041e, 0x0876, -76, -86, -52, 255}, 
   { 7.24, 3.55, 16.15, 1, 0x0441, 0x0287, 71, 83, 64, 255}, 
   { 6.31, -5.32, 0.84, 1, 0x0afd, 0x0dbb, 84, -88, -33, 255}, 
   { -7.17, 3.47, 16.10, 1, 0x0bae, 0x0275, -69, 83, 65, 255}, 
   { -2.86, 2.23, 19.00, 1, 0x0954, 0x010f, -49, 74, 90, 255}, 
   { -2.86, 4.05, 17.20, 1, 0x0960, 0x0254, -20, 103, 70, 255}, 
   { 0.04, -3.07, 19.28, 1, 0x0d3a, 0x0273, 2, -90, 88, 255}, 
   { -1.86, -1.71, 22.50, 1, 0x0dbf, 0x03fd, -66, -57, 92, 255}, 
   { -2.86, -2.72, 19.12, 1, 0x0f2a, 0x02ec, -43, -50, 107, 255}, 
   { 2.93, -2.73, 18.99, 1, 0x0b5f, 0x02b1, 42, -48, 109, 255}, 
   { 0.04, -1.76, 22.58, 1, 0x0d37, 0x03fd, 5, -72, 104, 255}, 
   { 0.02, 4.43, 16.98, 1, 0x07fb, 0x0295, -2, 108, 66, 255}, 
   { 0.04, 1.55, 22.57, 1, 0x0d56, 0x04f3, -4, 79, 99, 255}, 
   { 1.93, 1.50, 22.50, 1, 0x0cd1, 0x04f5, 64, 63, 88, 255}, 
   { 1.93, -1.52, 22.39, 1, 0x0c9f, 0x042a, 71, -55, 89, 255}, 
   { 0.05, 2.36, 19.09, 1, 0x0d53, 0x066b, -2, 111, 61, 255}, 
   { 2.93, 2.29, 19.11, 1, 0x0b6f, 0x0609, 49, 73, 90, 255}, 
   { -1.86, 1.31, 22.38, 1, 0x0deb, 0x04c9, -70, 59, 87, 255}, 
   { 0.03, 3.40, -2.80, 1, 0x0507, 0x0563, 0, 117, -47, 255}, 
   { -2.71, 0.91, -5.95, 1, 0x043c, 0x0400, -41, 49, -109, 255}, 
   { -5.32, 2.01, -3.70, 1, 0x0337, 0x0488, -78, 76, -63, 255}, 
   { 0.03, -5.97, -2.88, 1, 0x0504, 0x0085, 0, -112, -58, 255}, 
   { 2.78, -3.01, -6.17, 1, 0x05e2, 0x02d5, 39, -45, -112, 255}, 
   { 6.52, -3.61, -3.54, 1, 0x075b, 0x02bc, 92, -53, -68, 255}, 
   { 0.04, 4.50, 1.59, 1, 0x0500, 0x0809, 0, 123, -29, 255}, 
   { 5.53, 2.69, 0.27, 1, 0x0801, 0x061b, 80, 93, -28, 255}, 
   { 5.39, 1.96, -3.74, 1, 0x06da, 0x0495, 78, 76, -64, 255}, 
   { -5.46, 2.66, 0.27, 1, 0x020c, 0x0606, -81, 93, -27, 255}, 
   { 0.04, 1.41, -6.08, 1, 0x050b, 0x041a, 0, 68, -107, 255}, 
   { 0.04, -3.50, -6.22, 1, 0x0504, 0x02a5, -6, -61, -111, 255}, 
   { -2.71, -2.73, -5.97, 1, 0x0420, 0x02e6, -42, -42, -112, 255}, 
   { 2.78, 1.01, -5.77, 1, 0x05df, 0x040d, 39, 56, -106, 255}, 
   { -6.44, -3.59, -3.58, 1, 0x02ab, 0x02b3, -90, -52, -71, 255}, 
   { -6.23, -5.37, 0.84, 1, 0x00d2, 0x0149, -84, -88, -34, 255}, 
   { -2.86, 2.23, 19.00, 1, 0x0d21, 0x0204, -49, 74, 90, 255}, 
   { -5.84, -1.06, 18.79, 1, 0x0f04, 0x0341, -42, 6, 119, 255}, 
   { -2.86, -2.72, 19.12, 1, 0x0f71, 0x014a, -43, -50, 107, 255}, 
   { 0.02, -6.46, 17.84, 1, 0x0d57, 0x000b, 0, -86, 92, 255}, 
   { 0.04, -3.07, 19.28, 1, 0x0d3a, 0x0273, 2, -90, 88, 255}, 
   { 2.93, -2.73, 18.99, 1, 0x0b5f, 0x02b1, 42, -48, 109, 255}, 
   { -1.86, -1.71, 22.50, 1, 0x0dbf, 0x03fd, -66, -57, 92, 255}, 
   { -7.17, 3.47, 16.10, 1, 0x0cea, 0x052b, -69, 83, 65, 255}, 
   { 6.31, -5.32, 0.84, 1, 0x0afd, 0x0dbb, 84, -88, -33, 255}, 
   { 4.03, -7.05, 3.56, 1, 0x09ea, 0x0bf9, 32, -119, -26, 255}, 
   { 0.04, -7.12, 0.05, 1, 0x0808, 0x0dc3, 0, -121, -37, 255}, 
   { 5.91, -1.07, 18.67, 1, 0x00fd, 0x0338, 44, 5, 118, 255}, 
   { 2.93, 2.29, 19.11, 1, 0x02da, 0x01db, 49, 73, 90, 255}, 
   { 7.87, -7.20, 10.22, 1, 0x0bdd, 0x087b, 76, -86, -52, 255}, 
   { -8.27, -5.54, 16.63, 1, 0x0046, 0x01a4, -97, -47, 66, 255}, 
   { -8.04, -7.92, 11.12, 1, 0x019b, 0x066f, -81, -84, -48, 255}, 
   { -7.43, -8.79, 12.03, 1, 0x0260, 0x0581, -49, -115, -15, 255}, 
   { 8.09, -7.90, 11.11, 1, 0x0e94, 0x069d, 80, -86, -46, 255}, 
   { 8.32, -5.86, 16.75, 1, 0x0fe3, 0x01bf, 97, -46, 67, 255}, 
   { 7.29, -8.78, 12.00, 1, 0x0dba, 0x05a9, 41, -118, -19, 255}, 
   { -7.38, -6.21, 17.04, 1, 0x014f, 0x014c, -49, -75, 89, 255}, 
   { 7.45, -6.54, 17.10, 1, 0x0ee1, 0x016f, 47, -79, 87, 255}, 
   { -2.86, 4.05, 17.20, 1, 0x0960, 0x0254, -20, 103, 70, 255}, 
   { -7.35, 4.97, 11.89, 1, 0x0c00, 0x04e3, -76, 100, 9, 255}, 
   { -2.86, 5.76, 12.89, 1, 0x0980, 0x04aa, -14, 124, 20, 255}, 
   { 0.02, 4.43, 16.98, 1, 0x07fb, 0x0295, -2, 108, 66, 255}, 
   { 0.02, 4.43, 16.98, 1, 0x07fb, 0x0295, -2, 108, 66, 255}, 
   { 2.93, 4.10, 17.32, 1, 0x0690, 0x0250, 18, 104, 70, 255}, 
   { 2.93, 5.79, 13.02, 1, 0x067f, 0x04a4, 15, 124, 21, 255}, 
   { 7.38, 4.21, 8.33, 1, 0x0460, 0x0971, 93, 80, -30, 255}, 
   { 5.55, 5.25, 8.60, 1, 0x055c, 0x0921, 32, 120, -21, 255}, 
   { 7.46, 4.98, 11.46, 1, 0x044d, 0x078c, 77, 100, 5, 255}, 
   { -5.45, 5.25, 8.49, 1, 0x0aa0, 0x0941, -33, 120, -21, 255}, 
   { -7.31, 4.21, 8.33, 1, 0x0b9f, 0x0988, -93, 80, -29, 255}, 
   { 0.04, 5.68, 10.42, 1, 0x0802, 0x060f, 0, 126, -11, 255}, 
   { 0.04, 4.50, 1.59, 1, 0x07f8, 0x0d50, 0, 123, -29, 255}, 
   { -5.46, 2.66, 0.27, 1, 0x0ab1, 0x0e55, -81, 93, -27, 255}, 
   { -5.45, 5.25, 8.49, 1, 0x0aa0, 0x0941, -33, 120, -21, 255}, 
   { 0.83, -8.78, 12.56, 1, 0x08be, 0x058c, 5, -126, 5, 255}, 
   { 0.02, -6.46, 17.84, 1, 0x0819, 0x0051, 0, -86, 92, 255}, 
   { -0.75, -8.78, 12.56, 1, 0x076e, 0x0589, -5, -126, 5, 255}, 
   { 5.53, 2.69, 0.27, 1, 0x053c, 0x0e43, 80, 93, -28, 255}, 
   { 7.24, 3.55, 16.15, 1, 0x0325, 0x0505, 71, 83, 64, 255}, 
   { 2.93, 2.29, 19.11, 1, 0x02da, 0x01db, 49, 73, 90, 255}, 
   { 5.91, -1.07, 18.67, 1, 0x00fd, 0x0338, 44, 5, 118, 255}, 
   { 8.32, -5.86, 16.75, 1, 0x0d7a, 0x0550, 97, -46, 67, 255}, 
   { -5.84, -1.06, 18.79, 1, 0x0023, 0x03f3, -42, 6, 119, 255}, 
   { -8.64, -1.06, 17.35, 1, 0x0050, 0x05ae, -85, 13, 92, 255}, 
   { -8.27, -5.54, 16.63, 1, 0x0258, 0x0566, -97, -47, 66, 255}, 
   { -7.17, 3.47, 16.10, 1, 0x0cea, 0x052b, -69, 83, 65, 255}, 
   { 8.48, -1.07, 17.23, 1, 0x00cb, 0x04f2, 84, 14, 93, 255}, 
   { -10.16, -1.06, 14.86, 1, 0x0098, 0x0744, -123, 10, 28, 255}, 
   { -8.04, -7.92, 11.12, 1, 0x0436, 0x07d4, -81, -84, -48, 255}, 
   { -7.35, 4.97, 11.89, 1, 0x0bc3, 0x0768, -76, 100, 9, 255}, 
   { -9.93, -1.06, 10.30, 1, 0x0e93, 0x0966, -125, 7, -20, 255}, 
   { -7.81, -7.22, 10.22, 1, 0x041e, 0x0876, -76, -86, -52, 255}, 
   { -9.12, -1.55, 7.46, 1, 0x0e38, 0x0b21, -122, 0, -33, 255}, 
   { -6.23, -5.37, 0.84, 1, 0x0515, 0x0db5, -84, -88, -34, 255}, 
   { -7.62, -1.72, 1.56, 1, 0x0352, 0x0e0c, -124, 4, -23, 255}, 
   { -7.41, -1.72, -0.54, 1, 0x0166, 0x0384, -124, 6, -21, 255}, 
   { 10.19, -1.07, 14.74, 1, 0x0f57, 0x075c, 122, 11, 30, 255}, 
   { 8.09, -7.90, 11.11, 1, 0x0bc3, 0x07db, 80, -86, -46, 255}, 
   { 7.46, 4.98, 11.46, 1, 0x044d, 0x078c, 77, 100, 5, 255}, 
   { 9.96, -1.07, 10.18, 1, 0x0e9d, 0x09b7, 125, 7, -20, 255}, 
   { 7.87, -7.20, 10.22, 1, 0x0bdd, 0x087b, 76, -86, -52, 255}, 
   { 7.38, 4.21, 8.33, 1, 0x0460, 0x0971, 93, 80, -30, 255}, 
   { 9.15, -1.55, 7.35, 1, 0x0de1, 0x0b17, 122, 0, -33, 255}, 
   { 7.38, 4.21, 8.33, 1, 0x0460, 0x0971, 93, 80, -30, 255}, 
   { 9.15, -1.55, 7.35, 1, 0x01c6, 0x0b0d, 122, 0, -33, 255}, 
   { 5.53, 2.69, 0.27, 1, 0x053c, 0x0e43, 80, 93, -28, 255}, 
   { 6.31, -5.32, 0.84, 1, 0x0afd, 0x0dbb, 84, -88, -33, 255}, 
   { 7.66, -1.73, 1.40, 1, 0x0cb4, 0x0e27, 124, 4, -23, 255}, 
   { 7.45, -1.73, -0.70, 1, 0x0891, 0x038b, 124, 6, -22, 255}, 
   { -5.46, 2.66, 0.27, 1, 0x020c, 0x0606, -81, 93, -27, 255}, 
   { -5.32, 2.01, -3.70, 1, 0x0337, 0x0488, -78, 76, -63, 255}, 
   { -7.41, -1.72, -0.54, 1, 0x0166, 0x0384, -124, 6, -21, 255}, 
   { -6.44, -3.59, -3.58, 1, 0x02ab, 0x02b3, -90, -52, -71, 255}, 
   { 6.52, -3.61, -3.54, 1, 0x075b, 0x02bc, 92, -53, -68, 255}, 
   { 5.39, 1.96, -3.74, 1, 0x06da, 0x0495, 78, 76, -64, 255}, 
   { -7.43, -8.79, 12.03, 1, 0x0260, 0x0581, -49, -115, -15, 255}, 
   { -8.04, -7.92, 11.12, 1, 0x019b, 0x066f, -81, -84, -48, 255}, 
   { -0.75, -8.78, 12.56, 1, 0x076e, 0x0589, -5, -126, 5, 255}, 
   { 7.29, -8.78, 12.00, 1, 0x0dba, 0x05a9, 41, -118, -19, 255}, 
   { 0.83, -8.78, 12.56, 1, 0x08be, 0x058c, 5, -126, 5, 255}, 
   { 8.09, -7.90, 11.11, 1, 0x0e94, 0x069d, 80, -86, -46, 255}, 
   { 0.02, -6.46, 17.84, 1, 0x0819, 0x0051, 0, -86, 92, 255}, 
   { 0.04, -8.60, 11.78, 1, 0x0813, 0x0634, 0, -124, -26, 255}, 
   { 4.03, -7.05, 3.56, 1, 0x0b3e, 0x0ceb, 32, -119, -26, 255}, 
   { 0.04, -8.60, 11.78, 1, 0x0813, 0x0634, 0, -124, -26, 255}, 
   { 0.04, -7.12, 0.05, 1, 0x07f5, 0x0fac, 0, -121, -37, 255}, 
   { -3.96, -7.10, 3.56, 1, 0x04bf, 0x0cd1, -31, -120, -26, 255}, 
   { -7.81, -7.22, 10.22, 1, 0x01b8, 0x0759, -76, -86, -52, 255}, 
   { 0.02, -6.46, 17.84, 1, 0x0296, 0x00b1, 0, -86, 92, 255}, 
   { -2.86, -2.72, 19.12, 1, 0x00cd, 0x023f, -43, -50, 107, 255}, 
   { -7.38, -6.21, 17.04, 1, 0x0296, 0x04d1, -49, -75, 89, 255}, 
   { -5.84, -1.06, 18.79, 1, 0x0023, 0x03f3, -42, 6, 119, 255}, 
   { 0.02, -6.46, 17.84, 1, 0x0d8c, 0x00a0, 0, -86, 92, 255}, 
   { 7.45, -6.54, 17.10, 1, 0x0d3d, 0x04be, 47, -79, 87, 255}, 
   { 2.93, -2.73, 18.99, 1, 0x0f3d, 0x025d, 42, -48, 109, 255}, 
   { 5.91, -1.07, 18.67, 1, 0x0fd7, 0x041f, 44, 5, 118, 255}, 
};

//Test Object = 1 
Vtx player_head_VertList_0 [] = {
   { -10.50, 0.37, 10.20, 1, 0x0f5e, 0x019c, -85, -75, 56, 255}, 
   { -10.39, 8.71, 13.29, 1, 0x0e30, 0x07a5, -98, 78, 19, 255}, 
   { -10.71, 0.24, 7.65, 1, 0x0dd9, 0x009f, -95, -71, -43, 255}, 
   { -9.61, 9.20, 13.11, 1, 0x0b8e, 0x0541, 39, 120, -5, 255}, 
   { -9.05, -0.18, 7.23, 1, 0x0a7d, 0x007a, 63, -83, -71, 255}, 
   { -9.56, 5.16, 8.32, 1, 0x0bd7, 0x0281, 48, 84, -81, 255}, 
   { -10.85, 2.76, 7.02, 1, 0x0c8a, 0x01e2, -94, 27, -80, 255}, 
   { -9.34, 1.69, 6.38, 1, 0x0c7f, 0x0111, 53, 0, -115, 255}, 
   { -9.28, 7.70, 14.65, 1, 0x0f5e, 0x078f, 64, 26, 106, 255}, 
   { -0.03, 7.84, 7.80, 1, 0x081e, 0x0489, 1, 126, -7, 255}, 
   { -3.37, 6.76, 5.54, 1, 0x09a6, 0x05c0, -41, 102, -61, 255}, 
   { -4.95, 6.29, 7.17, 1, 0x0a85, 0x0503, -75, 99, -25, 255}, 
   { 10.23, 8.82, 13.22, 1, 0x0e27, 0x07a1, 97, 78, 21, 255}, 
   { 10.10, 7.58, 14.28, 1, 0x0f43, 0x0747, 87, 2, 92, 255}, 
   { 10.36, 0.47, 10.15, 1, 0x0f5a, 0x0198, 86, -82, 43, 255}, 
   { 10.54, 1.35, 8.21, 1, 0x0dd6, 0x016d, 112, -56, -13, 255}, 
   { 9.07, 0.88, 6.42, 1, 0x09e6, 0x00ba, -45, -57, -103, 255}, 
   { 9.44, 9.31, 13.06, 1, 0x0aa5, 0x0568, -40, 120, -2, 255}, 
   { 9.39, 5.26, 8.27, 1, 0x09a6, 0x02cf, -58, 70, -87, 255}, 
   { -3.65, -7.74, 1.10, 1, 0x0b06, 0x0fc6, -62, -80, -75, 255}, 
   { -0.04, 0.84, 0.51, 1, 0x081e, 0x09ec, 0, 42, -119, 255}, 
   { -0.18, -8.18, 0.09, 1, 0x083f, 0x103a, 0, -85, -94, 255}, 
   { 9.12, 7.80, 14.60, 1, 0x03de, 0x08e8, -64, 26, 106, 255}, 
   { 10.67, 1.91, 6.83, 1, 0x014d, 0x029f, 91, -12, -86, 255}, 
   { 5.78, 0.82, 2.45, 1, 0x040b, 0x0911, 78, 37, -92, 255}, 
   { 3.34, 6.60, 5.61, 1, 0x0686, 0x05c0, 42, 100, -64, 255}, 
   { 7.58, 0.95, 5.27, 1, 0x029e, 0x0722, 120, 23, -34, 255}, 
   { -5.86, 0.82, 2.45, 1, 0x0c33, 0x090c, -77, 35, -93, 255}, 
   { -7.62, 0.97, 5.13, 1, 0x0d91, 0x072f, -119, 23, -35, 255}, 
   { -3.37, 4.38, 12.59, 1, 0x0a88, 0x0156, -56, 84, 76, 255}, 
   { -0.10, 7.11, 10.94, 1, 0x0826, 0x02da, 0, 110, 62, 255}, 
   { -6.16, 5.65, 9.94, 1, 0x0b52, 0x03ab, -88, 84, 34, 255}, 
   { -6.94, 1.19, 12.25, 1, 0x0dfc, 0x0212, -101, 17, 74, 255}, 
   { 4.34, -2.32, 13.19, 1, 0x0acb, 0x06a0, 52, -53, 102, 255}, 
   { 6.87, 1.19, 12.25, 1, 0x0dc0, 0x0673, 101, 18, 73, 255}, 
   { 4.53, 0.67, 13.45, 1, 0x0c56, 0x0557, 95, 14, 82, 255}, 
   { -7.02, -3.23, 8.30, 1, 0x0348, 0x0a02, -121, -34, 8, 255}, 
   { -6.73, -3.23, 11.54, 1, 0x03f7, 0x0869, -102, -40, 62, 255}, 
   { -8.90, 2.35, 12.12, 1, 0x09af, 0x02c7, 76, -48, 88, 255}, 
   { -9.61, 9.20, 13.11, 1, 0x0b8e, 0x0541, 39, 120, -5, 255}, 
   { -9.28, 7.70, 14.65, 1, 0x0a90, 0x053f, 64, 26, 106, 255}, 
   { -10.39, 8.71, 13.29, 1, 0x0e30, 0x07a5, -98, 78, 19, 255}, 
   { -10.50, 0.37, 10.20, 1, 0x0f5e, 0x019c, -85, -75, 56, 255}, 
   { -10.27, 7.48, 14.34, 1, 0x0f48, 0x074b, -87, 2, 92, 255}, 
   { -10.85, 2.76, 7.02, 1, 0x0c8a, 0x01e2, -94, 27, -80, 255}, 
   { -10.71, 0.24, 7.65, 1, 0x0dd9, 0x009f, -95, -71, -43, 255}, 
   { -10.39, 8.71, 13.29, 1, 0x0e30, 0x07a5, -98, 78, 19, 255}, 
   { -9.56, 5.16, 8.32, 1, 0x0c6b, 0x03cc, 48, 84, -81, 255}, 
   { -9.34, 1.69, 6.38, 1, 0x0b5f, 0x00cf, 53, 0, -115, 255}, 
   { -9.56, 5.16, 8.32, 1, 0x0bd7, 0x0281, 48, 84, -81, 255}, 
   { -9.05, -0.18, 7.23, 1, 0x0a7d, 0x007a, 63, -83, -71, 255}, 
   { -8.82, -0.50, 9.35, 1, 0x09af, 0x0106, 72, -101, 22, 255}, 
   { -4.79, -6.81, 10.61, 1, 0x0598, 0x0985, -56, -95, 61, 255}, 
   { -5.14, -7.53, 5.40, 1, 0x0554, 0x0c08, -77, -100, -4, 255}, 
   { -0.04, -7.16, 10.59, 1, 0x07e0, 0x0981, 0, -107, 67, 255}, 
   { -3.65, -7.74, 1.10, 1, 0x05bb, 0x0e9a, -62, -80, -75, 255}, 
   { -0.02, -8.05, 3.65, 1, 0x0801, 0x0d29, 0, -126, 8, 255}, 
   { 5.95, 5.65, 9.94, 1, 0x04f0, 0x03a8, 87, 85, 35, 255}, 
   { 7.58, 0.95, 5.27, 1, 0x029e, 0x0722, 120, 23, -34, 255}, 
   { 4.88, 6.29, 7.17, 1, 0x05b3, 0x0504, 75, 98, -27, 255}, 
   { -0.03, 7.84, 7.80, 1, 0x081e, 0x0489, 1, 126, -7, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x05ae, 0x0158, 55, 85, 75, 255}, 
   { -0.10, 7.11, 10.94, 1, 0x0826, 0x02da, 0, 110, 62, 255}, 
   { -0.04, 4.57, 13.19, 1, 0x081b, 0x00cc, 2, 106, 68, 255}, 
   { 3.34, 6.60, 5.61, 1, 0x0686, 0x05c0, 42, 100, -64, 255}, 
   { 6.87, 1.19, 12.25, 1, 0x0dc0, 0x0673, 101, 18, 73, 255}, 
   { 6.94, -3.21, 8.26, 1, 0x0c86, 0x09b9, 121, -34, 8, 255}, 
   { 10.54, 1.35, 8.21, 1, 0x0dd6, 0x016d, 112, -56, -13, 255}, 
   { 10.56, 5.46, 9.05, 1, 0x0cd7, 0x0426, 104, 52, -49, 255}, 
   { 10.23, 8.82, 13.22, 1, 0x0e27, 0x07a1, 97, 78, 21, 255}, 
   { 9.44, 9.31, 13.06, 1, 0x0aa5, 0x0568, -40, 120, -2, 255}, 
   { 8.73, 2.45, 12.07, 1, 0x0bce, 0x028f, -76, -48, 88, 255}, 
   { 9.12, 7.80, 14.60, 1, 0x0b9b, 0x052a, -64, 26, 106, 255}, 
   { 8.65, -0.40, 9.30, 1, 0x0b58, 0x00dc, -62, -110, 1, 255}, 
   { 9.07, 0.88, 6.42, 1, 0x09e6, 0x00ba, -45, -57, -103, 255}, 
   { 9.39, 5.26, 8.27, 1, 0x00eb, 0x0525, -58, 70, -87, 255}, 
   { 10.36, 0.47, 10.15, 1, 0x051d, 0x05c6, 86, -82, 43, 255}, 
   { 10.10, 7.58, 14.28, 1, 0x0901, 0x09e8, 87, 2, 92, 255}, 
   { 4.71, -6.83, 10.59, 1, 0x0a27, 0x0963, 56, -96, 60, 255}, 
   { 5.08, -7.53, 5.43, 1, 0x0a95, 0x0bda, 77, -100, -4, 255}, 
   { -0.04, -7.16, 10.59, 1, 0x07e0, 0x0981, 0, -107, 67, 255}, 
   { 5.08, -7.53, 5.43, 1, 0x0a95, 0x0bda, 77, -100, -4, 255}, 
   { 4.71, -6.83, 10.59, 1, 0x0a27, 0x0963, 56, -96, 60, 255}, 
   { -0.02, -8.05, 3.65, 1, 0x0801, 0x0d29, 0, -126, 8, 255}, 
   { 3.61, -7.75, 1.19, 1, 0x0a5a, 0x0e67, 61, -81, -74, 255}, 
   { 3.00, 4.08, 14.04, 1, 0x0780, 0x01fa, 56, 83, 77, 255}, 
   { -2.78, 4.21, 14.31, 1, 0x0345, 0x020b, -47, 86, 80, 255}, 
   { -4.02, -1.72, 14.02, 1, 0x0230, 0x066e, -63, -56, 94, 255}, 
   { -0.04, -3.43, 12.91, 1, 0x054c, 0x083b, 0, -80, 98, 255}, 
   { -0.04, -2.70, 13.80, 1, 0x054a, 0x06e7, 0, -81, 97, 255}, 
   { 3.00, 4.08, 14.04, 1, 0x0780, 0x01fa, 56, 83, 77, 255}, 
   { 4.53, 0.67, 13.45, 1, 0x0998, 0x0461, 95, 14, 82, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x083e, 0x00eb, 55, 85, 75, 255}, 
   { 3.95, -1.72, 14.02, 1, 0x0862, 0x0664, 63, -56, 94, 255}, 
   { 4.12, 0.71, 14.82, 1, 0x083d, 0x0478, 81, 4, 97, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x05ae, 0x0158, 55, 85, 75, 255}, 
   { 6.87, 1.19, 12.25, 1, 0x0239, 0x0213, 101, 18, 73, 255}, 
   { 5.95, 5.65, 9.94, 1, 0x04f0, 0x03a8, 87, 85, 35, 255}, 
   { -4.41, -2.32, 13.19, 1, 0x04cb, 0x06d1, -52, -53, 102, 255}, 
   { -6.94, 1.19, 12.25, 1, 0x01d5, 0x06d6, -101, 17, 74, 255}, 
   { -6.73, -3.23, 11.54, 1, 0x03f7, 0x0869, -102, -40, 62, 255}, 
   { -3.37, 4.38, 12.59, 1, 0x0a88, 0x0156, -56, 84, 76, 255}, 
   { -4.60, 0.67, 13.45, 1, 0x0d43, 0x003b, -94, 15, 83, 255}, 
   { -0.04, 0.68, 15.37, 1, 0x0546, 0x049f, 1, -7, 126, 255}, 
   { -4.19, 0.71, 14.82, 1, 0x0252, 0x0481, -82, 4, 96, 255}, 
   { 4.34, -2.32, 13.19, 1, 0x0982, 0x074f, 52, -53, 102, 255}, 
   { -0.04, 4.57, 13.19, 1, 0x053e, 0x0109, 2, 106, 68, 255}, 
   { 3.34, 6.60, 5.61, 1, 0x0686, 0x05c0, 42, 100, -64, 255}, 
   { -0.04, 0.84, 0.51, 1, 0x081e, 0x09ec, 0, 42, -119, 255}, 
   { -3.37, 6.76, 5.54, 1, 0x09a6, 0x05c0, -41, 102, -61, 255}, 
   { -0.10, 7.11, 10.94, 1, 0x0826, 0x02da, 0, 110, 62, 255}, 
   { -6.16, 5.65, 9.94, 1, 0x0b52, 0x03ab, -88, 84, 34, 255}, 
   { -0.10, 7.11, 10.94, 1, 0x0826, 0x02da, 0, 110, 62, 255}, 
   { -0.03, 7.84, 7.80, 1, 0x081e, 0x0489, 1, 126, -7, 255}, 
   { 6.64, -3.20, 11.57, 1, 0x0bb9, 0x0825, 102, -40, 62, 255}, 
   { -6.94, 1.19, 12.25, 1, 0x01d5, 0x06d6, -101, 17, 74, 255}, 
   { -7.62, 0.97, 5.13, 1, 0x0068, 0x0b29, -119, 23, -35, 255}, 
   { -7.02, -3.23, 8.30, 1, 0x0348, 0x0a02, -121, -34, 8, 255}, 
   { -4.79, -6.81, 10.61, 1, 0x0598, 0x0985, -56, -95, 61, 255}, 
   { -5.14, -7.53, 5.40, 1, 0x0554, 0x0c08, -77, -100, -4, 255}, 
   { -0.02, -8.05, 3.65, 1, 0x0800, 0x0d2a, 0, -126, 8, 255}, 
   { -0.04, -7.16, 10.59, 1, 0x07e0, 0x0981, 0, -107, 67, 255}, 
   { -3.65, -7.74, 1.10, 1, 0x05bb, 0x0e9a, -62, -80, -75, 255}, 
   { -0.18, -8.18, 0.09, 1, 0x07f8, 0x0f4f, 0, -85, -94, 255}, 
   { -0.02, -8.05, 3.65, 1, 0x0801, 0x0d29, 0, -126, 8, 255}, 
   { 3.61, -7.75, 1.19, 1, 0x0536, 0x0fca, 61, -81, -74, 255}, 
   { 5.95, 5.65, 9.94, 1, 0x04f0, 0x03a8, 87, 85, 35, 255}, 
   { 6.87, 1.19, 12.25, 1, 0x0239, 0x0213, 101, 18, 73, 255}, 
   { 7.58, 0.95, 5.27, 1, 0x029e, 0x0722, 120, 23, -34, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x05ae, 0x0158, 55, 85, 75, 255}, 
   { 6.94, -3.21, 8.26, 1, 0x0c86, 0x09b9, 121, -34, 8, 255}, 
   { 10.54, 1.35, 8.21, 1, 0x0dd6, 0x016d, 112, -56, -13, 255}, 
   { 10.67, 1.91, 6.83, 1, 0x0cc9, 0x0142, 91, -12, -86, 255}, 
   { 10.56, 5.46, 9.05, 1, 0x0cd7, 0x0426, 104, 52, -49, 255}, 
   { 9.39, 5.26, 8.27, 1, 0x00eb, 0x0525, -58, 70, -87, 255}, 
   { 9.44, 9.31, 13.06, 1, 0x025f, 0x093e, -40, 120, -2, 255}, 
   { 10.23, 8.82, 13.22, 1, 0x02ac, 0x08fe, 97, 78, 21, 255}, 
   { 10.56, 5.46, 9.05, 1, 0x015b, 0x0583, 104, 52, -49, 255}, 
   { 10.54, 1.35, 8.21, 1, 0x025b, 0x02ca, 112, -56, -13, 255}, 
   { 10.36, 0.47, 10.15, 1, 0x03de, 0x02f5, 86, -82, 43, 255}, 
   { 8.65, -0.40, 9.30, 1, 0x039f, 0x0231, -62, -110, 1, 255}, 
   { 6.94, -3.21, 8.26, 1, 0x0c85, 0x09bb, 121, -34, 8, 255}, 
   { 6.64, -3.20, 11.57, 1, 0x0bb8, 0x0826, 102, -40, 62, 255}, 
   { 4.71, -6.83, 10.59, 1, 0x0a27, 0x0963, 56, -96, 60, 255}, 
   { 5.08, -7.53, 5.43, 1, 0x0a95, 0x0bda, 77, -100, -4, 255}, 
   { 3.00, 4.08, 14.04, 1, 0x0780, 0x01fa, 56, 83, 77, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x083e, 0x00eb, 55, 85, 75, 255}, 
   { -0.04, 4.57, 13.19, 1, 0x053e, 0x0109, 2, 106, 68, 255}, 
   { 3.00, 4.08, 14.04, 1, 0x0780, 0x01fa, 56, 83, 77, 255}, 
   { 4.12, 0.71, 14.82, 1, 0x083d, 0x0478, 81, 4, 97, 255}, 
   { 4.53, 0.67, 13.45, 1, 0x0998, 0x0461, 95, 14, 82, 255}, 
   { 3.95, -1.72, 14.02, 1, 0x0862, 0x0664, 63, -56, 94, 255}, 
   { 4.34, -2.32, 13.19, 1, 0x0982, 0x074f, 52, -53, 102, 255}, 
   { 4.53, 0.67, 13.45, 1, 0x0998, 0x0461, 95, 14, 82, 255}, 
   { 6.87, 1.19, 12.25, 1, 0x0239, 0x0213, 101, 18, 73, 255}, 
   { -0.04, 0.68, 15.37, 1, 0x0546, 0x049f, 1, -7, 126, 255}, 
   { 3.95, -1.72, 14.02, 1, 0x0862, 0x0664, 63, -56, 94, 255}, 
   { -0.04, -2.70, 13.80, 1, 0x054a, 0x06e7, 0, -81, 97, 255}, 
   { -0.04, -3.43, 12.91, 1, 0x054c, 0x083b, 0, -80, 98, 255}, 
   { 3.34, 6.60, 5.61, 1, 0x0686, 0x05c0, 42, 100, -64, 255}, 
   { 5.78, 0.82, 2.45, 1, 0x040b, 0x0911, 78, 37, -92, 255}, 
   { -0.04, 0.84, 0.51, 1, 0x081e, 0x09ec, 0, 42, -119, 255}, 
   { -4.41, -2.32, 13.19, 1, 0x04cb, 0x06d1, -52, -53, 102, 255}, 
   { -4.79, -6.81, 10.61, 1, 0x0599, 0x0984, -56, -95, 61, 255}, 
   { -0.04, -3.43, 12.91, 1, 0x07cc, 0x06d7, 0, -80, 98, 255}, 
   { -0.04, -7.16, 10.59, 1, 0x07e2, 0x0980, 0, -107, 67, 255}, 
   { 6.94, -3.21, 8.26, 1, 0x0c86, 0x09b9, 121, -34, 8, 255}, 
   { 5.08, -7.53, 5.43, 1, 0x0a97, 0x0bd9, 77, -100, -4, 255}, 
   { 6.94, -3.21, 5.85, 1, 0x0cea, 0x0afe, 120, -34, -19, 255}, 
   { -7.02, -3.23, 5.88, 1, 0x02f9, 0x0b4b, -120, -34, -19, 255}, 
   { -5.14, -7.53, 5.40, 1, 0x0555, 0x0c06, -77, -100, -4, 255}, 
   { -7.02, -3.23, 8.30, 1, 0x0348, 0x0a02, -121, -34, 8, 255}, 
   { 5.87, -3.21, 2.97, 1, 0x0d2e, 0x0cbb, 109, -24, -59, 255}, 
   { 3.61, -7.75, 1.19, 1, 0x0a5a, 0x0e67, 61, -81, -74, 255}, 
   { -5.94, -3.23, 3.01, 1, 0x02d1, 0x0d0a, -109, -24, -59, 255}, 
   { -3.65, -7.74, 1.10, 1, 0x05bb, 0x0e9a, -62, -80, -75, 255}, 
   { -7.62, 0.97, 5.13, 1, 0x0068, 0x0b29, -119, 23, -35, 255}, 
   { -5.86, 0.82, 2.45, 1, 0x0058, 0x0d36, -77, 35, -93, 255}, 
   { -4.63, -3.23, 1.33, 1, 0x0b93, 0x0c55, -66, -2, -108, 255}, 
   { 4.56, -3.21, 1.30, 1, 0x04b0, 0x0c55, 65, -3, -108, 255}, 
   { 7.58, 0.95, 5.27, 1, 0x0f6c, 0x0a9c, 120, 23, -34, 255}, 
};


//Test Object = 2 
Vtx player_right_arm_lower_VertList_0 [] = {
   { -5.31, -3.45, -12.57, 1, 0x0959, 0x09ab, -93, 40, 75, 255}, 
   { -4.77, -8.29, -13.27, 1, 0x0b1d, 0x0981, -74, -64, 80, 255}, 
   { -3.53, -6.33, -12.04, 1, 0x0a77, 0x0a31, -23, -24, 122, 255}, 
   { -0.15, -5.71, -12.04, 1, 0x07eb, 0x06cd, 78, -3, 100, 255}, 
   { 0.27, -4.61, -16.82, 1, 0x0943, 0x075d, 113, 35, -44, 255}, 
   { -0.44, -1.98, -12.47, 1, 0x07f8, 0x0826, 78, 73, 68, 255}, 
   { -2.67, -1.91, -18.21, 1, 0x0975, 0x0824, 1, 96, -82, 255}, 
   { -6.25, -4.69, -16.79, 1, 0x0a10, 0x089c, -117, 37, -31, 255}, 
   { 0.27, -8.51, -13.24, 1, 0x0d64, 0x0363, 88, -64, 65, 255}, 
   { -3.27, -1.07, -12.26, 1, 0x0866, 0x091d, -30, 96, 77, 255}, 
   { -2.91, -5.14, -19.20, 1, 0x09f2, 0x07dd, -2, 30, -123, 255}, 
   { -1.34, -10.38, -15.59, 1, 0x0e95, 0x026a, 36, -121, 0, 255}, 
   { -5.63, -7.85, -18.70, 1, 0x0a81, 0x082b, -84, -43, -84, 255}, 
   { -0.38, -8.01, -19.05, 1, 0x0a71, 0x06dd, 71, -43, -95, 255}, 
   { -4.82, -9.99, -15.67, 1, 0x0b86, 0x0895, -69, -106, 4, 255}, 
   { -3.82, -0.76, -4.92, 1, 0x0cbf, 0x069b, -125, 12, 13, 255}, 
   { 0.08, -4.68, -1.62, 1, 0x0847, 0x03ee, -2, -96, 82, 255}, 
   { -2.36, -1.50, -0.88, 1, 0x0b83, 0x034e, -76, -41, 92, 255}, 
   { -0.66, 4.42, 1.09, 1, 0x0fe8, 0x0078, -41, 74, 93, 255}, 
   { 1.25, 1.15, -5.68, 1, 0x020d, 0x061c, 97, 63, -50, 255}, 
   { 1.66, 4.78, 0.42, 1, 0x0016, 0x00c5, 69, 89, 57, 255}, 
   { 2.41, -3.13, -2.08, 1, 0x05ff, 0x03b3, 106, -44, 53, 255}, 
   { -2.79, -1.74, -12.97, 1, 0x00a0, 0x0d39, -47, 77, -88, 255}, 
   { -3.05, -6.04, -11.82, 1, 0x0904, 0x0c97, -61, -104, -37, 255}, 
   { -0.22, -5.82, -12.81, 1, 0x069a, 0x0cdf, 60, -83, -74, 255}, 
   { -0.46, -2.74, -13.82, 1, 0x0024, 0x0f65, 54, 27, -111, 255}, 
   { -4.59, -3.58, -12.20, 1, 0x002f, 0x0ad9, -114, -9, -54, 255}, 
};

//Test Object = 3 
Vtx player_left_arm_lower_VertList_0 [] = {
   { 5.24, -3.45, -12.44, 1, 0x090b, 0x0a43, 93, 40, 75, 255}, 
   { 3.46, -6.33, -11.91, 1, 0x0a3a, 0x0b1b, 23, -24, 122, 255}, 
   { 4.70, -8.29, -13.14, 1, 0x0b1e, 0x0a71, 74, -64, 80, 255}, 
   { 0.08, -5.71, -11.91, 1, 0x07fd, 0x06a6, -78, -3, 100, 255}, 
   { 0.36, -1.98, -12.33, 1, 0x07c3, 0x0837, -78, 73, 68, 255}, 
   { -0.34, -4.61, -16.69, 1, 0x096d, 0x0794, -113, 35, -44, 255}, 
   { 6.18, -4.69, -16.65, 1, 0x0a17, 0x0930, 117, 37, -31, 255}, 
   { 2.59, -1.91, -18.08, 1, 0x097d, 0x0885, -1, 96, -82, 255}, 
   { -0.34, -8.51, -13.10, 1, 0x0c9c, 0x035e, -88, -64, 65, 255}, 
   { 3.20, -1.07, -12.13, 1, 0x080f, 0x096c, 30, 96, 77, 255}, 
   { 2.84, -5.14, -19.06, 1, 0x0a1c, 0x084d, 2, 30, -123, 255}, 
   { 1.27, -10.38, -15.46, 1, 0x0dce, 0x026f, -36, -121, 0, 255}, 
   { 5.55, -7.85, -18.57, 1, 0x0ab1, 0x08c5, 84, -43, -84, 255}, 
   { 0.31, -8.01, -18.92, 1, 0x0ae5, 0x073f, -71, -43, -95, 255}, 
   { 4.75, -9.99, -15.54, 1, 0x0bca, 0x0976, 69, -106, 4, 255}, 
   { 3.75, -0.76, -4.78, 1, 0x0cb8, 0x0671, 125, 12, 13, 255}, 
   { 2.29, -1.50, -0.75, 1, 0x0b8c, 0x031e, 76, -41, 92, 255}, 
   { -0.15, -4.68, -1.49, 1, 0x084c, 0x03ae, 2, -96, 82, 255}, 
   { 0.59, 4.42, 1.22, 1, 0x0fff, 0x005c, 41, 74, 93, 255}, 
   { -1.32, 1.15, -5.55, 1, 0x0206, 0x05bf, -97, 63, -50, 255}, 
   { -2.48, -3.13, -1.95, 1, 0x0604, 0x0368, -106, -44, 53, 255}, 
   { -1.73, 4.78, 0.55, 1, 0x000d, 0x005c, -69, 89, 57, 255}, 
   { 2.72, -1.74, -12.83, 1, 0x00af, 0x0d00, 47, 77, -88, 255}, 
   { 2.97, -6.04, -11.68, 1, 0x08df, 0x0c5d, 61, -104, -37, 255}, 
   { 0.15, -5.82, -12.67, 1, 0x0673, 0x0c99, -60, -83, -74, 255}, 
   { 0.39, -2.74, -13.68, 1, 0x000d, 0x0f89, -54, 27, -111, 255}, 
   { 4.51, -3.58, -12.06, 1, 0x0040, 0x0a64, 114, -9, -54, 255}, 
};

//Test Object = 4 
Vtx player_right_leg_lower_VertList_0 [] = {
   { -3.76, 4.22, -20.56, 1, 0x0f0d, 0x0a9d, -68, 90, -56, 255}, 
   { -5.08, -3.63, -21.45, 1, 0x084a, 0x09d1, -99, 4, -78, 255}, 
   { -4.30, -3.52, -16.36, 1, 0x091e, 0x0b9c, -85, -22, 90, 255}, 
   { -3.21, 2.92, -14.74, 1, 0x0b4b, 0x0bf3, -60, 60, 93, 255}, 
   { 1.56, 2.70, -14.82, 1, 0x0ba8, 0x0c8b, 74, 49, 89, 255}, 
   { 1.35, -3.92, -21.56, 1, 0x08d3, 0x0eb7, 92, -6, -87, 255}, 
   { 0.90, -3.76, -16.45, 1, 0x093c, 0x0cf5, 83, -36, 88, 255}, 
   { -0.01, -10.23, -18.78, 1, 0x0304, 0x0cf0, 67, -71, 79, 255}, 
   { -4.04, -11.57, -21.63, 1, 0x00a5, 0x0ba5, -73, -89, -52, 255}, 
   { 0.28, -11.76, -21.71, 1, 0x00a4, 0x0d6f, 66, -93, -54, 255}, 
   { -3.51, -10.07, -18.72, 1, 0x02fe, 0x0bf2, -66, -69, 83, 255}, 
   { 2.14, 3.96, -20.67, 1, 0x00aa, 0x0437, 81, 77, -58, 255}, 
   { -2.58, -2.15, -16.55, 1, 0x09ff, 0x0de5, -62, -63, -90, 255}, 
   { -4.57, -1.08, -6.54, 1, 0x0a79, 0x07c2, -126, 8, -10, 255}, 
   { -2.97, -0.73, -16.28, 1, 0x093d, 0x0d83, -95, 7, -82, 255}, 
   { 3.11, -2.12, 0.34, 1, 0x0d3d, 0x02fb, 102, 8, 75, 255}, 
   { -3.60, 0.88, -0.36, 1, 0x09ee, 0x03c6, -59, 84, 74, 255}, 
   { -4.82, -2.30, 0.24, 1, 0x0a73, 0x0553, -102, 21, 71, 255}, 
   { 0.17, -0.71, -16.56, 1, 0x073d, 0x0892, 79, 0, -98, 255}, 
   { -0.06, -2.30, -16.64, 1, 0x0803, 0x08d7, 56, -68, -90, 255}, 
   { -3.92, -4.37, -6.22, 1, 0x0c58, 0x07d1, -86, -87, -31, 255}, 
   { -3.43, 2.45, -6.72, 1, 0x0852, 0x07c4, -68, 107, 0, 255}, 
   { -2.39, 0.94, -16.41, 1, 0x083a, 0x0d60, -55, 77, -83, 255}, 
   { 0.13, 0.79, -16.50, 1, 0x0679, 0x0d70, 65, 68, -84, 255}, 
   { 2.31, -1.30, -6.50, 1, 0x0452, 0x07b9, 124, -9, -21, 255}, 
   { 1.63, -4.77, -6.28, 1, 0x0310, 0x07d2, 79, -92, -36, 255}, 
   { 2.94, 0.84, -0.37, 1, 0x0543, 0x03e4, 79, 74, 64, 255}, 
   { 2.12, 2.04, -6.78, 1, 0x05bb, 0x079e, 86, 92, -8, 255}, 
   { -2.89, -8.99, 3.94, 1, 0x0f10, 0x0ee2, -58, -73, 85, 255}, 
   { 0.56, -9.20, 3.82, 1, 0x0e8d, 0x0683, 52, -82, 80, 255}, 
};

//Test Object = 5 
Vtx player_left_leg_lower_VertList_0 [] = {
   { 3.63, 4.22, -20.83, 1, 0x0ddf, 68, 90, -56, 255}, 
   { 4.17, -3.52, -16.63, 1, 0x08ad, 0x0d0c, 85, -22, 90, 255}, 
   { 4.95, -3.63, -21.72, 1, 0x081f, 0x0f32, 99, 4, -78, 255}, 
   { -1.70, 2.70, -15.09, 1, 0x0b52, 0x0bcf, -74, 49, 89, 255}, 
   { 3.08, 2.92, -15.01, 1, 0x0b09, 0x0c85, 60, 60, 93, 255}, 
   { -1.48, -3.92, -21.83, 1, 0x07b5, 0x0970, -92, -6, -87, 255}, 
   { -0.12, -10.23, -19.05, 1, 0x0349, 0x0bb3, -67, -71, 79, 255}, 
   { -1.03, -3.76, -16.72, 1, 0x0888, 0x0b77, -83, -36, 88, 255}, 
   { 3.91, -11.57, -21.90, 1, 0x00e8, 0x0d5a, 73, -89, -52, 255}, 
   { -0.42, -11.76, -21.98, 1, 0x00e8, 0x0b3e, -66, -93, -54, 255}, 
   { 3.37, -10.07, -18.99, 1, 0x034c, 0x0cdd, 66, -69, 83, 255}, 
   { -2.28, 3.96, -20.94, 1, 0x002e, 0x0451, -81, 77, -58, 255}, 
   { 4.43, -1.08, -6.81, 1, 0x0a77, 0x079d, 126, 8, -10, 255}, 
   { 2.44, -2.15, -16.82, 1, 0x0a0f, 0x0d7a, 62, -63, -90, 255}, 
   { 2.84, -0.73, -16.55, 1, 0x0955, 0x0d1e, 95, 7, -82, 255}, 
   { 3.47, 0.88, -0.63, 1, 0x0a0f, 0x03ec, 59, 84, 74, 255}, 
   { -3.24, -2.12, 0.07, 1, 0x0d2e, 0x0313, -102, 8, 75, 255}, 
   { 4.69, -2.30, -0.03, 1, 0x0a98, 0x0562, 102, 21, 71, 255}, 
   { -0.30, -0.71, -16.83, 1, 0x0f47, 0x0abf, -79, 0, -98, 255}, 
   { -0.07, -2.30, -16.91, 1, 0x0f39, 0x0ba5, -56, -68, -90, 255}, 
   { 3.79, -4.37, -6.49, 1, 0x0c40, 0x07a6, 86, -87, -31, 255}, 
   { 3.30, 2.45, -6.99, 1, 0x0877, 0x07a4, 68, 107, 0, 255}, 
   { 2.25, 0.94, -16.68, 1, 0x0dd6, 0x09ef, 55, 77, -83, 255}, 
   { -0.27, 0.79, -16.77, 1, 0x06bf, 0x0d14, -65, 68, -84, 255}, 
   { -2.44, -1.30, -6.77, 1, 0x0498, 0x07a6, -124, -9, -21, 255}, 
   { -1.77, -4.77, -6.55, 1, 0x0308, 0x07ed, -79, -92, -36, 255}, 
   { -0.70, -9.20, 3.55, 1, 0x00ff, 0x01fb, -52, -82, 80, 255}, 
   { -3.08, 0.84, -0.64, 1, 0x0577, 0x03fb, -79, 74, 64, 255}, 
   { -2.26, 2.04, -7.05, 1, 0x05ff, 0x0788, -86, 92, -8, 255}, 
   { 2.76, -8.99, 3.67, 1, 0x0ebf, 0x0eea, 58, -73, 85, 255}, 
};

//Test Object = 6 
Vtx player_left_leg_VertList_0 [] = {
   { 5.20, -5.25, 2.47, 1, 0x094e, 0x013b, 48, -74, 90, 255}, 
   { -1.73, -1.09, 0.13, 1, 0x0665, 0x04bf, -105, -8, 69, 255}, 
   { 0.07, -6.29, -0.14, 1, 0x095c, 0x0467, -61, -97, 53, 255}, 
   { 4.52, -3.06, -21.51, 1, 0x0aa1, 0x0b18, 64, -64, -88, 255}, 
   { 0.55, -1.32, -21.49, 1, 0x0d65, 0x0fff, -84, -5, -94, 255}, 
   { 4.87, -1.10, -21.31, 1, 0x0d22, 0x0a62, 89, 10, -89, 255}, 
   { -1.09, 3.85, -0.14, 1, 0x03c9, 0x0403, -80, 82, 52, 255}, 
   { 5.93, -0.70, 2.99, 1, 0x06f4, 0x0058, 68, 2, 106, 255}, 
   { 5.12, 4.34, 2.39, 1, 0x0429, 0x0062, 45, 84, 83, 255}, 
   { 1.14, -3.41, -21.39, 1, 0x038e, 0x0ae5, -53, -79, -83, 255}, 
   { -1.93, -1.43, -9.02, 1, 0x04d9, 0x04fd, -126, -10, -10, 255}, 
   { -1.23, 3.01, -9.51, 1, 0x0ea5, 0x07bc, -85, 91, -19, 255}, 
   { 4.24, 1.01, -21.23, 1, 0x0cf4, 0x0f99, 55, 78, -82, 255}, 
   { 0.82, 0.71, -21.47, 1, 0x0ecc, 0x0f22, -61, 67, -88, 255}, 
   { 7.40, -0.98, -7.89, 1, 0x0a66, 0x076d, 126, 6, -5, 255}, 
   { 6.09, 3.65, -6.93, 1, 0x0853, 0x075a, 77, 100, -9, 255}, 
   { 6.69, -5.28, -7.02, 1, 0x0c13, 0x06aa, 90, -88, -4, 255}, 
   { -0.50, -6.10, -8.79, 1, 0x0f15, 0x0762, -68, -105, -14, 255}, 
};

//Test Object = 7 
Vtx player_left_arm_VertList_0 [] = {
   { 0.66, -3.28, -4.57, 1, 0x0361, 0x05a1, -110, -56, -26, 255}, 
   { 5.26, -2.75, -15.11, 1, 0x0316, 0x0c62, -13, -86, -91, 255}, 
   { 5.39, -5.74, -3.61, 1, 0x0026, 0x05b3, 23, -124, -7, 255}, 
   { 0.07, -3.40, 0.02, 1, 0x035b, 0x02d3, -104, -63, 34, 255}, 
   { 2.41, 5.94, -4.30, 1, 0x0859, 0x05f9, -52, 110, -32, 255}, 
   { 10.27, 0.44, -3.85, 1, 0x09dc, 0x07c8, 126, 8, -5, 255}, 
   { 7.86, -3.76, 4.82, 1, 0x0a82, 0x0e40, 56, -59, 96, 255}, 
   { 7.39, 4.61, -1.37, 1, 0x0624, 0x085c, 79, 97, 17, 255}, 
   { 0.39, 4.59, 2.89, 1, 0x0874, 0x01bc, -94, 61, 58, 255}, 
   { 6.37, -0.24, -15.55, 1, 0x0bd7, 0x0000, 44, 41, -111, 255}, 
   { 3.74, 0.39, -14.53, 1, 0x053b, 0x0bd5, -79, 49, -86, 255}, 
   { 8.05, -1.03, -13.46, 1, 0x0688, 0x0f15, 116, -7, -50, 255}, 
   { 3.34, 4.53, 4.23, 1, 0x0bd3, 0x0033, 7, 72, 103, 255}, 
};

//Test Object = 8 
Vtx player_right_leg_VertList_0 [] = {
   { 1.44, -1.09, 0.04, 1, 0x05d6, 0x03cc, 105, -8, 69, 255}, 
   { -5.50, -5.25, 2.39, 1, 0x0492, 0x004c, -48, -74, 90, 255}, 
   { -0.36, -6.29, -0.22, 1, 0x0364, 0x029d, 61, -97, 53, 255}, 
   { -4.81, -3.06, -21.60, 1, 0x0aa6, 0x0f50, -64, -64, -88, 255}, 
   { -0.84, -1.32, -21.58, 1, 0x0d5f, 0x0a58, 84, -5, -94, 255}, 
   { -1.43, -3.41, -21.48, 1, 0x0a98, 0x0add, 53, -79, -83, 255}, 
   { 0.80, 3.85, -0.23, 1, 0x085a, 0x0415, 80, 82, 52, 255}, 
   { -6.22, -0.70, 2.90, 1, 0x06ec, 0x0063, -68, 2, 106, 255}, 
   { 1.64, -1.43, -9.11, 1, 0x04d1, 0x0507, 126, -10, -10, 255}, 
   { 0.94, 3.01, -9.60, 1, 0x0f0f, 0x07f1, 85, 91, -19, 255}, 
   { -4.53, 1.01, -21.32, 1, 0x0caa, 0x0f32, -55, 78, -82, 255}, 
   { -6.38, 3.65, -7.02, 1, 0x0a92, 0x05f4, -77, 100, -9, 255}, 
   { -7.70, -0.98, -7.98, 1, 0x0a7c, 0x0841, -126, 6, -5, 255}, 
   { -6.98, -5.28, -7.11, 1, 0x0c0f, 0x072d, -90, -88, -4, 255}, 
   { -1.11, 0.71, -21.55, 1, 0x06de, 0x0ae0, 61, 67, -88, 255}, 
   { -5.16, -1.10, -21.40, 1, 0x0bd1, 0x0f7c, -89, 10, -89, 255}, 
   { -5.41, 4.34, 2.30, 1, 0x0b1e, 0x0008, -45, 84, 83, 255}, 
   { 0.21, -6.10, -8.88, 1, 0x0ef0, 0x0777, 68, -105, -14, 255}, 
};

//Test Object = 9 
Vtx player_right_arm_VertList_0 [] = {
   { -0.83, -3.28, -4.70, 1, 0x030c, 0x0613, 110, -56, -26, 255}, 
   { -5.57, -5.74, -3.74, 1, 0x0042, 0x0686, -23, -124, -7, 255}, 
   { -5.43, -2.75, -15.23, 1, 0x039b, 0x0bf5, 13, -86, -91, 255}, 
   { -2.59, 5.94, -4.42, 1, 0x0764, 0x05c5, 54, 106, -43, 255}, 
   { -0.24, -3.40, -0.10, 1, 0x02b0, 0x03a6, 104, -63, 34, 255}, 
   { -10.44, 0.44, -3.98, 1, 0x0aab, 0x088e, -126, 8, -5, 255}, 
   { -8.03, -3.76, 4.69, 1, 0x0c9d, 0x0ded, -55, -61, 95, 255}, 
   { -7.56, 4.61, -1.50, 1, 0x07a0, 0x09da, -90, 89, 5, 255}, 
   { -0.56, 4.59, 2.76, 1, 0x06f9, 0x0217, 109, 31, 56, 255}, 
   { -6.55, -0.24, -15.68, 1, 0x0aad, 0x0180, -44, 41, -111, 255}, 
   { -3.92, 0.39, -14.65, 1, 0x0566, 0x0b39, 79, 49, -86, 255}, 
   { -8.23, -1.03, -13.59, 1, 0x06eb, 0x0de1, -116, -7, -50, 255}, 
   { -3.52, 7.25, 4.06, 1, 0x09b5, 0x005a, 0, 98, 80, 255}, 
};


 
 
/*

VERTEX COLOR VERSIONS:

Vtx player_head_VertList_0 [] = {
  { -9.62, 0.37, 10.20, 1, 0x08b7, 0x0a23, 62, 156, 151, 255}, 
   { -9.51, 8.71, 13.29, 1, 0x07a8, 0x0f8e, 62, 156, 151, 255}, 
   { -9.83, 0.24, 7.65, 1, 0x075a, 0x0940, 62, 156, 151, 255}, 
   { -8.73, 9.20, 13.11, 1, 0x0401, 0x094c, 62, 156, 151, 255}, 
   { -8.17, -0.18, 7.23, 1, 0x01a5, 0x1003, 62, 156, 151, 255}, 
   { -8.68, 5.16, 8.32, 1, 0x03f2, 0x0d50, 62, 156, 151, 255}, 
   { -9.97, 2.76, 7.02, 1, 0x062d, 0x0a62, 62, 156, 151, 255}, 
   { -8.46, 1.69, 6.38, 1, 0x0623, 0x09a6, 62, 156, 151, 255}, 
   { -8.41, 7.70, 14.65, 1, 0x08b7, 0x0f7b, 62, 156, 151, 255}, 
   { -3.65, -7.74, 1.10, 1, 0x00c3, 0x04b0, 62, 156, 151, 255}, 
   { -5.15, -7.33, 5.21, 1, 0x01ee, 0x054d, 62, 156, 151, 255}, 
   { -7.21, 0.97, 5.13, 1, 0x0598, 0x062c, 62, 156, 151, 255}, 
   { -6.80, -3.07, 7.43, 1, 0x0458, 0x05fe, 62, 156, 151, 255}, 
   { -5.72, 0.82, 1.57, 1, 0x04ac, 0x0591, 62, 156, 151, 255}, 
   { -0.04, 7.79, 5.97, 1, 0x0899, 0x034a, 62, 156, 151, 255}, 
   { -5.18, 6.74, 3.90, 1, 0x07ca, 0x0560, 62, 156, 151, 255}, 
   { -5.48, 7.47, 6.02, 1, 0x089a, 0x0580, 62, 156, 151, 255}, 
   { -0.04, -7.16, 10.32, 1, 0x0a3a, 0x0714, 62, 156, 151, 255}, 
   { -2.20, -4.15, 12.86, 1, 0x0bda, 0x0990, 62, 156, 151, 255}, 
   { -4.79, -6.45, 10.40, 1, 0x0e04, 0x0782, 62, 156, 151, 255}, 
   { 9.59, 8.82, 13.22, 1, 0x0792, 0x0f7a, 62, 156, 151, 255}, 
   { 9.46, 7.58, 14.28, 1, 0x0890, 0x0f28, 62, 156, 151, 255}, 
   { 9.72, 0.47, 10.15, 1, 0x08a5, 0x0a0f, 62, 156, 151, 255}, 
   { 9.90, 1.35, 8.21, 1, 0x0749, 0x09e7, 62, 156, 151, 255}, 
   { 8.43, 0.88, 6.42, 1, 0x010e, 0x0f8f, 62, 156, 151, 255}, 
   { 8.80, 9.31, 13.06, 1, 0x02a7, 0x08dc, 62, 156, 151, 255}, 
   { 8.75, 5.26, 8.27, 1, 0x00eb, 0x0c84, 62, 156, 151, 255}, 
   { -0.04, 0.84, 0.51, 1, 0x044c, 0x0342, 62, 156, 151, 255}, 
   { -0.18, -8.18, 0.09, 1, 0x0041, 0x0346, 62, 156, 151, 255}, 
   { 8.48, 7.80, 14.60, 1, 0x08a5, 0x0f66, 62, 156, 151, 255}, 
   { 10.03, 1.91, 6.83, 1, 0x0657, 0x09c1, 62, 156, 151, 255}, 
   { 5.08, -7.32, 5.24, 1, 0x01b0, 0x0125, 62, 156, 151, 255}, 
   { 3.61, -7.75, 1.19, 1, 0x009b, 0x01bd, 62, 156, 151, 255}, 
   { 7.17, 0.95, 5.27, 1, 0x0543, 0x0055, 62, 156, 151, 255}, 
   { 6.72, -3.04, 7.40, 1, 0x0405, 0x007f, 62, 156, 151, 255}, 
   { 5.65, 0.82, 1.57, 1, 0x0465, 0x00f3, 62, 156, 151, 255}, 
   { 5.24, 6.57, 4.00, 1, 0x077c, 0x0123, 62, 156, 151, 255}, 
   { -3.37, 4.38, 12.59, 1, 0x0c82, 0x0e90, 62, 156, 151, 255}, 
   { -0.04, 6.78, 11.87, 1, 0x09c1, 0x0fce, 62, 156, 151, 255}, 
   { -4.81, 6.50, 11.01, 1, 0x0d99, 0x0f64, 62, 156, 151, 255}, 
   { -7.21, 0.97, 5.13, 1, 0x0ebe, 0x0555, 62, 156, 151, 255}, 
   { -6.56, 1.19, 12.25, 1, 0x0d76, 0x031d, 62, 156, 151, 255}, 
   { -4.81, 6.50, 11.01, 1, 0x0950, 0x053a, 62, 156, 151, 255}, 
   { -0.04, 7.79, 5.97, 1, 0x0899, 0x034a, 62, 156, 151, 255}, 
   { -5.48, 7.47, 6.02, 1, 0x089a, 0x0580, 62, 156, 151, 255}, 
   { 4.34, -2.00, 12.57, 1, 0x0689, 0x0ac7, 62, 156, 151, 255}, 
   { 6.49, 1.19, 12.25, 1, 0x04b5, 0x0c99, 62, 156, 151, 255}, 
   { 4.53, 0.67, 13.45, 1, 0x064b, 0x0c9d, 62, 156, 151, 255}, 
   { -5.18, 6.74, 3.90, 1, 0x07ca, 0x0560, 62, 156, 151, 255}, 
   { -6.80, -3.07, 7.43, 1, 0x0294, 0x0643, 62, 156, 151, 255}, 
   { -6.52, -3.07, 10.67, 1, 0x02b6, 0x072c, 62, 156, 151, 255}, 
   { -2.20, -4.15, 12.86, 1, 0x0bda, 0x0990, 62, 156, 151, 255}, 
   { -4.41, -2.00, 12.57, 1, 0x0d8e, 0x0ac1, 62, 156, 151, 255}, 
   { -8.02, 2.35, 12.12, 1, 0x00e0, 0x0c8e, 62, 156, 151, 255}, 
   { -8.73, 9.20, 13.11, 1, 0x0401, 0x094c, 62, 156, 151, 255}, 
   { -8.41, 7.70, 14.65, 1, 0x0291, 0x0923, 62, 156, 151, 255}, 
   { -9.51, 8.71, 13.29, 1, 0x07a8, 0x0f8e, 62, 156, 151, 255}, 
   { -9.62, 0.37, 10.20, 1, 0x08b7, 0x0a23, 62, 156, 151, 255}, 
   { -9.39, 7.48, 14.34, 1, 0x08a3, 0x0f3d, 62, 156, 151, 255}, 
   { -9.97, 2.76, 7.02, 1, 0x062d, 0x0a62, 62, 156, 151, 255}, 
   { -9.83, 0.24, 7.65, 1, 0x075a, 0x0940, 62, 156, 151, 255}, 
   { -9.51, 8.71, 13.29, 1, 0x07a8, 0x0f8e, 62, 156, 151, 255}, 
   { -8.68, 5.16, 8.32, 1, 0x0611, 0x0c1a, 62, 156, 151, 255}, 
   { -8.46, 1.69, 6.38, 1, 0x02fa, 0x0fae, 62, 156, 151, 255}, 
   { -8.68, 5.16, 8.32, 1, 0x03f2, 0x0d50, 62, 156, 151, 255}, 
   { -8.17, -0.18, 7.23, 1, 0x01a5, 0x1003, 62, 156, 151, 255}, 
   { -7.94, -0.50, 9.35, 1, 0x0094, 0x0f16, 62, 156, 151, 255}, 
   { -4.79, -6.45, 10.40, 1, 0x03d2, 0x06ef, 62, 156, 151, 255}, 
   { -6.80, -3.07, 7.43, 1, 0x0030, 0x08db, 62, 156, 151, 255}, 
   { -5.15, -7.33, 5.21, 1, 0x0388, 0x0b80, 62, 156, 151, 255}, 
   { -0.04, -7.16, 10.32, 1, 0x07fd, 0x0716, 62, 156, 151, 255}, 
   { -3.65, -7.74, 1.10, 1, 0x04d2, 0x0f17, 62, 156, 151, 255}, 
   { -0.02, -8.05, 3.65, 1, 0x07fe, 0x0cea, 62, 156, 151, 255}, 
   { 4.74, 6.50, 11.01, 1, 0x0b41, 0x00c1, 62, 156, 151, 255}, 
   { 7.17, 0.95, 5.27, 1, 0x0e87, 0x0559, 62, 156, 151, 255}, 
   { 5.41, 7.47, 6.02, 1, 0x0bfa, 0x0174, 62, 156, 151, 255}, 
   { -0.04, 7.79, 5.97, 1, 0x0899, 0x034a, 62, 156, 151, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x0728, 0x0e95, 62, 156, 151, 255}, 
   { -0.04, 6.78, 11.87, 1, 0x09c1, 0x0fce, 62, 156, 151, 255}, 
   { -0.04, 4.57, 13.19, 1, 0x09d3, 0x0eda, 62, 156, 151, 255}, 
   { 5.24, 6.57, 4.00, 1, 0x077c, 0x0123, 62, 156, 151, 255}, 
   { 6.49, 1.19, 12.25, 1, 0x0285, 0x0a26, 62, 156, 151, 255}, 
   { 6.72, -3.04, 7.40, 1, 0x027f, 0x064b, 62, 156, 151, 255}, 
   { 7.17, 0.95, 5.27, 1, 0x0205, 0x0817, 62, 156, 151, 255}, 
   { 2.84, -3.94, 12.76, 1, 0x07ce, 0x09ad, 62, 156, 151, 255}, 
   { 4.71, -6.47, 10.37, 1, 0x0667, 0x0784, 62, 156, 151, 255}, 
   { 9.90, 1.35, 8.21, 1, 0x0749, 0x09e7, 62, 156, 151, 255}, 
   { 9.92, 5.46, 9.05, 1, 0x0664, 0x0c5a, 62, 156, 151, 255}, 
   { 9.59, 8.82, 13.22, 1, 0x0792, 0x0f7a, 62, 156, 151, 255}, 
   { 8.80, 9.31, 13.06, 1, 0x02a7, 0x08dc, 62, 156, 151, 255}, 
   { 8.09, 2.45, 12.07, 1, 0x0405, 0x0d1e, 62, 156, 151, 255}, 
   { 8.48, 7.80, 14.60, 1, 0x0405, 0x0952, 62, 156, 151, 255}, 
   { 8.01, -0.40, 9.30, 1, 0x0329, 0x0f87, 62, 156, 151, 255}, 
   { 8.43, 0.88, 6.42, 1, 0x010e, 0x0f8f, 62, 156, 151, 255}, 
   { 8.75, 5.26, 8.27, 1, 0x05ff, 0x0c06, 62, 156, 151, 255}, 
   { 9.72, 0.47, 10.15, 1, 0x0940, 0x0a31, 62, 156, 151, 255}, 
   { 9.46, 7.58, 14.28, 1, 0x0989, 0x0f73, 62, 156, 151, 255}, 
   { 5.08, -7.32, 5.24, 1, 0x0c71, 0x0b7e, 62, 156, 151, 255}, 
   { -0.04, -7.16, 10.32, 1, 0x07fd, 0x0716, 62, 156, 151, 255}, 
   { -0.02, -8.05, 3.65, 1, 0x07fe, 0x0cea, 62, 156, 151, 255}, 
   { 3.61, -7.75, 1.19, 1, 0x0b27, 0x0f05, 62, 156, 151, 255}, 
   { 5.08, -7.32, 5.24, 1, 0x0c71, 0x0b7e, 62, 156, 151, 255}, 
   { 3.00, 4.08, 14.04, 1, 0x07e4, 0x0185, 62, 156, 151, 255}, 
   { -2.78, 4.21, 14.31, 1, 0x02eb, 0x0199, 62, 156, 151, 255}, 
   { -4.02, -1.72, 14.02, 1, 0x01a5, 0x06c1, 62, 156, 151, 255}, 
   { -0.04, -2.74, 13.55, 1, 0x054d, 0x08df, 62, 156, 151, 255}, 
   { -0.04, -2.40, 14.91, 1, 0x054b, 0x0750, 62, 156, 151, 255}, 
   { -0.04, -2.74, 13.55, 1, 0x0a10, 0x0a98, 62, 156, 151, 255}, 
   { -4.41, -2.00, 12.57, 1, 0x0d8e, 0x0ac1, 62, 156, 151, 255}, 
   { -2.20, -4.15, 12.86, 1, 0x0bda, 0x0990, 62, 156, 151, 255}, 
   { 3.00, 4.08, 14.04, 1, 0x07e4, 0x0185, 62, 156, 151, 255}, 
   { 4.53, 0.67, 13.45, 1, 0x0a5b, 0x0458, 62, 156, 151, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x08c3, 0x0047, 62, 156, 151, 255}, 
   { 2.84, -3.94, 12.76, 1, 0x07ce, 0x09ad, 62, 156, 151, 255}, 
   { -0.04, -2.74, 13.55, 1, 0x0a10, 0x0a98, 62, 156, 151, 255}, 
   { -2.20, -4.15, 12.86, 1, 0x0bda, 0x0990, 62, 156, 151, 255}, 
   { 3.95, -1.72, 14.02, 1, 0x08ef, 0x06b5, 62, 156, 151, 255}, 
   { 4.12, 0.71, 14.82, 1, 0x08c2, 0x0473, 62, 156, 151, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x0728, 0x0e95, 62, 156, 151, 255}, 
   { 6.49, 1.19, 12.25, 1, 0x04b5, 0x0c99, 62, 156, 151, 255}, 
   { 4.74, 6.50, 11.01, 1, 0x05f1, 0x0f6b, 62, 156, 151, 255}, 
   { -4.41, -2.00, 12.57, 1, 0x0d8e, 0x0ac1, 62, 156, 151, 255}, 
   { -6.56, 1.19, 12.25, 1, 0x0f2c, 0x0c91, 62, 156, 151, 255}, 
   { -6.52, -3.07, 10.67, 1, 0x0f49, 0x0998, 62, 156, 151, 255}, 
   { 6.43, -3.04, 10.70, 1, 0x04e7, 0x09a7, 62, 156, 151, 255}, 
   { 4.34, -2.00, 12.57, 1, 0x0689, 0x0ac7, 62, 156, 151, 255}, 
   { -3.37, 4.38, 12.59, 1, 0x0c82, 0x0e90, 62, 156, 151, 255}, 
   { -4.60, 0.67, 13.45, 1, 0x0d9c, 0x0c96, 62, 156, 151, 255}, 
   { -4.02, -1.72, 14.02, 1, 0x01a5, 0x06c1, 62, 156, 151, 255}, 
   { -0.04, 0.68, 15.37, 1, 0x0546, 0x04a1, 62, 156, 151, 255}, 
   { -4.19, 0.71, 14.82, 1, 0x01cd, 0x047d, 62, 156, 151, 255}, 
   { -2.78, 4.21, 14.31, 1, 0x02eb, 0x0199, 62, 156, 151, 255}, 
   { -0.04, 4.57, 13.19, 1, 0x053d, 0x006a, 62, 156, 151, 255}, 
   { 5.24, 6.57, 4.00, 1, 0x077c, 0x0123, 62, 156, 151, 255}, 
   { -0.04, 0.84, 0.51, 1, 0x044c, 0x0342, 62, 156, 151, 255}, 
   { -5.18, 6.74, 3.90, 1, 0x07ca, 0x0560, 62, 156, 151, 255}, 
   { -3.65, -7.74, 1.10, 1, 0x00c3, 0x04b0, 62, 156, 151, 255}, 
   { -5.72, 0.82, 1.57, 1, 0x04ac, 0x0591, 62, 156, 151, 255}, 
   { -0.04, 0.84, 0.51, 1, 0x044c, 0x0342, 62, 156, 151, 255}, 
   { -0.04, 6.78, 11.87, 1, 0x09c1, 0x0fce, 62, 156, 151, 255}, 
   { -4.81, 6.50, 11.01, 1, 0x0950, 0x053a, 62, 156, 151, 255}, 
   { -0.04, 6.78, 11.87, 1, 0x0983, 0x034a, 62, 156, 151, 255}, 
   { -0.04, 7.79, 5.97, 1, 0x0899, 0x034a, 62, 156, 151, 255}, 
   { -6.56, 1.19, 12.25, 1, 0x027b, 0x0a22, 62, 156, 151, 255}, 
   { -7.21, 0.97, 5.13, 1, 0x022b, 0x0800, 62, 156, 151, 255}, 
   { -6.80, -3.07, 7.43, 1, 0x0294, 0x0643, 62, 156, 151, 255}, 
   { -6.52, -3.07, 10.67, 1, 0x0f49, 0x0998, 62, 156, 151, 255}, 
   { -4.79, -6.45, 10.40, 1, 0x0e04, 0x0782, 62, 156, 151, 255}, 
   { -2.20, -4.15, 12.86, 1, 0x0bda, 0x0990, 62, 156, 151, 255}, 
   { -5.15, -7.33, 5.21, 1, 0x0388, 0x0b80, 62, 156, 151, 255}, 
   { -0.02, -8.05, 3.65, 1, 0x07fe, 0x0cea, 62, 156, 151, 255}, 
   { -0.04, -7.16, 10.32, 1, 0x07fd, 0x0716, 62, 156, 151, 255}, 
   { -0.18, -8.18, 0.09, 1, 0x07da, 0x0fff, 62, 156, 151, 255}, 
   { 3.61, -7.75, 1.19, 1, 0x009b, 0x01bd, 62, 156, 151, 255}, 
   { 4.74, 6.50, 11.01, 1, 0x0eed, 0x052b, 62, 156, 151, 255}, 
   { 6.49, 1.19, 12.25, 1, 0x0d46, 0x0269, 62, 156, 151, 255}, 
   { 7.17, 0.95, 5.27, 1, 0x0b9b, 0x0081, 62, 156, 151, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x0728, 0x0e95, 62, 156, 151, 255}, 
   { 6.49, 1.19, 12.25, 1, 0x0285, 0x0a26, 62, 156, 151, 255}, 
   { 6.43, -3.04, 10.70, 1, 0x02b7, 0x0734, 62, 156, 151, 255}, 
   { 6.72, -3.04, 7.40, 1, 0x027f, 0x064b, 62, 156, 151, 255}, 
   { 2.84, -3.94, 12.76, 1, 0x07ce, 0x09ad, 62, 156, 151, 255}, 
   { 9.90, 1.35, 8.21, 1, 0x0749, 0x09e7, 62, 156, 151, 255}, 
   { 10.03, 1.91, 6.83, 1, 0x0657, 0x09c1, 62, 156, 151, 255}, 
   { 9.92, 5.46, 9.05, 1, 0x0664, 0x0c5a, 62, 156, 151, 255}, 
   { 8.75, 5.26, 8.27, 1, 0x05ff, 0x0c06, 62, 156, 151, 255}, 
   { 8.80, 9.31, 13.06, 1, 0x074c, 0x0fb3, 62, 156, 151, 255}, 
   { 9.59, 8.82, 13.22, 1, 0x0792, 0x0f7a, 62, 156, 151, 255}, 
   { 9.92, 5.46, 9.05, 1, 0x0664, 0x0c5a, 62, 156, 151, 255}, 
   { 9.90, 1.35, 8.21, 1, 0x0749, 0x09e7, 62, 156, 151, 255}, 
   { 9.72, 0.47, 10.15, 1, 0x08a5, 0x0a0f, 62, 156, 151, 255}, 
   { 8.01, -0.40, 9.30, 1, 0x086c, 0x095f, 62, 156, 151, 255}, 
   { 4.71, -6.47, 10.37, 1, 0x0c26, 0x06f8, 62, 156, 151, 255}, 
   { 5.08, -7.32, 5.24, 1, 0x0c71, 0x0b7e, 62, 156, 151, 255}, 
   { 3.00, 4.08, 14.04, 1, 0x07e4, 0x0185, 62, 156, 151, 255}, 
   { 3.30, 4.38, 12.59, 1, 0x08c3, 0x0047, 62, 156, 151, 255}, 
   { -0.04, 4.57, 13.19, 1, 0x053d, 0x006a, 62, 156, 151, 255}, 
   { 3.00, 4.08, 14.04, 1, 0x07e4, 0x0185, 62, 156, 151, 255}, 
   { 4.12, 0.71, 14.82, 1, 0x08c2, 0x0473, 62, 156, 151, 255}, 
   { 4.53, 0.67, 13.45, 1, 0x0a5b, 0x0458, 62, 156, 151, 255}, 
   { 2.84, -3.94, 12.76, 1, 0x07ce, 0x09ad, 62, 156, 151, 255}, 
   { 4.34, -2.00, 12.57, 1, 0x0689, 0x0ac7, 62, 156, 151, 255}, 
   { -0.04, -2.74, 13.55, 1, 0x0a10, 0x0a98, 62, 156, 151, 255}, 
   { 3.95, -1.72, 14.02, 1, 0x08ef, 0x06b5, 62, 156, 151, 255}, 
   { -0.04, 0.68, 15.37, 1, 0x0546, 0x04a1, 62, 156, 151, 255}, 
   { -0.04, -2.40, 14.91, 1, 0x054b, 0x0750, 62, 156, 151, 255}, 
   { 5.24, 6.57, 4.00, 1, 0x077c, 0x0123, 62, 156, 151, 255}, 
   { 5.65, 0.82, 1.57, 1, 0x0465, 0x00f3, 62, 156, 151, 255}, 
   { -0.04, 0.84, 0.51, 1, 0x044c, 0x0342, 62, 156, 151, 255},   
};

Vtx player_chest_VertList_0 [] = {
    { -0.11, 21.54, 60.58, 1, 0x0b43, 0x0ac7, 62, 156, 151, 255}, 
   { -24.62, 18.69, 54.52, 1, 0x084b, 0x0bb5, 62, 156, 151, 255}, 
   { -19.83, 29.07, 32.84, 1, 0x0942, 0x0e8b, 62, 156, 151, 255}, 
   { 0.04, 31.20, 30.13, 1, 0x0bb9, 0x0ea9, 62, 156, 151, 255}, 
   { 20.00, 28.48, 32.10, 1, 0x0e20, 0x0e0d, 62, 156, 151, 255}, 
   { 26.43, 14.92, 54.48, 1, 0x0eb1, 0x0ace, 62, 156, 151, 255}, 
   { -1.00, 25.54, 62.30, 1, 0x0b42, 0x0ac7, 62, 156, 151, 255}, 
   { -20.72, 33.07, 34.56, 1, 0x0940, 0x0e8b, 62, 156, 151, 255}, 
   { -25.51, 22.69, 56.24, 1, 0x084a, 0x0bb4, 62, 156, 151, 255}, 
   { 19.12, 32.48, 33.82, 1, 0x0e1e, 0x0e0e, 62, 156, 151, 255}, 
   { -0.85, 35.20, 31.85, 1, 0x0bb7, 0x0ea9, 62, 156, 151, 255}, 
   { 25.54, 18.93, 56.20, 1, 0x0eb0, 0x0acf, 62, 156, 151, 255}, 
   { 29.38, 12.91, 51.48, 1, 0x09e5, 0x059a, 62, 156, 151, 255}, 
   { 8.79, -8.95, 56.92, 1, 0x0c23, 0x066a, 62, 156, 151, 255}, 
   { 29.38, -13.60, 51.60, 1, 0x0bd7, 0x039f, 62, 156, 151, 255}, 
   { -16.38, -16.35, 0.48, 1, 0x004a, 0x03a7, 62, 156, 151, 255}, 
   { 0.11, -18.85, -7.92, 1, 0x02b3, 0x01e4, 62, 156, 151, 255}, 
   { 0.11, -17.38, 0.48, 1, 0x01d0, 0x004a, 62, 156, 151, 255}, 
   { 22.15, -23.93, 20.19, 1, 0x0d8c, 0x0a20, 62, 156, 151, 255}, 
   { 0.11, -27.23, 33.83, 1, 0x0818, 0x06bf, 62, 156, 151, 255}, 
   { 0.11, -25.59, 24.61, 1, 0x0819, 0x0909, 62, 156, 151, 255}, 
   { -27.27, -25.57, 29.41, 1, 0x0a86, 0x0f3c, 62, 156, 151, 255}, 
   { -29.17, 12.91, 51.48, 1, 0x0a2e, 0x098e, 62, 156, 151, 255}, 
   { -27.27, 15.40, 29.37, 1, 0x0870, 0x09f6, 62, 156, 151, 255}, 
   { 16.59, -16.35, 0.48, 1, 0x04c0, 0x011e, 62, 156, 151, 255}, 
   { 22.15, 12.65, 20.19, 1, 0x0747, 0x0537, 62, 156, 151, 255}, 
   { 0.11, 20.31, 51.48, 1, 0x09b3, 0x0794, 62, 156, 151, 255}, 
   { 0.11, 15.53, 33.80, 1, 0x082f, 0x0792, 62, 156, 151, 255}, 
   { -21.94, -23.93, 20.19, 1, 0x089b, 0x0f90, 62, 156, 151, 255}, 
   { -21.94, 12.65, 20.19, 1, 0x0742, 0x0a28, 62, 156, 151, 255}, 
   { 0.11, 12.78, 24.62, 1, 0x0736, 0x0799, 62, 156, 151, 255}, 
   { 27.48, -25.57, 29.41, 1, 0x09b4, 0x0078, 62, 156, 151, 255}, 
   { 0.11, -21.00, 51.60, 1, 0x0820, 0x021e, 62, 156, 151, 255}, 
   { -16.38, 10.03, 0.62, 1, 0x0439, 0x0a64, 62, 156, 151, 255}, 
   { 0.11, 12.87, 0.62, 1, 0x03f9, 0x0798, 62, 156, 151, 255}, 
   { 27.48, 15.40, 29.37, 1, 0x084e, 0x0544, 62, 156, 151, 255}, 
   { 16.59, 10.03, 0.62, 1, 0x048c, 0x051d, 62, 156, 151, 255}, 
   { -29.17, -13.60, 51.60, 1, 0x00a2, 0x0192, 62, 156, 151, 255}, 
   { 20.02, -17.70, -7.92, 1, 0x04bb, 0x01b5, 62, 156, 151, 255}, 
   { 8.79, 8.28, 56.87, 1, 0x0aa7, 0x06da, 62, 156, 151, 255}, 
   { 29.38, 12.91, 51.48, 1, 0x09e5, 0x059a, 62, 156, 151, 255}, 
   { 0.11, -8.95, 56.92, 1, 0x0c8b, 0x074f, 62, 156, 151, 255}, 
   { -5.59, -5.96, 66.24, 1, 0x0bbd, 0x07b2, 62, 156, 151, 255}, 
   { -8.58, -8.95, 56.92, 1, 0x0c61, 0x0873, 62, 156, 151, 255}, 
   { 8.79, -8.95, 56.92, 1, 0x0c23, 0x066a, 62, 156, 151, 255}, 
   { 0.11, -5.96, 66.24, 1, 0x0bb8, 0x0769, 62, 156, 151, 255}, 
   { -8.58, 8.28, 56.87, 1, 0x0aa8, 0x083c, 62, 156, 151, 255}, 
   { 29.38, -13.60, 51.60, 1, 0x0bd7, 0x039f, 62, 156, 151, 255}, 
   { -29.17, 12.91, 51.48, 1, 0x0a2e, 0x098e, 62, 156, 151, 255}, 
   { 0.11, 8.28, 56.87, 1, 0x0aa5, 0x078d, 62, 156, 151, 255}, 
   { 0.11, 5.34, 66.21, 1, 0x0b2e, 0x0785, 62, 156, 151, 255}, 
   { 5.80, 5.34, 66.21, 1, 0x0b28, 0x0748, 62, 156, 151, 255}, 
   { 5.80, -5.96, 66.24, 1, 0x0b99, 0x071f, 62, 156, 151, 255}, 
   { -5.59, 5.34, 66.21, 1, 0x0b3d, 0x07cb, 62, 156, 151, 255}, 
   { 0.11, 13.36, -7.76, 1, 0x055b, 0x0565, 62, 156, 151, 255}, 
   { -8.13, 3.64, -19.93, 1, 0x03e1, 0x046f, 62, 156, 151, 255}, 
   { -19.81, 11.47, -7.76, 1, 0x034c, 0x0592, 62, 156, 151, 255}, 
   { 0.11, -18.85, -7.92, 1, 0x02b3, 0x01e4, 62, 156, 151, 255}, 
   { 8.34, -9.72, -19.99, 1, 0x0426, 0x02d0, 62, 156, 151, 255}, 
   { -16.38, 10.03, 0.62, 1, 0x02d4, 0x0701, 62, 156, 151, 255}, 
   { -19.81, -17.70, -7.92, 1, 0x01cc, 0x03cc, 62, 156, 151, 255}, 
   { -16.38, -16.35, 0.48, 1, 0x004a, 0x03a7, 62, 156, 151, 255}, 
   { 16.59, -16.35, 0.48, 1, 0x0527, 0x004a, 62, 156, 151, 255}, 
   { 20.02, 11.47, -7.76, 1, 0x0640, 0x0374, 62, 156, 151, 255}, 
   { 16.59, 10.03, 0.62, 1, 0x07c3, 0x0392, 62, 156, 151, 255}, 
   { 0.11, 5.91, -22.16, 1, 0x0472, 0x0412, 62, 156, 151, 255}, 
   { 0.11, -10.19, -22.23, 1, 0x03a7, 0x033d, 62, 156, 151, 255}, 
   { -8.13, -9.72, -19.99, 1, 0x0335, 0x03bc, 62, 156, 151, 255}, 
   { 20.02, -17.70, -7.92, 1, 0x04bb, 0x01b5, 62, 156, 151, 255}, 
   { 8.34, 5.82, -19.93, 1, 0x04e5, 0x0399, 62, 156, 151, 255}, 
   { -27.27, -25.57, 29.41, 1, 0x0a86, 0x0f3c, 62, 156, 151, 255}, 
   { -29.17, -13.60, 51.60, 1, 0x0c8a, 0x0b62, 62, 156, 151, 255}, 
   { -29.17, 12.91, 51.48, 1, 0x0a2e, 0x098e, 62, 156, 151, 255}, 
   { 22.15, 12.65, 20.19, 1, 0x0747, 0x0537, 62, 156, 151, 255}, 
   { -27.27, 15.40, 29.37, 1, 0x0870, 0x09f6, 62, 156, 151, 255}, 
   { -29.17, 12.91, 51.48, 1, 0x0a2e, 0x098e, 62, 156, 151, 255}, 
   { 0.11, 20.31, 51.48, 1, 0x09b3, 0x0794, 62, 156, 151, 255}, 
   { -21.94, -23.93, 20.19, 1, 0x089b, 0x0f90, 62, 156, 151, 255}, 
   { -21.94, 12.65, 20.19, 1, 0x0742, 0x0a28, 62, 156, 151, 255}, 
   { -27.27, 15.40, 29.37, 1, 0x0870, 0x09f6, 62, 156, 151, 255}, 
   { 0.11, 15.53, 33.80, 1, 0x082f, 0x0792, 62, 156, 151, 255}, 
   { 0.11, 12.78, 24.62, 1, 0x0736, 0x0799, 62, 156, 151, 255}, 
   { 22.15, -23.93, 20.19, 1, 0x07ff, 0x0059, 62, 156, 151, 255}, 
   { 22.15, 12.65, 20.19, 1, 0x0747, 0x0537, 62, 156, 151, 255}, 
   { 27.48, 15.40, 29.37, 1, 0x084e, 0x0544, 62, 156, 151, 255}, 
   { 0.11, -25.59, 24.61, 1, 0x0819, 0x0909, 62, 156, 151, 255}, 
   { 0.11, -17.38, 0.48, 1, 0x081e, 0x0f50, 62, 156, 151, 255}, 
   { 0.11, 12.87, 0.62, 1, 0x03f9, 0x0798, 62, 156, 151, 255}, 
   { 0.11, -27.23, 33.83, 1, 0x0818, 0x06bf, 62, 156, 151, 255}, 
   { 0.11, -21.00, 51.60, 1, 0x0820, 0x021e, 62, 156, 151, 255}, 
   { -29.17, -13.60, 51.60, 1, 0x00a2, 0x0192, 62, 156, 151, 255}, 
   { 29.38, 12.91, 51.48, 1, 0x09e5, 0x059a, 62, 156, 151, 255}, 
   { 0.11, -18.85, -7.92, 1, 0x02b3, 0x01e4, 62, 156, 151, 255}, 
   { 0.11, 20.31, 51.48, 1, 0x09b3, 0x0794, 62, 156, 151, 255}, 
   { 0.11, 8.28, 56.87, 1, 0x0aa5, 0x078d, 62, 156, 151, 255}, 
   { 8.79, 8.28, 56.87, 1, 0x0aa7, 0x06da, 62, 156, 151, 255}, 
   { -29.17, -13.60, 51.60, 1, 0x0c8a, 0x0b62, 62, 156, 151, 255}, 
   { -8.58, -8.95, 56.92, 1, 0x0c61, 0x0873, 62, 156, 151, 255}, 
   { -8.58, 8.28, 56.87, 1, 0x0aa8, 0x083c, 62, 156, 151, 255}, 
   { 0.11, -8.95, 56.92, 1, 0x0c8b, 0x074f, 62, 156, 151, 255}, 
   { 29.38, -13.60, 51.60, 1, 0x0bd7, 0x039f, 62, 156, 151, 255}, 
   { 8.79, -8.95, 56.92, 1, 0x0c23, 0x066a, 62, 156, 151, 255}, 
   { 0.11, -8.95, 56.92, 1, 0x0c8b, 0x074f, 62, 156, 151, 255}, 
   { 0.11, 8.28, 56.87, 1, 0x0aa5, 0x078d, 62, 156, 151, 255}, 
   { 0.11, 5.34, 66.21, 1, 0x0b2e, 0x0785, 62, 156, 151, 255}, 
   { 5.80, 5.34, 66.21, 1, 0x0b28, 0x0748, 62, 156, 151, 255}, 
   { -5.59, 5.34, 66.21, 1, 0x0b3d, 0x07cb, 62, 156, 151, 255}, 
   { 5.80, -5.96, 66.24, 1, 0x0b99, 0x071f, 62, 156, 151, 255}, 
   { -5.59, -5.96, 66.24, 1, 0x0bbd, 0x07b2, 62, 156, 151, 255}, 
   { 0.11, -18.85, -7.92, 1, 0x02b3, 0x01e4, 62, 156, 151, 255}, 
   { 0.11, -10.19, -22.23, 1, 0x03a7, 0x033d, 62, 156, 151, 255}, 
   { 8.34, -9.72, -19.99, 1, 0x0426, 0x02d0, 62, 156, 151, 255}, 
   { 0.11, 12.87, 0.62, 1, 0x063d, 0x06fa, 62, 156, 151, 255}, 
   { 0.11, 13.36, -7.76, 1, 0x055b, 0x0565, 62, 156, 151, 255}, 
   { -19.81, 11.47, -7.76, 1, 0x034c, 0x0592, 62, 156, 151, 255}, 
   { -16.38, 10.03, 0.62, 1, 0x02d4, 0x0701, 62, 156, 151, 255}, 
   { -19.81, 11.47, -7.76, 1, 0x034c, 0x0592, 62, 156, 151, 255}, 
   { -19.81, -17.70, -7.92, 1, 0x01cc, 0x03cc, 62, 156, 151, 255}, 
   { 0.11, 5.91, -22.16, 1, 0x0472, 0x0412, 62, 156, 151, 255}, 
   { 8.34, 5.82, -19.93, 1, 0x04e5, 0x0399, 62, 156, 151, 255}, 
   { 8.34, -9.72, -19.99, 1, 0x0426, 0x02d0, 62, 156, 151, 255}, 
   { -8.13, 3.64, -19.93, 1, 0x03e1, 0x046f, 62, 156, 151, 255}, 
   { 20.02, 11.47, -7.76, 1, 0x0640, 0x0374, 62, 156, 151, 255}, 
   { 20.02, -17.70, -7.92, 1, 0x04bb, 0x01b5, 62, 156, 151, 255}, 
   { -8.13, -9.72, -19.99, 1, 0x0335, 0x03bc, 62, 156, 151, 255},  
};

Vtx player_right_arm_VertList_0 [] = {
   { -2.50, -9.85, -14.10, 1, 0x0429, 0x08a4, 178, 187, 217, 255}, 
   { -16.70, -17.21, -11.21, 1, 0x02ad, 0x0fa8, 178, 187, 217, 255}, 
   { -16.30, -8.26, -45.70, 1, 0x0755, 0x0930, 178, 187, 217, 255}, 
   { -7.76, 17.83, -13.27, 1, 0x08a2, 0x0709, 178, 187, 217, 255}, 
   { -0.72, -10.19, -0.31, 1, 0x0000, 0x04f7, 178, 187, 217, 255}, 
   { -31.33, 1.33, -11.95, 1, 0x0967, 0x0a29, 178, 187, 217, 255}, 
   { -24.10, -11.29, 14.08, 1, 0x0fff, 0x0fff, 178, 187, 217, 255}, 
   { -22.69, 13.83, -4.49, 1, 0x0ac3, 0x0858, 178, 187, 217, 255}, 
   { -1.69, 13.78, 8.27, 1, 0x09d3, 0x0168, 178, 187, 217, 255}, 
   { -19.64, -0.73, -47.04, 1, 0x0790, 0x0915, 178, 187, 217, 255}, 
   { -11.75, 1.18, -43.96, 1, 0x0764, 0x08d6, 178, 187, 217, 255}, 
   { -24.68, -3.09, -40.77, 1, 0x07af, 0x0965, 178, 187, 217, 255}, 
   { -10.55, 21.76, 21.21, 1, 0x0fff, 0x00f0, 178, 187, 217, 255}, 
};

Vtx player_right_arm_lower_VertList_0 [] = {
   { -15.93, -10.36, -37.71, 1, 0x06fb, 0x01cb, 76, 45, 156, 255}, 
   { -14.32, -24.86, -39.81, 1, 0x0652, 0x0567, 76, 45, 156, 255}, 
   { -10.59, -18.99, -36.13, 1, 0x0711, 0x0452, 76, 45, 156, 255}, 
   { -0.45, -17.12, -36.12, 1, 0x01a6, 0x0121, 76, 45, 156, 255}, 
   { 0.80, -13.83, -50.47, 1, 0x0249, 0x0436, 76, 45, 156, 255}, 
   { -1.31, -5.93, -37.41, 1, 0x030f, 0x0087, 76, 45, 156, 255}, 
   { -8.00, -5.72, -54.64, 1, 0x04e7, 0x006b, 76, 45, 156, 255}, 
   { -18.74, -14.07, -50.36, 1, 0x0510, 0x0207, 76, 45, 156, 255}, 
   { 0.80, -25.52, -39.71, 1, 0x069b, 0x067a, 76, 45, 156, 255}, 
   { -9.82, -3.21, -36.78, 1, 0x0409, 0x0097, 76, 45, 156, 255}, 
   { -8.74, -15.41, -57.60, 1, 0x0308, 0x068b, 76, 45, 156, 255}, 
   { -4.02, -31.15, -46.78, 1, 0x055f, 0x074c, 76, 45, 156, 255}, 
   { -16.88, -23.55, -56.11, 1, 0x0409, 0x0442, 76, 45, 156, 255}, 
   { -1.14, -24.03, -57.15, 1, 0x0169, 0x06c7, 76, 45, 156, 255}, 
   { -14.45, -29.97, -47.02, 1, 0x052c, 0x065f, 76, 45, 156, 255}, 
   { -11.47, -2.27, -14.75, 1, 0x04c2, 0x03b3, 76, 45, 156, 255}, 
   { 0.24, -14.04, -4.86, 1, 0x07cd, 0x0781, 76, 45, 156, 255}, 
   { -7.07, -4.49, -2.64, 1, 0x07f8, 0x046d, 76, 45, 156, 255}, 
   { -1.99, 13.27, 3.26, 1, 0x0a0b, 0x0000, 76, 45, 156, 255}, 
   { 3.74, 3.45, -17.04, 1, 0x051b, 0x0d35, 76, 45, 156, 255}, 
   { 4.99, 14.33, 1.25, 1, 0x0a0b, 0x0fff, 76, 45, 156, 255}, 
   { 7.23, -9.40, -6.24, 1, 0x07fe, 0x09ad, 76, 45, 156, 255}, 
   { -8.36, -5.23, -38.90, 1, 0x0a69, 0x0d8f, 76, 45, 156, 255}, 
   { -9.14, -18.11, -35.45, 1, 0x0199, 0x0784, 76, 45, 156, 255}, 
   { -0.65, -17.46, -38.43, 1, 0x01c6, 0x08d0, 76, 45, 156, 255}, 
   { -1.38, -8.22, -41.45, 1, 0x0ae4, 0x0ef7, 76, 45, 156, 255}, 
   { -13.76, -10.74, -36.59, 1, 0x0ab2, 0x0c05, 76, 45, 156, 255}, 
};


Vtx player_left_arm_VertList_0 [] = {
   { 1.98, -9.85, -13.72, 1, 0x075b, 0x0bd6, 178, 187, 217, 255}, 
   { 15.77, -8.26, -45.32, 1, 0x06cf, 0x08aa, 178, 187, 217, 255}, 
   { 16.17, -17.21, -10.83, 1, 0x0057, 0x0d52, 178, 187, 217, 255}, 
   { 0.20, -10.19, 0.07, 1, 0x0b08, 0x0fff, 178, 187, 217, 255}, 
   { 7.23, 17.83, -12.89, 1, 0x08f6, 0x075d, 178, 187, 217, 255}, 
   { 30.81, 1.33, -11.56, 1, 0x05d6, 0x0698, 178, 187, 217, 255}, 
   { 23.58, -11.29, 14.46, 1, 0x0000, 0x0000, 178, 187, 217, 255}, 
   { 22.17, 13.83, -4.10, 1, 0x07a7, 0x053c, 178, 187, 217, 255}, 
   { 1.16, 13.78, 8.66, 1, 0x0e97, 0x062c, 178, 187, 217, 255}, 
   { 19.11, -0.73, -46.66, 1, 0x06ea, 0x086f, 178, 187, 217, 255}, 
   { 11.23, 1.18, -43.58, 1, 0x0729, 0x089b, 178, 187, 217, 255}, 
   { 24.15, -3.09, -40.39, 1, 0x069a, 0x0850, 178, 187, 217, 255}, 
   { 10.03, 21.76, 21.59, 1, 0x0f0f, 0x0000, 178, 187, 217, 255}, 
};

Vtx player_left_arm_lower_VertList_0 [] = {
   { 15.71, -10.36, -37.31, 1, 0x0952, 0x013d, 76, 45, 156, 255}, 
   { 10.37, -18.99, -35.73, 1, 0x06e6, 0x0128, 76, 45, 156, 255}, 
   { 14.10, -24.86, -39.41, 1, 0x05dc, 0x01e0, 76, 45, 156, 255}, 
   { 0.24, -17.12, -35.72, 1, 0x04d1, 0x01d0, 76, 45, 156, 255}, 
   { 1.09, -5.93, -37.00, 1, 0x043e, 0x032a, 76, 45, 156, 255}, 
   { -1.02, -13.83, -50.06, 1, 0x07c6, 0x026c, 76, 45, 156, 255}, 
   { 18.53, -14.07, -49.95, 1, 0x0918, 0x0314, 76, 45, 156, 255}, 
   { 7.78, -5.72, -54.24, 1, 0x0aa3, 0x033c, 76, 45, 156, 255}, 
   { -1.01, -25.52, -39.31, 1, 0x04d5, 0x019a, 76, 45, 156, 255}, 
   { 9.61, -3.21, -36.38, 1, 0x044c, 0x0419, 76, 45, 156, 255}, 
   { 8.52, -15.41, -57.19, 1, 0x0a01, 0x0323, 76, 45, 156, 255}, 
   { 3.80, -31.15, -46.38, 1, 0x040b, 0x02c8, 76, 45, 156, 255}, 
   { 16.66, -23.55, -55.70, 1, 0x06f5, 0x0410, 76, 45, 156, 255}, 
   { 0.93, -24.03, -56.75, 1, 0x0a3b, 0x0195, 76, 45, 156, 255}, 
   { 14.24, -29.97, -46.62, 1, 0x04ef, 0x02fa, 76, 45, 156, 255}, 
   { 11.26, -2.27, -14.34, 1, 0x0c4c, 0x0b3d, 76, 45, 156, 255}, 
   { 6.86, -4.49, -2.24, 1, 0x0b92, 0x0807, 76, 45, 156, 255}, 
   { -0.46, -14.04, -4.46, 1, 0x087e, 0x0832, 76, 45, 156, 255}, 
   { 1.78, 13.27, 3.66, 1, 0x0fff, 0x05f4, 76, 45, 156, 255}, 
   { -3.95, 3.45, -16.64, 1, 0x02ca, 0x0ae4, 76, 45, 156, 255}, 
   { -7.45, -9.40, -5.84, 1, 0x0652, 0x0801, 76, 45, 156, 255}, 
   { -5.20, 14.33, 1.66, 1, 0x0000, 0x05f4, 76, 45, 156, 255}, 
   { 8.15, -5.23, -38.50, 1, 0x0535, 0x0dae, 76, 45, 156, 255}, 
   { 8.92, -18.11, -35.05, 1, 0x087b, 0x0e66, 76, 45, 156, 255}, 
   { 0.44, -17.46, -38.02, 1, 0x072f, 0x0e39, 76, 45, 156, 255}, 
   { 1.16, -8.22, -41.05, 1, 0x04b9, 0x0f16, 76, 45, 156, 255}, 
   { 13.54, -10.74, -36.19, 1, 0x04ec, 0x0c24, 76, 45, 156, 255}, 
};

 
Vtx player_right_leg_VertList_0 [] = {
   { 4.31, -3.28, 0.13, 1, 0x0c28, 0x010a, 76, 45, 156, 255}, 
   { -16.49, -15.76, 7.16, 1, 0x0f43, 0x0532, 76, 45, 156, 255}, 
   { -1.08, -18.86, -0.67, 1, 0x0f43, 0x016e, 76, 45, 156, 255}, 
   { -14.44, -9.19, -64.80, 1, 0x0a2e, 0x0f0a, 76, 45, 156, 255}, 
   { -2.52, -3.97, -64.73, 1, 0x0ce5, 0x0f63, 76, 45, 156, 255}, 
   { -4.28, -10.22, -64.45, 1, 0x0caf, 0x0f33, 76, 45, 156, 255}, 
   { 2.40, 11.56, -0.68, 1, 0x096b, 0x01ec, 76, 45, 156, 255}, 
   { -18.66, -2.11, 8.71, 1, 0x0cc7, 0x0645, 76, 45, 156, 255}, 
   { 4.91, -4.29, -27.33, 1, 0x0edb, 0x086c, 76, 45, 156, 255}, 
   { 2.81, 9.02, -28.80, 1, 0x013d, 0x07f0, 76, 45, 156, 255}, 
   { -13.60, 3.03, -63.97, 1, 0x04e7, 0x0ed9, 76, 45, 156, 255}, 
   { -19.13, 10.96, -21.06, 1, 0x06d6, 0x0654, 76, 45, 156, 255}, 
   { -23.09, -2.94, -23.94, 1, 0x0808, 0x071f, 76, 45, 156, 255}, 
   { -20.93, -15.84, -21.33, 1, 0x0902, 0x067d, 76, 45, 156, 255}, 
   { -3.34, 2.14, -64.66, 1, 0x0251, 0x0f09, 76, 45, 156, 255}, 
   { -15.47, -3.29, -64.19, 1, 0x0548, 0x0f0e, 76, 45, 156, 255}, 
   { -16.23, 13.03, 6.90, 1, 0x066d, 0x00e0, 76, 45, 156, 255}, 
   { 0.63, -18.30, -26.63, 1, 0x0e4d, 0x07fc, 76, 45, 156, 255}, 
};
 
Vtx player_right_leg_lower_VertList_0 [] = {
   { -11.28, 12.67, -61.69, 1, 0x0ef8, 0x03db, 178, 187, 217, 255}, 
   { -15.24, -10.89, -64.35, 1, 0x0c0d, 0x042f, 178, 187, 217, 255}, 
   { -12.91, -10.56, -49.08, 1, 0x0c18, 0x024c, 178, 187, 217, 255}, 
   { -9.64, 8.75, -44.21, 1, 0x0e7c, 0x01b1, 178, 187, 217, 255}, 
   { 4.69, 8.10, -44.47, 1, 0x0e67, 0x01ba, 178, 187, 217, 255}, 
   { 4.04, -11.77, -64.69, 1, 0x0bf2, 0x043a, 178, 187, 217, 255}, 
   { 2.69, -11.27, -49.36, 1, 0x0c01, 0x0255, 178, 187, 217, 255}, 
   { -0.03, -30.69, -56.34, 1, 0x099a, 0x0332, 178, 187, 217, 255}, 
   { -12.12, -34.70, -64.90, 1, 0x091b, 0x0441, 178, 187, 217, 255}, 
   { 0.84, -35.29, -65.14, 1, 0x0909, 0x0448, 178, 187, 217, 255}, 
   { -10.52, -30.22, -56.15, 1, 0x09a9, 0x032c, 178, 187, 217, 255}, 
   { 6.43, 11.87, -62.01, 1, 0x00a6, 0x0458, 178, 187, 217, 255}, 
   { -7.73, -6.45, -49.65, 1, 0x0823, 0x072e, 178, 187, 217, 255}, 
   { -13.71, -3.25, -19.62, 1, 0x0466, 0x0581, 178, 187, 217, 255}, 
   { -8.92, -2.20, -48.85, 1, 0x0748, 0x0755, 178, 187, 217, 255}, 
   { 9.32, -6.36, 1.01, 1, 0x0bca, 0x0538, 178, 187, 217, 255}, 
   { -10.80, 2.63, -1.08, 1, 0x0d51, 0x0187, 178, 187, 217, 255}, 
   { -14.47, -6.89, 0.72, 1, 0x0b7c, 0x00f3, 178, 187, 217, 255}, 
   { 0.51, -2.12, -49.67, 1, 0x073d, 0x0892, 178, 187, 217, 255}, 
   { -0.18, -6.90, -49.92, 1, 0x0803, 0x08d7, 178, 187, 217, 255}, 
   { -11.76, -13.10, -18.67, 1, 0x04c7, 0x040d, 178, 187, 217, 255}, 
   { -10.30, 7.34, -20.15, 1, 0x042d, 0x06ed, 178, 187, 217, 255}, 
   { -7.16, 2.83, -49.22, 1, 0x06cf, 0x07bd, 178, 187, 217, 255}, 
   { 0.39, 2.38, -49.49, 1, 0x06bb, 0x0856, 178, 187, 217, 255}, 
   { 6.92, -3.91, -19.49, 1, 0x0435, 0x0a84, 178, 187, 217, 255}, 
   { 4.90, -14.31, -18.85, 1, 0x04a5, 0x0c05, 178, 187, 217, 255}, 
   { 8.82, 2.51, -1.10, 1, 0x0128, 0x09d2, 178, 187, 217, 255}, 
   { 6.36, 6.13, -20.33, 1, 0x03f8, 0x0915, 178, 187, 217, 255}, 
   { -8.67, -26.98, 11.81, 1, 0x0ee6, 0x0d2a, 178, 187, 217, 255}, 
   { 1.68, -27.61, 11.45, 1, 0x0786, 0x0408, 178, 187, 217, 255}, 
};


Vtx player_left_leg_VertList_0 [] = {
   { 15.61, -15.76, 7.42, 1, 0x0ef2, 0x0227, 76, 45, 156, 255}, 
   { -5.18, -3.28, 0.40, 1, 0x0bd7, 0x064e, 76, 45, 156, 255}, 
   { 0.21, -18.86, -0.41, 1, 0x0ef2, 0x05eb, 76, 45, 156, 255}, 
   { 13.56, -9.19, -64.54, 1, 0x0432, 0x0edb, 76, 45, 156, 255}, 
   { 1.65, -3.97, -64.47, 1, 0x06e8, 0x0e69, 76, 45, 156, 255}, 
   { 14.60, -3.29, -63.92, 1, 0x03d6, 0x0ea1, 76, 45, 156, 255}, 
   { -3.27, 11.56, -0.41, 1, 0x091a, 0x056d, 76, 45, 156, 255}, 
   { 17.78, -2.11, 8.98, 1, 0x0c76, 0x0113, 76, 45, 156, 255}, 
   { 15.36, 13.03, 7.17, 1, 0x0984, 0x011c, 76, 45, 156, 255}, 
   { 3.41, -10.22, -64.18, 1, 0x0933, 0x0e5d, 76, 45, 156, 255}, 
   { -5.78, -4.29, -27.06, 1, 0x0860, 0x0790, 76, 45, 156, 255}, 
   { -3.68, 9.02, -28.53, 1, 0x06d2, 0x077e, 76, 45, 156, 255}, 
   { 12.72, 3.03, -63.70, 1, 0x042b, 0x0e65, 76, 45, 156, 255}, 
   { 2.47, 2.14, -64.40, 1, 0x069d, 0x0e47, 76, 45, 156, 255}, 
   { 22.21, -2.94, -23.68, 1, 0x0f10, 0x0793, 76, 45, 156, 255}, 
   { 18.26, 10.96, -20.80, 1, 0x0164, 0x069e, 76, 45, 156, 255}, 
   { 20.06, -15.84, -21.07, 1, 0x0e42, 0x06cd, 76, 45, 156, 255}, 
   { -1.51, -18.30, -26.37, 1, 0x08fb, 0x0740, 76, 45, 156, 255}, 
};

Vtx player_left_leg_lower_VertList_0 [] = {
   { 10.88, 12.67, -62.50, 1, 0x0f19, 0x0abc, 178, 187, 217, 255}, 
   { 12.50, -10.56, -49.88, 1, 0x08ba, 0x06ac, 178, 187, 217, 255}, 
   { 14.84, -10.89, -65.15, 1, 0x07fe, 0x0abc, 178, 187, 217, 255}, 
   { -5.09, 8.10, -45.28, 1, 0x0ae7, 0x0f6f, 178, 187, 217, 255}, 
   { 9.24, 8.75, -45.02, 1, 0x0eb9, 0x0f6f, 178, 187, 217, 255}, 
   { -4.44, -11.77, -65.50, 1, 0x07b1, 0x06a8, 178, 187, 217, 255}, 
   { -0.37, -30.69, -57.15, 1, 0x029e, 0x09fd, 178, 187, 217, 255}, 
   { -3.10, -11.27, -50.17, 1, 0x08cb, 0x0aa4, 178, 187, 217, 255}, 
   { 11.72, -34.70, -65.71, 1, 0x0081, 0x086b, 178, 187, 217, 255}, 
   { -1.25, -35.29, -65.95, 1, 0x00bd, 0x07ef, 178, 187, 217, 255}, 
   { 10.12, -30.22, -56.96, 1, 0x02a2, 0x07ae, 178, 187, 217, 255}, 
   { -6.83, 11.87, -62.82, 1, 0x0cfa, 0x050b, 178, 187, 217, 255}, 
   { 13.30, -3.25, -20.43, 1, 0x0c85, 0x0ad6, 178, 187, 217, 255}, 
   { 7.33, -6.45, -50.46, 1, 0x0ddc, 0x0baa, 178, 187, 217, 255}, 
   { 8.52, -2.20, -49.66, 1, 0x0d96, 0x0ae2, 178, 187, 217, 255}, 
   { 10.40, 2.63, -1.89, 1, 0x0bc2, 0x04a8, 178, 187, 217, 255}, 
   { -9.72, -6.36, 0.20, 1, 0x0a50, 0x00ee, 178, 187, 217, 255}, 
   { 14.07, -6.89, -0.09, 1, 0x09ea, 0x0531, 178, 187, 217, 255}, 
   { -0.91, -2.12, -50.48, 1, 0x0f47, 0x0abf, 178, 187, 217, 255}, 
   { -0.22, -6.90, -50.73, 1, 0x0f39, 0x0ba5, 178, 187, 217, 255}, 
   { 11.36, -13.10, -19.48, 1, 0x0cff, 0x0c9f, 178, 187, 217, 255}, 
   { 9.90, 7.34, -20.96, 1, 0x0cff, 0x08d5, 178, 187, 217, 255}, 
   { 6.75, 2.83, -50.03, 1, 0x0dd6, 0x09ef, 178, 187, 217, 255}, 
   { -0.80, 2.38, -50.30, 1, 0x0f32, 0x09ea, 178, 187, 217, 255}, 
   { -7.32, -3.91, -20.30, 1, 0x022a, 0x0a4e, 178, 187, 217, 255}, 
   { -5.30, -14.31, -19.66, 1, 0x03ef, 0x0996, 178, 187, 217, 255}, 
   { -2.09, -27.61, 10.64, 1, 0x048d, 0x037b, 178, 187, 217, 255}, 
   { -9.23, 2.51, -1.91, 1, 0x0000, 0x0770, 178, 187, 217, 255}, 
   { -6.77, 6.13, -21.14, 1, 0x0086, 0x0b0d, 178, 187, 217, 255}, 
   { 8.27, -26.98, 11.00, 1, 0x0e4f, 0x0e56, 178, 187, 217, 255}, 
};

*/