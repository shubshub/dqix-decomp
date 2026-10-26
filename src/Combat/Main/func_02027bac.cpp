#include <globaldefs.h>

struct Struct_02027bac {
#if defined(jpn)
    unsigned char pad[0x9cb];
#else
    unsigned char pad[0xa97];
#endif
    unsigned char flags;
};

// USA: func_02027bac
extern "C" ARM void func_02027bac(struct Struct_02027bac* p, unsigned char flags) {
    p->flags |= flags;
}
