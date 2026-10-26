#include <globaldefs.h>

struct Struct_0206e2a0 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};

// USA: func_0206e2a0
extern "C" ARM void func_0206e2a0(struct Struct_0206e2a0* obj, int index) {
    int var0;
    if (index >= 0xCC || index < 0) {
        return;
    }
    var0 = index / 2;
    obj->bits[var0] |= (index % 2) ? 0x80 : 0x8;
}
