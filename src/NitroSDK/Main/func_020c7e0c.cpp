#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
struct BlockedContextList;
void BlockCurrentContext(struct BlockedContextList* p);
void UnblockContexts(struct BlockedContextList* p);

// USA: func_020c7e0c
extern "C" ARM int func_020c7e0c(void* obj, unsigned int value, int arg2) {
    unsigned int mask = DisableIRQInterrupts();
    int count = *(int*)((char*)obj + 0x1c);
    int capacity = *(int*)((char*)obj + 0x14);
    if (capacity <= count) {
        int wait = arg2 & 1;
        while (1) {
            if (!wait) {
                SetIRQInterruptState(mask);
                return 0;
            }
            BlockCurrentContext((struct BlockedContextList*)obj);
            count = *(int*)((char*)obj + 0x1c);
            capacity = *(int*)((char*)obj + 0x14);
            if (capacity > count) break;
        }
    }
    int base = *(int*)((char*)obj + 0x18);
    int idx = (base + count) % capacity;
    unsigned int* arr = *(unsigned int**)((char*)obj + 0x10);
    arr[idx] = value;
    *(int*)((char*)obj + 0x1c) = *(int*)((char*)obj + 0x1c) + 1;
    UnblockContexts((struct BlockedContextList*)((char*)obj + 8));
    SetIRQInterruptState(mask);
    return 1;
}
