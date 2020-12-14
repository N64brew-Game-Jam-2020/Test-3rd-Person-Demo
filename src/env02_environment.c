#include "common.h"
#include "gbi.h"
#include "objectDefs.h"

Lights3 env_caveGround = gdSPDefLights3(  25, 30, 30, // amb col 
	0, 0, 0, // col 1  
	0,   -15,  90, // dir 1
	0, 0, 0, // col 1  
	0,   -15,  90, // dir 1
	0, 0, 0, // col 1  
	0,   -15,  90 // dir 1
	);  

	//PositionalLight cavePosLight;
	Vector3 values; 
PositionalLight cavePosLight = 
{  
	//70, 125, 135, // color of light
	//70, 125, 135, // color of light
	50.0f, 150.0f, 25.0f, // color of light
	0.0f, 0.0f, 50.0f, //light position
	0.01f,  0.75f // attenuation between 0 and 100%
}; 

Light cavePosLight_Ground;

	
#define THRESH1 0.01
#define THRESH2 0.3
void guPositionLight(PositionalLight *pl, Light *light,
                        float xOb, float yOb, float zOb)
{
        float x,y,z,d,a;
		float v0, v1, v2;


        x = pl->pos[0]-xOb;
        y = pl->pos[1]-yOb;
        z = pl->pos[2]-zOb;
        d = sqrtf(x*x + y*y + z*z);

        a = d*pl->a1 + pl->a2;
        if (a<THRESH1)
                a=100.0;
        else
		{
                a = 1/a;
				a += a;
		}

						//values.x = pl->col[0];
						//values.y = pl->col[1];
						//values.z = pl->col[2];
				
				
        if (d<THRESH1) {
                light->l.dir[0] = 0;
                light->l.dir[1] = 0;
                light->l.dir[2] = -120;

                light->l.col[0] = 0;
                light->l.col[1] = 0;
                light->l.col[2] = 0;
                light->l.colc[0] = 0;
                light->l.colc[1] = 0;
                light->l.colc[2] = 0;
        } else {
                d = 1/d;
				

				
                light->l.dir[0] = 120.0*x*d;
                light->l.dir[1] = 120.0*y*d;
                light->l.dir[2] = 120.0*z*d;
								
								
				
				if(pl->col[0]*a >= 255)
					light->l.col[0] = 255;
					else
						light->l.col[0] = pl->col[0]*a;
					
				if(pl->col[1]*a >= 255)
					light->l.col[1] = 255;
					else
						light->l.col[1] = pl->col[1]*a;	
				
				if(pl->col[2]*a >= 255)
					light->l.col[2] = 255;
					else
						light->l.col[2] = pl->col[2]*a;	
				
				
				//v0 = pl->col[0]*a;		
				//v1 = pl->col[1]*a;		
				//v2 = pl->col[2]*a;
								
				//light->l.col[0] = pl->col[0]*a;
                //light->l.col[1] = pl->col[1]*a;
                //light->l.col[2] = pl->col[2]*a;
				
				
				//if(light->l.colc[0] > 2)
								
                light->l.colc[0] = pl->col[0]*a;
                light->l.colc[1] = pl->col[1]*a;
                light->l.colc[2] = pl->col[2]*a;
				
				
				
				

        }		
		
		
		
		
		
			//values.x = cavePosLight.col[0];
			//values.y = cavePosLight.col[1];
			//values.z = cavePosLight.col[2];
			
			//values.x = light->l.col[0];
		//	values.y = light->l.col[1];
		//	values.z = light->l.col[2];

		
						//values.x = l->l.col[0];
						//values.y = l->l.col[1];
						//values.z = l->l.col[2];
		
		
}



//max 3518, 1885
//min 3388, -59

Vector2 positionRange;
Vector2 positionRangeB;
 
void guAreaPosLight(PositionalLight *pl, Light *light,
                        Vector2 min, Vector2 max, float strength)
{
	//see if light is inside x,y position range
	//
	if(pl->pos[0] >= min.x && pl->pos[0] <= max.x && pl->pos[1] >= min.y && pl->pos[1] <= max.y)
	{
		        light->l.col[0] = pl->col[0]*strength;
                light->l.col[1] = pl->col[1]*strength;
                light->l.col[2] = pl->col[2]*strength;
				light->l.colc[0] = pl->col[0]*strength;
                light->l.colc[1] = pl->col[1]*strength;
                light->l.colc[2] = pl->col[2]*strength;
				
				
				light->l.dir[0] = 1;
				light->l.dir[1] = 1;
	}
		//light->l.col[2]
		//light->l.col[2]

}
	
	
	
	
	
	 short maxOffsetC = 0x10;
	 short offsetC = 0x10;

	
	//Test Object = 0 
