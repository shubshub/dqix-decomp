#include <globaldefs.h>

struct Struct_ov003_0217f218 { char pad[0xc]; void* fieldC; };

extern "C" void func_ov003_0216d468(void*);

// USA: func_ov003_0217f218
extern "C" ARM void func_ov003_0217f218(struct Struct_ov003_0217f218* obj) {
    if (obj->fieldC) {
        func_ov003_0216d468(obj->fieldC);
    }
}
