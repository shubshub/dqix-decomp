#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

extern "C" unsigned short func_ov027_021dab38(unsigned short* data, int len);
extern "C" void func_020ca390(int val, void* dst, unsigned int size);
extern "C" void func_020ca3b8(int src, void* dst, int size);
extern "C" void func_ov027_021db124(void);
extern "C" int func_020d69cc(int a0, int a1, int a2, int a3, unsigned short a4, unsigned char a5);

struct Struct_0202bc00 { unsigned char data[0x16]; };

struct Struct_ov027_021db154 {
    unsigned char pad0[0x358];
    unsigned char unknown_358_;
    unsigned char pad1[0x35a - 0x359];
    unsigned short unknown_35a_;
    unsigned short unknown_35c_;
    Struct_0202bc00 unknown_35e_[15];
    unsigned char unknown_4a8_[8];
    unsigned short unknown_4b0_;
    unsigned char pad2[0x4b3 - 0x4b2];
    unsigned char unknown_4b3_;
    unsigned char unknown_4b4_;
    unsigned char unknown_4b5_;
    unsigned char pad3[0x4b8 - 0x4b6];
    unsigned int unknown_4b8_;
};

struct Struct_ov027_021dd940_9 {
    unsigned char pad0[0x10];
    unsigned int f10;
    void (*f14)(unsigned int);
    unsigned char pad1[0x1c - 0x18];
    Struct_ov027_021db154* f1c;
    unsigned char pad2[0x24 - 0x20];
    unsigned char f24;
    unsigned char pad3[0x26 - 0x25];
    unsigned char unknown_26_;
    unsigned char pad4[0x29 - 0x27];
    unsigned char unknown_29_;
    unsigned char pad5[0x40 - 0x2a];
    unsigned int f40;
    unsigned char unknown_44_;
    unsigned char f45;
    unsigned char f46;
    unsigned char f47;
    unsigned short unknown_48_;
    unsigned char unknown_4a_;
    unsigned char pad6[0x4c - 0x4b];
    unsigned short unknown_4c_;
    unsigned short unknown_4e_;
};

extern Struct_ov027_021dd940_9 data_ov027_021dd940;
extern int data_ov027_021dd980 __attribute__((aligned(32)));
extern unsigned short data_ov027_021dd988;
extern unsigned char data_ov027_021dd990[0x58];
extern unsigned char data_ov027_021dd9e8[8];

// USA: func_ov027_021db154
extern "C" ARM void func_ov027_021db154(int a0, unsigned short a1, unsigned char a2) {
    if (data_ov027_021dd940.unknown_26_ != data_ov027_021dd940.f1c->unknown_4b4_) {
        func_ov027_021db124();
    }

    data_ov027_021dd940.unknown_44_ = (data_ov027_021dd940.unknown_44_ & ~3) | 2;
    Struct_ov027_021db154* obj = data_ov027_021dd940.f1c;
    data_ov027_021dd940.f45 = obj->unknown_4b3_;
    data_ov027_021dd940.f46 = data_ov027_021dd940.unknown_26_;
    data_ov027_021dd940.f40 = obj->unknown_4b8_;
    data_ov027_021dd940.unknown_44_ = (data_ov027_021dd940.unknown_44_ & ~0xfc) | (((unsigned int)obj->unknown_4b5_ << 26) >> 24);
    unsigned char var1 = data_ov027_021dd940.unknown_29_;
    data_ov027_021dd940.unknown_29_ = var1 + 1;
    data_ov027_021dd940.f47 = var1;
    data_ov027_021dd940.unknown_4a_ = obj->unknown_358_;
    data_ov027_021dd940.unknown_4c_ = obj->unknown_35a_;
    data_ov027_021dd940.unknown_4e_ = obj->unknown_35c_;

    if (data_ov027_021dd940.f10 == 0 && data_ov027_021dd940.f14 != 0) {
        data_ov027_021dd940.f14(obj->unknown_4b8_);
    }

    int i;
    for (i = 0; i < 8; i++) {
        data_ov027_021dd9e8[i] = data_ov027_021dd940.f1c->unknown_4a8_[i];
    }

    func_020ca390(0, data_ov027_021dd990, 0x58);

    obj = data_ov027_021dd940.f1c;
    unsigned int sl = 0;
    unsigned short diff = obj->unknown_4b0_ ^ obj->unknown_35a_;
    for (i = 0; i < 15; i++) {
        if (diff & (2 << i)) {
            func_020ca3b8((int)((char*)data_ov027_021dd940.f1c + 0x35e + i * 0x16), data_ov027_021dd990 + sl * 0x16, 0x16);
            data_ov027_021dd940.f1c->unknown_4b0_ |= (2u << i);
            sl++;
            if (sl == 4) break;
        }
    }
    if (sl < 4) {
        data_ov027_021dd990[sl * 0x16] &= ~0xf0;
    }

    data_ov027_021dd940.unknown_48_ = 0;
    data_ov027_021dd940.unknown_48_ = func_ov027_021dab38(&data_ov027_021dd988, 0x68);

    obj = data_ov027_021dd940.f1c;
    if (obj->unknown_4b0_ == obj->unknown_35a_) {
        data_ov027_021dd940.f24 = 1;
    }

    func_020d69cc(0, (int)&data_ov027_021dd980, 0x70, a0, a1, (unsigned char)(a2 | 3));

    if (data_ov027_021dd940.f10 != 1) return;
    if (data_ov027_021dd940.f14 == 0) return;
    obj = data_ov027_021dd940.f1c;
    data_ov027_021dd940.f14(obj->unknown_4b8_);
}
