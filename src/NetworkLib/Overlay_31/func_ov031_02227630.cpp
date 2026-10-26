#include <globaldefs.h>

struct Struct_ov031_02290c40 { void* field0; };
extern Struct_ov031_02290c40 data_ov031_02290c40;

struct Struct_ov031_02227630 { void* field0; void* field4; int field8; };

extern "C" Struct_ov031_02227630* func_ov031_0223bfa0(int);
extern "C" int func_ov031_0223b61c(void*, int*, int);

// USA: func_ov031_02227630
extern "C" ARM Struct_ov031_02227630* func_ov031_02227630(void* a0) {
    int val = *(int*)((char*)data_ov031_02290c40.field0 + 0x60);
    Struct_ov031_02227630* out = func_ov031_0223bfa0(val);
    int local;
    int var3 = func_ov031_0223b61c(a0, &local, 4);
    char* base2 = (char*)var3 + 0x20;
    out->field8 = var3;
    out->field0 = base2 + 0x10;
    out->field4 = base2 + *(int*)(base2 + 4) + 8;
    return out;
}
