#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0203c1c8 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    short unknown_14_;
#if defined(jpn)
    char unknown_16_[0x20];
#endif
};

struct Struct_0203c108_3;

extern "C" void func_ov000_021704d8(struct Struct_0203c1c8* arg0, int* arg1, int* arg2, int* arg3);
extern "C" int func_ov000_021719f8(int* arg0);
#if defined(jpn)
struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
#endif
void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);
void CachedTextLabel_Release(char* obj);

extern "C" void __clear(void* arg0, int arg1);

struct Struct_ov000_02170538_2 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x1c - 0x19];
    signed char unknown_1c_;
    signed char unknown_1d_;
    char unknown_1e_[0x24 - 0x1e];
    unsigned char unknown_24_;
    char unknown_25_;
    unsigned short unknown_26_;
    int unknown_28_;
    short unknown_2c_;
    signed char unknown_2e_;
    char unknown_2f_[0x3c - 0x2f];
    int unknown_3c_;
    char unknown_40_[0x44 - 0x40];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
    struct Struct_0203c1c8 unknown_50_;
    struct Struct_0203c1c8 unknown_68_;
    char unknown_80_[RG(0x87 - 0x80, 0xc7 - 0xc0)];
    unsigned char unknown_87_;
    char unknown_88_[RG(0x443 - 0x88, 0x483 - 0xc8)];
    signed char unknown_443_;
};

extern "C" int func_ov000_0217f5dc(struct Struct_ov000_02170538_2* arg0);
extern "C" int func_ov000_02170c7c(struct Struct_ov000_02170538_2* arg0);
#if defined(jpn)
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170538_2* arg0);
#else
extern "C" int func_ov000_02171a74(struct Struct_ov000_02170538_2* arg0, char* arg1);
#endif

struct Struct_ov000_02170538 {
    int unknown_0_[2];
};

extern const struct Struct_ov000_021832f4 {
    char unknown_0_[RG(0x7c, 0x70)];
    struct Struct_ov000_02170538 unknown_7c_;
    struct Struct_ov000_02170538 unknown_84_;
} data_ov000_021832f4;

// USA: func_ov000_02170538
extern "C" ARM void func_ov000_02170538(struct Struct_ov000_02170538_2* arg0, int arg1, int arg2, int arg3) {
    if (arg0->unknown_4c_ < 0) return;
    if (!func_ov000_0217f5dc(arg0)) return;
    int var0 = func_ov000_02170c7c(arg0);
    if (arg0->unknown_24_ & 4) {
        int var1[2] = { arg0->unknown_44_ + 0x25, arg0->unknown_44_ + 0x26 };
        int var2[2] = { arg0->unknown_48_ + 0xb, arg0->unknown_48_ + 0xb };
        struct Struct_ov000_02170538 var3 = data_ov000_021832f4.unknown_7c_;
        var3.unknown_0_[0] = var0;
        func_ov000_021704d8(&arg0->unknown_68_, var1, var2, var3.unknown_0_);
        return;
    }
    int var4[2] = { arg0->unknown_44_ + RG(0x28, 0x2f) + arg1, arg0->unknown_44_ + 0x30 + arg1 };
    int var5[2] = { arg0->unknown_48_ + 8 + arg2, arg0->unknown_48_ + 8 + arg2 };
    struct Struct_ov000_02170538 var6 = data_ov000_021832f4.unknown_84_;
    var6.unknown_0_[0] = var0;
    func_ov000_021704d8(&arg0->unknown_68_, var4, var5, var6.unknown_0_);
    if (arg0->unknown_10_[arg0->unknown_18_] == 0x67) return;
    int var7[2] = { arg0->unknown_44_ + 0xb3 + arg1, arg0->unknown_44_ + 0xb4 + arg1 };
    int var8[2][2] = { { arg0->unknown_48_ + 0xf + arg2, arg0->unknown_48_ + 0xf + arg2 }, { arg0->unknown_48_ + 8 + arg2, arg0->unknown_48_ + 8 + arg2 } };
    int var9 = 1;
    unsigned int var10 = arg0->unknown_3c_ & 0x80019;
    unsigned int var11 = arg0->unknown_28_ & 0x80019;
    if (func_ov000_021719f8((int*)arg0)) {
        if (var10 != var11) {
#if defined(jpn)
            char* str = (char*)KeyTable_Get(*(struct Container020e0310**)((char*)e + 4), func_ov000_02171a74(e));
            if (str != NULL) {
                CachedTextLabel_SetText((struct Obj0203c108*)&e->label, str);
            }
#else
            char buf[0x80];
            __clear(buf, sizeof(buf));
            if (func_ov000_02171a74(e, buf) >= 0) {
                CachedTextLabel_SetText((struct Obj0203c108*)&e->label, buf);
            }
#endif
            arg0->unknown_3c_ = arg0->unknown_28_;
        }
        func_ov000_021704d8(&arg0->unknown_50_, var7, var8[0], var6.unknown_0_);
        return;
    }
    if (cur != want && (e->f3c & 0x80019)) {
        CachedTextLabel_Release((char*)&e->label);
        e->f3c = e->f28;
        e->b1d = -1;
        e->s2c = -1;
        e->b2e = -1;
        e->u26 = 0;
    }
    int var14 = 3;
    if (arg0->unknown_10_[arg0->unknown_18_] != 0x66) var14 = 0;
    if (arg0->unknown_26_ == 3) var9 = 0;
    if (arg0->unknown_1c_ == 6) var9 = 0;
    if (arg0->unknown_10_[arg0->unknown_18_] < 0x64) {
        if (arg0->unknown_87_) {
            var9 = 0;
        } else {
            return;
        }
    }
    var6.unknown_0_[0] = var14;
    if (arg3 == 2) return;
    if (arg0->unknown_443_ != 5) var9 = 0;
    func_ov000_021704d8(&arg0->unknown_50_, var7, var8[var9], var6.unknown_0_);
}
