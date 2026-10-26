#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov017_021baedc {
    int field0;
    int field4;
    unsigned char field8[0x1c];
    int field24;
    unsigned int field28;
};

// USA: func_ov017_021bb088
extern "C" ARM void func_ov017_021bb088(Struct_ov017_021baedc* p) {
    p->field0 = 0;
    p->field4 = 0;
    memset(&p->field8, 0, 0x1c);
    p->field24 = -1;
    p->field28 &= 0xf8000000;
    p->field28 &= ~0xf8000000;
}
