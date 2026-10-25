#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Interrupts.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define data_ov031_0224c90c data_ov031_0224d50c
#define data_ov031_0224c920 data_ov031_0224d520
#endif

#define REG_IME (*(volatile unsigned short*)0x04000208)
struct Struct_02018300_3;
extern SafeAllocator data_ov031_02291e3c;
extern char g_fileLoadBuffer;
extern char data_ov031_0224c90c[];
extern char data_ov031_0224c920[];
extern "C" void* func_0202ae18();
int CheckField0NonZero_0202b7d8(int*);
void GameObject_DisableControl(Obj020397cc*, int);
unsigned int* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int*, unsigned int);
void MarkContextStackTopUnknownSubspace(ProcessorContext*, unsigned int);

enum Enum_ov031_02243850 {
#if defined(jpn)
    Enum_ov031_02243850_183616 = 0x2d740,
#else
    Enum_ov031_02243850_183616 = 0x2cd40,
#endif
    Enum_ov031_02243850_179200 = 0x2bc00
};

// USA: func_ov031_02243850
extern "C" ARM int func_ov031_02243850(void* state) {
    GameState* game = GameState::GetInstance();
    int* field = (int*)func_0202ae18();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int result = 1;
    if (CheckField0NonZero_0202b7d8(field)) return -1;
    GameObject* object = game->GetUnknownGameObject();
    if (object) GameObject_DisableControl((Obj020397cc*)object, 1);
    AllocationLength02243850 length = ArenaLength02243850;
    SafeAllocator* external = *(SafeAllocator**)((char*)state + 0x28);
    if (!external) return -1;
    void* arena = external->Allocate(length);
    if (!arena) return -1;
    SafeAllocator* allocator = (SafeAllocator*)state;
    allocator->CreateTypeB(arena, length, 4);
    allocator->Reset();
    length = WorkLength02243850;
    void* buffer = allocator->Allocate(length);
    if (!buffer) return -1;
    data_ov031_02291e3c.CreateTypeB(buffer, length, 0x20);
    if (*(unsigned char*)((char*)state + 0x374) & 0x20) {
        BackgroundLoader::AddLockGlobal();
        *(void**)((char*)state + 0x388) = &g_fileLoadBuffer;
        *(int*)((char*)state + 0x39c) = loader->QueueLoadFile(data_ov031_0224c90c, 0);
        *(int*)((char*)state + 0x3a0) = loader->QueueLoadFile(data_ov031_0224c920, 0);
        result = 3;
        BackgroundLoader::RemoveLockGlobal();
    } else {
        *(void**)((char*)state + 0x4c) = allocator->Allocate(0x700);
        FlagWord_SetBits(GlobalFlags_GetInstance(), 0x80);
    }
#if defined(jpn)
    *(int*)((char*)GetGameResources() + 0x41e4) = 1;
#else
    *(int*)((char*)GetGameResources() + 0x4494) = 1;
#endif
    MarkContextStackTopUnknownSubspace(data_02111304.activeContext, 0x100);
    EnableSpecificInterrupts(0xc78);
    (void)REG_IME;
    REG_IME = 1;
    EnableIRQInterrupts();
    return var3;
}
