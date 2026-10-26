#include <globaldefs.h>

struct Struct_ov031_0223ea84 {
    char pad0[4];
    int field4;
    int field8;
    char pad2[0xc];
    int unknown_18_;
};

// USA: func_ov031_022412e8
extern "C" ARM int func_ov031_022412e8(Struct_ov031_0223ea84* self, int* out) {
    if (self->field8 == 0 || self->field4 == 0) {
        return -1;
    }
    *out = self->unknown_18_;
    return self->field4;
}
