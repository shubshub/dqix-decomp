#include <globaldefs.h>

struct Struct_02011544 {
#if defined(jpn)
    char unk[0x5A6C];
#else
    char unk[0x5CCC];
#endif
    signed int flag : 1;
};

// USA: func_02011544
extern "C" ARM void func_02011544(struct Struct_02011544* state) {
    state->flag = 1;
}
