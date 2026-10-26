#include <globaldefs.h>

struct Struct_020688cc {
    char unk[0x19d5];
    unsigned char field;
};

// USA: func_020688cc
extern "C" ARM int func_020688cc(int unused, struct Struct_020688cc* obj) {
    return obj->field == 0;
}
