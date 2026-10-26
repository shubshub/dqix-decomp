#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0224f670_20 {
    unsigned char field_0[0xc];
    void (*unknown_c_)(void*);
    int unknown_10_;
    unsigned char unknown_14_[0x1c];
    void* result;
    int unknown_34_;
    int state;
    unsigned char unknown_3c_[0x28];
    int running;
    unsigned char unknown_68_[0xc];
    int pending;
};

extern Struct_ov031_0224f670_20 data_ov031_0224f670;
extern ProcessorContext data_ov031_0224f71c;
bool IsContextInactive(ProcessorContext* context);
extern "C" void func_ov031_02222af0();
extern "C" int func_ov031_0221fb38();

// USA: func_ov031_02222a10
extern "C" THUMB int func_ov031_02222a10() {
    int state;
    if (data_ov031_0224f670.running) {
        state = data_ov031_0224f670.state;
        data_ov031_0224f670.unknown_10_ = 1;
        while (data_ov031_0224f670.state >= 1 && data_ov031_0224f670.state <= 5) {
            SleepCurrentContext(100);
        }
        SleepCurrentContext(500);
        if (!IsContextInactive(&data_ov031_0224f71c)) {
            do {
                MarkContextReadyAndSwitch(&data_ov031_0224f71c);
                AwaitContextCompletion(&data_ov031_0224f71c);
            } while (!IsContextInactive(&data_ov031_0224f71c));
        }
        if (data_ov031_0224f670.result) {
            data_ov031_0224f670.unknown_c_(data_ov031_0224f670.result);
            data_ov031_0224f670.result = 0;
        }
        data_ov031_0224f670.running = 0;
        if (state != data_ov031_0224f670.state) func_ov031_02222af0();
    }
    if (data_ov031_0224f670.pending > 0) {
        int result = func_ov031_0221fb38();
        data_ov031_0224f670.pending = 0;
        return result;
    }
    return -10;
}
