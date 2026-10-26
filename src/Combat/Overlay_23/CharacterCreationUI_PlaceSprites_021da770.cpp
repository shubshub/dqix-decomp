#include "Resource/CreationEnums.h"
#include <globaldefs.h>

#if defined(jpn)
#include "Resource/CharacterCreationUI.h"
#include "Graphics/SpriteAffineTransform.h"

extern "C" void SpriteContext_DrawSprite(SpriteContext0205ac40*, B174Outer*);
extern "C" void CharacterCreationUI_PlaceCursorCorners(CharacterCreationUI*, int, int, int, int);

// Overlay 23, originally func_ov023_021da770 (USA/EUR 0x021da770, JPN 0x021daf74)
extern "C" ARM void CharacterCreationUI_PlaceSprites(CharacterCreationUI* self) {
    if (!(self->flags & CreationFlag_HideButtons)) {
        if ((self->state != 9 || self->step < 1) && self->state != 11 &&
            !(self->flags & CreationFlag_NameRejected)) {
            fix32_t* position = self->subSprites[7].position;
            position[0] = 0xe000;
            position[1] = 0xa9000;
            SpriteContext_DrawSprite(self->subSpriteContext, &self->subSprites[7]);
            position = self->subSprites[6].position;
            position[0] = 0x19000;
            position[1] = 0xa9000;
            SpriteContext_DrawSprite(self->subSpriteContext, &self->subSprites[6]);
            position = self->subSprites[8].position;
            position[0] = 0x3b000;
            position[1] = 0xa9000;
            SpriteContext_DrawSprite(self->subSpriteContext, &self->subSprites[8]);
            position = self->subSprites[9].position;
            position[0] = 0x98000;
            position[1] = 0xa9000;
            SpriteContext_DrawSprite(self->subSpriteContext, &self->subSprites[9]);
            position = self->subSprites[10].position;
            position[0] = 0xd2000;
            position[1] = 0xa9000;
            SpriteContext_DrawSprite(self->subSpriteContext, &self->subSprites[10]);
        }
    }
    for (int i = 0; i < 8; ++i) {
        if (i > self->furthestState[self->sex] - 1) break;
        int x = (i * 16 + 0x78) << 12;
        if (self->state == 9) {
            if (self->step >= 1 && self->step != 0xff)
                self->subSprites[i + 11].palette = 11;
        } else if (self->state == 11) {
            self->subSprites[i + 11].palette = 11;
        } else if (i == self->state - 1) {
            self->subSprites[i + 11].palette = 9;
        } else {
            self->subSprites[i + 11].palette = 10;
        }
        fix32_t* position = self->subSprites[i + 11].position;
        position[0] = x;
        position[1] = 0x8000;
        SpriteContext_DrawSprite(self->subSpriteContext, &self->subSprites[i + 11]);
    }
    if (self->resourceStep == 1) return;
    int index = -1;
    bool handled = false;
    switch (self->state) {
    case 2: case 3: case 4: case 5: case 6: case 7:
        index = 20;
        if (self->state == 2) index = 19;
    case 1: case 8:
        handled = true;
        break;
    }
    if (index >= 0) {
        short x = self->lastCursorX;
        short y = self->lastCursorY;
        fix32_t* position = self->subSprites[index].position;
        position[0] = x << 12;
        position[1] = y << 12;
        SpriteContext_DrawSprite(self->subSpriteContext, &self->subSprites[index]);
    }
    if (!handled || (self->flags & CreationFlag_NameRejected)) return;
    CharacterCreationUI_PlaceCursorCorners(self, self->cursorX, self->cursorY,
                      self->cursorWidth, self->cursorHeight);
}
#else
extern "C" int SpriteContext_DrawSprite(void*, void*);
extern "C" void CharacterCreationUI_PlaceCursorCorners(void*, int, int, int, int);

