#include <globaldefs.h>

struct Struct_ov031_022073a4;
extern "C" ARM int func_ov031_022073a4(int arg0, int buffer, int size, int flags, const Struct_ov031_022073a4* destination);

// USA: func_ov031_0221e5a0
extern "C" THUMB int func_ov031_0221e5a0(int arg0, const void* buffer, int size, int flags, void* destination, int arg5) {
    *(unsigned char*)destination = (unsigned char)arg5;
    return func_ov031_022073a4(arg0, (int)buffer, size, flags, (const Struct_ov031_022073a4*)destination);
}
