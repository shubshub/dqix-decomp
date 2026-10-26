#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov004_0217018c { unsigned int w[0xd8 / 4]; };
extern struct Struct_ov004_0217018c data_ov004_0217018c;
extern "C" void func_ov011_02184a24(void*, void*, int);

// USA: func_ov004_0216e9cc
extern "C" ARM void func_ov004_0216e9cc(SafeAllocator* a, void* target) {
    struct Struct_ov004_0217018c tmp = data_ov004_0217018c;
    void* buf = a->Allocate(0xd8);
    memcpy(buf, &tmp, 0xd8);
    func_ov011_02184a24(target, buf, 0x36);
}
