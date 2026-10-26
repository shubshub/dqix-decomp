#include <globaldefs.h>

extern "C" int func_ov031_02222870();

extern int data_ov031_0224f670;
extern int data_ov031_0224b114;

struct Struct_ov031_02222aa4 { int f0; int f1; int f2; };

// USA: func_ov031_02222aa4
extern "C" THUMB int func_ov031_02222aa4(Struct_ov031_02222aa4* obj) {
    obj->f0 = *(int*)((char*)&data_ov031_0224f670 + 0x38);
    if (*(int*)((char*)&data_ov031_0224b114 + 0xc) == -1) {
        obj->f1 = -1;
    } else {
        obj->f1 = *(int*)((char*)&data_ov031_0224b114 + 0xc) - func_ov031_02222870();
    }
    obj->f2 = *(int*)((char*)&data_ov031_0224f670 + 0x78);
    return 1;
}
