#include <globaldefs.h>
#if defined(jpn)
#define data_020f155c data_020f16c4
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

struct Struct_020995c0;
extern struct Struct_020995c0* data_02109924;

extern char data_020f155c[];
extern char g_fileLoadBuffer[];
extern char data_020f1524[];

// USA: func_020998c4
extern "C" ARM void func_020998c4(struct Struct_020995c0* param0) {
    int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f155c, g_fileLoadBuffer, (unsigned int*)&count);
    if (header != 0) {
        data_02109924 = param0;
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        ((Script*)buf)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f1524);
        ((Script*)((struct StreamState*)buf))->Load(header, count);
        ((Script*)((struct Struct_0201f040_3*)buf))->Execute();
        data_02109924 = 0;
    }
    BackgroundLoader::RemoveLockGlobal();
}
