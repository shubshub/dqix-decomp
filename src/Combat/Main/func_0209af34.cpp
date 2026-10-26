#include <globaldefs.h>
#include "std_library_functions.h"

struct ResetObject0209af34Struct {
    unsigned char data[0x1c8];
    int unknown_1c8_;
    int unknown_1cc_;
    int unknown_1d0_;
};

// USA: func_0209af34
extern "C" ARM void func_0209af34(struct ResetObject0209af34Struct* obj) {
    obj->unknown_1c8_ = -1;
    obj->unknown_1cc_ = 0;
    obj->unknown_1d0_ = 0;
    memset(obj, 0, 0x1c8);
}
