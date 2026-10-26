#include <globaldefs.h>

struct Struct_ov000_02170460 {
    char pad0[0x24];
    unsigned char flags;
    char pad1[0x40 - 0x25];
    float accum;
    char pad2[0x4c - 0x44];
    int field4c;
};

// USA: func_ov000_02170460
extern "C" ARM void func_ov000_02170460(struct Struct_ov000_02170460* obj, int count) {
    if (obj->field4c < 0) return;
    if (count <= 0) count = 1;
    if (obj->flags & 8) {
        float sum = obj->accum + (float)count * 0.2f;
        if (3.1415926f < (obj->accum = sum)) {
            obj->accum = 3.1415926f;
        }
    } else {
        obj->accum = 0.0f;
    }
}
