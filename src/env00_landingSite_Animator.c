//Test Object = 0 
#include "common.h" 
 
 Vtx Landing_Ground001_VertList_0 [];
 Vtx Landing_Pad001_VertList_0 [];
 Vtx LadingZone_obelisks001001_VertList_0 [];
 Vtx Landing_2001_VertList_0 [];
 Vtx Landing001_VertList_0 [];
 Vtx Landing_Staris001_VertList_0 [];
 Vtx LadingZone_obeliskslit_VertList_0 [];
 
 /*
 	Lights1 env_lightingDark = gdSPDefLights1(  60, 50, 50, // amb col 
	115, 110, 100, // col 1   
	0,   0,  0 // dir 1
	);
 
 
		 Lights1 env_darkGround = gdSPDefLights1(  40, 35, 15, // amb col 
	100, 90, 70, // col 1  
//	0,   45,  -30, // dir 1
	0,   -15,  75 // dir 1
	);  
	*/
	
	
  	Lights2 env_cavLight = gdSPDefLights2(  30, 50, 60, // amb col 
	50, 70, 90, // col 1  
	0,   -45,  15, // dir 1
	40, 60, 80, // col 1  
	45,   0,  90 // dir 2
	);  
	
	
	Lights2 env_caveGlow = gdSPDefLights2(  40, 60, 70, // amb col 
	60, 90, 140, // col 1  
	10,   0,  110, // dir 2
	40, 90, 150, // col 1  
	0,   0,  80 // dir 1
	
	);  
	
	Lights2 env_caveGlowLight = gdSPDefLights2(  30, 60, 80, // amb col 
	45, 70, 90, // col 1  
	10,   0,  120, // dir 2
	45, 55, 85, // col 1  
	0,   0,  75 // dir 1	
	); 
	
	Lights2 env_evenGlow = gdSPDefLights2(  110, 175, 215, // amb col 
	15, 25, 65, // col 1  
	10,   0,  120, // dir 2
	25, 45, 75, // col 1  
	0,   0,  75 // dir 1	
	); 
	
	
 void Load_Landing_Site_Animator(u8 animFrame)
 {
	
	//gSPSetLights2(glistp++, env_lightingDark);
 
 	gSPSetLights2(glistp++, env_cavLight);
 
	Landing_Ground001_PolyList(animFrame);	

	//LadingZone_obelisks001001_PolyList(animFrame);
	Landing_2001_PolyList(animFrame);
	Landing001_PolyList(animFrame);

	
	gSPSetLights2(glistp++, env_caveGlow);
	//Landing_Pad001_PolyList(animFrame);	
	LadingZone_obelisks001001_PolyList(animFrame);	
	
	gSPSetLights2(glistp++, env_evenGlow);
	LadingZone_obeliskslit_PolyList(animFrame);
	
	gSPSetLights2(glistp++, env_caveGlowLight);
		Landing_Pad001_PolyList(animFrame);	
	Landing_Staris001_PolyList(animFrame);
	Landing_Ground001_PolyList(animFrame);	
 }
 
 
 
 
 //Scripts below:
 
 void Landing_Ground001_PolyList(u8 animFrame) 
 { 

   Vtx *Landing_Ground001_VTXPointer = &Landing_Ground001_VertList_0[0]; 

   gSPVertex(glistp++,Landing_Ground001_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 0 'Dirt1'OK 

   TEXTURE_4B_TLUT(glistp, Dirt1, Dirt1_tlut, 6,1);

   gSPVertex(glistp++,Landing_Ground001_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,6, 7, 8, 6); 
   gSP1Triangle(glistp++,6, 9, 10, 6); 
   gSP1Triangle(glistp++,7, 6, 10, 7); 
   gSP1Triangle(glistp++,8, 11, 12, 8); 
   gSP1Triangle(glistp++,12, 11, 13, 12); 
   gSP1Triangle(glistp++,11, 8, 7, 11); 
   gSP1Triangle(glistp++,14, 10, 9, 14); 
   gSP1Triangle(glistp++,14, 9, 15, 14); 
   gSP1Triangle(glistp++,16, 0, 2, 16); 
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSP1Triangle(glistp++,18, 16, 19, 18); 
   gSP1Triangle(glistp++,20, 21, 3, 20); 
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSP1Triangle(glistp++,23, 22, 17, 23); 
   gSP1Triangle(glistp++,23, 17, 19, 23); 
   gSP1Triangle(glistp++,5, 20, 3, 5); 
   gSP1Triangle(glistp++,10, 25, 7, 10); 
   gSPVertex(glistp++,Landing_Ground001_VTXPointer+10,26,0);
   gSP1Triangle(glistp++,15, 0, 16, 15); 
   gSP1Triangle(glistp++,17, 14, 18, 17); 
   gSP1Triangle(glistp++,17, 19, 14, 17); 
   gSP1Triangle(glistp++,14, 19, 12, 14); 
   gSP1Triangle(glistp++,4, 5, 20, 4); 
   gSP1Triangle(glistp++,11, 13, 9, 11); 
   gSPVertex(glistp++,Landing_Ground001_VTXPointer+3,26,0);
   gSP1Triangle(glistp++,18, 16, 0, 18); 
   gSPVertex(glistp++,Landing_Ground001_VTXPointer+1,26,0);
   gSP1Triangle(glistp++,0, 3, 2, 0); 
   gSP1Triangle(glistp++,0, 2, 1, 0); 
   gSP1Triangle(glistp++,1, 18, 15, 1); 

   gDPPipeSync(glistp++);

 } 
 
 
 
 //Test Object = 1 
void Landing_Pad001_PolyList(u8 animFrame) 
 { 

   Vtx *Landing_Pad001_VTXPointer = &Landing_Pad001_VertList_0[0]; 

   gSPVertex(glistp++,Landing_Pad001_VTXPointer+0,26,0);

//OBJECT: 1 MATERIAL NO. 3 'AltarPlatform'OK 

   TEXTURE_4B_TLUT(glistp, AltarPlatform, AltarPlatform_tlut, 6,1);

   gSPVertex(glistp++,Landing_Pad001_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 2, 3); 
   gSP1Triangle(glistp++,5, 6, 2, 5); 
   gSP1Triangle(glistp++,2, 7, 8, 2); 
   gSP1Triangle(glistp++,9, 10, 2, 9); 
   gSP1Triangle(glistp++,4, 9, 2, 4); 
   gSP1Triangle(glistp++,2, 10, 0, 2); 
   gSP1Triangle(glistp++,1, 11, 2, 1); 
   gSP1Triangle(glistp++,2, 11, 5, 2); 
   gSP1Triangle(glistp++,6, 7, 2, 6); 
   gSP1Triangle(glistp++,12, 3, 2, 12); 
   gSP1Triangle(glistp++,8, 12, 2, 8); 

   gDPPipeSync(glistp++);

 } 
 
 
 //Test Object = 2 
void LadingZone_obelisks001001_PolyList(u8 animFrame) 
 { 

   Vtx *LadingZone_obelisks001001_VTXPointer = &LadingZone_obelisks001001_VertList_0[0]; 

   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+0,26,0);

//OBJECT: 2 MATERIAL NO. 1 'Obelisk2'OK 

   TEXTURE_4B_TLUT_MIRRORX(glistp, Obelisk2, Obelisk2_tlut, 6,1);

   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,0, 2, 3, 0); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,1, 0, 4, 1); 
   gSP1Triangle(glistp++,5, 6, 7, 5); 
   gSP1Triangle(glistp++,5, 7, 8, 5); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,6, 5, 9, 6); 
   gSP1Triangle(glistp++,10, 11, 12, 10); 
   gSP1Triangle(glistp++,10, 12, 13, 10); 
   gSP1Triangle(glistp++,14, 15, 16, 14); 
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSP1Triangle(glistp++,18, 17, 20, 18); 
   gSP1Triangle(glistp++,21, 22, 17, 21); 
   gSP1Triangle(glistp++,21, 17, 19, 21); 
           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,22, 21, 23, 22); 
   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+24,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,1, 0, 3, 1); 
   gSP1Triangle(glistp++,4, 5, 0, 4); 
   gSP1Triangle(glistp++,4, 0, 2, 4); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,5, 4, 6, 5); 
   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+19,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x080b6856);
   gSP1Triangle(glistp++,0, 12, 13, 0); 
   gSP1Triangle(glistp++,12, 0, 14, 12); 
   gSP1Triangle(glistp++,15, 16, 0, 15); 
   gSP1Triangle(glistp++,15, 0, 13, 15); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,16, 15, 11, 16); 
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSP1Triangle(glistp++,18, 17, 20, 18); 
   gSP1Triangle(glistp++,21, 22, 17, 21); 
   gSP1Triangle(glistp++,21, 17, 19, 21); 
           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,22, 21, 23, 22); 
   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+43,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,1, 0, 3, 1); 
   gSP1Triangle(glistp++,4, 5, 0, 4); 
   gSP1Triangle(glistp++,4, 0, 2, 4); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,5, 4, 6, 5); 
   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+38,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x080b6856);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x17f16856);
   gSP1Triangle(glistp++,0, 12, 5, 0); 
   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+37,26,0);
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x080b6856);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x080b6bfe);
   gSP1Triangle(glistp++,13, 1, 0, 13); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x06115c03);
   gSP1Triangle(glistp++,14, 3, 1, 14); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x17f16856);
   gSP1Triangle(glistp++,14, 1, 6, 14); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,15, 14, 16, 15); 
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSP1Triangle(glistp++,18, 17, 20, 18); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,17, 19, 21, 17); 
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSP1Triangle(glistp++,23, 22, 25, 23); 
   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+59,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,0, 2, 4, 0); 
   gSP1Triangle(glistp++,5, 6, 7, 5); 
   gSP1Triangle(glistp++,6, 5, 8, 6); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,5, 7, 9, 5); 
   gSP1Triangle(glistp++,10, 11, 12, 10); 
   gSP1Triangle(glistp++,12, 13, 10, 12); 
   gSP1Triangle(glistp++,14, 10, 15, 14); 
   gSP1Triangle(glistp++,10, 14, 11, 10); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,14, 15, 16, 14); 
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSP1Triangle(glistp++,19, 20, 17, 19); 
   gSP1Triangle(glistp++,21, 17, 22, 21); 
   gSP1Triangle(glistp++,17, 21, 18, 17); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,21, 22, 23, 21); 
   gSPVertex(glistp++,LadingZone_obelisks001001_VTXPointer+83,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,2, 3, 0, 2); 
   gSP1Triangle(glistp++,4, 0, 5, 4); 
   gSP1Triangle(glistp++,0, 4, 1, 0); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,6, 5, 7, 6); 

   gDPPipeSync(glistp++);

 } 
 
 
 
 void LadingZone_obeliskslit_PolyList(u8 animFrame) 
 { 

   Vtx *LadingZone_obeliskslit_VTXPointer = &LadingZone_obeliskslit_VertList_0[0]; 

   gSPVertex(glistp++,LadingZone_obeliskslit_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 1 'Obelisk2'OK 

   TEXTURE_4B_TLUT_MIRRORX(glistp, Obelisk2, Obelisk2_tlut, 6,1);

   gSPVertex(glistp++,LadingZone_obeliskslit_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,0, 2, 3, 0); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,1, 0, 4, 1); 
   gSP1Triangle(glistp++,5, 6, 7, 5); 
   gSP1Triangle(glistp++,6, 5, 8, 6); 
   gSP1Triangle(glistp++,9, 10, 5, 9); 
   gSP1Triangle(glistp++,9, 5, 7, 9); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,10, 9, 11, 10); 
   gSP1Triangle(glistp++,12, 13, 14, 12); 
   gSP1Triangle(glistp++,13, 12, 15, 13); 
   gSP1Triangle(glistp++,16, 17, 12, 16); 
   gSP1Triangle(glistp++,16, 12, 14, 16); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,17, 16, 18, 17); 
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSP1Triangle(glistp++,20, 19, 22, 20); 
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,19, 21, 23, 19); 
   gSPVertex(glistp++,LadingZone_obeliskslit_VTXPointer+24,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,2, 3, 0, 2); 
   gSP1Triangle(glistp++,4, 0, 5, 4); 
   gSP1Triangle(glistp++,0, 4, 1, 0); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x18a26bf8);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x27486bf8);
   gSP1Triangle(glistp++,4, 5, 6, 4); 

   gDPPipeSync(glistp++);

 } 
 
 

 void Landing_2001_PolyList(u8 animFrame) 
 { 

   Vtx *Landing_2001_VTXPointer = &Landing_2001_VertList_0[0]; 

   gSPVertex(glistp++,Landing_2001_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 1 'RockToBlack'OK 

   TEXTURE_4B_TLUT(glistp, RockToBlack, RockToBlack_tlut, 6,1);

   gSPVertex(glistp++,Landing_2001_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,6, 7, 8, 6); 
   gSP1Triangle(glistp++,8, 9, 6, 8); 
   gSP1Triangle(glistp++,10, 11, 12, 10); 
   gSP1Triangle(glistp++,12, 13, 10, 12); 
   gSP1Triangle(glistp++,0, 14, 15, 0); 
   gSP1Triangle(glistp++,15, 1, 0, 15); 
   gSP1Triangle(glistp++,14, 4, 3, 14); 
   gSP1Triangle(glistp++,3, 15, 14, 3); 
   gSP1Triangle(glistp++,0, 16, 17, 0); 
   gSP1Triangle(glistp++,17, 18, 0, 17); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x9ffa0fba);
   gSP1Triangle(glistp++,6, 4, 19, 6); 
   gSP1Triangle(glistp++,19, 20, 6, 19); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x00300fba);           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x0030082a);
   gSP1Triangle(glistp++,7, 6, 20, 7); 
   gSP1Triangle(glistp++,20, 21, 7, 20); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x28230fba);
   gSP1Triangle(glistp++,10, 7, 21, 10); 
   gSP1Triangle(glistp++,21, 22, 10, 21); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x3c1c0fba);
   gSP1Triangle(glistp++,11, 10, 22, 11); 
   gSP1Triangle(glistp++,22, 23, 11, 22); 
   gSP1Triangle(glistp++,16, 11, 23, 16); 
   gSP1Triangle(glistp++,23, 17, 16, 23); 
   gSP1Triangle(glistp++,14, 0, 18, 14); 
   gSP1Triangle(glistp++,18, 24, 14, 18); 
   gSP1Triangle(glistp++,4, 14, 24, 4); 
   gSP1Triangle(glistp++,24, 19, 4, 24); 
   gSP1Triangle(glistp++,2, 25, 16, 2); 
   gSP1Triangle(glistp++,2, 16, 0, 2); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x9ffa0fba);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x9ffa0039);
   gSP1Triangle(glistp++,6, 9, 5, 6); 
   gSP1Triangle(glistp++,4, 6, 5, 4); 
   gSPVertex(glistp++,Landing_2001_VTXPointer+16,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x12d80f76);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0f280046);
   gSP1Triangle(glistp++,0, 9, 10, 0); 
   gSP1Triangle(glistp++,10, 11, 0, 10); 
   gSPVertex(glistp++,Landing_2001_VTXPointer+11,26,0);
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x005f006d);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00480fb9);
   gSP1Triangle(glistp++,1, 0, 17, 1); 
   gSP1Triangle(glistp++,17, 18, 1, 17); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x00330f6e);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x00390f62);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x002a0f62);
   gSP1Triangle(glistp++,17, 0, 5, 17); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x002a0f6c);
   gSP1Triangle(glistp++,5, 16, 17, 5); 

   gDPPipeSync(glistp++);

 } 
 
 
 
 void Landing001_PolyList(u8 animFrame) 
 { 

   Vtx *Landing001_VTXPointer = &Landing001_VertList_0[0]; 

   gSPVertex(glistp++,Landing001_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 0 'RockDirtEdge'OK 

   TEXTURE_4B_TLUT(glistp, RockDirtEdge, RockDirtEdge_tlut, 6,1);

   gSPVertex(glistp++,Landing001_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,2, 3, 0, 2); 
   gSP1Triangle(glistp++,4, 5, 6, 4); 
   gSP1Triangle(glistp++,6, 7, 4, 6); 
   gSP1Triangle(glistp++,8, 1, 0, 8); 
   gSP1Triangle(glistp++,0, 9, 8, 0); 
   gSP1Triangle(glistp++,10, 8, 11, 10); 
   gSP1Triangle(glistp++,11, 12, 10, 11); 
   gSP1Triangle(glistp++,13, 14, 15, 13); 
   gSP1Triangle(glistp++,15, 16, 13, 15); 
   gSP1Triangle(glistp++,17, 13, 2, 17); 
   gSP1Triangle(glistp++,18, 19, 5, 18); 
   gSP1Triangle(glistp++,5, 4, 18, 5); 
   gSP1Triangle(glistp++,20, 21, 22, 20); 
   gSP1Triangle(glistp++,22, 23, 20, 22); 
   gSP1Triangle(glistp++,10, 24, 1, 10); 
   gSP1Triangle(glistp++,1, 8, 10, 1); 
   gSP1Triangle(glistp++,13, 17, 25, 13); 
   gSP1Triangle(glistp++,25, 14, 13, 25); 
   gSPVertex(glistp++,Landing001_VTXPointer+25,26,0);
   gSP1Triangle(glistp++,1, 2, 3, 1); 
   gSP1Triangle(glistp++,3, 4, 1, 3); 
   gSPVertex(glistp++,Landing001_VTXPointer+8,26,0);
   gSP1Triangle(glistp++,0, 1, 22, 0); 
   gSP1Triangle(glistp++,23, 24, 25, 23); 
   gSPVertex(glistp++,Landing001_VTXPointer+31,26,0);
   gSP1Triangle(glistp++,2, 3, 0, 2); 
   gSPVertex(glistp++,Landing001_VTXPointer+26,26,0);
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x41180817);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x41181019);
   gSP1Triangle(glistp++,6, 1, 0, 6); 
   gSP1Triangle(glistp++,0, 7, 6, 0); 
   gSP1Triangle(glistp++,2, 9, 10, 2); 
   gSP1Triangle(glistp++,10, 3, 2, 10); 
   gSP1Triangle(glistp++,11, 12, 13, 11); 
   gSP1Triangle(glistp++,13, 14, 11, 13); 
   gSPVertex(glistp++,Landing001_VTXPointer+25,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x8a1721dc);
   gSP1Triangle(glistp++,16, 17, 0, 16); 
   gSPVertex(glistp++,Landing001_VTXPointer+17,26,0);
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x8a1721dc);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x978e2004);
   gSP1Triangle(glistp++,8, 0, 24, 8); 
   gSPVertex(glistp++,Landing001_VTXPointer+42,26,0);
   gSP1Triangle(glistp++,1, 2, 3, 1); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x1b652871);
   gSP1Triangle(glistp++,3, 0, 1, 3); 
   gSPVertex(glistp++,Landing001_VTXPointer+38,26,0);
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x1f34201f);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x1f25291f);
   gSP1Triangle(glistp++,1, 0, 8, 1); 
   gSP1Triangle(glistp++,8, 9, 1, 8); 
   gSP1Triangle(glistp++,10, 11, 12, 10); 
   gSP1Triangle(glistp++,12, 13, 10, 12); 
   gSP1Triangle(glistp++,14, 15, 16, 14); 
   gSP1Triangle(glistp++,16, 17, 14, 16); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x87000021);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x90fd0021);
   gSP1Triangle(glistp++,7, 6, 14, 7); 
   gSP1Triangle(glistp++,14, 17, 7, 14); 
   gSP1Triangle(glistp++,18, 19, 20, 18); 
   gSP1Triangle(glistp++,20, 21, 18, 20); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x261617e8);
   gSP1Triangle(glistp++,22, 21, 17, 22); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x26161048);
   gSP1Triangle(glistp++,17, 16, 22, 17); 
   gSP1Triangle(glistp++,23, 24, 25, 23); 
   gSPVertex(glistp++,Landing001_VTXPointer+61,26,0);
   gSP1Triangle(glistp++,2, 3, 0, 2); 
   gSPVertex(glistp++,Landing001_VTXPointer+45,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x26161fd3);           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x261617e8);
   gSP1Triangle(glistp++,13, 0, 10, 13); 
   gSP1Triangle(glistp++,10, 14, 13, 10); 
   gSP1Triangle(glistp++,20, 21, 18, 20); 
   gSP1Triangle(glistp++,18, 17, 20, 18); 
   gSP1Triangle(glistp++,15, 22, 11, 15); 
   gSP1Triangle(glistp++,11, 14, 15, 11); 
           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x8a1721dc);
   gSP1Triangle(glistp++,20, 23, 24, 20); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x7fd320ba);
   gSP1Triangle(glistp++,24, 21, 20, 24); 
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x1b652871);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x17511fc1);           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x09021fe0);
   gSP1Triangle(glistp++,23, 13, 12, 23); 
           gSPModifyVertex(glistp++, 24,   G_MWO_POINT_ST, 0x095e2811);
   gSP1Triangle(glistp++,12, 24, 23, 12); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x260b1fdd);
   gSP1Triangle(glistp++,0, 13, 23, 0); 
   gSPVertex(glistp++,Landing001_VTXPointer+3,26,0);
   gSP1Triangle(glistp++,10, 13, 0, 10); 
   gSPVertex(glistp++,Landing001_VTXPointer+2,26,0);
   gSP1Triangle(glistp++,1, 0, 11, 1); 
   gSP1Triangle(glistp++,0, 22, 15, 0); 
   gSPVertex(glistp++,Landing001_VTXPointer+1,26,0);
   gSP1Triangle(glistp++,1, 0, 23, 1); 
   gSPVertex(glistp++,Landing001_VTXPointer+51,26,0);
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSP1Triangle(glistp++,21, 22, 19, 21); 
   gSP1Triangle(glistp++,22, 21, 23, 22); 

   gDPPipeSync(glistp++);

 } 
 
 
 
 
 //Test Object = 5 
