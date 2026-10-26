#include "GameState/GameState.h"
#include "Util/Random.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct *arr, int value);
extern "C" int LinkSession_IsActive(int *p);
extern "C" int func_ov002_02154b94(void *self, int id);
extern "C" int func_ov002_02154a34(void *self, int id);
extern "C" int *LinkSession_GetInstance(void);
extern "C" void func_ov002_02153e90(char *entry);
extern "C" int func_ov002_02154a6c(char *self, int id, int arg);
extern "C" int func_ov002_02153be0(char *self, int target, int arg);
extern "C" void func_02048150(GameObject *m, int amount, int flag);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void Party_ReformLine(GameResources *r, int a, int b, int c, int d);

struct Struct_ov002_02154230 {
    short kind;
    signed char arg;
    unsigned char count;
    signed char ids[4];
};

struct Struct_ov002_02154230_2 {
    unsigned char state;
    unsigned char pad;
    short amount;
    unsigned char flag;
    unsigned char pad5;
};

// USA: func_ov002_02154230
extern "C" ARM int func_ov002_02154230(char *base, struct Struct_ov002_02154230 *arg1, int target, int arg3) {
    if (arg1 == NULL) return 0;
    if (target == 0) return 0;
    GameState *gs                  = GameState::GetInstance();
    GameResources *res             = GetGameResources();
    ArrayContainsByteStruct *party = (ArrayContainsByteStruct *) GameState_GetParty(gs);
    int *ctx                       = LinkSession_GetInstance();
    struct Struct_ov002_02154230_2 *recs       = (struct Struct_ov002_02154230_2 *) ((char *) arg1 + 8);
    unsigned char any              = 0;
    if (arg3) recs = (struct Struct_ov002_02154230_2 *) ((char *) arg1 + 0x20);
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90((char *) &recs[i]);
    }
    for (int i = 0; i < arg1->count; i++) {
        struct Struct_ov002_02154230_2 *rec = &recs[i];
        int id                  = arg1->ids[i];
        if (!func_02086ef0(party, id)) rec->flag = 1;
        if (!func_ov002_02154a6c(base, id, arg1->arg)) {
            rec->state = 1;
            continue;
        }
        if (func_ov002_02154b94(base, id)) {
            rec->state = 2;
            continue;
        }
        if (func_ov002_02154a34(base, id)) continue;
        int amount       = 0;
        unsigned char ok = 0;
        GameObject *m    = func_0200ff1c(gs, id);
        if (m == NULL) continue;
        if (arg1->kind == 0x27) {
            ok     = 1;
            amount = m->baseStats_->primaryStats.maxHP / 2;
            if (m->baseStats_->primaryStats.maxHP % 2) amount++;
        } else if (arg1->kind == 0x26) {
            ok       = 0;
            int rate = func_ov002_02153be0(base, target, arg1->arg);
            if (NextRandomMax(GetBTRandom(), 100) < rate) {
                ok     = 1;
                int v  = m->baseStats_->primaryStats.maxHP * (rate - 25);
                amount = v / 100;
                if (v % 100) amount++;
            }
        } else if (arg1->kind == 0x197) {
            ok     = 1;
            amount = 999;
        }
        if (!ok) continue;
        rec->state = 3;
        if (rec->flag) {
            rec->amount = amount;
            rec->state  = 3;
        } else {
            func_02048150(m, amount, 1);
        }
        if (LinkSession_IsActive(ctx) && func_02086ef0(party, id)) {
            func_ov017_021c9e00(id, 1, 0, 1);
        }
        if (func_02086ef0(party, id)) {
            Party_ReformLine(res, 1, 1, 1, 1);
        }
        any = 1;
    }
    return any;
}
