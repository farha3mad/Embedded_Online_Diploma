MEMORY
{
	Flash (RX) : ORIGIN = 0x00000000 ,LENGTH = 512M
	SRAM (RWX): ORIGIN = 0x20000000 ,LENGTH = 512M
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
	}>SRAM
}