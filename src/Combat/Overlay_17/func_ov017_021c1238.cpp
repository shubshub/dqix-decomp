#include <globaldefs.h>

struct Struct_ov017_021a3ef0_10 { unsigned char pad[0x1c]; void* f1c; };

extern "C" void func_ov008_021845ac(void*);
extern "C" void func_ov017_021c07d0(Struct_ov017_021a3ef0_10*);

// USA: func_ov017_021c1238
extern "C" ARM void func_ov017_021c1238(Struct_ov017_021a3ef0_10* obj) {
    void* p = obj->f1c;
    if (p) func_ov008_021845ac(p);
    func_ov017_021c07d0(obj);
    ((unsigned char*)obj)[1] = 1;
}
