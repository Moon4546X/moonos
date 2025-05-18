#include "../drivers/keyboard.h"
#include "../lib/stdio.h"

void read_input(char *buffer, int max_length) {
    int i = 0;
    char c;

    while (i < max_length - 1) {
        c = get_char(); // Blocks until a key is pressed

        if (c == '\n') {
            break;
        }

        buffer[i++] = c;
        print_char(c); // Echo to screen
    }

    buffer[i] = '\0';
    print_char('\n');
}

