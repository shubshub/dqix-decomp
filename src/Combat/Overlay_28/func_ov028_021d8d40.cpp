#include <globaldefs.h>

class Struct_ov001_02155d54 { public: virtual void inline_ov001_02155d54(); };
typedef void (Struct_ov001_02155d54::*Type_020e6d5c_2)(unsigned short);

struct Struct_020e6d5c_11 { unsigned int a; unsigned int b; };
struct Struct_ov028_021d9a34 { struct Struct_020e6d5c_11 e[4]; };
extern struct Struct_ov028_021d9a34 data_ov028_021d9a34;
extern struct Struct_020e6d5c_11 __ptmf_null;

union Struct_ov028_021d8d40 { struct Struct_020e6d5c_11* raw; Type_020e6d5c_2* fn; };

// USA: func_ov028_021d8d40
extern "C" ARM int func_ov028_021d8d40(Struct_ov001_02155d54* arg0, unsigned short arg1) {
    struct Struct_ov028_021d9a34 t = data_ov028_021d9a34;
    t.e[3].b = __ptmf_null.b;
    t.e[3].a = __ptmf_null.a;
    unsigned char idx = *(unsigned char*)((char*)arg0 + 0x80);
    if (t.e[idx].a == 0) {
        return 1;
    }
    union Struct_ov028_021d8d40 var2;
    var2.raw = &t.e[idx];
    (arg0->*(*var2.fn))(arg1);
    return 0;
}
