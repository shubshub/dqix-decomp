#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct Struct_020bf3c8 {
    char pad0[0x11c];
    int unknown_11c_;   /* 0x11c */
};

struct Struct_020bf3c8_2 {
    char pad0[8];
    struct Struct_020bf3c8* owner;  /* 0x8 */
};

// USA: func_020bf3c8
extern "C" ARM SignedAllocatorHeader* func_020bf3c8(SignedAllocatorList* list) {
    unsigned int saved = DisableIRQInterrupts();
    SignedAllocatorHeader* e = list->ElementAfter(NULL);
    if (e != NULL) {
        list->Remove(e);
        ((Struct_020bf3c8_2*)e)->owner->unknown_11c_--;
    }
    SetIRQInterruptState(saved);
    return e;
}
