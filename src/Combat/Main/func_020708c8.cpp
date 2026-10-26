#include <globaldefs.h>

struct Struct_020708c8 {
    unsigned char active;   // 0x0
    unsigned char unknown_1_;    // 0x1
    unsigned short color;   // 0x2
    unsigned char mode;     // 0x4
    unsigned char unknown_5_[3]; // 0x5-0x7
    int amount;             // 0x8
};

// USA: func_020708c8
extern "C" ARM void func_020708c8(struct Struct_020708c8* obj, unsigned int value) {
    obj->amount = (int)(16.667f * (float)value);
    obj->mode = 1;
    obj->active = 1;
}
