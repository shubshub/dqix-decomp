#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/ActionDataTables.h"
#include <std_library_functions.h>

#if defined(jpn)
enum { Enum_ov002_0215a0a4_3000 = 0xa80, Enum_ov002_0215a0a4_40 = 0x10, Enum_ov002_0215a0a4_7200 = 0x1ae8, Enum_ov002_0215a0a4_9352 = 0x22b8, Enum_ov002_0215a0a4_2400 = 0x800, Enum_ov002_0215a0a4_2144 = 0x700, Enum_ov002_0215a0a4_38 = 0x29, Enum_ov002_0215a0a4_17 = 0x12 };
#define FORMAT(m, k, t, d) func_020474a8(m, k, t, d)
#else
enum { Enum_ov002_0215a0a4_3000 = 0xbb8, Enum_ov002_0215a0a4_40 = 0x28, Enum_ov002_0215a0a4_7200 = 0x1c20, Enum_ov002_0215a0a4_9352 = 0x2488, Enum_ov002_0215a0a4_2400 = 0x960, Enum_ov002_0215a0a4_2144 = 0x860, Enum_ov002_0215a0a4_38 = 0x26, Enum_ov002_0215a0a4_17 = 0x11 };
#define FORMAT(m, k, t, d) MessageSystem_FormatText(m, k, t, d, 0xe3, 0, 1)
#endif

struct Struct_ov002_02157d40_8;
struct StoreStruct;
struct Obj02046574 {
    void* actor;
    unsigned char unknown_4[12];
    void* target;
};
struct Struct_ov002_0215a0a4_5 {
    char* name;
    int unknown_4;
    unsigned int counter : 8;
    unsigned int unused : 24;
};
struct Struct_ov002_0215a0a4_6 {
    unsigned char unknown_0[Enum_ov002_0215a0a4_3000];
    int state;
    int nextState;
    int timer;
    unsigned char unknown_bc4_[12];
    char* text;
    char* unknown_bd4_;
};
struct Struct_ov002_0215a0a4 {
    unsigned char unknown_0[8];
#if !defined(jpn)
    unsigned char actorName[12];
    unsigned char targetName[12];
#endif
    Container020e0310 texts;
    unsigned char unknown_28_[0x1000 - Enum_ov002_0215a0a4_40];
    Struct_ov002_0215a0a4_6 textState;
    unsigned char unknown_1bd8_[Enum_ov002_0215a0a4_7200 - 0x1000 - sizeof(Struct_ov002_0215a0a4_6)];
    signed char actorId;
    signed char partyIndex;
    unsigned char unknown_1c22_[4];
    short command;
    short messageKey;
    short unknown_1c2a_;
    unsigned char unknown_1c2c_[5];
    unsigned char pending;
    unsigned char unknown_1c32_[Enum_ov002_0215a0a4_9352 - Enum_ov002_0215a0a4_7200 - 0x12];
    short unknown_2488_;
    unsigned char active;
};
struct Struct_ov002_0215a0a4_2 {
    unsigned char kind;
    unsigned char unknown_1_[5];
};
struct Struct_ov002_0215a0a4_3 {
    unsigned char unknown_0[2];
    signed char actor;
    unsigned char count;
    signed char targets[4];
    Struct_ov002_0215a0a4_2 unknown_8_[4];
};
struct Struct_ov002_0215a0a4_4 {
    unsigned char unknown_0[0x130];
    unsigned int* flags;
};

extern "C" void* func_020e2ff8();
extern "C" void func_020e3428(void*, int);
extern "C" Obj02046574* MessageSystem_GetInstance();
extern "C" Struct_ov002_0215a0a4_5* func_02079e2c(char*, int);
extern "C" void* NameText_Clear(void*);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" int func_02048350(Struct_ov002_02157d40_8*, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" int KeyTable_Get(Container020e0310*, int);
extern "C" int Text_Append(char*, const char*);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" int* LinkSession_GetInstance();
extern "C" void func_02046380(void*);
extern "C" void func_ov017_021c9e00(int, int, int, int);
#if defined(jpn)
extern "C" void func_020474a8(void*, int, int, void*);
#else
extern "C" void MessageSystem_FormatText(void*, int, int, void*, int, int, int);
#endif

static inline char* CombatantName0215a0a4(GameObject* target) { SDK_NULL_ASSERT(target); return target->baseStats_->name; }

