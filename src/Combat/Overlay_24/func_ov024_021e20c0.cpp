#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

void* GetActiveCombatWork_ov000_02160130(void);
extern "C" int func_ov000_0215e9fc(int battle, short* ids, int max, int flags);
extern "C" int func_ov000_0215eb1c(int battle, short* ids, int count, int flag);
unsigned short GameObject_GetPartyMemberLevel(void* obj);
extern "C" void func_ov000_021620f0(void* work, int tier, int flag);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021fe728 { short unknown_0_[8]; };
extern struct Struct_ov024_021fe728 data_ov024_021fe728;
extern unsigned char data_ov024_021fe758[4][4];

struct Struct_ov024_021e20c0 {
    unsigned char unknown_0_0_ : 7;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov024_021e20c0_2 {
    char unknown_0_[0x1a];
    short unknown_1a_;
};

struct Struct_ov024_021e20c0_3 {
    char unknown_0_[4];
    struct Struct_ov024_021e20c0_2* unknown_4_;
    char unknown_8_[0xc - 8];
    void* unknown_c_;
    void* unknown_10_;
    char unknown_14_[0x6e - 0x14];
    unsigned char unknown_6e_;
};

// USA: func_ov024_021e20c0
extern "C" ARM void* func_ov024_021e20c0(struct Obj_021e20c0* obj, int unused, int id) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    void* work = GetActiveCombatWork_ov000_02160130();
    struct Buf8_021e20c0 buf = data_ov024_021fe728;
    int count = func_ov000_0215e9fc((int)obj->field0x10, buf.v, 4, 0);
    if (count <= 0) return 0;
    GameState* gs = GameState::GetInstance();
    unsigned short total = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantWithFlag0x100_0200ff1c(gs, buf.v[i]);
        if (member) {
            total += GameObject_GetPartyMemberLevel(member);
        }
    }
    int var8 = 0;
    if (var5 >= 0xc9) {
        var8 = 3;
    } else if (var5 >= 0x79) {
        var8 = 2;
    } else if (var5 >= 0x3d) {
        var8 = 1;
    }
    unsigned char var9 = NextRandomMax((struct Random*)arg0->unknown_10_, 100);
    unsigned char* var10 = data_ov024_021fe758[var8];
    unsigned char var11;
    for (var11 = 0; var11 < 4; var11++) {
        if (var10[var11] > var9) break;
        var9 -= var10[var11];
    }
    if (var11 >= 4) var11 = 3;
    int var12 = func_ov000_0215eb1c((int)arg0->unknown_10_, var2.unknown_0_, 8, 1);
    func_ov000_021620f0(var1, var11, 1);
    if (var12 > 0) {
        if (var12 > 1) {
            arg0->unknown_4_->unknown_1a_ = 0x221;
        } else {
            arg0->unknown_4_->unknown_1a_ = 0x220;
        }
        arg0->unknown_6e_ = 1;
    }
    void* var13 = func_ov000_0215e958(arg0->unknown_10_);
    if (!var13) return 0;
    struct Struct_ov024_021e20c0* var14 = (struct Struct_ov024_021e20c0*)((char*)arg0->unknown_c_ + 0x1c);
    func_ov000_0215cd44(arg0->unknown_10_, var13, var0, 0, 0, 0, var14->unknown_0_7_ != 0);
    return var13;
}
