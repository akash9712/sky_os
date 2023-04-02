ENTRY(_start)
OUTPUT_FORMAT("binary")
SECTIONS
{
	. = 0x1000;
	.text : { *(.txt) }

	. = 0x2000;
	.bss : { *(.bss) }

	. = 0x3000;
	.data : { *(.data) }
}
