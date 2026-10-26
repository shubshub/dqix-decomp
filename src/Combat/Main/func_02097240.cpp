#include <globaldefs.h>

struct Struct_02097240 {
    int pad0;
    int pad4;
    int pad8;
    short value;
};

// USA: func_02097240
extern "C" ARM short func_02097240(struct Struct_02097240* obj) {
    return obj->value;
}
