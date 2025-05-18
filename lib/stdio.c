#include "stdio.h"

void clear_screen() {
    
    volatile unsigned char* video_memory = VIDEO_MEMORY;
    for (int i = 0; i < 80 * 25; i++) {
        video_memory[i * 2] = ' '; 
        video_memory[i * 2 + 1] = 0x07; 
    }
}

void print_char(char c) {
    
    volatile unsigned char* video_memory = VIDEO_MEMORY;
    static int cursor_x = 0;
    static int cursor_y = 0;

    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        video_memory[cursor_y * 80 * 2 + cursor_x * 2] = c;
        video_memory[cursor_y * 80 * 2 + cursor_x * 2 + 1] = 0x07; 
        cursor_x++;
    }

    if (cursor_x >= 80) {
        cursor_x = 0;
        cursor_y++;
    }
}

void print_string(const char* str) {
    while (*str) {
        print_char(*str++);
    }
}
void print(const char* str) {
    print_string(str); 
}
