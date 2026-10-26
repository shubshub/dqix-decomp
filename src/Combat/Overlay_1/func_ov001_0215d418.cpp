#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov017_021d60f4(void*);
extern "C" void func_ov001_02158fc4(void* node, EventVec3 v, int extra);

struct Struct_ov001_02165880_23 { char pad[0x24]; void* field24; };
extern Struct_ov001_02165880_23 data_ov001_02165880;

// USA: func_ov001_0215d418
extern "C" ARM int func_ov001_0215d418(void* self) {
    EventVec3 v;
    memset(&v, 0, 0xc);
    v.a = (int)(4096.0f * func_ov017_021d6110(self));
    v.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    v.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    int extra = (int)func_ov017_021d60f4((char*)self + 0x18);
    func_ov001_02158fc4(data_ov001_02165880.field24, v, extra);
    return 1;
}
