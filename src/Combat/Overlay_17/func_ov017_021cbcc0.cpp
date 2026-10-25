#if defined(jpn)
enum { Enum_ov017_021cbcc0_1816 = 0x508 };
#else
enum { Enum_ov017_021cbcc0_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask);
int GameState_GetProtagonistIndex(GameState* battleStruct);
void SetByteFields0x77d3And0x77d4_ov000_0216872c(void* obj, int a, int b);
extern "C" void __clear(void* buf, int len);
extern "C" void func_ov017_021b848c(void* h, void* buf, int a, int b, int c, int d, int e, int f);

struct Struct_ov017_021cbcc0 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
};

struct Struct_ov017_021cbcc0_2 {
    unsigned char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned int unknown_8_;
    unsigned char unknown_c_;
    signed char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    signed char unknown_10_;
    unsigned char unknown_11_;
    signed short unknown_12_;
};

// USA: func_ov017_021cbcc0
extern "C" ARM void func_ov017_021cbcc0(int arg0, Struct_ov017_021cbcc0_2* arg1, GameState* arg2, unsigned char* arg3) {
    unsigned short var0;
    unsigned short var1;
    unsigned int var2;
    unsigned char var3;
    unsigned char var4;
    Struct_ov017_021cbcc0* var5;
    void* var6;
    void* var7;
    void* var8 = *(void**)(arg3 + 0x3000 + Enum_ov017_021cbcc0_1816);
    var5 = (Struct_ov017_021cbcc0*)func_ov017_021b8478(var8);
    if (!var5) return;
    var6 = func_ov017_021b8470(var8);
    if (!var6) return;
    var7 = func_ov017_021b8468(var8);
    if (!var7) return;

    var0 = arg1->unknown_4_;
    var1 = var5->unknown_8_;
    var2 = arg1->unknown_8_;
    var3 = arg1->unknown_e_;
    var4 = arg1->unknown_f_;
    if (var0 != var1) return;

    SetCombatWorkFlags0x55f4_ov000_02160fa8(field6ac, 0x80000000);
    int idx = GameState_GetProtagonistIndex(battleStruct);
    if (!(evt->field0xc & (1 << idx))) return;

    *(unsigned char*)((char*)var6 + 0x8e48) = (unsigned char)var2;
    func_ov000_0216872c(var7, var3, var4);

    unsigned char var10[4];
    __clear(var10, 4);
    for (int var11 = 0; var11 < 4; var11++) {
        if (arg1->unknown_c_ & (1 << var11)) var10[var11] = 1;
        else var10[var11] = 0;
    }
    func_ov017_021b848c(var8, var10, arg1->unknown_d_, 1, arg1->unknown_6_, arg1->unknown_10_, 1, arg1->unknown_12_);
}
