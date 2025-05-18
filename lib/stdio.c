#include "../lib/stdio.h"

static int cursor = 0;

void print(const char *str) {
    while (*str) {
        VIDEO_MEMORY[cursor++] = *str++;        // Character
        VIDEO_MEMORY[cursor++] = 0x07;          // Light grey on black
    }
}

void clear_screen() {
    for (int i = 0; i < MAX_ROWS * MAX_COLS * 2; i++) {
        VIDEO_MEMORY[i] = 0;
    }
    cursor = 0;
}

