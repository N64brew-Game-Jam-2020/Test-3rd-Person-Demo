#define COMBINE_HEX(U, V) ((((s32)U) << 16) & 0xFFFF0000) | (((s32)V) & 0x0000FFFF)

//Custom shaders
#define G_CC_SHADEFADEA             0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT
#define	G_CC_DECALFADE              0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT
#define	G_CC_DECALFADEA             0, 0, 0, TEXEL0, TEXEL0, 0, ENVIRONMENT, 0
#define	G_CC_TRANSTEXTUREFOG        TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0
#define	G_CC_TRANSTEXTUREFOG2 		0, 0, 0, COMBINED, 0, 0, 0, COMBINED

#define G_CC_VTXSHADER				0,	0, PRIMITIVE,	ENVIRONMENT,	0, 0, PRIMITIVE, ENVIRONMENT
		

//Graphics Macros

#define TEXTURE_FOG_LIGHT(dl,r,g,b,a,min,max){\
	gDPPipeSync(dl++);\
	gDPSetCycleType(dl++,G_CYC_2CYCLE);\
	gDPSetFogColor(dl++, r,g,b,a);\
	gSPFogPosition(dl++, min+130, max+130);\
	gSPSetGeometryMode(dl++,G_FOG);\
	gDPSetCombineMode(dl++, G_CC_MODULATERGB, G_CC_PASS2);\
	gDPSetRenderMode(dl++, G_RM_FOG_SHADE_A, G_RM_RA_ZB_OPA_SURF2)\
}

//NOTE: The following is for VTX colors without using lighting
#define TEXTURE_FOG(dl,r,g,b,a,min,max){\
	gDPPipeSync(dl++);\
	gSPClearGeometryMode(dl++,0xFFFFFFFF);\
	gSPSetGeometryMode(dl++, G_ZBUFFER|G_CULL_BACK|G_SHADE| G_SHADING_SMOOTH );\
	gDPSetCycleType(dl++,G_CYC_1CYCLE);\
	gDPSetColorDither(dl++, G_CD_BAYER);\
	gDPSetCombineMode(dl++, G_CC_MODULATERGBA, G_CC_MODULATERGBA);\
	gDPSetRenderMode(dl++, G_RM_FOG_SHADE_A, G_RM_RA_ZB_OPA_SURF2)\
}

	
#define DEBUG_LOG_1(x,y,string,a)	sprintf(tempstring, string, a);	sprintf(outstring, tempstring);	Draw8Font(x,y, TEX_COL_WHITE, 0)
#define DEBUG_LOG_5(x,y,string,a,b,c,d,e)	sprintf(tempstring, string, a,b,c,d,e);	sprintf(outstring, tempstring);	Draw8Font(x,y, TEX_COL_WHITE, 0)

#define DEBUGTEST(x,y)	Draw8Font(x,y, TEX_COL_WHITE, 0)

	
#define S_TEXTURE_FOG_LIGHT {\
	gsDPPipeSync(),\
	gsSPTexture(0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON),\
	gsDPLoadTextureBlock(Dark_Texture_Wall_1,	G_IM_FMT_RGBA,	G_IM_SIZ_16b,	32, 32,	0, G_TX_WRAP, G_TX_WRAP,	5, 5, G_TX_NOLOD, G_TX_NOLOD),\
	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),\
	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)\
}


	
#define TEXTURE_TRANSPARENT(dl,r,g,b,a) {\
	gDPPipeSync(dl++);\
	gDPSetCycleType(dl++,G_CYC_1CYCLE)\
}

#define PRIM_TRANSPARENT(dl) {\
	gDPPipeSync(dl++);\
	gDPTileSync(dl++);\
	gSPClearGeometryMode(dl++,0xFFFFFFFF);\
	gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_LIGHTING );\
	gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_OFF);\
	gDPSetCombineMode(dl++,G_CC_PRIMITIVE, G_CC_PRIMITIVE);\
	gDPSetRenderMode(dl++,G_RM_AA_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2)\
}

