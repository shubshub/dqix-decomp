#include <globaldefs.h>

struct Struct_ov000_02176134 { char pad[0xc]; short val; };

extern "C" void func_ov000_0217616c(struct Struct_ov000_02176134*);

// USA: func_ov000_02176134
extern "C" ARM void func_ov000_02176134(struct Struct_ov000_02176134* obj, short val) {
    if (val == obj->val) return;
    obj->val = val;
    func_ov000_0217616c(obj);
}
