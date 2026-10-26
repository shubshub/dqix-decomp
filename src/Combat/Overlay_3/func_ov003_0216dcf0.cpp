#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue2C0_150 = 0x150 };
enum { Enum_ov003_0216dcf0_680 = 0x138 };
enum { kRegionValue126C_10FC = 0x10fc };
#else
enum { kRegionValue2C0_150 = 0x2c0 };
enum { Enum_ov003_0216dcf0_680 = 0x2a8 };
enum { kRegionValue126C_10FC = 0x126c };
#endif

struct Elem_0205d81c {
    char pad0[0xac];
    short posX;
    short unknown_ae_;
};

struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
extern "C" int WindowPane_IsOpen(unsigned char* obj);

struct Struct_0205c570;
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov003_0216dcf0
extern "C" ARM void func_ov003_0216dcf0(char* obj) {
    GameState* battle = GameState::GetInstance();
    struct Elem_0205d81c* elem = Window_GetActivePane(*(struct Struct_0205d81c**)(obj + 0x1000 + kRegionValue2C0_150));
    if (elem != 0 && WindowPane_IsOpen((unsigned char*)elem) != 0) {
        short y = elem->unknown_ae_ << 3;
        short x = elem->posX;
        short sum = Window_GetSelectedIndex(*(struct Struct_0205c570**)(obj + 0x1000 + kRegionValue2C0_150));
        short row = y + sum * 12;
        struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + Enum_ov003_0216dcf0_680);
        if (cont == 0) return;
        SpriteEntryList_PlayAnimation(cont, 0);
        struct Elem0205a3d0* e = SpriteEntryList_Find(cont, 0);
        if (e != 0) {
            *(unsigned char*)((char*)e + 0x15) |= 8;
        }
        SpriteEntryList_AdvanceAnimations((struct Container0205a330*)cont, battle->GetTickCount());
        SpriteEntryList_SetPosition(cont, 0, (short)(x * 8) - 4, row + 2);
        SpriteContext_DrawEntries(obj + kRegionValue126C_10FC);
        return;
    }

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + Enum_ov003_0216dcf0_680);
    if (cont == 0) return;
    struct Elem0205a3d0* e = SpriteEntryList_Find(cont, 0);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
