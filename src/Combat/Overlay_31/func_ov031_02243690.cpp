#include <globaldefs.h>

struct Struct_ov017_021b1e24 {
    char pad[0x2c];
    signed char field2c;
};

typedef signed char (*Type_ov017_021b1e24)(Struct_ov017_021b1e24*);
extern Type_ov017_021b1e24 data_ov031_0224c8a8[];

// USA: func_ov031_02243690
extern "C" ARM int func_ov031_02243690(Struct_ov017_021b1e24* obj) {
    if (obj->field2c >= 0) {
        obj->field2c = data_ov031_0224c8a8[obj->field2c](obj);
    }
    return 1;
}
