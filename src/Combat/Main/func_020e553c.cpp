#include <globaldefs.h>

extern "C" int func_020e55c0(char* dst, const char* fmt);
typedef int (*Type_020e0574)(char*, const char*, int);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);

extern char g_fileLoadBuffer[];

// USA: func_020e553c
extern "C" ARM int func_020e553c(void* a, int* b, int c, int d) {
    char buf[0x40];
    if (a == 0) {
        return 0;
    }
    *b = 0;
    ((Type_020e0574)func_020e55c0)(buf, (char*)a, c);
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
