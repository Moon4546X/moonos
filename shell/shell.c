#include "../lib/stdio.h"
#include "../lib/input.h"
#include "../lib/system.h"

void shell_loop() {
    char input[100];

    while (1) {
        print("> ");
        read_input(input, 100);

        if (input[0] == 'r') {
            print("Rebooting...\n");
            reboot();
        } else {
            print("Unknown command: ");
            print(input);
            print("\n");
        }
    }
}

