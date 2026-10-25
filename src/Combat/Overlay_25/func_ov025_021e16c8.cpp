#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov025_021e16c8 { char unknown_0_[0x10]; unsigned int unknown_10_; };
struct Struct_ov025_021e16c8_2 : GameObject { char unknown_13c_[0xc]; Struct_ov025_021e16c8* unknown_148_; };
struct Struct_ov025_021e16c8_3 { unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; Struct_ov025_021e16c8_2* unknown_8_; };
struct Struct_ov025_021e16c8_4 { char unknown_0_[0x20]; unsigned short unknown_20_; char unknown_22_[0xe]; Struct_ov025_021e16c8_4* unknown_30_; };
struct Struct_ov025_021e16c8_5 { short unknown_0_; char unknown_2_[0xe]; Struct_ov025_021e16c8_4* unknown_10_; };
struct Struct_ov025_021e16c8_6 { char unknown_0_[0x18]; unsigned int unknown_18_; };
struct Struct_ov025_021e16c8_7 { unsigned char unknown_0_[6]; };
struct Struct_01ff8b48_16 { int unknown_0_[3]; int unknown_c_; };
inline int* inline_ov025_021dcf14() { static Struct_01ff8b48_16 s __attribute__((aligned(4))); return &s.unknown_c_; }
extern "C" void func_ov025_021e169c(unsigned char*, int);
extern "C" unsigned char func_020493a4(unsigned char*);
extern "C" unsigned int func_020493c8(unsigned char*);
extern "C" unsigned int func_020493ec(unsigned char*);
extern "C" void func_020493b8(unsigned char*, unsigned char);
extern "C" void func_020493dc(unsigned char*, unsigned char);
extern "C" void func_02049458(unsigned char*, unsigned char);
extern "C" int func_ov025_021e1540(int);
extern "C" void func_ov000_0216f82c(Struct_ov025_021e16c8_7*, const int*);
extern "C" void func_ov025_021e1ff4(Struct_ov025_021e16c8_7*, int, unsigned char*, Struct_ov025_021e16c8_2*, Struct_ov025_021e16c8_2*, void*, void*);
extern "C" void func_ov025_021e120c(unsigned char*, int, unsigned char, unsigned char, int);
extern "C" void func_ov025_021e12f8(unsigned char*, int, int, unsigned char, int, int);
extern "C" void func_ov025_021e13e0(unsigned char*, Struct_ov025_021e16c8_3*);
extern "C" unsigned int func_ov025_021e161c(int, int, unsigned char*, int);
extern "C" void func_ov025_021e1c20(int, unsigned char*, unsigned char*, int, void*, void*, Struct_ov025_021e16c8_3*);
extern "C" unsigned char func_ov025_021e1480(int, unsigned char*, int);
extern "C" Struct_ov025_021e16c8_6* func_02079e2c(char*, int);

static inline int ActorID(FormationEntry* entry) { return entry->actor_->obj3D_.actorIndex_; }
static inline void SetCell(unsigned char* cells, unsigned int index, unsigned char value) {
    if (index < 81) cells[index] = value;
}

