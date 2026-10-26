#include <globaldefs.h>
#include <NitroSDK/Interrupts.h>

struct Struct_01ff8300_3 {
    Struct_01ff8300_3* next;
};

struct Struct_02112780_4 {
    Struct_01ff8300_3* unknown_0_;
    unsigned long unknown_4_;
    Struct_01ff8300_3* unknown_8_;
    Struct_01ff8300_3* unknown_c_;
    Struct_01ff8300_3* unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    unsigned long unknown_20_;
};

extern Struct_02112780_4 data_02112780;
extern Struct_01ff8300_3* data_021127a4[9];
extern unsigned char data_02112a60[0x1800];

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
int SendCommandToArm7(int command, int data, bool error);
extern "C" void func_020d2880();
extern "C" void* func_020d22f4(unsigned long flags);

// USA: func_020d24c4
extern "C" ARM int func_020d24c4(unsigned long flags) {
    int var0 = DisableIRQInterrupts();
    if (data_02112780.unknown_8_ == NULL) {
        SetIRQInterruptState(var0);
        return true;
    }
    if (data_02112780.unknown_1c_ >= 8) {
        if (!(flags & 1)) {
            SetIRQInterruptState(var0);
            return false;
        }
        do {
            func_020d22f4(1);
        } while (data_02112780.unknown_1c_ >= 8);
        if (data_02112780.unknown_8_ == NULL) {
            SetIRQInterruptState(var0);
            return true;
        }
    }
    CleanInvalidateCacheRange(data_02112a60, sizeof(data_02112a60));
    if (SendCommandToArm7(7, (int)data_02112780.unknown_8_, false) < 0) {
        if (!(flags & 1)) {
            SetIRQInterruptState(var0);
            return false;
        }
        while (data_02112780.unknown_1c_ >= 8 ||
               SendCommandToArm7(7, (int)data_02112780.unknown_8_, false) < 0) {
            SetIRQInterruptState(var0);
            func_020d22f4(0);
            var0 = DisableIRQInterrupts();
            CleanInvalidateCacheRange(data_02112a60, sizeof(data_02112a60));
            if (data_02112780.unknown_8_ == NULL) {
                SetIRQInterruptState(var0);
                return true;
            }
        }
    }
    data_021127a4[data_02112780.unknown_18_] = data_02112780.unknown_8_;
    data_02112780.unknown_18_++;
    if (data_02112780.unknown_18_ > 8)
        data_02112780.unknown_18_ = 0;
    data_02112780.unknown_8_ = NULL;
    data_02112780.unknown_c_ = NULL;
    data_02112780.unknown_1c_++;
    data_02112780.unknown_20_++;
    SetIRQInterruptState(var0);
    if (flags & 2)
        func_020d2880();
    return true;
}
