#include <globaldefs.h>
#include "NitroSDK/Memory.h"


struct Struct_ov031_0221aed8 {
    unsigned char data[0xf0];
    unsigned char signature[14];
    unsigned short unknown_fe_;
    unsigned char unknown_100_[0x100];
    unsigned short unknown_200_[256];
};
struct Struct_ov031_0224e6a0 {
    int field_0;
    int unknown_4_;
    int address;
};
extern Struct_ov031_0224e6a0 data_ov031_0224e6a0;
extern unsigned char data_ov031_0224e6ac[];
extern "C" void* func_ov031_0221b8e4(void*);
extern "C" int func_ov031_0221b6f0(int, int, int);
extern "C" int func_ov031_0221b780(int, int, int);
extern "C" int func_ov031_0221b848();
extern "C" void HaltSystem();
extern "C" void func_020d1ba0(unsigned short*, unsigned short);
extern "C" unsigned short func_020d1cc8(const unsigned short*, const unsigned char*, unsigned int);
extern "C" int func_ov031_0221b7fc(int, int, int, int);

// USA: func_ov031_0221aed8
extern "C" ARM int func_ov031_0221aed8(void* storage, Struct_ov031_0221aed8* buffer) {
    int count;
    int address = data_ov031_0224e6a0.address;
    func_ov031_0221b8e4(storage);
    func_020d1ba0(buffer->unknown_200_, 0xa001);
    count = 0;
    do {
        if (func_ov031_0221b6f0(address, 0x100, (int)buffer) == 0) {
            HaltSystem();
            return 0;
        }
        VectorizedInvertedMemcpy(data_ov031_0224e6ac, buffer->signature, 14);
        buffer->unknown_fe_ = func_020d1cc8(buffer->unknown_200_, buffer->data, 0xfe);
        do {
            func_ov031_0221b780(address, 0x100, (int)buffer);
        } while (func_ov031_0221b7fc((int)buffer, address, 0x100, (int)buffer->unknown_100_) == 0);
        count++;
        address += 0x100;
    } while (count < 2);
    return func_ov031_0221b848() != 0;
}
