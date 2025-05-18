# Directories
BUILD_DIR = build
ISO_DIR = isodir

# Compiler and flags
CC = gcc
CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra
LD = ld
LDFLAGS = -m elf_i386

# Source files
SOURCES = \
	bootloader/boot.asm \
	kernel/kernel.c \
	lib/stdio.c \
	lib/string.c \
	lib/input.c \
	lib/system.c \
	shell/shell.c

# Object files (auto-generated)
OBJECTS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(filter %.c, $(SOURCES)))
ASM_OBJECTS = $(patsubst %.asm, $(BUILD_DIR)/%.o, $(filter %.asm, $(SOURCES)))

# Kernel binary
KERNEL = $(BUILD_DIR)/kernel.bin

# ISO file
ISO = moonos.iso

all: $(ISO)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.asm
	mkdir -p $(dir $@)
	nasm -f elf32 $< -o $@

$(KERNEL): $(ASM_OBJECTS) $(OBJECTS)
	$(LD) $(LDFLAGS) -T linker.ld -o $@ $(ASM_OBJECTS) $(OBJECTS)

$(ISO): $(KERNEL)
	mkdir -p $(ISO_DIR)/boot
	cp $(KERNEL) $(ISO_DIR)/boot/kernel.bin
	grub-mkrescue -o $@ $(ISO_DIR)

clean:
	rm -rf $(BUILD_DIR) $(ISO_DIR) $(ISO)

run: all
	qemu-system-i386 -cdrom $(ISO)