Vtx env02_segm_ceiling_wiring_VertList_0 [] = {
   { 556.32, 748.63, 73.87, 1, 0x12e7, 0x0a0d, 10, -4, -126, 255}, 
   { 603.00, 1363.82, 73.87, 1, 0x1fe5, 0x0a0d, 8, 0, -126, 255}, 
   { 663.85, 1371.66, 126.77, 1, 0x1fe5, 0x0048, 82, 7, -96, 255}, 
   { 496.40, 761.77, 126.77, 1, 0x12e7, 0x13d1, -79, 25, -95, 255}, 
   { 542.16, 1355.98, 126.77, 1, 0x1fe5, 0x13d1, -82, -6, -96, 255}, 
   { 377.85, 312.53, 127.95, 1, 0x08dd, 0x0048, 67, -49, -95, 255}, 
   { 66.63, -8.42, 127.95, 1, 0x0003, 0x0048, 59, -57, -96, 255}, 
   { 23.07, 34.78, 75.06, 1, 0x0003, 0x0a0d, 0, 0, -126, 255}, 
   { 321.46, 336.68, 75.06, 1, 0x08dd, 0x0a0d, 4, -5, -126, 255}, 
   { 616.25, 735.50, 126.77, 1, 0x12e7, 0x0048, 79, -23, -96, 255}, 
   { -20.49, 77.98, 127.95, 1, 0x0003, 0x13d1, -59, 58, -95, 255}, 
   { 265.06, 360.82, 127.95, 1, 0x08dd, 0x13d1, -66, 52, -94, 255}, 
   { 417.83, 2093.22, 73.87, 1, 0x2fe5, 0x0a0d, 3, 0, -126, 255}, 
   { 359.46, 2074.36, 126.77, 1, 0x2fe5, 0x13d1, -80, -20, -96, 255}, 
   { 317.29, 1879.29, 144.09, 1, 0x0fc9, 0x22e7, -68, -93, -50, 255}, 
   { 257.39, 2087.51, 144.09, 1, 0x1fc9, 0x22e7, -85, 89, -26, 255}, 
   { 343.26, 2112.22, -17.70, 1, 0x1fc9, 0x12e7, -70, 60, -86, 255}, 
   { 554.56, 2173.01, 144.09, 1, 0x1fc9, 0x22e7, 24, 121, -26, 255}, 
   { 468.68, 2148.30, -17.70, 1, 0x1fc9, 0x12e7, 27, 88, -86, 255}, 
   { 614.46, 1964.79, 144.09, 1, 0x1fc9, 0x22e7, 108, -43, -50, 255}, 
   { 528.59, 1940.08, -17.70, 1, 0x1fc9, 0x12e7, 70, -60, -86, 255}, 
   { 403.17, 1904.00, -17.70, 1, 0x1fc9, 0x12e7, -27, -88, -86, 255}, 
   { 425.52, 1072.84, 144.09, 1, 0x1fc9, 0x22e7, -83, 80, -50, 255}, 
   { 514.39, 1063.44, -17.70, 1, 0x1fc9, 0x12e7, -42, 82, -86, 255}, 
   { 491.60, 847.97, -17.70, 1, 0x0fc9, 0x12e7, -59, -71, -86, 255}, 
   { 733.03, 1040.32, 144.09, 1, 0x1fc9, 0x22e7, 98, 61, -50, 255}, 
   { 644.17, 1049.72, -17.70, 1, 0x1fc9, 0x12e7, 59, 71, -86, 255}, 
   { 710.25, 824.85, 144.09, 1, 0x1fc9, 0x22e7, 83, -80, -50, 255}, 
   { 621.38, 834.25, -17.70, 1, 0x1fc9, 0x12e7, 42, -82, -86, 255}, 
   { 402.74, 857.37, 144.09, 1, 0x1fc9, 0x22e7, -98, -61, -50, 255}, 
   { -232.56, -14.93, 144.09, 1, 0x0005, 0x22e7, -117, -37, -31, 255}, 
   { -79.99, 138.92, 144.09, 1, 0x0fc9, 0x22e7, -15, 115, -50, 255}, 
   { -16.54, 75.99, -17.70, 1, 0x0fc9, 0x12e7, 18, 90, -86, 255}, 
   { 139.58, -78.83, 144.09, 1, 0x1fc9, 0x22e7, 115, -14, -50, 255}, 
   { 76.13, -15.91, -17.70, 1, 0x1fc9, 0x12e7, 90, 18, -86, 255}, 
   { -12.99, -232.67, 144.09, 1, 0x2f8d, 0x22e7, -36, -117, -31, 255}, 
   { -76.44, -169.75, -17.70, 1, 0x2f8d, 0x12e7, -18, -90, -86, 255}, 
   { -169.11, -77.85, -17.70, 1, 0x3f8d, 0x12e7, -90, -18, -86, 255}, 
   { 259.76, 2079.25, 259.56, 1, 0x1fc9, 0x12e7, -35, 121, 9, 255}, 
   { 556.94, 2164.75, 259.56, 1, 0x0fc9, 0x12e7, -35, 121, 9, 255}, 
   { -12.99, -232.67, 261.95, 1, 0x2f8d, 0x2d1b, -89, -90, 0, 255}, 
   { -232.56, -14.93, 261.95, 1, 0x3f8d, 0x2d1b, -89, -90, 0, 255}, 
   { 476.21, 2112.08, 126.77, 1, 0x2fe5, 0x0048, 80, 20, -96, 255}, 
   { 663.85, 1371.66, 126.77, 1, 0x1fe5, 0x0048, 82, 7, -96, 255}, 
   { 417.83, 2093.22, 73.87, 1, 0x2fe5, 0x0a0d, 3, 0, -126, 255}, 
   { 417.83, 2093.22, 73.87, 1, 0x2fe5, 0x0a0d, 3, 0, -126, 255}, 
   { 603.00, 1363.82, 73.87, 1, 0x1fe5, 0x0a0d, 8, 0, -126, 255}, 
   { 359.46, 2074.36, 126.77, 1, 0x2fe5, 0x13d1, -80, -20, -96, 255}, 
};

//Test Object = 1 
Vtx_tn env02_segm_water01_VertList_0 [] = {
   { -881.52, -848.90, -2.36, 1, 0x0344, 0x5912, 0, 0, 127, 255}, 
   { -814.71, -905.73, -2.36, 1, 0x0bb8, 0x5912, 0, 0, 127, 255}, 
   { -556.65, -667.16, -2.36, 1, 0x0bb8, 0x4bd0, 0, 0, 126, 255}, 
   { -1074.43, -1142.66, -2.36, 1, 0x0bb8, 0x6650, 0, 0, 126, 255}, 
   { -1144.11, -1092.87, -2.36, 1, 0x0344, 0x6650, 0, 0, 126, 255}, 
   { -1475.10, -1626.86, -4.83, 1, 0x0344, 0x7d13, 0, 0, 126, 255}, 
   { -444.70, -244.28, -2.67, 1, 0x0344, 0x3ca3, 0, 0, 126, 255}, 
   { -616.71, -606.03, -2.36, 1, 0x0344, 0x4bd0, 0, 0, 127, 255}, 
   { -424.60, -68.12, -3.09, 1, 0x0344, 0x351c, 0, 0, 126, 255}, 
   { -373.31, -296.98, -2.67, 1, 0x0bb8, 0x3ca3, 0, 0, 126, 255}, 
   { -334.07, -74.05, -3.10, 1, 0x0bb8, 0x351c, 0, 0, 126, 255}, 
   { -320.91, 135.09, -3.52, 1, 0x0bb8, 0x2d65, 0, 0, 126, 255}, 
   { -374.76, 439.64, -3.51, 1, 0x0bb8, 0x21e8, 0, 0, 127, 255}, 
   { -445.61, 438.27, -3.50, 1, 0x0344, 0x21e8, 0, 0, 127, 255}, 
   { -592.38, 1332.49, -3.51, 1, 0x0bb8, 0x0005, 0, 0, 127, 255}, 
   { -669.76, 1307.87, -3.50, 1, 0x0344, 0x0005, 0, 0, 127, 255}, 
   { -1410.63, -1630.28, -4.83, 1, 0x0bb8, 0x7d13, 0, 0, 126, 255}, 
   { -402.03, 134.75, -3.51, 1, 0x0344, 0x2d65, 0, 0, 126, 255}, 
   { -402.03, 134.75, -3.51, 1, 0x0328, 0x3318, 0, 0, 126, 255}, 
};

//Test Object = 1 
Vtx_tn env02_segm_anim_water01_VertList_0 [] = {
   { -881.52, -848.90, -2.36, 1, 0x0344, 0x5912, 0, 0, 127, 255}, 
   { -814.71, -905.73, -2.36, 1, 0x0bb8, 0x5912, 0, 0, 127, 255}, 
   { -556.65, -667.16, -2.36, 1, 0x0bb8, 0x4bd0, 0, 0, 126, 255}, 
   { -1074.43, -1142.66, -2.36, 1, 0x0bb8, 0x6650, 0, 0, 126, 255}, 
   { -1144.11, -1092.87, -2.36, 1, 0x0344, 0x6650, 0, 0, 126, 255}, 
   { -1475.10, -1626.86, -4.83, 1, 0x0344, 0x7d13, 0, 0, 126, 255}, 
   { -444.70, -244.28, -2.67, 1, 0x0344, 0x3ca3, 0, 0, 126, 255}, 
   { -616.71, -606.03, -2.36, 1, 0x0344, 0x4bd0, 0, 0, 127, 255}, 
   { -424.60, -68.12, -3.09, 1, 0x0344, 0x351c, 0, 0, 126, 255}, 
   { -373.31, -296.98, -2.67, 1, 0x0bb8, 0x3ca3, 0, 0, 126, 255}, 
   { -334.07, -74.05, -3.10, 1, 0x0bb8, 0x351c, 0, 0, 126, 255}, 
   { -320.91, 135.09, -3.52, 1, 0x0bb8, 0x2d65, 0, 0, 126, 255}, 
   { -374.76, 439.64, -3.51, 1, 0x0bb8, 0x21e8, 0, 0, 127, 255}, 
   { -445.61, 438.27, -3.50, 1, 0x0344, 0x21e8, 0, 0, 127, 255}, 
   { -592.38, 1332.49, -3.51, 1, 0x0bb8, 0x0005, 0, 0, 127, 255}, 
   { -669.76, 1307.87, -3.50, 1, 0x0344, 0x0005, 0, 0, 127, 255}, 
   { -1410.63, -1630.28, -4.83, 1, 0x0bb8, 0x7d13, 0, 0, 126, 255}, 
   { -402.03, 134.75, -3.51, 1, 0x0344, 0x2d65, 0, 0, 126, 255}, 
   { -402.03, 134.75, -3.51, 1, 0x0328, 0x3318, 0, 0, 126, 255}, 
};


