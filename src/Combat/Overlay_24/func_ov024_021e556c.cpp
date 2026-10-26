#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_020854e8(unsigned char* actor);
extern "C" short func_ov000_0215a1d4(void* unused, int id, int delta, short* arg3);
extern "C" void func_ov000_0215acb8(void* world, int id, int arg2, int result);

struct Struct_ov024_021e556c {
    unsigned int unknown_0_0_ : 8;
    unsigned int pair : 2;
    unsigned int rest : 22;
};

struct Struct_ov024_021e556c_2 {
    unsigned int unknown_0_0_ : 5;
    unsigned int kind : 7;
    unsigned int sub : 4;
    unsigned int rest : 16;
};

struct Struct_ov024_021e556c_3 {
    char pad0[8];
    struct Struct_ov024_021e556c f8;
    char unknown_c_[4];
    unsigned int f10;
    char unknown_14_[4];
    struct Struct_ov024_021e556c_2 f18;
};

struct Struct_ov024_021e556c_4 {
    char pad0[0x10];
    void* world;
    char unknown_14_[0x75 - 0x14];
    unsigned char unknown_75_;
};

struct Struct_ov024_021e556c_5 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    unsigned char* f150;
};

// USA: func_ov024_021e556c
extern "C" ARM void func_ov024_021e556c(struct Struct_ov024_021e556c_4* obj, int arg1, int targetId, struct Struct_ov024_021e556c_3* rec, int arg4) {
    GameState* gs = GameState::GetInstance();
    if (GetCombatantByID((int)obj->world, targetId) == 0) return;
    if (!(rec->f10 & 1)) return;
    if (rec->f8.pair != 1) return;
    int var1 = (targetId >= 0 && targetId <= 3) ? 1 : 0;
    if (!var1) return;
    int var2 = (arg1 >= 0 && arg1 <= 3) ? 1 : 0;
    if (var2) return;
    if (rec->f8.unknown_0_0_ == 0) return;
    if (rec->f18.kind == 1) {
        if (arg4 <= 0) return;
    }
    if (rec->f18.sub != 2) return;
    if (obj->unknown_75_ == 0) return;
    struct Struct_ov024_021e556c_5* target = (struct Struct_ov024_021e556c_5*)func_0200ff1c(gs, targetId);
    if (target == 0) return;
    if (func_02010088((struct S_10088*)target)) return;
    if (!func_020854e8(target->f150)) return;
    short var4 = 0;
    short result = func_ov000_0215a1d4(obj->world, targetId, rec->f8.unknown_0_0_, &var4);
    func_ov000_0215acb8(obj->world, targetId, var4, result);
}
