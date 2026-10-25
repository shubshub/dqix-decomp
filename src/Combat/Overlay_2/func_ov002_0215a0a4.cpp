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
#define FORMAT(m, k, t, d) func_02046608(m, k, t, d, 0xe3, 0, 1)
#endif

struct Struct_ov002_02157d40_8;
struct Struct_ov002_02157d40_2;
struct Struct_ov002_02157d40_6 {
    void* unknown_0_;
    unsigned char unknown_4_[12];
    void* unknown_10_;
};
struct Struct_ov002_0215a0a4_5 {
    char* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
};
struct Struct_ov002_0215a0a4_6 {
    unsigned char unknown_0_[Enum_ov002_0215a0a4_3000];
    int unknown_bb8_;
    int unknown_bbc_;
    int unknown_bc0_;
    unsigned char unknown_bc4_[12];
    char* unknown_bd0_;
    char* unknown_bd4_;
};
struct Struct_ov002_0215a0a4 {
    unsigned char unknown_0_[8];
#if !defined(jpn)
    unsigned char unknown_8_[12];
    unsigned char unknown_14_[12];
#endif
    Struct_0201099c_3 unknown_20_;
    unsigned char unknown_28_[0x1000 - Enum_ov002_0215a0a4_40];
    Struct_ov002_0215a0a4_6 unknown_1000_;
    unsigned char unknown_1bd8_[Enum_ov002_0215a0a4_7200 - 0x1000 - sizeof(Struct_ov002_0215a0a4_6)];
    signed char unknown_1c20_;
    signed char unknown_1c21_;
    unsigned char unknown_1c22_[4];
    short unknown_1c26_;
    short unknown_1c28_;
    short unknown_1c2a_;
    unsigned char unknown_1c2c_[5];
    unsigned char unknown_1c31_;
    unsigned char unknown_1c32_[Enum_ov002_0215a0a4_9352 - Enum_ov002_0215a0a4_7200 - 0x12];
    short unknown_2488_;
    unsigned char unknown_248a_;
};
struct Struct_ov002_0215a0a4_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[5];
};
struct Struct_ov002_0215a0a4_3 {
    unsigned char unknown_0_[2];
    signed char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_[4];
    Struct_ov002_0215a0a4_2 unknown_8_[4];
};
struct Struct_ov002_0215a0a4_4 {
    unsigned char unknown_0_[0x130];
    unsigned int* unknown_130_;
};

void* GetData02153637_020e2ff8();
void Dispatch020e3428(void*, int);
Obj02046574* MessageSystem_GetInstance();
CommandEntry0215a0a4* SearchBothTables02079e2c(char*, int);
void* Clear12Bytes020e46c4(void*);
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
void NameText_InitFromPartyMember(void*, int);
int ConsumeCounter02048350(Obj02048350*, int);
int CheckField0NonZero_0202b7d8(int*);
int KeyTable_Get(Container020e0310*, int);
int Text_Append(char*, const char*);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
extern "C" int* func_0202ae18();
extern "C" void func_02046380(void*);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void MessageSystem_FormatText(void*, int, int, void*, int, int, int);

static inline char* CombatantName0215a0a4(GameObject* target) { SDK_NULL_ASSERT(target); return target->baseStats_->name; }

