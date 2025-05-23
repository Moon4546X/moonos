#ifndef IDT_H
#define IDT_H

#include <stdint.h>

#define IDT_ENTRIES 256


typedef struct {
    uint16_t base_lo;   
    uint16_t sel;      
    uint8_t  always0;   
    uint8_t  flags;     
    uint16_t base_hi;   
} __attribute__((packed)) idt_entry_t;


typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_ptr_t;

void idt_init(void);
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

#endif 

