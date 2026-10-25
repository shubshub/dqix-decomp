#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_0200f3a4_7 { char unknown_0_[0x568]; short unknown_568_; };
struct Struct_ov017_02190264 {
    GameObject unknown_0_;
#if defined(jpn)
    char unknown_13c_[0x0c];
#else
    char unknown1_13c_[0x18];
#endif
    short* unknown_154_;
    char unknown_158_[0x17a];
    unsigned char unknown_2d2_;
};
struct Struct_ov000_02161e30_4 { char unknown_0_[2]; unsigned char unknown_2_; };
struct Struct_ov017_021d622c { int unknown_0_[13]; };
struct Struct_ov017_02190264_2 { int unknown_0_[4]; };
struct Struct_02000c9c_12;
struct Struct_0202c1a4;
extern "C" int* func_0202ae18();
extern "C" int func_ov017_021925e0();
extern "C" Struct_0200f3a4_7* func_02053c6c(unsigned char*);
extern "C" void func_02082828(Struct_0200f3a4_7*);
extern "C" void func_ov017_021bd3d4(void*, int);
extern "C" Struct_ov000_02161e30_4* func_ov017_021a4658(GameResources*, int);
extern "C" void func_02046a8c(void*, Struct_ov000_02161e30_4*);
extern "C" void func_ov017_021b33d8(void*);
extern "C" int func_0202b7d8(int*);
extern "C" void* func_020120a0(char*, unsigned int);
extern "C" int func_020535c8(signed char*);
extern "C" void func_020531f0(GameObject*);
extern "C" void func_020545ac(short*);
extern "C" int func_020115a8(Struct_02000c9c_12*);
extern "C" void func_0200fd48(GameState*, int);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);
extern "C" signed char func_0202c1a4(Struct_0202c1a4*);
extern "C" void func_ov017_02190884(int, Struct_ov017_02190264_2*, int*, int, int, int);
extern "C" void func_ov017_02191234(GameResources*);
#if defined(jpn)
#define data_ov017_021d622c data_ov017_021d667c
#endif
extern Struct_ov017_021d622c data_ov017_021d622c;
static inline int inline_020dc548(int arg0) { return arg0 >= 0 && arg0 <= 3; }

// USA: func_ov017_02190264
extern "C" ARM void func_ov017_02190264(GameResources* arg0, int arg1) {
    int var0 = inline_020dc548(arg1);
    if (!var0) return;
    GameState* var1 = GameState::GetInstance();
    int* var2 = func_0202ae18();
    void* var3 = arg0->unknown_ptr_array_371c[6];
    if (func_ov017_021925e0()) {
        GameObject* var4 = var1->GetPartyMemberByIndex(arg1);
        if (var4 && (var4->obj3D_.unknown_0_ & 0x1000)) {
            Struct_0200f3a4_7* var5 = func_02053c6c((unsigned char*)var4);
            if (var5) {
                short var6 = var5->unknown_568_;
                func_02082828(var5);
                var5->unknown_568_ = var6;
            }
            func_ov017_021bd3d4(var3, (unsigned char)arg1);
            return;
        }
    }
    PartySlot* slot = func_ov017_021a4658(resources, index);
    if (slot->active) {
        func_02046a8c(resources->unknown_ptr_array_3700[0], slot);
        ResetEntriesAndNotify_021b33d8(slot);
    }
    GameObject* var8 = func_0200ff1c(var1, arg1);
    if (var8) {
        if (func_0202b7d8(var2) && (var8->obj3D_.unknown_0_ & 0x200)) {
            short* var9 = (short*)func_020120a0((char*)var1, arg1);
            if (var9) *var9 = 0;
        }
        if (func_020535c8((signed char*)var8)) func_020531f0(var8);
        strcpy(arg0->unknown_435c_[arg1], (char*)var8->baseStats_);
        short* var10 = ((Struct_ov017_02190264*)var8)->unknown_154_;
        if (var10) func_020545ac(var10);
        if (!func_020115a8((Struct_02000c9c_12*)var1)) {
            Struct_0200f3a4_7* var11 = func_02053c6c((unsigned char*)var8);
            if (var11) func_02082828(var11);
        }
    }
    Struct_ov017_021d622c var12 = data_ov017_021d622c;
    var12.unknown_0_[0] = arg1;
    var12.unknown_0_[1] = arg1 * 12 + 0x13;
    var12.unknown_0_[2] = arg1 * 12 + 0x14;
    var12.unknown_0_[3] = arg1 * 12 + 0x15;
    var12.unknown_0_[4] = arg1 * 12 + 0x16;
    var12.unknown_0_[5] = arg1 * 12 + 0x17;
    var12.unknown_0_[6] = arg1 * 12 + 0x18;
    var12.unknown_0_[7] = arg1 * 12 + 0x19;
    var12.unknown_0_[8] = arg1 * 12 + 0x1a;
    var12.unknown_0_[9] = arg1 * 12 + 0x1b;
    var12.unknown_0_[10] = arg1 * 12 + 0x1c;
    var12.unknown_0_[11] = arg1 * 12 + 0x1d;
    for (int var13 = 0; var12.unknown_0_[var13] >= 0; var13++) func_0200fd48(var1, var12.unknown_0_[var13]);
    int var14;
    GameState* var15 = GameState::GetInstance();
    Struct_ov017_02190264* var16[4] = {};
    for (var14 = 1; var14 < 4; var14++) {
        Struct_ov017_02190264* var17 = (Struct_ov017_02190264*)func_0200ff58(var15, var14);
        if (var17) var16[var17->unknown_2d2_] = var17;
    }
    int var18;
    Struct_ov017_02190264** var19 = var16;
    int var20 = 1;
    for (var18 = 0; var18 < 4; var18++) { Struct_ov017_02190264* var21 = *var19; if (var21) var21->unknown_2d2_ = var20++; var19++; }
    if (!func_0202b7d8(var2)) {
        func_ov017_02191108(arg0, 1, 1, 1, 1);
        return;
    }
    for (int var22 = 0; var22 < 4; var22++) {
        if (var22 == func_0202c1a4((Struct_0202c1a4*)var2)) func_ov017_02191108(arg0, 1, 1, 1, 1);
        else {
            Struct_ov017_02190264_2 var23;
            int var24 = 0;
            func_ov017_02190884(var22, &var23, &var24, 1, 1, 1);
        }
    }
    func_ov017_02191234(arg0);
}
