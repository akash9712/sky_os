OUTPUT_FORMAT("binary")
ENTRY(_start)
addr = 0x0001000;
SECTIONS
{
    .text addr : AT(addr) {
        code = .;
        *(.text)
        *(.rodata)
        . = ALIGN(4096);
    }
    .data : AT(addr + (data - code))
    {
        data = .;
        *(.data)
        . = ALIGN(4096);
    }
    .bss : AT(addr + (bss - code))
    {
        bss = .;
        *(.bss)
        . = ALIGN(4096);
    }
    end = .;
    /DISCARD/ :
    {
        *(.comment)
        *(.eh_frame)
    }
}

