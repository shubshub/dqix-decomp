#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov025_021e88d8 {
    int a;
    short b;
    short c;
    unsigned char d;
    unsigned char e;
};

struct Struct_ov000_0216fe48;

extern int data_ov025_021ef990;

extern "C" void func_ov025_021ebab4(char* obj);
extern "C" void func_ov025_021ed124(unsigned char* obj);
extern "C" void func_ov000_0216fe48(struct Struct_ov000_0216fe48* obj);
extern "C" void func_ov025_021e8a20(struct Struct_ov025_021e88d8* obj);

// USA: func_ov025_021e88d8
extern "C" ARM void func_ov025_021e88d8(void* arg) {
    char* obj = (char*)arg;

    *(int*)(obj + 0) = 0;
    *(int*)(obj + 4) = 0;
    data_ov025_021ef990 = 0;

    for (int i = 0; i < 4; i++) {
        *(int*)(obj + 0x10 + i * 4) = 0;
        *(int*)(obj + 0x20 + i * 4) = 0;
    }

    for (int i = 0; i < 3; i++) {
        SafeAllocator* alloc = (SafeAllocator*)(obj + 0x34) + i;
        alloc->ResetAllocatorPointer();
        void* other = obj + 0x70 + i * 0x70;
        *(int*)(obj + 0x10 + (i + 1) * 4) = (int)alloc;
        *(int*)(obj + 0x20 + (i + 1) * 4) = (int)other;
    }

    obj[0x30] = 0;
    *(int*)(obj + 0x1d8) = 0;
    *(short*)(obj + 0x21c) = 1;
    *(short*)(obj + 0x21e) = 0;
    *(int*)(obj + 0x224) = 0;
    func_ov025_021ebab4(obj + 0x22c);

    func_ov025_021ed124((unsigned char*)(obj + 0x5e8));

    func_ov000_0216fe48((struct Struct_ov000_0216fe48*)(obj + 0x798));

    obj[0x83c] = 0;
    obj[0x87c] = 0;
    *(int*)(obj + 0x880) = -1;
    *(int*)(obj + 0x884) = 0;
    *(short*)(obj + 0x57c) = 0;
    *(short*)(obj + 0x57e) = 0;
    *(short*)(obj + 0x580) = 0x333;
    obj[0x582] = 0;

    struct Struct_ov025_021e88d8* p = (struct Struct_ov025_021e88d8*)(obj + 0x594);
    for (unsigned char i = 0; i < 4; i++, p++) {
        func_ov025_021e8a20(p);
    }

    obj[0x5c5] = 0;
    obj[0x5c6] = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x228) = 0;
    *(short*)(obj + 0x5c8) = 0xff;
    *(short*)(obj + 0x5ce) = 0;
}
