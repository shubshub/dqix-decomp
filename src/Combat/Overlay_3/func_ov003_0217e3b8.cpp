#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Graphics.h"
#include "Resource/Brightness.h"

struct Struct_02018300_3;

struct Struct_ov003_0217e3b8
{
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    int unknown_8_;
    SafeAllocator unknown_c_;
    void* unknown_20_;
};

char* GetFieldIfFlag4_020100f8(char* gameState);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
void SetByteField0x253_020397c0(void* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* camera, unsigned char flags);
void ClearFlagBits_020a28b0(unsigned char* camera, int flags);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_020a1df8(int arg0);
extern "C" void func_ov003_021681c8(void* arg0);
extern "C" void func_ov003_021680d4(void* arg0, SafeAllocator* arg1);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov003_021685cc(void* arg0);
extern "C" int func_ov003_02168438(void* arg0, int arg1);
extern "C" void func_ov003_02168324(void* arg0);
extern "C" int func_ov003_021685c4(void* arg0);
extern "C" void func_ov003_0217e36c(Struct_ov003_0217e3b8* arg0);

extern AllocatorUnion data_02114e20;

// USA: func_ov003_0217e3b8
extern "C" ARM void func_ov003_0217e3b8(Struct_ov003_0217e3b8* arg0)
{
    GameState* gameState = GameState::GetInstance();
    unsigned int* resources = (unsigned int*)gameState->GetResources();
    GameObject* object = gameState->GetUnknownGameObject();
    char* camera = GetFieldIfFlag4_020100f8((char*)gameState);
    SetFlags04((GameResources*)resources, 0xc0);
    CancelPendingAction020397cc((Obj020397cc*)object, 1);
    SetFlagsAt0x244_020a28a0((unsigned char*)camera, 3);
    int ticks = gameState->GetTickCount();
    if (ticks < 0)
        ticks = 1;

    if (arg0->unknown_8_ == 0)
    {
        func_020a0cc4(R(0x16e14,0x16e18));
        void* var5 = func_02012d88(&data_02114e20, R(0x16e14,0x16e18));
        if (var5 == 0)
        {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_c_.CreateTypeA(var5, R(0x16e14,0x16e18));
        arg0->unknown_c_.Reset();
        arg0->unknown_20_ = arg0->unknown_c_.Allocate(R(0x5d4,0x5d8));
        if (arg0->unknown_20_ == 0)
        {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        func_020a1df8(3);
        func_ov003_021681c8(arg0->unknown_20_);
        func_ov003_021680d4(arg0->unknown_20_, &arg0->unknown_c_);
        arg0->unknown_8_++;
    }
    else if (arg0->unknown_8_ == 1)
    {
        if (func_ov017_021959b4())
            func_ov003_021685cc(arg0->unknown_20_);
        if (func_ov003_02168438(arg0->unknown_20_, var4))
            arg0->unknown_8_++;
    }
    else if (arg0->unknown_8_ == 2)
    {
        func_ov003_02168324(arg0->unknown_20_);
        arg0->unknown_8_++;
    }
    else if (arg0->unknown_8_ == 3)
    {
        DISPCNT = (DISPCNT & ~0x1f00) | (func_ov003_021685c4(arg0->unknown_20_) << 8);
        func_ov003_0217e36c(arg0);
        ClearFlags04((GameResources*)var1, 0xc0);
        func_020397c0(var2);
        func_020a28b0((unsigned char*)var3, 3);
        func_020a0c0c();
        arg0->unknown_1_ = 1;
    }
}
