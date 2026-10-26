#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


int LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);

struct StreamHeader;
struct Struct_02071488;
extern "C" int func_02071488(struct StreamHeader* buffer, int length, int arg2, struct Struct_02071488* obj);

extern char data_020f0c24;
extern char data_020f0c45;
extern char data_020f0c5e;
extern char g_fileLoadBuffer;

// USA: func_02071574
extern "C" ARM struct Struct_02071488* func_02071574(unsigned int value, struct Struct_02071488* obj) {
    unsigned int length;

    BackgroundLoader::AddLockGlobal();

    if (value >= 0x5208 && value < 0x9c40) {
        if (LoadFileIntoMemory(&data_020f0c24, &g_fileLoadBuffer, &length) &&
            func_02071488((struct StreamHeader*)&g_fileLoadBuffer, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    } else if (value >= 0x9c40) {
        if (LoadFileIntoMemory(&data_020f0c45, &g_fileLoadBuffer, &length) &&
            func_02071488((struct StreamHeader*)&g_fileLoadBuffer, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    } else {
        if (LoadFileIntoMemory(&data_020f0c5e, &g_fileLoadBuffer, &length) &&
            func_02071488((struct StreamHeader*)&g_fileLoadBuffer, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    return NULL;
}
