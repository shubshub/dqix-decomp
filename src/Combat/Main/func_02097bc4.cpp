#include <globaldefs.h>

extern "C" int DisableTextureImageVRAMBanks();
extern "C" int DisableTexturePaletteVRAMBanks();
extern "C" int DisableMainBGVRAMBanks();
extern "C" int DisableMainObjVRAMBanks();
extern "C" int DisableSubBGVRAMBanks();
extern "C" int DisableSubObjVRAMBanks();

struct Struct_020978fc {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    char pad18[6];
    unsigned char unknown_1e_;
};

// USA: func_02097bc4
extern "C" ARM void func_02097bc4(struct Struct_020978fc* obj, int flags) {
    obj->unknown_1e_ = (unsigned char)flags;
    if (flags & 1) {
        obj->field0 = DisableTextureImageVRAMBanks();
        obj->field4 = DisableTexturePaletteVRAMBanks();
        obj->field8 = DisableMainBGVRAMBanks();
        obj->fieldC = DisableMainObjVRAMBanks();
    }
    if (flags & 2) {
        obj->field10 = DisableSubBGVRAMBanks();
        obj->field14 = DisableSubObjVRAMBanks();
    }
}
