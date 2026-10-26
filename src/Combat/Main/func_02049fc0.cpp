#include <globaldefs.h>

struct Struct_02049fc0 { unsigned char pad[0x64]; float val; };
struct Struct_02049fc0_2 { unsigned char pad[0x13c]; Struct_02049fc0* inner; };

// USA: func_02049fc0
extern "C" ARM int func_02049fc0(Struct_02049fc0_2* obj) {
    Struct_02049fc0* inner = obj->inner;
    if (inner == 0) {
        return 0;
    }
    return inner->val != 0.0f;
}
