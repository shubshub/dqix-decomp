#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
struct BlockedContextList;
void BlockCurrentContext(struct BlockedContextList* p);
void UnblockContexts(struct BlockedContextList* p);
extern "C" int _s32_div_f(int a, int b);

// USA: func_020c7ea0
extern "C" ARM int func_020c7ea0(void* obj, unsigned int* out, int arg2) {
    unsigned int mask = DisableIRQInterrupts();
    if (*(int*)((char*)obj + 0x1c) == 0) {
        int wait = arg2 & 1;
        while (1) {
            if (!wait) {
                SetIRQInterruptState(mask);
                return 0;
            }
            BlockCurrentContext((struct BlockedContextList*)((char*)obj + 8));
            if (*(int*)((char*)obj + 0x1c) != 0) break;
        }
    }
    if (out != NULL) {
        unsigned int* arr = *(unsigned int**)((char*)obj + 0x10);
        unsigned int idx = *(unsigned int*)((char*)obj + 0x18);
        *out = arr[idx];
    }
    int base = *(int*)((char*)obj + 0x18);
    int capacity = *(int*)((char*)obj + 0x14);
    *(int*)((char*)obj + 0x18) = (base + 1) % capacity;
    *(int*)((char*)obj + 0x1c) = *(int*)((char*)obj + 0x1c) - 1;
    UnblockContexts((struct BlockedContextList*)obj);
    SetIRQInterruptState(mask);
    return 1;
}
