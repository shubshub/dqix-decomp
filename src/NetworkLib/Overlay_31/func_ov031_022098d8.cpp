#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_022098d8 {
    char unknown_0_[0x1d4];
    void* resource;
    char unknown_1d8_[0x10c];
    char unknown_2e4_[8];
    char unknown_2ec_[0x168];
    unsigned char enabled;
    unsigned char state;
    unsigned char pending;
    char unknown_457_[0x155];
    unsigned char unknown_5ac_;
    char unknown_5ad_[0x277];
    unsigned char* packet;
    unsigned int unknown_828_;
    unsigned int unknown_82c_;
};
extern "C" unsigned int func_ov031_0220940c(Struct_ov031_022098d8*, unsigned char*);
extern "C" void func_ov031_02208b78(Struct_ov031_022098d8*, unsigned char*);
extern "C" void func_ov031_0220911c(Struct_ov031_022098d8*, unsigned char*);
extern "C" void func_ov031_02208940(Struct_ov031_022098d8*, unsigned char*);
extern "C" void func_ov031_0220871c(Struct_ov031_022098d8*, unsigned char*);
extern "C" void func_ov031_02209310(Struct_ov031_022098d8*, unsigned char*);
extern "C" void func_ov031_022098ac(void*, int, int);
extern void (*data_ov031_0224c9c0)(unsigned char*);

// USA: func_ov031_022098d8
extern "C" ARM void func_ov031_022098d8(Struct_ov031_022098d8* work, unsigned char* packet) {
    unsigned char state = work->state;
    if (state == 9) {
        data_ov031_0224c9c0(packet);
        return;
    }
    unsigned char* var1;
    unsigned int length = (packet[3] << 8) + packet[4] + 5;
    unsigned int type = packet[0];
    if ((((unsigned char)(state + 0xf9) <= 1) && type != 21) || (type == 21 && length > 7)) {
        length = func_ov031_0220940c(work, packet);
        state = work->state;
        if (state == 9) {
            data_ov031_0224c9c0(packet);
            return;
        }
    }
    var1 = packet + 5;
    length -= 5;
    switch (type) {
    case 20:
        if (!work->resource) work->state = 9;
        else {
            VectorizedMemset(work->unknown_2e4_, 0, 8);
            work->state = 7;
        }
        break;
    case 21:
        if (var1[0] == 2) work->state = 9;
        break;
    case 22:
        do {
            int var4 = var1[0];
            unsigned int middle = var1[2] << 8;
            unsigned int var6 = (var1[1] << 16) + middle + var1[3];
            var1 += 4;
            switch (var4) {
            case 1:
                if (work->enabled && state == 0) func_ov031_02208b78(work, var1);
                break;
            case 16:
                func_ov031_0220911c(work, var1);
                break;
            case 2:
                func_ov031_02208940(work, var1);
                break;
            case 11:
                func_ov031_0220871c(work, var1);
                work->unknown_5ac_ = 0;
                break;
            case 13:
                work->unknown_5ac_ = 1;
                break;
            case 14:
                work->state = 4;
                break;
            case 20:
                func_ov031_02209310(work, var1);
                break;
            default:
                work->state = 9;
                break;
            }
            func_ov031_022098ac(work, (int)(var1 - 4), var6 + 4);
            var1 += var6;
            length -= var6 + 4;
            if (!length) break;
            state = work->state;
        } while (state != 9);
        break;
    case 23:
        work->packet = packet;
        work->unknown_82c_ = 5;
        work->unknown_828_ = length + 5;
        work->pending = 1;
        return;
    default:
        work->state = 9;
        break;
    }
    data_ov031_0224c9c0(packet);
}
