#include <globaldefs.h>

struct Struct_ov023_021f7550 {
    char unknown0[0x1c];
    int state;
};
typedef int (Struct_ov023_021f7550::*Type_ov023_021f7550)(void*);
extern Type_ov023_021f7550 __ptmf_null;
struct Struct_ov023_021fd8fc { Type_ov023_021f7550 handlers[4]; };
extern Struct_ov023_021fd8fc data_ov023_021fd8fc;

// USA: func_ov023_021f7550
extern "C" ARM int func_ov023_021f7550(Struct_ov023_021f7550* obj, void* param2) {
    Struct_ov023_021fd8fc table = data_ov023_021fd8fc;
    table.handlers[3] = __ptmf_null;
    int result = (obj->*table.handlers[obj->state])(param2);
    obj->state = result;
    return result;
}
