#include <globaldefs.h>

struct Struct_0209fe10 {
    char pad[0x64];
    int field;
};

// USA: func_0209fe10
extern "C" ARM void func_0209fe10(struct Struct_0209fe10* obj, int value) {
    obj->field = value;
}
