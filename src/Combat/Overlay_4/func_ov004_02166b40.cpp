#include <globaldefs.h>

extern "C" int func_ov023_021f6558(void* a, int b);
extern "C" void func_ov004_021660f4(void);
extern "C" void func_ov004_02165f2c(void);
extern "C" void func_ov004_02165ef4(void* a1);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct Struct_ov004_02166b40 {
    char pad[0x48];
    short unknown_48_;
    short count1;
    char pad2[4];
    unsigned char unknown_50_0_ : 6;
    unsigned char unknown_50_6_ : 1;
    unsigned char unknown_50_7_ : 1;
};
#if defined(jpn)
struct Struct_ov004_0217101c { unsigned int reserved; struct Struct_ov004_02166b40* value; };
extern Struct_ov004_0217101c data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c.value
#else
extern struct Struct_ov004_02166b40* data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c
#endif

// USA: func_ov004_02166b40
#pragma optimize_for_size off
extern "C" ARM int func_ov004_02166b40(void* a1) {
    struct Struct_ov004_02166b40* obj = CONTEXT_VALUE;
    int r = func_ov023_021f6558(a1, 0x5a);
    short val;
    if (r != 0xb4 && r == 0xb5) {
        obj->unknown_50_6_ = 1;
        obj->unknown_50_7_ = 1;
        val = obj->count1;
    } else {
        obj->unknown_50_6_ = 0;
        obj->unknown_50_7_ = 1;
        val = obj->unknown_48_;
    }

    if (val != 0) {
        func_ov004_021660f4();
        func_ov004_02165f2c();
        func_ov004_02165ef4(a1);
        func_ov011_021848a0(a1, 0x12d);
    } else {
        func_ov011_021848a0(a1, 0x66);
    }
    return 0;
}
