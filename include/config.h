#ifndef N64_CONFIG_H
#define N64_CONFIG_H

    extern int ptr_buf[];
    extern int tune_buf[];
    extern int sfx_buf[];
    
    void Rom2Ram(void *from_addr, void *to_addr, s32 seq_size);
	
 /*=================================
           Sound code segments
    =================================*/
    
    // Code segment start and end
    extern char _codeSegmentStart[];
    extern char _codeSegmentEnd[];

    // Segment arrays
    extern u8 _wbankSegmentRomStart[];
    extern u8 _pbankSegmentRomStart[];
    extern u8 _pbankSegmentRomEnd[];
    extern u8 _sfxSegmentRomStart[];
    extern u8 _sfxSegmentRomEnd[];

    // Segment macros
    #define WBANK_START	    _wbankSegmentRomStart
    #define PBANK_START	    _pbankSegmentRomStart
    #define PBANK_END	    _pbankSegmentRomEnd
    #define SFX_START	    _sfxSegmentRomStart
    #define SFX_END		    _sfxSegmentRomEnd

#endif