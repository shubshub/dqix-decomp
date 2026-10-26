#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"

struct BackgroundGraphics;

struct Camera0217c7a0
{
    char unk_0[0x10];
    Vector3i position;
};

struct Struct_02000c9c_89
{
    char data[0x20];
};

struct Struct_ov003_0217c7a0_2
{
    SafeAllocator* allocator;
    SafeAllocator allocA;
    SafeAllocator unknown_18_;
    SafeAllocator unknown_2c_;
    Struct_02000c9c_89 listA;
    Struct_02000c9c_89 listB;
    char unknown_80_[0x130 - 0x80];
    int unknown_130_;
    int unknown_134_;
    int unknown_138_;
    char unknown_13c_[0x141 - 0x13c];
    signed char state;
    char unknown_142_;
    unsigned char unknown_143_;
    Vector3i unknown_144_;
    int cameraTail[3];
};

extern "C" void Background_ClearMap(BackgroundGraphics* obj, void* buf);
extern "C" void Background_FlushMap(void* obj, int flag);
extern "C" void Background_TransferMap(void* obj, int flag);
extern "C" void Background_Destroy(BackgroundGraphics* list);
extern "C" void Set3DClearColor(int a, int b, int c, int d, int e);
extern "C" void Camera_SetOrbitVector(void* obj, int* vec);
extern "C" void FollowCamera_EnableFollow(void* obj);
extern "C" void func_020a2744(char* obj);
extern "C" int func_ov003_0217c2a0(int enable);
extern "C" void func_0200fd48(GameState* gs, int id);

// USA: func_ov003_0217c7a0
extern "C" ARM void func_ov003_0217c7a0(Struct_ov003_0217c7a0_2* self)
{
    GameResources* resources = GetGameResources();
    if (self->state == 0)
    {
        SetBrightness(resources, -16, 0x3c);
        self->state++;
    }
    else if (self->state == 1)
    {
        if (IsBrightnessTransitionActive(resources))
            return;

        GameState* gs = GameState::GetInstance();
        void* block;

        block = self->allocA.GetSignedAllocator();
        if (block)
        {
            self->allocA.Destroy();
            self->allocator->Free(block);
        }
        block = self->unknown_18_.GetSignedAllocator();
        if (block)
        {
            self->unknown_18_.Destroy();
            self->allocator->Free(block);
        }
        block = self->unknown_2c_.GetSignedAllocator();
        if (block)
        {
            self->unknown_2c_.Destroy();
            self->allocator->Free(block);
        }

        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->RemoveTask(self->unknown_130_);
        self->unknown_130_ = -1;
        loader->RemoveTask(self->unknown_134_);
        self->unknown_134_ = -1;
        loader->RemoveTask(self->unknown_138_);
        self->unknown_138_ = -1;

        Background_ClearMap((BackgroundGraphics*)&self->listA, 0);
        Background_FlushMap(&self->listA, 0);
        Background_TransferMap(&self->listA, 0);
        Background_Destroy((BackgroundGraphics*)&self->listA);
        Background_ClearMap((BackgroundGraphics*)&self->listB, 0);
        Background_FlushMap(&self->listB, 0);
        Background_TransferMap(&self->listB, 0);
        Background_Destroy((BackgroundGraphics*)&self->listB);

        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        Camera0217c7a0* camera = (Camera0217c7a0*)gs->GetCamera();
        camera->position = self->unknown_144_;
        Camera_SetOrbitVector(camera, self->cameraTail);
        FollowCamera_EnableFollow(camera);
        func_020a2744((char*)camera);
        func_ov003_0217c2a0(0);
        func_0200fd48(gs, 0xa0);
        self->unknown_143_ = 1;
    }
}