void Landing_Staris001_PolyList(u8 animFrame) 
 { 

   Vtx *Landing_Staris001_VTXPointer = &Landing_Staris001_VertList_0[0]; 

   gSPVertex(glistp++,Landing_Staris001_VTXPointer+0,26,0);

//OBJECT: 5 MATERIAL NO. 2 'Stairs2'OK 

   TEXTURE_4B_TLUT(glistp, Stairs2, Stairs2_tlut, 6,1);

   gSPVertex(glistp++,Landing_Staris001_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,2, 3, 0, 2); 
   gSP1Triangle(glistp++,4, 0, 3, 4); 
   gSP1Triangle(glistp++,3, 5, 4, 3); 
   gSP1Triangle(glistp++,6, 4, 5, 6); 
   gSP1Triangle(glistp++,5, 7, 6, 5); 
   gSP1Triangle(glistp++,8, 9, 10, 8); 
   gSP1Triangle(glistp++,11, 6, 7, 11); 
   gSP1Triangle(glistp++,7, 12, 11, 7); 
   gSP1Triangle(glistp++,13, 11, 12, 13); 
   gSP1Triangle(glistp++,12, 14, 13, 12); 
   gSP1Triangle(glistp++,15, 13, 14, 15); 
   gSP1Triangle(glistp++,16, 9, 8, 16); 
   gSP1Triangle(glistp++,8, 17, 16, 8); 
   gSP1Triangle(glistp++,18, 16, 17, 18); 
   gSP1Triangle(glistp++,17, 19, 18, 17); 
   gSP1Triangle(glistp++,20, 18, 19, 20); 
   gSP1Triangle(glistp++,19, 21, 20, 19); 
           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x005f0fca);           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x005f2000);
   gSP1Triangle(glistp++,1, 20, 21, 1); 
   gSP1Triangle(glistp++,21, 2, 1, 21); 

   gDPPipeSync(glistp++);

 } 
 
 
 
 
 
