#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void* GameState_GetParty(GameState*);

struct Struct_ov023_021f4438 {
#if defined(jpn)
    char pad0[0x5af0];
#else
    char pad0[0x5900];
#endif
    unsigned char unknown_5900_;
    signed char unknown_5901_;
#if defined(jpn)
    char pad1[0x7014 - 0x5af2];
#else
    char pad1[0x6e24 - 0x5902];
#endif
    int unknown_6e24_;
};

struct ElemBlock021f4438 {
    char pad0[0xf78];
    unsigned char unknown_f78_;
    char pad1[0xf7c - 0xf79];
    unsigned char count;
};

// USA: func_ov023_021f4438
extern "C" ARM int func_ov023_021f4438(Struct_ov023_021f4438* obj) {
    int result = 0;
    if (obj->unknown_5900_ != 0 || obj->unknown_6e24_ != 0) {
        GameState* battleStruct = GameState::GetInstance();
        void* p = LinkSession_GetInstance();
        result = 1;
        if (LinkSession_IsActive((int*)p)) {
            ElemBlock021f4438* base = (ElemBlock021f4438*)GameState_GetParty(battleStruct);
            int found = 0;
            int i;
            for (i = 0; i < base->count; i++) {
                ElemBlock021f4438* elem = (ElemBlock021f4438*)((char*)base + i);
                if (obj->unknown_5901_ & (1 << elem->unknown_f78_)) {
                    found = 1;
                    break;
                }
            }
            if (!found) result = 0;
        }
    }
    return result;
}