// USA: func_ov002_0215a0a4
extern "C" ARM void func_ov002_0215a0a4(Struct_ov002_0215a0a4* self, Struct_ov002_0215a0a4_3* event, int any) {
    GameObject* target;
    int var1;
    int* state;
    GameObject* actor;
    Struct_ov002_0215a0a4_2* var4;
    char* buffer;
    signed char* targetIds;
    GameState* gs;
    Obj02046574* message;
    Struct_ov002_0215a0a4_5* entry;
    int index;
    func_020e3428(func_020e2ff8(), 1);
    gs = GameState::GetInstance();
    message = MessageSystem_GetInstance();
    state = LinkSession_GetInstance();
    entry = func_02079e2c((char*)func_020797dc(), self->command);
    if (!entry) return;
    memset(self->textState.text, 0, Enum_ov002_0215a0a4_2400);
    memset(self->textState.unknown_bd4_, 0, Enum_ov002_0215a0a4_2400);
    func_02046380(message);
    buffer = self->textState.text;
#if !defined(jpn)
    NameText_Clear(self->actorName);
    NameText_Clear(self->targetName);
#endif
    actor = func_0200ff1c(gs, event->actor);
    if (actor) {
        MessageSystem_SetStringArgument(message, 0, actor->baseStats_->name);
#if !defined(jpn)
        NameText_InitFromPartyMember(self->actorName, event->actor);
        message->actor = self->actorName;
#endif
    }
    MessageSystem_SetStringArgument(message, 1, entry->name);
    if (self->command == 0x1e || self->command == 0x1f || self->command == 0x20 ||
        self->command == 0x21 || self->command == 0x23 || self->command == 0x26 || self->command == 0x27) {
        self->active = 1;
        self->messageKey = 0x232d;
        self->unknown_1c2a_ = -1;
        GameObject* party = gs->GetPartyMemberByIndex(self->partyIndex);
        int var12 = 0;
        if (any && party) {
            if (self->command == 0x1e || self->command == 0x1f || self->command == 0x20 || self->command == 0x21) {
                self->unknown_2488_ = 0x232c;
                var12 = 1;
            } else if (self->command == 0x23) {
                self->unknown_2488_ = 0x794b;
                var12 = 1;
            } else if (self->command == 0x27 || self->command == 0x26) {
                self->unknown_2488_ = 0x2336;
                var12 = 1;
            }
        } else if (!party) {
            self->messageKey = 0x232d;
            self->unknown_2488_ = 0x232b;
        } else if (*((Struct_ov002_0215a0a4_4*)party)->flags & 1) {
            if (self->command == 0x26) {
                self->unknown_2488_ = 0x2337;
                var12 = 1;
            } else {
                self->unknown_2488_ = 0x232b;
            }
        } else if (event->unknown_8_[0].kind == 1) {
            self->messageKey = 0x232d;
            self->unknown_2488_ = 0x232b;
        } else {
            self->messageKey = 0x2333;
            self->unknown_2488_ = 0x2334;
        }
        self->textState.state = Enum_ov002_0215a0a4_38;
        self->textState.nextState = Enum_ov002_0215a0a4_17;
        self->textState.timer = 0;
        if (var12) {
            func_02048350((Struct_ov002_02157d40_8*)actor, entry->counter);
            if (LinkSession_IsActive(state)) func_ov017_021c9e00(self->actorId, 0, 0, 1);
        }
        return;
    }
    if (self->command != 0x22 && self->command != 0x310) return;
    if (any) {
        FORMAT(message, 0xc, KeyTable_Get(&self->texts, 0x232d), buffer + Enum_ov002_0215a0a4_2144);
        Text_Append(self->textState.text, buffer + Enum_ov002_0215a0a4_2144);
        var4 = event->unknown_8_;
        var1 = 0x232c;
        index = 0;
        targetIds = event->targets;
        while (index < event->count) {
            int key = var4[index].kind == 3 ? var1 : 0x233a;
            if (key >= 0) {
#if defined(jpn)
                target = func_0200ff1c(gs, event->targets[index]);
#else
                target = func_0200ff1c(gs, targetIds[index]);
#endif
                if (target) {
                    func_02046380(message);
                    MessageSystem_SetStringArgument(message, 2, CombatantName0215a0a4(target));
#if !defined(jpn)
                    NameText_InitFromPartyMember(self->targetName, targetIds[index]);
                    message->target = self->targetName;
#endif
                    func_020465c0((StoreStruct*)message, 9, target->obj3D_.actorIndex_);
                    FORMAT(message, 0xc, KeyTable_Get(&self->texts, key), buffer + Enum_ov002_0215a0a4_2144);
                    Text_Append(self->textState.text, (const char*)KeyTable_Get(&self->texts, 8));
                    Text_Append(self->textState.text, buffer + Enum_ov002_0215a0a4_2144);
                }
            }
            index++;
        }
        func_02048350((Struct_ov002_02157d40_8*)actor, entry->counter);
        if (LinkSession_IsActive(state)) func_ov017_021c9e00(self->actorId, 0, 0, 1);
    } else {
        target = gs->GetLeader();
        if (target) {
            MessageSystem_SetStringArgument(message, 2, CombatantName0215a0a4(target));
#if !defined(jpn)
            NameText_InitFromPartyMember(self->targetName, target->obj3D_.actorIndex_);
            message->target = self->targetName;
#endif
        }
        Text_Append(buffer + Enum_ov002_0215a0a4_2144, (const char*)KeyTable_Get(&self->texts, 0x2333));
        Text_Append(buffer + Enum_ov002_0215a0a4_2144, (const char*)KeyTable_Get(&self->texts, 8));
        if (func_02011538(gs) == 1)
            Text_Append(buffer + Enum_ov002_0215a0a4_2144, (const char*)KeyTable_Get(&self->texts, 0x2334));
        else
            Text_Append(buffer + Enum_ov002_0215a0a4_2144, (const char*)KeyTable_Get(&self->texts, 0x2335));
        FORMAT(message, 0xc, (int)(buffer + Enum_ov002_0215a0a4_2144), self->textState.text);
    }
    self->pending = 1;
    memcpy(self->textState.unknown_bd4_, self->textState.text, Enum_ov002_0215a0a4_2400);
    self->unknown_2488_ = -1;
    self->active = 0;
}
