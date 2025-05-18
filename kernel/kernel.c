#include "../lib/stdio.h"
#include "../shell/shell.h"

void kmain() {
    clear_screen();
    print("🌙 Welcome to MoonOS v0.1\n");
    shell_loop();
}