#define PRIM_TRANSPARENT_PENITRATE_SURF(dl) {\
	gDPPipeSync(dl++);\
	gDPTileSync(dl++);\
	gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_OFF);\
	gDPSetCombineMode(dl++,G_CC_PRIMITIVE, G_CC_PRIMITIVE);\
	gDPSetRenderMode(dl++,G_RM_AA_ZB_XLU_INTER, G_RM_AA_ZB_XLU_INTER2)\
}

#define TEXTURE_4B_TRANSPARENT_OVERLAY(dl, texture, pal, scale, lod) {\
	gDPPipeSync(dl++);\
	gDPTileSync(dl++);\
	gSPClearGeometryMode(dl++,0xFFFFFFFF);\
    gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_LIGHTING );\
	gDPSetCycleType(dl++, G_CYC_1CYCLE);\
    gDPSetCombineMode(dl++,G_CC_BLENDRGBDECALA, G_CC_BLENDRGBDECALA);\
	gSPTexture(dl++, 0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);\
	gDPSetTextureFilter(dl++, G_TF_AVERAGE);\
	gDPSetRenderMode(dl++, G_RM_AA_ZB_XLU_SURF, G_RM_ZB_XLU_SURF2);\
	gDPSetTextureLUT(dl++, G_TT_RGBA16);\
	gDPLoadTLUT_pal16(dl++, 0, pal);\
	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod)\
}


#define TEXTURE_4B_TLUT_VTXCOL(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(dl++, G_TF_AVERAGE);	gDPSetRenderMode(dl++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)

#define TEXTURE_4B_TLUT_MIRRORX(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_MIRROR, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(dl++, G_TF_AVERAGE);	gDPSetRenderMode(dl++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)

#define TEXTURE_4B_TLUT(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(dl++, G_TF_AVERAGE);	gDPSetRenderMode(dl++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)
#define TEXTURE_4B_TLUT_BILERP(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(dl++, G_TF_BILERP);	gDPSetRenderMode(dl++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)
#define TEXTURE_4B_TLUT_POINT(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(dl++, G_TF_POINT);	gDPSetRenderMode(dl++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)
#define TEXTURE_4B_TLUT_ANIMATED(dl, texture, pal, s, t, scale, lod) 	gDPPipeSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureTile_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	s,t, 63, 63, 0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(dl++, G_TF_POINT);	gDPSetRenderMode(dl++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)

#define TEXTURE_4B_TLUT_INTER(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(dl++, G_TF_BILERP);	gDPSetRenderMode(dl++,G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_INTER)
#define TEXTURE_4B_TLUT_TRANSP(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_TRANSTEXTUREFOG, G_CC_TRANSTEXTUREFOG2);	gDPSetTextureFilter(dl++, G_TF_BILERP);	gDPSetPrimColor(dl++, 0, 255, 255, 255, 255, 90); gDPSetRenderMode(dl++,G_RM_FOG_SHADE_A,G_RM_ZB_XLU_SURF2)
#define TEXTURE_4B_TLUT_CLAMP(texture, pal, scale, lod) 	gDPPipeSync(glistp++); gSPTexture(glistp++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(glistp++, G_TT_RGBA16);	gDPLoadTLUT_pal16(glistp++, 0, pal);	gDPLoadTextureBlock_4b(glistp++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_CLAMP, G_TX_CLAMP,	scale, scale, lod, lod);	gDPSetCombineMode(glistp++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(glistp++, G_TF_BILERP);	gDPSetRenderMode(glistp++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)








