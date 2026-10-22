#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_02082828_5 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};
struct Struct_02082cdc {
    Struct_02082828_5 unknown_0_[3];
};
struct Struct_02082828 {
    unsigned char unknown_0_[0x16];
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};
struct Struct_020827c4 {
    unsigned char unknown_0_[0x1c];
};
struct Struct_02082828_2;
struct Struct_02082828_3 {
    unsigned int unknown_0_[10];
    short unknown_28_;
    unsigned short unknown_2a_;
};
struct Struct_02082828_4 {
    Struct_02082828_5 unknown_0_[6];
    unsigned int unknown_18_;
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    unsigned char unknown_20_;
    Struct_02082828 unknown_21_;
    unsigned char unknown_39_[3];
    char unknown_3c_[48];
    unsigned short unknown_6c_;
    unsigned short unknown_6e_;
    unsigned short unknown_70_;
    unsigned short unknown_72_;
    unsigned short unknown_74_;
    unsigned short unknown_76_;
    unsigned int unknown_78_;
    Struct_02082828 unknown_7c_;
    unsigned char unknown_94_[0xa4];
    unsigned int unknown_138_[13];
    unsigned short unknown_16c_[13];
    unsigned char unknown_186_[13];
    unsigned char unknown_193_[0x161];
    Struct_02082828_3 unknown_2f4_[8];
    unsigned char unknown_454_[16];
    unsigned char unknown_464_[27];
    unsigned char unknown_47f_[9];
    Struct_020827c4 unknown_488_;
    unsigned char unknown_4a4_[0xc0];
    unsigned short unknown_564_;
    unsigned short unknown_566_;
    short unknown_568_;
    unsigned char unknown_56a_;
    unsigned char unknown_56b_;
    unsigned char unknown_56c_;
    unsigned char unknown_56d_;
    unsigned char unknown_56e_;
#if defined(jpn)
    unsigned char unknown_56f_[0x7b8 - 0x56f];
#else
    unsigned char unknown1_56f_[0x850 - 0x56f];
#endif
    Struct_02082cdc unknown_850_[13];
    unsigned char unknown_8ec_[36];
    unsigned char unknown_910_[9];
    unsigned char unknown_919_[3];
    Struct_02082828_5 unknown_91c_[6];
    unsigned char unknown_934_[22];
    unsigned short unknown_94a_;
    unsigned int unknown_94c_;
    unsigned int unknown_950_;
    unsigned short unknown_954_;
    unsigned short unknown_956_;
    short unknown_958_;
    unsigned short unknown_95a_;
    unsigned short unknown_95c_;
    short unknown_95e_;
    unsigned short unknown_960_;
    unsigned short unknown_962_;
};
extern "C" void func_020891cc(void*);
extern "C" void func_02082cdc(Struct_02082cdc*);
extern "C" void func_020827c4(Struct_020827c4*);
extern "C" void func_02082d38(Struct_02082828*, Struct_02082828*);
extern "C" void func_02083508(Struct_02082828_2*);
extern "C" void func_020c99ac(void*);
extern char data_020f1010[];
extern char g_stringFormat[];

#if defined(jpn)
extern char data_020f1130[];
#endif

