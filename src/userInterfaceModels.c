#include "userInterfaceDefs.h"

EnvObject targetArrowObj;
EnvObject targetRingObj;

Vtx target_ring_VertList_0 [];
Vtx target_arrow_VertList_0 [];

//EnemyTargets* enemyTargetsP;

void ui_target_init()
{
	//enemyTargetsP = tempEnemyTargetsP;	

	SetVector3(&targetArrowObj.obj.pos, enemyTargets.activeTarget->pos.x, enemyTargets.activeTarget->pos.y, enemyTargets.activeTarget->pos.z + 30.0f);
	SetVector3(&targetArrowObj.obj.rot, 0,0,0);
	SetVector3(&targetArrowObj.obj.scl, 1,1,1);
	SetAnimator(&targetArrowObj.animator, &target_arrow_PolyList, 0,0);
	
	SetVector3(&targetRingObj.obj.pos, enemyTargets.activeTarget->pos.x, enemyTargets.activeTarget->pos.y, enemyTargets.activeTarget->pos.z +15.0f);
	SetVector3(&targetRingObj.obj.rot, 0,0,0);
	SetVector3(&targetRingObj.obj.scl, 2,2,2);
	SetAnimator(&targetRingObj.animator, &target_ring_PolyList, 0,0);
}

		
		Lights1 uiLight = gdSPDefLights1( 
		100,100,255,
		0,0,0,
		0,0,0);

void UI_Target_Render()
{

	if(enemyTargets.isActive == 1)
	{
		TEXTURE_FOG_LIGHT(glistp, 0, 0, 255, 75,100,500); //NOTE: this setting removes detail closer to the camera 
		gDPSetPrimColor(glistp++, 50, 50, 255, 245, 255, 210);  //water primative color is blended with fog in combiner
		TEXTURE_4B_TLUT_TRANSP(glistp, glow_material, glow_material_tlut, 6,1);
		gSPSetLights2(glistp++, uiLight);


		RenderEnvObj(&targetArrowObj);
		RenderEnvObj(&targetRingObj);
	}
}

void UI_Target_Update()
{
	if(enemyTargets.isActive == 1)
	{
		SetVector3(&targetArrowObj.obj.pos, enemyTargets.activeTarget->pos.x, enemyTargets.activeTarget->pos.y, enemyTargets.activeTarget->pos.z + 30.0f);
		SetVector3(&targetArrowObj.obj.rot, 0,0,0);
		SetVector3(&targetArrowObj.obj.scl, 1,1,1);
		SetAnimator(&targetArrowObj.animator, &target_arrow_PolyList, 0,0);
	
		SetVector3(&targetRingObj.obj.pos, enemyTargets.activeTarget->pos.x, enemyTargets.activeTarget->pos.y, enemyTargets.activeTarget->pos.z +15.0f);
		SetVector3(&targetRingObj.obj.rot, 0,0,0);
		SetVector3(&targetRingObj.obj.scl, 2,2,2);
		SetAnimator(&targetRingObj.animator, &target_ring_PolyList, 0,0);
	}
}

