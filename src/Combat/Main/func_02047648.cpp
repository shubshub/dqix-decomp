#include <globaldefs.h>

extern "C" void func_02047718(void* obj, void* entry, int something);

struct Struct_02047648 {
    unsigned char unknown_0_;
    unsigned char pad1;
    unsigned char count;
    unsigned char pad3;
    unsigned char* unknown_4_;
};

struct Struct_02047648_2 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char rest : 6;
};

// USA: func_02047648
extern "C" ARM void func_02047648(unsigned char* obj, int idx, int something) {
    struct Struct_02047648_2* flags = (struct Struct_02047648_2*)(obj + 0x84);
    if (!flags->bit0) return;
    if (!flags->unknown_0_1_) return;
    if (*(short*)(obj + 0x82) <= 0) return;

    struct Struct_02047648* entry = ((struct Struct_02047648*)(*(unsigned char**)(obj + 0x8))) + idx;
    if (entry->unknown_4_ == NULL || entry->count == 0) return;

    volatile int* reg = (volatile int*)0x4000444;
    *reg = 0;
    *(volatile int*)((char*)reg + 0x7c) = 0x7fffffff;
    *(volatile int*)((char*)reg + 0x80) = 0x4210;
    *(volatile int*)((char*)reg + 0x2c) = -(int)(entry->unknown_0_ << 12) >> 1;
    *(volatile int*)((char*)reg + 0x2c) = 0;
    *(volatile int*)((char*)reg + 0x2c) = 0;

    unsigned char* p = entry->unknown_4_;
    int i;
    for (i = 0; i < entry->count; ) {
        func_02047718(obj, p, something);
        i++;
        p += 8;
    }
    *(volatile int*)0x4000448 = 1;
}
