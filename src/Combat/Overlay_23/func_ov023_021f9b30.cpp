#include <globaldefs.h>

struct Struct_ov004_02153e20 {
    char pad[0x20];
    short* cells;
    unsigned short width;
    unsigned short height;
};

// USA: func_ov023_021f9b30
extern "C" ARM int func_ov023_021f9b30(struct Struct_ov004_02153e20* self, short val, unsigned int x, unsigned int y) {
    if (self->cells == NULL) {
        return 0;
    }
    if (!(self->width > x && self->height > y)) {
        return 0;
    }
    self->cells[x * self->height + y] = val;
    return 1;
}
