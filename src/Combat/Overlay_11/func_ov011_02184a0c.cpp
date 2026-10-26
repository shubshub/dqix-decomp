#include <globaldefs.h>

struct Struct_ov011_02184a0c {
    char pad[0x1b2];
    unsigned short key;
};

// USA: func_ov011_02184a0c
extern "C" ARM void func_ov011_02184a0c(Struct_ov011_02184a0c* obj, unsigned short key) {
    obj->key = key;
}
