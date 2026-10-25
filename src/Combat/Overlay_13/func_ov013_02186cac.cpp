#include <globaldefs.h>

struct Struct_0205d81c;
struct Struct_0205d0e0 {
    unsigned char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_[0xc];
    short unknown_bc_;
    short unknown_be_;
};
Elem_0205d81c* Window_GetActivePane(Struct_0205d81c*);
int WindowPane_IsOpen(unsigned char*);

struct Container0205a3d0;
void SpriteEntryList_PlayAnimation(Container0205a3d0*, int);
unsigned char* SpriteEntryList_Find(Container0205a3d0*, int);

struct Container0205a330;
void SpriteEntryList_AdvanceAnimations(Container0205a330*, int);

extern "C" void SpriteContext_DrawEntries(void*);

struct Struct_ov013_02186cac {
    char unknown_0_[0x3c];
    void* unknown_3c_;
};

// USA: func_ov013_02186cac
extern "C" ARM void func_ov013_02186cac(void* arg0) {
#if defined(jpn)
    enum { Enum_ov013_02186cac_1724 = 0x644, Enum_ov013_02186cac_56 = 0x34, Enum_ov013_02186cac_1596 = 0x5c8 };
#else
    enum { Enum_ov013_02186cac_1724 = 0x6bc, Enum_ov013_02186cac_56 = 0x38, Enum_ov013_02186cac_1596 = 0x63c };
#endif
    unsigned char* var0 = (unsigned char*)arg0;
    Struct_0205d0e0* var1;
    short var2, var3;
    unsigned char var4;
    Struct_ov013_02186cac* var5;
    Struct_0205a254* var6;
    unsigned char* var7;

    if (*(void**)(var0 + 0x18) == 0) return;
    if (!(var0[Enum_ov013_02186cac_1724] & 1)) return;

    elem = Window_GetActivePane((Struct_0205d81c*)(o + regionalElem));
    if (elem == 0) return;
    if (!WindowPane_IsOpen((unsigned char*)elem)) return;

    var2 = var1->unknown_ac_ * 8;
    var3 = var1->unknown_ae_ * 8;
    var2 += var1->unknown_bc_;
    var3 += var1->unknown_be_;
    var4 = var0[Enum_ov013_02186cac_1596];

    if (var4 != 3 && var4 != 4) {
        var2 = var2 - 8;
        var3 = var3 - 2;
    } else {
        var2 = var2 - 8;
    }

    var5 = *(Struct_ov013_02186cac**)(var0 + 0x18);
    var6 = (Struct_0205a254*)var5->unknown_3c_;
    if (var6 == 0) return;

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
