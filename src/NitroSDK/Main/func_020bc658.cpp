#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

// USA: func_020bc658
extern "C" ARM void func_020bc658(SignedAllocatorList* list, SignedAllocatorHeader* arg1) {
    SignedAllocatorHeader* e = list->ElementAfter(NULL);
    if (e != NULL) {
        do {
            if (*((unsigned char*)arg1 + 0x3d) < *((unsigned char*)e + 0x3d)) break;
            e = list->ElementAfter(e);
        } while (e != NULL);
    }
    list->InsertBefore(e, arg1);
    arg1->pPrevAllocator = (SignedAllocatorHeader*)list;
}
