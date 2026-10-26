#include <globaldefs.h>
#include "Resource/Script.h"

#if defined(jpn)
struct Struct_02099004 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 6;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_;
    char unknown_8_[3][0x26];
};
struct Struct_021098e8 { unsigned char unknown_0_; unsigned char unknown_1_[3]; Struct_02099004* unknown_4_; char* unknown_8_; };
extern Struct_021098e8 data_021098e8;
extern const char data_020f1670[];
extern const char data_020f1677[];
extern const char data_020f1683[];
extern const char data_020f1686[];
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_020474a8(void*, int, const char*, char*);

// JPN: func_0209abd0
extern "C" ARM int func_02099004(Script::Parameter* arg0, int arg1) {
    char var0[2];
    char var1[2];
    char var2[6];
    char var3[0xe];
    int var4;
    int var5;

    (arg0++)->ToInt();
    if (data_021098e8.unknown_4_->unknown_2_5_ != (arg0++)->ToInt()) return 0;
    void* var6 = MessageSystem_GetInstance();
    (arg0++)->ToInt();
    const char* var7 = (arg0++)->ToString();
    if (!data_021098e8.unknown_4_->unknown_3_7_) {
        var7 = (arg0++)->ToString();
    } else arg0++;
    if (data_021098e8.unknown_0_ & 0x10) var7 += 9;
    func_020474a8(var6, 12, var7, data_021098e8.unknown_8_);
    char* var8 = data_021098e8.unknown_8_;
    char* var9 = var8 + strlen(var8);
    memcpy(var2, data_020f1670, sizeof(var2));
    func_020474a8(var6, 12, data_020f1677, var3);
    memcpy(var0, data_020f1683, sizeof(var0));
    memcpy(var1, data_020f1686, sizeof(var1));
    if ((data_021098e8.unknown_0_ & 0x20) && !(data_021098e8.unknown_4_->unknown_8_[0][0] == '\x81' && data_021098e8.unknown_4_->unknown_8_[0][1] == 'E')) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        int var10 = strlen(var3);
        memcpy(var9, var3, var10);
        var9 += var10;

        memcpy(var9, data_021098e8.unknown_4_->unknown_8_[0], 0x26);
        for (var4 = 0; var4 < 0x13; var4++) {
            if (var9[var4 * 2] == '\x81' && (var9 + var4 * 2)[1] == 'E') {
                memset(var9 = var9 + var4 * 2, 0, (0x13 - var4) * 2);
                goto label0;
            }
        }
        memcpy(var9 + 0x26, var0, sizeof(var0));
        memcpy(var9 + 0x28, var1, sizeof(var1));
        var9 += 0x2a;

        memcpy(var9, data_021098e8.unknown_4_->unknown_8_[1], 0x26);
        for (var5 = 0; var5 < 0x13; var5++) {
            if (var9[var5 * 2] == '\x81' && (var9 + var5 * 2)[1] == 'E') {
                memset(var9 = var9 + var5 * 2, 0, (0x13 - var5) * 2);
                goto label0;
            }
        }
        memcpy(var9 + 0x26, var0, sizeof(var0));
        memcpy(var9 + 0x28, var1, sizeof(var1));
        var9 += 0x2a;

        memcpy(var9, data_021098e8.unknown_4_->unknown_8_[2], 0x26);
        for (var4 = 0; var4 < 0x13; var4++) {
            if (var9[var4 * 2] == '\x81' && (var9 + var4 * 2)[1] == 'E') {
                memset(var9 = var9 + var4 * 2, 0, (0x13 - var4) * 2);
                goto label0;
            }
        }
        memcpy(var9 + 0x26, var0, sizeof(var0));
        var9 += 0x28;
    }
