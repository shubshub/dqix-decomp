#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"

struct Struct_020fdc4c_6 {
    unsigned short unknown_0_;
    unsigned short unknown2;
};

// The map script context (CombatScriptContext in Combat/CombatScriptContext.h, defined here field by field): the
// opcode handlers allocate from data_020fdc54 and fill data_020fdc5c, the MapDisplay being loaded
unsigned int data_020fdc58;
SafeAllocator* data_020fdc54;
#if !defined(jpn)
char* data_020fdc50;
#endif
Struct_020fdc4c_6 data_020fdc4c;
char* data_020fdc5c;

#if defined(jpn)
#define data_020ef510 data_020ef3f4
#endif
// The .bmmp (minimap) script opcodes
extern Script::OpcodeLookupEntry data_020ef510[];

// Main, originally func_02020c18 (USA 0x02020c18, EUR 0x02020c28, JPN 0x02020834)
extern "C" ARM void MapDisplay_RunMapScript(MapDisplay* self, MapDisplayTaskHandle scriptTask, SafeAllocator* allocator) {
    Script script;
    void* code;
    unsigned int length;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* fileData = 0;
    unsigned int fileSize = 0;
#if defined(jpn)
    loader->GetLoadedFileByID(scriptTask, &fileData, &fileSize);
#else
    loader->GetLoadedFileByID(*scriptTask, &fileData, &fileSize);
#endif
    length = fileSize;
    data_020fdc5c = (char*)self;
    code = fileData;
    data_020fdc54 = allocator;
    script.Initialize();
    script.SetOpcodeLookup(data_020ef510);
    script.Load(code, length);
    script.Execute();
#if defined(jpn)
    BackgroundLoader::GetInstance()->RemoveTask(scriptTask);
#else
    BackgroundLoader::GetInstance()->RemoveTask(*scriptTask);
    *scriptTask = -1;
#endif
}
