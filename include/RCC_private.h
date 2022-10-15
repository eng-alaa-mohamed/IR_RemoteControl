/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : August 26, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/* Register Definitions - add 4 bytes to the base address */

/*  0x40021000  base address of RCC register - 5 registers for clock and 5 for Reset */

#define RCC_CR				*((uint32_t*)0x40021000)     /*choose clock type*/
#define RCC_CFGR			*((uint32_t*)0x40021004)     /*Clock configuration*/
#define RCC_CIR				*((uint32_t*)0x40021008)
#define RCC_APB2RSTR		*((uint32_t*)0x4002100C)
#define RCC_APB1RSTR		*((uint32_t*)0x40021010)
#define RCC_AHBENR			*((uint32_t*)0x40021014)   /*Enable prephiral on AHB bus*/
#define RCC_APB2ENR			*((uint32_t*)0x40021018)   /*Enable prephiral on APB2 bus*/
#define RCC_APB1ENR			*((uint32_t*)0x4002101C)   /*Enable prephiral on APB1 bus*/
#define RCC_BDCR			*((uint32_t*)0x40021020)
#define RCC_CSR				*((uint32_t*)0x40021024)


/* Clock Types */
#define RCC_HSE_CRYSTAL				0
#define RCC_HSE_RC					1									
#define RCC_HSI						2	
#define RCC_PLL 					3			

/*PLL Input */
#define RCC_PLL_IN_HSI_DIV_2        0
#define RCC_PLL_IN_HSE_DIV_2  		1	
#define RCC_PLL_IN_HSE 				2	

#define AFIO_RCC					0
#define GPIOA_RCC					2
#define GPIOB_RCC					3
#define GPIOC_RCC					4


#endif
