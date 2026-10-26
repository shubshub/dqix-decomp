#include <globaldefs.h>

struct Struct_0204ae44 {
    short width;
    short height;
    char unknown_4_[8];
    unsigned short* buffer;
};

// USA: func_0204ae7c
extern "C" ARM void func_0204ae7c(struct Struct_0204ae44* obj, short palette, short arg2, short arg3, short width, short height) {
    unsigned short* buffer = obj->buffer;
    if (buffer == NULL) {
        return;
    }
    unsigned short pal = palette & 0xF;
    pal = pal << 12;
    short var2 = arg2 + width;
    short var3 = arg3 + height;
    short pitch = obj->width;
    short y = arg3;
    unsigned short* p;
    while (y < var3) {
        p = buffer + pitch * y + arg2;
        short x = arg2;
        while (x < var2) {
            p[0] = p[0] & 0xFFF;
            p[0] = p[0] | pal;
            p++;
            x = x + 1;
        }
        y += 1;
    }
}
