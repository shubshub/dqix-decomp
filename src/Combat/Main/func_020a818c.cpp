#include <globaldefs.h>
#if defined(jpn)
#define data_020f1b97 data_020f1d0f
#define data_020f1b6c data_020f1ce4
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct {
    int unknown_0_;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    char pad[0x400];
    unsigned char unknown_42c_;
};

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

#if defined(jpn)
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern char g_fileLoadBuffer[];
#else
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
#endif

struct Struct_02109fe0_3 { void* a; void* b; };
extern struct Struct_02109fe0_3 data_02109fe0;

extern int data_020f1b97;
extern int data_020f1baa;
extern int data_020f1b6c;

// USA: func_020a818c
extern "C" ARM void func_020a818c(void* param0, void* param1) {
    BackgroundLoader::AddLockGlobal();
    int localVar = 0;
    #if defined(jpn)
    void* result = LoadFileIntoMemory((const char*)&data_020f1b97, g_fileLoadBuffer, (unsigned int*)&localVar);
#else
    void* result = ExtractFileFromGP2((const char*)&data_020f1b97, (const char*)&data_020f1baa, (unsigned int*)&localVar);
#endif
    if (result != 0) {
        struct ResetStruct local;
        data_02109fe0.a = param1;
        data_02109fe0.b = param0;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1b6c);
        ((Script*)((struct StreamState*)&local))->Load((struct StreamHeader*)result, localVar);
        ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
