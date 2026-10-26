#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020de714_3;
extern "C" int func_020de7a4(Struct_020de714_3* obj);

struct Struct_020de714;
struct Struct_020de7d0;
typedef void (*Type_020de714)(Struct_020de714*, Struct_020de7d0*);
extern "C" int func_020de7d0(Struct_020de714* c, Type_020de714 cb);

struct Struct_020de714_2 {
    char pad0[8];
    unsigned int field8;
    void* unknown_c_;
    void* unknown_10_;
};

// USA: func_020de714
extern "C" ARM int func_020de714(struct Struct_020de714_2* self, struct Struct_020de714_2* src, unsigned char* outFlag, Type_020de714 callback) {
    *outFlag = 0;
    if (src == 0) return 0;
    memcpy(self, src, 0xc);
    self->unknown_c_ = (char*)src + 0xc;
    self->unknown_10_ = (char*)src + (func_020de7a4((Struct_020de714_3*)self) + 0xc);
    if ((unsigned int)self->field8 >> 31) {
        *outFlag = 1;
        return 1;
    }
    func_020de7d0((Struct_020de714*)self, callback);
    self->field8 = (self->field8 & ~0x80000000) | 0x80000000;
    src->field8 = (src->field8 & ~0x80000000) | 0x80000000;
    return 1;
}
