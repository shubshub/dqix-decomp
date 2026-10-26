#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Mutex.h"
#include "NitroSDK/Memory.h"
struct Struct_ov031_0220f104 {
    char pad[0xf00];
    char buffer[0x1360];
    int state;
    char unknown_2264_[7];
    unsigned char busy;
};
struct Struct_ov031_0224e540_4 { char pad[0x24]; int state; };
extern "C" Struct_ov031_0220f104* func_ov031_0220d60c();
extern "C" int func_020d5bfc(int, void*, void*, unsigned int);
extern Mutex data_ov031_0224e54c;
extern BlockedContextList data_ov031_0224e544;
extern Struct_ov031_0224e540_4 data_ov031_0224e540;
extern "C" void func_ov031_0220f28c();
// USA: func_ov031_0220f104
extern "C" ARM int func_ov031_0220f104(void* obj, void* first, unsigned int arg2, void* second, int arg4) {
    int var0 = DisableIRQInterrupts();
    if (!func_ov031_0220d60c()) {
        SetIRQInterruptState(var0);
        return -1;
    }
    int total;
    LockMutex(&data_ov031_0224e54c);
    Struct_ov031_0220f104* state = func_ov031_0220d60c();
    if (!state) {
        UnlockMutex(&data_ov031_0224e54c);
        SetIRQInterruptState(var0);
        return -1;
    }
    if (state->state != 9 || state->busy == 1) {
        UnlockMutex(&data_ov031_0224e54c);
        SetIRQInterruptState(var0);
        return -4;
    }
    VectorizedInvertedMemcpy(first, state->buffer, arg2);
    if (arg4 > 0) VectorizedInvertedMemcpy(second, state->buffer + arg2, arg4);
    total = arg2 + arg4;
    switch (func_020d5bfc((int)func_ov031_0220f28c, obj, state->buffer, (unsigned short)total)) {
    case 0: case 1: case 3: case 4: case 5: case 6: case 7: case 8: default:
        UnlockMutex(&data_ov031_0224e54c);
        SetIRQInterruptState(var0);
        return -5;
    case 2:
        break;
    }
    BlockCurrentContext(&data_ov031_0224e544);
    switch (data_ov031_0224e540.state) {
    case 0:
        break;
    case 1:
    default:
        UnlockMutex(&data_ov031_0224e54c);
        SetIRQInterruptState(var0);
        return -5;
    }
    UnlockMutex(&data_ov031_0224e54c);
    SetIRQInterruptState(var0);
    return total;
}
