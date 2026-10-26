#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02166f40_1024 = 0x200 };
enum { Enum_ov003_02166f40_130 = 0xaa };
#else
enum { Enum_ov003_02166f40_1024 = 0x400 };
enum { Enum_ov003_02166f40_130 = 0x82 };
#endif
#include "GameState/GameState.h"

extern "C" void func_ov017_021b6bb8(int combatantId);
extern "C" int func_ov017_021b6c2c(int a, int d);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

// USA: func_ov003_02166f40
extern "C" ARM void func_ov003_02166f40(char* obj) {
    func_ov017_021b6bb8(*(short*)(obj + Enum_ov003_02166f40_1024 + Enum_ov003_02166f40_130));
    func_ov017_021b6c2c(*(short*)(obj + Enum_ov003_02166f40_1024 + Enum_ov003_02166f40_130), 0);
    GameObject* c = GameState::GetInstance()->GetProtagonist();
    if (c == NULL) return;
    GameObject_DisableControl((struct Obj020397cc*)c, 1);
}
