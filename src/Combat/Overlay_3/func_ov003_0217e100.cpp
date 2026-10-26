#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue90_8C = 0x8c };
enum { Enum_ov003_0217e100_120 = 0x74 };
enum { kRegionValue3C_38 = 0x38 };
#else
enum { kRegionValue90_8C = 0x90 };
enum { Enum_ov003_0217e100_120 = 0x78 };
enum { kRegionValue3C_38 = 0x3c };
#endif

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);

extern "C" int WindowPane_IsOpen(unsigned char*);

struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
extern "C" Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);

extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov003_0217e100
extern "C" ARM void func_ov003_0217e100(void* obj) {
    GameState* battleStruct = GameState::GetInstance();
    void* sub = *(void**)((char*)obj + kRegionValue90_8C);
    Elem_0205d81c* elem = Window_GetActivePane((Struct_0205d81c*)sub);
    if (elem == NULL) return;
    if (!WindowPane_IsOpen((unsigned char*)elem)) return;

    sub = *(void**)((char*)obj + kRegionValue90_8C);
    short a = *(short*)((char*)elem + 0xae);
    short c = *(short*)((char*)elem + 0xac);
    int field68 = *(int*)((char*)sub + 0x68);
    short d = a << 3;

    int e = Window_GetSelectedIndex((Struct_0205c570*)sub);
    short g = (short)e - field68 * 6;
    short var9 = (short)((int)g * 13 + d);

    Container0205a3d0* cont = *(Container0205a3d0**)((char*)obj + Enum_ov003_0217e100_120);
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
        *(short*)((char*)entry + 0x4) = (short)((int)c << 3) - 4;
        *(short*)((char*)entry + 0x6) = var9 + 2;
    }

    SpriteContext_DrawEntries((char*)obj + kRegionValue3C_38);
}
