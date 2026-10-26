#include <globaldefs.h>

struct Struct_02099fe8 {
    char pad[0x28];
    short field;
};

// USA: func_02099fe8
extern "C" ARM int func_02099fe8(struct Struct_02099fe8* obj) {
    return obj->field;
}
