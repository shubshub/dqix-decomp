#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc *arg0);

struct Struct_0205d81c;
struct Struct_0205d0e0 {
    unsigned char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_[0xc];
    short unknown_bc_;
    short unknown_be_;
};
struct Elem_0205d81c *Window_GetActivePane(struct Struct_0205d81c *s);
int WindowPane_IsOpen(unsigned char *p);

struct Struct_0205a254;
struct Struct_0205a254_2 {
    unsigned char unknown_0_[0x15];
    unsigned char unknown_15_;
};
struct Elem0205a3d0 *SpriteEntryList_Find(struct Container0205a3d0 *c, int key);
void SpriteEntryList_PlayAnimation(struct Container0205a3d0 *c, int key);
void SpriteEntryList_SetPosition(struct Container0205a3d0 *c, int key, short a, short b);

struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(struct Container0205a330 *c, int arg);

extern "C" void SpriteContext_DrawEntries(void *obj);

#if defined(jpn)
enum { Enum_ov002_0215afb8_9340 = 0x22ac, Enum_ov002_0215afb8_3784 = 0xe20, Enum_ov002_0215afb8_6764 = 0x19c4,
       Enum_ov002_0215afb8_7072 = 0x1a68, Enum_ov002_0215afb8_6760 = 0x19c0 };
#else
enum { Enum_ov002_0215afb8_9340 = 0x247c, Enum_ov002_0215afb8_3784 = 0xec8, Enum_ov002_0215afb8_6764 = 0x1a6c,
       Enum_ov002_0215afb8_7072 = 0x1ba0, Enum_ov002_0215afb8_6760 = 0x1a68 };
#endif

namespace {
struct Struct_ov002_0215afb8 {
    unsigned char unknown_0_[4];
    Struct_020e28dc* unknown_4_;
    unsigned char unknown_8_[Enum_ov002_0215afb8_3784 - 8];
    Struct_ov023_021d9c7c unknown_ec8_;
    unsigned char unknown_f84_[Enum_ov002_0215afb8_6760 - Enum_ov002_0215afb8_3784 - sizeof(Struct_ov023_021d9c7c)];
    void* unknown_1a68_;
    Struct_0205a254* unknown_1a6c_;
    unsigned char unknown_1a70_[Enum_ov002_0215afb8_7072 - Enum_ov002_0215afb8_6764 - 4];
    int unknown_1ba0_;
    unsigned char unknown_1ba4_[Enum_ov002_0215afb8_9340 - Enum_ov002_0215afb8_7072 - 4];
    int unknown_247c_;
};
}

// JPN: func_ov002_0215c318
// USA: func_ov002_0215afb8
extern "C" ARM void func_ov002_0215afb8(char *arg0) {
    Struct_ov002_0215afb8* var0 = ((Struct_ov002_0215afb8*)(arg0));
    struct Struct_0205a254_2 *var1;

    if (!(var0->unknown_247c_ & 4)) return;

    struct Elem_0205d81c *elem = Window_GetActivePane(((Struct_0205d81c*)(&state->window)));
    if (elem == NULL) return;
    if (!WindowPane_IsOpen(((unsigned char*)(elem)))) return;
    struct Outer020e28dc *choice = state->choice;
    if (choice == NULL) return;
    if (GetInnerFlagBit0020e28dc(choice)) return;

    short x = (short) (elem->fac * 8);
    short y = (short) (elem->fae * 8);
    x += elem->fbc;
    y += elem->fbe;
    struct Container0205a3d0 *cont = state->entries;
    SpriteEntryList_PlayAnimation(cont, 0);
    e = SpriteEntryList_Find(cont, 0);
    if (e != NULL) {
        e->flags |= 8;
    }
    SpriteEntryList_AdvanceAnimations(((Container0205a330*)(cont)), state->animation);
    SpriteEntryList_SetPosition(cont, 0, x - 8, y - 2);
    SpriteContext_DrawEntries(state->renderer);
}