void target_ring_PolyList(u8 animFrame) 
 { 

   Vtx *target_ring_VTXPointer = &target_ring_VertList_0[0]; 

   gSPVertex(glistp++,target_ring_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 0 'glow_material'OK 

  // TEXTURE_4B_TLUT(glistp, glow_material, glow_material_tlut, 6,1);
  

	TEXTURE_4B_TLUT_TRANSP(glistp, glow_material, glow_material_tlut, 6,1);
	
   gSPVertex(glistp++,target_ring_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,1, 3, 4, 1); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x00000f7f);
   gSP1Triangle(glistp++,3, 5, 6, 3); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0fff0f61);
   gSP1Triangle(glistp++,3, 1, 7, 3); 
   gSP1Triangle(glistp++,8, 0, 9, 8); 
   gSP1Triangle(glistp++,5, 8, 10, 5); 
   gSP1Triangle(glistp++,10, 11, 12, 10); 
   gSP1Triangle(glistp++,13, 14, 15, 13); 
   gSP1Triangle(glistp++,12, 11, 15, 12); 
   gSP1Triangle(glistp++,2, 16, 13, 2); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x068e0ff7);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x097d0ffc);
   gSP1Triangle(glistp++,8, 15, 14, 8); 
   gSP1Triangle(glistp++,4, 17, 16, 4); 
   gSP1Triangle(glistp++,9, 13, 11, 9); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x00000f7f);
   gSP1Triangle(glistp++,3, 18, 19, 3); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x00720e7d);
   gSP1Triangle(glistp++,6, 12, 17, 6); 
   gSP1Triangle(glistp++,5, 19, 15, 5); 
   gSP1Triangle(glistp++,0, 14, 7, 0); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0c570e6b);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x096c0e73);
   gSP1Triangle(glistp++,16, 7, 14, 16); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0f9e0e8e);           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x0f980e35);
   gSP1Triangle(glistp++,17, 18, 7, 17); 
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x03980e59);           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x00760e35);
   gSP1Triangle(glistp++,12, 19, 18, 12); 
   gSP1Triangle(glistp++,9, 0, 2, 9); 
   gSP1Triangle(glistp++,2, 1, 4, 2); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x00000f16);
   gSP1Triangle(glistp++,4, 3, 6, 4); 
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x0f970ffd);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0fff0f61);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0c6d0ff7);
   gSP1Triangle(glistp++,18, 3, 7, 18); 
   gSP1Triangle(glistp++,10, 8, 9, 10); 
   gSP1Triangle(glistp++,6, 5, 10, 6); 
   gSP1Triangle(glistp++,6, 10, 12, 6); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x06840e6e);
   gSP1Triangle(glistp++,11, 13, 15, 11); 
   gSP1Triangle(glistp++,19, 12, 15, 19); 
   gSP1Triangle(glistp++,9, 2, 13, 9); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x097d0ffc);
   gSP1Triangle(glistp++,0, 8, 14, 0); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x0ff90ef8);
   gSP1Triangle(glistp++,2, 4, 16, 2); 
   gSP1Triangle(glistp++,10, 9, 11, 10); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x00000f7f);           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x03a30fe7);
   gSP1Triangle(glistp++,5, 3, 19, 5); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x00000f16);           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x00720e7d);
   gSP1Triangle(glistp++,4, 6, 17, 4); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x068e0ff7);
   gSP1Triangle(glistp++,8, 5, 15, 8); 
   gSP1Triangle(glistp++,1, 0, 7, 1); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x096c0e73);
   gSP1Triangle(glistp++,13, 16, 14, 13); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0f9e0e8e);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0c570e6b);
   gSP1Triangle(glistp++,16, 17, 7, 16); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x00720e7d);           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x00760e35);
   gSP1Triangle(glistp++,17, 12, 18, 17); 

   gDPPipeSync(glistp++);

 } 
 
 
 //Test Object = 1 
void target_arrow_PolyList(u8 animFrame) 
 { 

   Vtx *target_arrow_VTXPointer = &target_arrow_VertList_0[0]; 

   gSPVertex(glistp++,target_arrow_VTXPointer+0,26,0);

//OBJECT: 1 MATERIAL NO. 0 'glow_material'OK 

   TEXTURE_4B_TLUT(glistp, glow_material, glow_material_tlut, 6,1);

   gSPVertex(glistp++,target_arrow_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 1, 3); 
   gSP1Triangle(glistp++,5, 6, 7, 5); 
   gSP1Triangle(glistp++,7, 8, 2, 7); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x07ac0fff);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x092b0e3c);
   gSP1Triangle(glistp++,1, 4, 5, 1); 
   gSP1Triangle(glistp++,9, 10, 11, 9); 
   gSP1Triangle(glistp++,10, 0, 8, 10); 
   gSP1Triangle(glistp++,9, 3, 0, 9); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0967085d);
   gSP1Triangle(glistp++,12, 7, 3, 12); 
   gSP1Triangle(glistp++,11, 8, 7, 11); 
   gSP1Triangle(glistp++,7, 6, 13, 7); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x02670a06);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x00000a70);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x032c0e7d);
   gSP1Triangle(glistp++,3, 13, 4, 3); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0b0c0a61);
   gSP1Triangle(glistp++,13, 6, 5, 13); 
   gSP1Triangle(glistp++,8, 0, 2, 8); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x05620f52);
   gSP1Triangle(glistp++,0, 3, 1, 0); 
   gSP1Triangle(glistp++,5, 7, 2, 5); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x07ac0fff);
   gSP1Triangle(glistp++,2, 1, 5, 2); 
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x01470000);
   gSP1Triangle(glistp++,12, 9, 11, 12); 
   gSP1Triangle(glistp++,11, 10, 8, 11); 
   gSP1Triangle(glistp++,10, 9, 0, 10); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x066a0000);           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x052b0072);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0967085d);
   gSP1Triangle(glistp++,9, 12, 3, 9); 
   gSP1Triangle(glistp++,12, 11, 7, 12); 
   gSP1Triangle(glistp++,3, 7, 13, 3); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x092b0e3c);
   gSP1Triangle(glistp++,4, 13, 5, 4); 

   gDPPipeSync(glistp++);

 } 
 
 
 
 
 
