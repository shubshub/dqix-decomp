#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"

extern "C" void __clear(void* out, int size);

extern "C" int func_0203cdd0(struct Struct_0203cdd0* obj);

struct Struct_020407c4 { unsigned int v[3]; };

struct Struct_020407c4_2 {
    unsigned char pad0[0x14];
    void* field14;
    unsigned char* field18;
    unsigned char* field1c;
};

// USA: func_020407c4
extern "C" ARM void func_020407c4(struct Struct_020407c4* out, struct Struct_020407c4_2* self) {
    Struct_020407c4 tmp;
    if (self->field14 != NULL) {
        __clear(&tmp, 0xc);
        tmp.v[1] = func_0203cdd0((struct Struct_0203cdd0*)self->field14);
        *out = tmp;
        return;
    }
    if (self->field18 != NULL) {
        *out = *(struct Struct_020407c4*)(self->field18 + 0x50);
        return;
    }
    if (self->field1c != NULL) {
        *out = *(struct Struct_020407c4*)(self->field1c + 0x50);
        return;
    }
    {
        Struct_020407c4 zero;
        zero.v[0] = 0;
        zero.v[1] = 0;
        zero.v[2] = 0;
        *out = zero;
    }
}
