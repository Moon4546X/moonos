#ifndef STDIO_H
#define STDIO_H

#define VIDEO_MEMORY ((volatile unsigned char*) 0xB8000)

// Custom Function
void clear_screen();
void print_char(char c);
void print_string(const char* str);
void print(const char* str);

#endif // STDIO_H

