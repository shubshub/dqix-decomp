#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

#if defined(jpn)
#define data_ov024_021fe748 data_ov024_021fef14
#endif

struct Struct_ov024_021ea4d0;
struct Struct_ov024_021eaa50;
struct Struct_ov024_021eaa50_2;
struct Struct_ov000_02153e78_3;
struct Struct_ov024_021dced0_2;

struct Struct_ov024_021eaa50_3 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 20;
    unsigned int unknown_b_4_ : 1;
    unsigned int unknown_b_5_ : 3;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int unknown_1a_0_ : 16;
    unsigned int unknown_1c_;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    unsigned int unknown_2c_0_ : 10;
    unsigned int unknown_2d_2_ : 4;
    unsigned int unknown_2d_6_ : 18;
    char unknown_30_[2];
    short unknown_32_;
};

struct Struct_ov024_021fe748 {
    short unknown_0_[8];
};

extern Struct_ov024_021fe748 data_ov024_021fe748;

extern "C" GameObject* func_ov000_021536f8(int, int);
extern "C" int func_ov000_02153e78(Struct_ov000_02153e78_3*, short*, int, int, int);
extern "C" int func_ov000_02159c58(void*, int);
extern "C" int func_ov000_0215e9fc(char*, short*, int, unsigned int);
extern "C" int func_ov000_02159cb4(void*, int);
extern "C" int func_ov024_021eadfc(GameObject*);
extern "C" unsigned int func_020dd290(void*, unsigned int);
extern "C" int func_ov024_021dd010(Struct_ov024_021dced0_2*);
extern "C" int func_ov000_0215fd24(int, int);
extern "C" GameObject* func_0200ff58(GameState*, int);

static inline int inline_ov000_02169850(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

// USA: func_ov024_021eaa50
// KEEP-NAME
extern "C" ARM int func_ov024_021eaa50(Struct_ov024_021ea4d0* arg0, Struct_ov024_021eaa50* arg1,
                                      Struct_ov024_021eaa50_2* arg2, int arg3) {
    char* var0 = (char*)arg0;
    char* var1 = (char*)arg1;
    Struct_ov024_021eaa50_3* var2 = (Struct_ov024_021eaa50_3*)arg2;
    GameState* var3 = GameState::GetInstance();
    short var4 = *(short*)(*(char**)(var1 + 0x10) + 0x20);
    GameObject* var5 = GetCombatantByID((int)*(char**)(var0 + 0x10), var4);
    Struct_ov024_021fe748 var6 = data_ov024_021fe748;

    if (*(unsigned short*)var1 == 0x153) {
        GameObject* var7 = func_ov000_021536f8((int)*(char**)(var0 + 0x10), *(short*)(*(char**)(var1 + 0x10) + 0x20));
        if (var7 == 0) {
            *(unsigned short*)var1 = 2;
            *(unsigned char*)(var1 + 9) = 0;
            return 2;
        }
        if (func_ov000_02153e78((Struct_ov000_02153e78_3*)*(char**)(var0 + 0x10), var6.unknown_0_, 8, *((unsigned char*)var7 + 0x17c), 1) != 8) {
            *(unsigned short*)var1 = 2;
            *(unsigned char*)(var1 + 9) = 0;
            return 2;
        }
    }
    if (*(unsigned short*)var1 == 0x31a) {
        GameObject* var8 = func_ov000_021536f8((int)*(char**)(var0 + 0x10), *(short*)(*(char**)(var1 + 0x10) + 0x20));
        if (var8 == 0) {
            *(unsigned short*)var1 = 2;
            *(unsigned char*)(var1 + 9) = 0;
            return 2;
        }
        if (func_ov000_02153e78((Struct_ov000_02153e78_3*)*(char**)(var0 + 0x10), var6.unknown_0_, 8, *((unsigned char*)var8 + 0x17c), 1) != 3) {
            *(unsigned short*)var1 = 2;
            *(unsigned char*)(var1 + 9) = 0;
            return 2;
        }
    }
    if (func_ov000_02159c58(*(char**)(var0 + 0x10), *(unsigned short*)var1)) {
        if (func_ov000_0215e9fc(*(char**)(var0 + 0x10), var6.unknown_0_, 8, 1) != 4) {
            *(unsigned char*)(var1 + 9) = 0;
            *(unsigned short*)var1 = (unsigned short)func_ov000_02159cb4(*(char**)(var0 + 0x10), *(short*)(*(char**)(var1 + 0x10) + 0x20));
            return *(unsigned short*)var1;
        }
    }

    int var9 = 0;
    if (!func_ov024_021eadfc(var5) && arg3 == 0 && !var2->unknown_b_4_) {
        short var10 = (short)var2->unknown_8_0_;
        if (inline_ov000_02169850(var4)) {
            var10 = (short)func_020dd290(
                func_0200ff1c(var3, var4), (unsigned int)var10);
        }
        if (var2->unknown_8_0_ < 0xff) {
            if (var5->currentStats_->primaryStats.currMP < var10) var9 = 1;
        } else {
            if (var5->currentStats_->primaryStats.currMP == 0) var9 = 1;
        }
    }
    if (var9) {
        int var11 = 0x1f8;
        if (var2->unknown_19_4_ == 1) var11 = 0x3a9;
        unsigned short var12 = *(unsigned short*)var1;
        *(unsigned short*)(var1 + 2) = var12;
        *(unsigned char*)(var1 + 9) = 0;
        *(unsigned short*)var1 = var11;
        if (var2->unknown_10_ & 1) *((unsigned char*)var5->currentStats_ + 0x3c) |= 8;
        else *((unsigned char*)var5->currentStats_ + 0x3c) |= 0x20;
        return var11;
    }

    if ((var2->unknown_10_ & 1) && func_ov024_021dd010((Struct_ov024_021dced0_2*)var5)) {
        unsigned short var13 = *(unsigned short*)var1;
        int var14 = 0x392;
        *(unsigned short*)(var1 + 2) = var13;
        *(unsigned char*)(var1 + 9) = 0;
        *(unsigned short*)var1 = var14;
        *((unsigned char*)var5->currentStats_ + 0x3c) |= 8;
        return var14;
    }

    if (action->f2c == 6 && IsPartyMember(id)) {
        int found = 0;
        if (IsIdOrEffectMatchTarget0215fd24((int)*(char**)(a0 + 0x10), id)) {
            void* arr = GameState_GetParty(gs);
            if (*(unsigned int*)((char*)arr + 0xf6c) < action->f32) found = 1;
        } else {
            GameObject* var17 = func_0200ff58(var3, var4);
            if (var17 != 0) {
                if (((int*)(*(char**)(var0 + 0x10) + 0x8e84))[0] < var2->unknown_32_) var15 = 1;
            } else {
                if (((int*)(*(char**)(var0 + 0x10) + 0x8e84))[var4] < var2->unknown_32_) var15 = 1;
            }
        }
        if (var15) {
            unsigned short var18 = *(unsigned short*)var1;
            int var19 = 0x3a7;
            *(unsigned short*)(var1 + 2) = var18;
            *(unsigned char*)(var1 + 9) = 0;
            *(unsigned short*)var1 = var19;
            return var19;
        }
    }
    return *(unsigned short*)var1;
}
