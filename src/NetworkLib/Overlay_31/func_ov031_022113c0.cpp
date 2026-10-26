#include <globaldefs.h>

struct Struct_ov031_022113c0 { int field0; };
extern Struct_ov031_022113c0* data_ov031_0224e590;

// USA: func_ov031_022113c0
extern "C" ARM int func_ov031_022113c0(void) {
    Struct_ov031_022113c0* obj = data_ov031_0224e590;
    if (obj == NULL) return 0;
    switch (obj->field0) {
        case 0:
        case 1:
            return 0;
        case 2:
        case 3:
            return 1;
        default:
            return 0;
    }
}
