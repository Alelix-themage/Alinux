# Defina os caminhos e variáveis
CC = gcc
LD = ld
AS = nasm
CFLAGS = -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T linker.ld
KERNEL_NAME = alinux
ISO_NAME = alinux.iso

# Diretórios
OBJDIR = obj
ISODIR = iso

# Arquivos fontes
KERNEL_SRC = kernel/main.c kernel/vga.c

# Arquivos objetos
KERNEL_OBJ = $(KERNEL_SRC:%.c=$(OBJDIR)/%.o)

# Compilação de arquivos C
$(OBJDIR)/%.o: kernel/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Linkagem para criar o binário do kernel
$(OBJDIR)/$(KERNEL_NAME).bin: $(KERNEL_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

# Criar o bootloader (se necessário)
# Assembler de um código de inicialização do bootloader
$(OBJDIR)/boot.o: boot/boot.s
	$(AS) -f elf64 -o $@ $<

# Criar a imagem ISO com GRUB
$(ISODIR)/$(ISO_NAME): $(OBJDIR)/$(KERNEL_NAME).bin $(OBJDIR)/boot.o
	mkdir -p $(ISODIR)/boot/grub
	cp $(OBJDIR)/$(KERNEL_NAME).bin $(ISODIR)/boot/$(KERNEL_NAME).bin
	cp $(OBJDIR)/boot.o $(ISODIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISODIR)/$(ISO_NAME) $(ISODIR)

# Limpar arquivos temporários
clean:
	rm -rf $(OBJDIR) $(ISODIR)
