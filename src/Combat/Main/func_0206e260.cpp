#include <globaldefs.h>

struct PackedNibbleArray0206e260 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};

// USA: func_0206e260
extern "C" ARM int func_0206e260(struct PackedNibbleArray0206e260* obj, int index) {
    int mask;
    if (index >= 0xCC || index < 0) {
        return 0;
    }
    mask = (index % 2) ? 0x40 : 0x4;
    return mask & obj->bits[index / 2];
}
