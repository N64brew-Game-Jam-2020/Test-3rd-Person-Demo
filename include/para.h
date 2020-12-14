
#define PAKCHK
//#define CAM_DISTANCE	7250.0	/*The distance between the camera and gaze-point */
#define CAM_DISTANCE	45.0	/*The distance between the camera and gaze-point */

#define BASE_MAX_SIZE	550.0	/*The length of one side of the base map */

#define OBJ_SIZE	100.0	/*The size of the map object */
#define OBJ_SCALE	0.6	/*The scale of the map object */

#define TAIL_SIZE	35.0	/*The size of the tail */
#define HEAD_SIZE	40.0	/*The size of the head */

#define SHOT_SPEED 30.0		/*Speed of the shot tail */
#define MAX_SLEEP 120		/*The sleeping time */
#define SUB	4		/*Whether or not to update the tail coordinate referring data before some V */

#define GAME_NOTE_SIZE	100*60*4	/* The game note size for saving  */

/*
   0. Decision			(Picooon)
   1. Canncel		    (Byuu)
   2. Cursor move		(Pico)
   3. Pause			    (Picooon)
   4. Shoot a bullet	(Pyu)
   5. Explosion (small)	(Dooon)
   6. Explosion (big)	(Ddooon)
   7. Bite			    (Gab)
   8. Time count down 1	("Pi" of pi, pi, pi, pooon)
   9. Time count down 2	("Pooon" of pi, pi, pi, pooon)
*/

#define EFF_OK		0
#define EFF_CANCEL	1
#define EFF_CUR_MOVE	2
#define EFF_PAUSE	3
#define EFF_SHOT_TAIL	4
#define EFF_SML_EXPL	5
#define EFF_BIG_EXPL	6
#define EFF_EAT_TAIL	7
#define EFF_TIME_DWN1	8
#define EFF_TIME_DWN2	9

/*WADE TEST SHADER MODES*/
#define G_CC_MULPRIMSHADE PRIMITIVE,0,SHADE,0,PRIMITIVE,0,SHADE,0

/*Don't change the below from here */
#define TAIL_MOVE_BUF	256	/*The maximum buffer for drawing the tail */
#define TAIL_NOTHING	0	/*The status of the shot tail */
#define TAIL_STOPPING	1
#define TAIL_MOVING	2
#define TAIL_WAITING	3
#define OBJ_MAX		9	/*The number of the map object */
#define PAK_NOT_REMAIN	100
#define NOT_CREAT	200
#define RUMBLE_PAK	300