#include <globaldefs.h>

struct BackgroundGraphics;
extern "C" void Background_ClearMap(struct BackgroundGraphics* obj, void* p);

extern "C" void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);

extern "C" void Background_FlushMap(void* obj, void* p);

struct Struct_ov023_021ecdfc {
    char pad0[0x64];
    char f64[0x400 - 0x64];
    char unknown_400_[0x38];
    unsigned short unknown_438_;
    char unknown_43a_[0x43d - 0x43a];
    unsigned char f43d;
    char unknown_43e_[0];
    short unknown1_43e_;
    short f440;
    short unknown_442_;
    short f444;
    short unknown_446_;
};

// USA: func_ov023_021ecdfc
extern "C" ARM void func_ov023_021ecdfc(struct Struct_ov023_021ecdfc* obj) {
    if ((obj->unknown_438_ & 0x40) != 0 || (obj->unknown_438_ & 0x200) != 0) {
        Background_ClearMap((struct BackgroundGraphics*)&obj->f64, NULL);

        short base = obj->unknown1_43e_;
        short v1 = obj->unknown_442_ + base;
        short v2 = obj->unknown_446_ - base;
        Background_DrawScreen((struct BackgroundGraphics*)&obj->f64, obj->f43d, 0, base, obj->f440, v1, obj->f444, v2, 0xffff);

        Background_FlushMap(&obj->f64, NULL);
    }
}
