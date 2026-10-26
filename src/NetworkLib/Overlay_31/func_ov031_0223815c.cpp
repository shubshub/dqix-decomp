#include <globaldefs.h>

extern "C" void func_ov031_0223e2c0(int idx, void* obj);
extern "C" ARM void* func_ov031_0223e218(void* a, void* b, void* c, int d);
extern "C" ARM void func_ov031_022384bc(int a);

struct Struct_ov031_0223815c {
    unsigned char pad[0x14];
    void* field14;
    unsigned short field18;
    unsigned char pad2;
    char unknown_1b_;
};
extern Struct_ov031_0223815c* data_ov031_02290d10;

// USA: func_ov031_0223815c
extern "C" ARM void func_ov031_0223815c(void* a0) {
    data_ov031_02290d10->unknown_1b_ = -1;
    data_ov031_02290d10->field18++;
    if (data_ov031_02290d10->field18 >= 0x78) {
        func_ov031_0223e2c0(0, a0);
        data_ov031_02290d10->field14 = func_ov031_0223e218((void*)1, (void*)func_ov031_022384bc, (void*)0, 0x78);
    }
}
