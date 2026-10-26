#include <globaldefs.h>

struct ColorHolder0204bd7c {
    unsigned short color; // 0x0
};

// USA: func_0204bd7c
extern "C" ARM unsigned short func_0204bd7c(struct ColorHolder0204bd7c* obj) {
    unsigned short color = obj->color;
    unsigned short red = color & 0x1f;
    unsigned short green = (color & 0x3e0) >> 5;
    unsigned short blue = (color & 0x7c00) >> 10;
    return 30000 + red * 100 + green * 10 + blue;
}
