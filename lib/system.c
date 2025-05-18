#include "../lib/system.h"

void reboot() {
    // Tell the keyboard controller (0x64) to pulse the CPU reset line
    unsigned char good = 0xFE;
    __asm__ volatile("outb %0, %1" : : "a"(good), "Nd"(0x64));
}

