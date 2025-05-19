#include "../drivers/keyboard.h"
#include "../lib/stdio.h"

void init_keyboard();

char get_char() {
    
    return 'A';
}

void read_input(char *buffer, int max_length) {
    int i = 0;
    char c;

    while (i < max_length - 1) {
        c = get_char(); 

        if (c == '\n') {
            break;
        }

        buffer[i++] = c;
        print_char(c); 
    }

    buffer[i] = '\0';
    print_char('\n');
}

