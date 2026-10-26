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

struct Camera0217bf78 {
    char unk_0[0x10];
    Vector3i position;
    char unk_1c[0x70 - 0x1c];
    Vector3i tail;
    char unknown_7c_[0x21e - 0x7c];
    short field_21e;
};

struct Struct_ov003_0217bf78_2 {
    char unk_0[0x80];
    char object[0x130 - 0x80];
    int unknown_130_;
    int unknown_134_;
    int unknown_138_;
    int unknown_13c_;
    unsigned char mode;
    signed char state;
    char unknown_142_[2];
    Vector3i unknown_144_;
    Vector3i cameraTail;
    char unknown_15c_[0x160 - 0x15c];
    int field_160;
};

extern "C" void FollowCamera_DisableFollow(void *obj);
extern "C" void func_020a27ac(void *obj);
extern "C" int Camera_GetOrbitYaw(void *obj);
extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char *obj);
extern "C" void func_ov003_0217c974(Struct_ov003_0217bf78_2 *self);
extern "C" void Camera_SetOrbitVector(void *obj, int *vec);
extern "C" void func_0200fd38(GameState *battleStruct, int id, GameObject *combatant);
extern "C" void func_ov003_0217ca84(Struct_ov003_0217bf78_2 *self, unsigned short arg1);
extern "C" void func_020a64e8(void);
extern "C" void Set3DClearColor(int a, int b, int c, int d, int e);
extern "C" int func_ov003_0217c2a0(int enable);
extern "C" void func_ov003_0217cb3c(Struct_ov003_0217bf78_2 *self, int arg1, int alternate);
extern "C" void SePlayer_LoadExtraArchiveB(void *sound, int a, int b);

extern char data_ov003_02180bef[];
extern char data_ov003_02180cf8[];
extern char data_ov003_02180d08[];
extern char data_ov003_02180c07[];
extern Vector3i data_ov003_02180ce0;
extern int data_ov003_02180cec[3];
extern int g_sePlayer;

// USA: func_ov003_0217bf78
extern "C" ARM void func_ov003_0217bf78(Struct_ov003_0217bf78_2 *self) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    GameResources *resources = GetGameResources();

    if (self->state == 0) {
        GameState *gs          = GameState::GetInstance();
        self->unknown_130_            = loader->QueueLoadFileInGP2(data_ov003_02180bef, data_ov003_02180cf8, 0);
        self->unknown_138_            = loader->QueueLoadFile(data_ov003_02180d08, 0);
        self->unknown_134_            = loader->QueueLoadFile(data_ov003_02180c07, 0);
        Camera0217bf78 *camera = (Camera0217bf78*)gs->GetCamera();
        FollowCamera_DisableFollow(camera);
        func_020a27ac(camera);
        camera->field_21e = Camera_GetOrbitYaw(camera);
        loader->RemoveTask(self->unknown_13c_);
        self->unknown_13c_ = -1;
        self->state++;
    } else if (self->state == 1) {
        if (!loader->GetTaskStatus(self->unknown_130_)) return;
        if (IsBrightnessTransitionActive(resources)) return;
        if (loader->GetDetailedTaskStatus(self->unknown_130_) != 2) {
            loader->RemoveTask(self->unknown_130_);
            self->mode  = 4;
            self->state = 0;
        }
        GameState *gs = GameState::GetInstance();
        MessageSystem_Reset((char *) MessageSystem_GetInstance());
        func_ov003_0217c974(self);
        Camera0217bf78 *camera = (Camera0217bf78*)gs->GetCamera();
        self->unknown_144_   = camera->position;
        self->cameraTail       = camera->tail;
        camera->position       = data_ov003_02180ce0;
        Camera_SetOrbitVector(camera, data_ov003_02180cec);
        func_0200fd38(gs, 0xa0, (GameObject *) self->object);
        func_ov003_0217ca84(self, 0);
        self->state++;
    } else if (self->state == 2) {
        if (!loader->GetTaskStatus(self->unknown_134_)) return;
        if (loader->GetDetailedTaskStatus(self->unknown_134_) != 2) {
            loader->RemoveTask(self->unknown_134_);
            self->mode  = 4;
            self->state = 0;
        }
        if (self->field_160 != 0) func_020a64e8();
        ((Object3D*)self->object)->MakeHidden();
        Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
        *(volatile unsigned int *) 0x4000000 = (*(volatile unsigned int *) 0x4000000 & ~0x1f00) | 0x100;
        func_ov003_0217c2a0(1);
        self->state++;
    } else if (self->state == 3) {
        if (!loader->GetTaskStatus(self->unknown_138_)) return;
        if (loader->GetDetailedTaskStatus(self->unknown_138_) != 2) {
            loader->RemoveTask(self->unknown_138_);
            self->mode  = 4;
            self->state = 0;
        }
        func_ov003_0217cb3c(self, 0, 0);
        unsigned short *screen = (unsigned short *) GetSubBG0ScreenBase();
        for (int i = 0; i < 0x800; i++)
            *screen++ = 0;
        *(volatile unsigned int *) 0x4001000 &= ~0x1f00;
        self->mode  = 2;
        self->state = 0;
        SePlayer_LoadExtraArchiveB(&g_sePlayer, 0x8b, 0x8b);
    }
}
