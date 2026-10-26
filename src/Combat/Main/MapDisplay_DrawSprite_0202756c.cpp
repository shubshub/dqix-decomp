#include <globaldefs.h>

struct Sprite {
    char pad0[0xc];
    int scaleX;
    int scaleY;
    int position[2];
    char pad1[4];
    unsigned short matrixIndex;
    unsigned char firstObject;
    char pad2[3];
    unsigned char priority;
};

enum { kMapDisplaySpriteContextOffset = 0x94, kMapDisplaySpritesOffset = 0xe8 };

extern "C" void SpriteContext_SetSpritePalette(int spriteContext, void* sprite, int palette);
extern "C" void SpriteContext_DrawSprite(void* context, void* sprite);

// Main, originally SetElementFields0202756c (USA 0x0202756c, EUR 0x0202757c, JPN 0x02026ed0)
extern "C" ARM void MapDisplay_DrawSprite(void* display, int x, int y, int spriteIndex,
        unsigned char oamSlot, unsigned char priority, unsigned short palette, unsigned char matrixIndex, int scaleX, int scaleY) {
    struct Sprite* sprite = (struct Sprite*)((char*)display + kMapDisplaySpritesOffset + spriteIndex * 0x28);
    sprite->position[0] = x;
    sprite->position[1] = y;
    sprite->firstObject = oamSlot & 0x7f;
    sprite->priority = priority & 0x3;
    if (palette < 0xf) {
        SpriteContext_SetSpritePalette((int)((char*)display + kMapDisplaySpriteContextOffset), sprite, palette);
    }
    if (matrixIndex < 0x40) {
        sprite->matrixIndex = matrixIndex;
    }
    sprite->scaleX = scaleX;
    sprite->scaleY = scaleY;
    SpriteContext_DrawSprite((char*)display + kMapDisplaySpriteContextOffset, sprite);
}