//Test Object = 2 
Vtx env02_segm_ground01_VertList_0 [] = {
   { -478.69, 447.09, 3.97, 1, 0x265d, 0x2494, 30, 6, 123, 255}, 
   { -699.83, 1298.90, 3.97, 1, 0x0e9b, 0x167b, 30, 7, 123, 255}, 
   { -1293.18, 1114.47, 3.97, 1, 0x0574, 0x27b5, 0, 0, 127, 255}, 
   { -338.11, 489.62, 3.97, 1, 0x288e, 0x2086, -26, -5, 124, 255}, 
   { -219.69, 527.60, 3.97, 1, 0x2a5b, 0x1d0f, 0, 0, 127, 255}, 
   { -440.83, 1379.41, 3.97, 1, 0x1299, 0x0ef5, 0, 0, 127, 255}, 
   { -412.38, 467.70, -32.44, 1, 0x1780, 0x0005, 0, 0, 126, 255}, 
   { -559.24, 1341.43, 3.97, 1, 0x0008, 0x108b, -26, -6, 124, 255}, 
   { -633.51, 1319.51, -32.44, 1, 0x0011, 0x0005, 1, 0, 126, 255}, 
   { -83.42, 569.96, 3.97, 1, 0x2c75, 0x191a, 0, 0, 127, 255}, 
   { -22.18, 1509.53, 3.97, 1, 0x190d, 0x02ce, 0, 0, 127, 255}, 
   { -1385.27, -843.70, 3.97, 1, 0x2eb0, 0x5564, 0, 0, 127, 255}, 
   { -1722.91, -1347.36, 3.97, 1, 0x324c, 0x6815, 0, 0, 127, 255}, 
   { -1495.96, -1606.57, 3.97, 1, 0x3d16, 0x68d8, 31, -20, 121, 255}, 
   { -832.43, -1326.90, 3.97, 1, 0x45b1, 0x53f1, 0, 0, 127, 255}, 
   { -946.42, -1241.04, 3.97, 1, 0x4141, 0x548c, 0, 0, 126, 255}, 
   { -1256.24, -1705.06, 3.97, 1, 0x449b, 0x65bd, 0, 0, 127, 255}, 
   { -1053.51, -1163.80, 3.97, 1, 0x4a02, 0x108b, -24, 21, 122, 255}, 
   { -1107.60, -1119.65, -32.44, 1, 0x4a0b, 0x0005, 2, -1, 126, 255}, 
   { -1442.88, -1628.38, -32.44, 1, 0x5a0b, 0x0005, 7, -4, 126, 255}, 
   { -1389.71, -1651.43, 3.97, 1, 0x4072, 0x677e, -33, 22, 120, 255}, 
   { -1167.18, -1071.49, 3.97, 1, 0x4a02, 0x108b, 19, -16, 124, 255}, 
   { -163.16, 141.33, 3.97, 1, 0x3428, 0x246b, 0, 0, 126, 255}, 
   { -20.46, 140.93, 3.97, 1, 0x3758, 0x2146, 0, 0, 126, 255}, 
   { -434.38, 142.08, 3.97, 1, 0x208d, 0x108b, 32, 0, 122, 255}, 
   { -364.94, 141.89, -32.44, 1, 0x2095, 0x0005, -1, 0, 126, 255}, 
   { -287.51, 140.56, 3.97, 1, 0x208d, 0x108b, -25, 0, 124, 255}, 
   { -760.04, 142.98, 3.97, 1, 0x26d0, 0x3193, 0, 0, 127, 255}, 
   { -478.69, 447.09, 3.97, 1, 0x265d, 0x2494, 30, 6, 123, 255}, 
   { -637.57, -585.74, 3.97, 1, 0x39a7, 0x3f1d, 27, -19, 122, 255}, 
   { -868.80, -356.42, 3.97, 1, 0x2f6e, 0x3f1d, 0, 0, 127, 255}, 
   { -343.67, -877.21, 3.97, 1, 0x46a6, 0x3f1d, 0, 0, 127, 255}, 
   { -444.99, -776.72, 3.97, 1, 0x422b, 0x3f1d, 0, 0, 126, 255}, 
   { -534.07, -689.95, 3.97, 1, 0x372f, 0x108b, -19, 15, 124, 255}, 
   { -588.26, -634.64, -32.44, 1, 0x3738, 0x0005, -4, 1, 126, 255}, 
   { -232.01, -364.43, 3.97, 1, 0x3dcd, 0x3137, 0, 0, 126, 255}, 
   { -468.74, -232.08, 3.97, 1, 0x3599, 0x337f, 33, -8, 122, 255}, 
   { -341.09, -304.72, 3.97, 1, 0x2bfc, 0x108b, -23, 7, 124, 255}, 
   { -408.13, -265.96, -32.44, 1, 0x2c04, 0x0005, -4, 0, 126, 255}, 
   { -107.45, -434.06, 3.97, 1, 0x421e, 0x3003, 0, 0, 127, 255}, 
   { -753.00, -73.16, 3.97, 1, 0x2bc0, 0x363d, 0, 0, 127, 255}, 
   { -789.67, 350.43, 3.97, 1, 0x2191, 0x2d9b, 0, 0, 127, 255}, 
   { -1293.18, 1114.47, 3.97, 1, 0x0574, 0x27b5, 0, 0, 127, 255}, 
   { -699.83, 1298.90, 3.97, 1, 0x0008, 0x108b, 30, 7, 123, 255}, 
   { -478.69, 447.09, 3.97, 1, 0x1778, 0x108b, 30, 6, 123, 255}, 
   { -633.51, 1319.51, -32.44, 1, 0x0011, 0x0005, 1, 0, 126, 255}, 
   { -1124.24, -1759.29, 3.97, 1, 0x48bf, 0x6408, 0, 0, 127, 255}, 
   { -832.43, -1326.90, 3.97, 1, 0x45b1, 0x53f1, 0, 0, 127, 255}, 
   { -1256.24, -1705.06, 3.97, 1, 0x449b, 0x65bd, 0, 0, 127, 255}, 
   { -1256.24, -1705.06, 3.97, 1, 0x449b, 0x65bd, 0, 0, 127, 255}, 
   { -946.42, -1241.04, 3.97, 1, 0x4141, 0x548c, 0, 0, 126, 255}, 
   { -1389.71, -1651.43, 3.97, 1, 0x4072, 0x677e, -33, 22, 120, 255}, 
   { -478.69, 447.09, 3.97, 1, 0x1778, 0x108b, 30, 6, 123, 255}, 
   { -434.38, 142.08, 3.97, 1, 0x208d, 0x108b, 32, 0, 122, 255}, 
   { -412.38, 467.70, -32.44, 1, 0x1780, 0x0005, 0, 0, 126, 255}, 
   { -364.94, 141.89, -32.44, 1, 0x2095, 0x0005, -1, 0, 126, 255}, 
   { -287.51, 140.56, 3.97, 1, 0x208d, 0x108b, -25, 0, 124, 255}, 
   { -412.38, 467.70, -32.44, 1, 0x1780, 0x0005, 0, 0, 126, 255}, 
   { -789.67, 350.43, 3.97, 1, 0x2191, 0x2d9b, 0, 0, 127, 255}, 
   { -760.04, 142.98, 3.97, 1, 0x26d0, 0x3193, 0, 0, 127, 255}, 
   { -478.69, 447.09, 3.97, 1, 0x265d, 0x2494, 30, 6, 123, 255}, 
   { -338.11, 489.62, 3.97, 1, 0x288e, 0x2086, -26, -5, 124, 255}, 
   { -287.51, 140.56, 3.97, 1, 0x3166, 0x272f, -25, 0, 124, 255}, 
   { -219.69, 527.60, 3.97, 1, 0x2a5b, 0x1d0f, 0, 0, 127, 255}, 
   { -946.42, -1241.04, 3.97, 1, 0x4141, 0x548c, 0, 0, 126, 255}, 
   { -444.99, -776.72, 3.97, 1, 0x422b, 0x3f1d, 0, 0, 126, 255}, 
   { -1053.51, -1163.80, 3.97, 1, 0x3d29, 0x5531, -24, 21, 122, 255}, 
   { -341.09, -304.72, 3.97, 1, 0x3a0d, 0x324b, -23, 7, 124, 255}, 
   { -232.01, -364.43, 3.97, 1, 0x3dcd, 0x3137, 0, 0, 126, 255}, 
   { -287.51, 140.56, 3.97, 1, 0x3166, 0x272f, -25, 0, 124, 255}, 
   { -408.13, -265.96, -32.44, 1, 0x2c04, 0x0005, -4, 0, 126, 255}, 
   { -468.74, -232.08, 3.97, 1, 0x2bfc, 0x108b, 33, -8, 122, 255}, 
   { -232.01, -364.43, 3.97, 1, 0x3dcd, 0x3137, 0, 0, 126, 255}, 
   { -107.45, -434.06, 3.97, 1, 0x421e, 0x3003, 0, 0, 127, 255}, 
   { -163.16, 141.33, 3.97, 1, 0x3428, 0x246b, 0, 0, 126, 255}, 
   { -534.07, -689.95, 3.97, 1, 0x3e43, 0x3f26, -19, 15, 124, 255}, 
   { -637.57, -585.74, 3.97, 1, 0x372f, 0x108b, 27, -19, 122, 255}, 
   { -588.26, -634.64, -32.44, 1, 0x3738, 0x0005, -4, 1, 126, 255}, 
   { -468.74, -232.08, 3.97, 1, 0x2bfc, 0x108b, 33, -8, 122, 255}, 
   { -343.67, -877.21, 3.97, 1, 0x46a6, 0x3f1d, 0, 0, 127, 255}, 
};

