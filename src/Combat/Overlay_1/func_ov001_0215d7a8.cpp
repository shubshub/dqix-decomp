#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" void func_ov001_0215907c(void* node, EventVec3 v1, EventVec3 v2);

struct Struct_ov001_02165880_29 { char pad[0x24]; void* field24; };
extern Struct_ov001_02165880_29 data_ov001_02165880;

// USA: func_ov001_0215d7a8
extern "C" ARM int func_ov001_0215d7a8(void* self) {
    EventVec3 v1;
    memset(&v1, 0, 0xc);
    EventVec3 v2;
    memset(&v2, 0, 0xc);
    v1.a = (int)(4096.0f * func_ov017_021d6110(self));
    v1.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    v1.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    v2.a = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x18));
    v2.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x20));
    v2.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x28));
    void* node = data_ov001_02165880.field24;
    func_ov001_0215907c(node, v1, v2);
    return 1;
}
