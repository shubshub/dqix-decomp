#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Struct_0208becc {
    char pad0[0xbc];
    int handle;              // 0xbc
    char pad1[0x12];         // 0xc0..0xd1
    short unknown_d2_;          // 0xd2
    char pad2[2];            // 0xd4..0xd5
    unsigned char unknown_d6_;  // 0xd6
    char pad3[3];            // 0xd7..0xd9
    unsigned short unknown_da_; // 0xda
    char pad4[1];            // 0xdc
    unsigned char unknown_dd_;  // 0xdd
};

// USA: func_0208becc
extern "C" ARM void func_0208becc(struct Struct_0208becc* obj, int value, unsigned char b) {
    if (value < 0) return;
    if (obj->unknown_d2_ == value) return;
    obj->unknown_d2_ = value;
    obj->unknown_dd_ = b;
    if (obj->handle >= 0) {
        int owner = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(owner))->RemoveTask((int)(obj->handle));
        obj->handle = -1;
    }
    obj->unknown_da_ |= 0x20;
    obj->unknown_d6_ = 0;
}
