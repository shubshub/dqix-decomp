#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"
#include "std_library_functions.h"
struct Struct_020ac2d4 { unsigned short value; };
struct Struct_020ac2d4_2 {
    unsigned short key;
    unsigned short bit0:1, unknown_2_1_:1, rest:14;
};
struct Struct_020ac2d4_3 { char pad[0x7800]; Struct_020ac2d4 entries[0x1d7]; };
struct Struct_020ac2d4_4 { char unknown0[IS_JPN ? 0x84 : 0x2c4]; Struct_020ac2d4_3 battle; };
// USA: func_020ac2d4
extern "C" ARM int func_020ac2d4(void*, short* keys, Struct_020ac2d4_2* output, int count) {
    Struct_020ac2d4_3* view = &((Struct_020ac2d4_4*)GameState::GetInstance())->battle;
    for (int i = 0; i < count; i++) {
        int key = keys[i];
        if (key >= 0) {
            int found = 0;
            Struct_020ac2d4* entry = view->entries;
            unsigned int index = 0;
            for (; index < 0x1d7; entry++, index++) {
                int current = (entry->value & 0xfffc) >> 2;
                if (current <= 0) { found = 1; break; }
                if (current == key) { found = 1; break; }
            }
            if (found) {
                Struct_020ac2d4_2 value;
                value.key = key;
                value.bit0 = (entry->value & 2) >> 1;
                value.unknown_2_1_ = entry->value & 1;
                memcpy(&output[i], &value, 4);
            }
        }
    }
    return 1;
}