//Test Object = 0 
Vtx Landing_Ground001_VertList_0 [] = {
   { 4051.45, -1375.76, 99.80, 1, 0x0475, 0x1645, 19, 18, 124, 255}, 
   { 3725.56, -1144.41, 99.80, 1, 0x00e7, 0x20fd, 12, 22, 124, 255}, 
   { 3733.17, -1704.66, -0.00, 1, 0x101f, 0x1c3b, 17, 15, 124, 255}, 
   { 3094.31, -1401.17, -0.00, 1, 0x0d32, 0x2fff, 6, 10, 126, 255}, 
   { 3256.30, -1031.54, 80.67, 1, 0x01c1, 0x2e9d, 13, 21, 124, 255}, 
   { 2513.63, -844.23, 0.00, 1, 0x02f4, 0x444c, 5, 5, 126, 255}, 
   { 3773.18, -1029.44, 301.46, 1, 0x1e73, 0x20a8, 0, 0, 127, 255}, 
   { 3402.94, -341.17, 301.46, 1, 0x0b5f, 0x2bc7, 0, 0, 127, 255}, 
   { 3256.30, -896.85, 301.46, 1, 0x1b2f, 0x2f5e, 0, 0, 127, 255}, 
   { 4165.39, -1316.44, 301.46, 1, 0x2630, 0x154f, 1, 0, 126, 255}, 
   { 4387.49, -748.99, 301.46, 1, 0x15f9, 0x0f9b, 0, 0, 126, 255}, 
   { 2853.76, -430.00, 301.46, 1, 0x0e61, 0x3b2e, 0, 0, 127, 255}, 
   { 2846.97, -924.87, 301.46, 1, 0x1c59, 0x3ae3, 0, 0, 127, 255}, 
   { 2418.39, -748.99, 301.46, 1, 0x17c7, 0x4726, 0, 0, 127, 255}, 
   { 4836.88, -1663.07, 311.27, 1, 0x2f56, 0x0204, 2, 0, 126, 255}, 
   { 4376.16, -2027.11, 301.46, 1, 0x3a0b, 0x0eaa, 2, 0, 126, 255}, 
   { 4307.46, -2015.37, 72.49, 1, 0x13a7, 0x0a13, 18, 6, 125, 255}, 
   { 3405.90, -2990.56, -0.00, 1, 0x3583, 0x1a62, 1, 0, 126, 255}, 
   { 4155.98, -2625.11, 35.77, 1, 0x256a, 0x0923, 10, 0, 126, 255}, 
   { 3768.11, -2084.08, -0.00, 1, 0x1a12, 0x1823, 9, 0, 126, 255}, 
   { 2145.27, -1733.54, -0.00, 1, 0x1dfc, 0x46da, 0, 0, 127, 255}, 
   { 2239.69, -2201.59, -0.00, 1, 0x29d5, 0x406b, 0, 0, 126, 255}, 
   { 3044.49, -3318.97, -0.00, 1, 0x4159, 0x216a, 0, 0, 127, 255}, 
   { 2513.16, -2625.29, -0.00, 1, 0x3303, 0x3584, 0, 0, 127, 255}, 
   { 2295.89, -3029.65, -0.00, 1, 0x3fb6, 0x3806, 0, 0, 127, 255}, 
   { 3589.37, 47.02, 301.46, 1, 0x0040, 0x26e7, 0, 0, 127, 255}, 
   { 4443.80, 27.72, 301.46, 1, 0x0002, 0x0ec8, 0, 0, 127, 255}, 
   { 1923.83, -3623.06, -0.00, 1, 0x52c9, 0x3d23, 0, 0, 126, 255}, 
   { 1812.60, -3063.19, -0.00, 1, 0x4499, 0x44ca, 0, 0, 127, 255}, 
   { 2528.68, -3737.61, -0.00, 1, 0x50e5, 0x2bdc, 0, 0, 127, 255}, 
   { 4231.09, -2677.77, 301.45, 1, 0x4c88, 0x121e, 3, 0, 126, 255}, 
};


