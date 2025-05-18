#include "../lib/system.h"

void reboot() {
    
    unsigned char good = 0xFE;
    __asm__ volatile("outb %0, %1" : : "a"(good), "Nd"(0x64));
}

