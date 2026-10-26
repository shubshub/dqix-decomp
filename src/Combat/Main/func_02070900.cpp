#include <globaldefs.h>

struct Struct_02070900 {
    int r;
    int g;
    int b;
};

struct Struct_02070900_2 {
    unsigned char active;   // 0x0
    unsigned char unknown_1_;    // 0x1
    unsigned short color;   // 0x2
    unsigned char mode;     // 0x4
    unsigned char unknown_5_[3]; // 0x5-0x7
    int amount;             // 0x8
};

// USA: func_02070900
extern "C" ARM void func_02070900(struct Struct_02070900_2* obj, struct Struct_02070900* arg1, unsigned int value) {
    obj->color = arg1->r | (arg1->g << 5) | (arg1->b << 10);
    obj->amount = (int)(16.667f * (float)value);
    obj->mode = 0x1f;
    obj->active = 1;
}