//Test Object = 3 
Vtx env02_segm_walls01_VertList_0 [] = {
   { -1292.80, -1177.14, 16.86, 1, 0x0577, 0x0892, 105, -60, 35, 255}, 
   { -1327.98, -1194.33, 85.55, 1, 0x06ac, 0x0848, 108, -53, 39, 255}, 
   { -1434.24, -1531.73, 76.28, 1, 0x04da, 0x006b, 77, 92, 39, 255}, 
   { -1556.11, -1275.10, 582.83, 1, 0x0d59, 0x07ee, 118, -37, -27, 255}, 
   { -1579.67, -1573.77, 562.30, 1, 0x0dad, 0x012d, 99, 75, -24, 255}, 
   { -1102.57, -1386.18, 7.20, 1, 0x05b7, 0x08ac, -61, 105, 36, 255}, 
   { -1414.87, -1498.87, -30.70, 1, 0x03aa, 0x008f, 89, 80, 40, 255}, 
   { -1119.02, -1420.58, 76.17, 1, 0x06b5, 0x0852, -51, 109, 38, 255}, 
   { -759.09, -450.19, 56.39, 1, 0x15c0, 0x2016, 109, -55, 31, 255}, 
   { -898.54, -442.27, 568.03, 1, 0x15c0, 0x1016, 107, -57, -33, 255}, 
   { -383.54, -849.12, -2.75, 1, 0x2b0c, 0x0fbf, -99, 73, 27, 255}, 
   { -372.41, -856.62, 58.07, 1, 0x2b38, 0x1008, -98, 73, 31, 255}, 
   { -1177.27, -1662.37, 569.15, 1, 0x3eee, 0x0008, -22, 121, -27, 255}, 
   { -742.51, -448.14, 2.17, 1, 0x0b3f, 0x1008, 111, -52, 32, 255}, 
   { -622.78, 44.52, 56.39, 1, 0x20db, 0x2016, 121, -5, 35, 255}, 
   { -124.05, -146.84, 62.64, 1, 0x1d6e, 0x0b6c, -121, 17, 31, 255}, 
   { -135.18, -139.33, 1.82, 1, 0x1d82, 0x1008, -123, 15, 24, 255}, 
   { -606.21, 46.58, 2.17, 1, 0x0b3f, 0x1008, 121, -4, 36, 255}, 
   { -217.86, -882.54, 557.81, 1, 0x2b38, 0x0008, -100, 69, -33, 255}, 
   { 30.50, -172.75, 557.81, 1, 0x1d94, 0x0008, -121, 18, -30, 255}, 
   { -687.13, 492.39, 2.17, 1, 0x150e, 0x1008, 112, 47, 36, 255}, 
   { -703.70, 490.34, 56.39, 1, 0x14f9, 0x0b6c, 112, 48, 33, 255}, 
   { -10.76, 562.87, 557.81, 1, 0x1036, 0x0008, -121, -4, -35, 255}, 
   { -165.31, 588.78, 62.64, 1, 0x1036, 0x1008, -123, -1, 30, 255}, 
   { -843.16, 498.26, 568.03, 1, 0x2aaa, 0x1016, 110, 49, -38, 255}, 
   { -176.44, 596.29, 1.82, 1, 0x1024, 0x1008, -124, 0, 22, 255}, 
   { -1127.27, 1086.36, 2.17, 1, 0x250e, 0x1008, 98, 73, 32, 255}, 
   { -1143.84, 1084.30, 56.39, 1, 0x24f9, 0x0b6c, 99, 73, 29, 255}, 
   { 25.11, 1444.01, 557.81, 1, 0x0036, 0x0008, -121, 4, -35, 255}, 
   { -129.44, 1469.92, 62.64, 1, 0x0036, 0x1008, -123, 5, 30, 255}, 
   { -1283.30, 1092.23, 568.03, 1, 0x3aaa, 0x1016, 100, 64, -44, 255}, 
   { -140.57, 1477.43, 1.82, 1, 0x0024, 0x1008, -124, 5, 23, 255}, 
   { -1556.11, -1275.10, 582.83, 1, 0x0013, 0x0b28, 118, -37, -27, 255}, 
   { -532.41, -526.47, 956.15, 1, 0x1024, 0x0008, -5, 6, -126, 255}, 
   { -898.54, -442.27, 568.03, 1, 0x0013, 0x0b28, 107, -57, -33, 255}, 
   { -762.24, 52.45, 568.03, 1, 0x1013, 0x0b28, 121, -5, -35, 255}, 
   { -368.95, 38.94, 956.15, 1, 0x1024, 0x0008, -11, 0, -126, 255}, 
   { -599.44, 1317.59, 956.15, 1, 0x1024, 0x0008, -11, 4, -126, 255}, 
   { -436.62, 600.49, 956.15, 1, 0x0024, 0x0008, -10, 4, -126, 255}, 
   { -1177.27, -1662.37, 569.15, 1, 0x3017, 0x0b2f, -22, 121, -27, 255}, 
   { -1149.57, -1172.87, 943.00, 1, 0x3028, 0x000f, 20, 8, -125, 255}, 
   { -1579.67, -1573.77, 562.30, 1, 0x008d, 0x0499, 99, 75, -24, 255}, 
   { -1434.24, -1531.73, 76.28, 1, 0x04da, 0x006b, 77, 92, 39, 255}, 
   { -1327.98, -1194.33, 85.55, 1, 0x06ac, 0x0848, 108, -53, 39, 255}, 
   { -1579.67, -1573.77, 562.30, 1, 0x0dad, 0x012d, 99, 75, -24, 255}, 
   { -1119.02, -1420.58, 76.17, 1, 0x06b5, 0x0852, -51, 109, 38, 255}, 
   { -1102.57, -1386.18, 7.20, 1, 0x05b7, 0x08ac, -61, 105, 36, 255}, 
   { -1434.24, -1531.73, 76.28, 1, 0x04da, 0x006b, 77, 92, 39, 255}, 
   { -759.09, -450.19, 56.39, 1, 0x15c0, 0x2016, 109, -55, 31, 255}, 
   { -372.41, -856.62, 58.07, 1, 0x2b13, 0x0b6c, -98, 73, 31, 255}, 
   { -383.54, -849.12, -2.75, 1, 0x2b0c, 0x0fbf, -99, 73, 27, 255}, 
   { -1119.02, -1420.58, 76.17, 1, 0x4087, 0x0b66, -51, 109, 38, 255}, 
   { -217.86, -882.54, 557.81, 1, 0x2b38, 0x0008, -100, 69, -33, 255}, 
   { -1292.80, -1177.14, 16.86, 1, 0x204c, 0x100f, 105, -60, 35, 255}, 
   { -742.51, -448.14, 2.17, 1, 0x0b3f, 0x1008, 111, -52, 32, 255}, 
   { -1327.98, -1194.33, 85.55, 1, 0x201d, 0x0b74, 108, -53, 39, 255}, 
   { -135.18, -139.33, 1.82, 1, 0x1d82, 0x1008, -123, 15, 24, 255}, 
   { -622.78, 44.52, 56.39, 1, 0x0b2b, 0x0b6c, 121, -5, 35, 255}, 
   { -759.09, -450.19, 56.39, 1, 0x0010, 0x0b6c, 109, -55, 31, 255}, 
   { -606.21, 46.58, 2.17, 1, 0x0b3f, 0x1008, 121, -4, 36, 255}, 
   { -124.05, -146.84, 62.64, 1, 0x1d94, 0x1008, -121, 17, 31, 255}, 
   { -372.41, -856.62, 58.07, 1, 0x2b38, 0x1008, -98, 73, 31, 255}, 
   { 30.50, -172.75, 557.81, 1, 0x1d94, 0x0008, -121, 18, -30, 255}, 
   { -703.70, 490.34, 56.39, 1, 0x14f9, 0x0b6c, 112, 48, 33, 255}, 
   { -165.31, 588.78, 62.64, 1, 0x1036, 0x1008, -123, -1, 30, 255}, 
   { -762.24, 52.45, 568.03, 1, 0x20db, 0x1016, 121, -5, -35, 255}, 
   { -622.78, 44.52, 56.39, 1, 0x20db, 0x2016, 121, -5, 35, 255}, 
   { -843.16, 498.26, 568.03, 1, 0x2aaa, 0x1016, 110, 49, -38, 255}, 
   { -176.44, 596.29, 1.82, 1, 0x1024, 0x1008, -124, 0, 22, 255}, 
   { -703.70, 490.34, 56.39, 1, 0x14f9, 0x0b6c, 112, 48, 33, 255}, 
   { -687.13, 492.39, 2.17, 1, 0x150e, 0x1008, 112, 47, 36, 255}, 
   { -1143.84, 1084.30, 56.39, 1, 0x24f9, 0x0b6c, 99, 73, 29, 255}, 
   { -165.31, 588.78, 62.64, 1, 0x1036, 0x1008, -123, -1, 30, 255}, 
   { -10.76, 562.87, 557.81, 1, 0x1036, 0x0008, -121, -4, -35, 255}, 
   { -129.44, 1469.92, 62.64, 1, 0x0036, 0x1008, -123, 5, 30, 255}, 
   { -1283.30, 1092.23, 568.03, 1, 0x3aaa, 0x1016, 100, 64, -44, 255}, 
   { -140.57, 1477.43, 1.82, 1, 0x0024, 0x1008, -124, 5, 23, 255}, 
   { -436.62, 600.49, 956.15, 1, 0x0024, 0x0008, -10, 4, -126, 255}, 
   { -368.95, 38.94, 956.15, 1, 0x0024, 0x0008, -11, 0, -126, 255}, 
   { -217.86, -882.54, 557.81, 1, 0x2017, 0x0b2f, -100, 69, -33, 255}, 
   { 25.11, 1444.01, 557.81, 1, 0x0017, 0x0b2f, -121, 4, -35, 255}, 
   { -10.76, 562.87, 557.81, 1, 0x0c3d, 0x0b2f, -121, -4, -35, 255}, 
   { -599.44, 1317.59, 956.15, 1, 0x0028, 0x000f, -11, 4, -126, 255}, 
};



 void env02_segm_ceiling_wiring_PolyList(u8 animFrame) 
 { 

   Vtx *env02_segm_ceiling_wiring_VTXPointer = &env02_segm_ceiling_wiring_VertList_0[0]; 

   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 0 'env02_cave_ceiling_light'OK 

  // TEXTURE_4B_TLUT(glistp, env02_cave_ceiling_light, env02_cave_ceiling_light_tlut, 6,1);

   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,14, 15, 16, 14); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0fc922e7);
   gSP1Triangle(glistp++,15, 17, 18, 15); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x0fc922e7);
   gSP1Triangle(glistp++,17, 19, 20, 17); 
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x0fc922e7);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x1fc922e7);
   gSP1Triangle(glistp++,19, 14, 21, 19); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0fc922e7);           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x1fc922e7);
   gSP1Triangle(glistp++,21, 16, 18, 21); 
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+23,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x0fc912e7);
   gSP1Triangle(glistp++,2, 3, 0, 2); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0fc912e7);
   gSP1Triangle(glistp++,4, 5, 3, 4); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x1fc912e7);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0fc912e7);
   gSP1Triangle(glistp++,6, 1, 5, 6); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x1fc922e7);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x1fc912e7);
   gSP1Triangle(glistp++,0, 3, 5, 0); 
   gSP1Triangle(glistp++,7, 8, 9, 7); 
   gSP1Triangle(glistp++,10, 11, 9, 10); 
   gSP1Triangle(glistp++,12, 13, 11, 12); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x3f8d22e7);
   gSP1Triangle(glistp++,7, 14, 13, 7); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0fc90025);
   gSP1Triangle(glistp++,14, 9, 11, 14); 
   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+15,26,0);
   gSP1Triangle(glistp++,0, 23, 24, 0); 
   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+35,26,0);
   gSP1Triangle(glistp++,0, 5, 6, 0); 
   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+14,26,0);
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0fc912e7);
   gSP1Triangle(glistp++,7, 0, 2, 7); 
           gSPModifyVertex(glistp++, 2,   G_MWO_POINT_ST, 0x0fc912e7);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x0fc922e7);
   gSP1Triangle(glistp++,2, 1, 4, 2); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x0fc912e7);           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x0fc922e7);
   gSP1Triangle(glistp++,4, 3, 6, 4); 
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x0fc912e7);           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x0fc922e7);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x1fc912e7);
   gSP1Triangle(glistp++,6, 5, 7, 6); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x0fc922e7);           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x1fc912e7);
   gSP1Triangle(glistp++,6, 7, 4, 6); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0fc922e7);
   gSP1Triangle(glistp++,15, 8, 10, 15); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0fc922e7);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x0fc912e7);
   gSP1Triangle(glistp++,8, 11, 9, 8); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x0fc922e7);           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x0fc912e7);
   gSP1Triangle(glistp++,11, 13, 12, 11); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x0fc922e7);           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x1fc922e7);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0fc912e7);
   gSP1Triangle(glistp++,13, 15, 14, 13); 
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x0fc922e7);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x1fc922e7);
   gSP1Triangle(glistp++,10, 9, 14, 10); 
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x000512e7);
   gSP1Triangle(glistp++,23, 16, 18, 23); 
   gSP1Triangle(glistp++,17, 19, 18, 17); 
   gSP1Triangle(glistp++,19, 21, 20, 19); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x3f8d22e7);
   gSP1Triangle(glistp++,21, 16, 22, 21); 
           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x1fc90025);           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x0fc90025);
   gSP1Triangle(glistp++,22, 23, 20, 22); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x1fc922e7);
   gSP1Triangle(glistp++,3, 1, 25, 3); 
   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+30,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x3f8d22e7);
   gSP1Triangle(glistp++,0, 5, 11, 0); 


