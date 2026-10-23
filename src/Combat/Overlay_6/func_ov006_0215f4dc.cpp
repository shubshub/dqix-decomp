#include <globaldefs.h>

struct Struct_02080f8c;
struct Struct_02080fa8;

struct Struct_ov006_02157a60 {
#if !defined(jpn)
    int unknown_0_;
    char** unknown_4_;
#endif
    char unknown_8_[0xc];
    void* unknown_14_;
    char unknown_18_[0x30];
    short** unknown_48_;
    unsigned char** unknown_4c_;
    unsigned short* unknown_50_;
#if defined(jpn)
    char unknown1_4c_[0x118];
#else
    char unknown_54_[0x11c];
#endif
    char unknown_170_[0xc];
#if defined(jpn)
    char unknown1_170_[0x1f2];
#else
    char unknown_17c_[0x1e6];
#endif
    short unknown_362_;
    char unknown_364_[0xc];
    short unknown_370_;
    char unknown_372_[0x16];
    unsigned char unknown_388_;
    unsigned char unknown_389_;
    unsigned char unknown_38a_;
    unsigned char unknown_38b_;
    char unknown_38c_[8];
    unsigned short unknown_394_;
};

extern "C" void func_02080b54(void*, int);
extern "C" void func_02080608(void*, int);
extern "C" void func_020806c4(void*, int);
extern "C" void func_02080b40(void*, int);
extern "C" void* func_020e5294(void*, int);
#if defined(jpn)
struct Container020e0310;
const char* KeyTable_Get(Container020e0310*, int);
#endif
extern "C" void func_02080f8c(Struct_02080f8c*, int, int);
extern "C" void func_02080fa8(Struct_02080fa8*, int, int);
extern "C" void func_020805f4(void*, int);
extern "C" void func_02081130(void*, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_020e4864(const char*, char*, int, int, int, int);
extern "C" void func_020813ec(void*, int);

// USA: func_ov006_0215f4dc
extern "C" ARM void func_ov006_0215f4dc(Struct_ov006_02157a60* arg0) {
    short var0;
    unsigned char* var1;
    unsigned short var2;
    short var3;
    void* var4;
    short* var5;
    int var6;
    int var7;
    unsigned short var8;
    unsigned char var9;
    var0 = arg0->unknown_362_ - 0x5b;
    var8 = arg0->unknown_388_ * 8;
    var1 = arg0->unknown_4c_[var0];
    var5 = arg0->unknown_48_[var0];
    var4 = arg0->unknown_14_;
    var2 = arg0->unknown_50_[var0];
    var6 = 0x64;
    var3 = 0x6c;
    var7 = 0x74;
    func_02080b54(var4, 0x11);
    func_02080608(var4, 0x11);
    arg0->unknown_394_ &= ~4;
    if (var2 > 8) arg0->unknown_394_ |= 4;
    for (var9 = 0; var9 < 8; var9++) {
        if (var2 > var8 && var5[var8] > 0) {
            func_020806c4(var4, var6);
            func_02080b40(var4, var6);
            func_02080b40(var4, var3);
            func_02080b40(var4, var7);
#if defined(jpn)
            SetEntryFirstField02080f8c((Container02080f8c*)menu, nameEntry, (int)KeyTable_Get((Container020e0310*)self->itemNames_, items[position]));
#else
            const char** var10 = (const char**)func_020e5294(arg0->unknown_170_, var5[var8]);
            if (var10 != NULL) {
                memset(arg0->unknown_4_[var9], 0, 4);
                func_020e4864(*var10, arg0->unknown_4_[var9], 1, 0, 0, 0);
                func_02080f8c((Struct_02080f8c*)arg0->unknown_14_, var6, (int)arg0->unknown_4_[var9]);
            }
            func_020805f4(var4, var6);
#endif
            unsigned char var11 = var1[var8];
            if (arg0->unknown_370_ == var5[var8]) var11 -= arg0->unknown_38b_;
            func_02080fa8((Struct_02080fa8*)var4, var7, var11);
        }
        var6 = (short)(var6 + 1);
        var3++;
        var7 = (short)(var7 + 1);
        var8++;
    }
    func_02080b40(var4, 0x7c);
    func_02080b40(var4, 0x7d);
    func_02080b40(var4, 0x7e);
    func_02080fa8((Struct_02080fa8*)var4, 0x7c, arg0->unknown_388_ + 1);
    func_02080fa8((Struct_02080fa8*)var4, 0x7d, arg0->unknown_389_);
    func_02081130(var4, 0x11, (arg0->unknown_394_ & 4) ? 1 : 0);
    func_020813ec(var4, 0x11);
}
