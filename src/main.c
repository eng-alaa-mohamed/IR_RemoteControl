/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 21, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "STK_interface.h"

void voidIR_Play(void);
void voidInterpret_IRData(void);
void voidGetIRFrame(void);

volatile uint8_t   u8StartFlag       = 0;    //To check if this the falling edge of the start bit or another bit else
volatile uint32_t  u32FrameData[50]  = {0};  //Initialize array 50 bits
volatile uint8_t   u8EdgeCounter     = 0;
volatile uint8_t   u8Data            = 0;


void voidIR_Play(void)
{
	switch (u8Data)  //Decimal Data depends on the pressed button
	{
	case 69: MGPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);  	break;  //power button
	case 70: MGPIO_voidSetPinValue(GPIOA,PIN1,GPIO_LOW); 	break;  //Mode  button

	case 71: MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_HIGH); 	break;  //mute button
	case 68: MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_LOW); 	break;  //play button

	case 67: MGPIO_voidSetPinValue(GPIOA,PIN3,GPIO_HIGH); 	break;  //forward button
	case 66: MGPIO_voidSetPinValue(GPIOA,PIN3,GPIO_LOW); 	break;  // button 7
	}
}

void voidInterpret_IRData(void)
{
	uint8_t i;
	u8Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )  //verify a valid frame. Typically start bit duration is 13500us
	{
		for (i=0;i<8;i++)
		{
			/*Ignore first bit (start) and 16 bits of the address *
			 * Data starts from bit 17 to 24 */
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )  //Bit "One" is 2250us
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}

		voidIR_Play();
	}

	else
	{
		/* Invalid Frame */
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}



void voidGetIRFrame(void)
{
	if (u8StartFlag == 0)
	{
		MSTK_voidSetIntervalSingle(500000,voidInterpret_IRData);       /* Start Timer - first falling edge */
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();       //Read the timer (No. of ticks) since the last falling edge
		MSTK_voidSetIntervalSingle(500000,voidInterpret_IRData);      //start the timer
		u8EdgeCounter++;
	}
}


void main(void)
{
	/*RCC*/
	RCC_voidInitSysClock();             		//Initialize clock system
	RCC_voidEnableClock(RCC_APB2, GPIOA_RCC);    //enable IOPA

	/*GPIO*/
	MGPIO_voidSetPinDirection(GPIOA, PIN0, INPUT_FLOATING);  	      //A0 input floating
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP);    //A1 output
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP);    //A2 output
	MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_2MHZ_PP);    //A3 output

	/*IR receiver power - A9 controls GND of IR receiver and Vcc is externally supplied 3.3v */
	MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_2MHZ_PP);    //A9 Output - Power IR receiver
	MGPIO_voidSetPinValue(GPIOA,PIN9,GPIO_LOW);

	/* EXTI Initialization */
	MEXTI_voidSetCallBack(voidGetIRFrame);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */


	//Enable EXTI0 from NVIC
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt (EXT0);  //External interrupt number is 6 in NVIC


	/* SysTick Init - Enable SysTick AHB/8 = 1MHZ */
	MSTK_voidInit();
	while(1);

}
