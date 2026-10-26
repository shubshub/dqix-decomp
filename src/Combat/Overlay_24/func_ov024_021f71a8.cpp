#include <globaldefs.h>

struct Struct_ov024_021f71a8 { int pad0[5]; float x; float y; float unknown_1c_; float unknown_20_; };

// USA: func_ov024_021f71a8
extern "C" ARM int func_ov024_021f71a8(struct Struct_ov024_021f71a8* obj) {
    obj->unknown_1c_ = obj->x * 1.5f;
    obj->unknown_20_ = obj->y * 1.5f;
    return 1;
}
