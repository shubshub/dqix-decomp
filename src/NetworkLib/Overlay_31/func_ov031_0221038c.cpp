#include <globaldefs.h>
#include "NitroSDK/Mutex.h"

struct Struct_ov031_0221038c {
    int field0;
    volatile int state;
    Mutex unknown_8_;
};
extern Struct_ov031_0221038c* data_ov031_0224e588;

// USA: func_ov031_0221038c
extern "C" ARM void func_ov031_0221038c(int state) {
    Struct_ov031_0221038c* context = data_ov031_0224e588;
    if (context == NULL) return;
    Mutex* var1 = &context->unknown_8_;
    (void)context->state;
    LockMutex(var1);
    if (data_ov031_0224e588->state != 2) data_ov031_0224e588->state = state;
    UnlockMutex(&data_ov031_0224e588->unknown_8_);
}