label0:
    const char* var11 = arg0[0].ToString();
    const char* var12 = arg0[1].ToString();
    const char* var13 = arg0[2].ToString();
    const char* var14 = arg0[3].ToString();
    if (data_021098e8.unknown_0_ & 2) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        func_020474a8(var6, 12, var11, var9);
        var9 += strlen(var9);
    } else if (data_021098e8.unknown_0_ & 4) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        func_020474a8(var6, 12, var12, var9);
        var9 += strlen(var9);
    } else if (data_021098e8.unknown_0_ & 8) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        func_020474a8(var6, 12, var13, var9);
        var9 += strlen(var9);
    }
    if (data_021098e8.unknown_0_ & 1) {
        memcpy(var9, var2, sizeof(var2));
        var9 += sizeof(var2);
        func_020474a8(var6, 12, var14, var9);
        var9 += strlen(var9);
    }
    return 1;
}
#else
struct Struct_02099004 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 4;
    unsigned int unknown_3_1_ : 6;
    unsigned int unknown_3_7_ : 1;
    signed int unknown_4_0_ : 9;
    unsigned int unknown_5_1_ : 23;
    char unknown_8_[1];
};
struct Struct_021098e8 { unsigned char unknown_0_; unsigned char unknown_1_[3]; char* unknown_4_; Struct_02099004* unknown_8_; };
extern Struct_021098e8 data_021098e8;
extern unsigned char data_020e8dac[2];
struct Struct_020e8dae { char unknown_0_[7]; };
extern const Struct_020e8dae data_020e8dae;
extern "C" int MessageSystem_GetInstance();
extern "C" int STD_GetStringLength(const char*);
extern "C" char* StandardStrings_Get(int);
extern "C" void func_02098f70(int*, void*, int, int);
extern "C" void MessageSystem_FormatText(int, int, const char*, char*, int, int, int);
extern "C" void __clear(void*, int);
extern "C" int Font_DecodeText(const char*, char*, int);

// USA: func_02099004
extern "C" ARM int func_02099004(Script::Parameter* arg0, int arg1) {
    (arg0++)->ToInt();
    if (data_021098e8.unknown_8_->unknown_2_5_ != (arg0++)->ToInt()) return 0;
    int var0 = MessageSystem_GetInstance();
    (arg0++)->ToInt();
    const char* var1 = (arg0++)->ToString();
    if (!data_021098e8.unknown_8_->unknown_3_7_) {
        var1 = (arg0++)->ToString();
    } else arg0++;
    if (data_021098e8.unknown_0_ & 0x10) var1 += 17;
    MessageSystem_FormatText(var0, 12, var1, data_021098e8.unknown_4_, 0xe3, 0, 1);
    char* var2 = data_021098e8.unknown_4_;
    char* var3 = var2 + strlen(var2);
    Struct_020e8dae var4 = data_020e8dae;
    int var5 = STD_GetStringLength(var4.unknown_0_);
    char var6[0x20];
    char var7[0x400];
    char var8[0x20];
    const char* var9 = StandardStrings_Get(0x3ea);
    MessageSystem_FormatText(var0, 12, var9, var6, 0xe3, 0, 1);
    char var10[2];
    var10[0] = data_020e8dac[0];
    var10[1] = data_020e8dac[1];
    const char* var11;
    if ((data_021098e8.unknown_0_ & 0x20) && (var11 = data_021098e8.unknown_8_->unknown_8_)[0]) {
        memcpy(var3, var4.unknown_0_, var5);
        var3 += var5;
        int var12 = strlen(var6);
        memcpy(var3, var6, var12);
        var3 += var12;
        int var13 = STD_GetStringLength(var11);
        int var14 = 0;
        do {
            int var15 = var13 - var14;
            if (var15 > 19) var15 = 19;
            __clear(var8, sizeof(var8));
            memcpy(var8, var11 + var14, var15);
            __clear(var7, sizeof(var7));
            Font_DecodeText(var8, var7, 1);
            var3 += sprintf(var3, var7);
            var14 += 19;
            if (var14 >= var13) break;
            var3 += sprintf(var3, var10);
        } while (1);
    }
    const char* var16 = arg0[0].ToString();
    const char* var17 = arg0[1].ToString();
    const char* var18 = arg0[2].ToString();
    const char* var19 = arg0[3].ToString();
    const char* var20 = 0;
    if (data_021098e8.unknown_0_ & 2) var20 = var16;
    else if (data_021098e8.unknown_0_ & 4) var20 = var17;
    else if (data_021098e8.unknown_0_ & 8) var20 = var18;
    if (var20) func_02098f70((int*)&var3, (void*)var20, (int)var4.unknown_0_, var5);
    var20 = 0;
    if (data_021098e8.unknown_0_ & 1) var20 = var19;
    if (var20) func_02098f70((int*)&var3, (void*)var20, (int)var4.unknown_0_, var5);
    return 1;
}
#endif