// USA: func_ov002_0215a0a4
extern "C" ARM void func_ov002_0215a0a4(BattleMessage0215a0a4* self, BattleEvent0215a0a4* event, int any) {
    GameObject* target;
    int rejectedKey;
    int* state;
    GameObject* actor;
    ActionResult0215a0a4* results;
    char* buffer;
    signed char* targetIds;
    GameState* gs;
    Obj02046574* message;
    CommandEntry0215a0a4* entry;
    int index;
    Dispatch020e3428(GetData02153637_020e2ff8(), 1);
    gs = GameState::GetInstance();
    message = MessageSystem_GetInstance();
    state = func_0202ae18();
    entry = SearchBothTables02079e2c((char*)GetData02108e10_020797dc(), self->command);
    if (!entry) return;
    memset(self->textState.text, 0, 0x960);
    memset(self->textState.textCopy, 0, 0x960);
    func_02046380(message);
    buffer = self->textState.text;
    Clear12Bytes020e46c4(self->actorName);
    Clear12Bytes020e46c4(self->targetName);
    actor = GetCombatantWithFlag0x100_0200ff1c(gs, event->actor);
    if (actor) {
        MessageSystem_SetStringArgument(message, 0, actor->baseStats_->name);
        NameText_InitFromPartyMember(self->actorName, event->actor);
        message->actor = self->actorName;
    }
    MessageSystem_SetStringArgument(message, 1, entry->name);
    if (self->command == 0x1e || self->command == 0x1f || self->command == 0x20 ||
        self->command == 0x21 || self->command == 0x23 || self->command == 0x26 || self->command == 0x27) {
        self->active = 1;
        self->messageKey = 0x232d;
        self->alternateKey = -1;
        GameObject* party = gs->GetPartyMemberByIndex(self->partyIndex);
        int consumed = 0;
        if (any && party) {
            if (self->command == 0x1e || self->command == 0x1f || self->command == 0x20 || self->command == 0x21) {
                self->secondaryKey = 0x232c;
                consumed = 1;
            } else if (self->command == 0x23) {
                self->secondaryKey = 0x794b;
                consumed = 1;
            } else if (self->command == 0x27 || self->command == 0x26) {
                self->secondaryKey = 0x2336;
                consumed = 1;
            }
        } else if (!var11) {
            arg0->unknown_1c28_ = 0x232d;
            arg0->unknown_2488_ = 0x232b;
        } else if (*((Struct_ov002_0215a0a4_4*)var11)->unknown_130_ & 1) {
            if (arg0->unknown_1c26_ == 0x26) {
                arg0->unknown_2488_ = 0x2337;
                var12 = 1;
            } else {
                arg0->unknown_2488_ = 0x232b;
            }
        } else if (arg1->unknown_8_[0].unknown_0_ == 1) {
            arg0->unknown_1c28_ = 0x232d;
            arg0->unknown_2488_ = 0x232b;
        } else {
            arg0->unknown_1c28_ = 0x2333;
            arg0->unknown_2488_ = 0x2334;
        }
        arg0->unknown_1000_.unknown_bb8_ = Enum_ov002_0215a0a4_38;
        arg0->unknown_1000_.unknown_bbc_ = Enum_ov002_0215a0a4_17;
        arg0->unknown_1000_.unknown_bc0_ = 0;
        if (var12) {
            func_02048350((Struct_ov002_02157d40_8*)var3, var9->unknown_8_0_);
            if (func_0202b7d8(var2)) func_ov017_021c9e00(arg0->unknown_1c20_, 0, 0, 1);
        }
        return;
    }
    if (self->command != 0x22 && self->command != 0x310) return;
    if (any) {
        MessageSystem_FormatText(message, 0xc, KeyTable_Get(&self->texts, 0x232d), buffer + 0x860, 0xe3, 0, 1);
        Text_Append(self->textState.text, buffer + 0x860);
        results = event->results;
        rejectedKey = 0x232c;
        index = 0;
        targetIds = event->targets;
        while (index < event->count) {
            int key = results[index].kind == 3 ? rejectedKey : 0x233a;
            if (key >= 0) {
                target = GetCombatantWithFlag0x100_0200ff1c(gs, targetIds[index]);
                if (target) {
                    func_02046380(message);
                    MessageSystem_SetStringArgument(message, 2, CombatantName0215a0a4(target));
                    NameText_InitFromPartyMember(self->targetName, targetIds[index]);
                    message->target = self->targetName;
                    StoreInArray0x8b0_020465c0((StoreStruct*)message, 9, target->obj3D_.actorIndex_);
                    MessageSystem_FormatText(message, 0xc, KeyTable_Get(&self->texts, key), buffer + 0x860, 0xe3, 0, 1);
                    Text_Append(self->textState.text, (const char*)KeyTable_Get(&self->texts, 8));
                    Text_Append(self->textState.text, buffer + 0x860);
                }
            }
            var10++;
        }
        func_02048350((Struct_ov002_02157d40_8*)var3, var9->unknown_8_0_);
        if (func_0202b7d8(var2)) func_ov017_021c9e00(arg0->unknown_1c20_, 0, 0, 1);
    } else {
        target = gs->GetUnknownGameObject();
        if (target) {
            MessageSystem_SetStringArgument(message, 2, CombatantName0215a0a4(target));
            NameText_InitFromPartyMember(self->targetName, target->obj3D_.actorIndex_);
            message->target = self->targetName;
        }
        Text_Append(buffer + 0x860, (const char*)KeyTable_Get(&self->texts, 0x2333));
        Text_Append(buffer + 0x860, (const char*)KeyTable_Get(&self->texts, 8));
        if (GetByteField0x5721_02011538(gs) == 1)
            Text_Append(buffer + 0x860, (const char*)KeyTable_Get(&self->texts, 0x2334));
        else
            Text_Append(buffer + 0x860, (const char*)KeyTable_Get(&self->texts, 0x2335));
        MessageSystem_FormatText(message, 0xc, (int)(buffer + 0x860), self->textState.text, 0xe3, 0, 1);
    }
    arg0->unknown_1c31_ = 1;
    memcpy(arg0->unknown_1000_.unknown_bd4_, arg0->unknown_1000_.unknown_bd0_, Enum_ov002_0215a0a4_2400);
    arg0->unknown_2488_ = -1;
    arg0->unknown_248a_ = 0;
}
