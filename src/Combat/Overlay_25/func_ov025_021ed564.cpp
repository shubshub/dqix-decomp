#include <globaldefs.h>

struct Struct_ov025_021ed564 {
    unsigned short ids[0x10];
    short targets[0x10];
    short unknown_40_[0x10];
    short unknown_60_[0x10];
    unsigned short unknown_80_[0x10];
    unsigned char types[0x10];
    int values[0x10];
    char unknown_f0_[0x60];
    unsigned char count;
};

// USA: func_ov025_021ed564
extern "C" ARM int func_ov025_021ed564(Struct_ov025_021ed564* queue, int id, int target, int type, int value, int arg5) {
    if (type >= 6) return -1;
    if (id == 0) return -1;
    unsigned short* p = queue->ids;
    for (int i = 0; i < queue->count; i++, p++) {
        if (*p == id && target == queue->targets[i]) {
            int v = queue->values[i];
            if (v == value && arg5 == queue->unknown_40_[i] && type == queue->types[i]) {
                return (short)i;
            }
        }
    }
    return -1;
}
