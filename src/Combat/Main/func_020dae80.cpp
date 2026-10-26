#include <globaldefs.h>

extern "C" int func_ov003_0217daa4(int p);

struct Struct_020dae80 { char pad[0xc]; int unknown_c_; };

// USA: func_020dae80
extern "C" ARM int func_020dae80(struct Struct_020dae80* obj) {
    int p = obj->unknown_c_;
    if (p == 0) return p;
    return func_ov003_0217daa4(p);
}
