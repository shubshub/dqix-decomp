#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_02163928_30524 = 0x792c, Enum_ov000_02163928_30528 = 0x7930 };
#else
enum { Enum_ov000_02163928_30524 = 0x773c, Enum_ov000_02163928_30528 = 0x7740 };
#endif
#include "GameState/GameState.h"

extern char data_ov000_021838df[];

// USA: func_ov000_02163928
extern "C" ARM void func_ov000_02163928(char* obj) {
    GameState* battle = GameState::GetInstance();
    int i;
    for (i = 0; i < 4; i++) {
        signed char var2 = *(signed char*)(obj + Enum_ov000_02163928_30524 + i);
        if (var2 < 0) continue;
        int counter = *(unsigned char*)(obj + Enum_ov000_02163928_30528 + i);
        counter--;
        if (counter <= 0) {
            *(signed char*)(obj + Enum_ov000_02163928_30524 + i) = -1;
            GameObject* c = func_0200ff1c(battle, var2);
            if (c != 0) {
                c->obj3D_.SetAnimationByName((char const*)data_ov000_021838df, 1);
            }
        } else {
            *(unsigned char*)(obj + Enum_ov000_02163928_30528 + i) = counter;
        }
    }
}
