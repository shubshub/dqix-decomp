#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <GameState/GameState.h>
#include <Resource/Brightness.h>
#include <Filesystem/BackgroundLoader.h>
#include <NitroSDK/Memory/AllocatorUnion.h>
#include <NitroSDK/Memory/HMRFAllocator.h>
#include <std_library_functions.h>


struct Struct_0203cf58;
struct TagValueEntry020e385c;
struct Struct_ov001_02154f24_3
{
    char unknown_0_[8];
    unsigned short lookupId;
    unsigned short state;
    char unknown_c_[7];
    unsigned char unknown_13_;
    char unknown_14_[4];
    unsigned short tag;
    char unknown_1a_[0x3e - 0x1a];
    char name[0x50 - 0x3e];
    unsigned short flags;
    char unknown_52_[0x74 - 0x52];
    int unknown_74_;
#if !defined(jpn)
    int unknown_78_;
#endif
    SafeAllocator allocator;
    unsigned int unknown_90_;
    char unknown_94_[8];
    unsigned char unknown_9c_;
    char unknown_9d_[0x110 - 0x9d];
    int unknown_110_;
};
struct LoadArguments02154f24
{
    unsigned short slot;
};
struct Struct_ov001_02154f24_2
{
    char unknown_0_[8];
    unsigned int index;
    char unknown_c_[0x34 - 0xc];
};
extern "C" void* func_0203cf4c();
extern "C" LoadArguments02154f24* Zone3D_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" void func_02012de4(AllocatorUnion*);
extern "C" void func_020a0cc4(int);
extern "C" void func_0203e0a0(void*, int);
extern "C" void func_ov017_021a316c(GameResources*);
extern "C" void func_0203cf58(Struct_0203cf58*);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void __clear(void*, unsigned int);
extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void*);
extern "C" TagValueEntry020e385c* func_020e3808();
extern "C" void* func_020e385c(TagValueEntry020e385c*, int, int);
extern "C" int LinkSession_IsHostOrSolo(void*);
extern "C" void func_020e3994(TagValueEntry020e385c*, int, int);
extern "C" void func_020e392c(TagValueEntry020e385c*, int, int);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_020e39d4(TagValueEntry020e385c*, int, int, int);
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

static inline SafeAllocator* inline_ov001_02154f24(GameResources* resources, int index)
{
    return &resources->allocator_array_38[index];
}

// USA: func_ov001_02154f24
extern "C" ARM int func_ov001_02154f24(Struct_ov001_02154f24_3* self)
{
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* list = func_0203cf4c();
    LoadArguments02154f24* arguments = Zone3D_GetInstance();
    void* other = LinkSession_GetInstance();
    if (!TestFlags00(resources, 0x1000))
    {
        if (!func_02094b4c(FontBankLoader_GetInstance()))
        {
            return self->state;
        }
    }
    if (IsBrightnessTransitionActive(resources))
    {
        return self->state;
    }
    func_02012de4(&g_mainAllocator);
    func_020a0cc4(0x40400);
    func_02012de4(&g_mainAllocator);
    if ((self->flags & 1) && !TestFlags00(resources, 0x1000))
    {
        func_0203e0a0(list, arguments->slot);
        func_ov017_021a316c(resources);
        func_0203cf58((Struct_0203cf58*)func_0203cf4c());
        SafeAllocator* var6 = inline_ov001_02154f24(resources, 7);
        self->unknown_90_ = var6->GetSize();
        void* oldAllocator = var6->GetSignedAllocator();
        var6->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, oldAllocator);
    }
    else if (self->flags & 4)
    {
        func_0203e0a0(list, arguments->slot);
        func_ov017_021a316c(resources);
        func_0203cf58((Struct_0203cf58*)func_0203cf4c());
        resources->allocator_array_38[7].Reset();
    }
    unsigned int size = 0x40400;
    if (self->flags & 8)
    {
        size -= 0xa000;
    }
    if (self->flags & 1)
    {
        size += self->unknown_90_;
    }
    if (!TestFlags00(resources, 0x1000))
    {
        void* memory = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
        self->allocator.CreateTypeA(memory, size);
        self->allocator.Reset();
    }
    else
    {
        ((HMRFAllocator*)self->allocator.pSignedAlloc)->Free(1);
    }
    func_02012de4(&g_mainAllocator);
    char filename[80];
    if (self->unknown_9c_)
    {
        sprintf(filename, data_ov001_02164bef, self->name);
    }
    else if (self->unknown_13_)
    {
        sprintf(filename, data_ov001_02164c01, self->name);
    }
    else
    {
        sprintf(filename, data_ov001_02164c13, self->name);
    }
    int length = strlen(filename) - 4;
#if defined(jpn)
    memcpy(filename + length, data_ov001_021661c1, 4);
    loader->AddFence();
    self->unknown_74_ = loader->QueueLoadFile(filename, &self->allocator);
#else
    memcpy(filename + length, data_ov001_02164c21, 4);
    char var12[16];
    __clear(var12, 16);
    memcpy(var12, self->name, strlen(self->name) - 4);
    char var13[16];
    sprintf(var13, data_ov001_02164c26, var12);
    char var14[32];
    sprintf(var14, data_ov001_02164c2d, var12);
    loader->AddFence();
    self->unknown_74_ = loader->QueueLoadFileInGP2(filename, var13, &self->allocator);
    self->unknown_78_ = loader->QueueLoadFileInGP2(filename, var14, &self->allocator);
#endif
    if (self->flags & 0x200)
    {
        self->unknown_110_ = loader->QueueLoadFile(data_ov001_02164c39, &self->allocator);
    }
    void* context = Scenario_GetInstance();
    Struct_ov001_02154f24_2 record;
    record.index = self->lookupId;
    if (Scenario_RunTrigger(context, 10, &record))
    {
        EventQuery_RunQueuedCommands(&record);
    }
    TagValueEntry020e385c* table = func_020e3808();
    void* found = func_020e385c(table, 1, 0x71e8);
    if (LinkSession_IsHostOrSolo(other) && !found && !func_020e385c(table, 1, self->tag))
    {
        func_020e3994(table, 1, -1);
        func_020e392c(table, 1, self->tag);
    }
    func_020e39d4(table, GameState_GetProtagonistIndex(game), 1, self->tag);
    return 2;
}
