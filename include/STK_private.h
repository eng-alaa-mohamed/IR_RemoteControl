/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 28, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct
{
	volatile uint32_t CTRL  ;
	volatile uint32_t LOAD  ;
	volatile uint32_t VAL   ;
}MSTK_Type;

#define     MSTK    ((MSTK_Type*)0xE000E010)


/*
#define	STK_CTRL	 *((volatile u32*)0xE000E010)         // SYSTICK Control Register
#define STK_LOAD	 *((volatile u32*)0xE000E014)
#define STK_VAL		 *((volatile u32*)0xE000E018)
#define STK_CALIB    *((volatile u32*)0xE000E01C)
*/


#define Processor_clock				0
#define Processor_clock_Div_8   	1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1


#endif


