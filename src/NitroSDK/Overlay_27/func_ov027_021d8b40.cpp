#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" int func_ov027_021d9de8(int a);
extern void* data_ov027_021e33ec;

// USA: func_ov027_021d8b40
#pragma optimize_for_size off
extern "C" ARM int func_ov027_021d8b40(int id, int kind) {
    int value, var1;
    int var2 = DisableIRQInterrupts();
    switch (kind) {
    case 0: var1 = 0xa; value = 4; break;
    case 1: var1 = 0xa; value = 3; break;
    case 2: var1 = 0xe; value = 2; break;
    case 3: var1 = 0x7; value = 5; break;
    default:
        SetIRQInterruptState(var2);
        return 0;
    }

    if (data_ov027_021e33ec != 0 && func_ov027_021d9de8(id) != 0) {
        int idx = id - 1;
        void* base = data_ov027_021e33ec;
        int v = *(int*)((char*)base + idx * 4 + 0x1000 + 0x4e8);
        if (var1 == v) {
            *(short*)((char*)base + idx * 2 + 0x1700 + 0x54) = (short)value;
            SetIRQInterruptState(var2);
            return 1;
        }
    }
    SetIRQInterruptState(var2);
    return 0;
}
