/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 28, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/*Apply clock choice from configuration file
 * Disable SysTick interrupt
 * Disable SysTick 						    */
void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(uint32_t Copy_u32Ticks);


void MSTK_voidSetIntervalSingle(uint32_t Copy_u32Ticks, void (*Copy_ptr) (void));


void MSTK_voidSetIntervalPeriodic(uint32_t Copy_u32Ticks, void (*Copy_ptr) (void));

void MSTK_voidStopInterval(void);

uint32_t MSTK_u32GetElapsedTime(void);

uint32_t MSTK_u32GetRemainingTime(void);



#endif
