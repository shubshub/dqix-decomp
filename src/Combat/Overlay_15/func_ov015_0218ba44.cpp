#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193fa0 data_ov015_02194ae0
#define data_ov015_02193fc8 data_ov015_02194b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
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

struct StreamHeader;
struct StreamState;

struct Struct_0201f040_3;

extern "C" void func_ov015_0218b828();
void* LoadFileIntoMemory(const char* path, void* buf, unsigned int* outLen);

extern int g_fileLoadBuffer;
extern int data_ov015_02193fc8;
extern void* data_ov015_02194560;
extern int data_ov015_02193fa0;

// USA: func_ov015_0218ba44
extern "C" ARM void func_ov015_0218ba44(void* self, const char* path) {
    func_ov015_0218b828();
    BackgroundLoader::AddLockGlobal();

    unsigned int length;
    void* buffer;
    if (path != 0) {
        buffer = LoadFileIntoMemory(path, &g_fileLoadBuffer, &length);
    } else {
        buffer = LoadFileIntoMemory((const char*)&data_ov015_02193fc8, &g_fileLoadBuffer, &length);
    }

    if (buffer != 0) {
        data_ov015_02194560 = self;

        struct ResetStruct local;
        ((Script*)&local)->Initialize();
        ((Script*)&local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_ov015_02193fa0);
        ((Script*)((struct StreamState*)&local))->Load((struct StreamHeader*)buffer, length);
        ((Script*)((struct Struct_0201f040_3*)&local))->Execute();
    }

    BackgroundLoader::RemoveLockGlobal();
}
