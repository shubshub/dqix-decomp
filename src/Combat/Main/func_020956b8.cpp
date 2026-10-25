#include <globaldefs.h>

#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"
#include "Resource/QuestScript.h"

extern short data_020f13d8;
extern const char data_020f1474[] __attribute__((aligned(4)));
extern Script::OpcodeLookupEntry data_020f141c[];

// USA: func_020956b8
extern "C" ARM void func_020956b8(struct Struct_020956b8* arg0, SafeAllocator* arg1) {
    unsigned int var0;

    if (arg1 == 0) {
        return;
    }

    BackgroundLoader::AddLockGlobal();
    void* file = LoadFileIntoMemory(data_020f1474, g_fileLoadBuffer, &fileSize);
    if (file != 0) {
        data_02109404.f8 = 0;
        data_02109404.f3 = 0;
        data_02109404.f4 = 0;
        data_02109404.allocator = allocator;
        data_02109404.selected = 0;
#if defined(jpn)
        *(short*)0x020f1524 = -1;
#else
        *(short*)0x020f13d8 = -1;
#endif
        arg0->unknown_a0_ = 0;
        data_02109404.unknown_0_ = 0;
        Script var2;
        var2.Initialize();
        var2.SetOpcodeLookup(data_020f141c);
        var2.Load(var1, var0);
        var2.Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
