#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void func_ov017_021b86e0(void* obj);

struct Struct_ov017_021cbc0c { unsigned char pad[4]; unsigned short field4; };
struct Struct_ov017_021cbc0c_2 { unsigned char pad[8]; unsigned short field8; };

// USA: func_ov017_021cbc0c
extern "C" ARM void func_ov017_021cbc0c(int unused0, Struct_ov017_021cbc0c* src, int arg2, GameResources* obj) {
    void* work = obj->unknown_ptr_3718;
    Struct_ov017_021cbc0c_2* r = (Struct_ov017_021cbc0c_2*)func_ov017_021b8478(work);
    if (!r) return;
    if (r->field8 != src->field4) return;
    func_ov017_021b86e0(work);
}
