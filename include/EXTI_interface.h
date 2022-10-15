/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 21, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


//void MEXTI_voidInit(u8 copy_u8Line, u8 copy_u8Mode);
// #hash define is better for Init - Init function in general should be without any argument

void MEXTI_voidInit();

void MEXTI_voidEnableEXTI(uint8_t copy_u8EXTILine);

void MEXTI_voidDisableEXTI(uint8_t copy_u8EXTILine);

void MEXTI_voidSwTrigger(uint8_t copy_u8EXTILine);

void MEXTI_voidSetSignalLatch(uint8_t copy_u8EXTILine, uint8_t Copy_u8EXTISenseMode);

void MEXTI_voidSetCallBack(void (*ptr)(void));


#endif
