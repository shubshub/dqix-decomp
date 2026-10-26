#if defined(jpn)
#define data_ov026_021de87c data_ov026_021dee50
#endif
#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_ov000_02161e30;

struct Struct_ov026_021de87c {
    int id;
    int params[3];
    Vector3i pos;
};

struct Struct_ov000_02160da0 {
    #if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    Struct_ov000_02161e30* battle;
    #if defined(jpn)
    char unknown_21c_[0x77c4];
#else
    char unknown_2a0_[0x7550];
#endif
    int unknown_77f0_;
    int unknown_77f4_[3];
    Vector3i unknown_7800_;
};

extern "C" void func_ov026_021d8b98(int* p, int a, int b, int c);
extern "C" int func_ov000_0215fc8c(void* p0, int arg1);

extern Struct_ov026_021de87c data_ov026_021de87c[];

// USA: func_ov026_021d8aac
extern "C" ARM void func_ov026_021d8aac(Struct_ov000_02160da0* self, int mode, int kind) {
    if (self->battle == 0) {
        return;
    }
    self->unknown_77f0_ = -1;
    for (Struct_ov026_021de87c* e = data_ov026_021de87c; e->id != -1; e++) {
        if (e->id == 0) {
            if (kind == 2) {
                self->unknown_77f0_ = e->id;
                func_ov026_021d8b98(self->unknown_77f4_, e->params[0], e->params[1], e->params[2]);
                self->unknown_7800_ = e->pos;
                return;
            }
        } else if (func_ov000_0215fc8c(self->battle, (short)e->id)) {
            self->unknown_77f0_ = e->id;
            if (e->id == 0x115) {
                e += mode % 3;
            }
            func_ov026_021d8b98(self->unknown_77f4_, e->params[0], e->params[1], e->params[2]);
            self->unknown_7800_ = e->pos;
            return;
        }
    }
}
