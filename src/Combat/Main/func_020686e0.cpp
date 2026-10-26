#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);

struct Struct_020686e0 {
    char pad[0xf78];
    unsigned char id;
};

struct Struct_020686e0_2 {
    unsigned int flags;
    unsigned short field4;
};

struct Struct_020686e0_3 {
    char pad[0x31];
    signed char unknown_31_;
};

// USA: func_020686e0
extern "C" ARM int func_020686e0(GameState* battleStruct, struct Struct_020686e0_3* obj2) {
    unsigned char* p = (unsigned char*)GameState_GetParty(battleStruct);
    signed char count = obj2->unknown_31_;
    if (count < 0) {
        int i;
        count = 0;
        for (i = 0; i < p[0xf7c]; i++) {
            GameObject* c = battleStruct->GetPartyMemberByIndex(((struct Struct_020686e0*)(p + i))->id);
            if (c != 0) {
                struct Struct_020686e0_2* sub = *(struct Struct_020686e0_2**)((char*)c + 0x130);
                if (!(sub->flags & 1)) {
                    if (sub->field4 != 0) {
                        count = count + 1;
                    }
                }
            }
        }
    }
    return count != 1;
}
