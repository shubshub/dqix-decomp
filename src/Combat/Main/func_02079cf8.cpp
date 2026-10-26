#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Resource/ActionDataTables.h"

extern "C" {
    void __clear(void*, unsigned int);
}

struct Struct0200fb08;
extern "C" int GameState_GetLanguage(Struct0200fb08*);

struct Struct_02079808;
extern "C" void* func_02079a3c(void* obj);

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
    func_02079a3c(&pair);

    unsigned int sizeOut;

    const char* name = data_020f0e02;
    bool ok = LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
        name, base, sizeOut, capacity, false, NULL);
    if (ok) {
        unsigned int outSize2 = 0;
        len = sizeOut;
        capacity -= len;
        GameState* battle = GameState::GetInstance();
        char buf[0x20];
        __clear(buf, sizeof(buf));

        int language = GameState_GetLanguage((Struct0200fb08*)battle);
        StringReplaceLanguageTag(data_020f0e17, buf, language);

        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + len,
            outSize2, capacity, buf);

        func_02079a58(&obj->unknown_c_, a1, base + len,
            func_02079808, 0, a2);

        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + len,
            outSize2, capacity, data_020f0e28);

        func_02079bac(&obj->unknown_24_, a1, base + len, NULL, 0, 0);
    }

    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}

#endif
