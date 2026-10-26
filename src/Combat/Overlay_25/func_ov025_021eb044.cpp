#include <globaldefs.h>

struct Struct_ov025_021eb044 {
    char pad[0x57c];
    unsigned short value;
};

// USA: func_ov025_021eb044
extern "C" ARM void func_ov025_021eb044(Struct_ov025_021eb044* obj, int val) {
    obj->value = val;
}
