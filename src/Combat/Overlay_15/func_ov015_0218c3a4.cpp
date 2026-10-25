#include <globaldefs.h>
#include "World/Object3D.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct ItemTable;
struct Obj020de2a4;

struct Struct_ov005_021556e4
{
    void* unknown_0_;
};

struct Struct_ov005_02155d6c
{
    char unknown_0_[0x68];
    unsigned int unknown_68_;
    char unknown_6c_[4];
};

struct Struct_ov015_0218bcb0_2
{
    Struct_ov005_02155d6c* unknown_0_;
};

struct Struct_ov015_0218c3a4
{
    char unknown_0_[0x4c];
    char unknown_4c_[0x18];
};

struct Struct_02099d34
{
    unsigned short unknown_0_[10][2];
    unsigned short unknown_28_[8][2];
    unsigned short unknown_48_[8][4];
    unsigned short unknown_88_[8][8];
    unsigned short unknown_108_[8][2];
    unsigned short unknown_128_;
};

struct Struct_ov015_0218c03c_2
{
    Struct_ov015_0218c3a4* unknown_0_;
    Struct_ov015_0218bcb0_2* unknown_4_;
    char unknown_8_[0x1c - 0x8];
    unsigned char unknown_1c_;
    char unknown_1d_[3];
    int* unknown_20_;
    Object3D* unknown_24_;
    char unknown_28_[0x3b - 0x28];
    unsigned char unknown_3b_;
    unsigned char unknown_3c_;
    unsigned char unknown_3d_;
    unsigned char unknown_3e_;
};

PartEntry* ItemTable_Find(ItemTable* c, int key);
int ItemRecord_GetPaletteSize(Obj020de2a4* obj, int a, int b);
CharacterColors* CharacterColors_GetInstance();
extern "C" void func_02099d34(void* obj, int a, int b, int c);

// USA: func_ov015_0218c3a4
extern "C" ARM void func_ov015_0218c3a4(Struct_ov015_0218c03c_2* arg0, int arg1)
{
    PartEntry* entry = ItemTable_Find((ItemTable*)&self->viewer_->parts_, (short)self->parts_[part]);
    if (entry == NULL || entry->model_ == NULL)
        return;
    Struct_ov005_02155d6c* var1 = &arg0->unknown_4_->unknown_0_[arg1];
    if (arg0->unknown_1c_ == 1)
    {
        int count = ItemRecord_GetPaletteSize((Obj020de2a4*)entry, 0, self->female_);
        if (count == 0)
            return;
        var2 *= 2;
        NSBXXTex* var3 = arg0->unknown_24_[arg1].pModel_->GetTEX0();
        if (var3 == NULL)
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
            var8 = var7->unknown_28_[arg0->unknown_3e_];
            break;
        case 4:
            var8 = var7->unknown_48_[arg0->unknown_3e_];
            break;
        case 8:
            var8 = var7->unknown_88_[arg0->unknown_3e_];
            break;
        }
        unsigned int var10 = (var1->unknown_68_ & 0xffff) << 3;
        if (var10 != 0 && var9 != 0)
        {
            LockStagedTextureVRAMCopying();
            CleanInvalidateCacheRange(var8, var9);
            MemoryMapTexturePalette();
            LoadToTexturePalette(var8, var10 + var4, var9);
            MemoryUnmapTexturePalette();
            CleanCacheRange(var8, var9);
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
        func_02099d34(var12, var11, var13, 4);
}
