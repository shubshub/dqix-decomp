#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov002_02154c30_5 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};
struct Struct_ov002_02154c30 {
    unsigned char unknown_0_[0x30];
    unsigned short unknown_30_;
    unsigned short unknown_32_;
};
struct Struct_ov002_02154c30_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x8b8];
#else
    unsigned char unknown1_0_[0x950];
#endif
    int unknown_950_;
};
struct Struct_ov002_02154c30_3 {
    unsigned char unknown_0_[0x130];
    Struct_ov002_02154c30_5 *unknown_130_;
    Struct_ov002_02154c30 *unknown_134_;
#if defined(jpn)
    unsigned char unknown_138_[0x144 - 0x138];
#else
    unsigned char unknown1_138_[0x150 - 0x138];
#endif
    Struct_ov002_02154c30_2 *unknown_150_;
};
struct Struct_ov002_02154c30_4 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_[2];
};

int GameObject_GetPartyMemberLevel(void *p);

static inline int inline_ov002_02154c30_2(unsigned short *arg0) { return *arg0; }
static inline int inline_ov002_02154c30_3(unsigned int *arg0) { return *arg0; }
static inline int inline_ov002_02154c30(int *arg0) { return *arg0; }

// USA: func_ov002_02154c30
extern "C" ARM int func_ov002_02154c30(Cache02154c30 *cache) {
    int changed = 0;
    void *gs    = GameState::GetInstance();
    Member02154c30 *m;
    Cache02154c30 *e;
    int i;
    for (i = 0; i < 4; i++) {
        m = (Member02154c30 *)((GameState*)gs)->GetPartyMemberByIndex(i);
        if (m == 0) continue;
        e = &cache[i];
        if (!(e->v4 != G16(&m->a->v4) || e->v6 != G16(&m->b->v30) || e->v8 != G16(&m->a->v6) || e->va != G16(&m->b->v32) ||
              e->vd != G8(&m->c->v950) || e->vc != GameObject_GetPartyMemberLevel(m) || e->id != G32(&m->a->id)))
            continue;
        e->v4   = m->a->v4;
        e->v6   = m->b->v30;
        e->v8   = m->a->v6;
        e->va   = m->b->v32;
        e->vd   = m->c->v950;
        e->vc   = GameObject_GetPartyMemberLevel(m);
        e->id   = m->a->id;
        changed = 1;
    }
    return var0;
}
