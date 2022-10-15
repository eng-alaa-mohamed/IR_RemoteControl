/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : August 26, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef	GPIO_PRIVATE_H	 
#define	GPIO_PRIVATE_H

				/* Register Addresses for Port A*/
#define GPIOA_CRL	*((uint32_t*)0x40010800)         /* Port configuration register low PIN0 to PIN7 */
#define GPIOA_CRH	*((uint32_t*)0x40010804)    		/* Port configuration register high PIN8 to PIN15 */
#define GPIOA_IDR  	*((uint32_t*)0x40010808)    		/*Port input data register*/
#define GPIOA_ODR  	*((uint32_t*)0x4001080C)			/*Port output data register*/

#define GPIOA_BSR 	*((uint32_t*)0x40010810)
#define GPIOA_BRR 	*((uint32_t*)0x40010814)
#define GPIOA_LCK 	*((uint32_t*)0x40010818)



                 /* Register Addresses for Port B*/
#define GPIOB_CRL	*((uint32_t*)0x40010C00)
#define GPIOB_CRH	*((uint32_t*)0x40010C04)
#define GPIOB_IDR  	*((uint32_t*)0x40010C08)    		/*Port input data register*/
#define GPIOB_ODR  	*((uint32_t*)0x40010C0C)			/*Port output data register*/

#define GPIOB_BSR 	*((uint32_t*)0x40010C10)
#define GPIOB_BRR 	*((uint32_t*)0x40010C14)
#define GPIOB_LCK 	*((uint32_t*)0x40010C18)



				/* Register Addresses for Port B*/
#define GPIOC_CRL	*((uint32_t*)0x40011000)
#define GPIOC_CRH	*((uint32_t*)0x40011004)
#define GPIOC_IDR  	*((uint32_t*)0x40011008)
#define GPIOC_ODR  	*((uint32_t*)0x4001100C)

#define GPIOC_BSR 	*((uint32_t*)0x40011010)
#define GPIOC_BRR 	*((uint32_t*)0x40011014)
#define GPIOC_LCK 	*((uint32_t*)0x40011018)









#endif
