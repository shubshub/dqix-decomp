#include <globaldefs.h>

struct Struct_ov031_02224f20 {
    unsigned char padding[0x11d];
    unsigned char mode;
};
struct Struct_ov031_02248a0c {
    unsigned short x;
    unsigned short y;
};
extern Struct_ov031_02224f20* data_ov031_02250bfc;
extern const Struct_ov031_02248a0c data_ov031_02248a0c[];
static inline const Struct_ov031_02248a0c* inline_ov031_02224f20(int index) {
    return &data_ov031_02248a0c[index];
}
extern "C" void func_ov031_02224ca4(int, int, int);
extern "C" void func_ov031_02224fa4(int, int);

// USA: func_ov031_02224f20
extern "C" ARM void func_ov031_02224f20(int mode) {
    int index;
    int first = 0;
    int second = 0;
    index = 0;
    int offset = 0;
    data_ov031_02250bfc->mode = mode;
    do {
        func_ov031_02224ca4(mode, index, inline_ov031_02224f20(offset)->y);
        ++index;
        offset += 12;
    } while (index < 4);
    if (mode == 2) first = 1;
    else if (mode == 1) second = 1;
    func_ov031_02224fa4(47, first);
    func_ov031_02224fa4(48, second);
}
