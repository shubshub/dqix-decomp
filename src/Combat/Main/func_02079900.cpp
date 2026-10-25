#include <globaldefs.h>
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/ActionDataTables.h"
struct Struct0200fb08;
unsigned char GameState_GetLanguage(Struct0200fb08*);
void* ResetObjectState02079a3c(void*);
extern "C" void __clear(void*, unsigned int);
#if defined(jpn)
#define data_020f0dcc data_020f0e94
#define data_020f0de1 data_020f0eab
#define data_020f0df2 data_020f0eb9
extern "C" int func_0207a6fc(void*, Struct_02079808*);
#endif
extern char data_020f0dcc[], data_020f0de1[], data_020f0df2[];
// USA: func_02079900
// JPN: func_0207a7c8
extern "C" ARM void func_02079900(Struct_02108e10* arg0, SafeAllocator* arg1) {
    BackgroundLoader::AddLockGlobal();
    GPCReadPair pair;
    unsigned int offset = 0;
    unsigned char* buffer = g_fileLoadBuffer;
    int capacity = 0x30000;
    ResetObjectState02079a3c(&pair);
    unsigned int length;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, data_020f0dcc, buffer, length, capacity, false, 0)) {
        offset = length;
        unsigned int decompressed = 0;
        unsigned int payloadCapacity = capacity - offset;
        unsigned char* payload = buffer + offset;
#if !defined(jpn)
        GameState* game = GameState::GetInstance();
        char filename[0x20];
        __clear(filename, 0x20);
        StringReplaceLanguageTag(data_020f0de1, filename, GameState_GetLanguage((Struct0200fb08*)game));
#else
        const char* var9 = data_020f0de1;
#endif
        DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var7, var5, var6, var9);
#if defined(jpn)
        Type_02079900 var10 = &func_0207a6fc;
#else
        Type_02079900 var10 = &func_02079808;
#endif
        func_02079a58(&arg0->unknown_0_, arg1, var7, var10, NULL
#if !defined(jpn)
                      , NULL
#endif
        );
        DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var7, var5, var6, data_020f0df2);
        func_02079bac(&arg0->unknown_18_, arg1, var7, NULL, NULL
#if !defined(jpn)
                      , NULL
#endif
        );
    }
    BackgroundLoader::RemoveLockGlobal();
    var0.Reset();
    ZeroDestroyGPCPointer(&var0.pGPCFile);
}
