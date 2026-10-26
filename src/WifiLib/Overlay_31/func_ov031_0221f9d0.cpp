#include <globaldefs.h>

struct Mutex;
void LockMutex(Mutex*);
void UnlockMutex(Mutex*);

extern int data_ov031_0224f704;
extern int data_ov031_0224f670;

typedef void (*Type_ov031_0221f9d0)(void*);

// USA: func_ov031_0221f9d0
extern "C" THUMB void func_ov031_0221f9d0(void* unused0, void* obj, int count) {
    if (obj != 0 && count > 0) {
        LockMutex((Mutex*)&data_ov031_0224f704);
        Type_ov031_0221f9d0 fn = *(Type_ov031_0221f9d0*)((char*)&data_ov031_0224f670 + 0xc);
        fn(obj);
        UnlockMutex((Mutex*)&data_ov031_0224f704);
    }
}
