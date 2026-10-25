#include <globaldefs.h>

extern "C" int func_020e05f8(char* arg0, char const* arg1, short);
typedef int (*Type_020e0574)(char*, const char*, int);

#if defined(jpn)
#include "Filesystem/FileIO.h"

// JPN: func_020e21e8
extern "C" ARM void* func_020e21e8(const char* arg0, unsigned int* arg1, int arg2) {
    char var0[0x40];
    if (arg0 == NULL)
        return NULL;
    *outSize = 0;
    ((ReplaceBin3)ReplaceBinExtensionWithNat020e05f8)(path, tablePath, variant);
    LoadFileIntoMemory(path, g_fileLoadBuffer, outSize);
    if (*outSize != 0)
        return g_fileLoadBuffer;
    return NULL;
}
#else
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);

extern char g_fileLoadBuffer[];

// USA: func_020e0574
extern "C" ARM int func_020e0574(void* arg0, int* arg1, int arg2, int arg3) {
    char var0[0x40];
    if (arg0 == 0) {
        return 0;
    }
    *b = 0;
    ((ReplaceBin3)ReplaceBinExtensionWithNat020e05f8)(buf, (char*)a, c);
    if (d == 0) {
        LoadFileIntoMemory(buf, g_fileLoadBuffer, (unsigned int*)b);
        if (*b != 0) {
            return (int)g_fileLoadBuffer;
        }
    } else {
        void* var1 = ExtractFileFromGP2((const char*)arg3, var0, (unsigned int*)arg1);
        if (var1 != 0) {
            return (int)var1;
        }
    }
    return 0;
}
#endif
