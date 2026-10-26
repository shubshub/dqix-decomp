#include <globaldefs.h>

struct S021b6b8c { unsigned char pad[0x24]; void* f24; };

extern "C" void func_ov003_0215fb94(void*);
extern "C" void func_ov017_021b67d8(S021b6b8c*);

// USA: func_ov017_021b6b8c
extern "C" ARM void func_ov017_021b6b8c(S021b6b8c* obj) {
    void* p = obj->f24;
    if (p) func_ov003_0215fb94(p);
    func_ov017_021b67d8(obj);
    ((unsigned char*)obj)[1] = 1;
}
