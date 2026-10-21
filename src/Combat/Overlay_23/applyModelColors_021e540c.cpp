#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

#if defined(jpn)
#define data_ov023_021fd68a data_ov023_021fc952
#endif

struct Struct_ov023_021e540c_2 {
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
};

struct Struct_ov023_021e540c_3 {
    char unknown_0_[0x488];
    Struct_ov023_021e540c_2 unknown_488_;
};

struct Struct_ov023_021e540c_4 {
    char unknown_0_[0x68];
    unsigned int unknown_68_0_ : 16;
    unsigned int unknown_6a_0_ : 16;
    unsigned int unknown_6c_;
};

struct Struct_0201099c_10;
struct Struct_020730e0_2;
struct Struct_0201099c_9 { void* unknown_0_; };

struct Struct_ov023_021e540c_5 {
    Object3D unknown_0_[10];
    SafeAllocator unknown_6b8_[10];
    SafeAllocator unknown_780_;
    Struct_ov023_021e540c_4 unknown_794_[10];
    short unknown_bf4_[12];
    Struct_0201099c_10* unknown_c0c_;
    char unknown_c10_[5];
    unsigned char unknown_c15_;
    char unknown_c16_[2];
    Struct_ov023_021e540c_3* unknown_c18_;
};

struct Struct_ov023_021e540c {
    unsigned short unknown_0_[10][2];
    unsigned short unknown_28_[8][2];
    unsigned short unknown_48_[8][4];
    unsigned short unknown_88_[8][8];
    unsigned short unknown_108_[16][2];
};

extern "C" unsigned short (*func_02099cac())[2];
extern "C" void func_ov023_021e5fdc(void* arg0, short* arg1, short* arg2);
extern "C" Struct_0201099c_9* func_020dedd0(Struct_0201099c_10* arg0, int arg1);
extern "C" int func_020de2a4(Struct_020730e0_2* arg0, int arg1, int arg2);
extern short data_ov023_021fd68a[];

// Overlay 23, originally func_ov023_021e540c (USA/EUR 0x021e540c, JPN 0x021e55f0)
extern "C" ARM void applyModelColors(Character021e540c* self) {
    Appearance021e540c* appearance = &self->member->appearance;
    PaletteTable021e540c* colors = (PaletteTable021e540c*)GetVariantShortTable02109928_02099cac();
    unsigned int eye = appearance->eyeColor;
    unsigned int skin = appearance->skinColor;
    unsigned int paletteOffset = self->vramStates[2].palette << 3;
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->hair[appearance->hairColor], paletteOffset + 0x24, 4, false, true);
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->skin[skin], paletteOffset + 0x28, 4, false, true);
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->eyes8[eye], paletteOffset + 0x30, 0x10, false, true);

    short var5[10];
    func_ov023_021e5fdc((void*)arg0->unknown_c15_, var5, var0->unknown_0_);
    int var6 = 0;
    int var7;
    for (; (var7 = data_ov023_021fd68a[var6]) >= 0; var6++) {
        Struct_0201099c_10* var8 = arg0->unknown_c0c_;
        int var9 = var5[var7];
        int var10 = var0->unknown_14_0_;
        if (var8 != NULL) {
          Struct_ov023_021e540c_4* var11 = &arg0->unknown_794_[var7];
          if (var11 != NULL) {
            Struct_0201099c_9* var12 = func_020dedd0(var8, (short)var9);
            if (var12 != NULL && var12->unknown_0_ != NULL) {
                int var13 = func_020de2a4((Struct_020730e0_2*)var12, 0, var10);
                if (var13 != 0) {
                    var13 *= 2;
                    Model3D* var14 = arg0->unknown_0_[var7].pModel_;
                    if (var14 != NULL) {
                        NSBXXTex* var15 = var14->GetTEX0();
                        if (var15 != NULL) {
                            int var16 = 0x30;
                            unsigned short var17 = var15->block4NumEightBytes_ << 3;
                            var17 = (var17 + 0x1f) & ~0x1f;
                            int var18 = 0x20;
                            if (var7 == 0) var18 = 0x200;
                            var16 -= var17 - var18;
                            Struct_ov023_021e540c* var19 = (Struct_ov023_021e540c*)func_02099cac();
                            if (var19 != NULL) {
                                const void* var20 = NULL;
                                unsigned int var21 = var13 * 2;
                                switch (var13) {
                                case 2: var20 = var19->unknown_28_[var2]; break;
                                case 4: var20 = var19->unknown_48_[var2]; break;
                                case 8: var20 = var19->unknown_88_[var2]; break;
                                }
                                if (var20 != NULL) {
                                    unsigned int var22 = arg0->unknown_794_[var7].unknown_68_0_ << 3;
                                    var22 += var16;
                                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, var20, var22, var21, false, true);
                                }
                            }
                        }
                    }
                }
            }
          }
        }
    }
}
