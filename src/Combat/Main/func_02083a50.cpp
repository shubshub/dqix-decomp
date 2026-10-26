#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02083a50_2284 = 0x854 };
#else
enum { Enum_02083a50_2284 = 0x8ec };
#endif


struct Struct_02083a50 {
    unsigned char pad[Enum_02083a50_2284];
    unsigned char bytes[0x24];
};

// USA: func_02083a50
extern "C" ARM int func_02083a50(struct Struct_02083a50* obj, short* out, int max) {
    int j;
    int k;
    int count;
    count = 0;
    for (j = 0; j < 0x24; j++) {
        unsigned char b = obj->bytes[j];
        if (b == 0) {
            continue;
        }
        for (k = 0; k < 8; k++) {
            if (obj->bytes[j] & (1 << k)) {
                out[count] = (short)(k + (j << 3));
                count++;
                if (count == max) {
                    return count;
                }
            }
        }
    }
    return count;
}
