#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

#if defined(jpn)
#define data_ov023_021fd68a data_ov023_021fc952
#endif

struct Appearance021e540c {
    short models[10];
    unsigned char female : 1;
    unsigned char skinColor : 3;
    unsigned char eyeColor : 4;
    unsigned char hairColor : 4;
    unsigned char unused : 4;
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

struct PaletteTable021e540c {
    unsigned short hair[10][2];
    unsigned short skin2[8][2];
    unsigned short skin4[8][4];
    unsigned short skin8[8][8];
    unsigned short eyes[16][2];
};

extern "C" unsigned short (*func_02099cac())[2];
extern "C" void func_ov023_021e5fdc(void* arg0, short* arg1, short* arg2);
extern "C" Struct_0201099c_9* func_020dedd0(Struct_0201099c_10* arg0, int arg1);
extern "C" int func_020de2a4(Struct_020730e0_2* arg0, int arg1, int arg2);
extern short data_ov023_021fd68a[];

// Overlay 23, originally func_ov023_021e540c (USA/EUR 0x021e540c, JPN 0x021e55f0)
extern "C" ARM void CharacterModel_ApplyColors(Character021e540c* self) {
    Appearance021e540c* appearance = &self->member->appearance;
    PaletteTable021e540c* colors = (PaletteTable021e540c*)GetVariantShortTable02109928_02099cac();
    unsigned int skin = appearance->skinColor;
    unsigned int eye = appearance->eyeColor;
    unsigned int paletteOffset = self->vramStates[2].palette << 3;
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->hair[appearance->hairColor], paletteOffset + 0x24, 4, false, true);
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->eyes[eye], paletteOffset + 0x28, 4, false, true);
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->skin8[skin], paletteOffset + 0x30, 0x10, false, true);

    short models[10];
    CopyAndClampShorts_021e5fdc((void*)self->vocation, models, appearance->models);
    int i = 0;
    int part;
    for (; (part = data_ov023_021fd68a[i]) >= 0; i++) {
        Container020dedd0* names = self->names;
        int modelID = models[part];
        int female = appearance->female;
        if (names != NULL) {
          VRAMState021e540c* state = &self->vramStates[part];
          if (state != NULL) {
            Element020de650* entry = FindElementByKey020dedd0(names, (short)modelID);
            if (entry != NULL && entry->model != NULL) {
                int count = GetNibbleField020de2a4((Obj020de2a4*)entry, 0, female);
                if (count != 0) {
                    count *= 2;
                    Model3D* model = self->parts[part].pModel_;
                    if (model != NULL) {
                        NSBXXTex* texture = model->GetTEX0();
                        if (texture != NULL) {
                            int offset = 0x30;
                            unsigned short size = texture->block4NumEightBytes_ << 3;
                            size = (size + 0x1f) & ~0x1f;
                            int reserved = 0x20;
                            if (part == 0) reserved = 0x200;
                            offset -= size - reserved;
                            PaletteTable021e540c* table = (PaletteTable021e540c*)GetVariantShortTable02109928_02099cac();
                            if (table != NULL) {
                                const void* data = NULL;
                                unsigned int bytes = count * 2;
                                switch (count) {
                                case 2: data = table->skin2[skin]; break;
                                case 4: data = table->skin4[skin]; break;
                                case 8: data = table->skin8[skin]; break;
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
