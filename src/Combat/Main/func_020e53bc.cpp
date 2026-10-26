#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020e53bc_3;
extern "C" unsigned int func_020e544c(Struct_020e53bc_3* header);

struct Struct_020e53bc;
struct Struct_020e545c;
typedef void (*Type_020e53bc)(Struct_020e53bc*, Struct_020e545c*);
extern "C" int func_020e545c(Struct_020e53bc* list, Type_020e53bc callback);

struct Struct_020e53bc_2 {
    unsigned int field0;
    void* field4;
    void* field8;
};

// USA: func_020e53bc
extern "C" ARM int func_020e53bc(struct Struct_020e53bc_2* self, struct Struct_020e53bc_2* src, unsigned char* outFlag, Type_020e53bc callback) {
    *outFlag = 0;
    if (src == 0) return 0;
    memcpy(self, src, 4);
    self->field4 = (char*)src + 4;
    self->field8 = (char*)src + (func_020e544c((Struct_020e53bc_3*)self) + 4);
    if ((unsigned int)self->field0 >> 31) {
        *outFlag = 1;
        return 1;
    }
    func_020e545c((Struct_020e53bc*)self, callback);
    self->field0 = (self->field0 & ~0x80000000) | 0x80000000;
    src->field0 = (src->field0 & ~0x80000000) | 0x80000000;
    return 1;
}
