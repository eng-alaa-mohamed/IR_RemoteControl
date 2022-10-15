/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : Sep 18, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* 0xE000E100  Base Address */

/*Interrupt set-enable registers (NVIC_ISERx)*/
#define NVIC_ISER0      *((uint32_t*) 0xE000E100)  /* Enable external interrupts from 0 to 31 */
#define NVIC_ISER1      *((uint32_t*) 0xE000E104)  /* Enable external interrupts from 32 to 63*/

#define NVIC_ICER0      *((uint32_t*) 0xE000E180)  /* Interrupt clear enable */
#define NVIC_ICER1      *((uint32_t*) 0xE000E184)  /* Interrupt clear enable */

#define NVIC_ISPR0      *((uint32_t*) 0xE000E200)  /* Interrupt clear enable */
#define NVIC_ISPR1      *((uint32_t*) 0xE000E204)  /* Interrupt clear enable */

#define NVIC_ICPR0      *((uint32_t*) 0xE000E280)  /* Interrupt clear enable */
#define NVIC_ICPR1      *((uint32_t*) 0xE000E284)  /* Interrupt clear enable */

#define NVIC_IABR0      *((volatile uint32_t*) 0xE000E300)   /* Interrupt Active Bit Register */
#define NVIC_IABR1      *((volatile uint32_t*) 0xE000E304)   /* Interrupt Active Bit Register */

/*Interrupt priority registers (NVIC_IPRx)*/
#define NVIC_IPR		((volatile uint8_t*)0xE000E400)     //no dereference as it is address of the array //u8 because this register is a byte-access

#define SCB				(*(uint32_t*)0xE000ED00)                       /*System control block*/
/*Application interrupt and reset control register */

#define SCB_AIRCR		*((uint32_t*)0xE000ED0C)  /*System control block base register + offset */



#define MNVIC_GROUP_4_SUB_0		0x05FA0300
#define MNVIC_GROUP_3_SUB_1		0x05FA0400
#define MNVIC_GROUP_2_SUB_2		0x05FA0500
#define MNVIC_GROUP_1_SUB_3		0x05FA0600
#define MNVIC_GROUP_0_SUB_4		0x05FA0700



#endif
