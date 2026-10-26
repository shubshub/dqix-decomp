#include <globaldefs.h>

struct Struct_ov024_021f6b8c { char pad[0x14]; float x; float y; float outX; float outY; };

// USA: func_ov024_021f6b8c
extern "C" ARM int func_ov024_021f6b8c(struct Struct_ov024_021f6b8c* obj) {
    obj->outX = obj->x * 1.25f;
    obj->outY = obj->y * 1.25f;
    return 1;
}
