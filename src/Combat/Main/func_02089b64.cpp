#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct_02089ea0;

extern "C" void func_02089ea0(struct Struct_02089ea0* out, SafeAllocator* alloc, int count);

struct Struct_02108efc_3 {
    struct Struct_02089ea0* pool;
    int unk4;
    int unknown_8_;
    SafeAllocator* alloc;
};
extern Struct_02108efc_3 data_02108efc;

// USA: func_02089b64
extern "C" ARM int func_02089b64(struct Variant02030b0c* variant) {
    func_02089ea0(data_02108efc.pool, data_02108efc.alloc, (short)((Script::Parameter*)variant)->ToInt());
    return 1;
}
