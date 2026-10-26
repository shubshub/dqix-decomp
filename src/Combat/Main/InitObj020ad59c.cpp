#include <globaldefs.h>

extern "C" void GameObject_Initialize(void* p);

// USA: func_020ad59c
ARM void InitObj020ad59c(void* param0) {
    char* base = (char*)param0;
    GameObject_Initialize(param0);
    *(int*)(base + 0x134) = 0;
    *(int*)(base + 0x138) = 0;
    *(unsigned short*)(base + 0x14c) = 0;
    *(int*)(base + 0x150) = 0;
    *(int*)(base + 0x160) = 0;
    *(int*)(base + 0x13c) = 0;
    *(int*)(base + 0x140) = 0;
    *(int*)(base + 0x144) = 0x1eb;
    *(int*)(base + 0x148) = 0xcc;
    *(int*)(base + 0x154) = 0;
    *(int*)(base + 0x158) = 0;
    *(int*)(base + 0x15c) = 0;
    *(int*)(base + 0x164) = 0;
    *(int*)(base + 0x168) = 0;
    *(int*)(base + 0x16c) = 0;
    *(int*)(base + 0x174) = 0;
    *(int*)(base + 0x178) = 0;
    *(int*)(base + 0x17c) = 0;
    *(int*)(base + 0x170) = 0;
    *(int*)(base + 0x180) = 0;
    *(unsigned char*)(base + 0x1a2) = 1;
    *(int*)(base + 0x130) = 0;
}
