#include <globaldefs.h>

struct Struct_ov025_021e120c {
    unsigned char cells[6];
};

extern "C" void func_ov000_0216f82c(Struct_ov025_021e120c* out, const int* cell);

static inline int inline_ov025_021e120c(unsigned char* grid, unsigned int cell) {
    return grid[cell] >= 0xf2 ? 1 : 0;
}

static inline void inline_ov025_021e120c_2(unsigned char* grid, unsigned int cell, unsigned char value) {
    if (cell < 0x51) {
        grid[cell] = value;
    }
}

// USA: func_ov025_021e120c
extern "C" ARM void func_ov025_021e120c(unsigned char* grid, int cell, unsigned char arg2, unsigned char arg3, unsigned char dist) {
    if (arg3 != 0) {
        arg3--;
    }
    if (arg3 == 0) {
        dist++;
    }
    Struct_ov025_021e120c nb;
    Struct_ov025_021e120c tmp;
    int c;
    c = cell;
    func_ov000_0216f82c(&tmp, &c);
    nb = tmp;
    for (int i = 0; i < 6; i++) {
        unsigned char n = nb.cells[i];
        if (n >= 0x51) {
            continue;
        }
        if (arg3 == 0 && inline_ov025_021e120c(grid, n)) {
            continue;
        }
        if (dist < arg2) {
            func_ov025_021e120c(grid, n, arg2, arg3, dist);
        }
        unsigned char cur = grid[n];
        if (dist >= cur && cur != 0) {
            continue;
        }
        if (arg3 != 0) {
            continue;
        }
        inline_ov025_021e120c_2(grid, n, dist);
    }
}
