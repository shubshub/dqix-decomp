#include <globaldefs.h>

struct Struct_020de34c {
    int unk0;
    int unk4;
    unsigned int nibble : 4;
};

// USA: func_020de34c
extern "C" ARM int func_020de34c(struct Struct_020de34c* s, int lo, int hi) {
    return lo <= (int)s->nibble && (int)s->nibble <= hi;
}
