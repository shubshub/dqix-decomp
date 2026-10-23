#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"

struct Struct_0204b010;
struct Struct_02020cb8_3;

struct Struct_ov003_0217c7a0
{
    char unknown_0_[0x10];
    Vector3i unknown_10_;
};

struct Struct_02000c9c_89
{
    char unknown_0_[0x20];
};

struct Struct_ov003_0217c7a0_2
{
    SafeAllocator* unknown_0_;
    SafeAllocator unknown_4_;
    SafeAllocator unknown_18_;
    SafeAllocator unknown_2c_;
    Struct_02000c9c_89 unknown_40_;
    Struct_02000c9c_89 unknown_60_;
    char unknown_80_[0x130 - 0x80];
    int unknown_130_;
    int unknown_134_;
    int unknown_138_;
    char unknown_13c_[0x141 - 0x13c];
    signed char unknown_141_;
    char unknown_142_;
    unsigned char unknown_143_;
    Vector3i unknown_144_;
    int unknown_150_[3];
};

void Background_ClearMap(Obj0204b010* obj, void* buf);
extern "C" void Background_FlushMap(void* obj, int flag);
extern "C" void Background_TransferMap(void* obj, int flag);
void ResetRecordList0204afb4(List0204afb4* list);
void Set3DClearColor_020c5588(int a, int b, int c, int d, int e);
void ApplyVec3Tail_0202e694(void* obj, int* vec);
void SetField0x238True_020a2794(void* obj);
void ApplyVecFromField0x21e_020a2744(char* obj);
int SetPowCnt1Bit15_0217c2a0(int enable);
void ClearCombatantSlot_0200fd48(GameState* gs, int id);

// USA: func_ov003_0217c7a0
extern "C" ARM void func_ov003_0217c7a0(Struct_ov003_0217c7a0_2* arg0)
{
    GameResources* var0 = GetGameResources();
    if (arg0->unknown_141_ == 0)
    {
        SetBrightness(var0, -16, 0x3c);
        arg0->unknown_141_++;
    }
    else if (arg0->unknown_141_ == 1)
    {
        if (IsBrightnessTransitionActive(var0))
            return;

        GameState* var1 = GameState::GetInstance();
        void* var2;

        var2 = arg0->unknown_4_.GetSignedAllocator();
        if (var2)
        {
            arg0->unknown_4_.Destroy();
            arg0->unknown_0_->Free(var2);
        }
        var2 = arg0->unknown_18_.GetSignedAllocator();
        if (var2)
        {
            arg0->unknown_18_.Destroy();
            arg0->unknown_0_->Free(var2);
        }
        var2 = arg0->unknown_2c_.GetSignedAllocator();
        if (var2)
        {
            arg0->unknown_2c_.Destroy();
            arg0->unknown_0_->Free(var2);
        }

        BackgroundLoader* var3 = BackgroundLoader::GetInstance();
        var3->RemoveTask(arg0->unknown_130_);
        arg0->unknown_130_ = -1;
        var3->RemoveTask(arg0->unknown_134_);
        arg0->unknown_134_ = -1;
        var3->RemoveTask(arg0->unknown_138_);
        arg0->unknown_138_ = -1;

        Background_ClearMap((Obj0204b010*)&self->listA, 0);
        Background_FlushMap(&self->listA, 0);
        Background_TransferMap(&self->listA, 0);
        ResetRecordList0204afb4((List0204afb4*)&self->listA);
        Background_ClearMap((Obj0204b010*)&self->listB, 0);
        Background_FlushMap(&self->listB, 0);
        Background_TransferMap(&self->listB, 0);
        ResetRecordList0204afb4((List0204afb4*)&self->listB);

        func_020c5588(0, 0, 0x7fff, 0, 0);
        Struct_ov003_0217c7a0* var4 = (Struct_ov003_0217c7a0*)func_020100bc(var1);
        var4->unknown_10_ = arg0->unknown_144_;
        func_0202e694(var4, arg0->unknown_150_);
        func_020a2794(var4);
        func_020a2744((char*)var4);
        func_ov003_0217c2a0(0);
        func_0200fd48(var1, 0xa0);
        arg0->unknown_143_ = 1;
    }
}
