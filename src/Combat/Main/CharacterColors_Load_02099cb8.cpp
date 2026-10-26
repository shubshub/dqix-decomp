#include <globaldefs.h>
#if defined(jpn)
#define data_020f15ac data_020f1714
#define data_020f1574 data_020f16dc
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char data_020f15ac[];
extern char g_fileLoadBuffer[];
extern char data_020f1574[];

// Main, originally PrepareAndRunBufferedScript02099cb8 (USA 0x02099cb8, EUR 0x02099cc8, JPN 0x0209b9ec)
extern "C" ARM void CharacterColors_Load(char* param0) {
    int count;
    char buf[0x430];

    memset(param0, 0, 0x12c);
    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f15ac, g_fileLoadBuffer, (unsigned int*)&count);
    if (header != 0) {
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        ((Script*)buf)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_020f1574);
        ((Script*)((struct StreamState*)buf))->Load(header, count);
        ((Script*)((struct Struct_0201f040_3*)buf))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
