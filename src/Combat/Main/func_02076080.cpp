#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/LoadToVRAM.h"

struct Struct_02047b40_5 {
    int count;
    void* buffer;
};
extern "C" void func_02048090(struct Struct_02047b40_5* obj, int count, SafeAllocator* alloc);

struct Struct_02076080;
extern "C" void func_02076928(struct Struct_02076080* s, int val);

extern "C" void func_02076994(void* ctx, unsigned char* data, unsigned int val, unsigned int w, unsigned int h);

struct Struct_02076080_2 {
    int** f0;
    int** f4;
    int** f8;
    int** fc;
    unsigned short* f10;
    char unknown_14_[4];
    int* f18;
    void** f1c;
    void** f20;
    void** f24;
    char pad28[0xc];
    int f34;
    int unknown_38_;
    int f3c;
    char unknown_40_[0x10];
    int unknown_50_;
    struct Struct_02047b40_5 unknown_54_;
    unsigned short unknown_5c_;
    unsigned char unknown_5e_;
    unsigned char unknown_5f_;
};

// USA: func_02076080
extern "C" ARM int func_02076080(struct Struct_02076080_2* sl, SafeAllocator* sb, unsigned char* data) {
    int var0;
    if (sl->unknown_5e_ == 0) {
        var0 = DISPCNT & 0x300010;
    } else {
        var0 = DISPCNTSUB & 0x300010;
    }

    int bpp;
    switch (var0) {
    case 0:        return 1;
    case 0x10:     bpp = 5; break;
    case 0x100010: bpp = 6; break;
    case 0x200010: bpp = 7; break;
    case 0x300010: bpp = 8; break;
    default: return 1;
    }

    int var2 = 0;
    memcpy(&sl->unknown_5c_, data, 2);
    memcpy(&var2, data + 2, 2);
    data += 4;

    switch (var2) {
    case 3: sl->unknown_50_ = 0; break;
    case 4: sl->unknown_50_ = 1; break;
    default: return 1;
    }

    sl->f10 = (unsigned short*)sb->Allocate(sl->unknown_5c_ * 2);
    sl->f4  = (int**)sb->Allocate(sl->unknown_5c_ * 4);
    sl->f0  = (int**)sb->Allocate(sl->unknown_5c_ * 4);
    sl->f8  = (int**)sb->Allocate(sl->unknown_5c_ * 4);
    sl->fc  = (int**)sb->Allocate(sl->unknown_5c_ * 4);

    unsigned int fp = sl->unknown_38_;
    for (unsigned short i = 0; i < sl->unknown_5c_; i++) {
        unsigned short var5, var6;
        unsigned int cellCount;
        memcpy(&var5, data, 2);
        memcpy(&var6, data + 2, 2);
        memcpy(&cellCount, data + 4, 4);
        sl->f10[i] = (unsigned short)cellCount;
        data += 8;

        sl->f4[i] = (int*)sb->Allocate(cellCount * 4);
        sl->f0[i] = (int*)sb->Allocate(cellCount * 4);
        sl->f8[i] = (int*)sb->Allocate(cellCount * 4);
        sl->fc[i] = (int*)sb->Allocate(cellCount * 4);

        for (int j = 0; j < cellCount; j++) {
            unsigned short var9, var10, var11, var12;
            memcpy(&var9, data, 2);
            memcpy(&var10, data + 2, 2);
            memcpy(&var11, data + 4, 2);
            memcpy(&var12, data + 6, 2);
            unsigned int w = 8u << var11;
            unsigned int h = 8u << var12;

            sl->f8[i][j] = var9;
            data += 8;
            sl->fc[i][j] = var10;

            int* var15 = sl->f4[i];
            if (w == 8 && h == 8) {
                var15[j] = 0;
            } else if (w == 0x10 && h == 0x10) {
                var15[j] = 0x40000000;
            } else if (w == 0x20 && h == 0x20) {
                var15[j] = 0x80000000;
            } else if (w == 0x40 && h == 0x40) {
                var15[j] = 0xc0000000;
            } else if (w == 0x10 && h == 8) {
                var15[j] = 0x4000;
            } else if (w == 0x20 && h == 8) {
                var15[j] = 0x40004000;
            } else if (w == 0x20 && h == 0x10) {
                var15[j] = 0x80004000;
            } else if (w == 0x40 && h == 0x20) {
                var15[j] = 0xc0004000;
            } else if (w == 8 && h == 0x10) {
                var15[j] = 0x8000;
            } else if (w == 8 && h == 0x20) {
                var15[j] = 0x40008000;
            } else if (w == 0x10 && h == 0x20) {
                var15[j] = 0x80008000;
            } else if (w == 0x20 && h == 0x40) {
                var15[j] = 0xc0008000;
            }

            unsigned int pixels = w * h;
            unsigned int size;
            if (var2 == 3) {
                size = pixels >> 1;
            } else {
                size = pixels;
            }
            sl->f0[i][j] = fp >> bpp;
            func_02076994(sl, data, sl->f0[i][j] << bpp, w, h);
            data += size;
            fp += (size + ((1 << bpp) - 1)) & ~((1 << bpp) - 1);
        }
    }

    sl->f34 = fp - sl->unknown_38_;

    unsigned int paletteSize;
    memcpy(&paletteSize, data, 4);
    data += 4;

    if (paletteSize <= 0x10) {
        int var19 = sl->f3c << 5;
        if (sl->unknown_5e_ == 0) {
            LoadToMainObjStandardPalette(data, var19, 0x20);
        } else {
            LoadToSubObjStandardPalette(data, var19, 0x20);
        }
    } else if (paletteSize <= 0x100) {
        int var20 = sl->f3c << 9;
        if (sl->unknown_5e_ == 0) {
            LoadToMainObjStandardPalette(data, var20, 0x200);
        } else {
            LoadToSubObjStandardPalette(data, var20, 0x200);
        }
    } else {
        if (sl->unknown_5e_ == 0) {
            LoadToMainObjStandardPalette(data, 0, paletteSize);
        } else {
            LoadToSubObjStandardPalette(data, 0, paletteSize);
        }
    }

    data += paletteSize * 2;
    memcpy(&sl->unknown_54_.count, data + 0x1e, 4);
    data += 0x22;
    func_02048090(&sl->unknown_54_, sl->unknown_54_.count, sb);

    int count = sl->unknown_54_.count;
    if (sl->unknown_54_.count > 0) {
        for (int k = 0; k < count; k++) {
            memcpy((char*)sl->unknown_54_.buffer + k * 0x1e, data, 0x1e);
            data += 0x1e;
        }

        int var23 = count * 4;
        sl->f18 = (int*)sb->Allocate(var23);
        sl->f1c = (void**)sb->Allocate(var23);
        sl->f20 = (void**)sb->Allocate(var23);
        sl->f24 = (void**)sb->Allocate(var23);

        for (int m = 0; m < count; m++) {
            memcpy(&sl->f18[m], data, 4);
            data += 4;
            int var25 = sl->f18[m] * 4;
            sl->f1c[m] = sb->Allocate(var25);
            sl->f20[m] = sb->Allocate(var25);
            sl->f24[m] = sb->Allocate(var25);
            memcpy(sl->f1c[m], data, var25);
            data += var25;
            memcpy(sl->f20[m], data, var25);
            data += var25;
            memcpy(sl->f24[m], data, var25);
            data += var25;
        }
    }

    sl->unknown_5f_ = 1;
    func_02076928((struct Struct_02076080*)sl, 1);
    return 0;
}
