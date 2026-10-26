#include <globaldefs.h>

struct Struct_ov031_0220d8f4 {
    char padding[0x2264];
    unsigned int mask;
};
extern Struct_ov031_0220d8f4* data_ov031_0224e53c;

// USA: func_ov031_0220d8f4
extern "C" ARM unsigned short func_ov031_0220d8f4(int start) {
    int var0 = 0;
    unsigned int mask = data_ov031_0224e53c->mask;
    int candidate = start;
    do {
        if (mask & (1 << (candidate % 13 + 1))) break;
        var0++;
        candidate++;
    } while (var0 < 13);
    return (start + var0) % 13 + 1;
}
