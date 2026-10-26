#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_ov031_0224e204 {
    char padding0[0x20];
};
struct Struct_ov031_0224f4c0 {
    void* (*unknown_0_)(void*);
    char padding4[4];
    void* context;
    void (*unknown_c_)(void*);
};
extern "C" void func_020c7de4(Struct_ov031_0224e204* queue, int buffer, int capacity);
extern "C" int func_ov031_0221f26c(int (*handler)(int), void* context, int size);
extern "C" int func_ov031_0221e7a8(int message);
extern "C" int func_020c7ea0(Struct_ov031_0224e204* queue, int* message, int arg2);
extern Struct_ov031_0224e204 data_ov031_0224f4e0;
extern int data_ov031_0224f4d0[4];
extern Struct_ov031_0224f4c0 data_ov031_0224f4c0;

// USA: func_ov031_0221e7d0
extern "C" THUMB int func_ov031_0221e7d0(void* (*arg0)(void*), void (*arg1)(void*)) {
    int running = 1;
    func_020c7de4(&data_ov031_0224f4e0, (int)data_ov031_0224f4d0, 4);
    if (arg0 == NULL || arg1 == NULL) return -1;
    int var1 = DisableIRQInterrupts();
    data_ov031_0224f4c0.unknown_0_ = arg0;
    data_ov031_0224f4c0.unknown_c_ = arg1;
    SetIRQInterruptState(var1);
    void* context = data_ov031_0224f4c0.unknown_0_((void*)0x5890);
    data_ov031_0224f4c0.context = context;
    if (context == NULL) return -1;
    if (func_ov031_0221f26c(func_ov031_0221e7a8, context, 0x5890) == 0) running = 0;
    if (running != 0) {
        do {
            int message;
            func_020c7ea0(&data_ov031_0224f4e0, &message, 1);
            switch (message) {
            case 4: case 5: break;
            case 6: return 0;
            case 0: case 1: case 2: case 3:
            case 7: case 8: case 9: case 10: case 11:
            case 12: case 13: case 14: case 15:
            default: running = 0; break;
            }
        } while (running != 0);
    }
    data_ov031_0224f4c0.unknown_c_(data_ov031_0224f4c0.context);
    return -1;
}
