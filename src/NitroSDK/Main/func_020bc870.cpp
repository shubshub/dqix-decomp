#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

extern "C" void func_020bc658(SignedAllocatorList* list, SignedAllocatorHeader* arg1);
extern "C" void func_020bc6a8(SignedAllocatorHeader* arg0);

extern SignedAllocatorList data_0210f3d8;

// USA: func_020bc870
extern "C" ARM void func_020bc870(SignedAllocatorHeader* header, unsigned char b) {
    SignedAllocatorList* list = (SignedAllocatorList*)header->pPrevAllocator;
    if (list != NULL) {
        list->Remove(header);
        header->pPrevAllocator = NULL;
    }
    data_0210f3d8.Remove(header);
    *((unsigned char*)header + 0x3d) = b;
    if (list != NULL) {
        func_020bc658(list, header);
    }
    func_020bc6a8(header);
}