//Test Object = 1 
Vtx Landing_Pad001_VertList_0 [] = {
   { 3782.21, -1819.79, 39.37, 1, 0x0809, 0x0dce, 0, 0, 126, 255}, 
   { 3782.21, -1615.99, 39.37, 1, 0x0ff5, 0x0ff5, 0, 0, 127, 255}, 
   { 3401.92, -1717.89, 39.37, 1, 0x0ffa, 0x0002, 0, 0, 127, 255}, 
   { 3123.53, -1996.28, 39.37, 1, 0x07f7, 0x0dd9, 0, 0, 126, 255}, 
   { 3300.02, -2098.18, 39.37, 1, 0x0222, 0x07fe, 0, 0, 127, 255}, 
   { 3503.82, -1337.61, 39.37, 1, 0x0227, 0x07f3, 0, 0, 127, 255}, 
   { 3300.02, -1337.61, 39.37, 1, 0x0003, 0x000b, 0, 0, 127, 255}, 
   { 3123.53, -1439.50, 39.37, 1, 0x022b, 0x0805, 0, 0, 127, 255}, 
   { 3021.63, -1615.99, 39.37, 1, 0x0806, 0x0dd9, 0, 0, 127, 255}, 
   { 3503.82, -2098.18, 39.37, 1, 0x0003, 0x0002, 0, 0, 127, 255}, 
   { 3680.31, -1996.28, 39.37, 1, 0x022f, 0x07f9, 0, 0, 127, 255}, 
   { 3680.31, -1439.50, 39.37, 1, 0x07fb, 0x0dce, 0, 0, 127, 255}, 
   { 3021.63, -1819.79, 39.37, 1, 0x1002, 0x0ff8, 0, 0, 127, 255}, 
};

