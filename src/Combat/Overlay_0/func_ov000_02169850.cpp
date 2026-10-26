#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02169850_3 { unsigned short action; unsigned char target; unsigned char group; unsigned char flags; };
struct Struct_02053dc0;
extern "C" Struct_ov000_02169850_3* func_02053dc0(Struct_02053dc0*);
struct Struct_ov000_02169850 {
    char pad0[0x1d];
    unsigned char group;
    char pad1e[0x10];
    signed char target;
    char unknown_2f_[0x1d];
    int owner;
#if defined(jpn)
    char unknown_50_[0x438];
#else
    char unknown1_50_[0x3f8];
#endif
};
struct Struct_ov000_02169850_2 {
#if defined(jpn)
    char pad0[0x21c];
#else
    char pad0[0x2a0];
#endif
    unsigned char* state;
#if defined(jpn)
    char unknown_220_[0x34fc];
#else
    char unknown_2a4_[0x34bc];
#endif
    char unknown_3760_[0x958];
    Struct_ov000_02169850 actions[4];
#if defined(jpn)
    char unknown_5294_[0x8ac];
#else
    char unknown_51d8_[0x778];
#endif
    unsigned char mode;
};
struct Struct_ov000_02169850_4 {
    unsigned char field0;
    unsigned char type;
    char pad2[4];
    short key;
    unsigned short value;
};
struct ActionEntry { char pad0[0x16]; unsigned short value; };
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_ov000_02162c14(Struct_ov000_02169850_2*, int, Struct_ov000_02169850_4*);
extern "C" ActionEntry* func_ov000_02171d90(Struct_ov000_02169850*, int);
extern "C" int func_ov000_021761c8(char*, int);
extern "C" int func_ov000_021761ec(char*, int);
extern "C" void func_02049458(unsigned char*, unsigned char);
static inline int IsPartyMember(int index) { return index >= 0 && index <= 3; }

// USA: func_ov000_02169850
extern "C" ARM void func_ov000_02169850(Struct_ov000_02169850_2* self) {
    GameState* game = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        if (!func_020a35e0(self->state, i)) continue;
        GameObject* combatant = func_0200ff1c(game, i);
        if (!combatant) continue;
        Struct_ov000_02169850_3* var3 = func_02053dc0((Struct_02053dc0*)combatant);
        if (!var3) continue;
        int value;
        Struct_ov000_02169850* action;
        if (IsPartyMember(i)) {
            for (int j = 0; j < 4; ++j) {
                if (i == self->actions[j].owner) {
                    action = &self->actions[j];
                    goto found;
                }
            }
        }
        action = 0;
    found:
        if (!action) continue;
        Struct_ov000_02169850_4 selected;
        func_ov000_02162c14(self, i, &selected);
        value = 1;
        if (selected.type == 0) {}
        else if (selected.type == 1) value = selected.value;
        else if (selected.type == 2) value = 3;
        else if (selected.type == 3) value = selected.value;
        else if (selected.type == 4) {
            ActionEntry* entry = func_ov000_02171d90(action, selected.key);
            if (entry) value = entry->value;
        } else if (selected.type == 5) value = selected.value;
        else if (selected.type == 6) {
            if (self->mode == 3 || self->mode == 4) {
                value = 0;
                var3->flags |= 1;
            } else value = 0x1f6;
        }
        var3->action = value;
        int target = action->target;
        unsigned char group = action->group;
        if (IsPartyMember(target)) {
            var3->group = 0;
            var3->target = target;
        } else if (group >= 8) {
            var3->group = 0;
            var3->target = 0;
        } else {
            var3->group = func_ov000_021761c8(self->unknown_3760_, group);
            var3->target = func_ov000_021761ec(self->unknown_3760_, group);
        }
        func_02049458((unsigned char*)combatant, var3->target);
    }
}
