#include <globaldefs.h>

struct Struct_0205bd04;
extern "C" int func_0205bd04(struct Struct_0205bd04*);
struct GridCursor;
extern "C" int GridCursor_GetSelectedIndex(struct GridCursor*);

struct Struct_0205c570 {
    char pad0[0x50];
    unsigned char unknown_50_;
    char unknown_51_[0x94 - 0x51];
    unsigned char field94;
    unsigned char unknown_95_;
};

// USA: func_0205c570
extern "C" ARM int func_0205c570(struct Struct_0205c570* s) {
    int result = -1;
    if (s->field94 != 0 && s->unknown_50_ != 0) {
        result = func_0205bd04((struct Struct_0205bd04*)((char*)s + 0x4));
    }
    if (s->unknown_95_ == 0) {
        return result;
    }
    return GridCursor_GetSelectedIndex((struct GridCursor*)((char*)s + 0x54));
}
