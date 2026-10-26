#include <globaldefs.h>

struct Struct_ov024_021f6e54 { char pad[0x14]; float x; float y; float outX; float outY; };

// USA: func_ov024_021f6e54
extern "C" ARM int func_ov024_021f6e54(struct Struct_ov024_021f6e54* obj) {
    obj->outX = obj->x * 0.3f;
    obj->outY = obj->y * 0.3f;
    return 1;
}
