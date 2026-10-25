#include <globaldefs.h>

struct Element0202756c {
    char pad0[0xc];
    int fieldC;
    int field10;
    int field14;
    int field18;
    char pad1[4];
    unsigned short field20;
    unsigned char field22;
    char pad2[3];
    unsigned char field26;
};

void SetBitfield0205afb0(int a, void* b, int c);
extern "C" void SpriteContext_DrawSprite(void* a, void* b);

// USA: func_0202756c
ARM void SetElementFields0202756c(void* obj, int p1, int p2, int idx,
        unsigned char p5, unsigned char p6, unsigned short p7, unsigned char p8, int p9, int p10) {
    struct Element0202756c* elem = (struct Element0202756c*)((char*)obj + 0xe8 + idx * 0x28);
    elem->field14 = p1;
    elem->field18 = p2;
    elem->field22 = p5 & 0x7f;
    elem->field26 = p6 & 0x3;
    if (p7 < 0xf) {
        SetBitfield0205afb0((int)((char*)obj + 0x94), elem, p7);
    }
    if (p8 < 0x40) {
        elem->field20 = p8;
    }
    elem->fieldC = p9;
    elem->field10 = p10;
    SpriteContext_DrawSprite((char*)obj + 0x94, elem);
}
