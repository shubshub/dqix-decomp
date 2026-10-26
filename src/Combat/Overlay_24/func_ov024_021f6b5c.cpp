#include <globaldefs.h>

struct Struct_ov024_021f6b5c { int pad0[5]; float x; float y; float unknown_1c_; float unknown_20_; };

// USA: func_ov024_021f6b5c
extern "C" ARM int func_ov024_021f6b5c(struct Struct_ov024_021f6b5c* obj) {
    obj->unknown_1c_ = obj->x * 0.75f;
    obj->unknown_20_ = obj->y * 0.75f;
    return 1;
}
