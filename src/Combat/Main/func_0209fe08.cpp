#include <globaldefs.h>

struct Struct_0209db28 {
    char pad[0x8c];
    int field;
};

// USA: func_0209fe08
extern "C" ARM void func_0209fe08(struct Struct_0209db28* obj, int value) {
    obj->field = value;
}
