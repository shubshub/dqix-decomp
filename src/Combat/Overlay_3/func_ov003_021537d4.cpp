#include <globaldefs.h>



class Struct_ov003_021537d4 { public: virtual void inline_ov003_021537d4(); };
typedef void (Struct_ov003_021537d4::*Type_020e6d5c)();

struct Struct_020e6d5c_12 { unsigned int a; unsigned int b; };

extern int data_ov003_02180ca0;
extern struct Struct_020e6d5c_12 __ptmf_null;
extern struct Struct_020e6d5c_12 data_ov003_0217fc80[];
extern struct Struct_020e6d5c_12 data_ov003_0217fc80_tbl[];

union Struct_ov003_021537d4_2 { struct Struct_020e6d5c_12* raw; Type_020e6d5c* fn; };

// USA: func_ov003_021537d4
extern "C" ARM int func_ov003_021537d4(Struct_ov003_021537d4* obj) {
    if (!(data_ov003_02180ca0 & 1)) {
        *(unsigned long long*)((char*)data_ov003_0217fc80 + 0x18) = *(const unsigned long long*)&__ptmf_null;
        data_ov003_02180ca0 |= 1;
    }
    unsigned char idx = *((unsigned char*)obj + 0x5a);
    struct Struct_020e6d5c_12* tbl = data_ov003_0217fc80_tbl;
    if (tbl[idx].a == 0) {
        return 1;
    }
    union Struct_ov003_021537d4_2 var2;
    var2.raw = &tbl[idx];
    (obj->*(*var2.fn))();
    return 0;
}
