#include "../lib/input.h"
#include "../lib/stdio.h"

// Dummy function for now — real keyboard input needs interrupts
void read_input(char* buffer, int max_len) {
    // Just fill buffer with a placeholder for now
    const char* dummy = "hello";
    int i = 0;
    while (dummy[i] && i < max_len - 1) {
        buffer[i] = dummy[i];
        i++;
    }
    buffer[i] = '\0';
}

