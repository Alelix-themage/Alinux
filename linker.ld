ENTRY(kernel_main)

MEMORY {
    CODE (rx)   : ORIGIN = 0x100000, LENGTH = 512M  /* Endereço e tamanho para o código executável */
    RO   (r)    : ORIGIN = 0x200000, LENGTH = 256M  /* Dados somente leitura */
    DATA (rw)   : ORIGIN = 0x300000, LENGTH = 128M  /* Dados inicializados */
    BSS  (rw)   : ORIGIN = 0x400000, LENGTH = 128M  /* Dados não inicializados */
}

SECTIONS {
    . = 1M;

    .multiboot : {
        *(.multiboot)  /* Cabeçalho multiboot */
    }

    .text : {
        *(.text*)      /* Código executável */
    } > CODE

    .rodata : {
        *(.rodata*)    /* Dados somente leitura */
    } > RO

    .data : {
        *(.data*)      /* Dados inicializados */
    } > DATA

    .bss : {
        *(.bss*)       /* Dados não inicializados */
        *(COMMON)
    } > BSS
}