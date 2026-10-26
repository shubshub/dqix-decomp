#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov002_02154c30_5 {
    unsigned int id;
    unsigned short v4;
    unsigned short v6;
};
struct Struct_ov002_02154c30 {
    unsigned char pad[0x30];
    unsigned short v30;
    unsigned short unknown_32_;
};
struct Struct_ov002_02154c30_2 {
#if defined(jpn)
    unsigned char pad[0x8b8];
#else
    unsigned char pad[0x950];
#endif
    int v950;
};
struct Struct_ov002_02154c30_3 {
    unsigned char pad[0x130];
    Struct_ov002_02154c30_5 *a;
    Struct_ov002_02154c30 *b;
#if defined(jpn)
    unsigned char unknown_138_[0x144 - 0x138];
#else
    unsigned char unknown1_138_[0x150 - 0x138];
#endif
    Struct_ov002_02154c30_2 *c;
};
struct Struct_ov002_02154c30_4 {
    unsigned int id;
    unsigned short v4;
    unsigned short v6;
    unsigned short v8;
    unsigned short unknown_a_;
    unsigned char vc;
    unsigned char vd;
    unsigned char pad[2];
};

extern "C" int GameObject_GetPartyMemberLevel(void *p);

static inline int inline_ov002_02154c30_2(unsigned short *p) { return *p; }
static inline int G32(unsigned int *p) { return *p; }
static inline int G8(int *p) { return *p; }

// USA: func_ov002_02154c30
extern "C" ARM int func_ov002_02154c30(Struct_ov002_02154c30_4 *cache) {
    int changed = 0;
    void *gs    = GameState::GetInstance();
    Struct_ov002_02154c30_3 *m;
    Struct_ov002_02154c30_4 *e;
    int i;
    for (i = 0; i < 4; i++) {
        m = (Struct_ov002_02154c30_3 *)((GameState*)gs)->GetPartyMemberByIndex(i);
        if (m == 0) continue;
        e = &cache[i];
        if (!(e->v4 != inline_ov002_02154c30_2(&m->a->v4) || e->v6 != inline_ov002_02154c30_2(&m->b->v30) || e->v8 != inline_ov002_02154c30_2(&m->a->v6) || e->unknown_a_ != inline_ov002_02154c30_2(&m->b->unknown_32_) ||
              e->vd != G8(&m->c->v950) || e->vc != GameObject_GetPartyMemberLevel(m) || e->id != G32(&m->a->id)))
            continue;
        e->v4   = m->a->v4;
        e->v6   = m->b->v30;
        e->v8   = m->a->v6;
        e->unknown_a_   = m->b->unknown_32_;
        e->vd   = m->c->v950;
        e->vc   = GameObject_GetPartyMemberLevel(m);
        e->id   = m->a->id;
        changed = 1;
    }
    return changed;
}
