#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov026_021db090_668 = 0x218, Enum_ov026_021db090_10416 = 0x28f0, Enum_ov026_021db090_8504 = 0x236c, Enum_ov026_021db090_2456 = 0x868, Enum_ov026_021db090_6491 = 0x1789, Enum_ov026_021db090_2468 = 0x874, Enum_ov026_021db090_6577 = 0x17e1, Enum_ov026_021db090_6492 = 0x178a, Enum_ov026_021db090_6590 = 0x17ee, Enum_ov026_021db090_6579 = 0x17e3 };
#else
enum { Enum_ov026_021db090_668 = 0x29c, Enum_ov026_021db090_10416 = 0x28b0, Enum_ov026_021db090_8504 = 0x2138, Enum_ov026_021db090_2456 = 0x998, Enum_ov026_021db090_6491 = 0x195b, Enum_ov026_021db090_2468 = 0x9a4, Enum_ov026_021db090_6577 = 0x19b1, Enum_ov026_021db090_6492 = 0x195c, Enum_ov026_021db090_6590 = 0x19be, Enum_ov026_021db090_6579 = 0x19b3 };
#endif

#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Resource/GameResources.h"

struct Struct_ov000_02161e30;
struct GameResources;
struct SePlayer;

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
};

struct Container_021dae60 {
    char pad0[0xb8];
};

struct Struct_ov026_021db090_4 {
    char pad0[0x10];
    unsigned char unknown_10_[8];
    signed char selection;
    char unknown_19_[3];
    signed char kind;
};

struct Struct_ov000_02160da0 {
    char pad0[Enum_ov026_021db090_668];
    Struct_ov000_02161e30* battle;
    PartyState* party;
    char unknown_2a4_[0xc08];
    int state;
    char unknown_eb0_[Enum_ov026_021db090_10416];
    Container_021dae60 list;
    char unknown_3818_[Enum_ov026_021db090_8504];
    unsigned char mode;
};

struct Struct_ov026_021db090 {
    char pad0;
    unsigned char kind;
    char pad2[8];
};

struct Struct_ov000_02182c74 {
    short ids[4];
};

struct Struct_ov026_021db090_2 {
    char pad0[0x14];
    unsigned int flags;
};

struct CombatantView {
    char pad0[0x138];
    Struct_ov026_021db090_2* status;
};

struct PartyList {
    char pad0[0xf78];
    unsigned char members[4];
    unsigned char count;
};

struct Struct_ov026_021db090_3 {
    int data[3];
};

struct MessageWindow {
    Struct_ov026_021db090_3* source;
    char pad4[Enum_ov026_021db090_2456 - 4];
    int active;
    char unknown_99c_[4];
    int busy;
    char unknown_9a4_[Enum_ov026_021db090_6491 - Enum_ov026_021db090_2468];
    unsigned char flags;
    char unknown_195c_[Enum_ov026_021db090_6577 - Enum_ov026_021db090_6492];
    unsigned char unknown_19b1_;
    unsigned char unknown_19b2_;
    char unknown_19b3_[Enum_ov026_021db090_6590 - Enum_ov026_021db090_6579];
    unsigned char unknown_19be_;
};

struct TextBuffers {
    char pad0[0x5c];
    char* text;
};

extern "C" void __clear(void* p, int size);
extern "C" MessageWindow* MessageSystem_GetInstance();
extern "C" int func_02010088(struct S_10088*);
extern "C" void func_020e4c74(void*, GameObject*);
extern "C" void func_02053ec8(void*, int);
extern "C" void func_ov017_021c9ad4(unsigned short);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void MessageSystem_Reset(char*);
extern "C" void func_ov000_02160d80(void*, int);
extern "C" Struct_ov026_021db090_4* func_ov026_021dae60(Container_021dae60*, int);

extern "C" {
int func_ov000_0215e9fc(Struct_ov000_02161e30*, short*, int, int);
void func_ov000_02162c14(Struct_ov000_02160da0*, int, Struct_ov026_021db090*);
void func_020dd0b0(int, char*);
void Zone3D_GetInstance();
void func_ov017_021a23b0(GameResources*, unsigned short);
#if defined(jpn)
void func_0204500c(MessageWindow*, char*, int);
#else
void func_0204500c(MessageWindow*, char*, int, int);
#endif
void MessageSystem_Stop(MessageWindow*);
void func_ov000_02160da0(Struct_ov000_02160da0*);
}

#if defined(jpn)
extern char data_ov026_021df3fa[];
extern char data_ov026_021df3ff[];
extern char data_ov026_021df423[];
extern char data_ov026_021df465[];
#endif