//Test Object = 1 
Vtx LadingZone_obelisks001001_VertList_0 [] = {
   { 3485.50, -1085.53, 158.30, 1, 0x19f1, 0x5c03, -124, 23, -11, 255}, 
   { 3457.61, -1240.22, 168.02, 1, 0x0611, 0x5c03, -124, 23, -11, 255}, 
   { 3450.06, -1229.03, 67.99, 1, 0x080b, 0x6856, -124, 23, -11, 255}, 
   { 3472.34, -1105.44, 60.22, 1, 0x17f1, 0x6856, -124, 23, -11, 255}, 
   { 3340.07, -1075.42, 1177.59, 1, 0x2000, 0x0c3c, -123, 21, 17, 255}, 
   { 3302.84, -1212.96, 157.83, 1, 0x19f1, 0x5c03, 122, -20, -28, 255}, 
   { 3330.73, -1058.27, 148.11, 1, 0x0611, 0x5c03, 122, -20, -28, 255}, 
   { 3348.68, -1083.65, 52.08, 1, 0x080b, 0x6856, 122, -20, -28, 255}, 
   { 3326.40, -1207.25, 59.85, 1, 0x17f1, 0x6856, 122, -20, -28, 255}, 
   { 3340.07, -1075.42, 1177.59, 1, 0x2000, 0x0c3c, 124, -22, 1, 255}, 
   { 3330.73, -1058.27, 148.11, 1, 0x19f1, 0x5c03, -23, -121, -27, 255}, 
   { 3485.50, -1085.53, 158.30, 1, 0x0611, 0x5c03, -23, -121, -27, 255}, 
   { 3472.34, -1105.44, 60.22, 1, 0x080b, 0x6856, -23, -121, -27, 255}, 
   { 3348.68, -1083.65, 52.08, 1, 0x17f1, 0x6856, -23, -121, -27, 255}, 
   { 3485.50, -1085.53, 158.30, 1, 0x18a2, 0x6bf8, -21, -125, 1, 255}, 
   { 3330.73, -1058.27, 148.11, 1, 0x2748, 0x6bf8, -21, -125, 1, 255}, 
   { 3340.07, -1075.42, 1177.59, 1, 0x2000, 0x0c3c, -21, -125, 1, 255}, 
   { 3801.91, -2030.19, 59.05, 1, 0x080b, 0x6856, 61, 106, 32, 255}, 
   { 3916.67, -2114.72, -0.00, 1, 0x17f1, 0x6bfe, 61, 106, 32, 255}, 
   { 3910.88, -2093.10, 59.05, 1, 0x17f1, 0x6856, 61, 106, 32, 255}, 
   { 3780.29, -2035.98, -0.00, 1, 0x080b, 0x6bfe, 61, 106, 32, 255}, 
   { 3916.67, -2114.72, 157.48, 1, 0x19f1, 0x5c03, 62, 108, -20, 255}, 
   { 3780.29, -2035.98, 157.48, 1, 0x0611, 0x5c03, 62, 108, -20, 255}, 
   { 3887.85, -2007.16, 1181.10, 1, 0x2000, 0x0c3c, 63, 109, 9, 255}, 
   { 3973.80, -1984.13, 59.06, 1, 0x080b, 0x6856, -61, -106, 32, 255}, 
   { 3859.03, -1899.60, -0.00, 1, 0x17f1, 0x6bfe, -61, -106, 32, 255}, 
   { 3864.83, -1921.22, 59.06, 1, 0x17f1, 0x6856, -61, -106, 32, 255}, 
   { 3995.41, -1978.34, -0.00, 1, 0x080b, 0x6bfe, -61, -106, 32, 255}, 
   { 3859.03, -1899.60, 157.48, 1, 0x19f1, 0x5c03, -62, -108, -20, 255}, 
   { 3995.41, -1978.34, 157.48, 1, 0x0611, 0x5c03, -62, -108, -20, 255}, 
   { 3887.85, -2007.16, 1181.10, 1, 0x2000, 0x0c3c, -63, -109, 9, 255}, 
   { 3995.41, -1978.34, -0.00, 1, 0x17f1, 0x6bfe, -106, 61, 32, 255}, 
   { 3973.80, -1984.13, 59.06, 1, 0x17f1, 0x6856, -106, 61, 32, 255}, 
   { 3916.67, -2114.72, -0.00, 1, 0x080b, 0x6bfe, -106, 61, 32, 255}, 
   { 3995.41, -1978.34, 157.48, 1, 0x19f1, 0x5c03, -108, 62, -20, 255}, 
   { 3916.67, -2114.72, 157.48, 1, 0x0611, 0x5c03, -108, 62, -20, 255}, 
   { 2971.00, -1405.17, 59.06, 1, 0x080b, 0x6856, -61, -106, 32, 255}, 
   { 2856.23, -1320.64, -0.00, 1, 0x17f1, 0x6bfe, -61, -106, 32, 255}, 
   { 2862.03, -1342.26, 59.06, 1, 0x17f1, 0x6856, -61, -106, 32, 255}, 
   { 2992.62, -1399.38, -0.00, 1, 0x080b, 0x6bfe, -61, -106, 32, 255}, 
   { 2856.23, -1320.64, 157.48, 1, 0x19f1, 0x5c03, -62, -108, -20, 255}, 
   { 2992.62, -1399.38, 157.48, 1, 0x0611, 0x5c03, -62, -108, -20, 255}, 
   { 2885.06, -1428.20, 1181.10, 1, 0x2000, 0x0c3c, -63, -109, 9, 255}, 
   { 2799.11, -1451.23, 59.06, 1, 0x080b, 0x6856, 61, 106, 32, 255}, 
   { 2913.88, -1535.76, -0.00, 1, 0x17f1, 0x6bfe, 61, 106, 32, 255}, 
   { 2908.08, -1514.14, 59.06, 1, 0x17f1, 0x6856, 61, 106, 32, 255}, 
   { 2777.49, -1457.02, -0.00, 1, 0x080b, 0x6bfe, 61, 106, 32, 255}, 
   { 2913.88, -1535.76, 157.48, 1, 0x19f1, 0x5c03, 62, 108, -20, 255}, 
   { 2777.49, -1457.02, 157.48, 1, 0x0611, 0x5c03, 62, 108, -20, 255}, 
   { 2885.06, -1428.20, 1181.10, 1, 0x2000, 0x0c3c, 63, 109, 9, 255}, 
   { 2777.49, -1457.02, -0.00, 1, 0x17f1, 0x6bfe, 106, -61, 32, 255}, 
   { 2777.49, -1457.02, 157.48, 1, 0x19f1, 0x5c03, 108, -62, -20, 255}, 
   { 2856.23, -1320.64, 157.48, 1, 0x18a2, 0x6bf8, 109, -63, 9, 255}, 
   { 2885.06, -1428.20, 1181.10, 1, 0x2000, 0x0c3c, 109, -63, 9, 255}, 
   { 3858.76, -1528.05, 150.21, 1, 0x0611, 0x5c03, -57, 110, -22, 255}, 
   { 3981.24, -1445.86, 59.41, 1, 0x17f1, 0x6856, -57, 110, -22, 255}, 
   { 3998.96, -1456.79, 158.18, 1, 0x19f1, 0x5c03, -57, 110, -22, 255}, 
   { 3869.21, -1502.80, 53.05, 1, 0x080b, 0x6856, -57, 110, -22, 255}, 
   { 3856.19, -1463.80, 1177.87, 1, 0x2000, 0x0c3c, -57, 113, 7, 255}, 
   { 3927.48, -1316.50, 161.29, 1, 0x0611, 0x5c03, 56, -112, -17, 255}, 
   { 3812.10, -1390.71, 55.54, 1, 0x17f1, 0x6856, 56, -112, -17, 255}, 
   { 3787.28, -1387.76, 153.33, 1, 0x19f1, 0x5c03, 56, -112, -17, 255}, 
   { 3924.13, -1333.77, 61.90, 1, 0x080b, 0x6856, 56, -112, -17, 255}, 
   { 3856.19, -1463.80, 1177.87, 1, 0x2000, 0x0c3c, 57, -112, 12, 255}, 
   { 3998.96, -1456.79, 158.18, 1, 0x0611, 0x5c03, -112, -57, -13, 255}, 
   { 3924.13, -1333.77, 61.90, 1, 0x17f1, 0x6856, -112, -57, -13, 255}, 
   { 3927.48, -1316.50, 161.29, 1, 0x19f1, 0x5c03, -112, -57, -13, 255}, 
   { 3981.24, -1445.86, 59.41, 1, 0x080b, 0x6856, -112, -57, -13, 255}, 
   { 3856.19, -1463.80, 1177.87, 1, 0x2000, 0x0c3c, -112, -56, 16, 255}, 
   { 2799.11, -1984.14, 59.06, 1, 0x17f1, 0x6856, 61, -106, 32, 255}, 
   { 2908.08, -1921.22, 59.06, 1, 0x080b, 0x6856, 61, -106, 32, 255}, 
   { 2913.88, -1899.60, -0.00, 1, 0x080b, 0x6bfe, 61, -106, 32, 255}, 
   { 2777.50, -1978.34, -0.00, 1, 0x17f1, 0x6bfe, 61, -106, 32, 255}, 
   { 2913.88, -1899.60, 157.48, 1, 0x0611, 0x5c03, 62, -108, -20, 255}, 
   { 2777.50, -1978.34, 157.48, 1, 0x19f1, 0x5c03, 62, -108, -20, 255}, 
   { 2885.06, -2007.16, 1181.10, 1, 0x2000, 0x0c3c, 63, -109, 9, 255}, 
   { 2971.00, -2030.19, 59.05, 1, 0x17f1, 0x6856, -61, 106, 32, 255}, 
   { 2862.03, -2093.11, 59.05, 1, 0x080b, 0x6856, -61, 106, 32, 255}, 
   { 2856.24, -2114.72, -0.00, 1, 0x080b, 0x6bfe, -61, 106, 32, 255}, 
   { 2992.62, -2035.98, -0.00, 1, 0x17f1, 0x6bfe, -61, 106, 32, 255}, 
   { 2856.24, -2114.72, 157.48, 1, 0x0611, 0x5c03, -62, 108, -20, 255}, 
   { 2992.62, -2035.98, 157.48, 1, 0x19f1, 0x5c03, -62, 108, -20, 255}, 
   { 2885.06, -2007.16, 1181.10, 1, 0x2000, 0x0c3c, -63, 109, 9, 255}, 
   { 2862.03, -2093.11, 59.05, 1, 0x17f1, 0x6856, 106, 61, 32, 255}, 
   { 2799.11, -1984.14, 59.06, 1, 0x080b, 0x6856, 106, 61, 32, 255}, 
   { 2777.50, -1978.34, -0.00, 1, 0x080b, 0x6bfe, 106, 61, 32, 255}, 
   { 2856.24, -2114.72, -0.00, 1, 0x17f1, 0x6bfe, 106, 61, 32, 255}, 
   { 2777.50, -1978.34, 157.48, 1, 0x0611, 0x5c03, 108, 62, -20, 255}, 
   { 2856.24, -2114.72, 157.48, 1, 0x19f1, 0x5c03, 108, 62, -20, 255}, 
   { 2777.49, -1978.34, 157.48, 1, 0x18a2, 0x6bf8, 109, 63, 9, 255}, 
   { 2885.06, -2007.16, 1181.10, 1, 0x2000, 0x0c3c, 109, 63, 9, 255}, 
};


