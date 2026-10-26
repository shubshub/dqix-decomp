#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#if defined(jpn)
#define data_020ee950 data_020eea14
#endif

struct Struct_020e1288;
extern "C" int func_020e1288(struct Struct_020e1288* obj);

extern VRAMSubregion data_020ee950[];

struct Struct_020e23f4 { unsigned char bit0 : 1; };

struct Struct_020e23f4_2 {
    char pad0[0x30];
    int unknown_30_;
    int f34;
    char pad1[0x6];
    unsigned char unknown_3e_;
    unsigned char unknown_3f_;
};

struct Struct_020e23f4_3 {
    unsigned char* field0;
    struct Struct_020e23f4_2* field4;
};

// USA: func_020e23f4
extern "C" ARM void func_020e23f4(struct Struct_020e23f4_3* obj) {
    struct Struct_020e23f4_2* var0 = obj->field4;
    if (var0 == 0 || obj->field0 == 0) return;
    ((struct Struct_020e23f4*)&var0->unknown_3f_)->bit0 = 1;
    var0 = obj->field4;
    int var1 = var0->unknown_30_;
    int half = func_020e1288((struct Struct_020e1288*)var0);
    StageMemoryToVRAM(
        data_020ee950[var0->unknown_3e_],
        obj->field0 + var1,
        var1,
        var0->f34 + half,
        true, false);
}
