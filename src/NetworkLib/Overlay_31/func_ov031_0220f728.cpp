#include <globaldefs.h>

struct Struct_ov031_0220f728_2 {
    unsigned char pad[0xc];
    int* unknown_c_;
    unsigned char pad2[0x20 - 0x10];
    int field20;
    int field24;
};

struct Struct_ov031_0220f728 {
    unsigned char pad[0x24];
    struct Struct_ov031_0220f728_2* field24;
};

extern struct Struct_ov031_0220f728* data_ov031_0224e580;

extern "C" int func_ov031_0220fe44(int arg);
extern "C" void func_ov031_0220fed8(void);

// USA: func_ov031_0220f728
extern "C" ARM void func_ov031_0220f728(void) {
    if (func_ov031_0220fe44(0)) {
        struct Struct_ov031_0220f728_2* q = data_ov031_0224e580->field24;
        q->field24 = *q->unknown_c_;
        q = data_ov031_0224e580->field24;
        q->field20 = 1;
    }
    func_ov031_0220fed8();
}
