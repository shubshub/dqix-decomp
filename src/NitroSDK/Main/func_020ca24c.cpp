#include <globaldefs.h>

unsigned int DisableSpecificInterrupts(unsigned int mask);
void SetInterruptHandler(unsigned int mask, const void* proc);

struct Struct_02111684_3 {
    int flag;                  // 0x0
    char pad[0xc];             // 0x4
    void (*callback)(void*);   // 0x10
    void* arg;                 // 0x14
    unsigned int unknown_18_;      // 0x18
    unsigned int unknown_1c_;      // 0x1c
};
extern struct Struct_02111684_3 data_02111684;

// USA: func_020ca24c
extern "C" ARM void func_020ca24c(void) {
    void (*callback)(void*);
    void* arg;

    DisableSpecificInterrupts(0x200000);
    *(volatile unsigned int*)0x4000600 =
        (data_02111684.unknown_18_ << 30) | (*(volatile unsigned int*)0x4000600 & ~0xc0000000);
    SetInterruptHandler(0x200000, (const void*)data_02111684.unknown_1c_);

    data_02111684.flag = 0;
    callback = data_02111684.callback;
    arg = data_02111684.arg;
    if (callback != NULL) {
        callback(arg);
    }
}
