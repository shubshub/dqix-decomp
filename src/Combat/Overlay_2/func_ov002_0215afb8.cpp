#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc *o);

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_[0xc];
    short unknown_bc_;
    short unknown_be_;
};
extern "C" struct Elem_0205d81c *Window_GetActivePane(struct Struct_0205d81c *s);
extern "C" int WindowPane_IsOpen(unsigned char *p);

struct Container0205a3d0;
struct Elem0205a3d0 {
    unsigned char pad0[0x15];
    unsigned char flags;
};
extern "C" struct Elem0205a3d0 *SpriteEntryList_Find(struct Container0205a3d0 *c, int key);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0 *c, int key);
extern "C" void SpriteEntryList_SetPosition(struct Container0205a3d0 *c, int key, short a, short b);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330 *c, int arg);

extern "C" void SpriteContext_DrawEntries(void *obj);

#if defined(jpn)
enum { Enum_ov002_0215afb8_9340 = 0x22ac, WindowOffset = 0xe20, EntryListOffset = 0x19c4,
       Enum_ov002_0215afb8_7072 = 0x1a68, Enum_ov002_0215afb8_6760 = 0x19c0 };
#else
enum { Enum_ov002_0215afb8_9340 = 0x247c, WindowOffset = 0xec8, EntryListOffset = 0x1a6c,
       Enum_ov002_0215afb8_7072 = 0x1ba0, Enum_ov002_0215afb8_6760 = 0x1a68 };
#endif

namespace {
struct Struct_ov002_0215afb8 {
    unsigned char unknown0[4];
    Struct_020e28dc* choice;
    unsigned char unknown8[WindowOffset - 8];
    CreationWindow window;
    unsigned char unknown_f84_[Enum_ov002_0215afb8_6760 - WindowOffset - sizeof(CreationWindow)];
    void* renderer;
    Container0205a3d0* entries;
    unsigned char unknown_1a70_[Enum_ov002_0215afb8_7072 - EntryListOffset - 4];
    int animation;
    unsigned char unknown_1ba4_[Enum_ov002_0215afb8_9340 - Enum_ov002_0215afb8_7072 - 4];
    int flags;
};
}

// JPN: func_ov002_0215c318
// USA: func_ov002_0215afb8
extern "C" ARM void func_ov002_0215afb8(char *obj) {
    Struct_ov002_0215afb8* state = ((Struct_ov002_0215afb8*)(obj));
    struct Elem0205a3d0 *e;

    if (!(state->flags & 4)) return;

    struct Elem_0205d81c *elem = Window_GetActivePane(((Struct_0205d81c*)(&state->window)));
    if (elem == NULL) return;
    if (!WindowPane_IsOpen(((unsigned char*)(elem)))) return;
    struct Struct_020e28dc *choice = state->choice;
    if (choice == NULL) return;
    if (func_020e28dc(choice)) return;

    short x = (short) (elem->unknown_ac_ * 8);
    short y = (short) (elem->unknown_ae_ * 8);
    x += elem->unknown_bc_;
    y += elem->unknown_be_;
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
