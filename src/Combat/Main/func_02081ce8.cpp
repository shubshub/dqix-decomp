#include <globaldefs.h>

struct Struct_02081ce8 {
    float field0;
    char pad1[0x6 - 0x4];
    short unknown_6_;
    short unknown_8_;
    char fieldA;
    char unknown_b_;
    char fieldC;
    char pad3[0x13 - 0xd];
    unsigned char unknown_13_0_ : 4;
    unsigned char unknown_13_4_ : 4;
    char pad4[0x28 - 0x14];
    short unknown_28_;
    unsigned char unknown_2a_;
};

extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" int Font_GetTextWidth(void* builder, void* obj);
extern "C" void func_0204f41c(int a, short b, short c, void* buf, int d, int e, void* f, void* g, int h);
extern char data_020f0ff2;

// USA: func_02081ce8
extern "C" ARM void func_02081ce8(void* unused0, int param1, struct Struct_02081ce8* obj, int arg3) {
    int var0 = obj->unknown_13_4_;
    if (obj->unknown_2a_ & 4) {
        var0 = 5;
    }
    char buf[0x40];
    __clear(buf, 0x40);
    sprintf(buf, &data_020f0ff2, (double)obj->field0);
    int r1val = Font_GetTextWidth(buf, 0);
    int nibble = obj->unknown_13_0_;
    short sum = (short)((obj->unknown_6_ + obj->unknown_28_) - r1val);
    func_0204f41c(param1, sum, obj->unknown_8_, buf, nibble, var0, &obj->fieldA, &obj->fieldC, 0);
}
