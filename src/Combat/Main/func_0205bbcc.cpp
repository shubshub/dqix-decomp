#include <globaldefs.h>

struct GridCursor;
extern "C" void GridCursor_InitGrid(struct GridCursor*);

struct Struct_0205bbcc {
    char base[0x30];
    int unknown_30_;
    int field34;
    short field38;
    short unknown_3a_;
    int field3c;
    int field40;
    int field44;
    int field48;
    unsigned char field4c;
    unsigned char unknown_4d_;
    unsigned char unknown_4e_;
};

// USA: func_0205bbcc
extern "C" ARM void func_0205bbcc(struct Struct_0205bbcc* s) {
    GridCursor_InitGrid((struct GridCursor*)s);
    s->unknown_30_ = -1;
    s->field34 = 0;
    s->field38 = 0;
    s->unknown_3a_ = 0;
    s->field3c = 0;
    s->field40 = 0;
    s->field44 = 0;
    s->field48 = 0;
    s->field4c = 0;
    s->unknown_4d_ = 0;
    s->unknown_4e_ = 0;
}
