# MoonOS
A cli-based lightweight operating system written in assembly and c, inspired by linux and templeos
```
  __  __                    ___  ____  
 |  \/  | ___   ___  _ __  / _ \/ ___| 
 | |\/| |/ _ \ / _ \| '_ \| | | \___ \ 
 | |  | | (_) | (_) | | | | |_| |___) |
 |_|  |_|\___/ \___/|_| |_|\___/|____/ 
```

![image](https://github.com/user-attachments/assets/e3a3afb8-1885-4ca6-bc6a-d12c8641d9d8)



# Structure (v0.2)
```
moonos/
├── bootloader/         
│   └── boot.asm
├── kernel/              
│   └── kernel.c
├── lib/                
│   ├── stdio.c
│   ├── stdio.h
│   ├── string.c
│   ├── string.h
│   ├── input.c
│   ├── input.h
│   ├── system.c
│   └── system.h
│   ├── ports.c
│   └── ports.h
├── shell/               
│   └── shell.c
│   └── shell.h
├── linker.ld           
├── Makefile             
├── iso/                 
├── build/
|   ├─── bootloader/
|   |      └── boot.o
|   ├─── drivers/
|   |      └── keyboard.o
|   ├─── kernel/
|   |      └── kernel.o
|   ├─── lib/
|   |      ├─── input.o
|   |      ├─── ports.o
|   |      ├─── stdio.o
|   |      ├─── string.o
|   |      └─── system.o
|   |      
|   ├─── shell/
|   |      └─── shell.o
|   └─── kernel.bin
├── cpu/
├── drivers/                
│   ├── idt.c
│   ├── idt.h
│   ├── keyboard.c
│   └── keyboard.h
└── isodir/
    ├─── boot/
    |      └── grub/
    |           └── grub.cfg
    └─── kernel.bin
```
