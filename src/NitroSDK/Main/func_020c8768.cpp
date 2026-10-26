#include <globaldefs.h>

struct Struct_020c8768 {
    struct Struct_020c8768* field0;
    struct Struct_020c8768* field4;
};

// USA: func_020c8768
extern "C" ARM struct Struct_020c8768* func_020c8768(struct Struct_020c8768* arg0, struct Struct_020c8768* arg1) {
    arg1->field4 = arg0;
    arg1->field0 = 0;
    if (arg0 != 0) {
        arg0->field0 = arg1;
    }
    return arg1;
}
