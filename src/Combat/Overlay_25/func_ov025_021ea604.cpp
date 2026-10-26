#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_021600f8 { char pad0[0xc]; short unknown_c_; short id; };
struct Struct_ov000_0215440c {
    unsigned short action;
    char pad2[7];
    unsigned char count;
    char padA[2];
    unsigned char unknown_c_0_ : 1;
    unsigned char unknown_c_1_ : 2;
    unsigned char unknown_c_3_ : 1;
    unsigned char unknown_c_4_ : 4;
};
struct Struct_ov025_021ea604 { unsigned short id; char pad2[2]; Struct_ov025_021ea604* next; };
typedef unsigned long long Type_02000c9c_8 __attribute__((aligned(4)));
struct Struct_ov025_021ea604_2 { Type_02000c9c_8 flags; Struct_ov025_021ea604* entries; };
struct Struct_ov025_021ea604_3 {
    char pad0[0x5c5];
    unsigned char counter;
    char unknown_5c6_[6];
    unsigned char active;
    char unknown_5cd_[3];
    unsigned char blocked;
    unsigned char enabled;
    short unknown_5d2_[9];
    int unknown_5e4_;
    char command[0x738-0x5e8];
    unsigned char busy;
    char unknown_739_[0xf];
    unsigned short timer;
};
struct Struct_ov023_021f2a48 { char pad0[0x28]; short unknown_28_; };
extern "C" void* func_ov000_02160130();
extern "C" Struct_ov000_0215440c* func_ov000_02160f20(void*);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" short func_ov000_0215ffa0(Struct_ov000_021600f8*);
extern "C" int func_ov000_0215fd90(Struct_ov025_021ea604_2*, unsigned int);
extern "C" void func_ov025_021ed35c(char*);
extern "C" void func_ov025_021ea958(Struct_ov025_021ea604_3*, int, int, int);
extern "C" int func_ov025_021ed380(char*, unsigned short, short, int, Struct_ov025_021ea604_2*, short, unsigned short);
extern "C" void func_ov025_021ead5c(Struct_ov025_021ea604_3*, int);
inline int inline_ov025_021dfce0_2(int id) { return id >= 0 && id <= 3; }

// USA: func_ov025_021ea604
extern "C" ARM void func_ov025_021ea604(Struct_ov025_021ea604_3* display, int index, int, Struct_ov025_021ea604_2* effect) {
    GameState* game = GameState::GetInstance();
    Struct_ov000_0215440c* list = func_ov000_02160f20(func_ov000_02160130());
    Struct_ov000_021600f8* node = func_ov000_021600f8(list, index);
    int force = 0;
    if (display->blocked) {
        int var4 = 1;
        int inRange = 0;
        if (node->id >= 0 && node->id <= 3) inRange = 1;
        bool party = inRange;
        for (int i = index + 1; i < list->count; i++) {
            Struct_ov000_021600f8* other = func_ov000_021600f8(list, i);
            int var9 = 0;
            if (other->id >= 0 && other->id <= 3) var9 = 1;
            bool var10 = var9;
            if ((party && var10) || (!party && !var10)) { var4 = 0; break; }
        }
        for (Struct_ov025_021ea604* entry = effect->entries; entry; entry = entry->next) {
            if (entry->id == 8) {
                display->unknown_5d2_[display->unknown_5e4_] = func_ov000_0215ffa0(node);
                display->unknown_5e4_++;
                entry->id = 0;
            }
        }
        if (var4) { force = 1; display->enabled = force; }
    }
    if (node) {
        int actorId = func_ov000_0215ffa0(node);
        if (!effect) return;
        if (func_ov000_0215fd90(effect, 11)) {
            GameObject* actor = game->GetCombatantByIndex(node->id);
            if (actor) actorId = ((Struct_ov023_021f2a48*)actor->currentStats_)->unknown_28_;
        }
        if (list->action == 0x399) actorId = node->unknown_c_;
        int reset = 0;
        if (!display->busy && display->timer < 500 && !display->active) reset = 1;
        int show = 1;
        if (inline_ov025_021dfce0_2(actorId) && list->unknown_c_0_ && !func_ov000_0215fd90(effect, 1)) show = 0;
        else if (!inline_ov025_021dfce0_2(actorId) && list->unknown_c_3_ && !func_ov000_0215fd90(effect, 1)) show = 0;
        if (show && reset) func_ov025_021ed35c(display->command);
        if (show || force) {
            int update = 0;
            if (force) update = 1;
            int selection = (short)actorId;
            if (force) selection = -2;
            func_ov025_021ea958(display, inline_ov025_021dfce0_2(actorId) ? 1 : 0, update, selection);
        }
        for (Struct_ov025_021ea604* entry = effect->entries; entry; entry = entry->next) {
            func_ov025_021ed380(display->command, entry->id, actorId, 1, effect, -1, 0);
        }
        if (display->active && func_ov000_0215fd90(effect, 2)) func_ov025_021ead5c(display, inline_ov025_021dfce0_2(actorId) ? 1 : 0);
    }
    display->counter++;
}
