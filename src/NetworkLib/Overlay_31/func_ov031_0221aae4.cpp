#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern signed char* data_ov031_0224a2dc;

// USA: func_ov031_0221aae4
extern "C" ARM int func_ov031_0221aae4(unsigned char* source, unsigned int length, char* output, unsigned int capacity) {
    unsigned int padding = length % 3 ? 4 : 0;
    unsigned int var1 = padding + length / 3 * 4;
    if (!output) return var1;
    if (capacity < var1) return -1;
    int var2;
    unsigned char* end = source + length;
    char* cursor = output;
    if (source != end) do {
        int remaining = end - source;
        int bits = remaining * 8;
        var2 = bits / 6 + (bits % 6 != 0);
        if (remaining >= 3) remaining = 3;
        unsigned char group[3];
        VectorizedMemset(group, 0, 3);
        VectorizedInvertedMemcpy(source, group, remaining);
        cursor[0] = data_ov031_0224a2dc[group[0] >> 2];
        if (var2 < 2) cursor[1] = '*';
        else cursor[1] = data_ov031_0224a2dc[((group[0] << 4) & 0x3f) | (group[1] >> 4)];
        if (var2 < 3) cursor[2] = '*';
        else cursor[2] = data_ov031_0224a2dc[((group[1] << 2) & 0x3f) | (group[2] >> 6)];
        if (var2 < 4) cursor[3] = '*';
        else cursor[3] = data_ov031_0224a2dc[group[2] & 0x3f];
        source += remaining;
        cursor += 4;
    } while (source != end);
    return cursor - output;
}
