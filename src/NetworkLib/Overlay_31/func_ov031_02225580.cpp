#include <globaldefs.h>

struct Struct_ov031_02225580_2 { int a; int b; };
struct Struct_ov031_02222ddc_6 { int pad0, pad1; Struct_ov031_02225580_2* arr; };
extern "C" Struct_ov031_02225580_2* func_ov031_0223baa0(Struct_ov031_02222ddc_6* obj, int idx);

struct Struct_ov031_02225580 { unsigned char pad[0xfc]; Struct_ov031_02222ddc_6* unknown_fc_; };
extern Struct_ov031_02225580* data_ov031_02250bfc;

struct Struct_ov031_02225580_3 { int v; };
struct Struct_ov031_02225580_4 { int v; };
extern "C" void func_ov031_02224ca4(int a, int idx, struct Struct_ov031_02225580_3 off, struct Struct_ov031_02225580_4 hi);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225604(void* obj);

// USA: func_ov031_02225580
extern "C" ARM void func_ov031_02225580(void* obj) {
    Struct_ov031_02225580_2* elem = func_ov031_0223baa0(data_ov031_02250bfc->unknown_fc_, 0);
    int val = elem->a;
    Struct_ov031_02225580* e = data_ov031_02250bfc;
    unsigned char var3 = *((unsigned char*)e + 0x11d);
    struct Struct_ov031_02225580_4 hi;
    struct Struct_ov031_02225580_3 off;
    hi.v = (unsigned int)(val & 0x1ff0000) >> 0x10;
    off.v = (val & 0xff) + 0xc;
    func_ov031_02224ca4(var3, 4, off, hi);
    if (off.v < 0xc0) return;
    func_ov031_0223e2b8(obj, (int)func_ov031_02225604);
}
