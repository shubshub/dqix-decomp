#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" void* func_ov000_02160130(void);
extern "C" int func_ov000_0215e9fc(int battle, short* ids, int max, int flags);
extern "C" int func_ov000_0215eb1c(int battle, short* ids, int count, int flag);
extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);
extern "C" void func_ov000_021620f0(void* work, int arg1, int flag);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021fe728 { short v[8]; };
extern struct Struct_ov024_021fe728 data_ov024_021fe728;
extern unsigned char data_ov024_021fe758[4][4];

struct Struct_ov024_021e20c0 {
    unsigned char pad : 7;
    unsigned char flag : 1;
};

struct Struct_ov024_021e20c0_2 {
    char pad0[0x1a];
    short messageId;
};

struct Struct_ov024_021e20c0_3 {
    char pad0[4];
    struct Struct_ov024_021e20c0_2* msg;
    char pad8[0xc - 8];
    void* unknown_c_;
    void* unknown_10_;
    char unknown_14_[0x6e - 0x14];
    unsigned char unknown_6e_;
};

// USA: func_ov024_021e20c0
extern "C" ARM void* func_ov024_021e20c0(struct Struct_ov024_021e20c0_3* obj, int unused, int id) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    void* work = func_ov000_02160130();
    struct Struct_ov024_021fe728 buf = data_ov024_021fe728;
    int count = func_ov000_0215e9fc((int)obj->unknown_10_, buf.v, 4, 0);
    if (count <= 0) return 0;
    GameState* gs = GameState::GetInstance();
    unsigned short total = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = func_0200ff1c(gs, buf.v[i]);
        if (member) {
            total += GameObject_GetPartyMemberLevel(member);
        }
    }
    int var8 = 0;
    if (total >= 0xc9) {
        var8 = 3;
    } else if (total >= 0x79) {
        var8 = 2;
    } else if (total >= 0x3d) {
        var8 = 1;
    }
    unsigned char roll = NextRandomMax((struct Random*)obj->unknown_10_, 100);
    unsigned char* weights = data_ov024_021fe758[var8];
    unsigned char k;
    for (k = 0; k < 4; k++) {
        if (weights[k] > roll) break;
        roll -= weights[k];
    }
    if (k >= 4) k = 3;
    int found = func_ov000_0215eb1c((int)obj->unknown_10_, buf.v, 8, 1);
    func_ov000_021620f0(work, k, 1);
    if (found > 0) {
        if (found > 1) {
            obj->msg->messageId = 0x221;
        } else {
            obj->msg->messageId = 0x220;
        }
        obj->unknown_6e_ = 1;
    }
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    struct Struct_ov024_021e20c0* var14 = (struct Struct_ov024_021e20c0*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var14->flag != 0);
    return entry;
}
