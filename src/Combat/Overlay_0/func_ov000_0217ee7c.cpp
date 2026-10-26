#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" void* GameState_GetParty(GameState*);

extern "C" ARM void func_ov000_0217ee7c(signed char* indices, signed char* count,
                                     int arg2, int mode)
{
    unsigned char* inventory = static_cast<unsigned char*>(GameState_GetParty(GameState::GetInstance()));
    signed char remaining = *count;
    switch (mode) {
    case 0:
        break;
    case 1:
        for (signed char slot = 0; slot < *count; ++slot) {
            signed char selected = indices[slot];
            int present = 0;
            for (signed char party = 0; party < inventory[0xf7c]; ++party) {
                if (selected == (inventory + party)[0xf78]) {
                    present = true;
                    break;
                }
            }
            if (!present) {
                --remaining;
                indices[slot] = -1;
            }
        }
        break;
    case 2:
        int var6 = arg2 >= 0 && arg2 <= 3;
        if (var6) {
            for (signed char slot = 0; slot < remaining; ++slot) {
                if (arg2 == indices[slot]) {
                    --remaining;
                    indices[slot] = -1;
                    break;
                }
            }
        }
        break;
    }
    for (signed char slot = 0; slot < *count - 1; ++slot) {
        if (indices[slot] < 0) {
            for (signed char next = slot + 1; next < *count; ++next) {
                if (indices[next] >= 0) {
                    indices[slot] = indices[next];
                    indices[next] = -1;
                    break;
                }
            }
        }
    }
    *count = remaining;
}
