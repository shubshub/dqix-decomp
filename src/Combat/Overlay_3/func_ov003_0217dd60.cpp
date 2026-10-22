#include <globaldefs.h>

struct Struct_0205de24_2;
struct Struct_0205ba68;
struct Struct_0205d81c;
struct Struct_0205bacc;
struct Struct_0201099c_3;

struct Struct_ov003_0217dd60 {
    char unknown_0_[0x8];
    int unknown_8_;
    char unknown_c_[0x58 - 0xc];
    int unknown_58_;
    char unknown_5c_[0x68 - 0x5c];
    int unknown_68_;
    char unknown_6c_[0x94 - 0x6c];
    unsigned char unknown_94_;
    unsigned char unknown_95_;
    char unknown_96_[0xa0 - 0x96];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[0xb5 - 0xb2];
    unsigned char unknown_b5_;
};

#if defined(jpn)
struct Struct_ov003_0217dd60_2 {
    char unknown_0_[0x14];
    unsigned char unknown_14_[0x2c - 0x14];
    unsigned char unknown_2c_;
    char unknown_2d_;
    unsigned char unknown_2e_;
    char unknown_2f_[0x8c - 0x2f];
    struct Struct_ov003_0217dd60* unknown_8c_;
    char unknown_90_[0xc8 - 0x90];
    char unknown_c8_[4];
};
#else
struct Struct_ov003_0217dd60_2 {
    char unknown_0_[0x10];
    int unknown_10_;
    char unknown_14_[0x18 - 0x14];
    unsigned char unknown_18_[0x30 - 0x18];
    unsigned char unknown_30_;
    char unknown_31_;
    unsigned char unknown_32_;
    char unknown_33_[0x90 - 0x33];
    struct Struct_ov003_0217dd60* unknown_90_;
    char unknown_94_[0xcc - 0x94];
    char unknown_cc_[4];
};
#endif

