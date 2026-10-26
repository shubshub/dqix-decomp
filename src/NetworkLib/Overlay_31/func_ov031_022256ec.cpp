#include <globaldefs.h>

struct Struct_ov031_022256ec_3 { unsigned char pad[0x60]; int* field60; };

struct Struct_ov031_022256ec { int v; };
struct Struct_ov031_022256ec_2 { int v; };

extern Struct_ov031_022256ec_3* data_ov031_02250bfc;
extern "C" void func_ov031_02224ca4(int a, int idx, struct Struct_ov031_022256ec off, struct Struct_ov031_022256ec_2 hi);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225760(void* obj);

// USA: func_ov031_022256ec
extern "C" ARM void func_ov031_022256ec(void* obj) {
    Struct_ov031_022256ec_3* e = data_ov031_02250bfc;
    int val = *e->field60;
    unsigned char var2 = *((unsigned char*)e + 0x11d);
    struct Struct_ov031_022256ec_2 hi;
    struct Struct_ov031_022256ec off;
    hi.v = (unsigned int)(val & 0x1ff0000) >> 0x10;
    off.v = (val & 0xff) + 0xc;
    func_ov031_02224ca4(var2, 1, off, hi);
    if (off.v < 0xc0) return;
    func_ov031_0223e2b8(obj, (int)func_ov031_02225760);
}
