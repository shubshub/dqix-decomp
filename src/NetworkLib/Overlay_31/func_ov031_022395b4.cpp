#include <globaldefs.h>

struct Struct_ov031_022395b4_2 {
    unsigned short field_0x0;
    unsigned short error;
    unsigned char unknown_4_[4];
    unsigned short type;
    unsigned char unknown_a_[6];
    unsigned short aid;
};

struct Struct_ov031_022395b4 {
    unsigned char field_0x0[0x4c];
    int (*unknown_4c_)(Struct_ov031_022395b4_2* event);
    unsigned short unknown_50_;
    unsigned short unknown_52_;
};

struct Struct_ov031_02290d18_10 {
    void (*unknown_0_)(int, const char*, ...);
    Struct_ov031_022395b4* slot;
};

extern Struct_ov031_02290d18_10 data_ov031_02290d18 __attribute__((aligned(4)));
extern const char data_ov031_0224c34c[];
extern const char data_ov031_0224c378[];
extern const char data_ov031_0224c3a4[];
extern "C" void func_ov031_022393e4(int v);
extern "C" void func_ov031_02239368(int);
extern "C" int func_ov031_02239724(void);
extern "C" int func_020d559c(int a0, unsigned int a1);

// USA: func_ov031_022395b4
extern "C" ARM void func_ov031_022395b4(Struct_ov031_022395b4_2* event) {
    unsigned short mask = 1 << event->aid;
    if (event->error) {
        func_ov031_022393e4(event->error);
        func_ov031_02239368(9);
        return;
    }
    unsigned short type = event->type;
    switch (type) {
    case 7:
        if (data_ov031_02290d18.unknown_0_) data_ov031_02290d18.unknown_0_(0x8000000, data_ov031_0224c34c, event->aid);
        if (data_ov031_02290d18.slot->unknown_4c_ && data_ov031_02290d18.slot->unknown_4c_(event) == 0) {
            int result = func_020d559c(0, event->aid);
            if (result == 2) return;
            func_ov031_022393e4(result);
            func_ov031_02239368(9);
            return;
        }
        data_ov031_02290d18.slot->unknown_52_ |= mask;
        break;
    case 9:
        if (data_ov031_02290d18.unknown_0_) data_ov031_02290d18.unknown_0_(0x8000000, data_ov031_0224c378, event->aid);
        data_ov031_02290d18.slot->unknown_52_ &= ~mask;
        break;
    case 0:
        if (func_ov031_02239724() == 0) func_ov031_02239368(9);
        break;
    case 2:
        break;
    default:
        if (data_ov031_02290d18.unknown_0_) data_ov031_02290d18.unknown_0_(0x8000000, data_ov031_0224c3a4, type);
    }
}
