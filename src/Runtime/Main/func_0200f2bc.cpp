#include <globaldefs.h>

extern "C" void* func_0200d9e4(void* ptr, int* arg1);

// USA: func_0200f2bc
extern "C" ARM void* func_0200f2bc(void* ptr) {
    unsigned char flags;
    int scratch;
    flags = *(unsigned char*)ptr;
    ptr = (char*)ptr + 2;
    ptr = func_0200d9e4(ptr, &scratch);
    if (!(flags & 0x40)) {
        return ptr;
    }
    ptr = func_0200d9e4(ptr, &scratch);
    return ptr;
}
