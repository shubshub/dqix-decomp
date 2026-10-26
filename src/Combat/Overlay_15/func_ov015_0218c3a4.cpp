#include <globaldefs.h>
#include "World/Object3D.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct ItemTable;
struct Obj020de2a4;

struct PartEntry
{
    void* model_;
};

struct Struct_ov005_02155d6c
{
    char unk_0[0x68];
    unsigned int unknown_68_;
    char unk_6c[4];
};

struct Struct_ov015_0218bcb0_2
{
    Struct_ov005_02155d6c* states_;
};

struct Struct_ov015_0218c3a4
{
    char unk_0[0x4c];
    char parts_[0x18];
};

struct CharacterColors
{
    unsigned short unknown_0_[10][2];
    unsigned short unknown_28_[8][2];
    unsigned short unknown_48_[8][4];
    unsigned short unknown_88_[8][8];
    unsigned short unknown_108_[8][2];
    unsigned short edge_;
};

struct Struct_ov015_0218c03c_2
{
    Struct_ov015_0218c3a4* viewer_;
    Struct_ov015_0218bcb0_2* slot_;
    char unk_8[0x1c - 0x8];
    unsigned char kind_;
    char unknown_1d_[3];
    int* parts_;
    Object3D* objects_;
    char unk_28[0x3b - 0x28];
    unsigned char female_;
    unsigned char hairColor_;
    unsigned char skinColor_;
    unsigned char eyeColor_;
};

extern "C" PartEntry* ItemTable_Find(ItemTable* c, int key);
extern "C" int ItemRecord_GetPaletteSize(Obj020de2a4* obj, int a, int b);
extern "C" CharacterColors* CharacterColors_GetInstance();
extern "C" void func_02099d34(void* obj, int a, int b, int c);

// USA: func_ov015_0218c3a4
extern "C" ARM void func_ov015_0218c3a4(Struct_ov015_0218c03c_2* self, int part)
{
    PartEntry* entry = ItemTable_Find((ItemTable*)&self->viewer_->parts_, (short)self->parts_[part]);
    if (entry == NULL || entry->model_ == NULL)
        return;
    Struct_ov005_02155d6c* state = &self->slot_->states_[part];
    if (self->kind_ == 1)
    {
        int count = ItemRecord_GetPaletteSize((Obj020de2a4*)entry, 0, self->female_);
        if (count == 0)
            return;
        count *= 2;
        NSBXXTex* texture = self->objects_[part].pModel_->GetTEX0();
        if (texture == NULL)
            return;
        int position = 0x30;
        unsigned short size = ((unsigned short)(texture->block4NumEightBytes_ << 3) + 0x1f) & ~0x1f;
        int start = 0x20;
        if (part == 0)
            start = 0x200;
        position -= size - start;
        CharacterColors* colors = CharacterColors_GetInstance();
        const void* source = NULL;
        int length = count * 2;
        switch (count)
        {
        case 2:
            source = colors->unknown_28_[self->eyeColor_];
            break;
        case 4:
            source = colors->unknown_48_[self->eyeColor_];
            break;
        case 8:
            source = colors->unknown_88_[self->eyeColor_];
            break;
        }
        unsigned int offset = (state->unknown_68_ & 0xffff) << 3;
        if (offset != 0 && length != 0)
        {
            LockStagedTextureVRAMCopying();
            CleanInvalidateCacheRange(source, length);
            MemoryMapTexturePalette();
            LoadToTexturePalette(source, offset + position, length);
            MemoryUnmapTexturePalette();
            CleanCacheRange(source, length);
            UnlockStagedTextureVRAMCopying();
        }
        return;
    }
    int colors = ItemRecord_GetPaletteSize((Obj020de2a4*)entry, 1, self->female_);
    Model3D* model = self->objects_[part].pModel_;
    unsigned char color = self->eyeColor_;
    if (part == 4)
        func_02099d34(model, colors, color, 0x10);
    else
        func_02099d34(model, colors, color, 4);
}
