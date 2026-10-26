#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02163c80_672 = 0x21c };
#else
enum { Enum_ov000_02163c80_672 = 0x2a0 };
#endif

#include "GameState/GameState.h"

struct Struct_ov000_02163c80 { char pad[Enum_ov000_02163c80_672]; unsigned char* unknown_2a0_; };

struct Obj02086b98;
struct S_10088;
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int func_02086b98(struct Obj02086b98* o);
extern "C" int func_02010088(struct S_10088* obj);

// USA: func_ov000_02163c80
extern "C" ARM int func_ov000_02163c80(struct Struct_ov000_02163c80* self, int arg1) {
    GameState* bs = GameState::GetInstance();
    struct Obj02086b98* list = (struct Obj02086b98*)GameState_GetParty(bs);
    int var2 = 1;
    int i;
    int j;
    for (i = 0; i < 4; i++) {
        GameObject* m = bs->GetPartyMemberByIndex(i);
        if (m == NULL) continue;
        if (func_020a35e0(self->unknown_2a0_, i & 0xff)) continue;
        if (!(**(int**)((char*)m + 0x130) & 1)) var2 = 0;
    }
    int var6 = func_02086b98(list) != 0;
    if (arg1) {
        var6 = 1;
        for (j = 0; j < 4; j++) {
            GameObject* c = bs->GetCombatantByIndex(j);
            if (c == NULL) continue;
            if (!func_020a35e0(self->unknown_2a0_, j & 0xff)) continue;
            if (!func_02010088((struct S_10088*)c)) var6 = 0;
        }
    }
    if (var6 && !var2) {
        unsigned char* bits = self->unknown_2a0_;
        if (bits[0x24] != 0 || bits[0x25] != 0) return 1;
    }
    return 0;
}
