#include <globaldefs.h>

struct Struct_0205ba2c;
void InitStruct_0205ba2c(struct Struct_0205ba2c*);

struct Struct_0205bef8 {
    char base[0x30];
    int field30;
    short field34;
    unsigned char field36;
    unsigned char field37;
    unsigned char field38;
    unsigned char field39;
    unsigned char field3a;
    unsigned char pad3b;
    unsigned char field3c;
    unsigned char field3d;
};

// Main, originally Init0205bef8 (USA 0x0205bef8, EUR 0x0205bf08, JPN 0x0205d258)
ARM void GridCursor_Init(struct Struct_0205bef8* s) {
    InitStruct_0205ba2c((struct Struct_0205ba2c*)s);
    s->field30 = 0;
    s->field34 = 0;
    s->field36 = 0;
    s->field37 = 0;
    s->field38 = 0;
    s->field39 = 0x14;
    s->field3a = 0xa;
    s->field3c = 1;
    s->field3d = 1;
}
