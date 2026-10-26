#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0215e2a8_962 = 0x3da };
enum { kRegionValue98_B0 = 0xb0 };
enum { Enum_ov003_0215e2a8_1010 = 0x40a };
enum { Enum_ov003_0215e2a8_2304 = 0x700 };
enum { Enum_ov003_0215e2a8_22 = 0xe6 };
enum { Enum_ov003_0215e2a8_916 = 0x3ac };
enum { kRegionValue358_370 = 0x370 };
#else
enum { Enum_ov003_0215e2a8_962 = 0x3c2 };
enum { kRegionValue98_B0 = 0x98 };
enum { Enum_ov003_0215e2a8_1010 = 0x3f2 };
enum { Enum_ov003_0215e2a8_2304 = 0x900 };
enum { Enum_ov003_0215e2a8_22 = 0x16 };
enum { Enum_ov003_0215e2a8_916 = 0x394 };
enum { kRegionValue358_370 = 0x358 };
#endif

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
extern "C" int WindowPane_IsOpen(unsigned char*);
extern "C" int MessageSystem_GetInstance(void);

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
extern "C" Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);

extern "C" void SpriteEntryList_SetFirstObject(Container0205a3d0*, int, int);
extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov003_0215e2a8
extern "C" ARM void func_ov003_0215e2a8(char* base) {
    if (*(unsigned char*)(base + Enum_ov003_0215e2a8_962) == 0) return;

    Elem_0205d81c* elem = Window_GetActivePane((Struct_0205d81c*)(base + kRegionValue98_B0));
    if (elem == NULL) return;
    if (*(unsigned char*)((char*)elem + 0xc4) != 1) return;
    if (!WindowPane_IsOpen((unsigned char*)elem)) return;
    if (*(unsigned char*)((char*)elem + 0xc5) & 0x20) return;

    short a = *(short*)((char*)elem + 0xac);
    short b = *(short*)((char*)elem + 0xae);
    short d = *(short*)((char*)elem + 0xbc);
    short e = *(short*)((char*)elem + 0xbe);

    short x = (short)(d + (short)((a << 3)));
    short y = (short)(e + (short)((b << 3)));
    x = (short)(x - 8);
    y = (short)(y - 2);

    if (*(unsigned char*)(base + Enum_ov003_0215e2a8_1010) != 0) {
        int f = MessageSystem_GetInstance();
        int v = *(short*)((char*)f + Enum_ov003_0215e2a8_2304 + Enum_ov003_0215e2a8_22);
        x = (short)(x - 2);
        y = (short)(y + (short)(v % 8));
    }

    GameState* battleStruct = GameState::GetInstance();
    Container0205a3d0* cont = *(Container0205a3d0**)(base + Enum_ov003_0215e2a8_916);
    if (cont == NULL) return;

    SpriteEntryList_PlayAnimation(cont, 0);
    Elem0205a3d0* entry = SpriteEntryList_Find(cont, 0);
    if (entry != NULL) {
        *(unsigned char*)((char*)entry + 0x15) |= 8;
    }

    int scaleCount = (int)battleStruct->GetTickCount();
    SpriteEntryList_AdvanceAnimations((Container0205a330*)cont, scaleCount);

    entry = SpriteEntryList_Find(cont, 0);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x4) = x;
        *(short*)((char*)entry + 0x6) = y;
    }

    SpriteEntryList_SetFirstObject(cont, 0, 0x3f);
    SpriteContext_DrawEntries(base + kRegionValue358_370);
}
