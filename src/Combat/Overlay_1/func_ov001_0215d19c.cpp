#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov001_02158efc(void* ctx, EventVec3 v);

struct Struct_ov001_02165880_20 { char pad[0x24]; void* field24; };
extern Struct_ov001_02165880_20 data_ov001_02165880;

// USA: func_ov001_0215d19c
extern "C" ARM int func_ov001_0215d19c(void* self) {
    EventVec3 v;
    memset(&v, 0, 0xc);
    v.a = (int)(4096.0f * func_ov017_021d6110(self));
    v.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    v.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    func_ov001_02158efc(data_ov001_02165880.field24, v);
    return 1;
}
