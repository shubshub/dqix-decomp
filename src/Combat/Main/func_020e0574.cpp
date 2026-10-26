#include <globaldefs.h>

extern "C" int func_020e05f8(char* dst, char const* fmt, short);
typedef int (*Type_020e0574)(char*, const char*, int);

#if defined(jpn)
#include "Filesystem/FileIO.h"

// JPN: func_020e21e8
extern "C" ARM void* func_020e21e8(const char* arg0, unsigned int* outSize, int variant) {
    char path[0x40];
    if (arg0 == NULL)
        return NULL;
    *outSize = 0;
    ((Type_020e0574)func_020e05f8)(path, arg0, variant);
    LoadFileIntoMemory(path, g_fileLoadBuffer, outSize);
    if (*outSize != 0)
        return g_fileLoadBuffer;
    return NULL;
}
#else
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);

extern char g_fileLoadBuffer[];

// USA: func_020e0574
extern "C" ARM int func_020e0574(void* a, int* b, int c, int d) {
    char buf[0x40];
    if (a == 0) {
        return 0;
    }
    *b = 0;
    ((Type_020e0574)func_020e05f8)(buf, (char*)a, c);
    if (d == 0) {
        LoadFileIntoMemory(buf, g_fileLoadBuffer, (unsigned int*)b);
        if (*b != 0) {
            return (int)g_fileLoadBuffer;
        }
    } else {
        void* res = ExtractFileFromGP2((const char*)d, buf, (unsigned int*)b);
        if (res != 0) {
            return (int)res;
        }
    }
    return 0;
}
#endif
