#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int idx);
extern "C" void* func_ov001_02158f30(void* ctx, EventVec3 v);

struct Struct_ov001_02165880_35 { char pad[0x24]; void* field24; };
extern Struct_ov001_02165880_35 data_ov001_02165880;

// USA: func_ov001_0215ded8
extern "C" ARM int func_ov001_0215ded8(void* self, int mode) {
    void* p = self;
    self = (char*)self + 0x8;
    int id = func_ov017_021d60f4(p);
    char* ptr = (char*)func_ov001_0215ab20(id);
    if (!ptr) {
        return 0;
    }
    EventVec3 v;
    memcpy(&v, ptr + 0x74, 0xc);
    if (mode >= 2) {
        void* q = self;
        self = (char*)self + 0x8;
        v.a += (int)(4096.0f * func_ov017_021d6110(q));
    }
    if (mode >= 3) {
        void* q = self;
        self = (char*)self + 0x8;
        v.b += (int)(4096.0f * func_ov017_021d6110(q));
    }
    if (mode >= 4) {
        v.c += (int)(4096.0f * func_ov017_021d6110(self));
    }
    void* ctx = data_ov001_02165880.field24;
    func_ov001_02158f30(ctx, v);
    return 1;
}
