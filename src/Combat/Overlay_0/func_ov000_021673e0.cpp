#include <globaldefs.h>

struct Struct_ov000_02161c0c_3 {
#if defined(jpn)
    char pad[0x5ff0];
#else
    char pad[0x5e00];
#endif
    unsigned char count;
    unsigned char flags;
    char pad2[2];
    int values[1];
};

// USA: func_ov000_021673e0
extern "C" ARM int func_ov000_021673e0(struct Struct_ov000_02161c0c_3* s) {
    int i;
    for (i = 0; i < s->count; i++) {
        if (!(s->flags & (1 << i))) {
            s->flags |= (1 << i);
            return s->values[i];
        }
    }
    return 0;
}
