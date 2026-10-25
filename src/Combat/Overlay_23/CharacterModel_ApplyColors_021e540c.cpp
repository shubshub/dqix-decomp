#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"
#include "Graphics/CharacterModel.h"
#include "GameState/PartyMember.h"

// The struct tags stay: ItemTable_Find's and ItemRecord_GetPaletteSize's C++ symbols are mangled with them.
struct ItemTable;
struct Obj020de2a4;
// One record of the item table (CharacterModel_Load's ItemRecord).
struct ItemRecord { void* model; };

// What CharacterColors_GetInstance returns.
struct CharacterColors {
    unsigned short hair[10][2];
    unsigned short skin2[8][2];
    unsigned short skin4[8][4];
    unsigned short skin8[8][8];
    unsigned short eyes[16][2];
};

unsigned short (*CharacterColors_GetInstance())[2];
void CharacterModel_GetPartModels(void* vocation, short* models, short* appearance);
ItemRecord* ItemTable_Find(ItemTable* itemTable, int itemId);
int ItemRecord_GetPaletteSize(Obj020de2a4* item, int which, int female);
extern short CharacterModel_skinPaletteParts[];

// Overlay 23, originally func_ov023_021e540c (USA/EUR 0x021e540c, JPN 0x021e55f0)
extern "C" ARM void CharacterModel_ApplyColors(CharacterModel* self) {
    PartyMemberAppearance* appearance = &self->member_->appearance_;
    CharacterColors* colors = (CharacterColors*)CharacterColors_GetInstance();
    unsigned int skin = appearance->skinColor_;
    unsigned int eye = appearance->eyeColor_;
    unsigned int paletteOffset = self->vramStates_[CharacterModelPart_Face].paletteKeyOffset << 3;
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->hair[appearance->hairColor_], paletteOffset + 0x24, 4, false, true);
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->eyes[eye], paletteOffset + 0x28, 4, false, true);
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->skin8[skin], paletteOffset + 0x30, 0x10, false, true);

    short models[10];
    CharacterModel_GetPartModels((void*)self->vocation_, models, &appearance->body_);
    int i = 0;
    int part;
    for (; (part = CharacterModel_skinPaletteParts[i]) >= 0; i++) {
        ItemTable* itemTable = self->itemTable_;
        int modelID = models[part];
        int female = appearance->female_;
        if (itemTable != NULL) {
          VramState* state = &self->vramStates_[part];
          if (state != NULL) {
            ItemRecord* item = ItemTable_Find(itemTable, (short)modelID);
            if (item != NULL && item->model != NULL) {
                int count = ItemRecord_GetPaletteSize((Obj020de2a4*)item, 0, female);
                if (count != 0) {
                    count *= 2;
                    Model3D* model = self->parts_[part].pModel_;
                    if (model != NULL) {
                        NSBXXTex* texture = model->GetTEX0();
                        if (texture != NULL) {
                            int offset = 0x30;
                            unsigned short size = texture->block4NumEightBytes_ << 3;
                            size = (size + 0x1f) & ~0x1f;
                            int reserved = 0x20;
                            if (part == CharacterModelPart_Body) reserved = 0x200;
                            offset -= size - reserved;
                            CharacterColors* table = (CharacterColors*)CharacterColors_GetInstance();
                            if (table != NULL) {
                                const void* data = NULL;
                                unsigned int bytes = count * 2;
                                switch (count) {
                                case 2: data = table->skin2[skin]; break;
                                case 4: data = table->skin4[skin]; break;
                                case 8: data = table->skin8[skin]; break;
                                }
                                if (data != NULL) {
                                    unsigned int destination = self->vramStates_[part].paletteKeyOffset << 3;
                                    destination += offset;
                                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, data, destination, bytes, false, true);
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
