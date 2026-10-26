#include <globaldefs.h>

extern "C" int func_ov031_02236878(int index);
extern "C" void* func_ov031_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_0222c71c(void);

struct Struct_ov031_0222ca64 {
    unsigned char pad[0x38];
    void* field0x38;
    unsigned char pad2[0x1d];
    unsigned char unknown_59_;
};
struct Struct_ov031_02290c8c_18 {
    unsigned char pad[2];
    unsigned short field2;
    Struct_ov031_0222ca64* field4;
};
extern Struct_ov031_02290c8c_18 data_ov031_02290c8c;

// USA: func_ov031_0222ca64
extern "C" ARM void func_ov031_0222ca64(void) {
    if (data_ov031_02290c8c.field2 == 0) {
        if (data_ov031_02290c8c.field4->unknown_59_ != 0) return;
        func_ov031_02236878(9);
        data_ov031_02290c8c.field4->unknown_59_ = 1;
    } else {
        func_ov031_02236878(0x13);
        void* r = func_ov031_0223e218(NULL, (void*)func_ov031_0222c71c, NULL, 0x78);
        data_ov031_02290c8c.field4->field0x38 = r;
    }
}
