#include <globaldefs.h>
#include "NitroSDK/Memory.h"

typedef void* (*Type_ov031_022167c8)(const char*, unsigned int);
union Struct_ov031_022167c8 {
    struct {
        char unknown_0_[0x40];
        Type_ov031_022167c8 unknown_40_;
        int unknown_44_;
    } unknown_0_;
    unsigned int words[18];
};
struct Struct_ov031_022167c8_2 {
    char unknown_0_[0x1004];
    int result;
    struct {
        unsigned int signature;
        char data[0x1c0];
    } buffer;
    union {
        Struct_ov031_022167c8 unknown_0_;
        struct {
            char unknown_0_[0x32];
            unsigned short counter;
            char unknown_34_[0xb];
            unsigned char flag;
        } state;
    } config;
    char unknown_1214_[0x100];
    void* context;
};
struct Struct_ov031_0224e5e8 {
    int state;
    int unknown_4_;
    Struct_ov031_022167c8_2* work;
};
extern Struct_ov031_0224e5e8 data_ov031_0224e5e8;
extern const char data_ov031_02249b98[];
extern "C" int func_ov031_02216b90(int);
extern "C" void func_ov031_022168ec();

// USA: func_ov031_022167c8
extern "C" ARM int func_ov031_022167c8(Struct_ov031_022167c8* arg0, void* context) {
    Type_ov031_022167c8 var0 = arg0->unknown_0_.unknown_40_;
    if (data_ov031_0224e5e8.work) return 2;
    data_ov031_0224e5e8.work = (Struct_ov031_022167c8_2*)var0(data_ov031_02249b98, 0x13f4);
    if (!data_ov031_0224e5e8.work) return 2;
    VectorizedMemset(data_ov031_0224e5e8.work, 0, 0x13f4);
    data_ov031_0224e5e8.work->context = context;
    data_ov031_0224e5e8.state = 0;
    VectorizedMemset(&data_ov031_0224e5e8.work->buffer, 0, 0x1c4);
    data_ov031_0224e5e8.work->buffer.signature = 0x4e84;
    data_ov031_0224e5e8.work->config.unknown_0_ = *arg0;
    data_ov031_0224e5e8.work->config.state.counter = 0;
    data_ov031_0224e5e8.work->config.state.flag = 0;
    data_ov031_0224e5e8.work->result = func_ov031_02216b90(1);
    if (data_ov031_0224e5e8.work->result) return data_ov031_0224e5e8.work->result;
    data_ov031_0224e5e8.unknown_4_ = 0;
    func_ov031_022168ec();
    return 0;
}
