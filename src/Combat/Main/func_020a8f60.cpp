#include <globaldefs.h>

struct Struct_020a8e9c {
    unsigned int count : 12;
};

// USA: func_020a8f60
extern "C" ARM int func_020a8f60(struct Struct_020a8e9c* obj) {
    return obj->count * 64;
}
