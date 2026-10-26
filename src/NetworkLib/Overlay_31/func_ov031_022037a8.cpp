#include <globaldefs.h>
#include "NitroSDK/Timing.h"

struct Struct_ov031_022037a8 {
    unsigned char padding[8];
    unsigned char status;
    unsigned char padding2[0x1f];
    unsigned int unknown_28_;
    unsigned short available;
    unsigned short unknown_2e_;
    unsigned int unknown_30_;
    int pending;
};

struct Struct_ov031_0224c980_10 {
    unsigned char padding[0x48];
    int (*unknown_48_)();
};

extern Struct_ov031_0224c980_10 data_ov031_0224c980;
extern "C" int func_ov031_0220376c(int, int, int, int, int, int);
extern "C" void func_ov031_02200264();

// USA: func_ov031_022037a8
extern "C" ARM unsigned int func_ov031_022037a8(unsigned char* first, unsigned int arg1, unsigned char* second, unsigned int arg3, Struct_ov031_022037a8* channel) {
    unsigned int total = 0;
    unsigned int var1;
    int var2 = 0;
    channel->pending = 0;
    int var3 = GetCurrentTimestamp() >> 16;
    while (data_ov031_0224c980.unknown_48_() != 0 && arg1 != 0 && channel->status == 4 && (int)(GetCurrentTimestamp() >> 16) - var3 < 159) {
        unsigned int var4 = channel->unknown_28_;
        func_ov031_0220376c((int)first, arg1, (int)second, arg3, (int)channel, var2);
        int start = GetCurrentTimestamp() >> 16;
        while (1) {
            func_ov031_02200264();
            if (data_ov031_0224c980.unknown_48_() == 0 || channel->status != 4 || channel->unknown_28_ == channel->unknown_30_ || (int)(GetCurrentTimestamp() >> 16) - start >= 15) break;
            if (var2 != 0 && channel->available != 0) break;
        }
        var1 = channel->unknown_30_ - var4;
        if (var1 > channel->unknown_28_ - var4) var1 = 0;
        total += var1;
        if (var1 != 0) var3 = GetCurrentTimestamp() >> 16;
        channel->unknown_28_ = channel->unknown_30_;
        if (channel->status == 4 && channel->available == 0 && var1 == 0) {
            if (var2 == 0) {
                int var6 = GetCurrentTimestamp() >> 16;
                while (data_ov031_0224c980.unknown_48_() != 0 && (int)(GetCurrentTimestamp() >> 16) - var6 < 15) {
                    func_ov031_02200264();
                    if (channel->available != 0) break;
                }
                if (channel->available == 0) var2 = 1;
            }
        } else {
            var2 = 0;
        }
        {
            if (var1 < arg1) {
                first += var1;
                arg1 -= var1;
            } else {
                unsigned int var7 = var1 - arg1;
                first = second + var7;
                second = NULL;
                arg1 = arg3 - var7;
                arg3 = 0;
            }
        }
    }
    return total;
}
