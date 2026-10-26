#include <globaldefs.h>
#include "NitroSDK/Timing.h"

struct Struct_ov031_02204368 {
    unsigned char type;
    unsigned char unknown_1_[3];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned char unknown8[8];
    unsigned char unknown_10_[4];
    unsigned char unknown14[8];
    unsigned short hardwareAddress[3];
    unsigned char unknown_22_[0xec - 0x22];
    unsigned char unknown_ec_[4];
    unsigned char unknown_f0_[1];
};
struct Struct_ov031_0224c980_15 {
    unsigned char unknown0[0x1c];
    unsigned int unknown_1c_;
    unsigned int unknown_20_;
    unsigned char unknown24[8];
    unsigned int unknown_2c_;
    unsigned char unknown30[4];
    unsigned int unknown_34_;
    unsigned char unknown_38_[0x10];
    int (*progress)();
    unsigned int unknown_4c_;
    unsigned int unknown_50_;
    unsigned char unknown54[0xc];
    unsigned int unknown_60_;
    unsigned int unknown_64_;
};
extern Struct_ov031_0224c980_15 data_ov031_0224c980;
extern unsigned short data_ov031_0224ce68[3];
extern "C" int func_ov031_02203b1c();
extern "C" void func_ov031_02200264();
extern "C" int func_ov031_0220357c(unsigned int *);
extern "C" int func_ov031_02200824(unsigned short *, unsigned short *);
extern "C" void func_ov031_02203670(int);
#define READ_NETWORK32_02204368(p) (((unsigned int)(unsigned short)(((p)[0] << 8) | (p)[1]) << 16) | (unsigned short)(((p)[2] << 8) | (p)[3]))
#define SWAP_NETWORK16_02204368(v) ((unsigned short)(((v) >> 8) | ((v) << 8)))

// USA: func_ov031_02204368
extern "C" ARM int func_ov031_02204368(int arg0, int arg1) {
    int var0 = (arg1 + 1) * 15;
    int start = (int)(GetCurrentTimestamp() >> 16);
    int result = 0;
    while (data_ov031_0224c980.progress() != 0 && result == 0 && (int)(GetCurrentTimestamp() >> 16) - start < var0) {
        if (!func_ov031_02203b1c()) {
            func_ov031_02200264();
            continue;
        }
        unsigned int length;
        unsigned char* buffer = (unsigned char*)func_ov031_0220357c(&length);
        Struct_ov031_02204368* packet = (Struct_ov031_02204368*)buffer;
        if (length > 0xf0 && packet->type == 2 &&
            arg0 == ((unsigned int)SWAP_NETWORK16_02204368(packet->unknown_4_) << 16 |
                             SWAP_NETWORK16_02204368(packet->unknown_6_)) &&
            !func_ov031_02200824(packet->hardwareAddress, data_ov031_0224ce68)) {
            unsigned char* end;
            unsigned int address = READ_NETWORK32_02204368(packet->unknown_10_);
            end = buffer + length;
            result = 3;
            unsigned char* option = buffer + 0xec;
            if (*option++ == 0x63 && *option++ == 0x82 && *option++ == 0x53 && *option++ == 0x63) {
                int type;
                while (option < end && (type = *option++) != 0xff) {
                    if (type == 0) continue;
                    switch (type) {
                    case 1:
                        data_ov031_0224c980.unknown_1c_ = READ_NETWORK32_02204368(option + 1);
                        break;
                    case 3:
                        data_ov031_0224c980.unknown_2c_ = READ_NETWORK32_02204368(option + 1);
                        break;
                    case 6:
                        if (option[0] < 8) data_ov031_0224c980.unknown_64_ = 0;
                        else data_ov031_0224c980.unknown_64_ = READ_NETWORK32_02204368(option + 5);
                        data_ov031_0224c980.unknown_60_ = READ_NETWORK32_02204368(option + 1);
                        break;
                    case 51:
                        data_ov031_0224c980.unknown_4c_ = READ_NETWORK32_02204368(option + 1);
                        break;
                    case 53:
                        switch (option[1]) {
                        case 2:
                            result = 1;
                            data_ov031_0224c980.unknown_34_ = address;
                            break;
                        case 5:
                            result = 2;
                            data_ov031_0224c980.unknown_50_ = address;
                            break;
                        default:
                            break;
                        }
                        break;
                    case 54:
                        data_ov031_0224c980.unknown_20_ = READ_NETWORK32_02204368(option + 1);
                        break;
                    default:
                        break;
                    }
                    option += option[0] + 1;
                }
            }
        }
        func_ov031_02203670(length);
    }
    return result;
}
