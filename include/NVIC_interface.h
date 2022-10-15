/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 18, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt (uint8_t Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (uint8_t Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag(uint8_t Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(uint8_t Copy_u8IntNumber);


uint8_t MNVIC_u8GetActiveFlag(uint8_t Copy_u8IntNumber);
void MNVIC_voidInit(void);
//void MNVIC_voidSetPriority(uint8_t Copy_PeripheralIndex, uint8_t Copy_u8Priority);
void MNVIC_voidSetPriority(int8_t Copy_s8IntID, uint8_t Copy_u8GroupPriority, uint8_t Copy_u8SubPriority, uint32_t Copy_u32GROUP);

#define		GROUP3		0x05FA0300     //4bits for group (IPR) =>group
#define		GROUP4		0x05FA0400    //3bits for group and 1 bit for sub
#define		GROUP5		0x05FA0500    //2bits for group and 2 bits for sub
#define		GROUP6		0x05FA0600	  //1bits for group and 3 bits for sub
#define		GROUP7		0x05FA0700	  //0bits for group and 4 bits for sub

//#define For Interrupt ID =  POsition In Vector Table
#define WWDG   0
#define EXT0   6
#define EXT1   7
#define DMA_ID 11
/////////////////////////


#endif
