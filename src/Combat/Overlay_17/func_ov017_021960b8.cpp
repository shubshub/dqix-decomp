#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021960b8_2456 = 0x868, Enum_ov017_021960b8_6603 = 0x17fc, Enum_ov017_021960b8_13912 = 0x3448, Enum_ov017_021960b8_14076 = 0x34ec, Enum_ov017_021960b8_17192 = 0x4108, Enum_ov017_021960b8_244 = 0x114 };
#else
enum { Enum_ov017_021960b8_2456 = 0x998, Enum_ov017_021960b8_6603 = 0x19cb, Enum_ov017_021960b8_13912 = 0x3658, Enum_ov017_021960b8_14076 = 0x36fc, Enum_ov017_021960b8_17192 = 0x4328, Enum_ov017_021960b8_244 = 0xf4 };
#endif

#include "GameState/GameState.h"
#include "Graphics/AtmosphericEffect.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"
#include "Input/Input.h"

struct Struct_02015438;
struct Struct_020444e0;

struct Struct_020707c8 {
    unsigned char unknown_0_;
};

struct Struct_ov003_02174114 {
    char unknown_0_[Enum_ov017_021960b8_2456];
    int unknown_998_;
    char unknown_99c_[Enum_ov017_021960b8_6603 - (Enum_ov017_021960b8_2456 + 4)];
    unsigned char unknown_19cb_;
};

struct Struct_ov017_021960b8 {
    unsigned int unknown_0_[2];
    char unknown_8_[Enum_ov017_021960b8_13912 - 0x8];
    unsigned char unknown_3658_;
    char unknown_3659_[Enum_ov017_021960b8_14076 - (Enum_ov017_021960b8_13912 + 1)];
    Struct_02015438** unknown_36fc_;
    char unknown_3700_[Enum_ov017_021960b8_17192 - (Enum_ov017_021960b8_14076 + 4)];
    unsigned char* unknown_4328_;
};

extern "C" void* func_020704fc(void);
extern "C" void __clear(void* ptr, int size);
void G3X_Reset();
extern "C" void G3X_ResetMtxStack();
void G3i_LookAt_(int, int, int, int, void*);
void G3i_OrthoW_(int, int, int, int, int, int, int, int, void*);
void ForwardObjAndField0_021a3b30(int);
void UpdateInterpTimer020707c8(Timer020707c8*);
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
void ReleaseField0x38IfValid020444e0(Obj020444e0*);
extern "C" void func_ov017_0219ad84(Battle021960b8*);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
extern "C" void func_0205337c(GameObject*);
unsigned char GameObject_IsControlEnabled(void*);
int GameObject_IsClimbingLadder(char*);
void MaybeDispatchPendingAction02096824(unsigned char*);
int* GetGlobal02109030_020936f8();
void UpdateChannelStateIfEligible02093f68(char*);
extern "C" void* Zone3D_GetInstance(void);
void MaybeUpdateOrDispatchEntry_021959ec(void*);
Global020421a0* MessageSystem_GetInstance();

extern Vector3fix data_ov017_021d6408;
extern Vector3fix data_ov017_021d6414;
extern int data_ov017_021d8340;
extern int data_ov017_021d8344;
extern int data_ov017_021d834c;
extern int data_ov017_021d8348;
extern int data_ov017_021d8350;

// USA: func_ov017_021960b8
extern "C" ARM void func_ov017_021960b8(Battle021960b8* self) {
    GameState* game = GameState::GetInstance();
    Global020421a0* global = MessageSystem_GetInstance();
    Timer020707c8* timer = (Timer020707c8*)func_020704fc();
    GameObject* leader = game->GetLeader();
    game->GetTickCount();

    Vector3fix var4 = data_ov017_021d6408;
    Vector3fix var5;
    __clear(&var5, sizeof(var5));
    Vector3fix var6 = data_ov017_021d6414;

    G3X_Reset();
    G3X_ResetMtxStack();
    *(volatile unsigned int*)0x04000440 = 0;
    G3i_LookAt_((int)&eye, (int)&up, (int)&target, 1, NULL);
    G3i_OrthoW_(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    *(volatile unsigned int*)0x04000440 = 2;
    func_ov017_021a3b30((int)arg0->unknown_36fc_);

    if (var2->unknown_0_ != 0) {
        func_020707c8(var2);
    }

    if (FieldTaskQueue_GetCurrentKind(self->nodeList) != 2 &&
        FieldTaskQueue_GetCurrentKind(self->nodeList) != 3 &&
        FieldTaskQueue_GetCurrentKind(self->nodeList) != 10) {
        if ((global->field998 != 0 || global->field19cb != 0) &&
            TestFlags04((GameResources*)(self->flags), 0x8000) == 0) {
            ReleaseField0x38IfValid020444e0((Obj020444e0*)global);
        }
        func_ov017_0219ad84(arg0);
        if (TestFlags04((GameResources*)(arg0->unknown_0_), 4) == 0) {
            for (int var7 = 0; var7 < 4; var7++) {
                GameObject* var8 = func_0200ff1c(var0, var7);
                if (var8 != NULL && var8->obj3D_.GetFlag(1) == 0) {
                    func_0205337c(var8);
                }
            }
        }
    }

    if (TestFlags04((GameResources*)(arg0->unknown_0_), 0x800) == 0) {
        LightingManager::GetInstance()->DrawBackgroundGradient();
    }

    if (TestFlags04((GameResources*)(self->flags), 0x80) == 0 && self->field3658 == 0 && leader != NULL &&
        (GameObject_IsControlEnabled(leader) != 0 || GameObject_IsClimbingLadder((char*)leader) != 0)) {
        if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
            if (data_ov017_021d8340 == 0) {
                data_ov017_021d8340 = 1;
                g_touchInput.GetTouchPoint(&data_ov017_021d8344, &data_ov017_021d834c);
            }
            g_touchInput.GetTouchPoint(&data_ov017_021d8348, &data_ov017_021d8350);
        } else {
            data_ov017_021d8340 = 0;
        }
        func_02096824(arg0->unknown_4328_);
    }

    UpdateChannelStateIfEligible02093f68((char*)GetGlobal02109030_020936f8());
    if (((AtmosphericEffectSet*)((char*)Zone3D_GetInstance() + kAtmosphericOffset))->Draw()) {
        MaybeUpdateOrDispatchEntry_021959ec(self);
    }
}
