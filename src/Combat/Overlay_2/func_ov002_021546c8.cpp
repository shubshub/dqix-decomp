#include "GameState/GameState.h"
#include <globaldefs.h>

extern "C" void *LinkSession_GetInstance(void);
extern "C" void func_ov002_02153e90(void *entry);
extern "C" int func_ov002_02154a6c(void *self, int idA, int arg2);
extern "C" int func_ov002_02154b94(void *self, int id);
extern "C" GameObject *func_0200ff1c(GameState *gameState, int combatantId);
extern "C" short func_02084a64(void *a, int b);
extern "C" void PartyMember_RecalculateStats(void *a, int arg1);
extern "C" int LinkSession_IsActive(int *p);
extern "C" void func_ov017_021cf078(int id, unsigned char b, int c);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

struct Struct_ov002_021546c8 {
    unsigned char kind;
    char pad1;
    short val;
    char pad4[2];
};

struct Struct_ov002_021546c8_2 {
    short s0;
    signed char b2;
    unsigned char count;
    signed char ids[4];
    struct Struct_ov002_021546c8 entries[4];
    struct Struct_ov002_021546c8 unknown_20_[4];
};

// USA: func_ov002_021546c8
extern "C" ARM int func_ov002_021546c8(void *self, struct Struct_ov002_021546c8_2 *req, void *other, int arg3) {
#if defined(jpn)
    enum { regionalOffset0 = 0x144, regionalOffset1 = 0x8b8 };
#else
    enum { regionalOffset0 = 0x150, regionalOffset1 = 0x950 };
#endif
    if (req == NULL) return 0;
    if (other == NULL) return 0;

    GameState *gs              = GameState::GetInstance();
    void *w                    = LinkSession_GetInstance();
    int ret                    = 0;
    struct Struct_ov002_021546c8 *ents = req->entries;
    if (arg3) ents = req->unknown_20_;

    int i;
    for (i = 0; i < 4; i++) {
        func_ov002_02153e90(&ents[i]);
    }

    for (i = 0; i < req->count; i++) {
        struct Struct_ov002_021546c8 *e = &ents[i];
        int id                  = req->ids[i];
        if (!func_ov002_02154a6c(self, id, req->b2)) {
            e->kind = 1;
            continue;
        }
        if (func_ov002_02154b94(self, id)) {
            e->kind = 2;
            continue;
        }
        GameObject *m = func_0200ff1c(gs, id);
        if (m == NULL) continue;
        e->val = func_02084a64(*(void **) ((char *) m + regionalOffset0), req->s0);
        if (e->val <= 0) continue;
        e->kind = 3;
        PartyMember_RecalculateStats(*(void **) ((char *) m + regionalOffset0), 0);
        if (LinkSession_IsActive((int *) w)) {
            func_ov017_021cf078(id, *(int *) (*(char **) ((char *) m + regionalOffset0) + regionalOffset1) & 0xff, 1);
            func_ov017_021c9e00(id, 0, 0, 1);
        }
        ret = 1;
    }
    return ret;
}
