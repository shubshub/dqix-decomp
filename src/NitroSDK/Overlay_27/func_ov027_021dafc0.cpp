#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" void func_020ca390(int val, void* dst, unsigned int nBytes);
extern "C" int func_020ca3b8(int src, int dst, int nBytes);
extern "C" unsigned short func_ov027_021dab38(unsigned short* data, int len);
extern "C" int func_020d69cc(int a0, int a1, int a2, int a3, unsigned short a4, unsigned char a5);

struct Struct_ov027_021dd940_7 {
    unsigned char pad0[0x1c];
    unsigned char* f1c;
    unsigned char* f20;
    unsigned char f24;
    unsigned char pad1[0x26 - 0x25];
    unsigned char unknown_26_;
    unsigned char unknown_27_;
    unsigned char f28;
    unsigned char unknown_29_;
    unsigned char pad2[0x40 - 0x2a];
    unsigned int f40;
    unsigned char unknown_44_0_:2;
    unsigned char unknown_44_2_:6;
    unsigned char f45;
    unsigned char f46;
    unsigned char f47;
    unsigned short unknown_48_;
    unsigned char unknown_4a_;
    unsigned char unknown_4b_;
    unsigned char unknown_4c_;
};

extern Struct_ov027_021dd940_7 data_ov027_021dd940;
extern int data_ov027_021dd980;
extern unsigned short data_ov027_021dd988;
extern unsigned char data_ov027_021dd98e;

#pragma opt_common_subs off
#pragma optimize_for_size off
// USA: func_ov027_021dafc0
extern "C" ARM int func_ov027_021dafc0(int arg0, unsigned short arg1, int arg2) {
    unsigned char* end = data_ov027_021dd940.f1c + 0x358;
    if (data_ov027_021dd940.f20 + 0x62 <= end) {
        data_ov027_021dd940.unknown_4c_ = 0x62;
    } else {
        data_ov027_021dd940.unknown_4c_ = end - data_ov027_021dd940.f20;
        {
            unsigned int off = data_ov027_021dd940.unknown_4c_;
            func_020ca390(0, &data_ov027_021dd98e + off, 0x62 - off);
        }
    }

    func_020ca3b8((int)data_ov027_021dd940.f20, (int)&data_ov027_021dd98e, data_ov027_021dd940.unknown_4c_);

    data_ov027_021dd940.unknown_4a_ = data_ov027_021dd940.unknown_27_;
    data_ov027_021dd940.unknown_4b_ = data_ov027_021dd940.f28;
    data_ov027_021dd940.unknown_44_0_ = data_ov027_021dd940.f1c[0x4b2];
    data_ov027_021dd940.f45 = data_ov027_021dd940.f1c[0x4b3];
    data_ov027_021dd940.f46 = data_ov027_021dd940.unknown_26_;
    data_ov027_021dd940.f40 = *(unsigned int*)(data_ov027_021dd940.f1c + 0x4b8);
    data_ov027_021dd940.unknown_44_2_ = data_ov027_021dd940.f1c[0x4b5];
    data_ov027_021dd940.f47 = data_ov027_021dd940.unknown_29_++;
    data_ov027_021dd940.unknown_48_ = 0;
    data_ov027_021dd940.unknown_48_ = func_ov027_021dab38(&data_ov027_021dd988, 0x68);

    data_ov027_021dd940.unknown_27_ = data_ov027_021dd940.unknown_27_ + 1;
    if (data_ov027_021dd940.unknown_27_ < data_ov027_021dd940.f28) {
        data_ov027_021dd940.f20 = data_ov027_021dd940.f20 + 0x62;
    } else {
        data_ov027_021dd940.f24 = 4;
    }

    return func_020d69cc(0, (int)&data_ov027_021dd980, 0x70, arg0, arg1, (arg2 | 3) & 0xff);
}
