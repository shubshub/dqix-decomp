#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_ov000_02169b04;
struct Struct_ov000_02169b54;
struct Struct_ov000_0215440c_2;
struct Struct_ov000_02163a7c;

struct Struct_ov000_02169b04_2 {
    char pad0[8];
    unsigned short kind;
};

struct Struct_ov025_021db8d8 {
    char pad0[0x20];
    unsigned short id;
};

struct Struct_ov025_021db8d8_2 {
    char pad0[0xe];
    short id;
};

struct Struct_ov025_021db8d8_3 {
    char pad0[0x10];
    struct Struct_ov025_021db8d8* actor;
    struct Struct_ov025_021db8d8_2* target;
};

struct Struct_ov025_021db8d8_4 {
    unsigned char b0 : 2;
    unsigned char pending : 1;
    unsigned char b3 : 5;
};

struct Struct_ov025_021db8d8_5 {
#if defined(jpn)
    char pad0[0x800];
    char camera[0xa7c - 0x800];
#else
    char pad0[0xc00];
    char camera[0xe7c - 0xc00];
#endif
    struct Struct_ov025_021db8d8_3* slot;
};

struct Struct_ov025_021db8d8_6 {
#if defined(jpn)
    char pad0[0x218];
    void* battle;
    char unknown_21c_[0x224 - 0x21c];
    struct Struct_ov000_02169b04* keys;
    char unknown_228_[0x3e8 - 0x228];
    unsigned int unknown_46c_;
    char unknown_3ec_[0x7f2 - 0x3ec];
    unsigned short unknown_876_;
    char unknown_7f4_[0xe28 - 0x7f4];
    int unknown_eac_;
    char unknown_e2c_[0x57c8 - 0xe2c];
    int unknown_55d8_;
    char unknown_57cc_[0x5b41 - 0x57cc];
    struct Struct_ov025_021db8d8_4 unknown_5951_;
#else
    char pad0[0x29c];
    void* battle;
    char unknown_2a0_[0x2a8 - 0x2a0];
    struct Struct_ov000_02169b04* keys;
    char unknown_2ac_[0x46c - 0x2ac];
    unsigned int unknown_46c_;
    char unknown_470_[0x876 - 0x470];
    unsigned short unknown_876_;
    char unknown_878_[0xeac - 0x878];
    int unknown_eac_;
    char unknown_eb0_[0x55d8 - 0xeb0];
    int unknown_55d8_;
    char unknown_55dc_[0x5951 - 0x55dc];
    struct Struct_ov025_021db8d8_4 unknown_5951_;
#endif
};

extern "C" struct Struct_ov025_021db8d8_3* func_ov000_02160f20(void*);
extern "C" void* func_ov000_02160f60(void*);
extern "C" unsigned int func_02049444(unsigned char*);
extern "C" int func_020493ec(unsigned char*);
extern "C" int func_020493c8(unsigned char*);
extern "C" void func_020493dc(unsigned char*, unsigned char);
extern "C" void func_02049390(unsigned char*, unsigned char);
extern "C" struct Struct_ov000_02169b04_2* func_ov000_02169b04(struct Struct_ov000_02169b04*, int);
extern "C" struct Struct_ov000_02169b04_2* func_ov000_02169b54(struct Struct_ov000_02169b54*, int);
extern "C" struct Struct_ov025_021db8d8* func_ov000_02160094(struct Struct_ov000_0215440c_2*, int);
extern "C" void func_ov000_02167dd8(unsigned char*);
extern "C" void func_ov000_02163a7c(struct Struct_ov000_02163a7c*);
extern "C" int func_ov025_021dfa9c(void* obj, void* battle);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" int func_ov000_02153e40(void* battle, short* ids, int max, int start);
extern "C" void func_02048cf0(GameObject* obj, int arg1);
extern "C" void func_ov000_0216e678(void* camera, int first, int second, int arg3, int active);
extern "C" void func_ov000_0216d464(void* camera);
extern "C" void func_02048e2c(GameObject* obj);
extern "C" void func_ov025_021dc220(void* obj);
extern "C" void func_ov025_021eb7fc(void* obj);

#if defined(jpn)
#define SUB_021db8d8 0x394
#else
#define SUB_021db8d8 0x18
#endif