//OBJECT: 0 MATERIAL NO. 1 'env02_cave_ceiling_wiring'OK 

 //  TEXTURE_4B_TLUT(glistp, env02_cave_ceiling_wiring, env02_cave_ceiling_wiring_tlut, 6,1);

   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 1, 3); 
   gSP1Triangle(glistp++,5, 6, 7, 5); 
   gSP1Triangle(glistp++,8, 0, 9, 8); 
   gSP1Triangle(glistp++,10, 11, 8, 10); 
   gSP1Triangle(glistp++,11, 3, 0, 11); 
   gSP1Triangle(glistp++,2, 1, 12, 2); 
   gSP1Triangle(glistp++,1, 4, 13, 1); 
   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,9, 0, 2, 9); 
   gSP1Triangle(glistp++,0, 3, 1, 0); 
   gSP1Triangle(glistp++,8, 5, 7, 8); 
   gSP1Triangle(glistp++,5, 8, 9, 5); 
   gSP1Triangle(glistp++,7, 10, 8, 7); 
   gSP1Triangle(glistp++,8, 11, 0, 8); 
   gSPVertex(glistp++,env02_segm_ceiling_wiring_VTXPointer+25,26,0);
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSP1Triangle(glistp++,20, 21, 22, 20); 

   gDPPipeSync(glistp++);

 } 
 
 void env02_segm_water01_PolyList(u8 animFrame) 
 { 
	int loopCounter;
	int animSpeed = 1;
   Vtx_tn *env02_segm_water01_VTXPointer = &env02_segm_anim_water01_VertList_0[0]; 

   gSPVertex(glistp++,env02_segm_water01_VTXPointer+0,26,0);

//OBJECT: 0 MATERIAL NO. 0 'env02_cave_river_dark'OK 

	if(maxOffsetC >= 4096)
	{
		for(loopCounter = 0; loopCounter < 19; loopCounter++)
			env02_segm_anim_water01_VertList_0[loopCounter].tc[1] = env02_segm_water01_VertList_0[loopCounter].tc[1];
		
		maxOffsetC = 0x10;
	}
	
	for(loopCounter = 0; loopCounter < 19; loopCounter++)
	{
		env02_segm_water01_VTXPointer[loopCounter].tc[1] += (offsetC*animSpeed);
	
	}
	maxOffsetC += offsetC;


   TEXTURE_4B_TLUT_TRANSP(glistp, env02_cave_river_dark, env02_cave_river_dark_tlut, 6,1);
   gDPSetPrimColor(glistp++, 0, 255, 255, 255, 255, 175);
   gSPVertex(glistp++,env02_segm_water01_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,4, 3, 1, 4); 
   gSP1Triangle(glistp++,6, 7, 2, 6); 
   gSP1Triangle(glistp++,8, 6, 9, 8); 
   gSP1Triangle(glistp++,8, 10, 11, 8); 
   gSP1Triangle(glistp++,11, 12, 13, 11); 
   gSP1Triangle(glistp++,12, 14, 15, 12); 
   gSP1Triangle(glistp++,7, 0, 2, 7); 
   gSP1Triangle(glistp++,16, 3, 5, 16); 
   gSP1Triangle(glistp++,0, 4, 1, 0); 
   gSP1Triangle(glistp++,9, 6, 2, 9); 
   gSP1Triangle(glistp++,10, 8, 9, 10); 
   gSP1Triangle(glistp++,17, 8, 11, 17); 
   gSP1Triangle(glistp++,17, 11, 13, 17); 
   gSP1Triangle(glistp++,13, 12, 15, 13); 

   gDPPipeSync(glistp++);

 } 
 
 
 
 void debug()
 {
	//if(ContTriger[0].button & D_CBUTTONS)
	
	if(nuContData[0].button & U_JPAD)
	{
		cavePosLight.a2 += 0.01f;
		//cavePosLight.a2 = 1.0f;
	
	
		////playerVelocity.y = 50;
		//playerRotate = 180;
	}
	
	if(nuContData[0].button & D_JPAD)
	{
		cavePosLight.a2 -= 0.01f;
	//	playerVelocity.y = -50;
		//playerRotate = 0;
	}
	
	
 }
 
 
 void env02_segm_ground01_PolyList(u8 animFrame) 
 { 

   Vtx *env02_segm_ground01_VTXPointer = &env02_segm_ground01_VertList_0[0]; 

   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+0,26,0);

