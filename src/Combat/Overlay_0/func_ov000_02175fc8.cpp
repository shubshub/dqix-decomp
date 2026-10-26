#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x8b4
#define REGION_OFFSET_1 0x483
#else
#define REGION_OFFSET_0 0x94c
#define REGION_OFFSET_1 0x443
#endif

#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void* obj, int index);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);

// USA: func_ov000_02175fc8
extern "C" ARM void func_ov000_02175fc8(void* obj) {
    char* e;
    int i;
    for (i = 0; i < 4; i++) {
        e = (char*)func_ov000_02161318(obj, i);
        if (e == NULL) continue;
        GameState* bs = GameState::GetInstance();
        GameObject* c = func_0200ff1c(bs, *(int*)(e + 0x4c));
        if (c == NULL) continue;
        int* p = *(int**)((char*)c + 0x130);
        if (*p & 4) {
            *(int*)(e + 0x28) |= 4;
        }
        int var5 = func_02053c6c((unsigned char*)c);
        if (var5 != 0) {
            *(unsigned char*)(e + REGION_OFFSET_1) = (unsigned char)*(int*)(var5 + REGION_OFFSET_0);
        }
    }
}