//Test Object = 0 
Vtx LadingZone_obeliskslit_VertList_0 [] = {
   { 3457.61, -1240.22, 168.02, 1, 0x19f1, 0x5c03, 21, 124, -12, 255}, 
   { 3302.84, -1212.96, 157.83, 1, 0x0611, 0x5c03, 21, 124, -12, 255}, 
   { 3326.40, -1207.25, 59.85, 1, 0x080b, 0x6856, 21, 124, -12, 255}, 
   { 3450.06, -1229.03, 67.99, 1, 0x17f1, 0x6856, 21, 124, -12, 255}, 
   { 3340.07, -1075.42, 1177.59, 1, 0x2000, 0x0c3c, 22, 123, 17, 255}, 
   { 3864.83, -1921.22, 59.06, 1, 0x080b, 0x6856, 106, -61, 32, 255}, 
   { 3780.29, -2035.98, -0.00, 1, 0x17f1, 0x6bfe, 106, -61, 32, 255}, 
   { 3801.91, -2030.19, 59.05, 1, 0x17f1, 0x6856, 106, -61, 32, 255}, 
   { 3859.03, -1899.60, -0.00, 1, 0x080b, 0x6bfe, 106, -61, 32, 255}, 
   { 3780.29, -2035.98, 157.48, 1, 0x19f1, 0x5c03, 108, -62, -20, 255}, 
   { 3859.03, -1899.60, 157.48, 1, 0x0611, 0x5c03, 108, -62, -20, 255}, 
   { 3887.85, -2007.16, 1181.10, 1, 0x2000, 0x0c3c, 109, -63, 9, 255}, 
   { 2908.08, -1514.14, 59.06, 1, 0x080b, 0x6856, -106, 61, 32, 255}, 
   { 2992.62, -1399.38, -0.00, 1, 0x17f1, 0x6bfe, -106, 61, 32, 255}, 
   { 2971.00, -1405.17, 59.06, 1, 0x17f1, 0x6856, -106, 61, 32, 255}, 
   { 2913.88, -1535.76, -0.00, 1, 0x080b, 0x6bfe, -106, 61, 32, 255}, 
   { 2992.62, -1399.38, 157.48, 1, 0x19f1, 0x5c03, -108, 62, -20, 255}, 
   { 2913.88, -1535.76, 157.48, 1, 0x0611, 0x5c03, -108, 62, -20, 255}, 
   { 2885.06, -1428.20, 1181.10, 1, 0x2000, 0x0c3c, -109, 63, 9, 255}, 
   { 3787.28, -1387.76, 153.33, 1, 0x0611, 0x5c03, 110, 55, -26, 255}, 
   { 3869.21, -1502.80, 53.05, 1, 0x17f1, 0x6856, 110, 55, -26, 255}, 
   { 3858.76, -1528.05, 150.21, 1, 0x19f1, 0x5c03, 110, 55, -26, 255}, 
   { 3812.10, -1390.71, 55.54, 1, 0x080b, 0x6856, 110, 55, -26, 255}, 
   { 3856.19, -1463.80, 1177.87, 1, 0x2000, 0x0c3c, 113, 57, 3, 255}, 
   { 2908.08, -1921.22, 59.06, 1, 0x17f1, 0x6856, -106, -61, 32, 255}, 
   { 2971.00, -2030.19, 59.05, 1, 0x080b, 0x6856, -106, -61, 32, 255}, 
   { 2992.62, -2035.98, -0.00, 1, 0x080b, 0x6bfe, -106, -61, 32, 255}, 
   { 2913.88, -1899.60, -0.00, 1, 0x17f1, 0x6bfe, -106, -61, 32, 255}, 
   { 2992.62, -2035.98, 157.48, 1, 0x0611, 0x5c03, -108, -62, -20, 255}, 
   { 2913.88, -1899.60, 157.48, 1, 0x19f1, 0x5c03, -108, -62, -20, 255}, 
   { 2885.06, -2007.16, 1181.10, 1, 0x2000, 0x0c3c, -109, -63, 9, 255}, 
};