// USA: func_ov025_021db8d8
extern "C" ARM void func_ov025_021db8d8(struct Struct_ov025_021db8d8_6* self) {
    int dist;
    struct Struct_ov000_02169b04_2* a;
    GameState* game;
    void* battle;
    int actorId;
    int ok;
    struct Struct_ov000_02169b04_2* b;
    int var7;
    GameState* var8;
    int count2;
    int row;
    int pos;
    GameState* game2;
    struct Struct_ov000_02169b04* keys;
    game = GameState::GetInstance();
    battle = self->battle;
    struct Struct_ov025_021db8d8_5* sub = (struct Struct_ov025_021db8d8_5*)((char*)self + SUB_021db8d8);
    struct Struct_ov025_021db8d8_3* slot = func_ov000_02160f20(self);
    actorId = -1;
    if (slot->actor) {
        actorId = slot->actor->id;
    }
    GameObject* actor = game->GetCombatantByIndex(actorId);
    int targetId = -1;
    if (slot->target) {
        targetId = slot->target->id;
    }
    int var18 = 0;
    if (actor && func_02049444((unsigned char*)actor)) {
        var18 = 1;
    }
    int var19 = 0;
    keys = self->keys;
    if (keys) {
        struct Struct_ov000_02169b04_2* node = func_ov000_02169b04(keys, 0xc);
        ok = 1;
        a = func_ov000_02169b04(keys, 0x3d);
        b = func_ov000_02169b04(keys, 7);
        if (node && ((a && node == func_ov000_02169b54((struct Struct_ov000_02169b54*)a, 0xc)) ||
                     (b && node == func_ov000_02169b54((struct Struct_ov000_02169b54*)b, 0xc)))) {
            ok = 0;
        }
        if (ok) {
            if (node && node->kind != 0xa) {
                var19 = 1;
            } else if (func_ov000_02169b04(keys, 0x20)) {
                var19 = 1;
            } else if (func_ov000_02169b04(keys, 0x22)) {
                var19 = 1;
            }
        }
    }
    if (func_ov025_021dfa9c(self, self->battle)) {
        var18 = 0;
        var19 = 1;
    }
    int started = 0;
    if (var18 || !var19) {
        func_ov000_021626a0(self, 4, 1);
        var7 = 0;
        GameObject* target = game->GetCombatantByIndex(targetId);
        if (target && func_020493ec((unsigned char*)target) != 0xff) {
            void* list = func_ov000_02160f60(self);
            if (list) {
                struct Struct_ov025_021db8d8* first = func_ov000_02160094((struct Struct_ov000_0215440c_2*)list, 0);
                if (first && first->id == targetId) {
                    var7 = 1;
                }
            }
        }
        if (actor && target) {
            Vector3fix from = actor->obj3D_.position_;
            Vector3fix to = target->obj3D_.position_;
            dist = Vector3fix_Distance(&from, &to);
            if (dist < (actor->obj3D_.GetRadius() + target->obj3D_.GetRadius()) >> 1) {
                var7 = 1;
            }
        }
        if (self->unknown_55d8_ != 0) {
            var8 = GameState::GetInstance();
            short ids[12];
            int count = func_ov000_02153e40(battle, ids, 12, 0);
            int any;
            for (int i = 0; i < count; i++) {
                GameObject* c = var8->GetCombatantByIndex(ids[i]);
                if (c && func_02049444((unsigned char*)c) >= 5) {
                    any = 1;
                    goto checked;
                }
            }
            any = 0;
        checked:
            if (!any && !var7) {
                goto quiet;
            }
        }
        {
            int i;
            game2 = GameState::GetInstance();
            int id = -1;
            if (slot->actor) {
                id = slot->actor->id;
            }
            GameObject* obj = game2->GetCombatantByIndex(id);
            int var35 = -1;
            if (slot->target) {
                var35 = slot->target->id;
            }
            row = pos = 0xff;
            if (obj) {
                pos = func_020493ec((unsigned char*)obj);
                row = func_020493c8((unsigned char*)obj);
            }
            short ids[12];
            count2 = func_ov000_02153e40(battle, ids, 12, 0);
            for (i = 0; i < count2; i++) {
                GameObject* c = game2->GetCombatantByIndex(ids[i]);
                if (c) {
                    func_02048cf0(c, var35 == ids[i]);
                }
            }
            if (obj) {
                func_020493dc((unsigned char*)obj, pos);
                if (pos != 0xff && row != 0xff) {
                    func_02049390((unsigned char*)obj, row);
                }
            }
            func_ov000_02167dd8((unsigned char*)self);
            sub->slot = slot;
            func_ov000_0216e678(sub->camera, actorId, targetId, 0, 1);
            func_ov000_02163a7c((struct Struct_ov000_02163a7c*)self);
            self->unknown_5951_.pending = 0;
            var18 = 0;
            if (var19) {
                self->unknown_876_ = 0x1f4;
            }
            goto shown;
        }
    quiet:
        sub->slot = slot;
        func_ov000_0216e678(sub->camera, actorId, targetId, 0, 0);
        func_ov000_02167dd8((unsigned char*)self);
    shown:
        started = 1;
        func_ov000_0216d464(sub->camera);
    }
    if (self->unknown_5951_.pending && var19) {
        self->unknown_46c_ |= 0x40;
    }
    if (var18 || (self->unknown_5951_.pending && !var19)) {
        int i;
        int count;
        GameState* var40 = GameState::GetInstance();
        short ids[12];
        count = func_ov000_02153e40(battle, ids, 12, 0);
        for (i = 0; i < count; i++) {
            GameObject* c = var40->GetCombatantByIndex(ids[i]);
            if (c) {
                func_02048e2c(c);
            }
        }
        if (var18) {
            self->unknown_eac_ = 2;
        } else {
            func_ov025_021dc220(self);
        }
    } else {
        func_ov025_021dc220(self);
    }
    if (started) {
        func_ov025_021eb7fc(&self->keys);
    }
}
