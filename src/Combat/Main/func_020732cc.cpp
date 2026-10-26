#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);

struct Field150Holder02052e2c;
extern "C" short* func_02052e2c(struct Field150Holder02052e2c* obj);
extern "C" void func_02048418(unsigned char*, unsigned short);

struct Struct_020732cc;
extern "C" int func_0207c378(struct Struct_020732cc* obj, int value, int amount, int key);
extern "C" void func_ov017_0218f5a4(void* a, int i, int b, int c, int d);

struct Struct_020732cc_2 {
    unsigned char pad0[8];
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
    GameObject* combatant = func_0200ff1c(gs, arg0);
    if (combatant != NULL) {
        int i;
        short* list;
        struct Struct_020732cc_2* slot;
        for (i = 0; i < 8; i++) {
            signed short idx = data_020e8854[i];
            char* base = *(char**)((char*)combatant + Enum_020732cc_336) + 0x194;
            slot = (struct Struct_020732cc_2*)(base + (unsigned char)data_020e8864[idx] * 0x20);
            list = func_02052e2c(
                (struct Field150Holder02052e2c*)combatant);
            if (list != NULL && slot != NULL) {
                if (list[idx] > 0) {
                    func_02048418((unsigned char*)combatant, 4);
                    func_0207c378((struct Struct_020732cc*)((char*)p2a04 + 0x1d4),
                                  list[idx], 1, slot->unknown_8_0_);
                }
                list[idx] = -1;
            }
        }
        func_ov017_0218f5a4(res, arg0, 0, 0, 0);
    }
}
