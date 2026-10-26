#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
#include <Filesystem/BackgroundLoader.h>
#include <NitroSDK/Memory/AllocatorUnion.h>
#include <NitroSDK/Memory/HMRFAllocator.h>
#include <std_library_functions.h>


struct Struct_0203cf58;
struct Struct_020e385c;
struct Struct_ov001_02154f24_3
{
    char unknown_0_[8];
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    char unknown_c_[7];
    unsigned char unknown_13_;
    char unknown_14_[4];
    unsigned short unknown_18_;
    char unknown_1a_[0x3e - 0x1a];
    char unknown_3e_[0x50 - 0x3e];
    unsigned short unknown_50_;
    char unknown_52_[0x74 - 0x52];
    int unknown_74_;
#if !defined(jpn)
    int unknown_78_;
#endif
    SafeAllocator unknown_7c_;
    unsigned int unknown_90_;
    char unknown_94_[8];
    unsigned char unknown_9c_;
    char unknown_9d_[0x110 - 0x9d];
    int unknown_110_;
};
struct Struct_ov001_02154f24
{
    unsigned short unknown_0_;
};
struct Struct_ov001_02154f24_2
{
    char unknown_0_[8];
    unsigned int unknown_8_;
    char unknown_c_[0x34 - 0xc];
};
void* GetGlobalPtr021075f4_0203cf4c();
extern "C" LoadArguments02154f24* Zone3D_GetInstance();
extern "C" void* LinkSession_GetInstance();
void EmptyStub02012de4(AllocatorUnion*);
extern "C" void func_020a0cc4(int);
extern "C" void func_0203e0a0(void*, int);
extern "C" void func_ov017_021a316c(GameResources*);
void InitWithExtendedRegion0203cf58(Struct_0203cf58*);
void AllocatorUnion_Free(AllocatorUnion*, void*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void __clear(void*, unsigned int);
extern "C" void* Scenario_GetInstance();
int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void*);
TagValueEntry020e385c* GetData02153660_020e3808();
void* FindEntryByTagAndValue(TagValueEntry020e385c*, int, int);
extern "C" int LinkSession_IsHostOrSolo(void*);
void ResetTaggedEntryAndNotifyOverlay020e3994(TagValueEntry020e385c*, int, int);
void RegisterTaggedEntryAndNotifyOverlay020e392c(TagValueEntry020e385c*, int, int);
int GameState_GetProtagonistIndex(GameState*);
void SetEntryBitUnlessMatching020e39d4(TagValueEntry020e385c*, int, int, int);
extern AllocatorUnion g_mainAllocator;
extern const char data_ov001_02164bef[];
extern const char data_ov001_02164c01[];
extern const char data_ov001_02164c13[];
#if defined(jpn)
extern const char data_ov001_021661c1[];
#else
extern const char data_ov001_02164c21[];
#endif
extern const char data_ov001_02164c26[];
extern const char data_ov001_02164c2d[];
extern const char data_ov001_02164c39[];

static inline SafeAllocator* inline_ov001_02154f24(GameResources* arg0, int arg1)
{
    return &arg0->allocator_array_38[arg1];
}

// USA: func_ov001_02154f24
extern "C" ARM int func_ov001_02154f24(Struct_ov001_02154f24_3* arg0)
{
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* list = GetGlobalPtr021075f4_0203cf4c();
    LoadArguments02154f24* arguments = Zone3D_GetInstance();
    void* other = LinkSession_GetInstance();
    if (!TestFlags00(resources, 0x1000))
    {
        if (!AlwaysTrue02094b4c(FontBankLoader_GetInstance()))
        {
            return arg0->unknown_a_;
        }
    }
    if (IsBrightnessTransitionActive(var1))
    {
        return arg0->unknown_a_;
    }
    EmptyStub02012de4(&g_mainAllocator);
    func_020a0cc4(0x40400);
    EmptyStub02012de4(&g_mainAllocator);
    if ((self->flags & 1) && !TestFlags00(resources, 0x1000))
    {
        func_0203e0a0(list, arguments->slot);
        func_ov017_021a316c(resources);
        InitWithExtendedRegion0203cf58((Struct_0203cf58*)GetGlobalPtr021075f4_0203cf4c());
        SafeAllocator* previousAllocator = GetAllocator02154f24(resources, 7);
        self->savedSize = previousAllocator->GetSize();
        void* oldAllocator = previousAllocator->GetSignedAllocator();
        previousAllocator->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, oldAllocator);
    }
    else if (arg0->unknown_50_ & 4)
    {
        func_0203e0a0(var3, var4->unknown_0_);
        func_ov017_021a316c(var1);
        func_0203cf58((Struct_0203cf58*)func_0203cf4c());
        var1->allocator_array_38[7].Reset();
    }
    unsigned int var8 = 0x40400;
    if (arg0->unknown_50_ & 8)
    {
        var8 -= 0xa000;
    }
    if (arg0->unknown_50_ & 1)
    {
        var8 += arg0->unknown_90_;
    }
    if (!TestFlags00(var1, 0x1000))
    {
        void* memory = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
        self->allocator.CreateTypeA(memory, size);
        self->allocator.Reset();
    }
    else
    {
        ((HMRFAllocator*)arg0->unknown_7c_.pSignedAlloc)->Free(1);
    }
    EmptyStub02012de4(&g_mainAllocator);
    char filename[80];
    if (self->alternatePath)
    {
        sprintf(var10, data_ov001_02164bef, arg0->unknown_3e_);
    }
    else if (arg0->unknown_13_)
    {
        sprintf(var10, data_ov001_02164c01, arg0->unknown_3e_);
    }
    else
    {
        sprintf(var10, data_ov001_02164c13, arg0->unknown_3e_);
    }
    int var11 = strlen(var10) - 4;
#if defined(jpn)
    memcpy(var10 + var11, data_ov001_021661c1, 4);
    var2->AddFence();
    arg0->unknown_74_ = var2->QueueLoadFile(var10, &arg0->unknown_7c_);
#else
    memcpy(var10 + var11, data_ov001_02164c21, 4);
    char var12[16];
    __clear(var12, 16);
    memcpy(var12, arg0->unknown_3e_, strlen(arg0->unknown_3e_) - 4);
    char var13[16];
    sprintf(var13, data_ov001_02164c26, var12);
    char var14[32];
    sprintf(var14, data_ov001_02164c2d, var12);
    var2->AddFence();
    arg0->unknown_74_ = var2->QueueLoadFileInGP2(var10, var13, &arg0->unknown_7c_);
    arg0->unknown_78_ = var2->QueueLoadFileInGP2(var10, var14, &arg0->unknown_7c_);
#endif
    if (arg0->unknown_50_ & 0x200)
    {
        arg0->unknown_110_ = var2->QueueLoadFile(data_ov001_02164c39, &arg0->unknown_7c_);
    }
    void* context = Scenario_GetInstance();
    LookupRecord02154f24 record;
    record.index = self->lookupId;
    if (Scenario_RunTrigger(context, 10, &record))
    {
        EventQuery_RunQueuedCommands(&record);
    }
    TagValueEntry020e385c* table = GetData02153660_020e3808();
    void* found = FindEntryByTagAndValue(table, 1, 0x71e8);
    if (LinkSession_IsHostOrSolo(other) && !found && !FindEntryByTagAndValue(table, 1, self->tag))
    {
        func_020e3994(var17, 1, -1);
        func_020e392c(var17, 1, arg0->unknown_18_);
    }
    SetEntryBitUnlessMatching020e39d4(table, GameState_GetProtagonistIndex(game), 1, self->tag);
    return 2;
}
