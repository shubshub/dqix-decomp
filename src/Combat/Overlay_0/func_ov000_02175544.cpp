#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short x_;
    short y_;
    unsigned char unknown_b0_[0xbc - 0xb0];
    short unknown_bc_;
    short unknown_be_;
    unsigned char unknown_c0_[0xc4 - 0xc0];
    unsigned char type_;
};
extern "C" Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
extern "C" int WindowPane_IsOpen(unsigned char*);

struct Elem0205a3d0 {
    char pad0[4];
    short x_;
    short y_;
    unsigned short key_;
    char padA[0x15 - 0xa];
    unsigned char flags_;
    char pad16[0x18 - 0x16];
};

struct Container0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
extern "C" Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);
extern "C" void SpriteEntryList_SetFirstObject(Container0205a3d0*, int, int);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);

extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov000_02175544
extern "C" ARM void func_ov000_02175544(unsigned char* obj) {
#if defined(jpn)
    enum { flagOffset = 0x1faa, byte14 = 0x4c };
#else
    enum { flagOffset = 0x1d72, byte14 = 0x50 };
#endif
    if (!(*(unsigned short*)(obj + flagOffset) & 0x100)) return;

    Elem_0205d81c* elem = Window_GetActivePane((Struct_0205d81c*)(obj + 0x188));
    if (elem == NULL) return;
    if (elem->type_ >= 0x1a) return;
    if (!WindowPane_IsOpen((unsigned char*)elem)) return;

    short x = elem->x_ * 8;
    short y = elem->y_ * 8;
    x += elem->unknown_bc_;
    y += elem->unknown_be_;

    Container0205a3d0* container = *(Container0205a3d0**)(obj + 0x174);
    SpriteEntryList_PlayAnimation(container, 0);
    Elem0205a3d0* entry = SpriteEntryList_Find(container, 0);
    if (entry != NULL) entry->flags_ |= 8;

    SpriteEntryList_AdvanceAnimations((Container0205a330*)container, *(int*)(obj + 0x94c));

    entry = SpriteEntryList_Find(container, 0);
    if (entry != NULL) {
        entry->x_ = x - 8;
        entry->y_ = y - 2;
    }

    SpriteEntryList_SetFirstObject(container, 0, byte14);
    SpriteContext_DrawEntries(obj + 0x11c);
}
