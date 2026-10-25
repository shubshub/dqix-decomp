#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue3C2_3DA = 0x3da };
enum { kRegionValue98_B0 = 0xb0 };
enum { kRegionValue3F2_40A = 0x40a };
enum { kRegionValue900_700 = 0x700 };
enum { kRegionValue16_E6 = 0xe6 };
enum { kRegionValue394_3AC = 0x3ac };
enum { kRegionValue358_370 = 0x370 };
#else
enum { kRegionValue3C2_3DA = 0x3c2 };
enum { kRegionValue98_B0 = 0x98 };
enum { kRegionValue3F2_40A = 0x3f2 };
enum { kRegionValue900_700 = 0x900 };
enum { kRegionValue16_E6 = 0x16 };
enum { kRegionValue394_3AC = 0x394 };
enum { kRegionValue358_370 = 0x358 };
#endif

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
int WindowPane_IsOpen(unsigned char*);
int MessageSystem_GetInstance(void);

struct Container0205a3d0;
struct Elem0205a3d0;
void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);

struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);

void SpriteEntryList_SetFirstObject(Container0205a3d0*, int, int);
extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov003_0215e2a8
ARM void UpdateEntryAndScale_0215e2a8(char* base) {
    if (*(unsigned char*)(base + kRegionValue3C2_3DA) == 0) return;

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

    if (*(unsigned char*)(base + kRegionValue3F2_40A) != 0) {
        int f = MessageSystem_GetInstance();
        int v = *(short*)((char*)f + kRegionValue900_700 + kRegionValue16_E6);
        x = (short)(x - 2);
        y = (short)(y + (short)(v % 8));
    }

    GameState* battleStruct = GameState::GetInstance();
    Container0205a3d0* cont = *(Container0205a3d0**)(base + kRegionValue394_3AC);
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
