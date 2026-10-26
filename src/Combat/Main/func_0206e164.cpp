#include <globaldefs.h>

struct Struct_0205faf4_3 {
    unsigned char unknown_0_[0x2CC];
    unsigned char unknown_2cc_[1];
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_021d0924(unsigned char a, unsigned char b, unsigned short c, unsigned short d);

// USA: func_0206e164
extern "C" ARM void func_0206e164(struct Struct_0205faf4_3* arg0, int arg1, int arg2) {
    if (arg1 >= 0xCC || arg1 < 0) {
        return;
    }
    int var0 = arg1 / 2;
    if (arg1 % 2) {
        unsigned char var1 = arg0->unknown_2cc_[var0] >> 4;
        var1 = (var1 & 0xc) | arg2;
        arg0->unknown_2cc_[var0] &= 0xf;
        arg0->unknown_2cc_[var0] |= var1 << 4;
    } else {
        unsigned char var2 = arg0->unknown_2cc_[var0] & 0xf;
        var2 = (var2 & 0xc) | arg2;
        arg0->unknown_2cc_[var0] &= 0xf0;
        arg0->unknown_2cc_[var0] |= var2;
    }
    if (LinkSession_IsHostOrSolo(LinkSession_GetInstance()) == 0) {
        return;
    }
    if (arg1 < 0xAE) {
        return;
    }
    func_ov017_021d0924(7, 0, arg1, arg2);
}
