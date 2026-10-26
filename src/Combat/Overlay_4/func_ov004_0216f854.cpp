#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct_ov004_02170264 { unsigned int w[0x28 / 4]; };
extern struct Struct_ov004_02170264 data_ov004_02170264;
extern "C" void func_ov011_02184a24(void*, void*, int);

// USA: func_ov004_0216f854
extern "C" ARM void func_ov004_0216f854(SafeAllocator* a, void* target) {
    struct Struct_ov004_02170264 tmp = data_ov004_02170264;
    void* buf = a->Allocate(0x28);
    memcpy(buf, &tmp, 0x28);
    func_ov011_02184a24(target, buf, 0xa);
}
