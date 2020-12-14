//Test Object = 0 
#include "testUV_fog.h" 
#include "ENV1_Fog.c"
void test_env_haze_PolyList() 
 { 
   Vtx *test_env_haze_VTXPointer = &test_env_haze_VertList_0[0]; 

	TEXTURE_4B_TRANSPARENT_OVERLAY(glistp, ENV1_Fog, ENV1_Fog_tlut, 10,0); 
	gSPLightColor(glistp++,LIGHT_3, 0x61696400);
	gSPLightColor(glistp++,LIGHT_2, 0xc3d3c800);
//Prim Color: 0 primColorCheck 3 
   gSPVertex(glistp++,test_env_haze_VTXPointer+0,26,0);
   gDPSetPrimColor(glistp++,1,255,255,225,213,155);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 2, 4, 3); 
   gSP1Triangle(glistp++,5, 4, 6, 5); 
   gSP1Triangle(glistp++,7, 6, 8, 7); 
   gSP1Triangle(glistp++,8, 9, 10, 8); 
   gSP1Triangle(glistp++,9, 11, 12, 9); 
   gSP1Triangle(glistp++,12, 11, 13, 12); 
   gSP1Triangle(glistp++,14, 13, 15, 14); 
   gSP1Triangle(glistp++,6, 16, 15, 6); 
   gSP1Triangle(glistp++,17, 16, 1, 17); 
   gSP1Triangle(glistp++,18, 15, 16, 18); 
   gSP1Triangle(glistp++,9, 8, 15, 9); 
   gSP1Triangle(glistp++,4, 1, 16, 4); 
   gSP1Triangle(glistp++,2, 1, 4, 2); 
   gSP1Triangle(glistp++,11, 9, 13, 11); 
   gSP1Triangle(glistp++,3, 0, 2, 3); 
   gSP1Triangle(glistp++,5, 3, 4, 5); 
   gSP1Triangle(glistp++,7, 5, 6, 7); 
   gSP1Triangle(glistp++,19, 7, 8, 19); 
   gSP1Triangle(glistp++,19, 8, 10, 19); 
   gSP1Triangle(glistp++,10, 9, 12, 10); 
   gSP1Triangle(glistp++,14, 12, 13, 14); 
   gSP1Triangle(glistp++,18, 14, 15, 18); 
   gSP1Triangle(glistp++,8, 6, 15, 8); 
   gSP1Triangle(glistp++,0, 17, 1, 0); 
   gSP1Triangle(glistp++,17, 18, 16, 17); 
   gSP1Triangle(glistp++,13, 9, 15, 13); 
   gSP1Triangle(glistp++,6, 4, 16, 6); 

   gDPPipeSync(glistp++);

 } 
 
 void test_env_haze_PolyList_PRIM() 
 { 
   Vtx *test_env_haze_VTXPointer = &test_env_haze_VertList_0[0]; 
   	gSPLightColor(glistp++,LIGHT_3, 0x61696400);
	gSPLightColor(glistp++,LIGHT_2, 0xc3d3c800);	
   gDPPipeSync(glistp++);

	PRIM_TRANSPARENT_PENITRATE_SURF(glistp); 
	
   //gSPVertex(glistp++,test_env_haze_VTXPointer+0,26,0);
//Prim Color: 0 primColorCheck 3 
   gSPVertex(glistp++,test_env_haze_VTXPointer+0,26,0);
   gDPSetPrimColor(glistp++,1,255,70,40,75,155);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 2, 4, 3); 
   gSP1Triangle(glistp++,5, 4, 6, 5); 
   gSP1Triangle(glistp++,7, 6, 8, 7); 
   gSP1Triangle(glistp++,8, 9, 10, 8); 
   gSP1Triangle(glistp++,9, 11, 12, 9); 
   gSP1Triangle(glistp++,12, 11, 13, 12); 
   gSP1Triangle(glistp++,14, 13, 15, 14); 
   gSP1Triangle(glistp++,6, 16, 15, 6); 
   gSP1Triangle(glistp++,17, 16, 1, 17); 
   gSP1Triangle(glistp++,18, 15, 16, 18); 
   gSP1Triangle(glistp++,9, 8, 15, 9); 
   gSP1Triangle(glistp++,4, 1, 16, 4); 
   gSP1Triangle(glistp++,2, 1, 4, 2); 
   gSP1Triangle(glistp++,11, 9, 13, 11); 
   gSP1Triangle(glistp++,3, 0, 2, 3); 
   gSP1Triangle(glistp++,5, 3, 4, 5); 
   gSP1Triangle(glistp++,7, 5, 6, 7); 
   gSP1Triangle(glistp++,19, 7, 8, 19); 
   gSP1Triangle(glistp++,19, 8, 10, 19); 
   gSP1Triangle(glistp++,10, 9, 12, 10); 
   gSP1Triangle(glistp++,14, 12, 13, 14); 
   gSP1Triangle(glistp++,18, 14, 15, 18); 
   gSP1Triangle(glistp++,8, 6, 15, 8); 
   gSP1Triangle(glistp++,0, 17, 1, 0); 
   gSP1Triangle(glistp++,17, 18, 16, 17); 
   gSP1Triangle(glistp++,13, 9, 15, 13); 
   gSP1Triangle(glistp++,6, 4, 16, 6); 

   gDPPipeSync(glistp++);

 } 
 
 void test_env_haze_PolyList_A() 
 { 
   Vtx *test_env_haze_VTXPointer = &test_env_haze_VertList_0[0]; 
   	gSPLightColor(glistp++,LIGHT_3, 0x61696400);
	gSPLightColor(glistp++,LIGHT_2, 0xc3d3c800);	
   gDPPipeSync(glistp++);

	PRIM_TRANSPARENT_PENITRATE_SURF(glistp); 
	
   //gSPVertex(glistp++,test_env_haze_VTXPointer+0,26,0);
//Prim Color: 0 primColorCheck 3 
   gSPVertex(glistp++,test_env_haze_VTXPointer+0,26,0);
   gDPSetPrimColor(glistp++,1,255,70,40,75,155);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 2, 4, 3); 
   gSP1Triangle(glistp++,5, 4, 6, 5); 
   gSP1Triangle(glistp++,7, 6, 8, 7); 
   gSP1Triangle(glistp++,8, 9, 10, 8); 
   gSP1Triangle(glistp++,9, 11, 12, 9); 
   gSP1Triangle(glistp++,12, 11, 13, 12); 
   gSP1Triangle(glistp++,14, 13, 15, 14); 
   gSP1Triangle(glistp++,6, 16, 15, 6); 
   gSP1Triangle(glistp++,17, 16, 1, 17); 
   gSP1Triangle(glistp++,18, 15, 16, 18); 
   gSP1Triangle(glistp++,9, 8, 15, 9); 
   gSP1Triangle(glistp++,4, 1, 16, 4); 
   gSP1Triangle(glistp++,2, 1, 4, 2); 
   gSP1Triangle(glistp++,11, 9, 13, 11); 
   gSP1Triangle(glistp++,3, 0, 2, 3); 
   gSP1Triangle(glistp++,5, 3, 4, 5); 
   gSP1Triangle(glistp++,7, 5, 6, 7); 
   gSP1Triangle(glistp++,19, 7, 8, 19); 
   gSP1Triangle(glistp++,19, 8, 10, 19); 
   gSP1Triangle(glistp++,10, 9, 12, 10); 
   gSP1Triangle(glistp++,14, 12, 13, 14); 
   gSP1Triangle(glistp++,18, 14, 15, 18); 
   gSP1Triangle(glistp++,8, 6, 15, 8); 
   gSP1Triangle(glistp++,0, 17, 1, 0); 
   gSP1Triangle(glistp++,17, 18, 16, 17); 
   gSP1Triangle(glistp++,13, 9, 15, 13); 
   gSP1Triangle(glistp++,6, 4, 16, 6); 

   gDPPipeSync(glistp++);

 } 
 
/* DEBUG 

*/
 