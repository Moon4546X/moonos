# Directories
BUILD_DIR := build
ISO_DIR := isodir
GRUB_DIR := $(ISO_DIR)/boot/grub

# Tools
CC := gcc
LD := ld
NASM := nasm
GRUB_MKRESCUE := grub-mkrescue
QEMU := qemu-system-i386

# Flags
CFLAGS := -m32 -ffreestanding -O2 -Wall -Wextra -I. -Iinclude -Icpu -Idrivers -Ilib
LDFLAGS := -m elf_i386

# Sources
C_SOURCES := \
	kernel/kernel.c \
	lib/stdio.c \
	lib/string.c \
	lib/input.c \
	lib/system.c \
	lib/ports.c \
	shell/shell.c \
	drivers/keyboard.c \
	

ASM_SOURCES := \
	bootloader/boot.asm

# Object files
OBJECTS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(C_SOURCES))
ASM_OBJECTS := $(patsubst %.asm, $(BUILD_DIR)/%.o, $(ASM_SOURCES))

# Targets
KERNEL := $(BUILD_DIR)/kernel.bin
ISO := moonos.iso

# Default
all: $(ISO)

# Compile C source
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "🧠 Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble ASM source
$(BUILD_DIR)/%.o: %.asm
	@mkdir -p $(dir $@)
	@echo "⚙️ Assembling $<"
	$(NASM) -f elf32 $< -o $@

# Link kernel
$(KERNEL): $(ASM_OBJECTS) $(OBJECTS)
	@echo "🔗 Linking kernel..."
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -T linker.ld -o $@ $(ASM_OBJECTS) $(OBJECTS)
	@echo "✅ Kernel linked at $@"

# Build ISO
$(ISO): $(KERNEL)
	@echo "📦 Creating bootable ISO..."
	@mkdir -p $(GRUB_DIR)
	cp $(KERNEL) $(ISO_DIR)/boot/kernel.bin
	echo 'set timeout=0' > $(GRUB_DIR)/grub.cfg
	echo 'set default=0' >> $(GRUB_DIR)/grub.cfg
	echo 'menuentry \"MoonOS\" {' >> $(GRUB_DIR)/grub.cfg
	echo '  multiboot /boot/kernel.bin' >> $(GRUB_DIR)/grub.cfg
	echo '  boot' >> $(GRUB_DIR)/grub.cfg
	echo '}' >> $(GRUB_DIR)/grub.cfg
	$(GRUB_MKRESCUE) -o $@ $(ISO_DIR)
	@echo "🚀 ISO ready: $@"

# Run in QEMU
run: all
	@echo "💻 Launching MoonOS in QEMU..."
	$(QEMU) -cdrom $(ISO)

# Debugging option
debug: CFLAGS += -g
debug: all

# Clean build
clean:
	@echo "🧹 Cleaning build artifacts..."
	rm -rf $(BUILD_DIR) $(ISO_DIR) $(ISO)
	@echo "✅ Clean complete"

.PHONY: all clean run debug

