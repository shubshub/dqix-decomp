#include <globaldefs.h>

#if defined(jpn)
#include "Resource/Script.h"

struct Struct_ov023_021f514c {
    char unknown_0_[0x50];
    unsigned int flags;
};

struct Struct_ov023_021fff08_9 {
    unsigned char count;
    unsigned char checked;
    unsigned char unknown_2_;
    unsigned char index;
    void* items;
    Struct_ov023_021f514c* unknown_8_;
};

extern Struct_ov023_021fff08_9 data_ov023_021fff08;
#endif

#if defined(jpn)
extern "C" ARM int func_ov023_021f514c(Script::Parameter* params, int numParams) {
    if (params->ToInt() != 0) {
        data_ov023_021fff08.unknown_8_->flags |= 1;
    } else {
        data_ov023_021fff08.unknown_8_->flags &= 1;
    }
    return 1;
}
#else
extern "C" ARM int func_ov023_021f5b94() {
    return 1;
}
#endif
