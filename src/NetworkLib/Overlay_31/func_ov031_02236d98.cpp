#include <globaldefs.h>

struct Struct_ov031_02222f44_2;
extern "C" void func_ov031_0223bd28(Struct_ov031_02222f44_2* h, int index, unsigned int* arg2, unsigned int* arg3);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_02236e38(void*);

struct Struct_ov031_02236d98 { void* items[5]; int f14; };
struct Struct_ov031_02290d04_6 { void* field0; Struct_ov031_02236d98* p; void* field8; void* fieldC; };
extern Struct_ov031_02290d04_6 data_ov031_02290d04;

// USA: func_ov031_02236d98
extern "C" ARM void func_ov031_02236d98(void* obj) {
    int hi;
    unsigned int lo;
    func_ov031_0223bd28((Struct_ov031_02222f44_2*)data_ov031_02290d04.p->items[4], 0, (unsigned int*)&hi, &lo);
    hi += 8;
    if (hi < 0xb0 || hi > 0x100) {
        func_ov031_0223bbd8(data_ov031_02290d04.p->items[4], -1, hi, 0x21);
        return;
    }
    hi = 0xb0;
    func_ov031_0223bbd8(data_ov031_02290d04.p->items[4], -1, hi, 0x21);
    func_ov031_0223e2b8(obj, (int)func_ov031_02236e38);
}
