/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 18, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInterrupt (uint8_t Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

}



void MNVIC_voidDisableInterrupt (uint8_t Copy_u8IntNumber)
{

	if(Copy_u8IntNumber <=31)   //u8 is a number >= 0
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);   //zero in NVIC_ICER0 has no effect
	}

	else if (Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -= 32;                  // to convert bit 32 to bit zero in register NVIC_ISER1
		NVIC_ICER1 = (1 << Copy_u8IntNumber);   //zero in NVIC_ISER0 has no effect
	}
	else
	{
		/*error*/
	}

}


void MNVIC_voidSetPendingFlag(uint8_t Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}

	else if (  Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}

	else
	{
		/* Return Error */
	}

}



void MNVIC_voidClearPendingFlag(uint8_t Copy_u8IntNumber)
{

	if(Copy_u8IntNumber <=31)   //u8 is a number >= 0
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);        //Interrupt Set Pending Register
	}

	else if (Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*error*/
	}

}


uint8_t MNVIC_u8GetActiveFlag(uint8_t Copy_u8IntNumber)
{

	uint8_t Local_u8Result;

	if(Copy_u8IntNumber <=31)   //u8 is a number >= 0
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);

	}

	else if (Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
	}
	else
	{
		/*error*/
	}

}

void MNVIC_voidSetPriority(int8_t Copy_s8IntID, uint8_t Copy_u8GroupPriority, uint8_t Copy_u8SubPriority, uint32_t Copy_u32GROUP)   //s8 signed character as Interrupt ID could be negative number
{
	/*step of each group is 0x100 which is 256 in binary */
	uint8_t Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << ((Copy_u32GROUP - 0x05FA0300)/256));  /* O/P is 0, 1,2,3,4 */


	/*Core peripheral */


	/*External peripheral*/
	if(Copy_s8IntID >= 0)   //u8 is a number >= 0
	{
		NVIC_IPR[Copy_s8IntID] =  Local_u8Priority << 4;   //to set priority in the 2nd half of the register as the 1st half is reserved
	}
	SCB_AIRCR = Copy_u32GROUP ;

	//else();
}


// Application interrupt and reset control register (SCB_AIRCR) to set priority grouping - bits 8,9,10
// To write to this register, you must write 0x5FA to the VECTKEY field,
void MNVIC_voidInit(void)
{

	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

/*
void MNVIC_voidSetPriority(u8 Copy_PeripheralIndex, u8 Copy_u8Priority)
{
	if (Copy_PeripheralIndex < 60)
	{
		//Copy_PeripheralIndex is the peripheral position in vector table for connectivity line devices
		//Copy_u8Priority is 8bit value but the 4 LSB are reserved and the 4 MSB represent group and sub-group priority
		//e.g, group 2-bit and sub-group 2-bit  0011  Group zero and sub-group 3
		NVIC_IPR[Copy_PeripheralIndex] = Copy_u8Priority;
	}
	else
	{
		/*Report Error*/
//	}
//}


//*/


