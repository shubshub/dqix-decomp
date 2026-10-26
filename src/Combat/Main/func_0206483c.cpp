#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);

// USA: func_0206483c
extern "C" ARM int func_0206483c(void* unused0, char* name) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(battleStruct, 0);
    char* var2 = (char*)func_02053c6c((unsigned char*)combatant) + 0x3c;
    int len = strlen(var2);
    int i;
    int var5;

    for (i = 0; i < len; name++, var2++, i++) {
        if ((i % 2) == 0) {
            if (*name == *var2) {
                var5 = 1;
            } else {
                var5 = 0;
            }
        } else if (var5) {
            if (*name != *var2) {
                return 0;
            }
        } else {
            unsigned char c1 = *(unsigned char*)name;
            unsigned char c2 = *(unsigned char*)var2;
            int shift = 0x5f;
            if (c1 > 0x7f) {
                shift = 0x5e;
            }
            int var9 = (c1 + shift) & 0xff;
            if (var9 != c2) {
                return 0;
            }
        }
    }
    return 1;
}
