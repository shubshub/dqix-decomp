#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02011430;

extern "C" ARM int func_02011430(Struct_02011430* owner, int floor, int containerSlot) {
    GameState* state = reinterpret_cast<GameState*>(owner);
    const unsigned char* flags = reinterpret_cast<const unsigned char*>(
        &state->unk_397d[0x5cd0 - 0x397d]);
    unsigned int var2 = containerSlot + (floor - 1) * 5;
    unsigned int var3 = var2 / 8;
    unsigned char mask = 1 << (var2 - var3 * 8);
    return (flags[var3] & mask) != 0;
}
