#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Resource/ActionDataTables.h"

extern "C" {
    void __clear(void*, unsigned int);
}

struct Struct0200fb08;
int GameState_GetLanguage(Struct0200fb08*);

struct Struct_02079808;
extern "C" void* func_02079a3c(void* arg0);

extern unsigned char g_fileLoadBuffer[0x30000];
extern const char data_020f0e02[];
extern const char data_020f0e17[];
extern const char data_020f0e28[];

#if !defined(jpn)
// USA: func_02079cf8
#pragma opt_propagation off
extern "C" ARM void func_02079cf8(ActionDataTables* obj, SafeAllocator* a1, SafeAllocator* a2) {
    unsigned int len;
    unsigned char* base;
    base = g_fileLoadBuffer;
    unsigned int capacity = sizeof(g_fileLoadBuffer);
    GPCReadPair pair;
    ResetObjectState02079a3c(&pair);

    unsigned int var4;

    const char* var5 = data_020f0e02;
    bool var6 = LoadAndDecompressGPCHeaderAndInnerFileInfo(&var3.pGPCFile, var3.machine,
        var5, var1, var4, var2, false, NULL);
    if (var6) {
        unsigned int var7 = 0;
        var0 = var4;
        var2 -= var0;
        GameState* var8 = GameState::GetInstance();
        char var9[0x20];
        __clear(var9, sizeof(var9));

        int language = GameState_GetLanguage((Struct0200fb08*)battle);
        StringReplaceLanguageTag(data_020f0e17, buf, language);

        DecompressFileFromGPCByName(var3.pGPCFile, var3.machine, var1 + var0,
            var7, var2, var9);

        func_02079a58(&arg0->unknown_c_, arg1, var1 + var0,
            func_02079808, 0, arg2);

        DecompressFileFromGPCByName(var3.pGPCFile, var3.machine, var1 + var0,
            var7, var2, data_020f0e28);

        func_02079bac(&arg0->unknown_24_, arg1, var1 + var0, NULL, 0, 0);
    }

    var3.Reset();
    ZeroDestroyGPCPointer(&var3.pGPCFile);
}

#endif
