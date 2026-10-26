#include <globaldefs.h>

extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_0222c7d8(void);
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);

struct Struct_ov031_0222cad8 {
    unsigned char pad0[0x38];
    int field38;
    unsigned char unknown_3c_[4];
    unsigned short field40;
    unsigned char unknown_42_[15];
    unsigned char unknown_51_;
    unsigned char unknown_52_[7];
    unsigned char unknown_59_;
};

struct Struct_ov031_02290c8c_19 {
    short pad0;
    unsigned short field2;
    Struct_ov031_0222cad8* field4;
};
extern Struct_ov031_02290c8c_19 data_ov031_02290c8c;

// USA: func_ov031_0222cad8
extern "C" ARM void func_ov031_0222cad8(void) {
    Struct_ov031_0222cad8* c = data_ov031_02290c8c.field4;
    if (data_ov031_02290c8c.field2 == c->field40 || c->unknown_51_ <= 4) {
        if (c->unknown_59_ != 0) return;
        func_ov031_02236878(9);
        data_ov031_02290c8c.field4->unknown_59_ = 1;
    } else {
        func_ov031_02236878(0x13);
        void* result = func_ov031_0223e218((void*)0, (void*)func_ov031_0222c7d8, (void*)0, 0x78);
        data_ov031_02290c8c.field4->field38 = (int)result;
    }
}
