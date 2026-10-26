#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov001_0215ad2c(int x);
extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);
extern "C" void func_0200fd48(GameState* battleStruct, int id);

struct Struct_ov001_02160d14 {
    unsigned char pad[0xd4];
    unsigned char unknown_d4_0_ : 1;
};

// USA: func_ov001_02160d14
extern "C" ARM int func_ov001_02160d14(char* self) {
    GameState* bs = GameState::GetInstance();
    void* global = func_0203cf4c();
    int var2 = func_ov017_021d60f4(self);
    int id2 = func_ov001_0215ad2c(func_ov017_021d60f4(self + 0x8));
    if (id2 < 0xa0 || id2 > 0xbf) return 0;
    void* entry = func_0203df78(global, var2);
    if (entry == 0) return 0;
    struct Struct_ov001_02160d14* combatant = *(struct Struct_ov001_02160d14**)((char*)entry + 0x18);
    if (combatant == 0) return 0;
    combatant->unknown_d4_0_ = 0;
    func_0200fd48(bs, id2);
    return 1;
}
