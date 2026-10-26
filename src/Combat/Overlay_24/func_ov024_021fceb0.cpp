#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov024_021fe698(void* obj, int type);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int a, int b);

struct Struct_ov024_021fceb0 { char pad[8]; int flag; };
struct Struct_ov024_021fceb0_2 { char pad[0x148]; Struct_ov024_021fceb0* q; };

struct Struct_ov024_021fceb0_3 {
    void* base;                     // 0x0
    char pad4[2];                    // 0x4
    unsigned char type;               // 0x6
    char unknown_7_[5];                      // 0x7
    int fieldC;                         // 0xc
    char pad10[0x7c - 0x10];             // 0x10
    Struct_ov024_021fceb0_2* list[1];           // 0x7c
    char unknown_80_[0x9c - 0x80];               // 0x80
    int count;                              // 0x9c
};

// USA: func_ov024_021fceb0
extern "C" ARM void func_ov024_021fceb0(Struct_ov024_021fceb0_3* obj) {
    float threshold = 1000.0f;
    int ok;
    if (obj->type == 2) {
        ok = 1;
    } else if (obj->type == 0) {
        return;
    } else {
        ok = 1;
        if (obj->fieldC >= 4) threshold = 50.0f;
    }
    if (!ok) return;
    if (!func_ov024_021fe698(obj, 0x12)) return;

    float v = *(float*)((char*)obj->base + 0x8e3c);
    if (v > 1.01f) return;

    int found = 0;
    for (int i = 0; i < obj->count; i++) {
        Struct_ov024_021fceb0* q = obj->list[i]->q;
        if (q && q->flag) {
            found = 1;
            break;
        }
    }
    if (!found) return;

    char buf[0xc8];
    memset(buf, 0, 0xc8);
    *(float*)(buf + 0xc4) = threshold;
    return func_ov024_021f9874(obj, buf, 0, 0);
}
