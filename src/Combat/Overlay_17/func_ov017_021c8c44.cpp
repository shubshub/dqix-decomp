#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_0207d7f4;
struct Struct_02053f7c_3;

struct Struct_ov017_021c8c44 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    int unknown_4_;
    unsigned short unknown_8_;
    unsigned char unknown_a_;
};

struct Struct_ov017_021c8c44_2 {
    Object3D unknown_0_;
#if defined(jpn)
    unsigned char unknown_ac_[0x150 - sizeof(Object3D)];
#else
    unsigned char unknown1_ac_[0x15c - sizeof(Object3D)];
#endif
    int unknown_15c_;
    unsigned char unknown_160_[0x1b2 - 0x160];
    unsigned short unknown_1b2_;
};

struct Struct_ov017_021d6d18 {
    int unknown_0_[4];
};

extern const Struct_ov017_021d6d18 data_ov017_021d6d18;

GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* gameState, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);
extern "C" void func_0202738c(void* a, int b, int c, int d);
extern "C" void func_02027304(void* obj, int id);
extern "C" void func_ov017_021b86f8(void* obj, int key, int a, int flag);
extern "C" int LinkSession_IsHostOrSolo(void* search);
Entry0207d9bc* GetData02108ea8_0207d78c(void);
void ResetEntryByKey0207da7c(Entry0207d9bc* arr, unsigned short key);
void EnqueueEventForFlaggedCombatants_021a33e0(void* ctx, int key);
void SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c* obj, unsigned short a, int b);
#define SetField0x1b2IfMatchOrFlag02053f7c SetField0x1b2IfMatchOrFlag02053f7c
void CallHelperWithBuf_021907dc(int a, int b, int c, int d, int e);
void ClearMatchingHalfword_02197324(unsigned char* obj, unsigned short key);

// USA: func_ov017_021c8c44
extern "C" ARM void func_ov017_021c8c44(int arg0, Struct_ov017_021c8c44* arg1, GameState* arg2, unsigned char* arg3, void* arg4) {
    int var0;
    int var1 = arg1->unknown_8_;
    int var2 = arg1->unknown_a_ != 0;
    int var3 = arg1->unknown_4_;
    GameState* var4 = GameState::GetInstance();
    void* var5 = GetGameResources()->unknown_ptr_36d0;
    int var6;

    for (var6 = 0; var6 < 4; var6++) {
        var0 = 0;
        if (var6 == arg0) {
            var0 = 1;
        } else {
            GameObject* var7 = func_0200ff58(var4, var6);
            if (var7 != NULL && arg0 == func_020546a8(var7)) {
                var0 = 1;
            }
        }
        if (var0) {
            func_0202738c(var5, 0, 1, var6);
            func_02027304(var5, var6);
        }
    }

#if defined(jpn)
    func_ov017_021b86f8(*(void**)(arg3 + 0x3508), var1, 1, var2);
#else
    func_ov017_021b86f8(*(void**)(arg3 + 0x3718), var1, 1, var2);
#endif

    if (LinkSession_IsHostOrSolo(search)) {
        ResetEntryByKey0207da7c(GetData02108ea8_0207d78c(), key);
        if (target != -1) {
            IndexList021c8c44 list = data_ov017_021d6d18;
            int n = 0;
            for (i = 0; i < 4; i++) {
                Combatant021c8c44* m = (Combatant021c8c44*)gs->GetPartyMemberByIndex(i);
                if (m != NULL) {
                    if (target == m->obj3D.GetField06() || target == m->field_15c) {
                        list.idx[n] = i;
                        n++;
                    }
                }
            }
            if (var9 == 1 && var8.unknown_0_[0] != 0) {
                func_ov017_021a33e0(arg3, var3);
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        Combatant021c8c44* c = (Combatant021c8c44*)GetCombatantWithFlag0x100_0200ff1c(gs, j);
        if (c != NULL) {
            if (id == c->obj3D.actorIndex_) {
                SetField0x1b2IfMatchOrFlag02053f7c((Obj02053f7c*)c, 0, 1);
            } else if (c->obj3D.unknown_0_ & 0x1000) {
                Combatant021c8c44* leader = (Combatant021c8c44*)GetCombatantWithFlag0x100_0200ff1c(gs, 0);
                if (leader != NULL) {
                    SetField0x1b2IfMatchOrFlag02053f7c((Obj02053f7c*)c, leader->field_1b2, 1);
                }
            }
        }
    }

    func_ov017_021907dc((int)arg3, arg0, 1, 1, 1);
    func_ov017_02197324(arg3, var1);
}
