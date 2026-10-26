#include <globaldefs.h>

extern "C" int func_ov031_02212ee8(void);
extern "C" void func_ov031_02223b1c(void);
extern "C" void func_ov031_022368e0(void);
extern "C" int func_ov031_02236878(int index);
extern "C" ARM int func_ov031_02212fb8(void);
extern "C" ARM void func_ov031_0222ea14(void* val);
extern "C" ARM void func_ov031_022274c0(int v);
extern "C" void func_ov031_0223e2c0(int idx, void* obj);
extern "C" void func_ov031_02233c94(void);

struct Struct_ov031_02290cd0_2 {
    unsigned char unknown_0_;
    unsigned char pad[3];
    int field4;
};
extern Struct_ov031_02290cd0_2 data_ov031_02290cd0;

// USA: func_ov031_02233d84
extern "C" ARM void func_ov031_02233d84(void* obj) {
    int r5;
    if (data_ov031_02290cd0.field4 != 0) {
        r5 = func_ov031_02212ee8();
        if (r5 == 0) return;
    }
    func_ov031_02223b1c();
    func_ov031_022368e0();
    if (data_ov031_02290cd0.field4 != 0 && r5 > 0) {
        data_ov031_02290cd0.unknown_0_ = 1;
        func_ov031_02236878(0x11);
    } else {
        int v;
        if (data_ov031_02290cd0.field4 == 0) {
            v = 0xffff3be9;
        } else {
            v = func_ov031_02212fb8();
        }
        if (v >= -10) {
            v = 0xffff3be9;
        }
        func_ov031_0222ea14((void*)v);
        func_ov031_02236878(0x12);
    }
    func_ov031_022274c0((int)func_ov031_02233c94);
    func_ov031_0223e2c0(0, obj);
}
