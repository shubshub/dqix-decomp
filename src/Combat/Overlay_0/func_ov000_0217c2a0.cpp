#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02054000;
extern "C" void* func_02054000(struct Struct_02054000* p);
extern "C" int func_ov000_0217538c(void* objRaw);

struct Struct_ov000_02184294_10 {
#if defined(jpn)
    void* field8;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    void* field8;
#endif
};
extern Struct_ov000_02184294_10 data_ov000_02184294;

// USA: func_ov000_0217c2a0
extern "C" ARM int func_ov000_0217c2a0(void* objRaw) {
    char* obj = (char*)objRaw;
    int result = 0;
    GameState* battleStruct = GameState::GetInstance();
    int var3 = *(int*)(obj + 0x4c);
    GameObject* combatant = func_0200ff1c(battleStruct, var3);
    if (combatant != 0) {
        void* sub = func_02054000((struct Struct_02054000*)combatant);
        if (sub != 0) {
            short val = *(short*)((char*)sub + 0x18);
            if (val > 0) {
                struct Struct_ov000_0217c2a0 { unsigned int bit0 : 1; unsigned int unknown_0_1_ : 1; unsigned int hi : 30; };
#if defined(jpn)
                enum { Enum_ov000_0217c2a0_336 = 0x144 };
#else
                enum { Enum_ov000_0217c2a0_336 = 0x150 };
#endif
                struct Struct_ov000_0217c2a0* bits = (struct Struct_ov000_0217c2a0*)(*(int*)((char*)combatant + Enum_ov000_0217c2a0_336) + 0x2f4);
                if (bits->unknown_0_1_) {
                    result = 1;
                } else {
                    if (bits->bit0) {
                        if (func_ov000_0217538c(data_ov000_02184294.field8) == 1) {
                            result = 1;
                        }
                    }
                }
            }
        }
        if (data_ov000_02184294.field0 == 1) {
            result = 1;
        }
    }
    return result;
}