/*
#define TEXTURE_4B_TLUT_INTER(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++);  gSPClearGeometryMode(dl++,0xFFFFFFFF); gSPSetGeometryMode(dl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_LIGHTING ); gDPSetCycleType(dl++,G_CYC_1CYCLE); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_SHADE, G_CC_SHADE);	gDPSetTextureFilter(dl++, G_TF_BILERP);	gDPSetRenderMode(dl++,G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_INTER2)
#define TEXTURE_4B_TLUT_CLAMP(texture, pal, scale, lod) 	gDPPipeSync(glistp++); gSPTexture(glistp++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(glistp++, G_TT_RGBA16);	gDPLoadTLUT_pal16(glistp++, 0, pal);	gDPLoadTextureBlock_4b(glistp++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_CLAMP, G_TX_CLAMP,	scale, scale, lod, lod);	gDPSetCombineMode(glistp++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(glistp++, G_TF_BILERP);	gDPSetRenderMode(glistp++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)
#define TEXTURE_4B_TLUT_CLAMP_GEIST(texture, pal, scale, lod) 	gDPPipeSync(glistp++); gDPSetCycleType(glistp++, G_CYC_2CYCLE);	gDPSetTextureLUT(glistp++, G_TT_RGBA16); gDPLoadTLUT_pal16(glistp++, 0, pal); gDPLoadTextureBlock_4b(glistp++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_CLAMP, G_TX_CLAMP,	scale, scale, lod, lod);	gDPSetCombineMode(glistp++,G_CC_MODULATERGB, G_CC_PASS2); 	gDPSetTextureFilter(glistp++, G_TF_BILERP);	gSPSetGeometryMode(glistp++, G_ZBUFFER|G_CULL_BACK|G_SHADE|G_FOG|G_LIGHTING );		gDPSetRenderMode(glistp++,G_RM_FOG_SHADE_A, G_RM_RA_ZB_OPA_SURF2)   //gSPTexture(glistp++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);


#define TEXTURE_4B_TRANSPARENT_TLUT(dl, texture, pal, scale, lod) 	gDPPipeSync(dl++); gDPTileSync(dl++); gSPTexture(dl++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(dl++, G_TT_RGBA16);	gDPLoadTLUT_pal16(dl++, 0, pal);	gDPLoadTextureBlock_4b(dl++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_WRAP, G_TX_WRAP,	scale, scale, lod, lod);	gDPSetCombineMode(dl++,G_CC_BLENDRGBDECALA, G_CC_BLENDRGBDECALA);	gDPSetTextureFilter(dl++, G_TF_AVERAGE);	gDPSetRenderMode(dl++,G_RM_AA_ZB_XLU_INTER, G_RM_AA_ZB_XLU_INTER2)
*/



//#define TEXTURE_SPECULAR(texture, pal, scale, lod) 	gSPTexture(glistp++,0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON);	gDPSetTextureLUT(glistp++, G_TT_RGBA16);	gDPLoadTLUT_pal16(glistp++, 0, pal);	gDPLoadTextureBlock_4b(glistp++,texture,	G_IM_FMT_CI,	64, 64,	0, G_TX_CLAMP, G_TX_CLAMP,	scale, scale, lod, lod);	gDPSetCombineMode(glistp++,G_CC_MODULATERGB, G_CC_PASS2);	gDPSetTextureFilter(glistp++, G_TF_BILERP);	gDPSetRenderMode(glistp++,G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2)

//#define S_TEXTURE_FOG_LIGHT(r,g,b,a,min,max) 	gsSPTexture(0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON),	gsDPLoadTextureBlock(Dark_Texture_Wall_1,	G_IM_FMT_RGBA,	G_IM_SIZ_16b,	32, 32,	0, G_TX_WRAP, G_TX_WRAP,	5, 5, G_TX_NOLOD, G_TX_NOLOD),	gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_PASS2),	gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_OPA_SURF2),

/*
#define	FBUF_ADRS(x,y)		(FBUF_TOP+((x)+(y)*SCREEN_WD)*2)
#define	canvas_cursor(x,y)	__cursor = (u16 *)FBUF_ADRS((x),(y))
#define	canvas_center(x,y)	canvas_cursor((SCREEN_WD-(x)*FONT_WSKIP)/2,(y))
#define	canvas_wskip(x)		__cursor += (x);
#define	canvas_putstr(n,fg,bg)	canvas_puts((n), sizeof(n)-1, (fg), (bg))
*/