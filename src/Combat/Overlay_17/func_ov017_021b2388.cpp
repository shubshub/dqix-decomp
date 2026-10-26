#if defined(jpn)
enum { Enum_ov017_021b2388_14080 = 0x34f0 };
#else
enum { Enum_ov017_021b2388_14080 = 0x3700 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"


extern "C" int GameState_GetFollowCamera(char* obj);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void func_020a27b8(unsigned char* obj);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void HaltSystem(void);
struct GameResources;
void SetBrightness(GameResources*, int, int);
struct ResetObj020d7a5c;
extern "C" struct ResetObj020d7a5c* TextQueue_GetInstance();
struct Obj020d7aa0;
extern "C" void TextQueue_Reset(struct Obj020d7aa0* obj);

extern int g_mainAllocator;
extern char data_ov017_021d7a28;

struct Struct_ov017_021b2388 {
    unsigned int unknown_0_0_ : 4;
    unsigned int unknown_0_4_ : 1;
    unsigned int rest : 27;
};

struct Struct_ov017_021b2388_2 {
    char pad0[0x8];
    int field8;
    int fieldc;
    SafeAllocator allocator;
    char name[0x14];
    struct Struct_ov017_021b2388 field38;
    char pad2[0x2];
    unsigned char unknown_3e_;
    unsigned int field40;
    void* field44;
};

// USA: func_ov017_021b2388
extern "C" ARM int func_ov017_021b2388(struct Struct_ov017_021b2388_2* ctx) {
    GameState* battle = (GameState*)GameState::GetInstance();
    int base = ((int)GetGameResources());
    unsigned char* fieldPtr;
    GameObject* combatant = battle->GetLeader();
    fieldPtr = (unsigned char*)GameState_GetFollowCamera((char*)battle);
    int var4 = (int)BackgroundLoader::GetInstance();
    void** entry = *(void***)((char*)base + Enum_ov017_021b2388_14080);
    unsigned int var6 = GetFlags04((GameResources*)base);
    ctx->field40 = var6;

    if (combatant) {
        GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
    }

    if (fieldPtr) {
        ctx->unknown_3e_ = (fieldPtr[0x244] & 2) != 0;
        func_020a28a0(fieldPtr, 2);
        func_020a27b8(fieldPtr);
        ctx->field44 = fieldPtr;
    }

    if (!FieldTaskQueue_IsEmpty(entry)) {
        return ctx->field8;
    }

    SetFlags00((GameResources*)base, 0x10);
    func_020a0cc4(0x2f800);
    void* buf = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x2f800);
    if (!buf) {
        HaltSystem();
    }
    ctx->allocator.CreateTypeA(buf, 0x2f800);

    char tmp[0x50];
    sprintf(tmp, &data_ov017_021d7a28, ctx->name);
    ctx->fieldc = ((BackgroundLoader*)(var4))->QueueLoadFile((const char*)((int)tmp), (SafeAllocator*)((int)&ctx->allocator));

    if (!ctx->field38.unknown_0_4_) {
        SetBrightness((GameResources*)base, -16, 30);
    }

    TextQueue_Reset((struct Obj020d7aa0*)TextQueue_GetInstance());
    return 1;
}
