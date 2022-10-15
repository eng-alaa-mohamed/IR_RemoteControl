/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 21, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


typedef struct {
	volatile uint32_t IMR;    //Interrupt mask register
	volatile uint32_t EMR;    //Event mask register
	volatile uint32_t RTSR;   //Rising trigger selection register
	volatile uint32_t FTSR;   //Falling trigger selection register
	volatile uint32_t SWIER;  //Software interrupt event register
	volatile uint32_t PR;     //Pending register
	
}EXTI_t;

#define EXTI ((volatile EXTI_t *) 0x40010400) 

#define 	EXTI_LINE0		0
#define 	EXTI_LINE1		1
#define 	EXTI_LINE2		2
#define 	EXTI_LINE3		3
#define 	EXTI_LINE4		4
#define 	EXTI_LINE5		5
#define 	EXTI_LINE6		6
#define 	EXTI_LINE7		7


#define		RISING_EDGE 		0
#define 	FALLING_EDGE 		1
#define 	ON_CHANGE			2



#endif
