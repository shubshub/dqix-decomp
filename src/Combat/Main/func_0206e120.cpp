#include <globaldefs.h>

struct PackedNibbleArray0206e120 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};

// USA: func_0206e120
extern "C" ARM int func_0206e120(struct PackedNibbleArray0206e120* obj, int index) {
    int var0;
    if (index >= 0xCC || index < 0) {
        return 0;
    }
    var0 = index / 2;
    if (index % 2) {
        return (obj->bits[var0] >> 4) & 3;
    }
    return obj->bits[var0] & 3;
}
