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
struct Struct_02013fb4;
extern "C" ARM void func_0209562c(struct Struct_02095578* arg0, int arg1,
    struct Struct_02013fb4* arg2, int arg3, unsigned short arg4, int arg5, int arg6);

extern "C" void* Zone3D_GetInstance();
int GetField5cb0Value_0201079c(char* obj);
int GetField5cb4Value_020107d0(char* obj);
extern int data_020f1474;
extern char data_02109418[] __attribute__((aligned(4)));

struct Struct_02095578_2 {
    char unknown_0_[0x164 - sizeof(SafeAllocator)];
    SafeAllocator unknown_150_[2];
    SafeAllocator* inline_02095578(int arg0) { return &unknown_150_[arg0]; }
};

// USA: func_02095578
extern "C" ARM int func_02095578(void) {
    char var0[0x40];
    unsigned int var1;
    GameState* var2;
    void* var3;
    struct Struct_02095578* var4;
    GameResources* var5;
    SafeAllocator* var6;
    unsigned short var7;
    int var8;
    int var9;
    void* var10;

    bs = GameState::GetInstance();
    move = Zone3D_GetInstance();
    header = (struct HeaderStruct0209562c*)&data_02109418;
    res = GetGameResources();
    (int)BackgroundLoader::GetInstance();
    var6 = ((Struct_02095578_2*)var5)->inline_02095578(1);
    var7 = *(unsigned short*)var3;
    var8 = func_0201079c((char*)var2);
    var9 = func_020107d0((char*)var2);
    BackgroundLoader::AddLockGlobal();
    sprintf(path, (const char*)&data_020f1474);
    file = LoadFileIntoMemory(path, g_fileLoadBuffer, &len);
    if (file != NULL) {
        SetupHeaderAndRunBufferedScript0209562c(header, (int)type, (struct StreamHeader*)file, len, id, cb0, cb4);
    }
    BackgroundLoader::RemoveLockGlobal();
    return var10 == NULL ? 0 : 1;
}
