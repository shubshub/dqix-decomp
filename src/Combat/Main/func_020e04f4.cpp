#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#include "Filesystem/FileIO.h"

extern "C" void* func_020e21e8(const char* arg0, unsigned int* outSize, int variant);
extern "C" char* func_020e046c(char* destination, void* data, void* arg2, int index);

// JPN: func_020e2168
extern "C" ARM int func_020e2168(char* destination, const char* arg1,
    int index, int variant, bool lock) {
    if (destination == NULL || arg1 == NULL || index < 0)
        return 0;
    if (lock)
        BackgroundLoader::AddLockGlobal();
    unsigned int size;
    func_020e21e8(arg1, &size, variant);
    char* result = func_020e046c(destination, g_fileLoadBuffer, (void*)size, index);
    if (lock)
        BackgroundLoader::RemoveLockGlobal();
    return (int)result;
}
#else
extern "C" int func_020e0574(void* a, int* b, int c, int d);
extern "C" int func_020e046c(int a, int b, int c, int d);

// USA: func_020e04f4
extern "C" ARM int func_020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5) {
    int tmp;
    int result;
    int var2;

    if (p0 == 0 || p1 == NULL || p2 < 0) {
        return 0;
    }
    if (p4 != 0) {
        BackgroundLoader::AddLockGlobal();
    }
    var2 = func_020e0574(p1, &tmp, p3, p5);
    result = func_020e046c(p0, var2, tmp, p2);
    if (p4 != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    return result;
}
#endif
