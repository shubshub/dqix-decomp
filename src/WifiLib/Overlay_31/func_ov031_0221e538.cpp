#include <globaldefs.h>

extern "C" int func_ov031_022072d0(int arg0, void* buffer, int size, int flags, void* address);

// USA: func_ov031_0221e538
extern "C" THUMB int func_ov031_0221e538(int arg0, void* buffer, int size, int flags, unsigned char* address, int* arg5) {
    *address = (unsigned char)*arg5;
    return func_ov031_022072d0(arg0, buffer, size, flags, address);
}
