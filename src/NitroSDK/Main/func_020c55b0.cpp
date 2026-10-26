#include <globaldefs.h>
#include "NitroSDK/DMA.h"


extern "C" void func_020ca3ec(int value, void* dst, int size);
extern int data_020f2270;

// USA: func_020c55b0
extern "C" ARM void func_020c55b0() {
    if (data_020f2270 != -1) {
        DMAMemsetAsync(data_020f2270, 0x4000330, 0, 0x10, NULL, 0);
        DMAMemsetSynchronous(data_020f2270, 0x4000360, 0, 0x60);
    } else {
        func_020ca3ec(0, (void*)0x4000330, 0x10);
        func_020ca3ec(0, (void*)0x4000360, 0x60);
    }
    int i = 0;
    do {
        i++;
        *(volatile unsigned int*)0x40004d0 = 0;
    } while (i < 0x20);
}
