#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov003_0217839c_336 = 0x144 };
#else
enum { Enum_ov003_0217839c_336 = 0x150 };
#endif

struct Struct_ov003_0217839c {
    unsigned int word0;
    unsigned int pad4 : 27;
    unsigned int unknown_7_3_ : 1;
    unsigned int unknown_7_4_ : 1;
    unsigned int unknown_7_5_ : 1;
    unsigned int unknown_7_6_ : 2;
};

struct Struct_ov003_0217839c_2 {
    Struct_ov003_0217839c* flags;
    unsigned char pad4[0x18 - 4];
    short unknown_18_;
};

struct Struct_ov003_0217839c_3 {
    unsigned char pad0[8];
    unsigned int kind : 4;
    unsigned int pad8 : 28;
};

struct Struct_ov003_0217839c_4 {
    unsigned char pad0[0x49c];
    unsigned char bit0 : 1;
    unsigned char unknown_49c_1_ : 7;
};

extern unsigned char data_ov003_0217fb60[];

// USA: func_ov003_0217839c
extern "C" ARM int func_ov003_0217839c(int id, void* entry) {
    if (((Struct_ov003_0217839c_3*)entry)->kind != 7) return 0;
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), id);
    if (combatant == 0) return 0;

    unsigned char i;
    uintptr_t base = *(uintptr_t*)((char*)combatant + Enum_ov003_0217839c_336);
    uintptr_t address = base + 0x2d4;
    if (address == 0) return 0;
    if (*(short*)(address + 0x18) != 0x4680) return 0;

    unsigned char selected[2];
    i = 0;
    while (i < 8) {
        unsigned char index = data_ov003_0217fb60[i];
        if (index == 0xff) break;
        uintptr_t var6 = base + 0x194 + ((unsigned int)index << 5);
        if (var6 != 0) {
            Struct_ov003_0217839c_2* slot = (Struct_ov003_0217839c_2*)var6;
            if (slot->unknown_18_ >= 0) {
                Struct_ov003_0217839c* flags = slot->flags;
                if (flags != 0 && !flags->unknown_7_5_) {
                    selected[0] = flags->unknown_7_3_ ? 1 : 0;
                    selected[1] = flags->unknown_7_4_ ? 1 : 0;
                    if (selected[((Struct_ov003_0217839c_4*)base)->bit0] == 0) return 1;
                }
            }
        }
        ++i;
    }
    return 0;
}
