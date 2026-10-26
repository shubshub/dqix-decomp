#include <globaldefs.h>


struct Struct_ov031_0223a0fc {
    unsigned char unknown_0_[0xc];
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned short unknown_14_;
    unsigned short unknown_16_;
    unsigned short unknown_18_;
    unsigned char unknown_1a_[0x18];
    unsigned short unknown_32_;
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    unsigned char unknown_38_[8];
    int unknown_40_;
    int unknown_44_;
    unsigned char unknown_48_[0x1258];
    int unknown_12a0_;
    int unknown_12a4_;
};
struct Struct_ov031_02290d18_23 { void (*unknown_0_)(int, const char*, ...); Struct_ov031_0223a0fc* unknown_4_; };
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
    data_ov031_02290d18.state->field_0x12a4 = 0x180;
    data_ov031_02290d18.state->field_0x12a0 = 0xe0;
    if (data_ov031_02290d18.report) data_ov031_02290d18.report(0x8000000, data_ov031_0224c41c, data_ov031_02290d18.state->field_0x12a4);
    if (data_ov031_02290d18.report) data_ov031_02290d18.report(0x8000000, data_ov031_0224c434, data_ov031_02290d18.state->field_0x12a0);
    data_ov031_02290d18.state->selection = selection;
    func_ov031_02239368(3);
    data_ov031_02290d18.unknown_4_->unknown_c_ = arg1;
    data_ov031_02290d18.unknown_4_->unknown_32_ = arg2;
    data_ov031_02290d18.unknown_4_->unknown_18_ = func_020d4b58();
    data_ov031_02290d18.unknown_4_->unknown_34_ = 0xd0;
    data_ov031_02290d18.unknown_4_->unknown_36_ = 0x44;
    data_ov031_02290d18.unknown_4_->unknown_10_ = 2;
    data_ov031_02290d18.unknown_4_->unknown_16_ = 0;
    data_ov031_02290d18.unknown_4_->unknown_12_ = 0;
    data_ov031_02290d18.unknown_4_->unknown_e_ = 1;
    data_ov031_02290d18.unknown_4_->unknown_14_ = arg0 == 2;
    if (arg0 == 0 || arg0 == 2 || arg0 == 4) return func_ov031_02239404();
    if (data_ov031_02290d18.unknown_0_) data_ov031_02290d18.unknown_0_(0x8000000, data_ov031_0224c47c, arg0);
    return 0;
}
