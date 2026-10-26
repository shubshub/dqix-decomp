#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);
extern "C" void func_0205c790(char* obj);
struct Struct020dfc40;
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);

// USA: func_ov017_021a7328
extern "C" ARM void func_ov017_021a7328(char* obj) {
    func_0204693c((struct ByteHeader0204693c*)obj);
    obj[0] = 0x3f;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x10) = 0;
    *(int*)(obj + 0x20) = -1;
    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x18) = 0;
    func_0205c790(obj + 0x24);
#if defined(jpn)
    ((SafeAllocator*)(obj + 0x1ec))->ResetAllocatorPointer();
    KeyTable_Reset((struct Struct020dfc40*)(obj + 0x200));
#else
    ((SafeAllocator*)(obj + 0x25c))->ResetAllocatorPointer();
    KeyTable_Reset((struct Struct020dfc40*)(obj + 0x270));
#endif
}
