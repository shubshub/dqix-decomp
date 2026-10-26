#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_020dc4d0(signed char*, signed char*);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" int func_020546a8(void*);
static inline int inline_020dc548(int index) { return index >= 0 && index <= 3; }

// USA: func_020dc548
extern "C" ARM void func_020dc548(int index, signed char* out, signed char* outCount) {
    if (!inline_020dc548(index)) { *outCount = 0; return; }
    GameState* game = GameState::GetInstance();
    signed char slots[4], count;
    func_020dc4d0(slots, &count);
    signed char groups[4][4];
    int leader = -1;
    signed char member = 0;
    signed char group = 0;
    signed char groupCounts[4] = {};
    for (signed char i = 0; i < count; ++i) {
        int slot = slots[i];
        GameObject* object = func_0200ff58(game, slot);
        if (object) {
            if (leader == func_020546a8(object)) {
                groups[group][member] = slot;
                ++groupCounts[group];
                ++member;
            }
        } else {
            game->GetPartyMemberByIndex(slot);
            if (leader >= 0) ++group;
            groups[group][0] = slot;
            ++groupCounts[group];
            member = 0;
            ++member;
            leader = slot;
        }
    }
    for (signed char i = 0; i < 4; ++i) {
        bool found = false;
        for (signed char j = 0; j < groupCounts[i]; ++j) {
            if (index == groups[i][j]) found = true;
        }
        if (found) {
            if (out) memcpy(out, groups[i], groupCounts[i]);
            *outCount = groupCounts[i];
            break;
        }
    }
}
