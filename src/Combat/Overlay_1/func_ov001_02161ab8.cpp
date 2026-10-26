#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_0205faf4_11;

struct Struct_ov001_02161ab8 {
    unsigned int flags;
    unsigned short hp;
};

struct Struct_ov001_02161ab8_2 {
    unsigned char pad[0x56b];
    unsigned char unk_56b : 4;
    unsigned char rank : 4;
};

struct Struct_ov001_02161ab8_3 {
    unsigned short flags;
    short unknown_2_;
    short level;
    char unknown_6_[0x130 - 0x6];
    Struct_ov001_02161ab8* status;
    #if defined(jpn)
    char unknown_134_[0x144 - 0x134];
#else
    char unknown1_134_[0x150 - 0x134];
#endif
    Struct_ov001_02161ab8_2* party;
};

struct Struct_ov001_02161ab8_4 {
    unsigned char unknown_0_0_ : 4;
    unsigned char kind : 4;
    unsigned char id;
    short combatantId;
    char unknown_4_[0x34 - 0x4];
    Struct_ov001_02161ab8_4* next;
};

struct Struct_ov001_02161ab8_5 {
    #if defined(jpn)
    char pad[0xcc];
#else
    char pad[0xd0];
#endif
    Struct_ov001_02161ab8_4* head;
};

extern "C" int func_ov017_021d60f4(void* arg);
extern "C" void func_ov017_021d6134(void* arg, int value);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_02061bd8(Struct_0205faf4_11* obj);

static inline int inline_ov000_0215a908_2(Struct_ov001_02161ab8* status) { return status->hp; }

// USA: func_ov001_02161ab8
extern "C" ARM int func_ov001_02161ab8(char* self, int count) {
    GameState* gs = GameState::GetInstance();
    Struct_ov001_02161ab8_5* work = (Struct_ov001_02161ab8_5*)GetGameResources()->unknown_ptr_array_371c[6];
    int id = func_ov017_021d60f4(self);
    Struct_ov001_02161ab8_4* e;
    for (e = work->head; e != NULL; e = e->next) {
        if (e->id == id) break;
    }
    if (e == NULL) {
        func_ov017_021d6134(self + 8, -1);
        func_ov017_021d6134(self + 0x10, 2);
        return 1;
    }
    int state;
    int kind;
    int combatantId;
    combatantId = -1;
    kind = e->kind;
    if (kind == 0) {
        func_ov017_021d6134(self + 8, kind);
        func_ov017_021d6134(self + 0x10, 0);
        return 1;
    }
    if (e->unknown_0_0_ == 10) {
        Struct_ov001_02161ab8_3* c = (Struct_ov001_02161ab8_3*)func_0200ff58(gs, 0xce);
        if (c != NULL) {
            state = 0;
        } else {
            int i;
            for (i = 0; i < 4; i++) {
                c = (Struct_ov001_02161ab8_3*)func_0200ff58(gs, i);
                if (c != NULL && func_02061bd8((Struct_0205faf4_11*)c)) break;
            }
            if (i == 4) {
                func_ov017_021d6134(self + 8, kind);
                func_ov017_021d6134(self + 0x10, 2);
                return 1;
            }
            state = inline_ov000_0215a908_2(c->status) <= 0 ? 1 : 0;
        }
    } else {
        Struct_ov001_02161ab8_3* c = (Struct_ov001_02161ab8_3*)func_0200ff1c(gs, e->combatantId);
        if (c == NULL) return 0;
        combatantId = e->combatantId;
        Struct_ov001_02161ab8_2* party = c->party;
        int var11;
        if (party != NULL) {
            var11 = party->rank != 0;
        } else {
            var11 = 0;
        }
        if (var11) {
            kind = (party != NULL ? party->rank : 0) + 7;
        } else if (!(c->flags & 0x1000) && c->level > 0 && c->level < 4) {
            kind = 14;
        }
        if (c != NULL) {
            Struct_ov001_02161ab8* status = c->status;
            if (inline_ov000_0215a908_2(status) <= 0 && (status->flags & 1)) {
                state = 1;
            } else {
                state = 0;
            }
        } else {
            state = 2;
        }
    }
    func_ov017_021d6134(self + 8, kind);
    func_ov017_021d6134(self + 0x10, state);
    if (count > 3) {
        func_ov017_021d6134(self + 0x18, combatantId);
    }
    return 1;
}
