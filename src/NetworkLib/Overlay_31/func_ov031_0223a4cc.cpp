#include <globaldefs.h>

extern "C" void func_ov031_02238694(void* p);
extern "C" void func_ov031_0223b07c(void);
extern "C" int func_ov031_0221aff8(int v);
extern "C" int func_ov031_02236474(void);
unsigned long long GetCurrentTimestamp(void);
extern unsigned char* data_ov031_02290d20;

struct Struct_ov031_0223a4cc { int a; int b; int c; int d; int e; int f; unsigned char g; };

// USA: func_ov031_0223a4cc
extern "C" ARM void func_ov031_0223a4cc(void* p0, struct Struct_ov031_0223a4cc* src) {
    data_ov031_02290d20 = (unsigned char*)p0;
    func_ov031_02238694((char*)p0 + 0xb00);
    *(unsigned short*)(data_ov031_02290d20 + 0x648) = 0;
    *(unsigned short*)(data_ov031_02290d20 + 0x64a) = 0;
    data_ov031_02290d20[0xa90] = 1;
    data_ov031_02290d20[0xa91] = 1;
    *(int*)(data_ov031_02290d20 + 0xa9c) = 0;
    func_ov031_0223b07c();
    *(int*)(data_ov031_02290d20 + 0xab4) = src->a;
    *(int*)(data_ov031_02290d20 + 0xab8) = src->b;
    *(int*)(data_ov031_02290d20 + 0xabc) = src->c;
    *(int*)(data_ov031_02290d20 + 0xac0) = src->d;
    *(int*)(data_ov031_02290d20 + 0xac4) = src->e;
    *(int*)(data_ov031_02290d20 + 0xac8) = src->f;
    data_ov031_02290d20[0xa92] = src->g;
    data_ov031_02290d20[0xacc] = 2;
    GetCurrentTimestamp();
    func_ov031_0221aff8((int)(data_ov031_02290d20 + 0x24c + 0x400));
    GetCurrentTimestamp();
    *(int*)(data_ov031_02290d20 + 0xaa4) = func_ov031_02236474();
}
