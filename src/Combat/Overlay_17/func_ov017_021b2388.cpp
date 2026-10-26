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


int GameState_GetFollowCamera(char* obj);
struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
int FieldTaskQueue_IsEmpty(void** obj);
extern "C" void func_020a0cc4(unsigned int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void HaltSystem(void);
struct GameResources;
void SetBrightness(GameResources*, int, int);
struct ResetObj020d7a5c;
struct ResetObj020d7a5c* TextQueue_GetInstance();
struct Obj020d7aa0;
void TextQueue_Reset(struct Obj020d7aa0* obj);

extern int g_mainAllocator;
extern char data_ov017_021d7a28;

struct Struct_ov017_021b2388 {
    unsigned int unknown_0_0_ : 4;
    unsigned int unknown_0_4_ : 1;
    unsigned int unknown_0_5_ : 27;
};

struct Struct_ov017_021b2388_2 {
    char unknown_0_[0x8];
    int unknown_8_;
    int unknown_c_;
    SafeAllocator unknown_10_;
    char unknown_24_[0x14];
    struct Struct_ov017_021b2388 unknown_38_;
    char unknown_3c_[0x2];
    unsigned char unknown_3e_;
    unsigned int unknown_40_;
    void* unknown_44_;
};

// USA: func_ov017_021b2388  (semantic: InitMenuAllocatorAndLoadData_021b2388)
extern "C" ARM int func_ov017_021b2388(struct Obj021b2388* ctx) {
    GameState* battle = (GameState*)GameState::GetInstance();
    int base = ((int)GetGameResources());
    unsigned char* fieldPtr;
    GameObject* combatant = battle->GetLeader();
    fieldPtr = (unsigned char*)GameState_GetFollowCamera((char*)battle);
    int loadedList = (int)BackgroundLoader::GetInstance();
    void** entry = *(void***)((char*)base + RegionOffset3700);
    unsigned int val40 = GetFlags04((GameResources*)base);
    ctx->field40 = val40;

    if (combatant) {
        GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
    }

    if (var2) {
        arg0->unknown_3e_ = (var2[0x244] & 2) != 0;
        func_020a28a0(var2, 2);
        func_020a27b8(var2);
        arg0->unknown_44_ = var2;
    }

    if (!FieldTaskQueue_IsEmpty(entry)) {
        return ctx->field8;
    }

    SetFlags00((GameResources*)var1, 0x10);
    func_020a0cc4(0x2f800);
    void* buf = AllocatorUnion_AllocateRounded((AllocatorUnion*)&g_mainAllocator, 0x2f800);
    if (!buf) {
        HaltSystem();
    }
    arg0->unknown_10_.CreateTypeA(var7, 0x2f800);

    char var8[0x50];
    sprintf(var8, &data_ov017_021d7a28, arg0->unknown_24_);
    arg0->unknown_c_ = ((BackgroundLoader*)(var4))->QueueLoadFile((const char*)((int)var8), (SafeAllocator*)((int)&arg0->unknown_10_));

    if (!arg0->unknown_38_.unknown_0_4_) {
        SetBrightness((GameResources*)var1, -16, 30);
    }

    TextQueue_Reset((struct Obj020d7aa0*)TextQueue_GetInstance());
    return 1;
}
