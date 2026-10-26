#if defined(jpn)
enum { Enum_ov017_021c40ec_14132 = 0x3524, Enum_ov017_021c40ec_384 = 0x17c };
#else
enum { Enum_ov017_021c40ec_14132 = 0x3734, Enum_ov017_021c40ec_384 = 0x180 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" void func_02052d7c(void* obj, int index, short value);
extern "C" void func_ov017_0218f5a4(void* self, int combatantId, int flag2, int arg3, int flag4);

struct Struct_ov017_021c40ec {
    char pad0[4];
    unsigned char unknown_4_0_ : 4;
    unsigned char unknown_4_4_ : 1;
    signed char arr1[5];
    short arr2[5];
};

// USA: func_ov017_021c40ec
extern "C" ARM void func_ov017_021c40ec(void* unused, struct Struct_ov017_021c40ec* info, GameState* battleStruct, void* ov) {
    int id = info->unknown_4_0_;
    char* p = (char*)GameState_GetParty(battleStruct);
    if (p != NULL) {
        int i;
        for (i = 0; i < *(unsigned char*)(p + 0xf7c); i++) {
            if (*(unsigned char*)(p + i + 0xf78) == id) return;
        }
    }

    GameObject* combatant = func_0200ff1c(battleStruct, id);
    if (combatant == NULL) return;

    char* s = *(char**)((char*)ov + Enum_ov017_021c40ec_14132);

    int j;
    for (j = 0; j < 5; j++) {
        int var6 = info->arr1[j];
        int value = info->arr2[j];
        if (var6 >= 0 && var6 < 0xa) {
            func_02052d7c(combatant, var6, value);
        }
        if (*(unsigned char*)(s + 3) != 0) {
            if (id == 0 && var6 == 6) {
                signed char v = *(signed char*)(s + Enum_ov017_021c40ec_384);
                if (v < 0) {
                    *(unsigned char*)(s + Enum_ov017_021c40ec_384) = 6;
                }
            }
        }
    }

    if (info->unknown_4_4_) {
        func_ov017_0218f5a4(ov, id, 0, 0, 0);
    }
}
