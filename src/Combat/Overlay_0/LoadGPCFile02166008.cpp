#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"


extern char data_ov000_02183a2f[];
extern char g_fileLoadBuffer[];

// USA: func_ov000_02166008
ARM unsigned int LoadGPCFile02166008(void* unused, GPCReadPair* readPair, int flag) {
    unsigned int length;
    if (flag) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
    }
    readPair->ZeroInitialize();
    LoadAndDecompressGPCHeaderAndInnerFileInfo(&readPair->pGPCFile, readPair->machine,
        data_ov000_02183a2f, g_fileLoadBuffer, length, 0x30000, false, NULL);
    return length;
}
