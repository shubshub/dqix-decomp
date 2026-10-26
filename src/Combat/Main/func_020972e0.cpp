#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
struct Struct_020972e0 { unsigned int count:12, size:19, unknown_3_7_:1; };
struct Struct_02097248 { int field_0x0, unknown_4_, unknown_8_; char pad[0x14]; };
struct Struct_020972e0_2 { void* base; Struct_020972e0 fields; Struct_02097248* entries; void* extra; };
extern "C" int func_02097408(Struct_020972e0*);
extern "C" int func_02097248(void*, Struct_02097248*);
extern "C" void func_02097798(Struct_020972e0_2*);
// USA: func_020972e0
extern "C" ARM void func_020972e0(Struct_020972e0_2* obj, SafeAllocator* allocator, char* source) {
    if (allocator && source) {
        memcpy(&obj->fields, source, 4);
        int var0 = func_02097408(&obj->fields);
        int var1 = obj->fields.size;
        if (var0)
            obj->entries = (Struct_02097248*)allocator->Allocate(var0);
        else
            obj->entries = 0;
        obj->extra = var1 ? allocator->Allocate(var1) : 0;
        if (obj->entries) memcpy(obj->entries, source + 4, var0);
        if (obj->extra) memcpy(obj->extra, source + (func_02097408(&obj->fields) + 4), var1);
        int (*callback)(void*, Struct_02097248*) = func_02097248;
        if ((unsigned int)callback && obj->entries) {
            Struct_02097248* entry;
            int i;
            int count;
            count = obj->fields.count;
            if (count && callback) {
                entry = obj->entries;
                for (i = 0; i < count; i++, entry++) func_02097248(&obj->fields, entry);
            }
        }
        obj->fields.unknown_3_7_ = 1;
    }
    obj->base = obj->entries;
    func_02097798(obj);
}
