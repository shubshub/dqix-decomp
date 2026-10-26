#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Matrix.h"

struct PartyState;
struct Bytes02033b88;

struct BattleCamera {
    char pad0[0x4];
    Vector3i eye;
    Vector3i target;
    char unknown_1c_[0x54];
    Vector3i offset;
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char pad0[0x21c];
#else
    char pad0[0x2a0];
#endif

    PartyState* party;
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

extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" int GameObject_ForceMotionState(Bytes02033b88* p, int val);
extern "C" void GameState_SetCamera(GameState* gs, int value);
extern "C" void func_0200fd48(GameState* gs, int id);
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);

extern "C" {
void* func_02057924();
void func_02057f00(void*, int);
BattleCamera* func_ov000_02160f14(Struct_ov000_02160da0*);
void func_ov000_0216d370(BattleCamera*, int, int, int);
}

// USA: func_ov026_021dbba8
extern "C" ARM void func_ov026_021dbba8(Struct_ov000_02160da0* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    func_02057f00(func_02057924(), 0x12);
    func_02057f00(func_02057924(), 0x1d);
    func_02057f00(func_02057924(), 0x1e);

    for (int i = 0; i < 4; i++) {
        if (func_020a35e0((unsigned char*)self->party, i)) {
            GameObject* member = func_0200ff1c(gs, i);
            if (member != NULL) {
                member->obj3D_.RemoveAnimationPackageByID(3);
                GameObject_ForceMotionState((Bytes02033b88*)member, 0);
            }
        }
    }

    BattleCamera* saved = (BattleCamera*)gs->GetCamera();
    BattleCamera* cam = func_ov000_02160f14(self);
    Vector3i offset = saved->offset;
    func_ov000_0216d370(cam, 1, 1, 1);
    cam->target = saved->target;
    Camera_SetOrbitVector(cam, &offset.x);
    cam->eye = saved->eye;
    GameState_SetCamera(gs, (int)func_ov000_02160f14(self));
    func_0200fd48(gs, 0xcf);

    loader->RemoveTask(self->unknown_7714_);
    loader->RemoveTask(self->unknown_771e_);
    loader->RemoveTask(self->unknown_7720_);
    self->unknown_7714_ = self->unknown_771e_ = self->unknown_7720_ = -1;
    self->unknown_774c_.Reset();
}
