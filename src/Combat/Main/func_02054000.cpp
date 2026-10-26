#include <globaldefs.h>

struct Struct_02054000_2 {
    char pad0[0x294];
    char unknown_294_;
    char pad1[0x496 - 0x295];
    short unknown_496_;
};

struct Struct_02054000 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    struct Struct_02054000_2* inner;
};

// USA: func_02054000
extern "C" ARM void* func_02054000(struct Struct_02054000* p) {
    struct Struct_02054000_2* inner = p->inner;
    if (inner != 0) {
        if (inner->unknown_496_ > 0) {
            return &inner->unknown_294_;
        }
    }
    return 0;
}
