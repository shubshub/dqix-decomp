#include <globaldefs.h>

struct Struct_0204bef4 {
    unsigned short color; // 0x0
};

// USA: func_0204bef4
extern "C" ARM int func_0204bef4(struct Struct_0204bef4* obj) {
    unsigned short color = obj->color;
    unsigned short red = color & 0x1f;
    unsigned short green = (color & 0x3e0) >> 5;
    unsigned short blue = (color & 0x7c00) >> 10;
    return 20000 + red * 100 + green * 10 + blue;
}