//OBJECT: 2 MATERIAL NO. 0 'env02_cave_ground_riverbed'OK 

   TEXTURE_4B_TLUT(glistp, env02_cave_ground_riverbed, env02_cave_ground_riverbed_tlut, 6,1);
  // gSPSetLights1(glistp++, env_caveGround);

  //gSPSetLights1(glistp++, env_caveGround);  
	cavePosLight.col[0] = 5.0f;
		cavePosLight.col[1] = 200.0f;
			cavePosLight.col[2] = 225.0f;
						
	cavePosLight.pos[0] = playerAvatar.obj.pos.x;
		cavePosLight.pos[1] = playerAvatar.obj.pos.y;
			cavePosLight.pos[2] = playerAvatar.obj.pos.z+10.0f;		
												
	//cavePosLight.a1 = 0.01f;
	//cavePosLight.a2 = 1.0f;
	
	positionRange.x = 3000;
		positionRange.y = 1885;	
		
	positionRangeB.x = 2100;
		positionRangeB.y = -59;	
//max 3518, 1885
//min 3388, -59
	
	 debug();

   guPositionLight(&cavePosLight, &cavePosLight_Ground, 2650, 1516, -1.0 );
	//guAreaPosLight(&cavePosLight, &cavePosLight_Ground, positionRangeB, positionRange, 1.0);
      
	env_caveGround.l[0].l = cavePosLight_Ground.l;
	env_caveGround.l[1].l = cavePosLight_Ground.l;
		env_caveGround.l[1].l.dir[0] *= -1;
		env_caveGround.l[1].l.dir[1] *= -1;
	env_caveGround.l[2].l = cavePosLight_Ground.l;
		env_caveGround.l[2].l.dir[0] = 0;
		env_caveGround.l[2].l.dir[1] = 0;
		env_caveGround.l[2].l.dir[2] *= -1.25;

		
		//check debug values:
		/*
			values.x = playerAvatar.obj.pos.y;
			values.y = env_caveGround.l[0].l.col[1];
			values.z = env_caveGround.l[0].l.col[2];
		*/
			
    gSPSetLights3(glistp++, env_caveGround);  
	

   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x1778108b);
   gSP1Triangle(glistp++,6, 3, 7, 6); 
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x1778108b);
   gSP1Triangle(glistp++,0, 6, 8, 0); 
   gSP1Triangle(glistp++,17, 18, 19, 17); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x5a02108b);
   gSP1Triangle(glistp++,18, 21, 13, 18); 
   gSP1Triangle(glistp++,24, 25, 6, 24); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+3,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x1778108b);
   gSP1Triangle(glistp++,23, 0, 3, 23); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+11,26,0);
   gSP1Triangle(glistp++,22, 23, 7, 22); 
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x372f108b);
   gSP1Triangle(glistp++,23, 18, 10, 23); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+25,26,0);
   gSP1Triangle(glistp++,12, 1, 0, 12); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+24,26,0);
   gSP1Triangle(glistp++,14, 1, 0, 14); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+22,26,0);
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x2bfc108b);
   gSP1Triangle(glistp++,12, 16, 14, 12); 
   gSP1Triangle(glistp++,11, 15, 16, 11); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+3,26,0);
   gSP1Triangle(glistp++,5, 3, 4, 5); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+28,26,0);
   gSP1Triangle(glistp++,15, 16, 17, 15); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+17,26,0);
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x5a02108b);
   gSP1Triangle(glistp++,3, 0, 2, 3); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+13,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x5a02108b);
   gSP1Triangle(glistp++,6, 5, 0, 6); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+29,26,0);
   gSP1Triangle(glistp++,23, 24, 25, 23); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+54,26,0);
   gSP1Triangle(glistp++,1, 2, 3, 1); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+17,26,0);
   gSP1Triangle(glistp++,0, 16, 1, 0); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+18,26,0);
   gSP1Triangle(glistp++,0, 16, 3, 0); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+55,26,0);
           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x2bfc108b);
   gSP1Triangle(glistp++,15, 12, 0, 15); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+53,26,0);
   gSP1Triangle(glistp++,18, 17, 0, 18); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+54,26,0);
   gSP1Triangle(glistp++,22, 23, 24, 22); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x372f108b);
   gSP1Triangle(glistp++,23, 21, 16, 23); 


