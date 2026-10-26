#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Resource/SpellTable.h"

struct Ctx0209a8b4 {
    void* field0;
};
extern struct Ctx0209a8b4* SpellTable_scriptContext;
extern char SpellTable_scriptOpcodes[];

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct_0201f040_3;

// USA: func_0209a8b4
extern "C" ARM void func_0209a8b4(struct Ctx0209a8b4* ctx, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    void* mem = alloc->Allocate(sizeof(SpellTable));
    ctx->field0 = mem;
    if (mem != NULL) {
        memset(mem, 0, sizeof(SpellTable));
        char local[0x430];
        SpellTable_scriptContext = ctx;
        ((Script*)((struct ResetStruct*)local))->Initialize();
        ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)SpellTable_scriptOpcodes);
        ((Script*)((struct StreamState*)local))->Load(buffer, length);
        ((Script*)((struct Struct_0201f040_3*)local))->Execute();
        SpellTable_scriptContext = NULL;
    }
}
