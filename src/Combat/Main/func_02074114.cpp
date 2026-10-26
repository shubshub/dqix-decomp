#include <globaldefs.h>
#include "Combat/BufferedScriptResult.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

#if defined(jpn)
#define data_020f0d40 data_020f0e38
#endif

extern char data_020f0d40[];
extern unsigned char g_fileLoadBuffer[];

// USA: func_02074114
extern "C" ARM int func_02074114(Struct_02074060* result, int key) {
    unsigned int length;
    BackgroundLoader::AddLockGlobal();
    void* bytecode = LoadFileIntoMemory(data_020f0d40, g_fileLoadBuffer, &length);
    if (bytecode != 0) {
        func_0207416c(result, key, bytecode, length);
        BackgroundLoader::RemoveLockGlobal();
        return 1;
    }
    BackgroundLoader::RemoveLockGlobal();
    return 0;
}
