#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Matrix.h"

struct Struct_ov000_0217e870_2;
struct Struct_02010604;

struct Struct_020a212c_2 {
    char unknown_0_[0x4];
    Vector3i unknown_4_;
    Vector3i unknown_10_;
    char unknown_1c_[0x54];
    Vector3i unknown_70_;
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char unknown_0_[0x21c];
#else
    char unknown1_0_[0x2a0];
#endif

    Struct_ov000_0217e870_2* unknown_2a0_;
#if defined(jpn)
    char unknown_220_[0x76e4];
#else
    char unknown_2a4_[0x7470];
#endif

    short unknown_7714_;
    char unknown_7716_[0x8];
    short unknown_771e_;
    short unknown_7720_;
    char unknown_7722_[0x2a];
    SafeAllocator unknown_774c_;
};

int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
int SetByte0xbeShiftPrev(Bytes02033b88* p, int val);
void GameState_SetCamera(GameState* gs, int value);
void ClearCombatantSlot_0200fd48(GameState* gs, int id);
void ApplyVec3Tail_0202e694(void* obj, int* vec);

extern "C" {
void* func_02057924();
void func_02057f00(void*, int);
Struct_020a212c_2* func_ov000_02160f14(Struct_ov000_02160da0*);
void func_ov000_0216d370(Struct_020a212c_2*, int, int, int);
}

// USA: func_ov026_021dbba8
extern "C" ARM void func_ov026_021dbba8(Struct_ov000_02160da0* arg0) {
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();

    func_02057f00(func_02057924(), 0x12);
    func_02057f00(func_02057924(), 0x1d);
    func_02057f00(func_02057924(), 0x1e);

    for (int var2 = 0; var2 < 4; var2++) {
        if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var2)) {
            GameObject* var3 = func_0200ff1c(var0, var2);
            if (var3 != NULL) {
                var3->obj3D_.RemoveAnimationPackageByID(3);
                func_02033b88((Struct_02010604*)var3, 0);
            }
        }
    }

    BattleCamera* saved = (BattleCamera*)gs->GetCamera();
    BattleCamera* cam = func_ov000_02160f14(self);
    Vector3i offset = saved->offset;
    func_ov000_0216d370(cam, 1, 1, 1);
    cam->target = saved->target;
    ApplyVec3Tail_0202e694(cam, &offset.x);
    cam->eye = saved->eye;
    GameState_SetCamera(gs, (int)func_ov000_02160f14(self));
    ClearCombatantSlot_0200fd48(gs, 0xcf);

    var1->RemoveTask(arg0->unknown_7714_);
    var1->RemoveTask(arg0->unknown_771e_);
    var1->RemoveTask(arg0->unknown_7720_);
    arg0->unknown_7714_ = arg0->unknown_771e_ = arg0->unknown_7720_ = -1;
    arg0->unknown_774c_.Reset();
}
