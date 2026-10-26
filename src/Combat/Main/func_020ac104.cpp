#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"
#include "std_library_functions.h"
struct Struct_020ac104 {
    short id;
    unsigned short active : 1;
    unsigned short flag : 1;
    unsigned short padding : 14;
};
struct Struct_020ac104_2 {
    unsigned short packed;
};
struct Struct_020ac104_3 {
    unsigned char pad0[IS_JPN ? 0x7884 : 0x7ac4];
    Struct_020ac104_2 entries[0x1d7];
};
struct Struct_020a0434 {
    unsigned char pad0[0x10];
    unsigned int low : 23;
    unsigned int value : 9;
    unsigned char pad1[0xb0 - 0x14];
};
extern "C" int func_020ac4c0(void*);
extern "C" void func_020a0434(Struct_020a0434*, unsigned int);
extern "C" int func_020ac494(void*);
// USA: func_020ac104
extern "C" ARM int func_020ac104(int unused, Struct_020ac104* input, int count) {
    Struct_020ac104_3* state = (Struct_020ac104_3*)GameState::GetInstance();
    int added = 0;
    Struct_020ac104_2* entries = state->entries;
    for (int i = 0; i < count; i++) {
        Struct_020ac104* entry = &input[i];
        if (entry->id < 0) continue;
        Struct_020ac104_2* cursor = entries;
        unsigned int slot = 0;
        unsigned int j;
        int id = entry->id;
        for (j = 0; j < 0x1d7; j++) {
            slot = j;
            int var9 = (cursor->packed & 0xfffc) >> 2;
            if (var9 <= 0) {
                if (entry->active == 1) added++;
                break;
            }
            if (var9 == id) {
                if (!((cursor->packed & 2) >> 1) && entry->active == 1) added++;
                break;
            }
            cursor++;
        }
        Struct_020ac104_2 var10;
        var10.packed = (id << 2) | (entry->active << 1) | entry->flag;
        memcpy(&state->entries[slot], &var10, 2);
    }
    Struct_020a0434 block;
    func_020ac4c0(&block);
    func_020a0434(&block, added);
    func_020ac494(&block);
    return 1;
}
