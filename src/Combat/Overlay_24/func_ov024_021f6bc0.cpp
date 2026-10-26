#include <globaldefs.h>

struct Struct_ov024_021f6bc0 {
    char pad[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
};

// USA: func_ov024_021f6bc0
extern "C" ARM int func_ov024_021f6bc0(Struct_ov024_021f6bc0* obj) {
    obj->f1c = 0.75f * obj->f14;
    obj->f20 = 0.75f * obj->f18;
    return 1;
}
