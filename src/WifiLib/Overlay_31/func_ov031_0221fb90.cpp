#include <globaldefs.h>
#include "NitroSDK/Timing.h"
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0221fb90 { unsigned char bytes[0xc0]; };
struct Struct_ov031_0224f670_14 { unsigned char padding0[0x10]; int error; unsigned char unknown_14_[4]; int unknown_18_; unsigned char padding1c[4]; int initialized; int connected; unsigned char padding28[0x34]; Struct_ov031_0221fb90* buffers; };
struct Struct_ov031_0224b114 { unsigned char padding[0xc]; unsigned int unknown_c_; };
extern Struct_ov031_0224f670_14 data_ov031_0224f670;
extern Struct_ov031_0224b114 data_ov031_0224b114;
extern unsigned char data_ov031_0224b128[];
extern "C" int func_ov031_0221f854(void*, void*, int);
extern "C" void func_ov031_0221fa88(int);
extern "C" unsigned int func_ov031_02222870();
extern "C" void* func_ov031_0221fa20();
extern "C" int func_ov031_0220764c(void*);

// USA: func_ov031_0221fb90
extern "C" THUMB int func_ov031_0221fb90() {
    int running = 1;
    int result = -2;
    Struct_ov031_0221fb90* buffer = data_ov031_0224f670.buffers + data_ov031_0224f670.unknown_18_;
    Alarm var3;
    if (buffer == NULL) return 0;
    if (func_ov031_0221f854(buffer, 0, 0x30000) == 0) return -2;
    ZeroInitializeAlarm(&var3);
    SetTimeout(&var3, 0x3fec42ULL, (Alarm::PFNCompletion)func_ov031_0221fa88, (ProcessorContext**)18);
    do {
        if (func_ov031_02222870() >= data_ov031_0224b114.unknown_c_) { result = -3; break; }
        if (data_ov031_0224f670.error != 0) { result = -8; break; }
        SleepCurrentContext(10);
        int message = (int)func_ov031_0221fa20();
        if (message != 0) { do {
            switch (message) {
            case 4: case 5: case 18: case 19: break;
            case 12: running = 0; result = 1; break;
            case 13:
                if (data_ov031_0224f670.error != 0) { running = 0; result = -8; }
                else if (func_ov031_0221f854(buffer, 0, 0x30000) == 0) return result;
                break;
            default: running = 0; break;
            }
            message = (int)func_ov031_0221fa20();
        } while (message != 0); }
    } while (running != 0);
    CancelAlarm(&var3);
    while (func_ov031_0221fa20() != 0) {}
    if (result > 0) {
        data_ov031_0224f670.initialized = 1;
        if (func_ov031_0220764c(data_ov031_0224b128) < 0) result = -2;
        else data_ov031_0224f670.connected = 1;
    }
    return result;
}
