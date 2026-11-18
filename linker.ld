ENTRY(_start)

SECTIONS
{
    . = 0x40000000;

    .text :
    {
        KEEP(*(.text.boot))
        *(.text*)
    }

    .rodata :
    {
        *(.rodata*)
    }

    .data :
    {
        *(.data*)
    }

    .bss (NOLOAD) :
    {
        *(.bss*)
        *(COMMON)
        . = ALIGN(16);
        _stack_bottom = .;
        . += 0x4000;
        _stack_top = .;
    }
}
