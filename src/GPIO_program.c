/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : August 26, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidSetPinDirection(uint8_t copy_u8PORT, uint8_t copy_u8PIN, uint8_t copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					if (copy_u8PIN <= 7)                       				   //each pin has 4 bits to control  
					{	
						GPIOA_CRL &= ~((0b1111) << (copy_u8PIN * 4));   	   // &= for clear, Reset - clear Pin     pin no * 4 to shift the "ones" by 4 per time as every pin is controled by 4 bits
																			   // then complement ones to be zero then AND zero with GPIOA to clear the 4 bits representing the pin number  
						
						GPIOA_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));       // |= for set   
					}
					else if (copy_u8PIN <= 15)
					{	
						copy_u8PIN = copy_u8PIN - 8;
						GPIOA_CRH &= ~ ((0b1111) << (copy_u8PIN * 4));
						GPIOA_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4)); 
					}	
					break;
		
		case GPIOB :
					if (copy_u8PIN <= 7)                       				   //each pin has 4 bits to control  
					{	
						GPIOB_CRL &= ~ ((0b1111) << (copy_u8PIN * 4));   	   // &= for clear, Reset - clear Pin     pin no * 4 to shift the "ones" by 4 per time as every pin is controled by 4 bits 
																			   // then complement ones to be zero then AND zero with GPIOA to clear the 4 bits representing the pin number  
						
						GPIOB_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));       // |= for set   
					}
					else if (copy_u8PIN <= 15)
					{	
						copy_u8PIN = copy_u8PIN - 8;
						GPIOB_CRH &= ~ ((0b1111) << (copy_u8PIN * 4));
						GPIOB_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4)); 
					}	
					break;
		
		
		case GPIOC :
					if (copy_u8PIN <= 7)                 // although GPIOC is only 3 pins, but below code is generic for any STM32
					{	
						GPIOC_CRL &= ~ ((0b1111) << (copy_u8PIN * 4));   	    
																			     
						
						GPIOC_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));         
					}
					else if (copy_u8PIN <= 15)
					{	
						copy_u8PIN = copy_u8PIN - 8;
						GPIOC_CRH &= ~ ((0b1111) << (copy_u8PIN * 4));
						GPIOC_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4)); 
					}	
					break;
		default : break;			
	}

	
}

void MGPIO_voidSetPinValue(uint8_t copy_u8PORT, uint8_t copy_u8PIN, uint8_t copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA:

					if (copy_u8Value == GPIO_HIGH)                 
					{	
						SET_BIT(GPIOA_ODR, copy_u8PIN);
					}	
					
					else if (copy_u8Value == GPIO_LOW)                 
					{	
						CLR_BIT(GPIOA_ODR, copy_u8PIN);
					}	
					break;

		case GPIOB:

					if (copy_u8Value == GPIO_HIGH)                 
					{	
						SET_BIT(GPIOB_ODR, copy_u8PIN);
					}	
					
					else if (copy_u8Value == GPIO_LOW)                 
					{	
						CLR_BIT(GPIOB_ODR, copy_u8PIN);
					}	
					break;

		case GPIOC:

					if (copy_u8Value == GPIO_HIGH)                 
					{	
						SET_BIT(GPIOC_ODR, copy_u8PIN);
					}	
					
					else if (copy_u8Value == GPIO_LOW)                 
					{	
						CLR_BIT(GPIOC_ODR, copy_u8PIN);
					}	
					break;
		default : break;			
	}
}



uint8_t MGPIO_voidGetPinValue(uint8_t copy_u8PORT, uint8_t copy_u8PIN)
{
	uint8_t LOC_u8Result = 0;   //Local variable to hold the pin value
	switch(copy_u8PORT)
	{
		case GPIOA: LOC_u8Result = GET_BIT(GPIOA_IDR, copy_u8PIN); break;
		case GPIOB: LOC_u8Result = GET_BIT(GPIOB_IDR, copy_u8PIN); break;
		case GPIOC: LOC_u8Result = GET_BIT(GPIOC_IDR, copy_u8PIN); break;
		default: break;
	}
	return LOC_u8Result;	
}

	

