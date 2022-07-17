MEMORY
{
	Flash (RX) : ORIGIN = 0x08000000 ,LENGTH = 128K
	SRAM (RWX): ORIGIN = 0x20000000 ,LENGTH = 20K
}

SECTIONS
{
	.text :{
	*(.vectors*)
	*(.text*)
	*(.rodata*)
	_E_text = .;
	}>Flash
	
	.data :{
	_S_data = .;
	*(.data*)
	_E_data = .;
	}>SRAM AT> Flash

	.bss :{
	_S_bss = .;
	*(.bss*)
	_E_bss = .;
	. = ALIGN(4);
	. = . + 1000;
	STACK_TOP = .;
	}>SRAM
}
