#include <globaldefs.h>

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

extern "C" void GlyphDestinationRect_InitArray(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
extern "C" void GlyphDestination_Clear(struct S_b20c* obj);
extern "C" void GlyphDestination_SetPixels(void* obj, int value);
extern "C" void GlyphDestination_SetRects(void* obj, int value, unsigned char flag);
extern "C" int Font_GetTextWidth(char*, int);
extern "C" int GlyphDestination_DrawText(void*, short, short, int, unsigned char, unsigned char);

#if defined(jpn)
extern short data_020ee908[];
extern short data_020ee926[];
extern short data_020ee90e[];
extern short data_020ee932[];
enum { kEntryCount = 3 };
#else
extern short data_020ee818[];
extern short data_020ee800[];
extern short data_020ee810[];
extern short data_020ee808[];
enum { kEntryCount = 4 };
#endif

// JPN: func_020e292c
// USA: func_020e0cfc
extern "C" ARM void func_020e0cfc(void* obj, int b, int c, int) {
    struct Struct02020520 arr[kEntryCount];
#if defined(jpn)
    GlyphDestinationRect_InitArray(arr, kEntryCount, data_020ee908, data_020ee926, data_020ee90e, data_020ee932);
#else
    GlyphDestinationRect_InitArray(arr, kEntryCount, data_020ee818, data_020ee800, data_020ee810, data_020ee808);

    int len1 = Font_GetTextWidth((char*)obj + 0x2f4 + 0x400, 0);
    int len2 = Font_GetTextWidth((char*)obj + 0x324 + 0x400, 0);

#endif
    struct S_b20c localObj;
    GlyphDestination_Clear(&localObj);
    GlyphDestination_SetPixels(&localObj, b + c);
    GlyphDestination_SetRects(&localObj, (int)arr, kEntryCount);

#if defined(jpn)
    GlyphDestination_DrawText(&localObj, (short)45, (short)5, (int)((char*)obj + 0x288 + 0x400), (unsigned char)10, (unsigned char)15);
    GlyphDestination_DrawText(&localObj, (short)45, (short)17, (int)((char*)obj + 0x298 + 0x400), (unsigned char)10, (unsigned char)15);
#else
    GlyphDestination_DrawText(&localObj, (short)(0x5f - len1), (short)0x14, (int)((char*)obj + 0x2f4 + 0x400), (unsigned char)0xf, (unsigned char)0);
    GlyphDestination_DrawText(&localObj, (short)(0x5f - len2), (short)0x2c, (int)((char*)obj + 0x324 + 0x400), (unsigned char)0xf, (unsigned char)0);
#endif
}
