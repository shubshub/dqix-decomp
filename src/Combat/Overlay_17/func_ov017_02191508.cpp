#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov017_02191508 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_ov017_02191508_2 {
#if defined(jpn)
    char unknown_0_[0xd];
#else
    char unknown_0_[0x12];
#endif

    unsigned char unknown_12_;
    unsigned char unknown_13_;
    Struct_ov017_02191508 unknown_14_[3];
};

struct Struct_ov017_02191508_3 {
    unsigned int unknown_0_0_ : 32;
    unsigned short unknown_4_0_ : 7;
    unsigned short unknown_4_7_ : 9;
    Struct_ov017_02191508 unknown_8_[3];
};

struct Struct_ov017_02191508_4 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_ov017_02191508_5 {
    unsigned char unknown_0_[0x130];
    Struct_ov017_02191508_4* unknown_130_;
    BaseCombatStats* unknown_134_;
};

struct Struct_ov017_02191508_6 {
    unsigned char unknown_0_[0x3c];
    char unknown_3c_[0x16c - 0x3c];
    unsigned short unknown_16c_;
    unsigned char unknown_16e_[0x56a - 0x16e];
    unsigned char unknown_56a_;
};

extern "C" Struct_ov017_02191508_6* func_02053c6c(unsigned char* arg0);
extern "C" void func_02083cbc(void* arg0, void* arg1, void* arg2);
extern "C" void func_02083e28(void* arg0, int arg1);
extern "C" void func_02083ca0(unsigned char* arg0, int arg1);
extern "C" void func_02083c18(char* arg0);
extern "C" void func_02083b60(unsigned char* arg0, int arg1);

extern char g_stringFormat[];

// USA: func_ov017_02191508
extern "C" ARM void func_ov017_02191508(int arg0, Struct_ov017_02191508_2* arg1) {
    Struct_ov017_02191508_5* var0 =
        (Struct_ov017_02191508_5*)func_0200ff1c(GameState::GetInstance(), arg0);
    if (var0 == NULL) return;
    Struct_ov017_02191508_6* var1 = func_02053c6c((unsigned char*)var0);
    if (var1 == NULL) return;

    int var2 = -1;
    if (strcmp(var1->unknown_3c_, arg1->unknown_0_) == 0) {
        var2 = var0->unknown_130_->unknown_4_;
    }
#if defined(jpn)
    sprintf(member->name, g_stringFormat, tmpl->name);

#else
    if (tmpl != NULL) {
        sprintf(member->name, g_stringFormat, tmpl->name);
    } else {
        sprintf(member->name, g_stringFormat, member->name);
    }

#endif
    Struct_ov017_02191508_3 var3;
    var3.unknown_0_0_ = 0;
    var3.unknown_4_7_ = 0;
    var3.unknown_4_0_ = arg1->unknown_12_;
    var3.unknown_8_[0].unknown_0_0_ = arg1->unknown_14_[0].unknown_0_0_;
    var3.unknown_8_[0].unknown_1_2_ = arg1->unknown_14_[0].unknown_1_2_;
    var3.unknown_8_[0].unknown_2_4_ = arg1->unknown_14_[0].unknown_2_4_;
    var3.unknown_8_[1].unknown_0_0_ = arg1->unknown_14_[1].unknown_0_0_;
    var3.unknown_8_[1].unknown_1_2_ = arg1->unknown_14_[1].unknown_1_2_;
    var3.unknown_8_[1].unknown_2_4_ = arg1->unknown_14_[1].unknown_2_4_;
    var3.unknown_8_[2].unknown_0_0_ = arg1->unknown_14_[2].unknown_0_0_;
    var3.unknown_8_[2].unknown_1_2_ = arg1->unknown_14_[2].unknown_1_2_;
    var3.unknown_8_[2].unknown_2_4_ = arg1->unknown_14_[2].unknown_2_4_;
    var1->unknown_56a_ = 0xb;
    func_02083cbc(var1, &var3, NULL);
    func_02083e28(var1, 0);

    if (var2 > -1) {
        var0->unknown_130_->unknown_4_ = var2;
    } else {
        var0->unknown_130_->unknown_4_ = var0->unknown_134_->primaryStats.maxHP;
    }
    var0->unknown_130_->unknown_6_ = var0->unknown_134_->primaryStats.maxMP;
    func_02083ca0((unsigned char*)var1, 0);
    func_02083c18((char*)var1);
    var1->unknown_16c_ = arg1->unknown_12_;
    func_02083b60((unsigned char*)var1, arg1->unknown_13_);
}