//OBJECT: 2 MATERIAL NO. 1 'env02_cave_ground'OK 

   TEXTURE_4B_TLUT(glistp, env02_cave_ground, env02_cave_ground_tlut, 6,1);

   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,3, 4, 5, 3); 
   gSP1Triangle(glistp++,4, 9, 10, 4); 
   gSP1Triangle(glistp++,11, 12, 13, 11); 
   gSP1Triangle(glistp++,14, 15, 16, 14); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x3d295531);
   gSP1Triangle(glistp++,15, 17, 20, 15); 
   gSP1Triangle(glistp++,22, 23, 9, 22); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+3,26,0);
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x2e182a66);
   gSP1Triangle(glistp++,24, 21, 25, 24); 
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x3166272f);
   gSP1Triangle(glistp++,23, 19, 1, 23); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+11,26,0);
   gSP1Triangle(glistp++,18, 19, 0, 18); 
   gSP1Triangle(glistp++,20, 21, 4, 20); 
           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x3e433f26);           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x3d295531);
   gSP1Triangle(glistp++,21, 22, 6, 21); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x3166272f);
   gSP1Triangle(glistp++,24, 11, 15, 24); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x2e182a66);
   gSP1Triangle(glistp++,25, 13, 16, 25); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+22,26,0);
   gSP1Triangle(glistp++,17, 1, 0, 17); 
   gSP1Triangle(glistp++,7, 14, 18, 7); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x3a0d324b);
   gSP1Triangle(glistp++,10, 13, 15, 10); 
   gSP1Triangle(glistp++,9, 17, 13, 9); 
   gSP1Triangle(glistp++,19, 6, 20, 19); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+3,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x10cc126c);
   gSP1Triangle(glistp++,4, 0, 2, 4); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+4,26,0);
   gSP1Triangle(glistp++,1, 0, 6, 1); 
           gSPModifyVertex(glistp++, 17,   G_MWO_POINT_ST, 0x389655a6);
   gSP1Triangle(glistp++,17, 7, 9, 17); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+29,26,0);
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+42,26,0);
   gSP1Triangle(glistp++,7, 8, 9, 7); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+4,26,0);
   gSP1Triangle(glistp++,0, 18, 5, 0); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+54,26,0);
   gSP1Triangle(glistp++,4, 5, 6, 4); 
   gSP1Triangle(glistp++,7, 8, 9, 7); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+11,26,0);
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x389655a6);
   gSP1Triangle(glistp++,10, 18, 0, 10); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+31,26,0);
   gSP1Triangle(glistp++,16, 0, 19, 16); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+42,26,0);
   gSP1Triangle(glistp++,22, 23, 24, 22); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+67,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+36,26,0);
   gSP1Triangle(glistp++,4, 0, 23, 4); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+53,26,0);
   gSP1Triangle(glistp++,19, 20, 21, 19); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+29,26,0);
   gSP1Triangle(glistp++,1, 0, 11, 1); 
   gSPVertex(glistp++,env02_segm_ground01_VTXPointer+54,26,0);
   gSP1Triangle(glistp++,21, 11, 13, 21); 
   gSP1Triangle(glistp++,11, 25, 18, 11); 

   gDPPipeSync(glistp++);

 } 
 
 
 void env02_segm_walls01_PolyList(u8 animFrame) 
 { 

   Vtx *env02_segm_walls01_VTXPointer = &env02_segm_walls01_VertList_0[0]; 

   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+0,26,0);

//OBJECT: 3 MATERIAL NO. 0 'env02_cave_wall'OK 

   TEXTURE_4B_TLUT(glistp, env02_cave_wall, env02_cave_wall_tlut, 6,1);

   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x00211016);
   gSP1Triangle(glistp++,8, 9, 3, 8); 
           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x3eee1008);
   gSP1Triangle(glistp++,11, 7, 12, 11); 
   gSP1Triangle(glistp++,9, 8, 14, 9); 
   gSP1Triangle(glistp++,11, 18, 19, 11); 
   gSP1Triangle(glistp++,19, 22, 23, 19); 
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x2aaa2016);
   gSP1Triangle(glistp++,14, 21, 24, 14); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+20,26,0);
   gSP1Triangle(glistp++,2, 8, 9, 2); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x2aaa2016);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x3aaa2016);
   gSP1Triangle(glistp++,1, 7, 10, 1); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+25,26,0);
           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x00212016);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x00211016);
   gSP1Triangle(glistp++,18, 23, 7, 18); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+39,26,0);
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x2b381008);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x3eee0008);
   gSP1Triangle(glistp++,13, 10, 0, 13); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+14,26,0);
           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x20db1016);           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x15c01016);
   gSP1Triangle(glistp++,21, 20, 0, 21); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+39,26,0);
   gSP1Triangle(glistp++,21, 22, 23, 21); 
   gSP1Triangle(glistp++,21, 23, 25, 21); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+64,26,0);
   gSP1Triangle(glistp++,1, 2, 3, 1); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+56,26,0);
   gSP1Triangle(glistp++,16, 17, 18, 16); 
           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x2aaa2016);
   gSP1Triangle(glistp++,11, 13, 19, 11); 


