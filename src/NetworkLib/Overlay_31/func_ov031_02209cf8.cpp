#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_ov031_0224c9e8_2 { unsigned long long value; unsigned long long unknown_8_; unsigned long long unknown_10_; };
extern Struct_ov031_0224c9e8_2 data_ov031_0224c9e8;
extern unsigned char data_ov031_0224e3b0;
extern unsigned char data_ov031_0224e528[20];
extern "C" void func_ov031_02209e28(void*, int);
extern "C" void func_ov031_0220b8a0(unsigned int*);
extern "C" void func_ov031_0220b8f4(void*, void*, int);
extern "C" void func_ov031_0220ba14(void*, void*);

// USA: func_ov031_02209cf8
extern "C" ARM void func_ov031_02209cf8(unsigned char* destination, int length) {
    unsigned int sum;
    unsigned char digest[20];
    unsigned int context[23];
    if (data_ov031_0224e3b0 == 0) {
        data_ov031_0224c9e8.value = data_ov031_0224c9e8.unknown_8_ * data_ov031_0224c9e8.value + data_ov031_0224c9e8.unknown_10_;
        sum = data_ov031_0224c9e8.value >> 32;
        func_ov031_02209e28(&sum, 4);
    }
    int var3 = 0;
    int var4 = 20;
    if (length <= 0) return;
    do {
            if (var4 == 20) {
                func_ov031_0220b8a0(context);
                int var5 = DisableIRQInterrupts();
                func_ov031_0220b8f4(context, data_ov031_0224e528, 20);
                func_ov031_0220ba14(context, digest);
                unsigned char* var6 = data_ov031_0224e528 + sizeof(data_ov031_0224e528) - 1;
                unsigned char* var7;
                int var8;
                unsigned int total;
                unsigned int var10 = 1;
                var8 = 19;
                var7 = digest + 19;
                do {
                    total = *var6 + *var7-- + var10;
                    *var6-- = total;
                    var10 = total >> 8;
                } while (--var8 >= 0);
                sum = total;
                SetIRQInterruptState(var5);
                var4 = 0;
            }
            unsigned char value = digest[var4++];
            if (value != 0) destination[var3++] = value;
    } while (var3 < length);
}
