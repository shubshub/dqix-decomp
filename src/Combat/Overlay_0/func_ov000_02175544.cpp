#include <globaldefs.h>

struct Struct_0205d81c;
struct Struct_0205d0e0 {
    unsigned char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_[0xbc - 0xb0];
    short unknown_bc_;
    short unknown_be_;
    unsigned char unknown_c0_[0xc4 - 0xc0];
    unsigned char unknown_c4_;
};
Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
int WindowPane_IsOpen(unsigned char*);

struct Struct_0205a254_2 {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    unsigned short unknown_8_;
    char unknown_a_[0x15 - 0xa];
    unsigned char unknown_15_;
    char unknown_16_[0x18 - 0x16];
};

struct Container0205a3d0;
void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);
void SpriteEntryList_SetFirstObject(Container0205a3d0*, int, int);

struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);

extern "C" void SpriteContext_DrawEntries(void*);

// USA: func_ov000_02175544
extern "C" ARM void func_ov000_02175544(unsigned char* arg0) {
#if defined(jpn)
    enum { Enum_ov000_02175544_7538 = 0x1faa, Enum_ov000_02175544_80 = 0x4c };
#else
    enum { Enum_ov000_02175544_7538 = 0x1d72, Enum_ov000_02175544_80 = 0x50 };
#endif
    if (!(*(unsigned short*)(arg0 + Enum_ov000_02175544_7538) & 0x100)) return;

    Elem_0205d81c* elem = Window_GetActivePane((Struct_0205d81c*)(obj + 0x188));
    if (elem == NULL) return;
    if (elem->type_ >= 0x1a) return;
    if (!WindowPane_IsOpen((unsigned char*)elem)) return;

    short var1 = var0->unknown_ac_ * 8;
    short var2 = var0->unknown_ae_ * 8;
    var1 += var0->unknown_bc_;
    var2 += var0->unknown_be_;

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
