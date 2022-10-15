/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : August 26, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/*Options:			RCC_HSE_CRYSTAL
					RCC_HSE_RC
					RCC_HSI
					RCC_PLL				*/
					
#define RCC_CLOCK_TYPE		RCC_HSE_CRYSTAL




/* Options          RCC_PLL_IN_HSI_DIV_2
				    RCC_PLL_IN_HSE_DIV_2
					RCC_PLL_IN_HSE          */
/* Note: Select value only if have PLL as input clock source */

#if RCC_CLOCK_TYPE == RCC_PLL				
#define RCC_PLL_INPUT	 	RCC_PLL_IN_HSE
#endif

/* Options 2 to 16 */
#if RCC_CLOCK_TYPE == RCC_PLL	
#define RCC_PLL_MUL_VAL		4
#endif


#endif