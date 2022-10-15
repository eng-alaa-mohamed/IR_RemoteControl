/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : August 26, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_HIGH	1
#define GPIO_LOW	0

#define		GPIOA	0
#define		GPIOB	1
#define		GPIOC	2

#define 	PIN0	0
#define 	PIN1	1
#define 	PIN2	2
#define 	PIN3	3
#define 	PIN4	4
#define 	PIN5	5
#define 	PIN6	6
#define 	PIN7	7

#define 	PIN8	8
#define 	PIN9	9
#define 	PIN10	10
#define 	PIN11	11
#define 	PIN12	12
#define 	PIN13	13
#define 	PIN14	14
#define 	PIN15	15


#define		OUTPUT_SPEED_10MHZ_PP		0b0001               //PP Output 10MHz - push pull
#define		OUTPUT_SPEED_10MHZ_OD		0b0101               //PP Output 10MHz - Open Drain
#define		OUTPUT_SPEED_10MHZ_AFPP		0b1001               //PP Output 10MHz - Alternative function - push pull
#define		OUTPUT_SPEED_10MHZ_AFOD		0b1101               //PP Output 10MHz - Alternative function - Open Drain


#define		OUTPUT_SPEED_2MHZ_PP		0b0010               //PP Output 2MHz - push pull
#define		OUTPUT_SPEED_2MHZ_OD		0b0110               //PP Output 2MHz - Open Drain
#define		OUTPUT_SPEED_2MHZ_AFPP		0b1010               //PP Output 2MHz - Alternative function - push pull
#define		OUTPUT_SPEED_2MHZ_AFOD		0b1110               //PP Output 2MHz - Alternative function - Open Drain

#define		OUTPUT_SPEED_50MHZ_PP		0b0011               //PP Output 50MHz - push pull
#define		OUTPUT_SPEED_50MHZ_OD		0b0111               //PP Output 50MHz - Open Drain
#define		OUTPUT_SPEED_50MHZ_AFPP		0b1011               //PP Output 50MHz - Alternative function - push pull
#define		OUTPUT_SPEED_50MHZ_AFOD		0b1111               //PP Output 50MHz - Alternative function - Open Drain



#define		INPUT_ANALOG				0b0000               
#define		INPUT_FLOATING				0b0100  
#define		INPUT_PULL_UP_DOWN			0b1000  










// THE ORDER TO CREATE A DRIVER, FIRST create _private.h file that has all register values then _intyerface.h file has all functions that user will use as if you are selling a driver to a user 
// copy the prototypes functions to _program.c 


void MGPIO_voidSetPinDirection(uint8_t copy_u8PORT, uint8_t copy_u8PIN, uint8_t copy_u8Mode);   //set pin direction (port, pin, direction either input or output)
void MGPIO_voidSetPinValue(uint8_t copy_u8PORT, uint8_t copy_u8PIN, uint8_t copy_u8Value);      //Output pin

uint8_t MGPIO_voidGetPinValue(uint8_t copy_u8PORT, uint8_t copy_u8PIN);  // Return pin value





#endif

