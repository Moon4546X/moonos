#include "idt.h"

#define KERNEL_CS 0x08  
static idt_entry_t idt_entries[IDT_ENTRIES];
static idt_ptr_t idt_ptr;

extern void idt_flush(uint32_t);

static void set_idt_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt_entries[num].base_lo = base & 0xFFFF;
    idt_entries[num].sel = sel;
    idt_entries[num].always0 = 0;
    idt_entries[num].flags = flags;
    idt_entries[num].base_hi = (base >> 16) & 0xFFFF;
}

void idt_init(void) {
    idt_ptr.limit = (sizeof(idt_entry_t) * IDT_ENTRIES) - 1;
    idt_ptr.base = (uint32_t)&idt_entries;

        for (int i = 0; i < IDT_ENTRIES; i++) {
        set_idt_gate(i, 0, 0, 0);
    }

    
    idt_flush((uint32_t)&idt_ptr);
}

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    set_idt_gate(num, base, sel, flags);
}

