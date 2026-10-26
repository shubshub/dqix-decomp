#include <globaldefs.h>

struct Struct_0205bbcc;
extern "C" void func_0205bbcc(struct Struct_0205bbcc*);
struct GridCursor;
extern "C" void GridCursor_Init(struct GridCursor*);

struct Struct_0205c53c {
    char pad0[0x94];
    unsigned char field94;
    unsigned char unknown_95_;
};

// USA: func_0205c53c
extern "C" ARM void func_0205c53c(struct Struct_0205c53c* s) {
    func_0205bbcc((struct Struct_0205bbcc*)((char*)s + 0x4));
    GridCursor_Init((struct GridCursor*)((char*)s + 0x54));
    s->field94 = 0;
    s->unknown_95_ = 0;
}
