/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 28, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Define Callback Global Variable */
static void (*MSTK_CallBack) (void);

/* Define Variable for interval mode */
static uint8_t MSTK_u8ModeOfInterval;

/*Apply clock choice from configuration file
 * Disable SysTick interrupt
 * Disable SysTick 						    */
void MSTK_voidInit(void)
{
	/*Clock Source Selection*/
	/* Disable STK - Disable STK Interrupt  */
#if clocksource == Processor_clock
	MSTK -> CTRL = 0x00000004;                 //Set clock source AHB
#elif 	clocksource == Processor_clock_Div_8
	MSTK -> CTRL = 0; 						   //Set clock source AHB/8

#endif

}

//synchronous timer function
void MSTK_voidSetBusyWait(uint32_t Copy_u32Ticks)
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	/* Wait till flag is raised */
	while( (GET_BIT(MSTK->CTRL,16)) == 0);

	/* Stop Timer */
	SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

void MSTK_voidSetIntervalSingle(uint32_t Copy_u32Ticks, void (*Copy_ptr) (void))
{
	/* Disable Timer i.e if the function is called during timer counting, it will reset the timer and start counting again */
	CLR_BIT(MSTK->CTRL, 0);
	MSTK -> VAL = 0;
	
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);

	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);
}

void MSTK_voidSetIntervalPeriodic(uint32_t Copy_u32Ticks, void (*Copy_ptr) (void))
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);

	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(MSTK->CTRL, 1);
}

//Stop Asynchronous Timer, either single or periodic interval
void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK->CTRL, 1);

	/* Stop Timer */
	SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}


uint32_t MSTK_u32GetElapsedTime(void)
{
	return MSTK -> LOAD - MSTK -> VAL;
}

uint32_t MSTK_u32GetRemainingTime(void)
{
	return MSTK -> VAL;
}


void SysTick_Handler(void)
{
	uint8_t Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK->CTRL, 1);

		/* Stop Timer */
		SET_BIT(MSTK->CTRL, 0);
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}

	/* Callback notification */
	MSTK_CallBack();

	/* Clear interrupt flag by reading the flag bit*/
	Local_u8Temporary = GET_BIT(MSTK->CTRL,16);
}
