#if defined(jpn)
enum { Enum_ov017_02195658_1052 = 0x16c, Enum_ov017_02195658_2864 = 0x910 };
#else
enum { Enum_ov017_02195658_1052 = 0x41c, Enum_ov017_02195658_2864 = 0xb30 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;
extern "C" struct SearchStruct* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsSlotLost(struct SearchStruct* obj, int value);
extern "C" GameObject* func_0200fee0(GameState* battleStruct, int combatantId);
extern "C" void func_ov017_021905b8(void* self, int idx, int flag);

// USA: func_ov017_02195658
extern "C" ARM int func_ov017_02195658(unsigned char* self) {
    GameState* battle = GameState::GetInstance();
    struct SearchStruct* search = LinkSession_GetInstance();
    for (int i = 1; i < 4; i++) {
        int flagA = 0;
        int var4 = 1;
        GameObject* c = func_0200fee0(battle, i);
        unsigned char* ptr = *(unsigned char**)(self + 0x4000 + Enum_ov017_02195658_1052);
        if (ptr[0] == 1 && ptr[2] == i) {
            if (c != NULL) {
                flagA = var4;
                var4 = 0;
            }
        }
        if (LinkSession_IsSlotLost(search, i) != 0) flagA = 1;
        if (flagA != 0) {
            func_ov017_021905b8(self, i, var4);
            if (var4 != 0) {
                unsigned char* ptr2 = *(unsigned char**)(self + 0x4000 + Enum_ov017_02195658_1052);
                if (ptr2[0] != 0 && ptr2[2] == i) {
                    ptr2[0] = 0;
                    ptr2[1] = 0;
                    unsigned char* other = *(unsigned char**)(self + 0x3000 + Enum_ov017_02195658_2864);
                    if (other[3] != 0) other[8] = 1;
                }
            }
            return i;
        }
    }
    return -1;
}
