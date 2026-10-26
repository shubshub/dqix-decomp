#include <globaldefs.h>

struct Struct_ov023_021fb680 {
    char unknown0[0x1c];
    int state;
};
typedef int (Struct_ov023_021fb680::*Type_ov023_021fb680)(void*);
extern Type_ov023_021fb680 __ptmf_null;
struct Struct_ov023_021fd964 { Type_ov023_021fb680 handlers[4]; };
extern Struct_ov023_021fd964 data_ov023_021fd964;

// USA: func_ov023_021fb680
extern "C" ARM int func_ov023_021fb680(Struct_ov023_021fb680* obj, void* param2) {
    Struct_ov023_021fd964 table = data_ov023_021fd964;
    table.handlers[3] = __ptmf_null;
    int result = (obj->*table.handlers[obj->state])(param2);
    obj->state = result;
    return result;
}
