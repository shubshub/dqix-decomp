#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern void* GameState_GetParty(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);

struct Struct_02052e2c;
extern "C" short* func_02052e2c(struct Struct_02052e2c* arg0);
extern "C" void func_02048418(unsigned char*, unsigned short);

struct Struct_020732cc;
extern "C" int func_0207c378(struct Struct_020732cc* arg0, int arg1, int arg2, int arg3);
extern "C" void func_ov017_0218f5a4(void* arg0, int arg1, int arg2, int arg3, int arg4);

struct Struct_020732cc_2 {
    unsigned char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
};

extern signed short data_020e8854[];
extern signed short data_020e8864[];

#if defined(jpn)
enum { Enum_020732cc_336 = 0x144 };
#else
enum { Enum_020732cc_336 = 0x150 };
#endif

// USA: func_020732cc
extern "C" ARM void func_020732cc(int arg0) {
    GameState* gs = GameState::GetInstance();
    void* res = GetGameResources();
    void* p2a04 = GameState_GetParty(gs);
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(gs, arg0);
    if (combatant != NULL) {
        int i;
        short* list;
        struct Slot020732cc* slot;
        for (i = 0; i < 8; i++) {
            signed short idx = data_020e8854[i];
            char* base = *(char**)((char*)combatant + CombatantSlotOffset) + 0x194;
            slot = (struct Slot020732cc*)(base + (unsigned char)data_020e8864[idx] * 0x20);
            list = GetField150Ptr0x488_02052e2c(
                (struct Field150Holder02052e2c*)combatant);
            if (list != NULL && slot != NULL) {
                if (list[idx] > 0) {
                    TryClearFlags0x130_02048418((unsigned char*)combatant, 4);
                    func_0207c378((struct KeyedList0207c378*)((char*)p2a04 + 0x1d4),
                                  list[idx], 1, slot->keyBits);
                }
                var5[var7] = -1;
            }
        }
        func_ov017_0218f5a4(var1, arg0, 0, 0, 0);
    }
}
