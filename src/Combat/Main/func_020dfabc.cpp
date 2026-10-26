#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020df850;
struct Struct_020dfa68;
typedef int (*Type_020df850)(struct Struct_020df850 *, struct Struct_020dfa68 *);
extern "C" int func_020dfa68(struct Struct_020df850 *, Type_020df850);

struct Struct_020df850_4;
extern "C" int func_020dfbc0(struct Struct_020df850_4 *);

struct Struct_020df850_3 {
    unsigned short count;
    unsigned short pad2;
    unsigned int unknown_4_0_ : 15;
    unsigned int unknown_5_7_ : 1;
    unsigned int unknown_6_0_ : 16;
    void *elements;
    unsigned int end;
};

// USA: func_020dfabc
extern "C" ARM int func_020dfabc(struct Struct_020df850_3 *self, struct Struct_020df850_3 *src, char *outFlag, Type_020df850 cb) {
    *outFlag = 0;
    if (src == NULL) return 0;
    memcpy(self, src, 8);
    self->elements = (void *)((char *)src + 8);
    self->end = (unsigned int)((func_020dfbc0((struct Struct_020df850_4 *)self) + 8) + (char *)src);
    if (self->unknown_5_7_) {
        *outFlag = 1;
        return 1;
    }
    func_020dfa68((struct Struct_020df850 *)self, cb);
    self->unknown_5_7_ = 1;
    src->unknown_5_7_ = 1;
    return 1;
}