extern "C" void func_0205de24(struct Struct_0205de24_2*, unsigned char, unsigned char);
extern "C" void func_0205cf04(void*);
extern "C" void func_0205cef8(void*);
extern "C" int func_020421a0();
extern "C" void func_02012fe4();
extern "C" void __clear(void* arg0, int arg1);
extern "C" int func_020e0434(struct Struct_0201099c_3* arg0, int arg1);
extern "C" void func_02041b70(char* arg0, int arg1, const char* arg2);
extern "C" void func_02042058(char* arg0, const char* arg1);
extern "C" unsigned char* func_0205e00c(struct Struct_0205d81c* arg0, int arg1);
extern "C" void func_02050400(unsigned char* arg0, int arg1);
extern "C" void func_0205042c(unsigned char* arg0, unsigned char arg1);
extern "C" void func_02050440(unsigned char* arg0, int arg1);
#if defined(jpn)
struct Struct_020465c0;
extern "C" void func_0205d304(void* arg0, char* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
extern "C" void func_02046380(void* arg0);
extern "C" void func_020465c0(struct Struct_020465c0*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char* arg0, int arg1);
#else
extern "C" void func_0205d304(void* arg0, char* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif
void GridCursor_SetDimensions(struct Struct_0205ba68* t, int a, int b, int c);
void GridCursor_SetCount(struct Node0205bacc* n, int value);

extern const char data_ov003_02180c7f[];

// USA: func_ov003_0217dd60
#if defined(jpn)
extern "C" ARM void func_ov003_0217dd60(struct Struct_ov003_0217dd60_2* arg0) {
    char var0[0x400];
    func_02012fe4();
    struct Struct_020465c0* var1 = (struct Struct_020465c0*)func_020421a0();
    func_0205de24((struct Struct_0205de24_2*)arg0->unknown_8c_, 0, 1);
    arg0->unknown_8c_->unknown_b1_ = 0;
    {
        struct Struct_ov003_0217dd60* var2 = arg0->unknown_8c_;
        var2->unknown_a0_ = 14;
        var2->unknown_a2_ = 11;
    }
    {
        struct Struct_ov003_0217dd60* var3 = arg0->unknown_8c_;
        var3->unknown_a4_ = 9;
        var3->unknown_a6_ = 2;
    }
    {
        struct Struct_ov003_0217dd60* var4 = arg0->unknown_8c_;
        var4->unknown_a8_ = 13;
        var4->unknown_aa_ = 6;
    }
    {
        struct Struct_ov003_0217dd60* var5 = arg0->unknown_8c_;
        var5->unknown_ac_ = 10;
        var5->unknown_ae_ = 13;
    }
    arg0->unknown_8c_->unknown_b5_ = 1;
    func_0205cf04(arg0->unknown_8c_);
    func_0205cef8(arg0->unknown_8c_);
    int var6;
    int var7;
    int var8 = arg0->unknown_8c_->unknown_68_;
    __clear(var0, 0x400);
    var6 = (var8 + 1) * 6;
    if (var6 > arg0->unknown_2c_) {
        var6 = arg0->unknown_2c_;
    }
    for (var7 = var8 * 6; var7 < var6; var7++) {
        const char* var9 = (const char*)func_020e0434((struct Struct_0201099c_3*)arg0->unknown_c8_, (short)(arg0->unknown_14_[var7] + 100));
        func_02041b70(var0, var7 % 6, var9);
        if (var7 != var6 - 1) {
            func_02042058(var0, data_ov003_02180c7f);
        }
    }
    if (arg0->unknown_2e_ > 1) {
        func_02046380(var1);
        func_020465c0(var1, 0, var8 + 1);
        func_020465c0(var1, 1, arg0->unknown_2e_);
        func_020465f0((unsigned char*)var1, 0, 2);
        func_020465f0((unsigned char*)var1, 1, 2);
        func_020465d8((unsigned char*)var1, 0, 1);
        func_020465d8((unsigned char*)var1, 1, 0);
        func_02042428(var0, 8);
        func_02042058(var0, (const char*)func_020e0434((struct Struct_0201099c_3*)arg0->unknown_c8_, 200));
    }
    if (arg0->unknown_2e_ > 1) {
        func_0205d304(arg0->unknown_8c_, var0, 0, 0, 1, 1, 0);
    } else {
        func_0205d304(arg0->unknown_8c_, var0, 0, 0, 0, 1, 0);
    }
    int field32 = menu->field32;
    struct ListWindow0217dd60* window = menu->window;
    window->field8 = field32;
    window->field58 = field32;
    GridCursor_SetDimensions((struct Struct_0205ba68*)((char*)window + 4), 1, 6, 0);
    GridCursor_SetDimensions((struct Struct_0205ba68*)((char*)window + 0x54), 1, 6, 0);
    unsigned char itemCount = menu->itemCount;
    GridCursor_SetCount((struct Node0205bacc*)((char*)window + 4), itemCount);
    GridCursor_SetCount((struct Node0205bacc*)((char*)window + 0x54), itemCount);
    window->field94 = 1;
    window->field95 = 1;
}
#else
extern "C" ARM void func_ov003_0217dd60(struct Struct_ov003_0217dd60_2* arg0) {
    char var13[0x400];
    func_02012fe4();
    func_020421a0();
    func_0205de24((struct Struct_0205de24_2*)arg0->unknown_90_, 0, 1);
    int var14 = arg0->unknown_10_;
    arg0->unknown_90_->unknown_b1_ = 0;
    short var15 = (short)(var14 >> 3);
    {
        struct Struct_ov003_0217dd60* var16 = arg0->unknown_90_;
        var16->unknown_a0_ = var15;
        var16->unknown_a2_ = 11;
    }
    {
        struct Struct_ov003_0217dd60* var17 = arg0->unknown_90_;
        var17->unknown_a4_ = (32 - var15) >> 1;
        var17->unknown_a6_ = 2;
    }
    {
        struct Struct_ov003_0217dd60* var18 = arg0->unknown_90_;
        var18->unknown_a8_ = 12;
        var18->unknown_aa_ = 6;
    }
    {
        struct Struct_ov003_0217dd60* var19 = arg0->unknown_90_;
        var19->unknown_ac_ = 10;
        var19->unknown_ae_ = 13;
    }
    if (arg0->unknown_32_ > 1) {
        struct Struct_ov003_0217dd60* var20 = arg0->unknown_90_;
        var20->unknown_a0_ = var15;
        var20->unknown_a2_ = 12;
    }
    arg0->unknown_90_->unknown_b5_ = 1;
    func_0205cf04(arg0->unknown_90_);
    func_0205cef8(arg0->unknown_90_);
    int var21;
    int var22;
    int var23 = arg0->unknown_90_->unknown_68_;
    __clear(var13, 0x400);
    var21 = (var23 + 1) * 6;
    if (var21 > arg0->unknown_30_) {
        var21 = arg0->unknown_30_;
    }
    for (var22 = var23 * 6; var22 < var21; var22++) {
        const char* var24 = (const char*)func_020e0434((struct Struct_0201099c_3*)arg0->unknown_cc_, (short)(arg0->unknown_18_[var22] + 100));
        func_02041b70(var13, var22 % 6, var24);
        if (var22 != var21 - 1) {
            func_02042058(var13, data_ov003_02180c7f);
        }
    }
    if (arg0->unknown_32_ > 1) {
        unsigned char* var25 = func_0205e00c((struct Struct_0205d81c*)arg0->unknown_90_, 0);
        if (var25 != NULL) {
            func_02050400(var25, 1);
            func_0205042c(var25, var23);
            func_02050440(var25, arg0->unknown_32_);
        }
    }
    if (arg0->unknown_32_ > 1) {
        func_0205d304(arg0->unknown_90_, var13, 0, 0, 1, 1, 0, 0);
    } else {
        func_0205d304(arg0->unknown_90_, var13, 0, 0, 0, 1, 0, 0);
    }
    int field32 = menu->field32;
    struct ListWindow0217dd60* window = menu->window;
    window->field8 = field32;
    window->field58 = field32;
    GridCursor_SetDimensions((struct Struct_0205ba68*)((char*)window + 4), 1, 6, 0);
    GridCursor_SetDimensions((struct Struct_0205ba68*)((char*)window + 0x54), 1, 6, 0);
    unsigned char itemCount = menu->itemCount;
    GridCursor_SetCount((struct Node0205bacc*)((char*)window + 4), itemCount);
    GridCursor_SetCount((struct Node0205bacc*)((char*)window + 0x54), itemCount);
    window->field94 = 1;
    window->field95 = 1;
}
#endif
