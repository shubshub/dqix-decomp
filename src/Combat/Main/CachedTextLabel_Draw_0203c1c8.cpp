#include <globaldefs.h>

struct CachedTextTable;
extern CachedTextTable* data_02105244;

// How a label's x is used
enum {
    TextAlignment_Left = 0,         // x is the left edge
    TextAlignment_Right = 1,        // x is the right edge
    TextAlignment_Center = 2,       // x is the centre
    TextAlignment_ScreenCenter = 3  // centred on the screen, x ignored
};
enum { kScreenCenterX = 0x80 };

struct Struct0203c1c8 {
#if defined(jpn)
    short textSlots[10];
#endif
    int x;
    int y;
#if defined(jpn)
    int lineHeight;
    int characterAdvance;
#endif
    int paletteOffset;
    int alignment;
    int priority;
#if defined(jpn)
    signed int affineIndex : 16;
    unsigned int unknown32 : 8;
    unsigned int unknown33 : 8;
    int affineMode;
#else
    short entryIndex;
#endif
};

#if defined(jpn)
extern "C" int CachedTextLabel_GetWidth(const Struct0203c1c8* text);
extern "C" void CachedTextTable_DrawText(CachedTextTable* cache, int count, const short* slots, int affineMode,
                            int priority, int affineIndex, int x, int y,
                            int paletteOffset, int characterAdvance, int lineHeight);
#else
extern "C" ARM unsigned char CachedTextLabel_GetWidth(char* label);
extern "C" void CachedTextTable_DrawText(void* table, short entryIndex, int priority, int x, int y, int palette);
#endif

// USA: CachedTextLabel_Draw
// JPN: func_0203bd44
// Main, originally AdjustAndDispatchEntry0203c1c8 (USA 0x0203c1c8, EUR 0x0203c1d8, JPN 0x0203bd44)
#if defined(jpn)
extern "C" ARM void CachedTextLabel_Draw(Struct0203c1c8* label, int count) {
#else
extern "C" ARM void CachedTextLabel_Draw(Struct0203c1c8* label) {
#endif
    if (data_02105244 == NULL) return;

#if defined(jpn)
    int width = CachedTextLabel_GetWidth(label);
#else
    unsigned char width = CachedTextLabel_GetWidth((char*)label);
#endif
    int halfWidth = width >> 1;
    int x = label->x;
    int y = label->y;
    int alignment = label->alignment;

    switch (alignment) {
        case TextAlignment_Right: x -= width; break;
        case TextAlignment_Center: x -= halfWidth; break;
        case TextAlignment_ScreenCenter: x = kScreenCenterX - halfWidth; break;
    }

#if defined(jpn)
    CachedTextTable_DrawText(data_02105244, count, label->textSlots, label->affineMode,
                  label->priority, label->affineIndex, x, y,
                  label->paletteOffset, label->characterAdvance, label->lineHeight);
#else
    CachedTextTable_DrawText(data_02105244, label->entryIndex, label->priority, x, y, label->paletteOffset);
#endif
}
