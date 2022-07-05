#include <stdint.h>
extern uint32_t STACK_TOP;
extern void main();
void Reset_handler(void);

void Default_handler(){
	Reset_handler();
}

void NMI_handler() __attribute__((weak,alias("Default_handler")));
void HardFault_handler() __attribute__((weak,alias("Default_handler")));
void MMFault_handler() __attribute__((weak,alias("Default_handler")));
void BusFault_handler() __attribute__((weak,alias("Default_handler")));
void UsageFault_handler() __attribute__((weak,alias("Default_handler")));

uint32_t vector [] __attribute__((section(".vectors")))= {
	(uint32_t) &STACK_TOP,
	(uint32_t) &Reset_handler,
	(uint32_t) &NMI_handler,
	(uint32_t) &HardFault_handler,
	(uint32_t) &MMFault_handler,
	(uint32_t) &BusFault_handler,
	(uint32_t) &UsageFault_handler
};
uint32_t i;
extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

void Reset_handler(void){
	/*copying .data from Flash to RAM*/
	uint32_t _data_size = (uint8_t*)&_E_data - (uint8_t*)&_S_data;
	uint8_t *ptr_scr = &_E_text;
	uint8_t *ptr_dest = &_S_data;
	for(i=0 ; i< _data_size ; i++)
	{
		*((uint8_t*)ptr_dest++) = *((uint8_t*)ptr_scr++);
	}
	
	/*create .bss section*/
	uint32_t _bss_size = (uint8_t*)&_E_bss - (uint8_t*)&_S_bss;
	ptr_dest = &_S_data;
	for(i=0 ; i< _data_size ; i++)
	{
		*((uint8_t*)ptr_dest++) = (uint8_t*)0;
	}
	
	/*branching to main*/
	main();
}


