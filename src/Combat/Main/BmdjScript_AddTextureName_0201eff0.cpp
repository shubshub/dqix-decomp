#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct StrTable0201f308;
struct Struct02030b7c;

extern "C" void BmdjScriptState_AddTextureName(StrTable0201f308*, char*, SafeAllocator*);

// data_020fdc40, the BMDJ script's context while BmdjScriptState_RunScript runs it
struct Struct_020fdc40_6 {
    int currentResource;
    SafeAllocator* allocator;
    StrTable0201f308* state;
};
extern Struct_020fdc40_6 data_020fdc40;

// Main, originally AddStringIfPresent0201eff0 (USA 0x0201eff0, EUR 0x0201f000, JPN 0x0201ed7c)
extern "C" ARM int BmdjScript_AddTextureName(Struct02030b7c* params) {
    char* textureName = (char*)(void*)((Script::Parameter*)params)->ToString();
    if (textureName != NULL) {
        BmdjScriptState_AddTextureName(data_020fdc40.state, textureName, data_020fdc40.allocator);
    }
    return 1;
}
