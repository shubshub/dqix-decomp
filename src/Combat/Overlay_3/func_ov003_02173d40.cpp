#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02173d40_216 = 0xd4 };
enum { Enum_ov003_02173d40_250 = 0x108 };
enum { Enum_ov003_02173d40_268 = 0x11a };
enum { Enum_ov003_02173d40_288 = 0x12c };
enum { Enum_ov003_02173d40_296 = 0x134 };
enum { Enum_ov003_02173d40_300 = 0x138 };
enum { kRegion130 = 0x13c };
enum { Enum_ov003_02173d40_388 = 0x190 };
enum { Enum_ov003_02173d40_448 = 0x1cc };
enum { Enum_ov003_02173d40_456 = 0x1d4 };
enum { Enum_ov003_02173d40_2494 = 0x7ee };
enum { Enum_ov003_02173d40_728 = 0x228 };
enum { Enum_ov003_02173d40_732 = 0x22c };
enum { Enum_ov003_02173d40_736 = 0x230 };
#else
enum { Enum_ov003_02173d40_216 = 0xd8 };
enum { Enum_ov003_02173d40_250 = 0xfa };
enum { Enum_ov003_02173d40_268 = 0x10c };
enum { Enum_ov003_02173d40_288 = 0x120 };
enum { Enum_ov003_02173d40_296 = 0x128 };
enum { Enum_ov003_02173d40_300 = 0x12c };
enum { kRegion130 = 0x130 };
enum { Enum_ov003_02173d40_388 = 0x184 };
enum { Enum_ov003_02173d40_448 = 0x1c0 };
enum { Enum_ov003_02173d40_456 = 0x1c8 };
enum { Enum_ov003_02173d40_2494 = 0x9be };
enum { Enum_ov003_02173d40_728 = 0x2d8 };
enum { Enum_ov003_02173d40_732 = 0x2dc };
enum { Enum_ov003_02173d40_736 = 0x2e0 };
#endif
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"

extern "C" int MessageSystem_GetInstance(void);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
struct Struct_0205a244;
extern "C" void func_0205a244(struct Struct_0205a244* target);
extern "C" void SpriteContext_Destroy(void* obj);
extern "C" void func_020a64e8(void* obj);
struct Struct_02074bd0;
extern "C" void func_02074bd0(struct Struct_02074bd0* obj);
struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4* obj);
struct Struct_020727d8 {
    void* entries;
    short capacity;
    short count;
};
extern "C" void func_020727ec(struct Struct_020727d8* list);
void CleanCacheRange(const void* addr, unsigned int size);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(const void* src, unsigned int offset, unsigned int size);
extern "C" void* GetMainBG1ScreenBase(void);
unsigned long long GetCurrentTimestamp(void);

struct Struct_ov003_02173d40 {
    unsigned char pad0[Enum_ov003_02173d40_216];
    unsigned char unknown_d8_[Enum_ov003_02173d40_250 - Enum_ov003_02173d40_216];
    unsigned char unknown_fa_[Enum_ov003_02173d40_268 - Enum_ov003_02173d40_250];
    unsigned char unknown_10c_[Enum_ov003_02173d40_288 - Enum_ov003_02173d40_268];
    int unknown_120_;
    int unknown_124_;
    unsigned char unknown_128_[Enum_ov003_02173d40_300 - Enum_ov003_02173d40_296];
    struct Struct_0205a244* unknown_12c_;
    unsigned char field_0x130[Enum_ov003_02173d40_388 - kRegion130];
    SafeAllocator allocators[3];
    unsigned char unknown_1c0_[Enum_ov003_02173d40_456 - Enum_ov003_02173d40_448];
    struct Struct_020727d8 lists[3];
};

// USA: func_ov003_02173d40
extern "C" ARM void func_ov003_02173d40(Struct_ov003_02173d40* scene) {
    GameState* gs = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    unsigned char* global = (unsigned char*)MessageSystem_GetInstance();
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x1000);
    global[0x1000 + Enum_ov003_02173d40_2494] = 0;
    func_0205a244(scene->unknown_12c_);
    SpriteContext_Destroy(scene->field_0x130);
    func_020a64e8(scene->unknown_d8_);
    *(volatile int*)0x4001010 = 0;
    func_02074bd0((struct Struct_02074bd0*)scene->unknown_fa_);
    func_02074bf4((struct Struct_02074bf4*)scene->unknown_10c_);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | (scene->unknown_120_ << 8);
    volatile unsigned int* var4 = (volatile unsigned int*)0x4001000;
    *var4 = (*var4 & ~0x1f00) | (scene->unknown_124_ << 8);

    ClearFlags00(resources, 4);
    ClearFlags04(resources, 0x81e);
    func_020727ec(&scene->lists[0]);
    func_020727ec(&scene->lists[1]);
    func_020727ec(&scene->lists[2]);
    scene->allocators[0].Destroy();
    scene->allocators[1].Destroy();
    scene->allocators[2].Destroy();

    unsigned char palette[0x20];
    memset(palette, 0, 0x20);
    CleanCacheRange(palette, 0x20);
    CleanInvalidateCacheRange(palette, 0x20);
    LoadToMainBG1CharacterData(palette, 0, 0x20);
    memset(GetMainBG1ScreenBase(), 0, 0x800);

    *(int*)(global + Enum_ov003_02173d40_728) = 0;
    *(int*)(global + Enum_ov003_02173d40_732) = 0;
    *(int*)(global + Enum_ov003_02173d40_736) = 0;
    gs->mainTimestamp_ = GetCurrentTimestamp();
    gs->altTimestamp_ = GetCurrentTimestamp();
}
