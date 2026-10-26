#include <globaldefs.h>

struct Struct_ov031_0220f814_3 {
    char unknown_0_[4];
    int unknown_4_;
    char padding[8];
    int unknown_10;
    int unknown_14_;
};
struct Struct_ov031_0220f814 {
    char padding[0x24];
    Struct_ov031_0220f814_3* session;
};
struct Struct_ov031_0220f814_2 {
    unsigned int length;
    unsigned int magic;
    unsigned int command;
    int unknown_c_;
    int unknown_10;
    int unknown_14_;

};
extern Struct_ov031_0220f814* data_ov031_0224e580;
extern "C" int func_ov031_0220fe44(int (*)(int*));
extern "C" int func_ov031_0220f770(int*);
extern "C" int func_ov031_0220ff18(void*);
extern "C" void func_ov031_0220fea0();
extern "C" void func_ov031_0220fed8();

// USA: func_ov031_0220f814
extern "C" ARM void func_ov031_0220f814() {
    char storage[0x414];
    Struct_ov031_0220f814_2* message = (Struct_ov031_0220f814_2*)storage;
    message->length = 0x18;
    message->magic = 0x44535359;
    Struct_ov031_0220f814* context = data_ov031_0224e580;
    message->command = 0xdb;
    message->unknown_c_ = context->session->unknown_4_;
    message->unknown_10 = context->session->unknown_10;
    message->unknown_14_ = context->session->unknown_14_;
    if (func_ov031_0220fe44(func_ov031_0220f770)) {
        if (func_ov031_0220ff18(storage)) {
            func_ov031_0220fea0();
        }
    }
    func_ov031_0220fed8();
}
