#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
struct BlockedContextList;
void BlockCurrentContext(struct BlockedContextList* p);

// USA: func_020c7fe0
extern "C" ARM int func_020c7fe0(void* obj, unsigned int* out, int arg2) {
    unsigned int mask = DisableIRQInterrupts();
    if (*(unsigned int*)((char*)obj + 0x1c) == 0) {
        int wait = arg2 & 1;
        while (1) {
            if (!wait) {
                SetIRQInterruptState(mask);
                return 0;
            }
            BlockCurrentContext((struct BlockedContextList*)((char*)obj + 8));
            if (*(unsigned int*)((char*)obj + 0x1c) != 0) break;
        }
    }
    if (out != NULL) {
        unsigned int* arr = *(unsigned int**)((char*)obj + 0x10);
        unsigned int idx = *(unsigned int*)((char*)obj + 0x18);
        *out = arr[idx];
    }
    SetIRQInterruptState(mask);
    return 1;
}
