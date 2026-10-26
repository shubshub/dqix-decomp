#include <globaldefs.h>

struct Struct_02097418 {
    int pad0;
    int pad4;
    void* value;
};

// USA: func_02097418
extern "C" ARM void* func_02097418(struct Struct_02097418* obj) {
    return obj->value;
}
