#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct Struct_020b08b8_3 {
    int f0;
    int f4;
    unsigned int f8;
    const unsigned char* f0c;
};

struct Struct_020b08b8 {
    unsigned short count;
    unsigned short pad2;
    const unsigned short* table;
};

struct Struct_020b08b8_2 {
    int f0;
    int f4;
    int arr[3];
};

extern "C" void func_020b035c(char* base, int index, int value);

// USA: func_020b08b8
extern "C" ARM void func_020b08b8(Struct_020b08b8_3* res, Struct_020b08b8* arg1, int base, int arg3,
                                  Struct_020b08b8_2* out) {
    unsigned int size = (res->f0 == 3) ? 0x20 : 0x200;
    unsigned short count = arg1->count;
    unsigned int dst;
    const unsigned char* data;
    unsigned int src;
    unsigned short i = 0;

    if (count != 0) {
        do {
            data = res->f0c;
            unsigned int idx = arg1->table[i];
            dst = size * i;
            src = size * idx;
            CleanInvalidateCacheRange(data, res->f8);
            switch (arg3) {
            case 1:
                if (res->f4) {
                    MemoryMapMainObjExtendedPalette();
                    LoadToMainObjExtendedPalette(data + dst, base + src, size);
                    MemoryUnmapMainObjExtendedPalette();
                } else {
                    LoadToMainObjStandardPalette(data + dst, base + src, size);
                }
                break;
            case 2:
                if (res->f4) {
                    MemoryMapSubObjExtendedPalette();
                    LoadToSubObjExtendedPalette(data + dst, base + src, size);
                    MemoryUnmapSubObjExtendedPalette();
                } else {
                    LoadToSubObjStandardPalette(data + dst, base + src, size);
                }
                break;
            case 0:
                MemoryMapTexturePalette();
                LoadToTexturePalette(data + dst, base + src, size);
                MemoryUnmapTexturePalette();
                break;
            }
            i++;
        } while (i < count);
    }

    out->f0 = res->f0;
    out->f4 = res->f4;
    func_020b035c((char*)out, arg3, base);
}
