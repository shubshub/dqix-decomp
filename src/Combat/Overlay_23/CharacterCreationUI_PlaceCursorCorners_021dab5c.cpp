#include <globaldefs.h>

#if defined(jpn)
#include "Resource/CharacterCreationUI.h"
#include "Graphics/SpriteAffineTransform.h"

extern "C" int GridCursor_GetCount(void*);
extern "C" void SpriteContext_DrawSprite(SpriteContext0205ac40*, B174Outer*);

// Overlay 23, originally func_ov023_021dab5c (USA/EUR 0x021dab5c, JPN 0x021db3c8)
extern "C" ARM void CharacterCreationUI_PlaceCursorCorners(CharacterCreationUI* self, int x, int y, int width, int height) {
    int var0 = height << 12;
    int fx = x << 12;
    int var2 = y << 12;
    int minX, maxX, var5, var6;
    if (self->state == 1) {
        int var7 = fx + (width << 12);
        int var8 = var2 + var0;
        minX = fx - 0x7000;
        var5 = var2 - 0x7000;
        maxX = var7 - 0x1000;
        var6 = var8 - 0x1000;
        if (GridCursor_GetCount(&self->navigation) == 8 && self->navigation.rows == 1) {
            minX = fx - 0x4000;
            var5 = var2 - 0x4000;
            maxX = var7 - 0x4000;
            var6 = var8 - 0x4000;
        }
    } else {
        int var9 = fx + (width << 12);
        int var10 = var2 + var0;
        minX = fx - 0x4000;
        var5 = var2 - 0x4000;
        maxX = var9 - 0x4000;
        var6 = var10 - 0x4000;
    }
    fix32_t* position = self->subSprites[21].position;
    position[0] = minX;
    position[1] = var5;
    position = self->subSprites[22].position;
    position[0] = maxX;
    position[1] = var5;
    position = self->subSprites[23].position;
    position[0] = minX;
    position[1] = var6;
    position = self->subSprites[24].position;
    position[0] = maxX;
    position[1] = var6;
    for (int i = 0; i < 4; ++i)
        SpriteContext_DrawSprite(self->subSpriteContext, &self->subSprites[i + 21]);
}
#else
extern "C" int GridCursor_GetCount(void* obj);
extern "C" void SpriteContext_DrawSprite(void* dst, void* entry);

// USA: CharacterCreationUI_PlaceCursorCorners
extern "C" ARM void CharacterCreationUI_PlaceCursorCorners(void* obj, int a1, int a2, int a3, int a4) {
    char* o = (char*)obj;
    int var14 = a4 << 12;
    int fx = a1 << 12;
    int var16 = a2 << 12;
    int minX, var18, maxX, var20;

    if (*(signed char*)(o + 0xc58) == 1) {
        int var21 = fx + (a3 << 12);
        int var22 = var16 + var14;
        minX = fx - 0x7000;
        var18 = var16 - 0x7000;
        maxX = var21 - 0x1000;
        var20 = var22 - 0x1000;
        if (GridCursor_GetCount(o + 0xbec) == 8 && *(int*)(o + 0xbf8) == 1) {
            minX = fx - 0x4000;
            var18 = var16 - 0x4000;
            maxX = var21 - 0x4000;
            var20 = var22 - 0x4000;
        }
    } else {
        int var23 = fx + (a3 << 12);
        int var24 = var16 + var14;
        minX = fx - 0x4000;
        var18 = var16 - 0x4000;
        maxX = var23 - 0x4000;
        var20 = var24 - 0x4000;
    }

    char* dst = *(char**)(o + 0x7e8);
    *(int*)(dst + 0x35c) = minX;
    *(int*)(dst + 0x360) = var18;
    *(int*)(dst + 0x384) = maxX;
    *(int*)(dst + 0x388) = var18;
    *(int*)(dst + 0x3ac) = minX;
    *(int*)(dst + 0x3b0) = var20;
    *(int*)(dst + 0x3d4) = maxX;
    *(int*)(dst + 0x3d8) = var20;

    int j;
    for (j = 0; j < 4; j++) {
        SpriteContext_DrawSprite(*(void**)(o + 0x7e4), dst + (j + 0x15) * 0x28);
    }
}
#endif
