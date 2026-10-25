#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define data_ov002_0216d10c data_ov002_0216d790
#define data_ov002_0216d3b0 data_ov002_0216db30
#define data_ov002_0216cb18 data_ov002_0216d120
#define data_ov002_0216cb1c data_ov002_0216d124
#define RG(u, j) (j)
#define OBJ (var0 + 0xe20)
#define PAGES 47
#else
#define RG(u, j) (u)
#define OBJ (var0 + 0x2c8 + 0xc00)
#define PAGES 44
#endif

class Struct_ov002_0215bba8_2 {
public:
    char unknown_0_[0x1bb8];
};

typedef void (Struct_ov002_0215bba8_2::*Type_ov002_0215bba8)(void *buf, int flag);

struct Struct_ov002_0216cb18 {
    int unknown_0_;
    int unknown_4_;
};

extern Type_ov002_0215bba8 data_ov002_0216d10c[PAGES];
extern unsigned int data_ov002_0216d3b0[2];
extern PageFn0215bba8 __ptmf_null;
extern ModePage0215bba8 data_ov002_0216cb18[];
extern ModePage0215bba8 data_ov002_0216cb1c[];

extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" unsigned char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(char *s, unsigned char key);
struct StructA0205d5d0;
void Window_SetPaneText(StructA0205d5d0*, int, int, int, unsigned char);

struct Struct_ov002_0215bba8 {
    char unknown_0_[0x34];
    int unknown_34_;
};
// USA: func_ov002_0215bba8
extern "C" ARM void func_ov002_0215bba8(Struct_ov002_0215bba8_2 *arg0) {
    char *var0 = (char *) arg0;
    int var1   = *(int *) (var0 + 0x1000 + RG(0xbc8, 0xa90));
    if (var1 == 0) {
        return;
    }
    int var2 = 0;
    if (var1 == 2) {
        if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
            Struct_ov002_0215bba8 *var3 = (Struct_ov002_0215bba8 *) OBJ + 1;
            var3--;
            if (var3->unknown_34_ < 0) {
                return;
            }
        }
        var2 = 1;
    }
    memset(*(void **) (var0 + 0x1000 + RG(0xbd0, 0xa98)), 0, RG(0x960, 0x800));
    if (!(data_ov002_0216d3b0[0] & 1)) {
        PageFn0215bba8 nul      = __ptmf_null;
        data_ov002_0216d10c[0]  = nul;
        data_ov002_0216d10c[23] = nul;
        data_ov002_0216d10c[30] = nul;
        data_ov002_0216d10c[36] = nul;
        data_ov002_0216d10c[40] = nul;
        data_ov002_0216d10c[41] = nul;
        data_ov002_0216d10c[42] = nul;
        data_ov002_0216d10c[43] = nul;
        data_ov002_0216d3b0[0] |= 1;
    }
    int var5 = *(int *) (var0 + 0x1000 + RG(0xbb8, 0xa80));
    if (data_ov002_0216d10c[var5] == 0) {
        return;
    }
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci(base + 0x2c8 + 0xc00, (unsigned char) key) != 0) {
        (self->*data_ov002_0216d10c[*(int *) (base + 0x1000 + 0xbb8)])(*(void **) (base + 0x1000 + 0xbd0), hl);
        Window_SetPaneText((StructA0205d5d0*)(base + 0x2c8 + 0xc00), (unsigned char) *(int *) (base + 0x1000 + 0xbb8), (int)(*(void **) (base + 0x1000 + 0xbd0)), 0, 0);
    }
#endif
    if (*(int *) (var0 + 0x1000 + RG(0xbcc, 0xa94)) == 0) {
        return;
    }
    for (int var6 = 0; data_ov002_0216cb18[var6].unknown_0_ >= 0; var6++) {
        if (*(int *) (var0 + 0x1000 + RG(0xbb8, 0xa80)) == data_ov002_0216cb18[var6].unknown_0_) {
            int var7 = data_ov002_0216cb1c[var6].unknown_0_;
            memset(*(void **) (var0 + 0x1000 + RG(0xbd0, 0xa98)), 0, RG(0x960, 0x800));
            if (data_ov002_0216d10c[var7] == 0) {
                break;
            }
#if !defined(jpn)
            if (func_0205d81c(OBJ, var7) == 0) {
                continue;
            }
            (self->*data_ov002_0216d10c[page])(*(void **) (base + 0x1000 + 0xbd0), hl);
            Window_SetPaneText((StructA0205d5d0*)(base + 0x2c8 + 0xc00), (unsigned char) page, (int)(*(void **) (base + 0x1000 + 0xbd0)), 0, 0);
        }
    }
    *(int *) (var0 + 0x1000 + RG(0xbcc, 0xa94)) = 0;
}
