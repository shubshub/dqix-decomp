#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

extern "C" void func_020bbef8(int bit);
extern SignedAllocatorList data_0210fca8;

struct Struct_020bcc7c {
    char pad0[0x24];
    int field24;        /* 0x24 */
    char pad28[0x18];
    int field40;        /* 0x40 */
};

// USA: func_020bccf0
extern "C" ARM void func_020bccf0(struct Struct_020bcc7c* obj) {
    func_020bbef8(obj->field40);
    data_0210fca8.Remove((SignedAllocatorHeader*)obj);
    obj->field24 &= ~1;
}
