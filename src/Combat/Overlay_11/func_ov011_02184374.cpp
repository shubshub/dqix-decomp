#include <globaldefs.h>

struct Struct_ov011_02184374 {
    short f0;
    short f2;
    char pad[0x74 - 4];
    int unknown_74_;
    int unknown_78_;
};

// USA: func_ov011_02184374
extern "C" ARM void func_ov011_02184374(Struct_ov011_02184374* obj) {
    obj->f0 = 0;
    obj->f2 = 0;
    obj->unknown_74_ = 0;
    obj->unknown_78_ = 0;
}
