//Test Object = 0 
#include "testUV_cube.h" 

void Sloped_Cube_Collision_Wall_PolyList() 
 { 
	Vtx *Sloped_Cube_Collision_Wall_VTXPointer = &Sloped_Cube_Collision_Wall_VertList_0[0]; 
	gSPLightColor(glistp++,LIGHT_3, 0x61696400);
	gSPLightColor(glistp++,LIGHT_2, 0xc3d3c800);	
	TEXTURE_4B_TLUT(glistp, testGround, testGround_tlut, 6,0);   

   

      gSPVertex(glistp++,Sloped_Cube_Collision_Wall_VTXPointer+0,26,0);
   gDPSetPrimColor(glistp++,1,255,255,255,255,255);
	gSP1Triangle(glistp++,0, 1, 2, 0); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0000062c); 
   gSP1Triangle(glistp++,1, 3, 4, 1); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x0abc0fff); 
   gSP1Triangle(glistp++,5, 6, 4, 5); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x066a0d5d);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00000d5d); 
   gSP1Triangle(glistp++,5, 0, 7, 5); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x05430a98); 
   gSP1Triangle(glistp++,7, 2, 4, 7); 
   gSP1Triangle(glistp++,0, 5, 3, 0); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x03040aa0); 
   gSP1Triangle(glistp++,7, 0, 2, 7); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x00000000);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x066a0000); 
   gSP1Triangle(glistp++,2, 1, 4, 2); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0fff0ff7);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0cfb0aa0);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x0abc0fff); 
   gSP1Triangle(glistp++,3, 5, 4, 3); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x066a0fff);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x066a0d5d);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x00000fff); 
   gSP1Triangle(glistp++,6, 5, 7, 6); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x0abc0a98);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x05430a98); 
   gSP1Triangle(glistp++,6, 7, 4, 6); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00000d5d);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x066a062c); 
   gSP1Triangle(glistp++,1, 0, 3, 1); 

   gDPPipeSync(glistp++);

 } 

