#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_ov001_02161d54 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

extern "C" int func_ov017_021d6134(void* obj, int flag);

// USA: func_ov001_02161d54
extern "C" ARM int func_ov001_02161d54(void* obj) {
    GameObject* combatant = GameState::GetInstance()->GetProtagonist();
    struct Struct_ov001_02161d54* sub = (struct Struct_ov001_02161d54*)func_02053c6c((unsigned char*)combatant);
    int flag = sub->bit0 ? 0 : 1;
    func_ov017_021d6134(obj, flag);
    return 1;
}
