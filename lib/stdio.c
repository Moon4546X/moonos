// lib/stdio.c

#include "../lib/stdio.h"
#include "../lib/ports.h"  // If you're writing to VGA using outb()

#define VIDEO_MEMORY (char*)0xb8000
int cursor = 0;

void print(const char* str) {
    while (*str) {
        print_char(*str++);
    }
}

void print_char(char c) {
    volatile char* video = VIDEO_MEMORY;
    video[cursor * 2] = c;
    video[cursor * 2 + 1] = 0x07;
    cursor++;
}

