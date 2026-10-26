#include <globaldefs.h>
#include <NitroSDK/Interrupts.h>
#include <NitroSDK/ProcessorContext.h>

struct Struct_ov031_022066b4 {
    unsigned char unknown_0_[0x2c];
    unsigned short unknown_2c_;
    unsigned short available;
};

struct TransferSettings {
    unsigned char unknown_0_[0x24];
    int limit;
};

extern TransferSettings data_ov031_0224e1d0;

// USA: func_ov031_022066b4
extern "C" ARM int func_ov031_022066b4(int value) {
    Struct_ov031_022066b4* var0 = reinterpret_cast<Struct_ov031_022066b4*>(data_02111304.activeContext->unknown_A4);
    int var1 = DisableIRQInterrupts();
    int var2;
    if (var0 != 0) {
        int available = var0->available;
        if (available != 0 && var0->unknown_2c_ != 0) {
            int var4 = var0->unknown_2c_;
            int maximum = data_ov031_0224e1d0.limit;
            if (available > var4) {
                available = var4;
            }
            if (available > maximum) {
                available = maximum;
            }
            var2 = available * 2;
        } else {
            var2 = data_ov031_0224e1d0.limit * 2;
        }
    } else {
        var2 = data_ov031_0224e1d0.limit * 2;
    }
    SetIRQInterruptState(var1);
    if (var2 > 0) {
        int var6 = value / var2;
        if (var6 > 0) {
            return var2 * var6;
        }
    }
    return value;
}
