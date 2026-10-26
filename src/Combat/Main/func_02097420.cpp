#include <globaldefs.h>

struct Struct_02097420 {
    unsigned int pad0;
    unsigned int value : 12;
};

// USA: func_02097420
extern "C" ARM int func_02097420(struct Struct_02097420* obj) {
    return obj->value;
}
