#include <globaldefs.h>

struct Struct_ov004_0215c974 { char pad[0xb0]; int fieldB0; int fieldB4; };

// USA: func_ov011_02184534
extern "C" ARM void func_ov011_02184534(struct Struct_ov004_0215c974* obj, int b0, int arg2) {
    obj->fieldB0 = b0;
    obj->fieldB4 = arg2;
}
