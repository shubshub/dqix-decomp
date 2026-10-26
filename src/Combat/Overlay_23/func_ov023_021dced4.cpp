#include <globaldefs.h>

struct Struct_ov023_021dced4 {
#if defined(jpn)
    char padding[0x715];
#else
    char padding[0x799];
#endif
    unsigned char unknown_799_;
};

// USA: func_ov023_021dced4
extern "C" ARM void func_ov023_021dced4(void* obj, unsigned char v) {
    ((Struct_ov023_021dced4*)obj)->unknown_799_ = v;
}
