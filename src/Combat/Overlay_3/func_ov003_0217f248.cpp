#include <globaldefs.h>

struct Struct_ov003_0217f248 { char pad[0xc]; void* fieldC; };

extern "C" void func_ov003_0216d53c(void*);

// USA: func_ov003_0217f248
extern "C" ARM void func_ov003_0217f248(struct Struct_ov003_0217f248* obj) {
    if (obj->fieldC) {
        func_ov003_0216d53c(obj->fieldC);
    }
}