// USA: func_ov025_021e16c8
extern "C" ARM void func_ov025_021e16c8(Struct_ov025_021e16c8_3* arg0, Struct_ov025_021e16c8_3* arg1, unsigned char* arg2,
    Struct_ov025_021e16c8_5* arg3, Struct_ov025_021e16c8_6* arg4, void* arg5, void* arg6) {
    unsigned char var0[81];
    unsigned char var1[81];
    unsigned char var2[81];
    unsigned char var3[12];
    Struct_ov025_021e16c8_7 var4;
    unsigned char var5[6];
    Struct_ov025_021e16c8_7 var6;
    func_ov025_021e169c(arg2, arg0->unknown_1_);
    memcpy(var0, arg2, 81);
    memset(var1, 0, 81);
    int var7 = 0;
    for (Struct_ov025_021e16c8_4* var8 = arg3->unknown_10_; var8; var8 = var8->unknown_30_) {
        if (var8->unknown_20_ == inline_ov025_021e16c8(arg0)) { var7 = 1; break; }
    }
    unsigned int var9 = func_020493a4((unsigned char*)arg1->unknown_8_);
    if (!var7) {
        var9 = func_020493ec((unsigned char*)arg1->unknown_8_);
        if (var9 == 255) var9 = func_020493c8((unsigned char*)arg1->unknown_8_);
        if (var9 == 255) var9 = func_020493a4((unsigned char*)arg1->unknown_8_);
    } else {
        int var10 = func_ov025_021e1540(arg1->unknown_0_);
        func_ov000_0216f82c(&var6, &var10);
        var4 = var6;
        func_ov025_021e1ff4(&var4, 6, arg2, arg0->unknown_8_, arg1->unknown_8_, arg5, arg6);
    }
    Struct_ov025_021e16c8* var11 = 0;
    int var12 = 2;
    int var13 = 1;
    if (arg1->unknown_8_->obj3D_.unknown_0_ & 0x400) var11 = arg1->unknown_8_->unknown_148_;
    if (var11) {
        unsigned int var14 = (var11->unknown_10_ << 1) >> 30;
        if (var14) { var12 += var14; var13 += var14; }
    }
    func_ov025_021e120c(var0, var9, var12, var13, 0);
    if (var7) {
        func_ov025_021e120c(var1, var9, var12, var13, 0);
        inline_ov025_021e120c_2(var1, var9, arg1->unknown_1_);
        unsigned int var15 = 0;
        if (var11) {
            unsigned int var16 = (var11->unknown_10_ << 1) >> 30;
            if (var16) var15 = var16;
        }
        func_ov025_021e12f8(var1, var9, arg1->unknown_1_, var15, (unsigned char)var13, 0);
    }
    if (var11) {
        unsigned int var17 = (var11->unknown_10_ << 1) >> 30;
        if (var17) func_ov025_021e12f8(var0, var9, arg0->unknown_1_, var17, 0, 0);
    }
    int var18 = 0;
    if (var7) {
        int var19 = var0[func_020493a4((unsigned char*)arg0->unknown_8_)];
        if ((arg4->unknown_18_ << 16) >> 28 == 2) {
            if (var12 == var19) var18 = 1;
        } else if (var19 > 0 && var19 <= var12) {
            var18 = 1;
            if (var12 - 1 == var0[func_020493a4((unsigned char*)arg0->unknown_8_)]) {
                int var20 = 1;
                int* var21 = inline_ov025_021dcf14();
                *var21 = var20;
            }
        }
    } else if (var12 == var0[func_020493a4((unsigned char*)arg0->unknown_8_)]) var18 = 1;
    if (var18) {
        func_ov025_021e13e0(arg2, arg0);
        if (var7) {
            unsigned int var22 = func_ov025_021e161c(func_020493a4((unsigned char*)arg0->unknown_8_), var9, var0, var12);
            if (var22 != 255) {
                func_020493dc((unsigned char*)arg0->unknown_8_, var22);
                inline_ov025_021e120c_2(arg2, (unsigned char)var22, arg0->unknown_1_);
            }
            func_ov025_021e1c20(func_020493a4((unsigned char*)arg0->unknown_8_), arg2, var1, var12, arg5, arg6, arg0);
        }
        return;
    }
    unsigned char var23 = 0;
    unsigned char var24 = 0;
    for (int var25 = 0; var25 < 81; ++var25) {
        if (var0[var25] == var12 - 1) var5[var23++] = var25;
        else if (var0[var25] == var12) var3[var24++] = var25;
    }
    unsigned char var26 = 255;
    if (var24 == 1) var26 = var3[0];
    else if (var24 > 1) var26 = func_ov025_021e1480(func_020493a4((unsigned char*)arg0->unknown_8_), var3, var24);
    else if (var23 == 1) var26 = var5[0];
    else if (var23 > 1) var26 = func_ov025_021e1480(func_020493a4((unsigned char*)arg0->unknown_8_), var5, var23);
    if (var7) {
        Struct_ov025_021e16c8_6* var27 = func_02079e2c((char*)func_020797dc(), arg3->unknown_0_);
        if (var27 && (var27->unknown_18_ << 16) >> 28 != 2) {
            memset(var2, 0, 81);
            func_ov025_021e120c(var2, var9, 1, var13, 0);
            int var28 = func_020493a4((unsigned char*)arg0->unknown_8_);
            if ((var28 < 81 && var2[var28] == 1) || var9 == var28) var26 = (unsigned char)var28;
        }
    }
    if (var26 >= 81) var26 = func_020493a4((unsigned char*)arg0->unknown_8_);
    func_020493b8((unsigned char*)arg0->unknown_8_, var26);
    if (var26 < 81) inline_ov025_021e120c_2(arg2, var26, arg0->unknown_1_);
    if (var7) {
        unsigned int var29 = func_ov025_021e161c(var26, var9, var0, var12);
        if (var29 != 255) {
            func_020493dc((unsigned char*)arg0->unknown_8_, var29);
            inline_ov025_021e120c_2(arg2, (unsigned char)var29, arg0->unknown_1_);
        }
    }
    if (var7) func_ov025_021e1c20(var26, arg2, var1, var12, arg5, arg6, arg0);
    func_02049458((unsigned char*)arg0->unknown_8_, arg1->unknown_0_);
}
