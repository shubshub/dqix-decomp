#include <globaldefs.h>

struct Struct_02072aa8;
extern "C" int func_02072aa8(struct Struct_02072aa8* obj, int ptr, int value);

struct Struct_020e03f0 {
    unsigned int unknown_0_0_ : 12;
    unsigned int unknown_1_4_ : 20;
    int field4;
};

// USA: func_020e03f0
extern "C" ARM int func_020e03f0(struct Struct_020e03f0* self, struct Struct_02072aa8* obj) {
    if (obj == NULL) return 0;
    func_02072aa8(obj, self->field4, self->unknown_0_0_);
    return 1;
}
