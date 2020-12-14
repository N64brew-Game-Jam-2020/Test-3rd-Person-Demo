#ifndef BOOLCAST_H_   /* Include guard */
#define BOOLCAST_H_

#define MAX_BITS    8
#define TRUE        1
#define FALSE       0

/**
  @author James
  @section BOOL CAST
  @brief This is a tool to use multiple data types to represent flags as one-bit, rather than a byte to save memory.
         It is targeted for the Nintendo 64
  */

/**
 *  @macro BC_SET_FLAG
 *  @brief This is a shorthand notation for setting or clearing a flag in the data.
 *  @param FLAG - This is the entire flag data to have one bit set
 *  @param POS -  This is the bit to set in the entire data structure
 */
#define BC_SET_FLAG(FLAG, POS) (FLAG |= (1<<POS))

/**
 *  @macro BC_CLEAR_FLAG
 *  @brief This is a shorthand notation for setting or clearing a flag in the data.
 *  @param FLAG - This is the entire flag data to have one bit set
 *  @param POS -  This is the bit to set in the entire data structure
 */
#define BC_CLEAR_FLAG(FLAG, POS) (FLAG &= ~(1<<POS))

///@brief typedef declarations
///@param Bool - a parameter to pass an unsigned 8-bit integer for a flag mask.
///@note 'Bool' is used as a typical defined function here, as C99 standards are not yet defined
typedef union bool_t
{
    u8  flags8_t;
    u16 flags16_t;
    u32 flags32_t;
    u64 flags64_t;
}bool_;


#endif // BOOLCAST_H_
