#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_0207d300;
extern "C" int func_02083960(struct Struct_0207d300* s);

// USA: func_02086d20
extern "C" ARM int func_02086d20(unsigned char* self) {
    short total = 0;
    GameState* battleStruct = GameState::GetInstance();
    int i = 0;
    while (i < self[0xf7c]) {
        unsigned char* p = self + i;
        GameObject* c = func_0200ff1c(battleStruct, p[0xf78]);
        if (c != 0) {
            int field = func_02053c6c((unsigned char*)c);
            if (field != 0) {
                total = total + func_02083960((struct Struct_0207d300*)field);
            }
        }
        i++;
    }
    return total;
}
