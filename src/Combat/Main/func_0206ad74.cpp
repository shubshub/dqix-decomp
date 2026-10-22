#include <globaldefs.h>
#include "std_library_functions.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
extern "C" int func_02069408(void*, unsigned short);
extern "C" int func_02069430(void*, unsigned short);
extern "C" void func_0206cb14(void*, int, unsigned short);
extern "C" void __clear(void*, int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern const char data_020f07ce[];
extern const char data_020f0aeb[];

// JPN: func_0206c794
extern "C" ARM void func_0206c794(void* arg0) {
    Struct_02021b84* var0 = static_cast<Struct_02021b84*>(arg0);
    unsigned short var1[16];
    unsigned char var2 = 0;
    __clear(var1, sizeof(var1));
    unsigned short* var3 = static_cast<unsigned short*>(var0->unknown_1c_);
    int var4 = 0;
    var0->unknown_1774_ = 0;
    unsigned char var5 = var0->unknown_17f3_;
    for (;;) {
        if (func_02069408(var0, *var3)) {
            var2 = 0;
            var0->unknown_1774_ = -1;
            var0->unknown_1772_ = 0;
            var0->unknown_19c4_ = 0;
            var4 = 1;
            break;
        }
        if (!func_02069430(var0, *var3)) {
            if (func_02001aec(var3, data_020f07ce, 2) == 0) {
                var0->unknown_17f3_ = 0;
                break;
            }
            var1[var2] = *var3;
            var2 = (unsigned char)(var2 + 1) & 15;
        }
        var0->unknown_1774_++;
        var3++;
    }
    var3++;
    for (;;) {
        if (func_02069408(var0, *var3)) break;
        if (!func_02069430(var0, *var3)) {
            if (func_02001aec(var3, data_020f0aeb, 2) == 0) {
                var2 = 0;
                var0->unknown_1774_ = -1;
                var0->unknown_1772_ = 0;
                var0->unknown_19c4_ = 0;
                var0->unknown_17f3_ = var5;
                var4 = 1;
                break;
            }
            if (func_02001aec(var3, data_020f07ce, 2) == 0) break;
        }
        var3++;
    }
    if (!var0->unknown_17f3_ && var2) {
        unsigned short var6;
        for (unsigned char var7 = 0; var7 < var0->unknown_1772_; var7++) {
            var6 = var0->unknown_1752_[var7];
            if (!func_02069430(var0, var6)) {
                Struct_0204166c* var8 = &var0->unknown_9b8_[var6];
                if (var8->unknown_8_ >= 0 &&
                    var8->unknown1_18_ != var1[var7]) {
                    var4 = 1;
                    break;
                }
            }
        }
    }
    if (var4) {
        for (unsigned char var9 = 0; var9 < var0->unknown_1772_; var9++)
            func_0206cb14(var0, 10, var0->unknown_1752_[var9]);
        memset(var0->unknown_1752_, 0xff01, sizeof(var0->unknown_1752_));
        var0->unknown_19c3_ = 0;
    } else if (var0->unknown_1772_) {
        var0->unknown_6c_ = (short)var0->unknown_1774_;
        var0->unknown1_40_ = var0->unknown_1774_;
        var0->unknown_78_ = (short)var0->unknown_1774_;
        return;
    }
    var0->unknown_1772_ = 0;
}
#else

struct Entry0204254c { int value; signed char width; signed char advance : 6; signed char field5 : 2; unsigned char field6[2]; };
Entry0204254c* Font_FindCharacter(int, int);
int GetWordFromTable02042648(int);
struct CombatSlots0206b198;
void DecrementSlotRef0206b198(CombatSlots0206b198*, unsigned short);
extern char data_020f08dc[];
extern char data_020f0979[];
extern char data_020f097c[];
extern "C" void __clear(void*, int);
struct Struct_0206ad74 {
    unsigned char unknown_0_[0x50];
    char* unknown_50_;
    unsigned char unknown_54_[0x74-0x54];
    int unknown_74_;
    int unknown_78_;
    unsigned char unknown_7c_[8];
    int unknown_84_;
    int unknown_88_;
    unsigned char unknown_8c_[0x912-0x8c];
    unsigned char unknown_912_;
    unsigned char unknown_913_[0x934-0x913];
    short unknown_934_;
    short unknown_936_;
    unsigned char unknown_938_[0x1882-0x938];
    unsigned short unknown_1882_[64];
    char unknown_1902_[64];
    unsigned short unknown_1942_;
    short unknown_1944_;
    short unknown_1946_;
    unsigned char unknown_1948_[0x19c2-0x1948];
    unsigned char unknown_19c2_;
    unsigned char unknown_19c3_;
    unsigned char unknown_19c4_[0x19dc-0x19c4];
    unsigned char unknown_19dc_;
};

// USA: func_0206ad74
extern "C" ARM void func_0206ad74(Struct_0206ad74* arg0) {
    int var0;
    int var1 = 0;
    arg0->unknown_84_ = 0;
    arg0->unknown_88_ = 0;
    arg0->unknown_1944_ = 0;
    arg0->unknown_1942_ = 0;
    arg0->unknown_1946_ = 0;
    unsigned char var2 = arg0->unknown_19c2_;
    int var3 = 1;
    int var4 = 0;
    char var5[64];
    __clear(var5, sizeof(var5));
    unsigned char var6;
    char* var7;
    char* var8 = arg0->unknown_50_;
    char* var9 = strstr(var8, data_020f08dc);
    char* var10 = strstr(var8, data_020f0979);
    char* var11 = strstr(var8, data_020f097c);
    var6 = func_02042648(arg0->unknown_19dc_);
    if (var9) {
        for (;;) {
            if (var8 == var9) break;
            unsigned short var12;
            memcpy(&var12, var8, 2);
            var4++;
            if ((var12 & 0xff00) == 0xff00) var8++;
            var8++;
        }
        char* var13 = var9 + 2;
        char* var14 = strstr(var13, data_020f08dc);
        if (var14) {
            var1 = var14 - var13;
            memcpy(var5, var13, var1);
            var3 = 0;
            arg0->unknown_19c2_ = var3;
            var7 = var5;
            for (;;) {
                defaultWidth = fontWidth + 1;
                if (!*cursor) break;
                Entry0204254c* entry = Font_FindCharacter((int)cursor, self->font);
                if (entry) {
                    self->count++;
                    int width = entry->width;
                    int advance = entry->advance;
                    self->width += width + 1;
                    cursor += advance;
                } else {
                    arg0->unknown_1942_++;
                    var7++;
                    arg0->unknown_1944_ += var0;
                }
            }
            arg0->unknown_1946_ = var14 - var9;
            arg0->unknown_1946_ += 3;
            arg0->unknown_1946_ += var4 - 2;
            arg0->unknown_912_ = 4;
            short var18 = 8 - (arg0->unknown_1944_ & 7);
            arg0->unknown_934_ = arg0->unknown_1944_ + 18 + var18;
            arg0->unknown_936_ = 22;
        } else arg0->unknown_19c2_ = var2;
    } else {
        if (var10 || var11) arg0->unknown_912_ = 3;
        else arg0->unknown_1946_ = -1;
    }
    if (!arg0->unknown_19c2_ && var1) var3 = strcmp(arg0->unknown_1902_, var5);
    if (var3) {
        for (int var19 = 0; var19 < arg0->unknown_1942_; var19++) func_0206b198((Struct_0204500c_4*)arg0, arg0->unknown_1882_[var19]);
        memset(arg0->unknown_1882_, 0xff01, sizeof(arg0->unknown_1882_));
        memset(arg0->unknown_1902_, 0, sizeof(arg0->unknown_1902_));
        memcpy(arg0->unknown_1902_, var5, var1);
        arg0->unknown_19c3_ = 0;
        if (arg0->unknown_1942_) {
            arg0->unknown_84_ = arg0->unknown_1946_;
            arg0->unknown_88_ = arg0->unknown_1942_ + var4 + 3;
        }
    } else if (arg0->unknown_1942_) {
        arg0->unknown_84_ = arg0->unknown_1946_;
        arg0->unknown_88_ = arg0->unknown_1942_ + var4 + 3;
        arg0->unknown_74_ = arg0->unknown_1942_ + var4 + 3;
        arg0->unknown_78_ = arg0->unknown_1942_ + var4 + 3;
        arg0->unknown_1942_++;
        return;
    }
    arg0->unknown_1942_ = 0;
}

#endif
