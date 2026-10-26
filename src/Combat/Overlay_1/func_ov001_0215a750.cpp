#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char g_fileLoadBuffer[];

// USA: func_ov001_0215a750
extern "C" ARM unsigned int func_ov001_0215a750(const char* path, void** outPtr) {
    BackgroundLoader::AddLockGlobal();
    unsigned int size = 0;
    void* result = LoadFileIntoMemory(path, g_fileLoadBuffer, &size);
    if (result == NULL) return 0;
    BackgroundLoader::RemoveLockGlobal();
    *outPtr = g_fileLoadBuffer;
    return size;
}
