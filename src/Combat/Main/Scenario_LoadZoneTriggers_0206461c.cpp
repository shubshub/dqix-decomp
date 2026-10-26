#include <globaldefs.h>
#if defined(jpn)
#define func_02095578 func_020971c8
#define data_020f05dc data_020f0644
#endif
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>
#include "Resource/GameResources.h"

struct Struct_0206461c {
    unsigned char unknown_0_[0x47c];
    int unknown_47c_;
    unsigned char unknown_480_[0x14];
    int unknown_494_;
};
struct Struct_0206461c_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[3];
    char unknown_5_[3];
};
struct Obj02064574;
struct StreamHeader;
extern Obj02064574 g_scenario;
extern char data_020f05dc[] __attribute__((aligned(4)));
int GameState_GetStoryChapter(char*);
int GameState_GetStoryPart(char*);
void Scenario_LoadTriggers(Obj02064574*, int, StreamHeader*, int, int, int, int);
void* GetGlobal02109418_02094d6c();
extern "C" void func_02095578(void*);

static inline SafeAllocator* inline_0206461c(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// Main, originally func_0206461c (USA 0x0206461c, EUR 0x0206462c, JPN 0x02065908)
extern "C" ARM int Scenario_LoadZoneTriggers(LoaderOwner0206461c* owner, Request0206461c* request) {
    GameState* state = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    Obj02064574* object = &g_scenario;
    SafeAllocator* allocator = GetAllocator0206461c(GetGameResources(), 15);
    unsigned int size = 0;
    char name[4];
    char path[64];
    int first = GameState_GetStoryChapter((char*)state);
    int second = GameState_GetStoryPart((char*)state);
    allocator->Reset();
    owner->field_0x47c = 0;
    owner->field_0x494 = 0;
    memcpy(name, request->name, 3);
    name[3] = 0;
    if (name[0] == 'F') name[1] = 0;
    BackgroundLoader::AddLockGlobal();
    sprintf(path, data_020f05dc, name);
    StreamHeader* file = (StreamHeader*)LoadFileIntoMemory(path, g_fileLoadBuffer, &size);
    if (file) Scenario_LoadTriggers(object, (int)allocator, file, size, request->id, first, second);
    BackgroundLoader::RemoveLockGlobal();
    func_02095578(func_02094d6c());
    return 1;
}
