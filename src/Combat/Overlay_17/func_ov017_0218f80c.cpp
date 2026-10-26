#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);
void OS_WaitVBlankIntr(void);
void StageTexFilePaletteData(NSBXXTex volatile*, bool);
struct NSBXXTex;
void StageTexFileImageData(NSBXXTex volatile*, bool);

struct Struct_ov017_021d61fc {
    int unknown_0_[12];
};
extern struct Struct_ov017_021d61fc data_ov017_021d61fc;

// USA: func_ov017_0218f80c
extern "C" ARM void func_ov017_0218f80c(void* obj, int idx) {
    volatile unsigned short* dispstat = (volatile unsigned short*)0x4000004;
    if ((*dispstat & 1) == 0) {
        OS_WaitVBlankIntr();
    }

    GameState* var1 = GameState::GetInstance();

    struct Struct_ov017_021d61fc var2 = data_ov017_021d61fc;
    int var3 = arg1 * 12;
    var2.unknown_0_[0] = arg1;
    var2.unknown_0_[1] = var3 + 0x13;
    var2.unknown_0_[2] = var3 + 0x14;
    var2.unknown_0_[3] = var3 + 0x16;
    var2.unknown_0_[4] = var3 + 0x17;
    var2.unknown_0_[5] = var3 + 0x18;
    var2.unknown_0_[6] = var3 + 0x19;
    var2.unknown_0_[7] = var3 + 0x1a;
    var2.unknown_0_[8] = var3 + 0x1b;
    var2.unknown_0_[9] = var3 + 0x1c;
    var2.unknown_0_[10] = var3 + 0x1d;

    int var4;
    for (var4 = 0; var2.unknown_0_[var4] > -1; var4++) {
        GameObject* var5 = var1->GetGameObjectByIndex(var2.unknown_0_[var4]);
        if (var5 == NULL) {
            continue;
        }
        if (var5->obj3D_.unknown_2_ <= -1) {
            continue;
        }
        void* var6 = var5->obj3D_.pModel_;
        if (var6 == NULL) {
            continue;
        }
        int var7 = _ZN7Model3D7GetTEX0Ev(var6);
        if (var7 == 0) {
            continue;
        }
        StageTexFilePaletteData((NSBXXTex volatile*)var7, 0);
        StageTexFileImageData((NSBXXTex volatile*)var7, 0);
    }
}
