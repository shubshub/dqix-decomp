#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

struct Struct_020839dc { unsigned char pad[IS_JPN ? 0x878 : 0x910]; unsigned char bytes[9]; };
// USA: func_020839dc
extern "C" ARM int func_020839dc(struct Struct_020839dc* s, unsigned char* out, int max) {
    int var0;
    int bit;
    int count;
    count = 0;
    for (var0 = 0; var0 < 9; var0++) {
        if (s->bytes[var0] == 0) {
            continue;
        }
        for (bit = 0; bit < 8; bit++) {
            if (s->bytes[var0] & (1 << bit)) {
                out[count] = (unsigned char)(bit + var0 * 8);
                count++;
                if (count == max) {
                    return count;
                }
            }
        }
    }
    return count;
}
