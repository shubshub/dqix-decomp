#include <globaldefs.h>
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;

extern "C" int *LinkSession_GetInstance(void);
extern "C" int func_02086ef0(ArrayContainsByteStruct *arr, int value);
extern "C" int LinkSession_IsActive(int *p);
extern "C" int func_ov002_02154a34(void *self, int id);
extern "C" int func_ov002_02154b94(void *self, int id);

struct Struct_ov002_02153ea4 {
    unsigned char state;
    unsigned char pad1;
    unsigned short value;
    unsigned char unknown_4_;
    unsigned char pad5;
};

struct Struct_ov002_02153ea4_2 {
    unsigned char pad0[2];
    signed char kind;
    unsigned char count;
    signed char ids[4];
    Struct_ov002_02153ea4 entries[4];
    Struct_ov002_02153ea4 unknown_20_[4];
};

extern "C" void func_ov002_02153e90(Struct_ov002_02153ea4 *e);
extern "C" int func_ov002_02154a6c(void *self, int id, int kind);
extern "C" unsigned short func_ov002_021549c8(void *self, int id, int mode, Struct_ov002_02153ea4 *e);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_ov002_02153ea4
extern "C" ARM int func_ov002_02153ea4(void *self, Struct_ov002_02153ea4_2 *info, int enabled, int arg3) {
    if (info == 0) return 0;
    if (enabled == 0) return 0;
    ArrayContainsByteStruct *party = (ArrayContainsByteStruct *)GameState_GetParty(GameState::GetInstance());
    int *g                         = LinkSession_GetInstance();
    int changed                    = 0;
    Struct_ov002_02153ea4 *entries         = info->entries;
    if (arg3) entries = info->unknown_20_;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(&entries[i]);
    }
    for (int i = 0; i < info->count; i++) {
        Struct_ov002_02153ea4 *e = &entries[i];
        int id           = info->ids[i];
        if (!func_02086ef0(party, id)) e->unknown_4_ = 1;
        if (!func_ov002_02154a6c(self, id, info->kind)) {
            e->state = 1;
            continue;
        }
        if (func_ov002_02154b94(self, id)) {
            e->state = 2;
            continue;
        }
        if (!func_ov002_02154a34(self, id)) continue;
        if (e->unknown_4_) {
            e->value = 1;
            e->state = 3;
        } else {
            e->value = func_ov002_021549c8(self, id, 2, e);
        }
        if (e->state == 0) continue;
        if (LinkSession_IsActive(g) && func_02086ef0(party, id)) {
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        changed = 1;
    }
    return changed;
}
