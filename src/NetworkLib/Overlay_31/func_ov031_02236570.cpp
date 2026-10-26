#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_022364c0 {
    unsigned char unknown_0[0xe7];
    unsigned char active_;
    unsigned char unknown_e8_[7];
    unsigned char flags_;
    unsigned char unknown_f0_[14];
    unsigned short unknown_fe_;
};
struct Struct_ov031_02236570 {
    Struct_ov031_022364c0 slots_[4];
    unsigned char unknown_400_[0xf8];
    unsigned short unknown_4f8_[256];
};
extern Struct_ov031_02236570* data_ov031_02290cfc;
extern "C" unsigned short func_020d1cc8(const unsigned short* table, const unsigned char* data, unsigned int length);
extern "C" void* func_ov031_0223cf4c(int, int);
extern "C" int func_ov031_0221b024(Struct_ov031_02236570*, int*, void*);
extern "C" void func_ov031_0223cf70(void**);

// USA: func_ov031_02236570
extern "C" ARM void func_ov031_02236570(int index) {
    int one = 1;
    unsigned char active = data_ov031_02290cfc->slots_[index].active_;
    int selected = 0;
    int var3 = one << index;
    int dirty[4];
    VectorizedMemset(dirty, 0, sizeof(dirty));
    dirty[index] = one;
    if (index <= 2) {
        if (data_ov031_02290cfc->slots_[0].flags_ & var3) selected = one;
        if (active == 255 && selected != 0) {
            data_ov031_02290cfc->slots_[0].flags_ &= ~var3;
            data_ov031_02290cfc->slots_[1].flags_ &= ~(var3);
            dirty[1] = 1;
            dirty[0] = 1;
        } else if (active != 255 && selected == 0) {
            data_ov031_02290cfc->slots_[0].flags_ |= var3;
            data_ov031_02290cfc->slots_[1].flags_ |= var3;
            dirty[1] = 1;
            dirty[0] = 1;
        }
    }
    int i = 0;
    int offset = 0;
    do {
        if (dirty[i])
            data_ov031_02290cfc->slots_[i].unknown_fe_ = func_020d1cc8(data_ov031_02290cfc->unknown_4f8_, (const unsigned char*)data_ov031_02290cfc + offset, 254);
        i++;
        offset += 256;
    } while (i < 4);
    void* buffer = func_ov031_0223cf4c(256, 32);
    func_ov031_0221b024(data_ov031_02290cfc, dirty, buffer);
    func_ov031_0223cf70(&buffer);
}
