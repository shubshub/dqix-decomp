#include "GameState/GameState.h"
#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Container020e0310;
struct Obj02046574;

struct MsgGlobals021552b8 {
    void *unknown_0_;
    char pad4[0xc];
    void *unknown_10_;
    char unknown_14_[0x28 - 0x14];
    void *extra;
    char pad2c[LOW_REGION(0x868,0x998) - 0x2c];
    int active;
    int unknown_99c_;
    int phase;
};

struct Struct_ov003_021552b8_3 {
    char pad0[LOW_REGION(0x8b8,0x950)];
    int vocation;
};

struct Struct_ov003_021552b8_4 {
#if defined(jpn)
    char pad0[0x134];
    void* name;
    char unknown_138_[0x144 - 0x138];
#else
    char pad0[0x150];
#endif
    Struct_ov003_021552b8_3 *data;
};

struct Struct_ov003_021552b8_5 {
    char pad0[4];
    void *unknown_4_;
    char pad8[0xe4 - 8];
    char messages[LOW_REGION(0x1e8,0x1ec) - 0xe4];
    short curId;
    short unknown_1ee_;
    char unknown_1f0_[0x1f7 - 0x1f0];
    signed char slot;
    unsigned char mode;
    unsigned char sub;
    unsigned char step;
    char unknown_1fb_;
    unsigned int flags;
};

struct Struct_ov003_021552b8 {
    char data[0xc];
};

extern "C" MsgGlobals021552b8 *MessageSystem_GetInstance();
extern "C" void func_02046380(MsgGlobals021552b8 *);
extern "C" int func_ov003_02156034(void *);
extern "C" void * KeyTable_Get(Container020e0310*, int);
extern "C" void NameText_InitFromPartyMember(void *, int);
extern "C" void func_020e4b34(void *, void *, int, int, int, int, int, int, int, int, int, int);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#if defined(jpn)
extern "C" void func_0204500c(MsgGlobals021552b8*, void*, int);
#endif
#if !defined(jpn)
extern "C" void func_0204500c(MsgGlobals021552b8 *, void *, int, int);
#endif
extern "C" int func_ov003_021538e0(void *);
extern "C" void MessageSystem_Reset(char *);
extern "C" void MessageSystem_Stop(MsgGlobals021552b8 *);

// USA: func_ov003_021552b8
extern "C" ARM void func_ov003_021552b8(Struct_ov003_021552b8_5 *self) {
    MsgGlobals021552b8 *g = MessageSystem_GetInstance();
    if (self->step == 0) {
#if !defined(jpn)
        int id = self->curId;
#endif
        if (self->flags & 1) {
#if defined(jpn)
            int id = self->curId;
#endif
            switch (id) {
                case 6: id = 0x1b; break;
                case 7: id = 0x1c; break;
                case 8: id = 0x1d; break;
                case 9: id = 0x1e; break;
                case 10: id = 0x1f; break;
                case 11: id = 0x20; break;
                case 12: id = 0x21; break;
                case 13: id = 0x22; break;
                case 0x30: id = 0x32; break;
                case 0x31: id = 0x33; break;
            }
            self->curId = id;
        }
        func_02046380(g);
        GameState *gs           = GameState::GetInstance();
        Struct_ov003_021552b8_4 *party = (Struct_ov003_021552b8_4 *) gs->GetPartyMemberByIndex(self->slot);
#if defined(jpn)
        void* name = 0;
        int vocation = 0;
        if (party) {
            vocation = party->data->vocation;
            name = party->name;
        }
        MessageSystem_SetStringArgument((Obj02046574*)g, 0, (char*)name);
        short key = func_ov003_02156034(self) + 0x23;
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, (char*)(KeyTable_Get((Container020e0310*)self->messages, key)));
        MessageSystem_SetStringArgument((Obj02046574*)g, 2, (char*)(KeyTable_Get((Container020e0310*)self->messages, (short)(vocation + 0x23))));
        MessageSystem_SetStringArgument((Obj02046574*)g, 3, (char*)(KeyTable_Get((Container020e0310*)self->messages, (short)(vocation + 0x34))));
        func_0204500c(g, KeyTable_Get((Container020e0310*)self->messages, self->curId), 0);
#else
        int vocation            = 0;
        if (party) {
            vocation = party->data->vocation;
        }
        short key = func_ov003_02156034(self) + 0x23;
        void *a   = KeyTable_Get((Container020e0310*)self->messages, key);
        void *b   = KeyTable_Get((Container020e0310*)self->messages, (short) (vocation + 0x23));
        Struct_ov003_021552b8 unit;
        NameText_InitFromPartyMember(&unit, self->slot);
        g->unknown_0_  = &unit;
        g->unknown_10_ = &unit;
        Struct_ov003_021552b8 obj;
        void *pick = a;
        if (id == 0x10 || id == 0x13 || id == 0x16) {
            pick = b;
        }
        func_020e4b34(&obj, pick, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        g->extra = &obj;
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, (char*)a);
        MessageSystem_SetStringArgument((Obj02046574*)g, 2, (char*)b);
        MessageSystem_SetStringArgument((Obj02046574*)g, 3, (char*)(KeyTable_Get((Container020e0310*)self->messages, (short) (vocation + 0x34))));
        func_0204500c(g, KeyTable_Get((Container020e0310*)self->messages, id), 0, 0xe3);
#endif
        g->active  = 1;
        g->unknown_99c_ = 1;
        self->step++;
    } else if (self->step == 1) {
        if (g->active == 0) {
            self->curId  = self->unknown_1ee_;
            self->unknown_1ee_ = -1;
            self->mode   = 7;
            self->step   = 0;
            if (func_ov003_021538e0(self->unknown_4_) == 0) {
                self->mode = 5;
                self->sub  = 0;
            }
        } else if (g->phase == 3) {
            self->curId  = self->unknown_1ee_;
            self->unknown_1ee_ = -1;
            if (self->curId < 0 && (self->flags & 2)) {
                MessageSystem_Reset((char *) g);
                MessageSystem_Stop(g);
                self->flags &= ~2;
            }
            self->step = 0;
        }
    }
}
