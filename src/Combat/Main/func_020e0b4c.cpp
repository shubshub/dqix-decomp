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
extern "C" int STD_GetStringLength(const char* s);
extern "C" int GlyphDestination_DrawText(void*, short, short, int, unsigned char, unsigned char);

#if defined(jpn)
extern short data_020ee9e6[];
extern short data_020ee998[];
extern short data_020ee9b2[];
#else
extern short data_020ee864[];
extern short data_020ee87e[];
extern short data_020ee898[];
#endif
extern short data_020ee8b2[];

#if defined(jpn)
enum {
    kLabelStride = 0x24, Enum_020e0b4c_1748 = 0x668,
    kThreeX = 100, kTwoX = 110, kOneX = 120, kOneY = 16,
    kDrawFirst = 10, kDrawSecond = 15
};
#else
enum {
    kLabelStride = 0x48, Enum_020e0b4c_1748 = 0x6d4,
    kThreeX = 116, kTwoX = 120, kOneX = 125, kOneY = 15,
    kDrawFirst = 15, kDrawSecond = 0
};
#endif

// JPN: func_020e2788
// USA: func_020e0b4c
extern "C" ARM void func_020e0b4c(void* obj, void* buffer, int offset, int) {
    struct Struct02020520 arr[13];
#if defined(jpn)
    GlyphDestinationRect_InitArray(arr, 13, data_020ee9e6, data_020ee998, data_020ee9b2, data_020ee8b2);
#else
    GlyphDestinationRect_InitArray(arr, 13, data_020ee864, data_020ee87e, data_020ee898, data_020ee8b2);
#endif
    struct S_b20c localObj;
    GlyphDestination_Clear(&localObj);
    GlyphDestination_SetPixels(&localObj, (int)buffer + offset);
    GlyphDestination_SetRects(&localObj, (int)arr, 13);
    for (int i = 0; i < 3; i++) {
        GlyphDestination_DrawText(&localObj, (short)0xa, (short)(i * 13 + 0x10), (int)((char*)obj + 0x1fc + 0x400 + i * kLabelStride), (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        char* s = (char*)obj + Enum_020e0b4c_1748 + i * 8;
        if (STD_GetStringLength(s) == 3) {
            GlyphDestination_DrawText(&localObj, (short)kThreeX, (short)(i * 13 + 0x10), (int)s, (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        } else if (STD_GetStringLength(s) == 2) {
            GlyphDestination_DrawText(&localObj, (short)kTwoX, (short)(i * 13 + 0x10), (int)s, (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        } else if (STD_GetStringLength(s) == 1) {
            GlyphDestination_DrawText(&localObj, (short)kOneX, (short)(i * 13 + kOneY), (int)s, (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        } else {
            GlyphDestination_DrawText(&localObj, (short)kThreeX, (short)(i * 13 + 0x10), (int)s, (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        }
    }
}
