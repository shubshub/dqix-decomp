#include <globaldefs.h>
#include "NitroSDK/Memory.h"

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

extern "C" void func_020ca390(int, void*, unsigned int);
extern "C" void func_ov031_0221bfe8(void*);
extern "C" void* func_ov031_0221b8e4(void*);
extern "C" void func_ov031_02236570(int);

struct Struct_ov031_022364c0 { unsigned char pad[0xe7]; unsigned char unknown_e7_; unsigned char unknown_e8_[8]; unsigned char key[14]; unsigned char unknown_fe_[2]; };
struct Struct_ov031_022364c0_2 { Struct_ov031_022364c0 slots[4]; };
extern Struct_ov031_022364c0_2* data_ov031_02290cfc;

// USA: func_ov031_022364c0
extern "C" ARM void func_ov031_022364c0() {
    func_020ca390(0, data_ov031_02290cfc, 0x400);
    int var0 = 0;
    do {
        data_ov031_02290cfc->slots[var0].unknown_e7_ = 0xff;
        var0++;
    } while (var0 < 3);
    unsigned char buffer[20];
    func_ov031_0221bfe8(buffer);
    void* key = func_ov031_0221b8e4(buffer);
    unsigned int offset;
    int i = 0;
    offset = 0;
    do {
        Struct_ov031_022364c0* slot = (Struct_ov031_022364c0*)((char*)data_ov031_02290cfc + offset);
        VectorizedInvertedMemcpy(key, slot->key, 14);
        i++;
        offset += 0x100;
    } while (i < 2);
    int j = 0;
    do {
        func_ov031_02236570(j);
        j++;
    } while (j < 4);
}