//Test Object = 0 
Vtx Landing_2001_VertList_0 [] = {
   { 2850.41, -1181.01, 1205.82, 1, 0x640f, 0x0fba, -73, 62, -82, 255}, 
   { 2445.03, -815.65, 602.91, 1, 0x640f, 0x0039, -76, 54, -84, 255}, 
   { 2866.13, -515.28, 624.38, 1, 0x5a12, 0x0039, -42, 85, -84, 255}, 
   { 2513.63, -2622.84, 602.91, 1, 0x8c01, 0x0039, -85, -52, -77, 255}, 
   { 2850.41, -2286.07, 1205.82, 1, 0x8c01, 0x0fba, -72, -64, -82, 255}, 
   { 2899.76, -2928.48, 715.38, 1, 0x95fe, 0x0039, -35, -85, -87, 255}, 
   { 3402.94, -2514.93, 1205.82, 1, 0x0030, 0x0fba, -3, -97, -81, 255}, 
   { 4210.72, -2361.58, 1205.82, 1, 0x142a, 0x0fba, 44, -80, -87, 255}, 
   { 4292.25, -2622.84, 780.19, 1, 0x142a, 0x0039, 22, -101, -72, 255}, 
   { 3402.94, -2991.21, 602.91, 1, 0x0030, 0x0028, 14, -98, -78, 255}, 
   { 4353.81, -1819.10, 1205.82, 1, 0x0c4e, 0x0fba, 83, 22, -92, 255}, 
   { 3918.58, -1035.57, 1205.82, 1, 0x2048, 0x0fba, 64, 45, -99, 255}, 
   { 4281.64, -792.86, 723.36, 1, 0x2048, 0x0039, 94, 17, -83, 255}, 
   { 4743.40, -1681.50, 780.19, 1, 0x0c4e, 0x0039, 79, 46, -87, 255}, 
   { 2621.55, -1733.54, 1205.82, 1, 0x7808, 0x0fba, -100, 0, -77, 255}, 
   { 2145.27, -1733.54, 602.91, 1, 0x7808, 0x0039, -98, -2, -80, 255}, 
   { 3427.47, -849.94, 1205.82, 1, 0x5015, 0x0fba, -25, 75, -99, 255}, 
   { 3402.94, -1326.29, 1702.98, 1, 0x5015, 0x082a, -5, 94, -85, 255}, 
   { 3114.97, -1445.57, 1702.98, 1, 0x640f, 0x082a, -71, 71, -76, 255}, 
   { 3114.97, -2021.51, 1702.98, 1, 0x8c01, 0x082a, -71, -71, -76, 255}, 
   { 3402.94, -2140.79, 1702.98, 1, 0x9ffa, 0x082a, -7, -97, -80, 255}, 
   { 3690.91, -2021.51, 1702.98, 1, 0x142a, 0x082a, 57, -59, -96, 255}, 
   { 3810.19, -1733.54, 1702.98, 1, 0x2823, 0x082a, 88, 7, -90, 255}, 
   { 3690.91, -1445.57, 1702.98, 1, 0x3c1c, 0x082a, 70, 63, -84, 255}, 
   { 2995.69, -1733.54, 1702.98, 1, 0x7808, 0x082a, -101, 0, -76, 255}, 
   { 3395.72, -424.50, 645.85, 1, 0x5015, 0x0039, -77, 78, -63, 255}, 
   { 3582.15, -36.31, 645.85, 1, 0x003c, 0x0046, -107, 50, -44, 255}, 
   { 3713.85, -101.31, 1046.21, 1, 0x003c, 0x0f96, -61, 45, -101, 255}, 
   { 4057.12, -110.63, 1046.21, 1, 0x1021, 0x0fb9, 63, 7, -109, 255}, 
   { 4352.92, -42.05, 723.36, 1, 0x1023, 0x0047, 94, -8, -84, 255}, 
};


