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

void GlyphDestinationRect_InitArray(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void GlyphDestination_Clear(struct S_b20c* obj);
void GlyphDestination_SetPixels(void* obj, int value);
void GlyphDestination_SetRects(void* obj, int value, unsigned char flag);
extern "C" int GlyphDestination_DrawText(void*, short, short, int, unsigned char, unsigned char);

#if defined(jpn)
int STD_GetStringLength(const char*);
extern short data_020ee980[];
extern short data_020ee938[];
extern short data_020ee950[];
extern short data_020ee968[];
enum { kEntryCount = 12, kY = 7, kDrawFirst = 10, kDrawSecond = 15 };
#else
extern short data_020ee82c[];
extern short data_020ee848[];
extern short data_020ee856[];
extern short data_020ee83a[];
enum { kEntryCount = 7, kY = 2, kDrawFirst = 15, kDrawSecond = 0 };
#endif

// JPN: func_020e29f0
// USA: func_020e0df8
ARM void SetupWeightedEntriesAndSubmit_020e0df8(void* obj, int b, int c, int) {
    struct Struct02020520 arr[kEntryCount];
#if defined(jpn)
    GlyphDestinationRect_InitArray(arr, kEntryCount, data_020ee980, data_020ee938, data_020ee950, data_020ee968);
#else
    GlyphDestinationRect_InitArray(arr, kEntryCount, data_020ee82c, data_020ee848, data_020ee856, data_020ee83a);
#endif
    struct S_b20c localObj;
    GlyphDestination_Clear(&localObj);
    GlyphDestination_SetPixels(&localObj, b + c);
    GlyphDestination_SetRects(&localObj, (int)arr, kEntryCount);
#if defined(jpn)
    GlyphDestination_DrawText((void*)&localObj, (short)6, (short)kY, (int)((char*)obj + 0x1b4 + 0x400), (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
    int byteLength = STD_GetStringLength((char*)obj + 0x1b4 + 0x400);
    short val = (byteLength / 2) * 10 + 7;
#else
    int ret = GlyphDestination_DrawText((void*)&localObj, (short)6, (short)kY, (int)((char*)obj + 0x1b4 + 0x400), (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
    short val = ret + 9;
#endif
    GlyphDestination_DrawText((void*)&localObj, val, (short)kY, (int)((char*)obj + 0x1f4 + 0x400), (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
}
