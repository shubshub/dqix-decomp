#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021e2c34_28 = 0xc };
#else
enum { Enum_ov025_021e2c34_28 = 0x1c };
#endif

#include "GameState/GameState.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094;
struct Struct_02059cfc_4;
struct S190;

extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern int data_ov025_021ef988;

// USA: func_ov025_021e2c34
extern "C" ARM int func_ov025_021e2c34(void* unused, struct Struct_ov000_0215440c_2* list) {
    struct Struct_ov000_02160094* node = func_ov000_02160094(list, 0);
    if (!node) return 0;
    int id = *(unsigned short*)((char*)node + 0x20);
    GameState* battle = GameState::GetInstance();
    GameObject* c = battle->GetGameObjectByIndex(id);
    int flags = *(int*)((char*)&data_ov025_021ef988 + Enum_ov025_021e2c34_28);
    if (flags & 4) return 0;
    if (((Object3D*)((struct Struct_02059cfc_4*)c))->HasAnimationStopped()) return 1;
    return ((Object3D*)((struct S190*)c))->HasAnimationJustStarted() != 0;
}
