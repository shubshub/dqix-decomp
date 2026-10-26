#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov028_021d9940;
extern "C" void func_ov028_021d9940(Struct_ov028_021d9940* obj, SafeAllocator* allocator, unsigned int count);

struct Struct_ov028_021d9bc4 {
    Struct_ov028_021d9940* field0;
    SafeAllocator* field4;
};
extern Struct_ov028_021d9bc4 data_ov028_021d9bc4;

// USA: func_ov028_021d97b0
extern "C" ARM int func_ov028_021d97b0(Script::Parameter* params, int count) {
    func_ov028_021d9940(data_ov028_021d9bc4.field0, data_ov028_021d9bc4.field4, (unsigned short)params->ToInt());
    return 1;
}
