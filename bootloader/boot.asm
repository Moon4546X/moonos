section .multiboot
    align 4
    dd 0x1BADB002       ; Magic number
    dd 0x00             ; Flags
    dd - (0x1BADB002)   ; Checksum

section .text
    extern kmain
    global _start

_start:
    cli                 ; Disable interrupts
    call kmain
    hlt                 ; Halt CPU

