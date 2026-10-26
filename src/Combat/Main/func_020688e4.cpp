#include <globaldefs.h>

struct Struct_020688e4 {
    char unk[0x19d6];
    unsigned char field;
};

// USA: func_020688e4
extern "C" ARM int func_020688e4(int unused, struct Struct_020688e4* obj) {
    return obj->field == 0;
}
