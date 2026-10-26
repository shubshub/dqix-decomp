#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_ov023_021fff08 {
    char pad0[0x2];
    unsigned char flag;
    char pad1[0x9];
    short* unknown_c_;
};
extern struct Struct_ov023_021fff08 data_ov023_021fff08;

// USA: func_ov023_021f55b8
extern "C" ARM int func_ov023_021f55b8(struct Variant02030b0c* v) {
    if (data_ov023_021fff08.flag != 0) {
        *data_ov023_021fff08.unknown_c_ = (short)((Script::Parameter*)v)->ToInt();
    }
    return 1;
}
