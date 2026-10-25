#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Matrix.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

struct GameObject;

struct Struct_ov003_0217bf78 {
    char unknown_0_[0x10];
    Vector3i unknown_10_;
    char unknown_1c_[0x70 - 0x1c];
    Vector3i unknown_70_;
    char unknown_7c_[0x21e - 0x7c];
    short unknown_21e_;
};

struct Struct_ov003_0217bf78_2 {
    char unknown_0_[0x80];
    char unknown_80_[0x130 - 0x80];
    int unknown_130_;
    int unknown_134_;
    int unknown_138_;
    int unknown_13c_;
    unsigned char unknown_140_;
    signed char unknown_141_;
    char unknown_142_[2];
    Vector3i unknown_144_;
    Vector3i unknown_150_;
    char unknown_15c_[0x160 - 0x15c];
    int unknown_160_;
};

void FollowCamera_DisableFollow(void *obj);
void SetField0x23cTrue_020a27ac(void *obj);
int GetField0x70_0202e7f0(void *obj);
int MessageSystem_GetInstance();
void MessageSystem_Reset(char *obj);
extern "C" void func_ov003_0217c974(Scene0217bf78 *self);
void ApplyVec3Tail_0202e694(void *obj, int *vec);
void RegisterCombatantSlot_0200fd38(GameState *battleStruct, int id, GameObject *combatant);
extern "C" void func_ov003_0217ca84(Scene0217bf78 *self, unsigned short fillValue);
void ResetSubBg1AndClearCache020a64e8(void);
void Set3DClearColor_020c5588(int a, int b, int c, int d, int e);
int SetPowCnt1Bit15_0217c2a0(int enable);
extern "C" void func_ov003_0217cb3c(Scene0217bf78 *self, int mainScreen, int alternate);
void SePlayer_LoadExtraArchiveB(void *sound, int a, int b);

extern char data_ov003_02180bef[];
extern char data_ov003_02180cf8[];
extern char data_ov003_02180d08[];
extern char data_ov003_02180c07[];
extern Vector3i data_ov003_02180ce0;
extern int data_ov003_02180cec[3];
extern int g_sePlayer;

// USA: func_ov003_0217bf78
extern "C" ARM void func_ov003_0217bf78(Struct_ov003_0217bf78_2 *arg0) {
    BackgroundLoader *var0 = BackgroundLoader::GetInstance();
    GameResources *var1 = GetGameResources();

    if (self->state == 0) {
        GameState *gs          = GameState::GetInstance();
        self->taskA            = loader->QueueLoadFileInGP2(data_ov003_02180bef, data_ov003_02180cf8, 0);
        self->taskC            = loader->QueueLoadFile(data_ov003_02180d08, 0);
        self->taskB            = loader->QueueLoadFile(data_ov003_02180c07, 0);
        Camera0217bf78 *camera = (Camera0217bf78*)gs->GetCamera();
        FollowCamera_DisableFollow(camera);
        SetField0x23cTrue_020a27ac(camera);
        camera->field_21e = GetField0x70_0202e7f0(camera);
        loader->RemoveTask(self->taskD);
        self->taskD = -1;
        self->state++;
    } else if (self->state == 1) {
        if (!loader->GetTaskStatus(self->taskA)) return;
        if (IsBrightnessTransitionActive(resources)) return;
        if (loader->GetDetailedTaskStatus(self->taskA) != 2) {
            loader->RemoveTask(self->taskA);
            self->mode  = 4;
            self->state = 0;
        }
        GameState *gs = GameState::GetInstance();
        MessageSystem_Reset((char *) MessageSystem_GetInstance());
        func_ov003_0217c974(self);
        Camera0217bf78 *camera = (Camera0217bf78*)gs->GetCamera();
        self->cameraPosition   = camera->position;
        self->cameraTail       = camera->tail;
        camera->position       = data_ov003_02180ce0;
        ApplyVec3Tail_0202e694(camera, data_ov003_02180cec);
        RegisterCombatantSlot_0200fd38(gs, 0xa0, (GameObject *) self->object);
        func_ov003_0217ca84(self, 0);
        self->state++;
    } else if (self->state == 2) {
        if (!loader->GetTaskStatus(self->taskB)) return;
        if (loader->GetDetailedTaskStatus(self->taskB) != 2) {
            loader->RemoveTask(self->taskB);
            self->mode  = 4;
            self->state = 0;
        }
        if (arg0->unknown_160_ != 0) func_020a64e8();
        ((Object3D*)arg0->unknown_80_)->MakeHidden();
        func_020c5588(0, 0x1f, 0x7fff, 0, 0);
        *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
        func_ov003_0217c2a0(1);
        arg0->unknown_141_++;
    } else if (arg0->unknown_141_ == 3) {
        if (!var0->GetTaskStatus(arg0->unknown_138_)) return;
        if (var0->GetDetailedTaskStatus(arg0->unknown_138_) != 2) {
            var0->RemoveTask(arg0->unknown_138_);
            arg0->unknown_140_  = 4;
            arg0->unknown_141_ = 0;
        }
        func_ov003_0217cb3c(arg0, 0, 0);
        unsigned short *var6 = (unsigned short *) GetSubBG0ScreenBase();
        for (int var7 = 0; var7 < 0x800; var7++)
            *var6++ = 0;
        *(volatile unsigned int *) 0x4001000 &= ~0x1f00;
        self->mode  = 2;
        self->state = 0;
        SePlayer_LoadExtraArchiveB(&g_sePlayer, 0x8b, 0x8b);
    }
}
