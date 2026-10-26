#include <globaldefs.h>
#include "NitroSDK/Timing.h"

extern "C" void* func_ov031_022133f8(unsigned int flags);
extern "C" int func_ov031_022151b0(void*, void*, int, int);
extern int data_ov031_02245fb0;
extern int data_ov031_02245fb8;

// USA: func_ov031_02214b64
extern "C" ARM void func_ov031_02214b64(int which) {
    char* obj = (char*)func_ov031_022133f8(0x10);
    switch (which) {
    case 3: {
        *(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
        int v = *(signed char*)(obj + 0xd11);
        func_ov031_022151b0(&data_ov031_02245fb0, &data_ov031_02245fb8, v, 0x200000);
        break;
    }
    case 4: {
        *(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
        int idx = *(unsigned char*)(obj + 0xd0f) * 0xc0;
        int v = *(unsigned short*)(obj + 0x4a6 + idx) - 1;
        func_ov031_022151b0(obj + 0x474 + idx, obj + 0x47c + idx, v, 0x300000);
        break;
    }
    case 5: {
        *(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
        int idx = *(unsigned char*)(obj + 0xd0f);
        int v = *(signed char*)(obj + 0xd11);
        func_ov031_022151b0(&data_ov031_02245fb0, obj + 0x304 + idx * 0x24, v, 0x300000);
        break;
    }
    }
}
