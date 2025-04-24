ENTRY(kernel_main)

SECTIONS {
    /* Colocando a seção .multiboot no início da memória */
    . = 1M;
    
    .multiboot : {
        /* Cabeçalho multiboot */
        *(.multiboot)
    }

    .text : {
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(.bss*)
        *(COMMON)
    }
}
