/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 21, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


static void (*EXTI0_CallBack)(void) = NULL;

void MEXTI_voidInit()
{
#if		EXTI_LINE == EXTI_LINE0
	SET_BIT(EXTI -> IMR , EXTI_LINE0 );
#elif	EXTI_LINE == EXTI_LINE1
	SET_BIT(EXTI -> IMR , EXTI_LINE1 );
#elif	EXTI_LINE == EXTI_LINE2
	SET_BIT(EXTI -> IMR , EXTI_LINE2 );
#else
#error ("Wrong Externl Interrupt Line !")
#endif

#if EXTI_MODE == RISING_EDGE
	SET_BIT(EXTI->RTSR, EXTI_LINE);
#elif EXTI_MODE == FALLING_EDGE
	SET_BIT(EXTI->FTSR, EXTI_LINE);
#elif EXTI_MODE == ON_CHANGE
	SET_BIT(EXTI->RTSR, EXTI_LINE);
	SET_BIT(EXTI->FTSR, EXTI_LINE);
#else
#error "Wrong Interrupt Mode !"
#endif
	// CLR_BIT(EXTI->IMR, copy_u8Line);  by default, disable the interrupt
}

void MEXTI_voidEnableEXTI(uint8_t copy_u8EXTILine)
{
	SET_BIT(EXTI->IMR, copy_u8EXTILine);
}

void MEXTI_voidDisableEXTI(uint8_t copy_u8EXTILine)
{
	CLR_BIT(EXTI->IMR, copy_u8EXTILine);
}

void MEXTI_voidSwTrigger(uint8_t copy_u8EXTILine)   //software interrupt
{
	SET_BIT(EXTI->SWIER, copy_u8EXTILine);

}

void MEXTI_voidSetSignalLatch(uint8_t copy_u8EXTILine, uint8_t Copy_u8EXTISenseMode)  //same as EXTI initialization, but in runtime
{
	switch (Copy_u8EXTISenseMode)
	{
	case RISING_EDGE    :SET_BIT(EXTI->RTSR, copy_u8EXTILine); break;
	case FALLING_EDGE   :SET_BIT(EXTI->FTSR, copy_u8EXTILine); break;
	case ON_CHANGE:SET_BIT(EXTI->RTSR, copy_u8EXTILine);
	SET_BIT(EXTI->FTSR, copy_u8EXTILine); break;
	default: break;
	}
	SET_BIT(EXTI->IMR, copy_u8EXTILine);

}

void MEXTI_voidSetCallBack(void (*ptr) (void))
{

	EXTI0_CallBack = ptr;

}


void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();

	/*clear pending bit*/
	//SET_BIT(EXTI->PR, copy_u8EXTILine);
	SET_BIT(EXTI->PR, 0);
}


