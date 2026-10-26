#include <globaldefs.h>
typedef int (*Type_020439b0_2)();
typedef void (*Type_020439b0_3)(int);
extern Type_020439b0_2 data_020f2bdc[];
extern Type_020439b0_3 data_020f2bec[];
struct Struct_020439b0 {
    unsigned char state;
    unsigned char type;
    unsigned char subtype;
};
// USA: func_020e2cc4
extern "C" ARM void func_020e2cc4(struct Struct_020439b0* obj, int enabled) {
    int v;
    if (obj->state == enabled) return;
    obj->state = enabled;
    v = data_020f2bdc[obj->type]();
    if (enabled) v |= 1 << obj->subtype;
    else v &= ~(1 << obj->subtype);
    data_020f2bec[obj->type](v);
}
