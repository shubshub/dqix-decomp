#include <globaldefs.h>

struct Struct_0205bbcc;
void Init0205bbcc(struct Struct_0205bbcc*);
struct GridCursor;
void GridCursor_Init(struct GridCursor*);

struct Struct_0205c53c {
    char pad0[0x94];
    unsigned char field94;
    unsigned char field95;
};

// USA: func_0205c53c
ARM void InitChannelPair0205c53c(struct Struct_0205c53c* s) {
    Init0205bbcc((struct Struct_0205bbcc*)((char*)s + 0x4));
    GridCursor_Init((struct GridCursor*)((char*)s + 0x54));
    s->field94 = 0;
    s->field95 = 0;
}
