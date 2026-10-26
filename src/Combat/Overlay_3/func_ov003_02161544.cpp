#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_02161544_1024 = 0x200 };
enum { Enum_ov003_02161544_130 = 0xaa };
#else
enum { Enum_ov003_02161544_1024 = 0x400 };
enum { Enum_ov003_02161544_130 = 0x82 };
#endif

extern "C" void* GameState_GetParty(GameState* battleStruct);

// USA: func_ov003_02161544
extern "C" ARM int func_ov003_02161544(void* self) {
    GameState* bs = GameState::GetInstance();
    unsigned char* arr = (unsigned char*)GameState_GetParty(bs);
    unsigned char count = 0;
    unsigned char i = 0;
    while (i < arr[0xf7c]) {
        unsigned char* p = arr + i;
        unsigned char id = p[0xf78];
        if (id != *(short*)((char*)self + Enum_ov003_02161544_1024 + Enum_ov003_02161544_130)) {
            GameObject* c = bs->GetCombatantByIndex(id);
            if (c != NULL) {
                int* q = *(int**)((char*)c + 0x130);
                if (*(unsigned short*)((char*)q + 4) != 0) {
                    count = count + 1;
                }
            }
        }
        i = i + 1;
    }
    return count;
}
