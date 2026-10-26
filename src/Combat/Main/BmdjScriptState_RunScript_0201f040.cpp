#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct StreamHeader;

int LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char g_fileLoadBuffer;
extern char data_020ef418;

// data_020fdc40, the BMDJ script's context: the opcode handlers (data_020ef418) write into state and allocate from
// allocator; currentResource is the last resource record opcode 0x6c added
struct BmdjScriptContext {
    int currentResource;
    void* allocator;
    void* state;
};
extern struct BmdjScriptContext data_020fdc40;

// Main, originally RegisterAndRunBufferedScript0201f040 (USA 0x0201f040, EUR 0x0201f050, JPN 0x0201edcc)
ARM void BmdjScriptState_RunScript(void* state, void* allocator, struct StreamHeader* scriptIn, unsigned int lengthIn) {
    unsigned int length = lengthIn;
    int locked = 0;
    struct StreamHeader* script = scriptIn;
    Script runner;

    if (script == NULL) {
        int nullFileName;
        BackgroundLoader::AddLockGlobal();
        nullFileName = locked;
        locked = 1;
        script = (struct StreamHeader*)LoadFileIntoMemory((const char*)nullFileName, &g_fileLoadBuffer, &length);
    }
    if (script != NULL) {
        data_020fdc40.allocator = allocator;
        data_020fdc40.state = state;
        runner.Initialize();
        runner.SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020ef418);
        runner.Load(script, length);
        runner.Execute();
        data_020fdc40.state = 0;
        data_020fdc40.allocator = 0;
    }
    if (locked) {
        BackgroundLoader::RemoveLockGlobal();
    }
}
