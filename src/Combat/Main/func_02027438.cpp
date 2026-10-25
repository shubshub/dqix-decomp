#include <globaldefs.h>

class Struct_02012de8;

FlagWord02046708* GlobalFlags_GetInstance();
bool TestFlags02046708(FlagWord02046708* flags, unsigned int mask);

#define TILE_PHASE02027438(v) ((v) < 0 ? (v) % 8 + 8 : (v) % 8)

struct Struct_0202343c_4 {
    char unknown_0_[0x14];
    int unknown_14_;
    char unknown_18_[0x44 - 0x18];
    int unknown_44_;
    int unknown_48_;
};

// USA: func_02027438  (semantic: UpdateSubBG0ScrollForMode02027438)
extern "C" ARM void func_02027438(struct ScrollState02027438* state) {
    if (TestFlags02046708(GlobalFlags_GetInstance(), 0x41)) {
        return;
    }
    switch (arg0->unknown_14_) {
    case 0: {
        int var0 = arg0->unknown_44_;
        int var1 = TILE_PHASE02027438(var0);
        int var2 = arg0->unknown_48_;
        int var3 = TILE_PHASE02027438(var2);
        *(volatile unsigned int*)0x4001010 =
            ((var1 + 0x80) & 0x1ff) | (((var3 + 0x20) << 16) & 0x1ff0000);
        break;
    }
    case 2:
    case 3: {
        int var4 = arg0->unknown_48_;
        int var5 = TILE_PHASE02027438(var4);
        *(volatile unsigned int*)0x4001010 = ((var5 + 0x20) << 16) & 0x1ff0000;
        break;
    }
    case 4: {
        int var6 = arg0->unknown_48_;
        int var7 = TILE_PHASE02027438(var6);
        *(volatile unsigned int*)0x4001010 = ((0x20 - var7) << 16) & 0x1ff0000;
        break;
    }
    default:
        *(volatile unsigned int*)0x4001010 = 0;
        break;
    }
}
