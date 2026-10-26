#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct BlockedContextList;
void BlockCurrentContext(struct BlockedContextList* p);

struct Mutex;
void* LockMutex(Mutex*);
extern "C" void func_020bf79c(void* p);

extern "C" ARM SignedAllocatorHeader* func_020bf3c8(SignedAllocatorList* list);
extern "C" void func_020bf458(SignedAllocatorHeader* header);

struct Struct_ov031_02290f8c;
void UnlockMutex(Mutex*);

// USA: func_020c015c
extern "C" ARM void func_020c015c(void *obj) {
    char *base = (char*)obj;
    for (;;) {
        BlockCurrentContext((BlockedContextList*)(base + 0x4c0));
    retry:
        LockMutex((Mutex*)(base + 0x4c8));
        {
            SignedAllocatorHeader *e = func_020bf3c8((SignedAllocatorList*)(base + 0x4e0));
            if (e == 0) {
                UnlockMutex((Mutex*)(base + 0x4c8));
            } else {
                func_020bf79c(e);
                func_020bf458(e);
                UnlockMutex((Mutex*)(base + 0x4c8));
                goto retry;
            }
        }
    }
}
