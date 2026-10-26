#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct Struct_020b07c0_2 {
    int f0;
    int f4;
    unsigned int f8;
    const void* f0c;
};

struct Struct_020b07c0 {
    int f0;
    int f4;
    char pad8[0x18];
};

extern "C" void func_020b035c(char* base, int index, int value);

// USA: func_020b07c0
extern "C" ARM void func_020b07c0(Struct_020b07c0_2* res, int arg1, int arg2, Struct_020b07c0* out) {
    const void* data = res->f0c;
    unsigned int len = res->f8;

    CleanInvalidateCacheRange(data, len);

    switch (arg2) {
    case 1:
        if (res->f4) {
            MemoryMapMainObjExtendedPalette();
            LoadToMainObjExtendedPalette(data, arg1, len);
            MemoryUnmapMainObjExtendedPalette();
        } else {
            LoadToMainObjStandardPalette(data, arg1, len);
        }
        break;
    case 2:
        if (res->f4) {
            MemoryMapSubObjExtendedPalette();
            LoadToSubObjExtendedPalette(data, arg1, len);
            MemoryUnmapSubObjExtendedPalette();
        } else {
            LoadToSubObjStandardPalette(data, arg1, len);
        }
        break;
    case 0:
        MemoryMapTexturePalette();
        LoadToTexturePalette(data, arg1, len);
        MemoryUnmapTexturePalette();
        break;
    }

    out->f0 = res->f0;
    out->f4 = res->f4;
    func_020b035c((char*)out, arg2, arg1);
}
