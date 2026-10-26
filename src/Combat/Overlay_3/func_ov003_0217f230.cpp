#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov003_0217f230 { char pad[0xc]; void* fieldC; };

extern "C" void func_ov003_0216d5f0(void*);

// USA: func_ov003_0217f230
extern "C" ARM void func_ov003_0217f230(struct Struct_ov003_0217f230* obj) {
    if (obj->fieldC) {
        func_ov003_0216d5f0(obj->fieldC);
    }
}
