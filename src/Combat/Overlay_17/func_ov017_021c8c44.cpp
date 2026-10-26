#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Entry0207d9bc;
struct Struct_02053f7c_3;

struct Struct_ov017_021c8c44 {
    unsigned char tag;
    unsigned char pad1[3];
    int target;
    unsigned short key;
    unsigned char flag;
};

struct Struct_ov017_021c8c44_2 {
    Object3D obj3D;
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
    int idx[4];
};

extern const Struct_ov017_021d6d18 data_ov017_021d6d18;

extern "C" GameObject* func_0200ff58(GameState* gameState, int combatantId);
extern "C" int func_020546a8(void* obj);
extern "C" void func_0202738c(void* a, int b, int c, int d);
extern "C" void func_02027304(void* obj, int id);
extern "C" void func_ov017_021b86f8(void* obj, int key, int a, int flag);
extern "C" int LinkSession_IsHostOrSolo(void* search);
extern "C" Entry0207d9bc* func_0207d78c(void);
extern "C" void func_0207da7c(Entry0207d9bc* arr, unsigned short key);
extern "C" void func_ov017_021a33e0(void* ctx, int key);
extern "C" void func_02053f7c(Struct_02053f7c_3* obj, unsigned short a, int b);
extern "C" void func_ov017_021907dc(int a, int b, int c, int d, int e);
extern "C" void func_ov017_02197324(unsigned char* obj, unsigned short key);

// USA: func_ov017_021c8c44
extern "C" ARM void func_ov017_021c8c44(int id, Struct_ov017_021c8c44* evt, GameState* gs, unsigned char* ctx, void* search) {
    int match;
    int key = evt->key;
    int flag = evt->flag != 0;
    int target = evt->target;
    GameState* inst = GameState::GetInstance();
    void* var5 = GetGameResources()->unknown_ptr_36d0;
    int i;

    for (i = 0; i < 4; i++) {
        match = 0;
        if (i == id) {
            match = 1;
        } else {
            GameObject* c = func_0200ff58(inst, i);
            if (c != NULL && id == func_020546a8(c)) {
                match = 1;
            }
        }
        if (match) {
            func_0202738c(var5, 0, 1, i);
            func_02027304(var5, i);
        }
    }

#if defined(jpn)
    func_ov017_021b86f8(*(void**)(ctx + 0x3508), key, 1, flag);
#else
    func_ov017_021b86f8(*(void**)(ctx + 0x3718), key, 1, flag);
#endif

    if (LinkSession_IsHostOrSolo(search)) {
        func_0207da7c(func_0207d78c(), key);
        if (target != -1) {
            Struct_ov017_021d6d18 list = data_ov017_021d6d18;
            int n = 0;
            for (i = 0; i < 4; i++) {
                Struct_ov017_021c8c44_2* m = (Struct_ov017_021c8c44_2*)gs->GetPartyMemberByIndex(i);
                if (m != NULL) {
                    if (target == m->obj3D.GetField06() || target == m->unknown_15c_) {
                        list.idx[n] = i;
                        n++;
                    }
                }
            }
            if (n == 1 && list.idx[0] != 0) {
                func_ov017_021a33e0(ctx, target);
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        Struct_ov017_021c8c44_2* c = (Struct_ov017_021c8c44_2*)func_0200ff1c(gs, j);
        if (c != NULL) {
            if (id == c->obj3D.actorIndex_) {
                func_02053f7c((Struct_02053f7c_3*)c, 0, 1);
            } else if (c->obj3D.unknown_0_ & 0x1000) {
                Struct_ov017_021c8c44_2* leader = (Struct_ov017_021c8c44_2*)func_0200ff1c(gs, 0);
                if (leader != NULL) {
                    func_02053f7c((Struct_02053f7c_3*)c, leader->unknown_1b2_, 1);
                }
            }
        }
    }

    func_ov017_021907dc((int)ctx, id, 1, 1, 1);
    func_ov017_02197324(ctx, key);
}
