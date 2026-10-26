#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_[0xc];
    short unknown_bc_;
    short unknown_be_;
};
extern "C" Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
extern "C" int WindowPane_IsOpen(unsigned char*);

struct Container0205a3d0;
extern "C" void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
extern "C" unsigned char* SpriteEntryList_Find(Container0205a3d0*, int);

struct Container0205a330;
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);

extern "C" void SpriteContext_DrawEntries(void*);

struct Struct_ov013_02186cac {
    char pad0[0x3c];
    void* container;
};

// USA: func_ov013_02186cac
extern "C" ARM void func_ov013_02186cac(void* obj) {
#if defined(jpn)
    enum { Enum_ov013_02186cac_1724 = 0x644, regionalElem = 0x34, Enum_ov013_02186cac_1596 = 0x5c8 };
#else
    enum { Enum_ov013_02186cac_1724 = 0x6bc, regionalElem = 0x38, Enum_ov013_02186cac_1596 = 0x63c };
#endif
    unsigned char* o = (unsigned char*)obj;
    Elem_0205d81c* elem;
    short x, y;
    unsigned char mode;
    Struct_ov013_02186cac* list;
    Container0205a3d0* container;
    unsigned char* entry;

    if (*(void**)(o + 0x18) == 0) return;
    if (!(o[Enum_ov013_02186cac_1724] & 1)) return;

    elem = Window_GetActivePane((Struct_0205d81c*)(o + regionalElem));
    if (elem == 0) return;
    if (!WindowPane_IsOpen((unsigned char*)elem)) return;

    x = elem->unknown_ac_ * 8;
    y = elem->unknown_ae_ * 8;
    x += elem->unknown_bc_;
    y += elem->unknown_be_;
    mode = o[Enum_ov013_02186cac_1596];

    if (mode != 3 && mode != 4) {
        x = x - 8;
        y = y - 2;
    } else {
        x = x - 8;
    }

    list = *(Struct_ov013_02186cac**)(o + 0x18);
    container = (Container0205a3d0*)list->container;
    if (container == 0) return;

    SpriteEntryList_PlayAnimation(container, *(unsigned short*)(o + 0x1c));
    entry = SpriteEntryList_Find(container, *(unsigned short*)(o + 0x1c));
    if (entry != 0) entry[0x15] |= 8;

    SpriteEntryList_AdvanceAnimations((Container0205a330*)container, *(int*)(o + 0x14));

    entry = SpriteEntryList_Find(container, *(unsigned short*)(o + 0x1c));
    if (entry != 0) {
        *(short*)(entry + 4) = x;
        *(short*)(entry + 6) = y;
    }

    SpriteContext_DrawEntries(*(void**)(o + 0x18));
}
