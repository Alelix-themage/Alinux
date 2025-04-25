# Defina os caminhos e variáveis
CC = gcc
LD = ld
AS = nasm
CFLAGS = -ffreestanding -O2 -Wall -Wextra -Ikernel -Ikernel/drivers/video -Ikernel/lib
LDFLAGS = -T linker.ld
KERNEL_NAME = alinux
ISO_NAME = alinux.iso

# Diretórios
OBJDIR = obj
ISODIR = iso
BOOTDIR = boot

# Arquivos fontes
KERNEL_SRC = \
    kernel/main.c \
    kernel/lib/String.c \
    kernel/drivers/video/vga.c

# Arquivos objetos
KERNEL_OBJ = $(KERNEL_SRC:%.c=$(OBJDIR)/%.o)

# Arquivo objeto do bootloader
BOOT_OBJ = $(OBJDIR)/boot/boot.o

# Arquivo de configuração do GRUB
GRUB_CFG = $(ISODIR)/boot/grub/grub.cfg

# Compilação de arquivos C
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<  

# Assembler do código de inicialização do bootloader
$(BOOT_OBJ): $(BOOTDIR)/boot.s
	@mkdir -p $(dir $@)
	$(AS) -f elf64 -o $@ $<

# Linkagem para criar o binário do kernel (incluindo o BOOT_OBJ)
$(OBJDIR)/$(KERNEL_NAME).bin: $(BOOT_OBJ) $(KERNEL_OBJ)
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -o $@ $^  

# Criar o diretório para o GRUB
$(ISODIR)/boot/grub:
	@mkdir -p $@              

# Criar o arquivo de configuração do GRUB
$(GRUB_CFG): $(BOOTDIR)/grub/grub.cfg
	@mkdir -p $(dir $@)
	cp $< $@

# Criar a imagem ISO com GRUB
$(ISODIR)/$(ISO_NAME): $(OBJDIR)/$(KERNEL_NAME).bin $(GRUB_CFG) $(ISODIR)/boot/grub
	@mkdir -p $(ISODIR)/boot     
	cp $(OBJDIR)/$(KERNEL_NAME).bin $(ISODIR)/boot/$(KERNEL_NAME).bin 
	grub-mkrescue -o $@ $(ISODIR) 

# Limpar arquivos temporários
clean:
	rm -rf $(OBJDIR) $(ISODIR) 

# Regra principal
all: $(ISODIR)/$(ISO_NAME)

# Regra padrão
.PHONY: all clean