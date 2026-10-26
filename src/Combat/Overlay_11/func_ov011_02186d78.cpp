#include <globaldefs.h>

extern "C" void* func_ov017_021b2164(void);

struct Struct_ov011_02186d78 {
    char pad[0x1cc];
    unsigned char unknown_1cc_;
};

// USA: func_ov011_02186d78
extern "C" ARM int func_ov011_02186d78(void) {
    Struct_ov011_02186d78* obj = (Struct_ov011_02186d78*)func_ov017_021b2164();
    obj->unknown_1cc_ = 1;
    return 1;
}
