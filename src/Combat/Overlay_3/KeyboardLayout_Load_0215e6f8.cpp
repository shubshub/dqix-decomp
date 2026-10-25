#include <globaldefs.h>
#include "Resource/Script.h"

struct StreamHeader;

extern int KeyboardLayout_scriptContext;
extern int KeyboardLayout_scriptOpcodes;

// Overlay 3, originally func_ov003_0215e6f8 (USA/EUR 0x0215e6f8; JPN not identified)
extern "C" ARM void KeyboardLayout_Load(int layout, int allocator, struct StreamHeader* file, int size) {
    Script script;
    *(int*)((char*)&KeyboardLayout_scriptContext + 4) = layout;
    *(int*)&KeyboardLayout_scriptContext = allocator;
    script.Initialize();
    script.SetOpcodeLookup((Script::OpcodeLookupEntry*)&KeyboardLayout_scriptOpcodes);
    script.Load(file, size);
    script.Execute();
}
