#include <globaldefs.h>
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;

extern "C" int *LinkSession_GetInstance(void);
extern "C" int func_02086ef0(ArrayContainsByteStruct *arr, int value);
extern "C" int LinkSession_IsActive(int *p);
extern "C" int func_ov002_02154a34(void *self, int id);
extern "C" int func_ov002_02154b94(void *self, int id);
extern "C" void *func_02079ee0(void *table, int key);

struct Struct_ov002_02153ccc {
    unsigned char state;
    unsigned char pad1;
    unsigned short value;
    unsigned char unknown_4_;
    unsigned char pad5;
};

struct Struct_ov002_02153ccc_2 {
    short type;
    signed char kind;
    unsigned char count;
    signed char ids[4];
    Struct_ov002_02153ccc entries[4];
    Struct_ov002_02153ccc unknown_20_[4];
};

struct Struct_ov002_02153ccc_3 {
    unsigned char pad0[8];
    unsigned int lo : 14;
    unsigned int key : 8;
    unsigned int hi : 10;
};

extern "C" void func_ov002_02153e90(Struct_ov002_02153ccc *e);
extern "C" int func_ov002_02154a6c(void *self, int id, int kind);
extern "C" int func_ov002_021538e4(void *self, Struct_ov002_02153ccc_3 *action, void *elem, int kind);
extern "C" unsigned short func_ov002_021548c4(void *self, int id, int value, Struct_ov002_02153ccc *e);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_ov002_02153ccc
extern "C" ARM int func_ov002_02153ccc(void **self, Struct_ov002_02153ccc_2 *info, Struct_ov002_02153ccc_3 *action, int arg3) {
    if (info == 0) return 0;
    if (action == 0) return 0;
    ArrayContainsByteStruct *party = (ArrayContainsByteStruct *)GameState_GetParty(GameState::GetInstance());
    int *g                         = LinkSession_GetInstance();
    Struct_ov002_02153ccc *entries         = info->entries;
    int changed                    = 0;
    if (arg3) entries = info->unknown_20_;
    for (int i = 0; i < 4; i++) {
        func_ov002_02153e90(&entries[i]);
    }
    for (int i = 0; i < info->count; i++) {
        Struct_ov002_02153ccc *e = &entries[i];
        int id           = info->ids[i];
        int value;
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
        if (info->type == 0x21) {
            value = 999;
        } else {
            void *elem = func_02079ee0(*self, action->key);
            if (elem == 0) continue;
            value = func_ov002_021538e4(self, action, elem, info->kind);
        }
        if (e->unknown_4_) {
            e->value = value;
            e->state = 3;
        } else {
            e->value = func_ov002_021548c4(self, id, value, e);
        }
        if (e->state == 0) continue;
        if (LinkSession_IsActive(g) && func_02086ef0(party, id)) {
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        changed = 1;
    }
    return changed;
}
