#include <globaldefs.h>

struct Struct_ov024_021f6c40 { int pad0[5]; float x; float y; float unknown_1c_; float unknown_20_; };

// USA: func_ov024_021f6c40
extern "C" ARM int func_ov024_021f6c40(struct Struct_ov024_021f6c40* obj) {
    obj->unknown_1c_ = obj->x * 0.5f;
    obj->unknown_20_ = obj->y * 0.5f;
    return 1;
}
