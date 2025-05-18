#ifndef STDIO_H
#define STDIO_H

#define VIDEO_MEMORY ((volatile unsigned char*) 0xB8000)
#define MAX_ROWS 25
#define MAX_COLS 80

void print(const char *str);
void clear_screen();

#endif