//Test Object = 0 
Vtx Landing001_VertList_0 [] = {
   { 2145.27, -1733.54, -0.00, 1, 0x690a, 0x1019, -115, 12, 51, 255}, 
   { 2010.58, -1733.54, 301.46, 1, 0x690a, 0x0817, -126, 9, 1, 255}, 
   { 2105.26, -2207.46, 301.46, 1, 0x7307, 0x0817, -117, -46, -8, 255}, 
   { 2239.69, -2201.59, -0.00, 1, 0x7307, 0x1019, -107, -45, 49, 255}, 
   { 3484.94, -3098.07, 301.45, 1, 0x0019, 0x0817, 71, -104, 2, 255}, 
   { 4261.32, -2686.88, 434.62, 1, 0x1412, 0x0817, 53, -115, -1, 255}, 
   { 4155.98, -2625.11, 35.77, 1, 0x1412, 0x1019, 59, -105, 36, 255}, 
   { 3405.90, -2990.56, -0.00, 1, 0x0019, 0x1019, 66, -95, 51, 255}, 
   { 2418.39, -748.99, 301.46, 1, 0x5511, 0x0817, -82, 96, 6, 255}, 
   { 2513.63, -844.23, 0.00, 1, 0x5511, 0x1019, -22, 116, 44, 255}, 
   { 2445.03, -815.65, 602.91, 1, 0x5511, 0x0021, -98, 75, -27, 255}, 
   { 2859.43, -446.29, 301.46, 1, 0x4b14, 0x0817, -47, 114, -26, 255}, 
   { 2866.13, -515.28, 624.38, 1, 0x4b14, 0x0021, -49, 114, -25, 255}, 
   { 2379.45, -2634.58, 301.45, 1, 0x7d04, 0x0817, -126, -7, 0, 255}, 
   { 2254.92, -2952.69, 300.20, 1, 0x8700, 0x0817, -70, 105, -1, 255}, 
   { 2295.89, -3029.65, -0.00, 1, 0x8700, 0x1019, -63, 100, 43, 255}, 
   { 2513.63, -2622.84, -0.00, 1, 0x7d04, 0x1019, -115, -5, 51, 255}, 
   { 2513.63, -2622.84, 602.91, 1, 0x7d04, 0x0021, -90, 2, -89, 255}, 
   { 3402.94, -2991.21, 602.91, 1, 0x0019, 0x0014, 60, -86, -70, 255}, 
   { 4292.25, -2622.84, 780.19, 1, 0x1412, 0x0021, 45, -117, -17, 255}, 
   { 4743.40, -1681.50, 780.19, 1, 0x0c2d, 0x003d, 110, 55, -26, 255}, 
   { 4281.64, -792.86, 723.36, 1, 0x1ff1, 0x0021, 119, 26, -32, 255}, 
   { 4387.49, -748.99, 301.46, 1, 0x2063, 0x0aa9, 121, 23, -30, 255}, 
   { 4836.88, -1663.07, 311.27, 1, 0x0c2b, 0x0ba0, 111, 55, -24, 255}, 
   { 2145.27, -1733.54, 602.91, 1, 0x690a, 0x0021, -113, 2, -57, 255}, 
   { 2307.63, -3024.89, 594.86, 1, 0x8700, 0x0021, -39, 62, -103, 255}, 
   { 4051.45, -1375.76, 99.80, 1, 0x2d1f, 0x1019, 87, 65, 64, 255}, 
   { 4165.39, -1316.44, 301.46, 1, 0x2d1f, 0x0817, 88, 60, 67, 255}, 
   { 3773.18, -1029.44, 301.46, 1, 0x371b, 0x0817, 45, 98, 65, 255}, 
   { 3725.56, -1144.41, 99.80, 1, 0x371b, 0x1019, 45, 97, 66, 255}, 
   { 2841.54, -1049.19, 8.56, 1, 0x4b14, 0x1019, 29, 115, 42, 255}, 
   { 4231.09, -2677.77, 301.45, 1, 0x1925, 0x0817, 118, -26, 38, 255}, 
   { 4376.16, -2027.11, 301.46, 1, 0x2d1f, 0x0817, 120, 7, 39, 255}, 
   { 4307.46, -2015.37, 72.49, 1, 0x2d1f, 0x1019, 121, 11, 36, 255}, 
   { 4155.98, -2625.11, 35.77, 1, 0x1925, 0x1019, 117, -26, 38, 255}, 
   { 3256.30, -896.85, 301.46, 1, 0x4118, 0x0817, 9, 108, 65, 255}, 
   { 3256.30, -1031.54, 80.67, 1, 0x4118, 0x1019, 11, 109, 62, 255}, 
   { 2859.43, -446.29, 301.46, 1, 0x4b14, 0x0817, -47, 114, -26, 255}, 
   { 3402.94, -341.17, 301.46, 1, 0x4118, 0x0817, -81, 95, -21, 255}, 
   { 3395.72, -424.50, 645.85, 1, 0x4118, 0x0021, -72, 101, -22, 255}, 
   { 2866.13, -515.28, 624.38, 1, 0x4b14, 0x0021, -49, 114, -25, 255}, 
   { 2899.76, -2928.48, 715.38, 1, 0x965f, 0x27c4, 2, -6, -126, 255}, 
   { 2589.02, -3333.78, 708.62, 1, 0x89a8, 0x29cb, 1, -11, -126, 255}, 
   { 2899.76, -2928.48, 715.38, 1, 0x2ee2, 0x2ce1, 2, -6, -126, 255}, 
   { 3402.94, -2991.21, 602.91, 1, 0x2f99, 0x1f79, 60, -86, -70, 255}, 
   { 3068.27, -3340.63, 603.87, 1, 0x260b, 0x1fdd, 59, -68, -88, 255}, 
   { 3589.37, 47.02, 301.46, 1, 0x1052, 0x291f, -114, 54, -10, 255}, 
   { 3582.15, -36.31, 645.85, 1, 0x1052, 0x201f, -114, 54, -10, 255}, 
   { 4387.49, -748.99, 301.46, 1, 0x2063, 0x0aa9, 121, 23, -30, 255}, 
   { 4281.64, -792.86, 723.36, 1, 0x1ff1, 0x0021, 119, 26, -32, 255}, 
   { 4352.92, -42.05, 723.36, 1, 0x301f, 0x0021, 123, -9, -26, 255}, 
   { 4443.80, 27.72, 301.46, 1, 0x301f, 0x0a77, 124, -8, -25, 255}, 
   { 3484.94, -3098.07, 301.45, 1, 0x90fd, 0x0817, 71, -104, 2, 255}, 
   { 3405.90, -2990.56, -0.00, 1, 0x90fd, 0x1019, 66, -95, 51, 255}, 
   { 3044.49, -3318.97, -0.00, 1, 0x8700, 0x1019, 75, -90, 45, 255}, 
   { 3138.16, -3387.77, 302.02, 1, 0x8700, 0x0817, 80, -98, 5, 255}, 
   { 2007.25, -3709.49, 301.66, 1, 0x091b, 0x17ca, -23, -124, -10, 255}, 
   { 1992.39, -3555.35, 603.23, 1, 0x091b, 0x1fe1, -14, -77, -99, 255}, 
   { 2600.88, -3704.11, 603.32, 1, 0x179a, 0x1fb2, 22, -92, -84, 255}, 
   { 2626.72, -3793.68, 301.66, 1, 0x179a, 0x17b9, 37, -121, -1, 255}, 
   { 2528.68, -3737.61, -0.00, 1, 0x179a, 0x1015, 23, -120, 32, 255}, 
   { 2295.89, -3029.65, -0.00, 1, 0x86f4, 0x1018, -63, 100, 43, 255}, 
   { 2254.92, -2952.69, 300.20, 1, 0x86f4, 0x0807, -70, 105, -1, 255}, 
   { 1779.10, -2937.45, 295.53, 1, 0x942b, 0x082a, -7, 126, -2, 255}, 
   { 1812.60, -3063.19, -0.00, 1, 0x9426, 0x1018, -8, 116, 50, 255}, 
   { 2307.63, -3024.89, 594.86, 1, 0x86f4, 0x0021, -39, 62, -103, 255}, 
   { 1861.13, -3109.58, 591.05, 1, 0x942a, 0x0021, -16, 84, -93, 255}, 
   { 1923.83, -3623.06, -0.00, 1, 0x091b, 0x1034, -23, -121, 28, 255}, 
   { 2589.02, -3333.78, 708.62, 1, 0x89a8, 0x29cb, 1, -11, -126, 255}, 
   { 1926.76, -3332.46, 699.91, 1, 0x7e17, 0x285b, -5, 8, -126, 255}, 
   { 3256.30, -1031.54, 80.67, 1, 0x4118, 0x1019, 11, 109, 62, 255}, 
   { 3256.30, -896.85, 301.46, 1, 0x4118, 0x0817, 9, 108, 65, 255}, 
   { 2846.97, -924.87, 301.46, 1, 0x4b14, 0x0817, 23, 113, 52, 255}, 
   { 2841.54, -1049.19, 8.56, 1, 0x4b14, 0x1019, 29, 115, 42, 255}, 
   { 2418.39, -748.99, 301.46, 1, 0x5511, 0x0817, -82, 96, 6, 255}, 
};


//Test Object = 5 
Vtx Landing_Staris001_VertList_0 [] = {
   { 3300.02, -2098.18, 39.37, 1, 0x1db3, 0x0fca, 9, 37, 121, 255}, 
   { 3123.53, -1996.28, 39.37, 1, 0x0f09, 0x0fca, 27, 27, 121, 255}, 
   { 3035.73, -2084.08, -0.00, 1, 0x0f09, 0x2000, 27, 27, 121, 255}, 
   { 3267.89, -2218.12, -0.00, 1, 0x1db3, 0x2000, 9, 37, 121, 255}, 
   { 3503.82, -2098.18, 39.37, 1, 0x2c5d, 0x0fca, -9, 37, 121, 255}, 
   { 3535.96, -2218.12, -0.00, 1, 0x2c5d, 0x2000, -9, 37, 121, 255}, 
   { 3680.31, -1996.28, 39.37, 1, 0x3b07, 0x0fca, -27, 27, 121, 255}, 
   { 3768.11, -2084.08, -0.00, 1, 0x3b07, 0x2000, -27, 27, 121, 255}, 
   { 3267.88, -1217.67, 0.00, 1, 0x845a, 0x2000, 12, -36, 121, 255}, 
   { 3300.02, -1337.61, 39.37, 1, 0x845a, 0x0fca, 9, -37, 121, 255}, 
   { 3503.82, -1337.61, 39.37, 1, 0x75b0, 0x0fca, 0, -39, 120, 255}, 
   { 3782.21, -1819.79, 39.37, 1, 0x49b2, 0x0fca, -37, 9, 121, 255}, 
   { 3902.15, -1851.93, -0.00, 1, 0x49b2, 0x2000, -37, 9, 120, 255}, 
   { 3782.21, -1615.99, 39.37, 1, 0x585c, 0x0fca, -38, -10, 120, 255}, 
   { 3896.81, -1581.00, -0.00, 1, 0x585c, 0x2000, -38, -8, 120, 255}, 
   { 3680.31, -1439.50, 39.37, 1, 0x6706, 0x0fca, -35, -20, 120, 255}, 
   { 3123.53, -1439.50, 39.37, 1, 0x9304, 0x0fca, 27, -27, 121, 255}, 
   { 3035.73, -1351.70, 0.00, 1, 0x9304, 0x2000, 27, -27, 121, 255}, 
   { 3021.63, -1615.99, 39.37, 1, 0xa1ae, 0x0fca, 37, -9, 121, 255}, 
   { 2901.69, -1583.86, -0.00, 1, 0xa1ae, 0x2000, 37, -9, 121, 255}, 
   { 3021.63, -1819.79, 39.37, 1, 0xb058, 0x0fca, 37, 9, 121, 255}, 
   { 2901.70, -1851.93, -0.00, 1, 0xb058, 0x2000, 37, 9, 121, 255}, 
};

