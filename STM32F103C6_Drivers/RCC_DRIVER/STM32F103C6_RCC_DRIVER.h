/*****************************************************************/
/* Author      : Farha Emad                                      */
/* Date        : 20 April 2023                                   */      
/*****************************************************************/

#ifndef	STM32F103C6_RCC_DRIVER_H
#define STM32F103C6_RCC_DRIVER_H

//MACROS for Clock System
#define 		HSE_CLOCK		(uint32_t)16000000
#define 		HSI_CLOCK		(uint32_t)8000000

 
uint32_t MCAL_RCC_GetSYSCLK_Freq();
uint32_t MCAL_RCC_GetHCLK_Freq();
uint32_t MCAL_RCC_GetPCLK1_Freq();
uint32_t MCAL_RCC_GetPCLK2_Freq();

#endif
