#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Memory/HPXEAllocator.h"


extern "C" void HaltSystem(void);
extern HPXEAllocator* data_ov031_02290d3c;

// USA: func_ov031_0223ce9c
extern "C" ARM void func_ov031_0223ce9c(void* a) {
    VectorizedMemset(a, 0, 0x40000);
    HPXEAllocator* p = HPXEAllocator::CreateAtLocation(a, 0x40000, 0);
    data_ov031_02290d3c = p;
    if (p == 0) {
        HaltSystem();
    }
}
