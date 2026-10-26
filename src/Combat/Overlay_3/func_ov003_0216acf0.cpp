#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

#if defined(jpn)
enum { Enum_ov003_0216acf0_1439 = 0x59b };
enum { kRegionValueE4_E0 = 0xe0 };
enum { Enum_ov003_0216acf0_1240 = 0x4d4 };
enum { Enum_ov003_0216acf0_1244 = 0x4d8 };
enum { kRegionValue480_47C = 0x47c };
#else
enum { Enum_ov003_0216acf0_1439 = 0x59f };
enum { kRegionValueE4_E0 = 0xe4 };
enum { Enum_ov003_0216acf0_1240 = 0x4d8 };
enum { Enum_ov003_0216acf0_1244 = 0x4dc };
enum { kRegionValue480_47C = 0x480 };
#endif

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
extern "C" int WindowPane_IsOpen(unsigned char*);

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
extern "C" Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);

extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov003_0216acf0
extern "C" ARM void func_ov003_0216acf0(char* base) {
    if (!(*(unsigned char*)(base + Enum_ov003_0216acf0_1439) & 1)) return;

    Elem_0205d81c* elem = Window_GetActivePane((Struct_0205d81c*)(base + kRegionValueE4_E0));
    if (elem == NULL) return;
    if (!WindowPane_IsOpen((unsigned char*)elem)) return;
    if (*(unsigned char*)((char*)elem + 0xc5) & 0x20) return;

    short a = *(short*)((char*)elem + 0xac);
    short b = *(short*)((char*)elem + 0xae);
    short d = *(short*)((char*)elem + 0xbc);
    short e = *(short*)((char*)elem + 0xbe);

    short x = (short)(d + (short)(a << 3));
    short y = (short)(e + (short)(b << 3));

    Container0205a3d0* cont = *(Container0205a3d0**)(base + Enum_ov003_0216acf0_1240);
    SpriteEntryList_PlayAnimation(cont, 0);

    cont = *(Container0205a3d0**)(base + Enum_ov003_0216acf0_1240);
    Elem0205a3d0* entry = SpriteEntryList_Find(cont, 0);
    if (entry != NULL) {
        *(unsigned char*)((char*)entry + 0x15) |= 8;
    }

    cont = *(Container0205a3d0**)(base + Enum_ov003_0216acf0_1240);
    int arg = *(int*)(base + Enum_ov003_0216acf0_1244);
    SpriteEntryList_AdvanceAnimations((Container0205a330*)cont, arg);

    cont = *(Container0205a3d0**)(base + Enum_ov003_0216acf0_1240);
    entry = SpriteEntryList_Find(cont, 0);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x4) = (short)(x - 8);
        *(short*)((char*)entry + 0x6) = (short)(y - 2);
    }

    SpriteContext_DrawEntries(base + kRegionValue480_47C);
}
