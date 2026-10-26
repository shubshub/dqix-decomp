#include <globaldefs.h>

struct Struct_ov031_02214358 { unsigned char pad[0xb]; unsigned char unknown_b_; };

// USA: func_ov031_022143f4
extern "C" ARM int func_ov031_022143f4(struct Struct_ov031_02214358* e) {
    return e->unknown_b_ == 0 ? (int)0xffff3c4d : (int)0xffff3865;
}
