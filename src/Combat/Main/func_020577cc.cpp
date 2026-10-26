#include <globaldefs.h>

struct Struct_020577cc_3 {
    unsigned char pad[0x2c];
    unsigned char unknown_2c_;
    unsigned char pad2[0x148 - 0x2c - 1];
    struct Struct_020577cc_3* unknown_148_;
};

struct Struct_020577cc {
    unsigned char pad[0x34];
    struct Struct_020577cc_3* unknown_34_;
};

struct Struct_020577cc_2;
extern "C" void func_02059c90(struct Struct_020577cc_2* obj, unsigned short* out0, unsigned short* out1);

// USA: func_020577cc
extern "C" ARM void func_020577cc(struct Struct_020577cc* obj, unsigned short* out1, unsigned short* out2) {
    unsigned short var0 = 0, var1 = 0;
    struct Struct_020577cc_3* cur = obj->unknown_34_;
    while (cur != NULL) {
        if (cur->unknown_2c_ == 0) {
            cur = cur->unknown_148_;
            continue;
        }
        unsigned short local1 = 0, var4 = 0;
        func_02059c90((struct Struct_020577cc_2*)cur, &local1, &var4);
        cur = cur->unknown_148_;
        var0 = var0 + local1;
        var1 = var1 + var4;
    }
    *out1 = var0;
    *out2 = var1;
}
