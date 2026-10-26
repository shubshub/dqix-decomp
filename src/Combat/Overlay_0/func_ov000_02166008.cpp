#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"


extern char data_ov000_02183a2f[];
extern char g_fileLoadBuffer[];

// USA: func_ov000_02166008
extern "C" ARM unsigned int func_ov000_02166008(void* unused, GPCReadPair* arg1, int flag) {
    unsigned int length;
    if (flag) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
    }
    arg1->ZeroInitialize();
    LoadAndDecompressGPCHeaderAndInnerFileInfo(&arg1->pGPCFile, arg1->machine,
        data_ov000_02183a2f, g_fileLoadBuffer, length, 0x30000, false, NULL);
    return length;
}
