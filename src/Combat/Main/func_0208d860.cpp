// KEEP-NAME
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Combat/ScriptElementList.h"

#if defined(jpn)
#define data_020f121c data_020f12ec
#endif

extern Script::OpcodeLookupEntry data_020f121c[];

// USA: func_0208d860
extern "C" ARM void func_0208d860(Struct_0208d550* header, SafeAllocator* allocator,
                                                const void* bytecode, unsigned int length,
                                                const short* arg4, short arg5,
                                                unsigned short flags) {
    if (allocator != NULL && bytecode != NULL && length != 0) {
        data_02108fc0.header = header;
        data_02108fc0.header->unknown_8_ = arg4;
        data_02108fc0.header->unknown_c_ = arg5;
        data_02108fc0.header->flags = flags;
        data_02108fc0.allocator = allocator;
        Script script;
        script.Initialize();
        script.SetOpcodeLookup(data_020f121c);
        script.Load(bytecode, length);
        script.Execute();
    }
}
