#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char g_fileLoadBuffer[];
extern int data_020f0cc8;

struct Struct_02108db0_3 {
    unsigned char field0;
    char pad1;
    unsigned short field2;
    void* field4;
    void* field8;
    int fieldc;
    void* field10;
};
extern struct Struct_02108db0_3 data_02108db0;

// USA: func_020727f8
extern "C" ARM void func_020727f8(void* param0, const char* path, int param2, void* param3, unsigned char arg4) {
    unsigned int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(path, g_fileLoadBuffer, &count);
    if (header != 0) {
        data_02108db0.field10 = param0;
        data_02108db0.fieldc = 0;
        data_02108db0.field8 = &param2;
        data_02108db0.field2 = 1;
        data_02108db0.field4 = param3;
        data_02108db0.field0 = arg4;

        ((Script*)((struct ResetStruct*)buf))->Initialize();
        ((Script*)buf)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f0cc8);
        ((Script*)((struct StreamState*)buf))->Load(header, count);
        ((Script*)((struct Struct_0201f040_3*)buf))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
