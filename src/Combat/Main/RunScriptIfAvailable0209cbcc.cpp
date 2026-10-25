#include <globaldefs.h>
#if defined(jpn)
#define data_020f1744 data_020f18ac
#define data_020f1718 data_020f1880
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

int LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char data_020f1744;
extern char g_fileLoadBuffer;
extern char data_020f1718;

// USA: func_0209cbcc
ARM void RunScriptIfAvailable0209cbcc(void*) {
    int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(&data_020f1744, &g_fileLoadBuffer, (unsigned int*)&count) != 0) {
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        ((Script*)buf)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020f1718);
        ((Script*)((struct StreamState*)buf))->Load((struct StreamHeader*)&g_fileLoadBuffer, count);
        ((Script*)((struct Struct02030774*)buf))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
