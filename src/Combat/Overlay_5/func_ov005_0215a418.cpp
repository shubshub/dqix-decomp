#if defined(jpn)
#define func_ov005_0215a418 func_ov005_0215b96c
#endif

#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_020c51a4 func_020c6c70
#endif

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

extern "C" void func_020c51a4(int arg0);

extern "C" char* func_ov017_021a193c(int*);
struct Struct_02052e14;
extern "C" short* func_02052e14(Struct_02052e14*);
extern "C" void func_02047554(void* arg0, int arg1, int arg2);

extern const unsigned char data_ov005_0215cc1c[];

#define G3_MTX_PUSH  (*(volatile int*)0x04000444)
#define G3_MTX_POP   (*(volatile int*)0x04000448)
#define G3_MTX_SCALE (*(volatile int*)0x0400046c)
#define G3_MTX_TRANS (*(volatile int*)0x04000470)

struct Struct_ov005_0215a418_2 { char unknown_0_[0x88]; };

struct Struct_ov005_0215a418_3 {
    char unknown_0_[0x1000];
    Struct_ov005_0215a418_2 unknown_1000_[1];
};

struct Struct_ov005_0215a418 {
    char unknown_0_[LOW_REGION(0x19e8, 0x1a70)];
    Struct_ov005_0215a418_2 unknown_1a70_[(LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70)) / 0x88];
    char unknown_3d80_[LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70) - ((LOW_REGION(0x3d30, 0x3db8) - LOW_REGION(0x19e8, 0x1a70)) / 0x88) * 0x88];
    unsigned char unknown_3db8_;
    char unknown_3db9_[3];
    unsigned char unknown_3dbc_;
};

// USA: func_ov005_0215a418
extern "C" ARM void func_ov005_0215a418(Scene0215a418* self) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    char* holder = GetField1c_021a193c((int*)res->unknown_ptr_array_3700[2]);
    short* tbl = GetField150Ptr0x488((Field150Holder02052e14*)(GetCombatantWithFlag0x100_0200ff1c(gs,*(int*)(holder + LOW_REGION(0x4f8, 0x4fc)))));
    if (self->mode != 0) return;

    for (int var4 = 0; var4 < 8; var4++) {
        int var5 = 0;
        if (var4 == arg0->unknown_3dbc_) var5 = 1;
        int var6 = var5 * 11;
        int var7 = (var4 * 0x18) << 12;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x7f000;
        int var8 = (var6 + 4) * 0x88;
        Struct_ov005_0215a418_2* var9 = ((Struct_ov005_0215a418_3*)((char*)arg0 + LOW_REGION(0x9e8, 0xa70)))->unknown_1000_;
        G3_MTX_TRANS = var7;
        G3_MTX_TRANS = -0x200000;
        func_02047554((Struct_ov005_0215a418_2*)((char*)var9 + var8), 0, 1);
        G3_MTX_POP = 1;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x100000;
        G3_MTX_TRANS = var7;
        G3_MTX_TRANS = -0x200000;
        Matrix4x3 var10 = RotationMatrixY(0x3244);
        func_020c51a4((int)&var10);
        func_02047554((Struct_ov005_0215a418_2*)((char*)var9 + var8), 0, 1);
        G3_MTX_POP = 1;
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x70000;
        G3_MTX_TRANS = var7;
        G3_MTX_TRANS = -0x200000;
        G3_MTX_SCALE = 0x14000;
        G3_MTX_SCALE = 0x1000;
        G3_MTX_SCALE = 0x1000;
        func_02047554(&arg0->unknown_1a70_[var6 + 5], 0, 1);
        G3_MTX_POP = 1;
        Struct_ov005_0215a418_2* var11 = &arg0->unknown_1a70_[var6 + 7 + var4];
        if (var3[data_ov005_0215cc1c[var4]] > 0) {
            var11 = &arg0->unknown_1a70_[var6 + 6];
        }
        G3_MTX_PUSH = 0;
        G3_MTX_TRANS = 0x85000;
        G3_MTX_TRANS = var7;
        G3_MTX_TRANS = -0x1ff000;
        func_02047554(var11, 0, 1);
        G3_MTX_POP = 1;
    }
}