Vtx target_ring_VertList_0 [] = {
   { 0.00, 22.95, -6.35, 1, 0x0976, 0x0f81, 0, 102, 75, 255}, 
   { 21.83, 7.09, -6.35, 1, 0x0c66, 0x0f76, 97, 31, 75, 255}, 
   { 21.83, 7.09, -8.71, 1, 0x0c62, 0x0f27, 97, 31, -75, 255}, 
   { 13.49, -18.57, -6.35, 1, 0x0fff, 0x0f61, 59, -82, 75, 255}, 
   { 13.49, -18.57, -8.71, 1, 0x0ff9, 0x0ef8, 59, -82, -75, 255}, 
   { -13.49, -18.57, -6.35, 1, 0x039d, 0x0f75, -59, -82, 75, 255}, 
   { -13.49, -18.57, -8.71, 1, 0x039b, 0x0f26, -59, -82, -75, 255}, 
   { 17.77, 5.77, -6.35, 1, 0x0c6d, 0x0ff7, -60, -19, 109, 255}, 
   { -21.83, 7.09, -6.35, 1, 0x0689, 0x0f7c, -97, 31, 75, 255}, 
   { 0.00, 22.95, -8.71, 1, 0x0974, 0x0f30, 0, 102, -75, 255}, 
   { -21.83, 7.09, -8.71, 1, 0x0688, 0x0f2b, -97, 31, -75, 255}, 
   { -17.77, 5.77, -8.71, 1, 0x0683, 0x0eb8, 60, -19, -109, 255}, 
   { -10.98, -15.11, -8.71, 1, 0x0396, 0x0ea5, 37, 51, -109, 255}, 
   { 0.00, 18.68, -8.71, 1, 0x096d, 0x0ebe, 0, -63, -109, 255}, 
   { 0.00, 18.68, -6.35, 1, 0x096c, 0x0e73, 0, -63, 109, 255}, 
   { -17.77, 5.77, -6.35, 1, 0x0684, 0x0e6e, 60, -19, 109, 255}, 
   { 17.77, 5.77, -8.71, 1, 0x0c5a, 0x0ec0, -60, -19, -109, 255}, 
   { 10.98, -15.11, -8.71, 1, 0x0f9e, 0x0e8e, -37, 51, -109, 255}, 
   { 10.98, -15.11, -6.35, 1, 0x0063, 0x0fff, -37, 51, 109, 255}, 
   { -10.98, -15.11, -6.35, 1, 0x03a3, 0x0fe7, 37, 51, 109, 255}, 
};

Vtx target_arrow_VertList_0 [] = {
   { -2.82, 1.15, 23.02, 1, 0x0469, 0x09a6, -89, 89, 0, 255}, 
   { -2.82, 1.15, 11.58, 1, 0x0562, 0x0f52, -52, 70, -91, 255}, 
   { -2.82, -1.48, 11.58, 1, 0x06af, 0x0f1a, -52, -70, -91, 255}, 
   { 1.27, 1.15, 23.02, 1, 0x0267, 0x0a06, 38, 114, 38, 255}, 
   { 1.27, 1.15, 13.96, 1, 0x032c, 0x0e7d, 69, 82, -66, 255}, 
   { 1.27, -1.48, 13.96, 1, 0x0842, 0x0d97, 69, -82, -66, 255}, 
   { 6.15, -1.48, 23.02, 1, 0x09cc, 0x0a98, 90, -70, 54, 255}, 
   { 1.27, -1.48, 23.02, 1, 0x081f, 0x0916, 38, -114, 38, 255}, 
   { -2.82, -1.48, 23.02, 1, 0x05e1, 0x095f, -89, -89, 0, 255}, 
   { 1.27, 1.15, 40.66, 1, 0x00a7, 0x017c, 73, 73, 73, 255}, 
   { -2.82, 1.15, 40.66, 1, 0x02ad, 0x0210, -73, 73, 73, 255}, 
   { -2.82, -1.48, 40.66, 1, 0x0395, 0x00f8, -73, -73, 73, 255}, 
   { 1.27, -1.48, 40.66, 1, 0x052b, 0x0072, 73, -73, 73, 255}, 
   { 6.15, 1.15, 23.02, 1, 0x0b0c, 0x0a61, 90, 70, 54, 255}, 
};
