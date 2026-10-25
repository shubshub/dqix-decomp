#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02163c80_672 = 0x21c };
#else
enum { Enum_ov000_02163c80_672 = 0x2a0 };
#endif

#include "GameState/GameState.h"

struct Struct_ov000_02163c80 { char unknown_0_[Enum_ov000_02163c80_672]; unsigned char* unknown_2a0_; };

struct Struct_0201bdac_4;
struct Struct_02010088;
extern "C" int func_020a35e0(unsigned char* arg0, unsigned char arg1);
extern "C" int func_02086b98(struct Struct_0201bdac_4* arg0);
extern "C" int func_02010088(struct Struct_02010088* arg0);

// USA: func_ov000_02163c80
extern "C" ARM int func_ov000_02163c80(struct S02163c80* self, int checkEnemies) {
    GameState* bs = GameState::GetInstance();
    struct Obj02086b98* list = (struct Obj02086b98*)GameState_GetParty(bs);
    int partyOk = 1;
    int i;
    int j;
    for (i = 0; i < 4; i++) {
        GameObject* m = bs->GetPartyMemberByIndex(i);
        if (m == NULL) continue;
        if (TestBitAt0x34_020a35e0(self->bitsPtr, i & 0xff)) continue;
        if (!(**(int**)((char*)m + 0x130) & 1)) partyOk = 0;
    }
    int var6 = func_02086b98(var1) != 0;
    if (arg1) {
        var6 = 1;
        for (var4 = 0; var4 < 4; var4++) {
            GameObject* var7 = var0->GetCombatantByIndex(var4);
            if (var7 == NULL) continue;
            if (!func_020a35e0(arg0->unknown_2a0_, var4 & 0xff)) continue;
            if (!func_02010088((struct Struct_02010088*)var7)) var6 = 0;
        }
    }
    if (var6 && !var2) {
        unsigned char* var8 = arg0->unknown_2a0_;
        if (var8[0x24] != 0 || var8[0x25] != 0) return 1;
    }
    return 0;
}
