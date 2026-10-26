#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void func_0202c848(int arg);
extern "C" int func_020d4aa8(void);
extern "C" unsigned short func_020d4be8(void);

struct Struct_02101680 {
    int field0;
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned char unknown_a_[6];
    unsigned short type;
    unsigned short unknown_12_;
};
extern "C" int func_020d5340(int a0, struct Struct_02101680* ctx);

extern unsigned char data_021015a0[0xc];
extern struct Struct_02101680 data_02101680;
extern int data_02101b80;
extern unsigned char data_02101694[0x20];
extern "C" void func_0202cefc(void);

// USA: func_0202cddc
extern "C" ARM int func_0202cddc(void) {
    int var0 = func_020d4aa8();
    if (var0 == 0x8000) {
        func_0202c848(3);
        return 0;
    }
    if (var0 == 0) {
        func_0202c848(0x16);
        return 0;
    }

    unsigned short var1 = *(unsigned short*)(data_021015a0 + 8);
    if (var1 == 0) {
        unsigned int v = data_02101680.field6;
        unsigned int t = (~v) & (v - 1);
        unsigned int var4;
        asm {
            clz var4, t
        }
        unsigned int k = 32 - var4;
        int pos = k + 1;
        unsigned int bit;
        do {
            pos = pos + 1;
            if ((unsigned int)pos > 0x10) pos = 1;
            bit = 1 << (pos - 1);
        } while ((var0 & bit) == 0);
        data_02101680.field6 = bit;
    } else {
        data_02101680.field6 = (unsigned short)(1 << (var1 - 1));
    }

    data_02101680.field8 = func_020d4be8();
    data_02101680.field0 = (int)&data_02101b80;
    data_02101680.field4 = 0x400;
    data_02101680.type = 1;
    data_02101680.unknown_12_ = 0;
    VectorizedMemset(data_02101694, 0xff, 0x20);

    int r = func_020d5340((int)func_0202cefc, &data_02101680);
    if (r == 2) return 1;
    func_0202c848(r);
    return 0;
}
