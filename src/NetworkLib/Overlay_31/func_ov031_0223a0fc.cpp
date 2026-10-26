#include <globaldefs.h>


struct Struct_ov031_0223a0fc {
    unsigned char field_0x0[0xc];
    unsigned short unknown_c_;
    unsigned short enabled;
    unsigned short field_0x10;
    unsigned short unknown_12_;
    unsigned short alternate;
    unsigned short unknown_16_;
    unsigned short unknown_18_;
    unsigned char unknown_1a_[0x18];
    unsigned short unknown_32_;
    unsigned short width;
    unsigned short height;
    unsigned char unknown_38_[8];
    int mode;
    int selection;
    unsigned char unknown_48_[0x1258];
    int unknown_12a0_;
    int unknown_12a4_;
};
struct Struct_ov031_02290d18_23 { void (*unknown_0_)(int, const char*, ...); Struct_ov031_0223a0fc* state; };
extern Struct_ov031_02290d18_23 data_ov031_02290d18 __attribute__((aligned(4)));
extern const char data_ov031_0224c41c[];
extern const char data_ov031_0224c434[];
extern const char data_ov031_0224c47c[];
extern "C" void HaltSystem(void);
extern "C" void func_ov031_02239368(int);
extern "C" int func_ov031_02239404(void);
extern "C" unsigned short func_020d4b58(void);

// USA: func_ov031_0223a0fc
extern "C" ARM int func_ov031_0223a0fc(int selection, int first, int second) {
    (data_ov031_02290d18.state->mode == 1) || (HaltSystem(), 0);
    data_ov031_02290d18.state->unknown_12a4_ = 0x180;
    data_ov031_02290d18.state->unknown_12a0_ = 0xe0;
    if (data_ov031_02290d18.unknown_0_) data_ov031_02290d18.unknown_0_(0x8000000, data_ov031_0224c41c, data_ov031_02290d18.state->unknown_12a4_);
    if (data_ov031_02290d18.unknown_0_) data_ov031_02290d18.unknown_0_(0x8000000, data_ov031_0224c434, data_ov031_02290d18.state->unknown_12a0_);
    data_ov031_02290d18.state->selection = selection;
    func_ov031_02239368(3);
    data_ov031_02290d18.state->unknown_c_ = first;
    data_ov031_02290d18.state->unknown_32_ = second;
    data_ov031_02290d18.state->unknown_18_ = func_020d4b58();
    data_ov031_02290d18.state->width = 0xd0;
    data_ov031_02290d18.state->height = 0x44;
    data_ov031_02290d18.state->field_0x10 = 2;
    data_ov031_02290d18.state->unknown_16_ = 0;
    data_ov031_02290d18.state->unknown_12_ = 0;
    data_ov031_02290d18.state->enabled = 1;
    data_ov031_02290d18.state->alternate = selection == 2;
    if (selection == 0 || selection == 2 || selection == 4) return func_ov031_02239404();
    if (data_ov031_02290d18.unknown_0_) data_ov031_02290d18.unknown_0_(0x8000000, data_ov031_0224c47c, selection);
    return 0;
}
