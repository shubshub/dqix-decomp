#include <globaldefs.h>

struct Struct_ov015_0218bae8 { void* base; int pad4; int count; };

#pragma optimize_for_size off
// USA: func_ov015_0218bae8
extern "C" ARM void* func_ov015_0218bae8(struct Struct_ov015_0218bae8* obj, int idx) {
    if (idx < 0)
        goto ret0;
    if (obj->count > idx)
        goto good;
ret0:
    return NULL;
good:
    return (char*)obj->base + idx * 0xc;
}
