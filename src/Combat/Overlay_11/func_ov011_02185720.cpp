#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(TaggedNumber02184c30*);

// USA: func_ov011_02185720
extern "C" ARM int func_ov011_02185720(TaggedNumber02184c30* a) {
    int which = func_ov011_02184c30(a);
    int val = func_ov011_02184c30((TaggedNumber02184c30*)((char*)a + 8));
    if (which == 0) {
        unsigned int* reg = (unsigned int*)0x4000000;
        *reg = (*reg & ~0x1f00) | (val << 8);
    } else if (which == 1) {
        unsigned int* reg = (unsigned int*)0x4001000;
        *reg = (*reg & ~0x1f00) | (val << 8);
    }
    return 1;
}
