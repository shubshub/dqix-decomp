#include <globaldefs.h>
#include "NitroSDK/Mutex.h"

struct Struct_ov031_0224f670_9 {
    unsigned char padding[4];
    void* (*unknown_4_)(int);
};

extern Mutex data_ov031_0224f704;
extern Struct_ov031_0224f670_9 data_ov031_0224f670;

// USA: func_ov031_0221f9a0
extern "C" THUMB void* func_ov031_0221f9a0(void* unused, int size) {
    if (size > 0) {
        LockMutex(&data_ov031_0224f704);
        void* allocation = data_ov031_0224f670.unknown_4_(size);
        UnlockMutex(&data_ov031_0224f704);
        return allocation;
    }
    return NULL;
}