//OBJECT: 3 MATERIAL NO. 1 'env02_cave_wall_base'OK 

   TEXTURE_4B_TLUT(glistp, env02_cave_wall_base, env02_cave_wall_base_tlut, 6,1);

   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+0,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSP1Triangle(glistp++,1, 3, 4, 1); 
   gSP1Triangle(glistp++,5, 6, 2, 5); 
   gSP1Triangle(glistp++,7, 2, 4, 7); 
           gSPModifyVertex(glistp++, 5,   G_MWO_POINT_ST, 0x40ad0fbe);           gSPModifyVertex(glistp++, 7,   G_MWO_POINT_ST, 0x40870b66);
   gSP1Triangle(glistp++,10, 5, 7, 10); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x0b2b0b6c);           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x201d0b74);
   gSP1Triangle(glistp++,13, 8, 1, 13); 
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x2b130b6c);
   gSP1Triangle(glistp++,11, 15, 16, 11); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x00100b6c);           gSPModifyVertex(glistp++, 13,   G_MWO_POINT_ST, 0x00241008);
   gSP1Triangle(glistp++,8, 13, 17, 8); 
   gSP1Triangle(glistp++,17, 20, 21, 17); 
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x10100b6c);
   gSP1Triangle(glistp++,15, 23, 25, 15); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+20,26,0);
   gSP1Triangle(glistp++,0, 6, 7, 0); 
           gSPModifyVertex(glistp++, 3,   G_MWO_POINT_ST, 0x10100b6c);           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x00100b6c);
   gSP1Triangle(glistp++,3, 9, 11, 3); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+9,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x10130b28);
   gSP1Triangle(glistp++,23, 0, 24, 23); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+34,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+30,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x10130b28);
   gSP1Triangle(glistp++,0, 7, 8, 0); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+24,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x10130b28);           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x10240008);           gSPModifyVertex(glistp++, 12,   G_MWO_POINT_ST, 0x00240008);
   gSP1Triangle(glistp++,0, 14, 12, 0); 
           gSPModifyVertex(glistp++, 9,   G_MWO_POINT_ST, 0x2028000f);
   gSP1Triangle(glistp++,15, 16, 9, 15); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+18,26,0);
           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x20170b2f);           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x2028000f);           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x1616000f);
   gSP1Triangle(glistp++,0, 15, 18, 0); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x16050b2f);           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x0c4e000f);
   gSP1Triangle(glistp++,1, 18, 20, 1); 
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x0c3d0b2f);           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x0028000f);
   gSP1Triangle(glistp++,4, 20, 19, 4); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0da8093b);           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x084b0026);
   gSP1Triangle(glistp++,14, 22, 23, 14); 
           gSPModifyVertex(glistp++, 23,   G_MWO_POINT_ST, 0x00c1058c);           gSPModifyVertex(glistp++, 22,   G_MWO_POINT_ST, 0x0b54007b);           gSPModifyVertex(glistp++, 21,   G_MWO_POINT_ST, 0x0ee507d0);
   gSP1Triangle(glistp++,23, 22, 21, 23); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+0,26,0);
           gSPModifyVertex(glistp++, 6,   G_MWO_POINT_ST, 0x03c0008c);
   gSP1Triangle(glistp++,6, 0, 2, 6); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+25,26,0);
   gSP1Triangle(glistp++,17, 18, 19, 17); 
   gSP1Triangle(glistp++,20, 21, 22, 20); 
           gSPModifyVertex(glistp++, 14,   G_MWO_POINT_ST, 0x0d9507e5);
   gSP1Triangle(glistp++,14, 20, 19, 14); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+49,26,0);
   gSP1Triangle(glistp++,0, 1, 2, 0); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+39,26,0);
   gSP1Triangle(glistp++,14, 15, 16, 14); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+39,26,0);
           gSPModifyVertex(glistp++, 11,   G_MWO_POINT_ST, 0x2b271008);
   gSP1Triangle(glistp++,11, 10, 17, 11); 
   gSP1Triangle(glistp++,18, 19, 20, 18); 
   gSP1Triangle(glistp++,18, 20, 24, 18); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+56,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x1d6e0b6c);
   gSP1Triangle(glistp++,0, 4, 12, 0); 
   gSP1Triangle(glistp++,13, 14, 15, 13); 
           gSPModifyVertex(glistp++, 16,   G_MWO_POINT_ST, 0x10100b6c);
   gSP1Triangle(glistp++,12, 16, 20, 12); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+32,26,0);
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x00240008);
   gSP1Triangle(glistp++,8, 0, 1, 8); 
           gSPModifyVertex(glistp++, 1,   G_MWO_POINT_ST, 0x00240008);
   gSP1Triangle(glistp++,1, 2, 4, 1); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+57,26,0);
           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x00130b28);           gSPModifyVertex(glistp++, 18,   G_MWO_POINT_ST, 0x10130b28);
   gSP1Triangle(glistp++,10, 18, 20, 10); 
           gSPModifyVertex(glistp++, 8,   G_MWO_POINT_ST, 0x00130b28);           gSPModifyVertex(glistp++, 10,   G_MWO_POINT_ST, 0x10130b28);
   gSP1Triangle(glistp++,8, 10, 21, 8); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+33,26,0);
           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x20170b2f);           gSPModifyVertex(glistp++, 0,   G_MWO_POINT_ST, 0x2028000f);
   gSP1Triangle(glistp++,19, 6, 0, 19); 
   gSPVertex(glistp++,env02_segm_walls01_VTXPointer+58,26,0);
           gSPModifyVertex(glistp++, 4,   G_MWO_POINT_ST, 0x16050b2f);           gSPModifyVertex(glistp++, 20,   G_MWO_POINT_ST, 0x1616000f);
   gSP1Triangle(glistp++,4, 21, 20, 4); 
           gSPModifyVertex(glistp++, 15,   G_MWO_POINT_ST, 0x0c3d0b2f);           gSPModifyVertex(glistp++, 19,   G_MWO_POINT_ST, 0x0c4e000f);
   gSP1Triangle(glistp++,15, 4, 19, 15); 
   gSP1Triangle(glistp++,22, 23, 24, 22); 

   gDPPipeSync(glistp++);

 } 
 
 
Vector3 getPosLightValues()
{



	// = {cavePosLight.col[0], cavePosLight.col[1],cavePosLight.col[2]};
	//Vector3 values = {cavePosLight_Ground.l.col[0], cavePosLight_Ground.l.col[1],cavePosLight_Ground.l.col[2]};
	//Vector3 values = {env_caveGround.l[1].l.dir[0], env_caveGround.l[1].l.dir[1],env_caveGround.l[1].l.dir[2]};
	//Vector3 values = {env_caveGround.l[1].l.col[0], env_caveGround.l[1].l.col[1],env_caveGround.l[1].l.col[2]};


	return values;
	
}