#include <globaldefs.h>

struct Struct_0209494c {
#if defined(jpn)
    char pad[0x139];
#else
    char pad[0x3c9];
#endif
    unsigned char bit0 : 1;
    unsigned char rest : 7;
    unsigned char unknown_3ca_;
    signed char unknown_3cb_;
};

// USA: func_0209494c
extern "C" ARM int func_0209494c(struct Struct_0209494c* obj) {
    if (obj->bit0) {
        return obj->unknown_3cb_ <= 0;
    }
    return 1;
}
