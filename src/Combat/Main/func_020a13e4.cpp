#include <globaldefs.h>
#if defined(jpn)
#define data_020f1917 data_020f1a7f
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

struct Struct_02109d94_2 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldC;
};
extern struct Struct_02109d94_2 data_02109d94;

extern int data_020f1917;
extern int data_020f192c;
extern int data_020f18ec;

// USA: func_020a13e4
extern "C" ARM void func_020a13e4(void* param0, void* param1, int param2, unsigned short param3, unsigned char param4) {
    if (param1 != 0) {
        int localVar;
        void* result;
        data_02109d94.field4 = param0;
        data_02109d94.field8 = param1;
        data_02109d94.fieldC = param2;
        data_02109d94.field2 = param3;
        data_02109d94.field0 = param4;
        BackgroundLoader::AddLockGlobal();
        localVar = 0;
        #if defined(jpn)
        result = LoadFileIntoMemory((const char*)&data_020f1917, g_fileLoadBuffer, (unsigned int*)&localVar);
#else
        result = ExtractFileFromGP2((const char*)&data_020f1917, (const char*)&data_020f192c, (unsigned int*)&localVar);
#endif
        if (result != 0) {
            struct ResetStruct local;
            ((Script*)&local)->Initialize();
            ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f18ec);
            ((Script*)((struct StreamState*)&local))->Load((struct StreamHeader*)result, localVar);
            ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
        }
        BackgroundLoader::RemoveLockGlobal();
    }
}
