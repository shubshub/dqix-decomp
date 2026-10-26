#include <globaldefs.h>
#include "Graphics/OBJImage.h"

struct Struct_ov006_0215479c {
    struct Struct_02075cdc base;
    int unknown_70_;
    short unknown_74_;
    short unknown_76_;
    short unknown_78_;
    unsigned char unknown_7a_;
};

// USA: func_ov006_0215479c
extern "C" ARM void func_ov006_0215479c(struct Struct_ov006_0215479c* self) {
    func_02075cdc(&self->base);
    self->unknown_70_ = -1;
    self->unknown_74_ = -1;
    self->unknown_7a_ = self->unknown_76_ = self->unknown_78_ = 0;
}