// USA: CharacterCreationUI_PlaceSprites  (semantic: ConfigureEntryPositions_021da770)
extern "C" ARM void CharacterCreationUI_PlaceSprites(void* obj) {
    char* base = (char*)obj;
    char* ctx = *(char**)(base + 0x7e4);
    int flags = *(int*)(base + 0xd9c);
    char* arr = *(char**)(base + 0x7e8);
    if (!(flags & CreationFlag_HideButtons)) {
        int var13 = *(signed char*)(base + 0xc00 + 0x58);
        int var14 = *(int*)(base + 0xd9c);
        if ((var13 != 9 || *(unsigned char*)(base + 0xc59) < 1) &&
            var13 != 0xb && !(var14 & 0x400000)) {
            char* e;
            e = arr + 0x118;
            *(int*)(e + 0x14) = 0xe000;
            *(int*)(e + 0x18) = 0xa9000;
            SpriteContext_DrawSprite(ctx, e);

            e = arr + 0xf0;
            *(int*)(e + 0x14) = 0x15000;
            *(int*)(e + 0x18) = 0xa9000;
            SpriteContext_DrawSprite(ctx, e);

            e = arr + 0x140;
            *(int*)(e + 0x14) = 0x3b000;
            *(int*)(e + 0x18) = 0xa9000;
            SpriteContext_DrawSprite(ctx, e);

            e = arr + 0x168;
            *(int*)(e + 0x14) = 0x8e000;
            *(int*)(e + 0x18) = 0xa9000;
            SpriteContext_DrawSprite(ctx, e);

            e = arr + 0x190;
            *(int*)(e + 0x14) = 0xc8000;
            *(int*)(e + 0x18) = 0xa9000;
            SpriteContext_DrawSprite(ctx, e);
        }
    }

    int i;
    for (i = 0; i < 8; i++) {
        unsigned char idx = *(unsigned char*)(base + 0xda3);
        int limit = *(signed char*)(base + idx + 0xd00 + 0xa0);
        if (i > limit - 1) break;

        int val = (i * 0x10 + 0x78) << 12;
        char* e = arr + (i + 11) * 0x28;
        int sb = *(signed char*)(base + 0xc00 + 0x58);
        int type = 10;
        if (sb == 9) {
            unsigned char var23 = *(unsigned char*)(base + 0xc59);
            if (var23 >= 1 && var23 != 0xff) type = 11;
        } else if (sb == 0xb) {
            type = 11;
        } else if (i == sb - 1) {
            type = 9;
        }
        *(unsigned char*)(e + 0x25) = (unsigned char)type;
        *(int*)(e + 0x14) = val;
        *(int*)(e + 0x18) = 0x8000;
        SpriteContext_DrawSprite(ctx, e);
    }

    if (*(unsigned char*)(base + 0xd94) == 1) return;

    int var24 = *(signed char*)(base + 0xc00 + 0x58);
    int idx2 = -1;
    int handled = 0;
    switch (var24) {
    case 2: case 3: case 4: case 5: case 6: case 7:
        idx2 = 0x14;
        if (var24 == 2) idx2 = 0x13;
    case 1: case 8:
        handled = 1;
        break;
    default:
        break;
    }

    if (idx2 >= 0) {
        char* e = arr + idx2 * 0x28;
        short var28 = *(short*)(base + 0xc00 + 0x54);
        short var29 = *(short*)(base + 0xc00 + 0x56);
        *(int*)(e + 0x14) = var28 << 12;
        *(int*)(e + 0x18) = var29 << 12;
        SpriteContext_DrawSprite(ctx, e);
    }

    if (!handled) return;
    if (*(int*)(base + 0xd9c) & CreationFlag_NameRejected) return;

    short s52 = *(short*)(base + 0xc00 + 0x52);
    short s4c = *(short*)(base + 0xc00 + 0x4c);
    short s4e = *(short*)(base + 0xc00 + 0x4e);
    short s50 = *(short*)(base + 0xc00 + 0x50);
    CharacterCreationUI_PlaceCursorCorners(obj, s4c, s4e, s50, s52);
}
#endif
