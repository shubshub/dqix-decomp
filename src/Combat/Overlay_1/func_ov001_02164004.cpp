#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"

struct Struct_02000c9c_39 {
    char pad[0x20];
    short current;
    short previous;
    short unknown_24_;
    short kind;
    short counter;
};

extern "C" float func_ov017_021d6110(void* obj);
extern "C" unsigned int func_ov017_021d60f4(void* obj);

// USA: func_ov001_02164004
extern "C" ARM int func_ov001_02164004(void* obj, int count) {
    float f = func_ov017_021d6110(obj);
    unsigned int extra = 0;
    GameState* battle = GameState::GetInstance();
    if (count >= 2) {
        extra = func_ov017_021d60f4((char*)obj + 8);
    }
    unsigned short kind = extra * battle->GetEffectiveDeltaTime();
    LightingManager::GetInstance()->BeginFade(4096.0f * f, kind);
    return 1;
}