extern char data_ov026_021dedee[];
extern Struct_ov000_02182c74 data_ov026_021de6bc;
extern SePlayer g_sePlayer;

// USA: func_ov026_021db090
extern "C" ARM void func_ov026_021db090(Struct_ov000_02160da0* self) {
    GameState* gs = GameState::GetInstance();
    MessageWindow* win = MessageSystem_GetInstance();

    if (self->state == 0) {
#if defined(jpn)
        char message[0x80];
        char name[0x40];
#else
        char message[0x100];
        Struct_ov026_021db090_3 var4;
        unsigned short name[0x20];
#endif
        Struct_ov026_021db090 info;
        short ids[4];
        Struct_ov000_02182c74 var8;
        int n;
#if defined(jpn)
        int count;
        int var10;
#else
        int count;
#endif
        int i;
        char* text;

#if defined(jpn)
        gs->GetProtagonist();
#else
        sprintf(message, data_ov026_021dedee);
#endif
        __clear(name, sizeof(name));
        n = func_ov000_0215e9fc(self->battle, ids, 4, 0);
        var8 = data_ov026_021de6bc;
#if defined(jpn)
        count = 0;
        var10 = 0;
#else
        count = 0;
#endif
        for (i = 0; i < n; i++) {
            GameObject* c = gs->GetCombatantByIndex(ids[i]);
            if (c == NULL || func_02010088((S_10088*)c)) {
                continue;
            }
            func_ov000_02162c14(self, ids[i], &info);
            if (info.kind != 6) {
                continue;
            }
            if (((CombatantView*)c)->status->flags & 0x80019) {
                continue;
            }
            var8.ids[count] = ids[i];
#if defined(jpn)
            count++;
            var10++;
#else
            count++;
#endif
        }
#if defined(jpn)
        GameObject* first = gs->GetCombatantByIndex(var8.ids[0]);
        if (first != NULL) {
            strcpy(name, (char*)first->baseStats_);
        }
        if (var10 > 1) {
            strcat(name, data_ov026_021df3fa);
        }
#else
        func_020e4c74(&var4, gs->GetPartyMemberByIndex(var8.ids[0]));
#endif

        if (self->mode == 2) {
#if defined(jpn)
            sprintf(message, data_ov026_021df3ff, name);
#else
            text = ((TextBuffers*)MessageSystem_GetInstance())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(1, text);
            strcat(message, text);
#endif

            int j;
            PartyList* party;
            GameState* state;
            state = GameState::GetInstance();
            party = (PartyList*)GameState_GetParty(state);
            for (j = 0; j < party->count; j++) {
                GameObject* member = func_0200ff1c(state, party->members[j]);
                if (member != NULL) {
                    func_02053ec8(member, 2);
                }
            }
            GameResources* res = GetGameResources();
            Zone3D_GetInstance();
            unsigned short netId = self->party->netId;
            func_ov017_021c9ad4(netId);
            func_ov017_021a23b0(res, netId);
        } else if (self->mode == 4) {
#if defined(jpn)
            sprintf(message, data_ov026_021df423, name);
#else
            text = ((TextBuffers*)MessageSystem_GetInstance())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(2, text);
            strcat(message, text);
#endif
        } else {
#if defined(jpn)
            sprintf(message, data_ov026_021df465, name);
#else
            text = ((TextBuffers*)MessageSystem_GetInstance())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(3, text);
            strcat(message, text);
#endif
        }

#if defined(jpn)
        func_0204500c(win, message, 0);
#else
        win->source = &var4;
        func_0204500c(win, message, 0, 0xe3);
#endif
        win->unknown_19b1_ = 0;
        win->unknown_19b2_ = 0;
        win->unknown_19be_ = 1;
        win->flags |= 2;
        win->active = 1;
        SePlayer_Play(&g_sePlayer, 9, 0);
        self->state++;
    } else if (win->busy == 0) {
        self->state++;
        if (self->state >= 0x1e) {
            MessageSystem_Reset((char*)win);
            MessageSystem_Stop(win);
            if (self->mode == 2) {
                func_ov000_02160d80(self, 4);
            } else {
                for (int i = 0; i < 4; i++) {
                    Struct_ov026_021db090_4* slot = func_ov026_021dae60(&self->list, i);
                    if (slot != NULL && slot->kind == 6) {
                        slot->unknown_10_[slot->selection] = 0x66;
                    }
                }
                func_ov000_02160da0(self);
            }
        }
    }
}
