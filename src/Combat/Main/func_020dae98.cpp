#include <globaldefs.h>

struct Struct_020dae98 { char pad0; unsigned char unknown_1_; };

extern "C" void func_020dae08(struct Struct_020dae98* obj);

// USA: func_020dae98
extern "C" ARM void func_020dae98(struct Struct_020dae98* obj) {
    func_020dae08(obj);
    obj->unknown_1_ = 1;
}
