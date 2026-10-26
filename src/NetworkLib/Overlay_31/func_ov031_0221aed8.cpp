#include <globaldefs.h>
#include "NitroSDK/Memory.h"


struct Struct_ov031_0221aed8 {
    unsigned char unknown_0_[0xf0];
    unsigned char unknown_f0_[14];
    unsigned short unknown_fe_;
    unsigned char unknown_100_[0x100];
    unsigned short unknown_200_[256];
};
struct Struct_ov031_0224e6a0 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};
extern Struct_ov031_0224e6a0 data_ov031_0224e6a0;
extern unsigned char data_ov031_0224e6ac[];
extern "C" void* func_ov031_0221b8e4(void*);
extern "C" int func_ov031_0221b6f0(int, int, int);
extern "C" int func_ov031_0221b780(int, int, int);
extern "C" int func_ov031_0221b848();
extern "C" void HaltSystem();
void GenCrc16Table_020d1ba0(unsigned short*, unsigned short);
extern "C" unsigned short Crc16Compute_020d1cc8(const unsigned short*, const unsigned char*, unsigned int);
int CheckAndCompare_0221b7fc(int, int, int, int);

// USA: func_ov031_0221aed8
extern "C" ARM int func_ov031_0221aed8(void* arg0, Struct_ov031_0221aed8* arg1) {
    int var0;
    int var1 = data_ov031_0224e6a0.unknown_8_;
    func_ov031_0221b8e4(arg0);
    func_020d1ba0(arg1->unknown_200_, 0xa001);
    var0 = 0;
    do {
        if (func_ov031_0221b6f0(address, 0x100, (int)buffer) == 0) {
            HaltSystem();
            return 0;
        }
        VectorizedInvertedMemcpy(data_ov031_0224e6ac, arg1->unknown_f0_, 14);
        arg1->unknown_fe_ = func_020d1cc8(arg1->unknown_200_, arg1->unknown_0_, 0xfe);
        do {
            func_ov031_0221b780(var1, 0x100, (int)arg1);
        } while (func_ov031_0221b7fc((int)arg1, var1, 0x100, (int)arg1->unknown_100_) == 0);
        var0++;
        var1 += 0x100;
    } while (var0 < 2);
    return func_ov031_0221b848() != 0;
}
