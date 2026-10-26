#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020abe84_30192 = 0x73b0 };
#else
enum { Enum_020abe84_30192 = 0x75f0 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "GameState/BattleRecordSnapshot.h"

struct Struct_020abe84 {
    unsigned int fieldA : 10;
    unsigned int rest : 22;
};

struct Struct_020abe84_2 {
    unsigned char unknown0[Enum_020abe84_30192];
    Struct_020abe84 entries[308];
};

static inline unsigned int inline_020abe84(const Struct_020abe84* e) { return e->fieldA; }

extern "C" int func_020ac4c0(void*);
extern "C" void func_020a0460(Struct_02061c04*, unsigned int);
extern "C" int func_020ac494(void*);

// USA: func_020abe84
extern "C" ARM int func_020abe84(void* unused, short* indices, Struct_020abe84* values, int count) {
    Struct_02061c04 block;
    Struct_020abe84* table = reinterpret_cast<Struct_020abe84_2*>(GameState::GetInstance())->entries;
    int added = 0;
    int i;
    for (i = 0; i < count; i++) {
        short idx = (short)(indices[i] - 1);
        Struct_020abe84* src = &values[i];
        if (idx < 0) continue;
        if (idx >= 0x134) continue;
        if (inline_020abe84(&table[idx]) == 0 && src->fieldA != 0) {
            added++;
        }
        memcpy(&table[idx], src, sizeof(*src));
    }
    func_020ac4c0(&block);
    func_020a0460(&block, added);
    func_020ac494(&block);
    return 1;
}
