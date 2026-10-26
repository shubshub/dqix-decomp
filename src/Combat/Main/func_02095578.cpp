#include <globaldefs.h>

#if defined(jpn)
#define func_02095578 func_020971c8
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct Struct_02095578;
struct StreamHeader;
extern "C" ARM void func_0209562c(struct Struct_02095578* header, int param1,
    struct StreamHeader* buffer, int length, unsigned short param4, int arg5, int arg6);

extern "C" void* Zone3D_GetInstance();
extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" int GameState_GetStoryPart(char* obj);
extern int data_020f1474;
extern char data_02109418[] __attribute__((aligned(4)));

struct Struct_02095578_2 {
    char pad[0x164 - sizeof(SafeAllocator)];
    SafeAllocator allocs[2];
    SafeAllocator* inline_02095578(int i) { return &allocs[i]; }
};

// USA: func_02095578
extern "C" ARM int func_02095578(void) {
    char path[0x40];
    unsigned int len;
    GameState* bs;
    void* move;
    struct Struct_02095578* header;
    GameResources* res;
    SafeAllocator* type;
    unsigned short id;
    int cb0;
    int cb4;
    void* file;

    bs = GameState::GetInstance();
    move = Zone3D_GetInstance();
    header = (struct Struct_02095578*)&data_02109418;
    res = GetGameResources();
    (int)BackgroundLoader::GetInstance();
    type = ((Struct_02095578_2*)res)->inline_02095578(1);
    id = *(unsigned short*)move;
    cb0 = GameState_GetStoryChapter((char*)bs);
    cb4 = GameState_GetStoryPart((char*)bs);
    BackgroundLoader::AddLockGlobal();
    sprintf(path, (const char*)&data_020f1474);
    file = LoadFileIntoMemory(path, g_fileLoadBuffer, &len);
    if (file != NULL) {
        func_0209562c(header, (int)type, (struct StreamHeader*)file, len, id, cb0, cb4);
    }
    BackgroundLoader::RemoveLockGlobal();
    return file == NULL ? 0 : 1;
}
