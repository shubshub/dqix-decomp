#include <globaldefs.h>

#pragma opt_arithtransformation off

// USA: func_ov023_021f6c90
ARM int inline_ov023_021f6c90(void* base, unsigned int idx1, unsigned int width) {
    char* row;
    int i = 0;
    while (i < 0x80) {
        int var2 = 1;
        row = (char*)base + (idx1 << 4);
        unsigned int j = i;
        unsigned short sb = 0;
        while (sb < width) {
            unsigned int word = *(unsigned int*)(row + (j >> 2) * 4 + 8);
            if (word & (1u << (j & 3))) {
                var2 = 0;
                break;
            }
            j++;
            sb++;
        }
        if (var2) {
            return i;
        }
        i++;
    }
    return -1;
}
