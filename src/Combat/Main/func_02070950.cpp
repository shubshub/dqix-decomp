#include <globaldefs.h>

struct Struct_02070950 {
    int r;
    int g;
    int b;
};

struct Struct_02070950_2 {
    unsigned char active;   // 0x0
    unsigned char unknown_1_;    // 0x1
    unsigned short color;   // 0x2
    unsigned char mode;     // 0x4
    unsigned char unknown_5_[3]; // 0x5-0x7
    int amount;             // 0x8
    unsigned char unknown_c_[4]; // 0xc-0xf
    int field10;            // 0x10
};

// USA: func_02070950
extern "C" ARM void func_02070950(struct Struct_02070950_2* obj, struct Struct_02070950* arg1, int duration, int value, int mode) {
    if (duration < 0) {
        return;
    }
    obj->field10 = duration;
    obj->color = arg1->r | (arg1->g << 5) | (arg1->b << 10);
    obj->amount = (int)(16.667f * (float)value);
    obj->mode = (unsigned char)mode;
    obj->active = 1;
}
