#include <globaldefs.h>
#include "NitroSDK/Cache.h"

struct Struct_020200c0_4 {
    int unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
};
struct Struct_ov023_021e6b8c {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};
struct Struct_ov023_021e6b8c_2 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
};
struct Struct_ov023_021e6b8c_3 {
    void* unknown_0_;
    Struct_ov023_021e6b8c_2* unknown_4_;
};
struct Struct_ov023_021e6b8c_4 : Struct_ov023_021e6b8c_3 {
    unsigned char unknown_8_[0x20];
};
struct Struct_ov023_021e6b8c_5 {
    short unknown_0_;
    short unknown_2_;
    const char* unknown_4_;
    const char* unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
};
struct Struct_ov023_021e6b8c_6 {
    Struct_ov023_021e6b8c_5* unknown_0_;
    unsigned char unknown_4_[0x1a];
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned char unknown_20_;
};
struct Struct_ov023_021e6b8c_7 {
    Struct_ov023_021e6b8c_6* unknown_0_;
    unsigned char unknown_4_[0x1364 - 4];
    Struct_ov023_021e6b8c_4* unknown_1364_;
    unsigned char unknown_1368_[8];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    unsigned char unknown_1372_[10];
    void* unknown_137c_;
};
void GlyphDestination_Clear(S_b20c*);
void GlyphDestination_SetPixels(void*, int);
void GlyphDestination_SetRects(void*, int, unsigned char);
extern "C" {
void Keyboard_GetKeySize(int, short*, short*);
void CanvasRect_InitFromSprite(WeightedEntry021e6b8c*, int, SpriteEntry021e6b8c*);
void* memcpy(void*, const void*, unsigned int);
int Font_GetTextWidth(const char*, int);
void Canvas_FillRect(void*, short, short, short, short, short);
int GlyphDestination_DrawText(void*, short, short, const char*, unsigned char, unsigned char);
void LoadToMainObjVRAM(const void*, unsigned int, unsigned int);
}

// USA: func_ov023_021e6b8c
extern "C" ARM void func_ov023_021e6b8c(LabelState021e6b8c* self, unsigned short address, Label021e6b8c* label, int size) {
    if (self->mode != 14 || self->index <= 1 || self->index >= 10) return;
    label = self->owner->selected;
    if (label == 0 || label->index == 3) return;
    SpriteEntry021e6b8c* sprite = &self->sprites[label->index + 15];
    short x;
    short y;
    Keyboard_GetKeySize(label->index, &x, &y);
    WeightedEntry021e6b8c entries[3];
    for (int i = 0; i < 3; i++) {
        entries[i].field_0 = 0;
        entries[i].offset = 0;
        entries[i].field_6 = 0;
        entries[i].width = 0;
        entries[i].height = 0;
    }
    CanvasRect_InitFromSprite(entries, 3, sprite);
    int offset = 0;
    size = 0;
    for (int i = 0; i < 3; i++) {
        entries[i].offset = offset;
        offset += entries[i].width;
        size += (entries[i].width * entries[i].height) >> 1;
    }
    SpriteHeader021e6b8c copy = *sprite;
    address = (unsigned short)(copy.flags->flags & 0x3ff) << 5;
    memcpy(self->buffer, (const void*)(0x6400000 + address), size);
    unsigned char flags = self->owner->flags;
    unsigned char mode = self->owner->mode;
    const char* text = label->text;
    if (label->mode == 0 && (mode != 0 || (flags & 2) != 0)) text = label->alternate;
    int center = (x - Font_GetTextWidth(text, 1)) >> 1;
    S_b20c destination;
    GlyphDestination_Clear(&destination);
    GlyphDestination_SetPixels(&destination, (int)self->buffer);
    GlyphDestination_SetRects(&destination, (int)entries, 3);
    Canvas_FillRect(&destination, 9, 9, (short)(x + 7), (short)(y + 7), 9);
    GlyphDestination_DrawText(&destination, (short)(center + 8), 10, text, 2, 1);
    CleanInvalidateCacheRange(self->buffer, size);
    LoadToMainObjVRAM(self->buffer, address, size);
    CleanCacheRange(self->buffer, size);
}
