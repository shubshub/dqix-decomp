#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Mutex.h"

struct Struct_ov031_02216ca0 {
    char padding[0x1020];
    int state;
    char unknown_1024_[0xb14];
    ProcessorContext context;
};
struct Struct_ov031_02216ca0_2 {
    char padding[0x1004];
    int result;
    int state;
    char unknown_100c_[0x308];
    Struct_ov031_02216ca0* session;
    ProcessorContext context;
    Mutex unknown_13e0_;
    int unknown_13f8_;
};
struct Struct_ov031_0224e5e8_9 { int field0; int field4; Struct_ov031_02216ca0_2* state; };
extern Struct_ov031_0224e5e8_9 data_ov031_0224e5e8;
extern "C" void func_ov031_02217598(int);
extern "C" int func_ov031_02216f54();
extern "C" void func_ov031_022183b4(Struct_ov031_02216ca0*);
extern "C" int func_ov031_02216b90(int);

// USA: func_ov031_02216ca0
extern "C" ARM void func_ov031_02216ca0() {
    int var0 = 0;
    while (true) {
        if (data_ov031_0224e5e8.state->session->context.uniqueID != 0)
            AwaitContextCompletion(&data_ov031_0224e5e8.state->session->context);
        int mode;
        if (data_ov031_0224e5e8.state->session->state != 8) {
            data_ov031_0224e5e8.state->state = 0x4e84;
            int sessionState = data_ov031_0224e5e8.state->session->state;
            if (sessionState == 7) { func_ov031_02217598(20); return; }
            if (var0 > 2) {
                if (sessionState == 2) { func_ov031_02217598(9); return; }
                if (sessionState == 3) { func_ov031_02217598(11); return; }
                func_ov031_02217598(13); return;
            }
            mode = 1;
            ++var0;
        } else {
            int result = func_ov031_02216f54();
            switch (result) {
            case 21:
                func_ov031_02217598(21); return;
            case 16:
                if (var0 > 2) { func_ov031_02217598(16); return; }
                mode = 0;
                ++var0;
                break;
            case 17:
                func_ov031_02217598(result); return;
            default:
                if (var0 >= 2) { func_ov031_02217598(result); return; }
                mode = 1;
                ++var0;
                break;
            }
        }
        unsigned long long start = GetCurrentTimestamp();
        if ((((GetCurrentTimestamp() - start) << 6) / 33514ULL) < 5000ULL) {
          do {
            LockMutex(&data_ov031_0224e5e8.state->unknown_13e0_);
            if (data_ov031_0224e5e8.state->unknown_13f8_ == 1) {
                data_ov031_0224e5e8.state->state = 0x4e84;
                UnlockMutex(&data_ov031_0224e5e8.state->unknown_13e0_);
                func_ov031_02217598(20);
                return;
            }
            UnlockMutex(&data_ov031_0224e5e8.state->unknown_13e0_);
            SleepCurrentContext(5000);
          } while ((((GetCurrentTimestamp() - start) << 6) / 33514ULL) < 5000ULL);
        }
        func_ov031_022183b4(data_ov031_0224e5e8.state->session);
        LockMutex(&data_ov031_0224e5e8.state->unknown_13e0_);
        data_ov031_0224e5e8.state->result = func_ov031_02216b90(mode);
        if (data_ov031_0224e5e8.state->result != 0) {
            data_ov031_0224e5e8.state->state = 0x4e84;
            UnlockMutex(&data_ov031_0224e5e8.state->unknown_13e0_);
            return;
        }
        UnlockMutex(&data_ov031_0224e5e8.state->unknown_13e0_);
    }
}
