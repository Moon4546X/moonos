#include "../lib/ports.h"
#include "../lib/stdio.h"

unsigned char keyboard_map[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n', 0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0,'\\',
    'z','x','c','v','b','n','m',',','.','/', 0,
    '*', 0,' ', 0, 
   
};

char get_char() {
    unsigned char scancode;

    
    while (1) {
        if (port_byte_in(0x64) & 0x01) { 
            scancode = port_byte_in(0x60);

            
            if (scancode < 128) {
                return keyboard_map[scancode];
            }
        }
    }
}

