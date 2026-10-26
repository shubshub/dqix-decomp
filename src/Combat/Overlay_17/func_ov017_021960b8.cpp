#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021960b8_2456 = 0x868, Enum_ov017_021960b8_6603 = 0x17fc, Enum_ov017_021960b8_13912 = 0x3448, Enum_ov017_021960b8_14076 = 0x34ec, Enum_ov017_021960b8_17192 = 0x4108, kAtmosphericOffset = 0x114 };
#else
enum { Enum_ov017_021960b8_2456 = 0x998, Enum_ov017_021960b8_6603 = 0x19cb, Enum_ov017_021960b8_13912 = 0x3658, Enum_ov017_021960b8_14076 = 0x36fc, Enum_ov017_021960b8_17192 = 0x4328, kAtmosphericOffset = 0xf4 };
#endif

#include "GameState/GameState.h"
#include "Graphics/AtmosphericEffect.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"
#include "Input/Input.h"

struct HeadNode02046b24;
struct Obj020444e0;

struct Struct_020707c8 {
    unsigned char field0;
};

struct Global020421a0 {
    char pad0[Enum_ov017_021960b8_2456];
    int unknown_998_;
    char pad1[Enum_ov017_021960b8_6603 - (Enum_ov017_021960b8_2456 + 4)];
    unsigned char unknown_19cb_;
};

struct Struct_ov017_021960b8 {
    unsigned int flags[2];
    char pad8[Enum_ov017_021960b8_13912 - 0x8];
    unsigned char unknown_3658_;
    char unknown_3659_[Enum_ov017_021960b8_14076 - (Enum_ov017_021960b8_13912 + 1)];
    HeadNode02046b24** nodeList;
    char unknown_3700_[Enum_ov017_021960b8_17192 - (Enum_ov017_021960b8_14076 + 4)];
    unsigned char* unknown_4328_;
};

extern "C" void* func_020704fc(void);
extern "C" void __clear(void* ptr, int size);
extern "C" void G3X_Reset();
extern "C" void G3X_ResetMtxStack();
extern "C" void G3i_LookAt_(int, int, int, int, void*);
extern "C" void G3i_OrthoW_(int, int, int, int, int, int, int, int, void*);
extern "C" void func_ov017_021a3b30(int);
extern "C" void func_020707c8(Struct_020707c8*);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void func_020444e0(Obj020444e0*);
extern "C" void func_ov017_0219ad84(Struct_ov017_021960b8*);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" void func_0205337c(GameObject*);
extern "C" unsigned char GameObject_IsControlEnabled(void*);
extern "C" int GameObject_IsClimbingLadder(char*);
extern "C" void func_02096824(unsigned char*);
extern "C" int* func_020936f8();
extern "C" void func_02093f68(char*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021959ec(void*);
extern "C" Global020421a0* MessageSystem_GetInstance();

extern Vector3fix data_ov017_021d6408;
extern Vector3fix data_ov017_021d6414;
extern int data_ov017_021d8340;
extern int data_ov017_021d8344;
extern int data_ov017_021d834c;
extern int data_ov017_021d8348;
extern int data_ov017_021d8350;

// USA: func_ov017_021960b8
extern "C" ARM void func_ov017_021960b8(Struct_ov017_021960b8* self) {
    GameState* game = GameState::GetInstance();
    Global020421a0* global = MessageSystem_GetInstance();
    Struct_020707c8* timer = (Struct_020707c8*)func_020704fc();
    GameObject* leader = game->GetLeader();
    game->GetTickCount();

    Vector3fix target = data_ov017_021d6408;
    Vector3fix eye;
    __clear(&eye, sizeof(eye));
    Vector3fix up = data_ov017_021d6414;

    G3X_Reset();
    G3X_ResetMtxStack();
    *(volatile unsigned int*)0x04000440 = 0;
    G3i_LookAt_((int)&eye, (int)&up, (int)&target, 1, NULL);
    G3i_OrthoW_(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    *(volatile unsigned int*)0x04000440 = 2;
    func_ov017_021a3b30((int)self->nodeList);

    if (timer->field0 != 0) {
        func_020707c8(timer);
    }

    if (FieldTaskQueue_GetCurrentKind(self->nodeList) != 2 &&
        FieldTaskQueue_GetCurrentKind(self->nodeList) != 3 &&
        FieldTaskQueue_GetCurrentKind(self->nodeList) != 10) {
        if ((global->unknown_998_ != 0 || global->unknown_19cb_ != 0) &&
            TestFlags04((GameResources*)(self->flags), 0x8000) == 0) {
            func_020444e0((Obj020444e0*)global);
        }
        func_ov017_0219ad84(self);
        if (TestFlags04((GameResources*)(self->flags), 4) == 0) {
            for (int i = 0; i < 4; i++) {
                GameObject* combatant = func_0200ff1c(game, i);
                if (combatant != NULL && combatant->obj3D_.GetFlag(1) == 0) {
                    func_0205337c(combatant);
                }
            }
        }
    }

    if (TestFlags04((GameResources*)(self->flags), 0x800) == 0) {
        LightingManager::GetInstance()->DrawBackgroundGradient();
    }

    if (TestFlags04((GameResources*)(self->flags), 0x80) == 0 && self->unknown_3658_ == 0 && leader != NULL &&
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
        func_02096824(self->unknown_4328_);
    }

    func_02093f68((char*)func_020936f8());
    if (((AtmosphericEffectSet*)((char*)Zone3D_GetInstance() + kAtmosphericOffset))->Draw()) {
        func_ov017_021959ec(self);
    }
}
