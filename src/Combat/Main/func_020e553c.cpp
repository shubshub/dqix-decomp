#include <globaldefs.h>

extern "C" int func_020e55c0(char* arg0, const char* arg1);
typedef int (*Type_020e0574)(char*, const char*, int);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);

extern char g_fileLoadBuffer[];

// USA: func_020e553c
extern "C" ARM int func_020e553c(void* arg0, int* arg1, int arg2, int arg3) {
    char var0[0x40];
    if (arg0 == 0) {
        return 0;
    }
    *b = 0;
    ((ReplaceBin3)ReplaceBinExtensionWithNat020e55c0)(buf, (char*)a, c);
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
