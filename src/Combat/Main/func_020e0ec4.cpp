#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02000c9c_8;

struct Struct_020200c0_3 {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};

struct Struct_020200c0_4 {
    int unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
};

void GlyphDestinationRect_InitArray(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void GlyphDestination_Clear(struct S_b20c* obj);
void GlyphDestination_SetPixels(void* obj, int value);
void GlyphDestination_SetRects(void* obj, int value, unsigned char flag);
int GameState_GetLanguage(Struct0200fb08*);
extern "C" int GlyphDestination_DrawText(void*, short, short, int, unsigned char, unsigned char);

#if defined(jpn)
extern short data_020ee91a[];
extern short data_020ee92c[];
extern short data_020ee914[];
enum { Enum_020e0ec4_14 = 3 };
#else
extern short data_020ee8e8[];
extern short data_020ee8cc[];
extern short data_020ee904[];
extern const short data_020ee820[];
enum { Enum_020e0ec4_14 = 14 };
#endif
extern short data_020ee920[];

// JPN: func_020e2ad4
// USA: func_020e0ec4
extern "C" ARM void func_020e0ec4(void* arg0, void* arg1, int arg2, int) {
    struct Struct_020200c0_3 var0[Enum_020e0ec4_14];
#if defined(jpn)
    GlyphDestinationRect_InitArray(arr, kEntryCount, data_020ee920, data_020ee91a, data_020ee92c, data_020ee914);
#else
    GlyphDestinationRect_InitArray(arr, kEntryCount, data_020ee920, data_020ee8cc, data_020ee8e8, data_020ee904);
#endif
    struct S_b20c localObj;
    GlyphDestination_Clear(&localObj);
    GlyphDestination_SetPixels(&localObj, (int)buffer + offset);
    GlyphDestination_SetRects(&localObj, (int)arr, kEntryCount);

#if defined(jpn)
    GlyphDestination_DrawText(&localObj, (short)44, (short)18, (int)((char*)obj + 0x680), (unsigned char)10, (unsigned char)15);
#else
    int idx = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
    GlyphDestination_DrawText(&localObj, data_020ee820[idx], (short)6, (int)((char*)obj + 0x2ec + 0x400), (unsigned char)0xf, (unsigned char)0);
#endif
}
