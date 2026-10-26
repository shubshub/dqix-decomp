#include <globaldefs.h>
#include "Combat/MapDisplay.h"
#include "std_library_functions.h"

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
extern "C" ARM void* __clear(void* dst, int count);
extern char data_020ef6b6;
extern "C" int GlyphDestination_DrawText(void* selector, int weight, int mode, char* buf, int a, int b);

#if defined(jpn)
extern short data_020e790a[6], data_020e7916[6], data_020e78f2[6], data_020e78fe[6];
extern "C" int STD_GetStringLength(const char* text);

extern "C" ARM void func_02023218(MapDisplay* obj, char* buffer, int offset, unsigned int capacity) {
    Struct02020520 entries[6];
    S_b20c selector;
    GlyphDestinationRect_InitArray(entries, 6, data_020e790a, data_020e7916, data_020e78f2, data_020e78fe);
    GlyphDestination_Clear(&selector);
    GlyphDestination_SetPixels(&selector, (int)(buffer + offset));
    GlyphDestination_SetRects(&selector, (int)entries, 6);
    GlyphDestination_DrawText(&selector, 14, 3, obj->GetMapNameText(), 10, 15);
    GlyphDestination_DrawText(&selector, (short)(STD_GetStringLength(obj->GetMapNameText()) / 2 * 10 + 15), 3, obj->GetLevelLabelText(), 10, 15);
}
#else
// USA: func_02023218
extern "C" ARM void func_02023218(char* obj, char* buffer, int offset) {
    short a[21];
    short b[21];
    short c[21];
    short d[21];
    struct Struct02020520 arr[21];
    struct S_b20c sel;
    char buf[0x100];
    int i;
    int weight;
    int v;

    __clear(b, 0x2a);
    for (i = 0; i < 0x15; i++) {
        a[i] = i * 8;
        c[i] = 8;
        d[i] = 0x10;
    }
    GlyphDestinationRect_InitArray(arr, 0x15, a, b, c, d);

    v = *(int*)(obj + 0xbe4);
    if (v > 0x98) {
        weight = -*(int*)(obj + 0xbe8);
    } else {
        weight = (0x98 - v) >> 1;
    }

    GlyphDestination_Clear(&sel);
    GlyphDestination_SetPixels(&sel, (int)(buffer + offset));
    GlyphDestination_SetRects(&sel, (int)arr, 0x15);

    __clear(buf, 0x100);
    sprintf(buf, &data_020ef6b6, obj + 0x5b4, obj + 0x5f4);

    GlyphDestination_DrawText(&sel, (short)weight, 3, buf, 0xf, 0);
}

#endif
