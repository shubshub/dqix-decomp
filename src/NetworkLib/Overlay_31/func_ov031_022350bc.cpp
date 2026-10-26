#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(int size, int align);

struct Struct_ov031_022350bc_2 { unsigned short a; unsigned short b; };
extern "C" void func_ov031_0223cb10(unsigned short a, unsigned short b, Struct_ov031_022350bc_2* out);

extern "C" int func_ov031_0223be70(int, int, int);
extern unsigned char data_ov031_022491f0[];

extern "C" void func_ov031_0223bbd8(void*, int, int, int);

struct Struct_ov031_02222ce4;
extern "C" ARM void func_ov031_0223bcc8(Struct_ov031_02222ce4*, int, int);

extern "C" ARM void* func_ov031_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_02235234(void);

struct Struct_ov031_022350bc {
    int field0;
    unsigned char pad0[0xc - 0x4];
    int fieldc;
    unsigned char pad1[0x19 - 0x10];
    unsigned char unknown_19_;
    unsigned char unknown_1a_;
    unsigned char unknown_1b_;
};
extern Struct_ov031_022350bc* data_ov031_02290cf4;

// USA: func_ov031_022350bc
extern "C" ARM void func_ov031_022350bc(int a, int b, unsigned short c, unsigned short d, int e) {
    data_ov031_02290cf4 = (Struct_ov031_022350bc*)func_ov031_0223cf4c(0x20, 4);
    data_ov031_02290cf4->unknown_1b_ = (unsigned char)a;
    data_ov031_02290cf4->unknown_19_ = (unsigned char)b;
    data_ov031_02290cf4->unknown_1a_ = (unsigned char)e;
    func_ov031_0223cb10((unsigned short)c, (unsigned short)d, (Struct_ov031_022350bc_2*)((char*)data_ov031_02290cf4 + 0x10));
    data_ov031_02290cf4->field0 = func_ov031_0223be70(0, data_ov031_022491f0[a], 1);
    func_ov031_0223bbd8((void*)data_ov031_02290cf4->field0, -1, c, d + e);
    func_ov031_0223bcc8((Struct_ov031_02222ce4*)data_ov031_02290cf4->field0, -1, 1);
    data_ov031_02290cf4->fieldc = (int)func_ov031_0223e218(0, (void*)func_ov031_02235234, 0, 0x80);
}