// USA: func_02082828
extern "C" ARM void func_02082828(Struct_02082828_4* arg0) {
    unsigned char var0 = 0;
    arg0->unknown_568_ = -1;
    for (var0 = 0; var0 < 13; var0++) {
        arg0->unknown_16c_[var0] = 1;
        arg0->unknown_186_[var0] = 0;
        arg0->unknown_138_[var0] = 0;
    }
    arg0->unknown_94c_ = 5;
    arg0->unknown_950_ = 0;
    arg0->unknown_954_ = 0;
    memset(arg0->unknown_3c_, 0, 48);
    arg0->unknown_6c_ = 1;
    arg0->unknown_6e_ = 0;
    arg0->unknown_70_ = 0;
    arg0->unknown_72_ = 0;
    arg0->unknown_74_ = 0;
    arg0->unknown_78_ &= ~0x3ff;
    arg0->unknown_78_ &= ~0x40000000;
    memset(arg0->unknown_7c_.unknown_0_, 100, 22);
    memset(arg0->unknown_0_, 0, 24);
    arg0->unknown_0_[2].unknown_1_2_ = 1;
    memset(arg0->unknown_91c_, 0, 24);
    arg0->unknown_91c_[2].unknown_1_2_ = 1;
    memset(arg0->unknown_934_, 100, 22);
    func_020891cc(arg0->unknown_94_);
    for (int var1 = 0; var1 < 13; var1++) func_02082cdc(&arg0->unknown_850_[var1]);
    func_020827c4(&arg0->unknown_488_);
    memset(arg0->unknown_4a4_, -1, 192);
    arg0->unknown_91c_[0].unknown_0_0_ = 0;
    arg0->unknown_0_[0].unknown_0_0_ = arg0->unknown_91c_[0].unknown_0_0_;
    arg0->unknown_91c_[0].unknown_2_4_ = 0;
    arg0->unknown_0_[0].unknown_2_4_ = arg0->unknown_91c_[0].unknown_2_4_;
    arg0->unknown_91c_[0].unknown_1_2_ = 0;
    arg0->unknown_0_[0].unknown_1_2_ = arg0->unknown_91c_[0].unknown_1_2_;
    arg0->unknown_91c_[1].unknown_0_0_ = 0;
    arg0->unknown_0_[1].unknown_0_0_ = arg0->unknown_91c_[1].unknown_0_0_;
    arg0->unknown_91c_[1].unknown_1_2_ = 0;
    arg0->unknown_0_[1].unknown_1_2_ = arg0->unknown_91c_[1].unknown_1_2_;
    arg0->unknown_91c_[1].unknown_2_4_ = 0;
    arg0->unknown_0_[1].unknown_2_4_ = arg0->unknown_91c_[1].unknown_2_4_;
    arg0->unknown_91c_[2].unknown_0_0_ = 0;
    arg0->unknown_0_[2].unknown_0_0_ = arg0->unknown_91c_[2].unknown_0_0_;
    arg0->unknown_91c_[2].unknown_1_2_ = 1;
    arg0->unknown_0_[2].unknown_1_2_ = arg0->unknown_91c_[2].unknown_1_2_;
    arg0->unknown_91c_[2].unknown_2_4_ = 0;
    arg0->unknown_0_[2].unknown_2_4_ = arg0->unknown_91c_[2].unknown_2_4_;
    arg0->unknown_6c_ = arg0->unknown_0_[2].unknown_1_2_;
    arg0->unknown_6e_ = arg0->unknown_0_[2].unknown_2_4_;
    arg0->unknown_564_ = 0;
    arg0->unknown_56c_ = 0;
    arg0->unknown_56d_ = 0;
    arg0->unknown_56e_ = 0;
    arg0->unknown_1c_ = arg0->unknown_6c_;
    arg0->unknown_1e_ = arg0->unknown_6e_;
    func_02082d38(&arg0->unknown_21_, &arg0->unknown_7c_);
    arg0->unknown_18_ = 0;
    arg0->unknown_20_ = 0;
    memset(arg0->unknown_454_, -1, 16);
    memset(arg0->unknown_464_, 0, 27);
    func_02083508((Struct_02082828_2*)arg0);
    memset(arg0->unknown_8ec_, 0, 36);
    memset(arg0->unknown_910_, 0, 9);
    for (unsigned char var2 = 0; var2 < 8; var2++) {
        arg0->unknown_2f4_[var2].unknown_0_[0] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[1] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[2] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[3] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[4] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[5] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[6] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[7] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[8] = 0;
        arg0->unknown_2f4_[var2].unknown_0_[9] = 0;
        arg0->unknown_2f4_[var2].unknown_28_ = -1;
    }
    unsigned char var3[6];
#if defined(jpn)
    char var8[11];
    func_020c99ac(var3);
    char var4[] = "\x82\x60";
    char var5[] = "\x82\x60";
    signed char var6 = (var3[0] + var3[1] + var3[2]) % 26;
    var4[1] += var6;
    signed char var7 = (var3[3] + var3[4] + var3[5]) % 26;
    var5[1] += var7;
    sprintf(var8, data_020f1130, var4, var5);
#else
    char var8[18];
    func_020c99ac(var3);
    int var9 = (var3[0] + var3[2] + var3[4]) % 26;
    int var10 = (var3[1] + var3[3] + var3[5]) % 26;
    sprintf(var8, data_020f1010, (signed char)(var9 + 65), (signed char)(var10 + 65));
#endif
    sprintf(object->name, g_stringFormat, suffix);
    object->field956 = 0;
    object->field958 = -1;
    object->field95a = 0;
    object->field95c = 0;
    object->field95e = -1;
    object->field960 = 0;
    object->field962 = 0;
    object->nibbles &= ~15;
    object->nibbles &= ~240;
}
