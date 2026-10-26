#include <globaldefs.h>
struct Struct_ov031_0220764c {
    int field_0x0;
    void* (*unknown_4_)(void*, unsigned int);
    void (*unknown_8_)(void*, void*, unsigned int);
    int enabled;
    unsigned int field_0x10, unknown_14_, unknown_18_, field_0x1c, unknown_20_;
    char pad24[8];
    int unknown_2c_, unknown_30_;
};
struct Struct_ov031_0224e234_3 {
    int field_0x0;
    void (*unknown_4_)(void*, void*, unsigned int);
    int unknown_8_;
    void* (*unknown_c_)(void*, unsigned int);
    char pad10[0x30];
    int enabled;
    unsigned int unknown_44_, unknown_48_, unknown_4c_, unknown_50_, unknown_54_;
    void* (*unknown_58_)(unsigned int);
    void (*unknown_5c_)(void*);
    int unknown_60_;
    char unknown_64_[0xc];
    int unknown_70_, unknown_74_;
};
extern Struct_ov031_0224e234_3 data_ov031_0224e234;
extern char data_ov031_0224e274;
extern "C" void* func_ov031_022075f4(unsigned int);
extern "C" void func_ov031_02207620(void*);
extern "C" void func_ov031_02204dbc(void*);
// USA: func_ov031_0220764c
extern "C" ARM void func_ov031_0220764c(Struct_ov031_0220764c* input) {
    data_ov031_0224e234.enabled = input->enabled == 1;
    data_ov031_0224e234.unknown_44_ = (((input->field_0x10 >> 24) & 0xff) | ((input->field_0x10 >> 8) & 0xff00) | ((input->field_0x10 << 8) & 0xff0000) | ((input->field_0x10 << 24) & 0xff000000));
    data_ov031_0224e234.unknown_48_ = (((input->unknown_14_ >> 24) & 0xff) | ((input->unknown_14_ >> 8) & 0xff00) | ((input->unknown_14_ << 8) & 0xff0000) | ((input->unknown_14_ << 24) & 0xff000000));
    data_ov031_0224e234.unknown_4c_ = (((input->unknown_18_ >> 24) & 0xff) | ((input->unknown_18_ >> 8) & 0xff00) | ((input->unknown_18_ << 8) & 0xff0000) | ((input->unknown_18_ << 24) & 0xff000000));
    data_ov031_0224e234.unknown_50_ = (((input->field_0x1c >> 24) & 0xff) | ((input->field_0x1c >> 8) & 0xff00) | ((input->field_0x1c << 8) & 0xff0000) | ((input->field_0x1c << 24) & 0xff000000));
    data_ov031_0224e234.unknown_54_ = (((input->unknown_20_ >> 24) & 0xff) | ((input->unknown_20_ >> 8) & 0xff00) | ((input->unknown_20_ << 8) & 0xff0000) | ((input->unknown_20_ << 24) & 0xff000000));
    data_ov031_0224e234.unknown_58_ = func_ov031_022075f4;
    data_ov031_0224e234.unknown_5c_ = func_ov031_02207620;
    data_ov031_0224e234.unknown_c_ = input->unknown_4_;
    data_ov031_0224e234.unknown_4_ = input->unknown_8_;
    data_ov031_0224e234.unknown_60_ = 0x40;
    data_ov031_0224e234.unknown_70_ = input->unknown_2c_;
    data_ov031_0224e234.unknown_74_ = input->unknown_30_;
    func_ov031_02204dbc(&data_ov031_0224e274);
}
