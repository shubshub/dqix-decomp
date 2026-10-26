#include <globaldefs.h>

struct Struct_ov017_021a1284_7 {
    #if defined(jpn)
    char pad[0x4e4];
#else
    char pad[0x4e8];
#endif
    int unknown_4e8_;
    int unknown_4ec_[4];
};

// USA: func_ov023_021e31b0
extern "C" ARM void func_ov023_021e31b0(struct Struct_ov017_021a1284_7* o, unsigned char* src, int c) {
    int i;
    if (src == NULL || c == 0) return;
    o->unknown_4e8_ = c;
    for (i = 0; i < 4; i++) {
        o->unknown_4ec_[i] = src[i];
    }
}
