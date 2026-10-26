#include <globaldefs.h>

struct Struct_020e1e24;
extern "C" void func_020e1e24(struct Struct_020e1e24* obj, unsigned short* outX, unsigned short* outY, int index);

struct Struct_020e2604 {
    char pad0[0x10];
    struct Struct_020e1e24* outer;
    char index;
    char pad1[3];
    short x;
    short y;
};

// USA: func_020e2604
extern "C" ARM void func_020e2604(struct Struct_020e2604* self) {
    func_020e1e24(self->outer, (unsigned short*)&self->x, (unsigned short*)&self->y, self->index);
    self->x -= 0x10;
    self->y -= 2;
}
