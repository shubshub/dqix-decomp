#include <globaldefs.h>

struct Struct_ov024_021f6dd4 { int pad0[5]; float x; float y; float unknown_1c_; float unknown_20_; };

// USA: func_ov024_021f6dd4
extern "C" ARM int func_ov024_021f6dd4(struct Struct_ov024_021f6dd4* obj) {
    obj->unknown_1c_ = obj->x * 2.0f;
    obj->unknown_20_ = obj->y * 2.0f;
    return 1;
}
