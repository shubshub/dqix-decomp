#include <globaldefs.h>

struct Struct_0205faf4_13 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};

// USA: func_0206e2dc
extern "C" ARM int func_0206e2dc(struct Struct_0205faf4_13* obj, int index) {
    int mask;
    if (index >= 0xCC || index < 0) {
        return 0;
    }
    mask = (index % 2) ? 0x80 : 0x8;
    return mask & obj->bits[index / 2];
}
