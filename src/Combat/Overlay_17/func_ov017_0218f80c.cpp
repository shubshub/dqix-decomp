#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);
extern "C" void OS_WaitVBlankIntr(void);
void StageTexFilePaletteData(NSBXXTex volatile*, bool);
struct NSBXXTex;
void StageTexFileImageData(NSBXXTex volatile*, bool);

struct Struct_ov017_021d61fc {
    int v[12];
};
extern struct Struct_ov017_021d61fc data_ov017_021d61fc;

// USA: func_ov017_0218f80c
extern "C" ARM void func_ov017_0218f80c(void* obj, int idx) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x4000004;
    if ((*var0 & 1) == 0) {
        OS_WaitVBlankIntr();
    }

    GameState* battleStruct = GameState::GetInstance();

    struct Struct_ov017_021d61fc table = data_ov017_021d61fc;
    int base = idx * 12;
    table.v[0] = idx;
    table.v[1] = base + 0x13;
    table.v[2] = base + 0x14;
    table.v[3] = base + 0x16;
    table.v[4] = base + 0x17;
    table.v[5] = base + 0x18;
    table.v[6] = base + 0x19;
    table.v[7] = base + 0x1a;
    table.v[8] = base + 0x1b;
    table.v[9] = base + 0x1c;
    table.v[10] = base + 0x1d;

    int i;
    for (i = 0; table.v[i] > -1; i++) {
        GameObject* combatant = battleStruct->GetGameObjectByIndex(table.v[i]);
        if (combatant == NULL) {
            continue;
        }
        if (combatant->obj3D_.unknown_2_ <= -1) {
            continue;
        }
        void* ptr = combatant->obj3D_.pModel_;
        if (ptr == NULL) {
            continue;
        }
        int var7 = _ZN7Model3D7GetTEX0Ev(ptr);
        if (var7 == 0) {
            continue;
        }
        StageTexFilePaletteData((NSBXXTex volatile*)var7, 0);
        StageTexFileImageData((NSBXXTex volatile*)var7, 0);
    }
}
