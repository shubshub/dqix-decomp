#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
extern "C" void func_020bf458(SignedAllocatorHeader* header);

// USA: func_020bf358
extern "C" ARM void func_020bf358(SignedAllocatorList* list, SignedAllocatorHeader* arg1) {
    unsigned int mask;
    SignedAllocatorHeader* element;
    SignedAllocatorHeader* next;
    mask = DisableIRQInterrupts();
    element = list->ElementAfter(0);
    if (element != 0) {
        do {
            next = list->ElementAfter(element);
            if (element->pNextAllocator == arg1) {
                list->Remove(element);
                func_020bf458(element);
            }
            element = next;
        } while (element != 0);
    }
    SetIRQInterruptState(mask);
}
