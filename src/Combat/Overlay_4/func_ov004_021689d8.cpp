#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_ov011_02184a24(void* a, void* b, int c);
struct Struct_ov004_021700c0 { unsigned int w[5]; };
extern struct Struct_ov004_021700c0 data_ov004_021700c0;

// USA: func_ov004_021689d8
extern "C" ARM void func_ov004_021689d8(SafeAllocator* a, void* target) {
    struct Struct_ov004_021700c0 buf = data_ov004_021700c0;
    void* allocated = a->Allocate(0x14);
    memcpy(allocated, &buf, 0x14);
    func_ov011_02184a24(target, allocated, 5);
}
