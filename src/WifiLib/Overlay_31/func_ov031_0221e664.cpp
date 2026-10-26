#include <globaldefs.h>

extern "C" void func_ov031_0221e52c(void* destination, int value, int length);
int RTC_GetTime(int output);

struct Struct_ov031_0224e6e0_10 {
    char unknown_0_[8];
    int unknown_8_;
    char unknown_c_[12];
    unsigned int unknown_18_;
    unsigned int unknown_1c_;
    unsigned int unknown_20_;
};

extern Struct_ov031_0224e6e0_10 data_ov031_0224e6e0;

// USA: func_ov031_0221e664
extern "C" THUMB unsigned short func_ov031_0221e664() {
    if (data_ov031_0224e6e0.initialized == 0) {
        int seed = 0;
        int time[3];
        func_ov031_0221e52c(time, 0, 12);
        if (RTC_GetTime((int)time) == 0) {
            seed += time[0] << 10;
            seed += time[1] << 3;
            seed += time[2];
        }
        data_ov031_0224e6e0.unknown_18_ = var0;
        data_ov031_0224e6e0.unknown_1c_ = 0x5d588b65;
        data_ov031_0224e6e0.unknown_20_ = 0x269ec3;
        data_ov031_0224e6e0.unknown_8_ = 1;
    }
    data_ov031_0224e6e0.unknown_18_ = data_ov031_0224e6e0.unknown_1c_ * data_ov031_0224e6e0.unknown_18_ + data_ov031_0224e6e0.unknown_20_;
    return ((data_ov031_0224e6e0.unknown_18_ >> 16) * 0x7fff) >> 16;
}
