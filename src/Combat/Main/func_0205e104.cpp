#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern void* data_02108740[];
extern Script::OpcodeLookupEntry data_020f051c[];

// USA: func_0205e104
extern "C" ARM void func_0205e104(char* arg0, SafeAllocator* allocator, const void* buffer, unsigned int length) {
    Script script;
    if (arg0 && buffer && length) {
        data_02108740[1] = arg0;
        data_02108740[0] = allocator;
        script.Initialize();
        script.SetOpcodeLookup(data_020f051c);
        script.Load(buffer, length);
        script.Execute();
    }
}
