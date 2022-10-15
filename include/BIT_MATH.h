/***************************************************************************************/
/*** Author            : Alaa Mohamed                                                 **/
/*** Date              : August 26, 2022                                              **/
/*** Version           : 1.0													     **/
/***************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)		VAR |=  (1 << (BIT))       //left shift 1 by number of bit, then OR operatiom - set means OR operation
#define CLR_BIT(VAR,BIT)  		VAR &= ~(1 << (BIT))	  //AND it with zero and AND the other with Ones
#define GET_BIT(VAR,BIT)    	( (VAR >> BIT) & 1 )      //RETUEN value of this bit - Right shift the value then and it with zero so all bits will be zero except the bit will be one
#define TOG_BIT(VAR,BIT)        VAR ^=  (1 << (BIT))      //XOR

#endif
