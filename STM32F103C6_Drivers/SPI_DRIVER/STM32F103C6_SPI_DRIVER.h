/*****************************************************************/
/* Author      : Farha Emad                                      */
/* Date        : 30 April 2023                                   */      
/*****************************************************************/

#ifndef	STM32F103C6_SPI_DRIVER_H
#define STM32F103C6_SPI_DRIVER_H

#include "stm32f103x6.h"
#include "STM32F103C6_RCC_DRIVER.h"
#include "STM32F103C6_USART_DRIVER.h"
#include "STM32F103C6_GPIO_Driver.h"

struct IRQ_Source
{
	uint8_t	TXEIE:1;
	uint8_t	RXNEIE:1;
	uint8_t	ERRIE:1;
	uint8_t	Reserved:5;

};

typedef struct{

	uint16_t 		SPI_MODE;					//specifies Master/Slave operating mode
												//This parameter must be set from @ref SPI_MODE_define

	uint16_t 		SPI_Communication;			//specifies SPI BI-direction communication mode
												//This parameter must be set from @ref SPI_COMMUNICATION_define

	uint16_t 		SPI_Frame_Size;	        	//specifies SPI 8- or 16-bit transfer frame format selection
										    	//This parameter must be set from @ref SPI_FRAME_SIZE_define

	uint16_t 		SPI_Data_Order;	   			//specifies SPI data order with MSB-first or LSB-first shifting
												//This parameter must be set from @ref SPI_DATA_ORDER_define

	uint16_t 		SPI_NSS;		        	//specifies SPI NSS pin management by: Hardware or Software
												//This parameter must be set from @ref SPI_NSS_define

	uint16_t 		SPI_Baud_Rate_Prescaler;	//specifies SPI baud rate prescalers
												//This parameter must be set from @ref SPI_BAUD_RATE_PRE_define

	uint16_t 		SPI_Clock_Polarity;			//specifies SPI Clock Polarity
												//This parameter must be set from @ref SPI_CLOCK_POLARITY_define

	uint16_t 		SPI_Clock_Phase;			//specifies Clock Phase
												//This parameter must be set from @ref SPI_CLOCK_PHASE_define

	uint16_t 		SPI_IRQ;					//specifies SPI interrupts enable
												//This parameter must be set from @ref SPI_IRQ_ENABLE_define

	void (* P_IRQ_CallBack) (struct IRQ_Source);//Set the C function to be called once the interrupt happen

}SPI_config;


//---------------------------------
//Macros Configuration References
//---------------------------------

//@ref SPI_MODE_define
#define 	SPI_MODE_SLAVE						(0)
#define 	SPI_MODE_MASTER						(1<<2)


//@ref SPI_COMMUNICATION_define
#define 	SPI_COMMUNICATION_2LINES			(0) //Bit 10 RXONLY: Receive only .. Full duplex (Transmit and receive)
#define 	SPI_COMMUNICATION_2LINES_RXONLY		(1<<10)	//Bit 10 RXONLY: Receive only .. Output disabled (Receive-only mode)
#define 	SPI_COMMUNICATION_1LINE_TXONLY		(1<<15 | 1<<14) //Bit 15 BIDIMODE: Bidirectional data mode enable & Bit 14 BIDIOE: Output enable in bidirectional mode
#define 	SPI_COMMUNICATION_1LINE_RXONLY		(1<<15) //Bit 15 BIDIMODE: Bidirectional data mode enable

//@ref SPI_FRAME_SIZE_define
//Bit 11 DFF: Data frame format
#define 	SPI_FRAME_SIZE_8					(0)
#define 	SPI_FRAME_SIZE_16					(1<<11)

//@ref SPI_DATA_ORDER_define
//Bit 7 LSBFIRST: Frame format
#define 	SPI_DATA_ORDER_LSBFIRST				(1<<7)
#define 	SPI_DATA_ORDER_MSBFIRST				(0)

//@ref SPI_CLOCK_POLARITY_define
//Bit1 CPOL: Clock polarity
#define 	SPI_CLOCK_POLARITY_IDLE_LOW			(0)
#define 	SPI_CLOCK_POLARITY_IDLE_HIGH		(1<<1)

//@ref SPI_CLOCK_PHASE_define
//Bit 0 CPHA: Clock phase
#define 	SPI_CLOCK_PHASE_CAPTURE_FIRST		(0)
#define 	SPI_CLOCK_PHASE_SAMPLING_FIRST		(1<<0)

//@ref SPI_BAUD_RATE_PRE_define
//Bits 5:3 BR[2:0]: Baud rate control
#define 	SPI_BAUD_RATE_PRE_2					(0b000 << 3)
#define 	SPI_BAUD_RATE_PRE_4					(0b001 << 3)
#define 	SPI_BAUD_RATE_PRE_8					(0b010 << 3)
#define 	SPI_BAUD_RATE_PRE_16				(0b011 << 3)
#define 	SPI_BAUD_RATE_PRE_32				(0b100 << 3)
#define 	SPI_BAUD_RATE_PRE_64				(0b101 << 3)
#define 	SPI_BAUD_RATE_PRE_128				(0b110 << 3)
#define 	SPI_BAUD_RATE_PRE_256				(0b111 << 3)

//@ref SPI_IRQ_ENABLE_define
#define 	SPI_IRQ_ENABLE_NONE					(0)
#define 	SPI_IRQ_ENABLE_TXEIE				(1 << 7)
#define 	SPI_IRQ_ENABLE_RXNEIE				(1 << 6)
#define 	SPI_IRQ_ENABLE_ERRIE				(1 << 5)


//@ref SPI_NSS_define
//Hardware
#define 	SPI_NSS_HARDWARE_MASTER_OUTPUT		(1<<2) //Bit 2 SSOE: SS output enable
#define 	SPI_NSS_HARDWARE_MASTER_INPUT		~(1<<2)
#define 	SPI_NSS_HARDWARE_SLAVE_INPUT		(0)

//Software
#define 	SPI_NSS_SOFTWARE_ENABLE_HIGH		(1<<9 | 1 << 8) //Bit 9 SSM: Software slave management (Master or Slave) & Bit 8 SSI: Internal slave select
#define 	SPI_NSS_SOFTWARE_ENABLE_LOW		    (1<<9) //Bit 9 SSM: Software slave management (Master or Slave)

//---------------------------------
//APIs
//---------------------------------

void MCAL_SPI_init(SPI_TypeDef * SPIx , SPI_config * SPI_conf );
void MCAL_SPI_deinit(SPI_TypeDef * SPIx);

void MCAL_GPIO_SPI_SetPins(SPI_TypeDef *SPIx);
void MCAL_SPI_SendData(SPI_TypeDef *SPIx , uint16_t *data_buffer , enum polling poll);
void MCAL_SPI_ReceiveData(SPI_TypeDef *SPIx , uint16_t *data_buffer , enum polling poll);



#endif
