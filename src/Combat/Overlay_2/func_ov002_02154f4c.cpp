#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Sub {
    unsigned char pad[RG(0xc68, 0xb2c)];
    unsigned char slots[5];
};

extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" void func_ov002_02154c30(void* p);

// USA: func_ov002_02154f4c
extern "C" ARM int func_ov002_02154f4c(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned char buf[8];
    unsigned char n = GameState_GetPartyOrder((char*)battle, buf);
    unsigned char count = 0;
    unsigned char i;

    buf[n] = 4;
    for (i = 0; i < n; i++) {
        if (battle->GetPartyMemberByIndex(buf[i]) != NULL) {
            ((Sub*)(obj + count + 0x1000))->slots[0] = buf[i];
            count = count + 1;
        }
    }
    ((Sub*)(obj + count + 0x1000))->slots[0] = 4;
    obj[0x1000 + RG(0xc6d, 0xb31)] = count;

    int j;
    for (j = 0; j < 4; j++) {
        memset(obj + RG(0xa70 + 0x1000, 0x19c8) + j * 16, 0, 4);
    }
    func_ov002_02154c30(obj + RG(0xa70 + 0x1000, 0x19c8));
    return 0;
}
