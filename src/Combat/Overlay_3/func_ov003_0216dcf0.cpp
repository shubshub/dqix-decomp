#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0216dcf0_704 = 0x150 };
enum { Enum_ov003_0216dcf0_680 = 0x138 };
enum { Enum_ov003_0216dcf0_4716 = 0x10fc };
#else
enum { Enum_ov003_0216dcf0_704 = 0x2c0 };
enum { Enum_ov003_0216dcf0_680 = 0x2a8 };
enum { Enum_ov003_0216dcf0_4716 = 0x126c };
#endif

struct Struct_0205d0e0 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_0205d81c;
struct Elem_0205d81c* Window_GetActivePane(struct Struct_0205d81c* s);
int WindowPane_IsOpen(unsigned char* obj);

struct Struct_0205c570;
int Window_GetSelectedIndex(struct Struct_0205c570* s);

struct Container0205a3d0;
struct Elem0205a3d0;
void SpriteEntryList_PlayAnimation(struct Container0205a3d0* c, int key);
struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);
void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);

struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(struct Container0205a330* c, int arg);

extern "C" void SpriteContext_DrawEntries(void* obj);

// USA: func_ov003_0216dcf0
extern "C" ARM void func_ov003_0216dcf0(char* obj) {
    GameState* battle = GameState::GetInstance();
    struct Elem_0205d81c* elem = Window_GetActivePane(*(struct Struct_0205d81c**)(obj + 0x1000 + kRegionValue2C0_150));
    if (elem != 0 && WindowPane_IsOpen((unsigned char*)elem) != 0) {
        short y = elem->posY << 3;
        short x = elem->posX;
        short sum = Window_GetSelectedIndex(*(struct Struct_0205c570**)(obj + 0x1000 + kRegionValue2C0_150));
        short row = y + sum * 12;
        struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + kRegionValue2A8_138);
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

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + kRegionValue2A8_138);
    if (cont == 0) return;
    struct Elem0205a3d0* e = SpriteEntryList_Find(cont, 0);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
