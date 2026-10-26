#include <globaldefs.h>

struct Struct_0204ae44 {
    short width;   // 0x0
    short height;  // 0x2
    char unknown_4_[8];  // 0x4
    void* buffer;  // 0xc
};

extern "C" void func_0204ae7c(struct Struct_0204ae44* obj, int palette, int arg2, int arg3, int width, int height);

// USA: func_0204ae44
extern "C" ARM void func_0204ae44(struct Struct_0204ae44* obj, int palette) {
    if (obj->buffer != NULL) {
        func_0204ae7c(obj, palette, 0, 0, obj->width, obj->height);
    }
}
