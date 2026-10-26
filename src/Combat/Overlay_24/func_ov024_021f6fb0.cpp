#include <globaldefs.h>

struct Struct_ov024_021f6fb0 { char pad[0x14]; float x; float y; float outX; float outY; };

// USA: func_ov024_021f6fb0
extern "C" ARM int func_ov024_021f6fb0(struct Struct_ov024_021f6fb0* obj) {
    obj->outX = obj->x * 1.3f;
    obj->outY = obj->y * 1.3f;
    return 1;
}
